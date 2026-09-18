# My Library for Competitive Programming

[![Actions Status](https://github.com/anqooqie/proconlib/actions/workflows/verify.yml/badge.svg)](https://github.com/anqooqie/proconlib/actions)
[![anqooqie](https://img.shields.io/endpoint?url=https%3A%2F%2Fatcoder-badges.now.sh%2Fapi%2Fatcoder%2Fjson%2Fanqooqie)](https://atcoder.jp/users/anqooqie)

My C++ library for competitive programming.

## Requirements

- C++23 or later.
- GCC 14+ or Clang 20+.
- `char`, `short`, `int`, and `long long` are 8, 16, 32, and 64 bits wide respectively. Their unsigned counterparts (and `signed char`) have the same widths.
- The ordinary literal encoding is ASCII-compatible; specifically, `'a'`..`'z'` and `'A'`..`'Z'` each occupy contiguous code points.

Individual headers may impose additional constraints (e.g. requiring GCC). See the documentation of each header for details.

## Policy

- **Embraces C++23.** Concepts, deducing `this`, ranges, and other modern language features are used throughout.
- **No `using namespace std` assumption.** Library headers fully qualify standard-library names so they integrate cleanly with any user code.
- **Per-header documentation.** Every header has a dedicated documentation page.

## Documentation

See [![GitHub Pages](https://img.shields.io/static/v1?label=GitHub+Pages&message=+&color=brightgreen&logo=github)](https://anqooqie.github.io/proconlib).

## How to Use

### Install

```sh
git clone --recursive https://github.com/anqooqie/proconlib.git /path/to/the/library
```

### Include

Include the library headers in your code.

```cpp
#include <iostream>
#include "tools/totient.hpp"

int main() {
  std::cout << "phi(6) = " << tools::totient(6) << '\n';
  return 0;
}
```

Compile with the repository root added to the include path (e.g. `g++ -I /path/to/the/library ...`).

### Bundle for submission

Most online judges do not support submitting multiple files, so you typically need to expand `#include` statements before submission.
You can use any tool, but [oj-bundle](https://github.com/online-judge-tools/verification-helper) is recommended.

```sh
oj-bundle -I /path/to/the/library example.cpp >expanded_example.cpp
```

### Update

Update follows standard Git conventions; no library-specific steps are required.

```sh
cd /path/to/the/library
git pull origin main
git submodule update --recursive
```

## Development

Tests live under `tests/` and are either verified against an online judge or run standalone with assertions. The following `make` targets drive the workflow:

```sh
make test                                            # Run every test affected by changes since its last success
make test FILES="tools/foo.hpp tests/bar.test.cpp"   # Run only these tests and the tests that depend on these headers
make test COMPILER=g++                               # Either form, restricted to one compiler
make docs                                            # Generate and serve documentation locally via Jekyll
```

## Acknowledgments

- [AtCoder Library](https://github.com/atcoder/ac-library) — a [patched fork](https://github.com/anqooqie/ac-library) is included as a git submodule and exposed via `atcoder/` headers. Installed automatically when cloning this repository with `--recursive`; no separate installation is required. Library headers assume the patches, so the upstream release cannot be used in its place.
- [competitive-verifier](https://github.com/competitive-verifier/competitive-verifier) — drives CI verification against online judges, and is also required locally for `make test` and `make docs`. Not required to simply use the library.
- [atcoder-cli](https://github.com/Tatamo/atcoder-cli), [online-judge-tools](https://github.com/online-judge-tools/oj), and [verification-helper](https://github.com/online-judge-tools/verification-helper) (`oj-bundle`) — assumed to be pre-installed when using the per-contest workspace template under `template/`. The library itself does not depend on these, and `template/` can be ignored.

Verification uses problems from [AtCoder](https://atcoder.jp/), [Library Checker](https://judge.yosupo.jp/), [Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/), and [Yukicoder](https://yukicoder.me/).

## License

Most files are licensed under CC0, but some have different licenses. For the exact license of each file, please refer to the corresponding page on GitHub Pages.
