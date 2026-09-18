# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**proconlib** — a C++23 header-only competitive programming library with ~314 headers under `tools/`. See README.md for requirements, install, and policy.

## Build & Verification Commands

```sh
make test                                            # Regression: run every test affected by changes since its last success
make test FILES="tools/foo.hpp tests/bar.test.cpp"   # Run only these tests and the tests that depend on these headers
make test COMPILER=g++                               # Either form, restricted to one compiler (g++ or clang++)
make docs                                            # Generate and serve documentation locally via Jekyll
```

`make test` wraps `scripts/test.py`, which drives competitive-verifier:

- **No manual preparation.** Untracked sources under `tools/` and `tests/` (and `docs/*.md` for `make docs`) are included automatically: competitive-verifier finds files through `git ls-files`, so the script registers them with `--intent-to-add` in a temporary copy of the index and runs git and competitive-verifier against that copy. Your own index is never modified. Dependencies are read from the `#include` lines on every run, so adding files or changing includes needs no extra step.
- **Regression (no `FILES`)** re-runs a test for each compiler whose previous result failed or is older than one of the test's dependencies or `.verify-helper/config.toml`. Results are kept in `.competitive-verifier/local/result.json`.
- **Focused (`FILES`)** always re-runs the selected tests. `FILES` accepts tests, headers (including deleted ones), and directories. The results are also recorded, so a later regression run does not repeat them.
- **Output**: one line per failure and a final summary. The exit status is non-zero when anything fails. The failure lines look like this:
  - `FAILED <test> [<compiler>]: <reason> (log: <path>)` for a test that ran, where the reason is a compile error, a failed test, the judge verdicts, missing test cases, or a timeout.
  - `FAILED <test>: <reason>` for a test that could not run, such as one that includes a missing file.

  The logs in `.competitive-verifier/local/run/` are kept until the next run.
- **Time limit**: each test gets 300 seconds for each compiler it runs, as one budget shared by those compilers and including compilation. Beyond that it fails as timed out. The limit also keeps CI quick, so split or shrink a test that approaches it.
- **Duration**: a regression after touching a widely included header, or a run over all tests, can take around 10 minutes. From a shell tool with a short timeout, run it in the background. If the run is stopped (Ctrl-C, SIGTERM, or SIGHUP), the completed results are kept.
- Tests with the `IGNORE` attribute (currently the AtCoder PROBLEM tests, whose test cases are unavailable) are never run.

The `pre-commit` hook in `.githooks/` runs the regression when the commit touches `tools/`, `tests/`, or `.verify-helper/`. It finishes in seconds if `make test` has already passed. It tests the working tree, not only the staged changes, so an unrelated failing work-in-progress test also blocks the commit. The hook is active when `core.hooksPath` is set to `.githooks`; the dev container sets this up.

**Debugging a single test by hand:**

Tests are either STANDALONE (assert-based, self-contained) or PROBLEM (verified against an online judge). The first line of each test file indicates its type (see Test File Conventions below). To get a binary for a debugger:

```sh
g++ --std=c++23 -O2 -Wall -g -I . tests/<name>.test.cpp -o /tmp/test_binary
# or
clang++ --std=c++23 -O2 -Wall -g -fno-builtin-std-forward_like -I . tests/<name>.test.cpp -o /tmp/test_binary
```

The include path root is the repository root (`.`), so `#include "tools/foo.hpp"` resolves from there. After `make test` has run a PROBLEM test, its test cases are cached under `.competitive-verifier/cache/`: in the problem's directory under `library-checker-problems/` for Library Checker, and under `problems/<hash of the problem URL>/test/` for the other judges.

## Architecture

