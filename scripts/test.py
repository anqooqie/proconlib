#!/usr/bin/env python3
"""competitive-verifier でテストを実行する。

    scripts/test.py [--compiler NAME]... [--jobs N] [--timeout SECONDS] [PATH]...
    scripts/test.py --docs

PATH を省略すると、リグレッションテストとして、前回の成功以降に依存ファイルが変更されたテストを実行する。
PATH を指定すると、指定されたテストと、指定されたヘッダーに依存するテストだけを、前回の結果にかかわらず実行する。
--docs は、全ファイルを解決してドキュメントの Markdown を生成する (make docs が使う)。

git と competitive-verifier は git ls-files でファイルを探すので、インデックスの一時コピーに未追跡のファイルを
intent-to-add で登録し、それを見せる。利用者のインデックスは変更しない。
"""
import argparse
import collections
import concurrent.futures
import datetime
import fcntl
import hashlib
import json
import os
import pathlib
import re
import shutil
import signal
import subprocess
import sys
import threading
import tomllib

ROOT = pathlib.Path(__file__).resolve().parent.parent
CONFIG = ".verify-helper/config.toml"
LOCAL = ROOT / ".competitive-verifier" / "local"
VERIFY_FILES = LOCAL / "verify_files.json"
RESULT = LOCAL / "result.json"
LOCK = LOCAL / "test.lock"
RUN = LOCAL / "run"
INDEX = RUN / "index"

RESOLVE_EXCLUDE = ["archive", "atcoder", "lib", "template"]
# 無限ループへの備えだけでなく、CI を気軽に回せるよう長すぎるテストを排除する目的もある
TIMEOUT = 300
INCLUDE_RE = re.compile(r'^[ \t]*#[ \t]*include[ \t]*"([^"]+)"', re.MULTILINE)
IGNORE_RE = re.compile(r"^//[ \t]*competitive-verifier:[ \t]*IGNORE\b", re.MULTILINE)
FAILURE_RE = re.compile(r'Failed to (compile|test): .*?verification=\{"name":"([^"]+)"')
FAILURE_KINDS = {"compile": "compile error", "test": "test failed"}
# フックの中では git がこれらを設定する。Library Checker の問題リポジトリへの git pull などに漏らさない。
REPOSITORY_ENV = ("GIT_DIR", "GIT_WORK_TREE", "GIT_INDEX_FILE", "GIT_OBJECT_DIRECTORY",
                  "GIT_ALTERNATE_OBJECT_DIRECTORIES", "GIT_COMMON_DIR", "GIT_PREFIX")


class UsageError(Exception):
    pass


def log(message):
    try:
        print(f"[test] {message}", flush=True)
    except OSError:
        # 出力先 (head や閉じられた端末など) に書けなくなっても、テストの停止や結果の保存は続ける
        os.dup2(os.open(os.devnull, os.O_WRONLY), sys.stdout.fileno())


def indexed_env():
    return dict(os.environ, GIT_INDEX_FILE=str(INDEX))


def detached_env():
    return {k: v for k, v in os.environ.items() if k not in REPOSITORY_ENV}


def git(*args, env=None):
    return subprocess.run(["git", *args], cwd=ROOT, env=env or indexed_env(),
                          check=True, capture_output=True, text=True).stdout


def is_source(path):
    return path.endswith((".hpp", ".cpp"))


def read_text(path):
    return (ROOT / path).read_text(encoding="utf-8", errors="replace")


def prepare_index():
    """インデックス (フックの中ではコミットされるインデックス) を一時コピーする。"""
    source = os.environ.get("GIT_INDEX_FILE") or git("rev-parse", "--git-path", "index", env=os.environ).strip()
    if (ROOT / source).is_file():
        shutil.copyfile(ROOT / source, INDEX)


def exclude_deleted():
    """作業ツリーで削除されたファイルは、oj-resolve が読もうとして失敗するので一時コピーから除く。"""
    paths = [p for p in git("ls-files", "-z", "--deleted").split("\0") if p]
    if paths:
        git("update-index", "--force-remove", "--", *paths)
        log(f"excluding {len(paths)} deleted file(s): {' '.join(paths)}")


