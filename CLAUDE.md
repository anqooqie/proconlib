# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**proconlib** — a C++23 header-only competitive programming library. ~314 tools in `tools/`, verified against online judge problems (AtCoder, Yosupo, AOJ, Yukicoder). Targets GCC 14+ and Clang 20+.

## Build & Verification Commands

```sh
make resolve                # Generate .competitive-verifier/local/verify_files.json (must run before verify)
make verify                 # Run verification (single-process)
make verify-multi-process   # Run verification (parallel, uses all cores)
make docs                   # Generate and serve documentation locally via Jekyll
```

**Compiling a single tool's test manually:**
```sh
g++ --std=c++23 -O2 -Wall -g -I . tests/<name>.test.cpp -o test_binary
# or
clang++ --std=c++23 -O2 -Wall -g -fno-builtin-std-forward_like -I . tests/<name>.test.cpp -o test_binary
```

The include path root is the repository root (`.`), so `#include "tools/foo.hpp"` resolves from there.

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

**Include style**: quoted paths from repo root for library tools (`"tools/foo.hpp"`, `"atcoder/convolution.hpp"`), angle brackets for standard library.

## Test File Conventions

Line 1 must be exactly one of:
- `// competitive-verifier: PROBLEM <judge-url>` — verified against online judge
- `// competitive-verifier: STANDALONE` — self-contained (uses `assert_that` or `static_assert`)

Tests always use `std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);` and `return 0;`.

## Key Dependency Relationships

- **Foundational concepts**: `is_integral.hpp` → `integral.hpp` → `non_bool_integral.hpp` → used by most tools
- **Getter infrastructure**: `getter_result.hpp` + `mutable_type.hpp` — used by nearly all class-based tools
- **~20 tools** depend on AtCoder Library (`atcoder/` headers) for convolution, modint, segtree, fenwicktree, maxflow, etc.
- **`util.hpp`** is a kitchen-sink header (`<bits/stdc++.h>`, `ll`, `REP`, `ALL`) used only by `template/main.cpp`, never by library tools themselves
