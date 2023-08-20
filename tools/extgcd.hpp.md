---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bezout.hpp
    title: "B\xE9zout's identity"
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/extended_garner.hpp
    title: Extended Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':question:'
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':question:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/log_mod.hpp
    title: $\log_x y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':x:'
    path: tools/sqrt_mod.hpp
    title: $\sqrt{x} \pmod{P}$
  - icon: ':x:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bezout.test.cpp
    title: tests/bezout.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_garner.test.cpp
    title: tests/extended_garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extgcd.test.cpp
    title: tests/extgcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/log_mod.test.cpp
    title: tests/log_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':x:'
    path: tests/sqrt_mod.test.cpp
    title: tests/sqrt_mod.test.cpp
  - icon: ':x:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#include <utility>\n\
    #line 1 \"tools/quo.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace tools {\n\
    \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N>\
    \ quo(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    if (lhs >= M(0)) {\n      return lhs / rhs;\n    } else {\n      if (rhs\
    \ >= N(0)) {\n        return -((-lhs - T(1) + rhs) / rhs);\n      } else {\n \
    \       return (-lhs - T(1) + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line\
    \ 7 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T,\
    \ T, T> extgcd(T prev_r, T r) {\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n\
    \    T t(1);\n    while (r != T(0)) {\n      const T q = ::tools::quo(prev_r,\
    \ r);\n      ::std::tie(prev_r, r) = ::std::make_pair(r, prev_r - q * r);\n  \
    \    ::std::tie(prev_s, s) = ::std::make_pair(s, prev_s - q * s);\n      ::std::tie(prev_t,\
    \ t) = ::std::make_pair(t, prev_t - q * t);\n    }\n\n    if (prev_r < T(0)) prev_r\
    \ = -prev_r;\n    return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n}\n\n\
    \n"
  code: "#ifndef TOOLS_EXTGCD_HPP\n#define TOOLS_EXTGCD_HPP\n\n#include <tuple>\n\
    #include <utility>\n#include \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {\n    T prev_s(1);\n\
    \    T prev_t(0);\n    T s(0);\n    T t(1);\n    while (r != T(0)) {\n      const\
    \ T q = ::tools::quo(prev_r, r);\n      ::std::tie(prev_r, r) = ::std::make_pair(r,\
    \ prev_r - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s, prev_s -\
    \ q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t - q * t);\n\
    \    }\n\n    if (prev_r < T(0)) prev_r = -prev_r;\n    return ::std::make_tuple(prev_s,\
    \ prev_t, prev_r);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/extgcd.hpp
  requiredBy:
  - tools/rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  - tools/garner.hpp
  - tools/inv_mod.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/sqrt_mod.hpp
  - tools/extended_garner.hpp
  - tools/bezout.hpp
  - tools/log_mod.hpp
  - tools/extended_lucas.hpp
  - tools/tetration_mod.hpp
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/extended_lucas.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/extended_garner.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/has_mod.test.cpp
  - tests/bezout.test.cpp
  - tests/log_mod.test.cpp
  - tests/sqrt_mod.test.cpp
  - tests/extgcd.test.cpp
documentation_of: tools/extgcd.hpp
layout: document
title: Extended Euclidean algorithm
---

```cpp
template <typename T>
std::tuple<T, T, T> extgcd(T a, T b);
```

It returns $(x_0, y_0, \gcd(a, b))$ which satisfies $a \cdot x_0 + b \cdot y_0 = \gcd(a, b)$.
In this function, we define $\gcd(a, 0) = a$, $\gcd(0, b) = b$ and $\gcd(0, 0) = 0$.

## Constraints
- None

## Time Complexity
- $O(\log(\min(\|a\|, \|b\|)))$

## License
- CC0

## Author
- anqooqie