def include_untracked(directories, suffixes):
    output = git("ls-files", "-z", "--others", "--exclude-standard", "--", *directories)
    paths = [p for p in output.split("\0") if p.endswith(suffixes)]
    if paths:
        git("add", "--intent-to-add", "--", *paths)
        log(f"including {len(paths)} untracked file(s): {' '.join(paths)}")


class Sources:
    """tools/ と tests/ のソースと、その #include による依存関係。

    competitive-verifier が記録する依存関係も tools/ と tests/ のファイルに限られるので、それと一致する。
    """

    def __init__(self):
        output = git("ls-files", "-z", "--", "tools", "tests")
        self.paths = sorted(p for p in output.split("\0") if is_source(p))
        known = set(self.paths)
        includes = {p: set(INCLUDE_RE.findall(read_text(p))) for p in self.paths}
        self.includes = {p: {i for i in found if i in known} for p, found in includes.items()}
        self.missing = {p: sorted(i for i in found if i.startswith(("tools/", "tests/")) and i not in known)
                        for p, found in includes.items()}
        self.dependents = collections.defaultdict(set)
        for path, found in includes.items():
            for include in found:
                self.dependents[include].add(path)
        self.tests = [p for p in self.paths if p.endswith(".test.cpp")]

    def dependencies(self, path):
        """path 自身と、path が直接または間接に #include するファイル。"""
        found = {path}
        stack = [path]
        while stack:
            for include in self.includes[stack.pop()] - found:
                found.add(include)
                stack.append(include)
        return found

    def missing_includes(self, test):
        """test が直接または間接に #include している、存在しないファイル。"""
        return sorted((missing, path) for path in self.dependencies(test) for missing in self.missing[path])

    def dependent_tests(self, path):
        """path 自身を含め、path を直接または間接に #include するテスト。path は削除済みのファイルでもよい。"""
        found = {path}
        stack = [path]
        while stack:
            for dependent in self.dependents[stack.pop()] - found:
                found.add(dependent)
                stack.append(dependent)
        return {p for p in found if p.endswith(".test.cpp")}


def select_tests(paths, sources):
    """指定されたパスを、テストはそのまま、ヘッダーはそれに依存するテストに展開する。"""
    known = set(sources.paths)
    tests = set()
    for path in paths:
        relative = os.path.relpath(os.path.realpath(path), ROOT)
        if relative == ".":
            targets = sources.paths
        elif (ROOT / relative).is_dir():
            targets = [s for s in sources.paths if s.startswith(relative + "/")]
        elif relative in known or relative in sources.dependents:
            targets = [relative]
        elif not (ROOT / relative).exists():
            raise UsageError(f"{path} does not exist")
        else:
            targets = []
        if not targets:
            raise UsageError(f"{path} contains no source file under tools/ or tests/")
        found = set().union(*(sources.dependent_tests(t) for t in targets))
        if not found:
            log(f"warning: no test depends on {path}")
        tests |= found
    if not tests:
        raise UsageError("no test to run")
    return sorted(tests)


def compiler_names():
    """検証名は config.toml の CXX のファイル名 (g++, clang++ など) になる。"""
    with open(ROOT / CONFIG, "rb") as f:
        config = tomllib.load(f)
    return [pathlib.PurePath(e["CXX"]).name for e in config["languages"]["cpp"]["environments"]]


def is_ignored(path):
    """IGNORE 属性のテストは常に skipped となるので実行しない。"""
    return IGNORE_RE.search(read_text(path)) is not None


def stale_compilers(dependencies, compilers, cached):
    """前回の結果が成功でないか、依存ファイルと config.toml のどれかより古いコンパイラ。"""
    newest = max((ROOT / d).stat().st_mtime for d in [*dependencies, CONFIG])
    results = {v.get("verification_name"): v for v in (cached or {}).get("verifications", [])}
    stale = []
    for compiler in compilers:
        result = results.get(compiler)
        if (result is None or result["status"] != "success"
                or datetime.datetime.fromisoformat(result["last_execution_time"]).timestamp() < newest):
            stale.append(compiler)
    return stale


