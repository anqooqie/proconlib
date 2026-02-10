#!/usr/bin/env python3
"""verify_files.json 内の problem 型テストのバイナリパスを一意化する。

同一問題 URL を参照する複数テストが同じ a.out を共有する問題を解消し、
make verify-multi-process での並列実行時の競合を防ぐ。
"""
import hashlib, json, sys

def uniquify(path):
    with open(path) as f:
        data = json.load(f)
    for fname, info in data["files"].items():
        for v in info.get("verification", []):
            if v.get("type") != "problem":
                continue
            key = f"{fname}:{v.get('name', '')}"
            suffix = hashlib.md5(key.encode()).hexdigest()[:8]
            unique_name = f"a_{suffix}.out"
            if v.get("compile"):
                v["compile"] = v["compile"].replace("/a.out ", f"/{unique_name} ")
            if v.get("command"):
                v["command"] = v["command"].replace("/a.out", f"/{unique_name}")
    with open(path, "w") as f:
        json.dump(data, f)

if __name__ == "__main__":
    uniquify(sys.argv[1])