- **`tools/*.hpp`** — One header per tool. Each is self-contained with its own include guard and dependencies.
- **`tools/detail/*.hpp`** — Internal implementation helpers (AVL tree, geometry, int128, interval set, rolling hash, kth largest).
- **`tests/*.test.cpp`** or **`tests/<tool>/*.test.cpp`** — Complete C++ programs (not unit test framework). Each is either verified against an online judge problem or standalone with assertions.
- **`docs/*.md`** — Jekyll/Doxygen markdown, one per tool. Uses `documentation_of: //tools/<name>.hpp`.
- **`lib/ac-library/`** — AtCoder Library (git submodule). Symlinked as `atcoder/` at repo root for include resolution.
- **`template/`** — Per-contest-problem workspace template with its own Makefile (uses `-fsanitize=address,undefined -DLOCAL` and `oj-bundle` for submission bundling).

## Coding Conventions

**Header structure** — every `tools/<name>.hpp`:
```cpp
#ifndef TOOLS_UPPERCASE_SNAKE_CASE_HPP
#define TOOLS_UPPERCASE_SNAKE_CASE_HPP

#include <standard_headers>
#include "tools/dependency.hpp"

namespace tools {
  // ...
}

#endif
```

**Naming**: `snake_case` everywhere (classes, functions, variables). Private members: `m_` prefix. Static members: `s_` prefix.

**C++23 patterns used heavily**:
- Explicit object parameters (deducing `this`) with `std::forward_like` for getters
- `tools::getter_result_t<decltype(self), T>` as return type for getter methods
- `tools::mutable_type` concept to constrain mutating methods to non-const `this`
- Concepts (`tools::integral`, `tools::modint`, etc.) and `requires` clauses
- `if constexpr`, `std::ranges`, `std::views`

**Customization point pattern** — functions like `abs`, `gcd`, `signum` dispatch through `tools::detail::<func>::impl<T>` which types like `bigint` and `rational` specialize.

**Include style**: quoted paths from repo root for library tools (`"tools/foo.hpp"`, `"atcoder/convolution.hpp"`), angle brackets for standard library. Within each group (standard / library), sort alphabetically.

**Interface conformance over house style** — when a class is clearly modeled on one from the standard library, AtCoder Library or Boost, match the model's interface, and apply the conventions here only where they do not change it. `tools::preset_segtree_beats` follows `atcoder::lazy_segtree`: its template parameter stays unconstrained, its constructors are not range-based, and it has no `size()`, because the model has none of these; Rule of Zero, include order and the naming of internals still apply.

**Ongoing modernization policies** (applied when touching existing code):
- **`int` over `std::size_t`** for sizes, indices, and return values. Competitive programming inputs fit in `int`; mixing signed/unsigned is error-prone.
- **Concept constraints on template parameters**: prefer `tools::non_bool_integral T` (or other appropriate concepts) over unconstrained `typename T`.
- **Rule of Zero**: do not explicitly default special member functions (copy/move constructors, destructor, assignment operators) unless the class manages resources.
- **`assert` for preconditions**: reject invalid inputs with `assert`, not silent early returns.
- **PROBLEM → STANDALONE test migration**: AtCoder-based PROBLEM tests that can no longer fetch test cases are being rewritten as STANDALONE tests with `assert_that`.

## Test File Conventions

There are two types of tests. Line 1 must be exactly one of:
- `// competitive-verifier: PROBLEM <judge-url>` — verified against an online judge problem. `make test` downloads the test cases (see Build & Verification Commands above).
- `// competitive-verifier: STANDALONE` — self-contained (uses `assert_that` or `static_assert`). Can be run directly after compilation.

A second line `// competitive-verifier: IGNORE` disables a test. `IGNORE_IF_GCC` and `IGNORE_IF_CLANG` are not supported by `make test`: it treats the skipped compiler as a failure.

Tests always use `std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);` and `return 0;`.

## Key Dependency Relationships

- **Foundational concepts**: `is_integral.hpp` → `integral.hpp` → `non_bool_integral.hpp` → used by most tools
- **Getter infrastructure**: `getter_result.hpp` + `mutable_type.hpp` — used by nearly all class-based tools
- **~20 tools** depend on AtCoder Library (`atcoder/` headers) for convolution, modint, segtree, fenwicktree, maxflow, etc.
- **`util.hpp`** is a kitchen-sink header (`<bits/stdc++.h>`, `ll`, `REP`, `ALL`) used only by `template/main.cpp`, never by library tools themselves