def run_resolver(output, log_file, *args):
    with open(output, "w") as stdout, open(log_file, "w") as stderr:
        process = subprocess.run(
            ["competitive-verifier", "oj-resolve", *args, "--config", CONFIG],
            cwd=ROOT, env=dict(indexed_env(), CPLUS_INCLUDE_PATH=""), stdout=stdout, stderr=stderr,
        )
    if process.returncode != 0:
        raise RuntimeError(f"oj-resolve failed (log: {log_file.relative_to(ROOT)})")
    return json.loads(pathlib.Path(output).read_text())["files"]


def uniquify(files):
    """同じ問題を参照するテストどうしが実行ファイルを共有しないよう、problem 検証の実行ファイル名をテストとコンパイラごとに分ける。

    名前にはリポジトリの場所も含めて、別の worktree での実行と pkill で取り違えないようにする。
    competitive-verifier 4.1.2 では、compile は引数のリストで、command は実行ファイルのパスの文字列。
    """
    for path, info in files.items():
        for verification in info.get("verification", []):
            if verification["type"] != "problem":
                continue
            suffix = hashlib.md5(f"{ROOT}:{path}:{verification['name']}".encode()).hexdigest()[:8]
            binary = verification["command"]
            unique = str(pathlib.PurePath(binary).with_name(f"a_{suffix}.out"))
            verification["command"] = unique
            verification["compile"] = [unique if arg == binary else arg for arg in verification["compile"]]
    return files


def resolve_tests(tests, jobs):
    """テストを解決する。一括で失敗したら、原因のテストを特定するために 1 件ずつ解決し直す。

    解決できたテストと、解決できなかったテストからその理由への辞書を返す。
    """
    log(f"resolving {len(tests)} test(s)")
    try:
        return uniquify(run_resolver(RUN / "resolved.json", RUN / "resolve.log", "--no-bundle", "--include", *tests)), {}
    except RuntimeError:
        pass

    def resolve(test):
        stem = test.replace("/", "__")
        return run_resolver(RUN / f"{stem}.resolved.json", RUN / f"{stem}.resolve.log", "--no-bundle", "--include", test)

    resolved = {}
    failed = {}
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as executor:
        futures = {executor.submit(resolve, t): t for t in tests}
        for future in concurrent.futures.as_completed(futures):
            try:
                resolved.update(future.result())
            except RuntimeError as e:
                failed[futures[future]] = str(e)
    return uniquify(resolved), failed


def load_cache():
    if RESULT.is_file():
        return json.loads(RESULT.read_text())
    return {"total_seconds": 0.0, "files": {}}


def update_cache(cache, results, keep=None):
    """結果をコンパイラ単位で上書きする。keep を指定すると、それ以外のファイルの結果を捨てる。"""
    files = cache["files"]
    for path, result in results.items():
        verifications = {v.get("verification_name"): v for v in files.get(path, {}).get("verifications", [])}
        verifications.pop(None, None)
        for verification in result["verifications"]:
            verifications[verification.get("verification_name")] = verification
        files[path] = {"verifications": list(verifications.values()), "newest": True}
    if keep is not None:
        cache["files"] = {p: r for p, r in files.items() if p in keep}
    cache["total_seconds"] = sum(v["elapsed"] for r in cache["files"].values() for v in r["verifications"])
    temporary = RESULT.with_suffix(".json.tmp")
    temporary.write_text(json.dumps(cache))
    temporary.replace(RESULT)


