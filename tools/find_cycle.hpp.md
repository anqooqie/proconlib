---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':question:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':x:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/find_cycle.test.cpp
    title: tests/find_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':x:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/find_cycle.hpp\"\n\n\n\n#include <utility>\n\nnamespace\
    \ tools {\n\n  template <typename T, typename F>\n  ::std::pair<long long, long\
    \ long> find_cycle(const T& seed, const F& f) {\n    auto i = 1LL;\n    auto j\
    \ = 2LL;\n    T x = f(seed);\n    T y = f(f(seed));\n    for (; x != y; ++i, j\
    \ += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x = seed;\n    for (; x !=\
    \ y; ++i, ++j, x = f(x), y = f(y));\n\n    const auto head = i;\n\n    ++i;\n\
    \    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n    for (; x != y; ++i, j +=\
    \ 2, x = f(x), y = f(f(y)));\n\n    const auto cycle = j - i;\n\n    return ::std::make_pair(head,\
    \ cycle);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_FIND_CYCLE_HPP\n#define TOOLS_FIND_CYCLE_HPP\n\n#include <utility>\n\
    \nnamespace tools {\n\n  template <typename T, typename F>\n  ::std::pair<long\
    \ long, long long> find_cycle(const T& seed, const F& f) {\n    auto i = 1LL;\n\
    \    auto j = 2LL;\n    T x = f(seed);\n    T y = f(f(seed));\n    for (; x !=\
    \ y; ++i, j += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x = seed;\n    for\
    \ (; x != y; ++i, ++j, x = f(x), y = f(y));\n\n    const auto head = i;\n\n  \
    \  ++i;\n    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n    for (; x != y; ++i,\
    \ j += 2, x = f(x), y = f(f(y)));\n\n    const auto cycle = j - i;\n\n    return\
    \ ::std::make_pair(head, cycle);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/find_cycle.hpp
  requiredBy:
  - tools/modint_for_rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  - tools/pow_mod_cache.hpp
  - tools/rolling_hash.hpp
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/find_cycle.test.cpp
  - tests/has_mod.test.cpp
  - tests/rolling_hash.test.cpp
documentation_of: tools/find_cycle.hpp
layout: document
title: Floyd's cycle-finding algorithm
---

```cpp
template <typename T, typename F>
std::pair<long long, long long> find_cycle(T seed, F f);
```

It returns the length of head and the length of cycle.

## Parameters
- `seed`
    - the initial state
- `f`
    - the function which generates the next state

## License
- CC0

## Author
- anqooqie
