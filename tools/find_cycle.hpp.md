---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':heavy_check_mark:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':heavy_check_mark:'
    path: tools/stirling_1st.hpp
    title: Stirling numbers of the first kind $s(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/berlekamp_massey.test.cpp
    title: tests/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/find_cycle.test.cpp
    title: tests/find_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multidimensional.test.cpp
    title: tests/polynomial/multidimensional.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multipoint_evaluation.test.cpp
    title: tests/polynomial/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
    title: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/taylor_shift.test.cpp
    title: tests/polynomial/taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial_interpolation.test.cpp
    title: tests/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st.test.cpp
    title: tests/stirling_1st.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - tools/stirling_1st.hpp
  - tools/pow_mod_cache.hpp
  - tools/polynomial_interpolation.hpp
  - tools/bostan_mori.hpp
  - tools/detail/rolling_hash.hpp
  - tools/rolling_hash.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/berlekamp_massey.hpp
  - tools/polynomial.hpp
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/stirling_1st.test.cpp
  - tests/has_mod.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/find_cycle.test.cpp
  - tests/bostan_mori.test.cpp
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