def download(entries):
    """テストケースを先にまとめて取得する。並列実行中に同じ問題を取り合わないようにするため。"""
    problems = {p: e for p, e in entries.items() if any(v["type"] == "problem" for v in e["verification"])}
    if not problems:
        return
    urls = {v["problem"] for e in problems.values() for v in e["verification"] if v["type"] == "problem"}
    log(f"downloading the test cases of {len(urls)} problem(s)")
    verify_json = RUN / "download.json"
    verify_json.write_text(json.dumps({"files": problems}))
    with open(RUN / "download.log", "w") as output:
        process = subprocess.run(
            ["competitive-verifier", "download", "--verify-json", str(verify_json)],
            cwd=ROOT, env=detached_env(), stdout=output, stderr=subprocess.STDOUT,
        )
    if process.returncode != 0:
        log(f"downloading failed for some problems (log: {(RUN / 'download.log').relative_to(ROOT)})")


class Runner:
    """テストごとに competitive-verifier verify を別プロセスで実行する。"""

    def __init__(self, timeout):
        self.timeout = timeout
        self.processes = {}
        self.lock = threading.Lock()
        self.stopped = False

    def stop(self):
        with self.lock:
            self.stopped = True
            for process, binaries in self.processes.items():
                kill(process, binaries)

    def run(self, path, entry):
        """結果と、コンパイラから competitive-verifier の結果より優先する失敗理由への辞書を返す。"""
        stem = path.replace("/", "__")
        verify_json = RUN / f"{stem}.json"
        output = RUN / f"{stem}.result.json"
        verify_json.write_text(json.dumps({"files": {path: entry}}))
        started = datetime.datetime.now(datetime.timezone.utc)
        timeout = self.timeout * len(entry["verification"])
        binaries = [v["command"] for v in entry["verification"] if v["type"] == "problem"]
        with open(log_path(path), "w") as log_file, self.lock:
            if self.stopped:
                return None, {}
            # テストのプログラムまで確実に止められるよう、別のプロセスグループで起動する
            process = subprocess.Popen(
                ["competitive-verifier", "verify", "--verify-json", str(verify_json), "--no-download", "--output", str(output)],
                cwd=ROOT, env=detached_env(), stdout=log_file, stderr=subprocess.STDOUT, start_new_session=True,
            )
            self.processes[process] = binaries
        try:
            process.wait(timeout=timeout)
            timed_out = False
        except subprocess.TimeoutExpired:
            kill(process, binaries)
            process.wait()
            timed_out = True
        finally:
            with self.lock:
                self.processes.pop(process)

        names = [v["name"] for v in entry["verification"]]
        if timed_out:
            return failed_result(names, started), {n: f"timed out (limit: {self.timeout} seconds per compiler)" for n in names}
        try:
            result = json.loads(output.read_text())["files"][path]
        except (OSError, KeyError, ValueError):
            return failed_result(names, started), {}
        reasons = {}
        problems = {v["name"] for v in entry["verification"] if v["type"] == "problem"}
        for verification in result["verifications"]:
            # 実行中に保存された変更を見逃さないよう、終了時刻ではなく開始時刻を記録する
            verification["last_execution_time"] = started.isoformat()
            # テストケースがなければ oj test は 0 件で成功と判定するので、失敗として扱う
            name = verification.get("verification_name")
            if name in problems and verification["status"] == "success" and not verification.get("testcases"):
                verification["status"] = "failure"
                reasons[name] = f"no test cases; see {(RUN / 'download.log').relative_to(ROOT)} for the download"
        return result, reasons


def kill(process, binaries):
    """verify のプロセスグループと、oj test が別のセッションで起動する problem 検証の実行ファイルを止める。"""
    try:
        os.killpg(process.pid, signal.SIGKILL)
    except ProcessLookupError:
        pass
    for binary in binaries:
        # 実行ファイル名は uniquify でテストとコンパイラごとに一意になっている
        subprocess.run(["pkill", "-KILL", "-f", re.escape(pathlib.PurePath(binary).name)])


def failed_result(names, started):
    return {"verifications": [
        {"verification_name": n, "status": "failure", "elapsed": 0.0, "last_execution_time": started.isoformat()}
        for n in names
    ]}


def log_path(path):
    return RUN / (path.replace("/", "__") + ".log")


