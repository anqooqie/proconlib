---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/floor_log.hpp
    title: $\left\lfloor \log_b(x) \right\rfloor$
  - icon: ':warning:'
    path: tools/pow_mod_cache.hpp
    title: Precompute $b^n \pmod{M}$
  - icon: ':warning:'
    path: tools/round.hpp
    title: Apply banker's rounding to $\frac{x}{y}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bezout.test.cpp
    title: tests/bezout.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/floor_log.test.cpp
    title: tests/floor_log.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/floor.hpp\"\n\n\n\n#line 1 \"tools/detail/ceil_and_floor.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace tools {\n\n  template <typename M,\
    \ typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M& lhs, const\
    \ N& rhs);\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs);\n  \n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> floor(const M& lhs, const N& rhs) {\n\
    \    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs / rhs :\n      lhs < 0\
    \ && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n      lhs >= 0 && rhs <\
    \ 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs, -rhs);\n\
    \  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/floor.hpp\"\n\
    \n\n"
  code: '#ifndef TOOLS_FLOOR_HPP

    #define TOOLS_FLOOR_HPP


    #include "tools/detail/ceil_and_floor.hpp"


    #endif

    '
  dependsOn:
  - tools/detail/ceil_and_floor.hpp
  isVerificationFile: false
  path: tools/floor.hpp
  requiredBy:
  - tools/round.hpp
  - tools/floor_log.hpp
  - tools/pow_mod_cache.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bezout.test.cpp
  - tests/floor_log.test.cpp
documentation_of: tools/floor.hpp
layout: document
title: $\left\lfloor \frac{x}{y} \right\rfloor$
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> floor(M x, N y);
```

It returns $\left\lfloor \frac{x}{y} \right\rfloor$.

## Constraints
- $y \neq 0$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