def describe(path, verification, reasons):
    name = verification.get("verification_name")
    if name in reasons:
        return reasons[name]
    bad = [t for t in verification.get("testcases") or [] if t["status"] != "AC"]
    if bad:
        shown = ", ".join(f"{t['status']} on {t['name']}" for t in bad[:3])
        return shown + (f", and {len(bad) - 3} more" if len(bad) > 3 else "")
    for kind, failed in FAILURE_RE.findall(log_path(path).read_text(errors="replace")):
        if failed == name:
            return FAILURE_KINDS[kind]
    return "see the log"


def run_tests(entries, jobs, timeout):
    """テストを並列に実行し、結果と、中断されたかどうかを返す。中断されたら、終わったテストの結果だけを返す。"""
    download(entries)
    log(f"running {len(entries)} test(s) with {jobs} job(s)")
    runner = Runner(timeout)
    results = {}
    step = len(entries) // 10 if len(entries) >= 20 else len(entries)
    executor = concurrent.futures.ThreadPoolExecutor(max_workers=jobs)
    futures = {executor.submit(runner.run, p, e): p for p, e in entries.items()}
    try:
        for done, future in enumerate(concurrent.futures.as_completed(futures), 1):
            path = futures[future]
            result, reasons = future.result()
            results[path] = result
            for verification in result["verifications"]:
                if verification["status"] == "failure":
                    name = verification.get("verification_name") or "-"
                    log(f"FAILED {path} [{name}]: {describe(path, verification, reasons)} "
                        f"(log: {log_path(path).relative_to(ROOT)})")
            if done % step == 0 and done != len(entries):
                log(f"{done}/{len(entries)} test(s) done")
    except KeyboardInterrupt:
        log("interrupted; stopping the running tests")
        runner.stop()
        executor.shutdown(wait=True, cancel_futures=True)
        return results, True
    executor.shutdown()
    return results, False


def summarize(results, failed):
    counts = collections.Counter(v["status"] for r in results.values() for v in r["verifications"])
    log(f"{len(results)} test(s) run: {counts['success']} verification(s) succeeded, {counts['failure']} failed"
        + (f"; {len(failed)} test(s) could not run" if failed else ""))
    return 1 if counts["failure"] or failed else 0


def generate_docs():
    log("resolving all files (this takes a few minutes)")
    files = run_resolver(VERIFY_FILES, RUN / "resolve.log", "--exclude", *RESOLVE_EXCLUDE)
    # competitive-verifier docs は全テストの結果を要求するので、結果のないテスト (IGNORE 属性や未実行のテスト) は skipped とする
    cache = load_cache()
    for path, info in files.items():
        if info.get("verification") and path not in cache["files"]:
            cache["files"][path] = {"verifications": [{"status": "skipped", "elapsed": 0.0}]}
    results = RUN / "docs-result.json"
    results.write_text(json.dumps(cache))
    log("generating the documents")
    with open(RUN / "docs.log", "w") as output:
        process = subprocess.run(
            ["competitive-verifier", "docs", "--verify-json", str(VERIFY_FILES), str(results)],
            cwd=ROOT, env=indexed_env(), stdout=output, stderr=subprocess.STDOUT,
        )
    if process.returncode != 0:
        raise RuntimeError(f"generating the documents failed (log: {(RUN / 'docs.log').relative_to(ROOT)})")


STOP_SIGNALS = (signal.SIGINT, signal.SIGTERM, signal.SIGHUP)


def interrupt(signum, frame):
    """最初の信号でだけ中断する。端末を閉じたときの 2 回目の SIGHUP などに、止める処理そのものを中断させないため。"""
    for s in STOP_SIGNALS:
        signal.signal(s, lambda *_: None)
    raise KeyboardInterrupt


def positive_int(value):
    number = int(value)
    if number <= 0:
        raise argparse.ArgumentTypeError(f"{value} is not a positive integer")
    return number


def main():
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("paths", nargs="*", metavar="PATH", help="tests, headers, or directories to test")
    parser.add_argument("--compiler", action="append", default=[], help="run only this compiler (repeatable)")
    parser.add_argument("--jobs", type=positive_int, default=os.cpu_count(), help="number of tests to run in parallel")
    parser.add_argument("--timeout", type=positive_int, default=TIMEOUT,
                        help=f"seconds allowed for each test and compiler, including compilation (default: {TIMEOUT})")
    parser.add_argument("--docs", action="store_true", help="resolve all files and generate the documents")
    args = parser.parse_args()
    if args.docs and (args.paths or args.compiler):
        parser.error("--docs takes neither PATH nor --compiler")
    available = compiler_names()
    unknown = sorted(set(args.compiler) - set(available))
    if unknown:
        parser.error(f"unknown compiler(s): {' '.join(unknown)} (available: {' '.join(available)})")
    compilers = [c for c in available if not args.compiler or c in args.compiler]
    # Ctrl-C だけでなく、コマンドのタイムアウトや端末を閉じたときもテストを止めて結果を保存する (nohup などで無視されている信号はそのまま)
    for s in STOP_SIGNALS:
        if signal.getsignal(s) != signal.SIG_IGN:
            signal.signal(s, interrupt)

    LOCAL.mkdir(parents=True, exist_ok=True)
    with open(LOCK, "w") as lock:
        try:
            fcntl.flock(lock, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            log("waiting for another run of scripts/test.py to finish")
            fcntl.flock(lock, fcntl.LOCK_EX)
        try:
            return run(args, compilers)
        except KeyboardInterrupt:
            log("interrupted")
            return 130


def run(args, compilers):
    shutil.rmtree(RUN, ignore_errors=True)
    RUN.mkdir()
    try:
        prepare_index()
        exclude_deleted()
        include_untracked(["tools", "tests"], (".hpp", ".cpp"))
        if args.docs:
            include_untracked(["docs"], (".md",))
            generate_docs()
            return 0

        sources = Sources()
        cache = load_cache()
        if args.paths:
            selected = select_tests(args.paths, sources)
            ignored = [t for t in selected if is_ignored(t)]
            if ignored:
                log(f"ignored by the IGNORE attribute: {' '.join(ignored)}")
            stale = {t: compilers for t in selected if t not in ignored}
            keep = None
        else:
            candidates = [t for t in sources.tests if not is_ignored(t)]
            stale = {}
            for test in candidates:
                # 削除されたヘッダーは更新時刻で検出できないので、それを #include するテストは常に対象にする
                if sources.missing_includes(test):
                    stale[test] = compilers
                    continue
                compilers_to_run = stale_compilers(sources.dependencies(test), compilers, cache["files"].get(test))
                if compilers_to_run:
                    stale[test] = compilers_to_run
            log(f"{len(stale)} of {len(candidates)} test(s) need to run "
                f"({len(sources.tests) - len(candidates)} ignored by the IGNORE attribute)")
            keep = set(sources.tests)

        # 存在しないファイルを #include するテストは、解決も実行もできないので先に報告する
        failed = {}
        for test in stale:
            missing = sources.missing_includes(test)
            if missing:
                failed[test] = "missing include " + ", ".join(f"{m} (in {p})" for m, p in missing)
        tests = [t for t in stale if t not in failed]
        resolved, unresolved = resolve_tests(tests, args.jobs) if tests else ({}, {})
        failed |= unresolved
        entries = {}
        for test in tests:
            if test in failed:
                continue
            verifications = [v for v in resolved.get(test, {}).get("verification", []) if v.get("name") in stale[test]]
            if verifications:
                entries[test] = dict(resolved[test], verification=verifications)
            else:
                failed[test] = "no verification; check its competitive-verifier comment"
        for test, reason in sorted(failed.items()):
            log(f"FAILED {test}: {reason}")
    except UsageError as e:
        log(f"error: {e}")
        return 2
    except RuntimeError as e:
        log(f"error: {e}")
        return 1

    results, interrupted = run_tests(entries, args.jobs, args.timeout) if entries else ({}, False)
    update_cache(cache, results, keep)
    status = summarize(results, failed)
    return 130 if interrupted else status


if __name__ == "__main__":
    sys.exit(main())
