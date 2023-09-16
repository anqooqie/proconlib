---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/extended_garner.hpp
    title: Extended Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':heavy_check_mark:'
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/log_mod.hpp
    title: $\log_x y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/sqrt_mod.hpp
    title: $\sqrt{x} \pmod{P}$
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extended_garner.test.cpp
    title: tests/extended_garner.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/log_mod.test.cpp
    title: tests/log_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sqrt_mod.test.cpp
    title: tests/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/inv_mod.hpp\"\n\n\n\n#include <cassert>\n#line 1 \"\
    tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#include <utility>\n#line 7 \"tools/extgcd.hpp\"\
    \n#include <algorithm>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n \
    \ constexpr float abs(const float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr\
    \ double abs(const double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long\
    \ double abs(const long double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr\
    \ int abs(const int x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const\
    \ long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const\
    \ long long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const\
    \ unsigned int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned\
    \ long x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 9 \"tools/extgcd.hpp\"\n\n\
    namespace tools {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T\
    \ prev_r, T r) {\n    const bool prev_r_is_neg = prev_r < T(0);\n    const bool\
    \ r_is_neg = r < T(0);\n\n    if (prev_r_is_neg) prev_r = -prev_r;\n    if (r_is_neg)\
    \ r = -r;\n\n    #ifndef NDEBUG\n    const T a = prev_r;\n    const T b = r;\n\
    \    #endif\n\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n    T t(1);\n\
    \    while (r != T(0)) {\n      const T q = prev_r / r;\n      ::std::tie(prev_r,\
    \ r) = ::std::make_pair(r, prev_r - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s,\
    \ prev_s - q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t -\
    \ q * t);\n    }\n\n    if (prev_r_is_neg) prev_s = -prev_s;\n    if (r_is_neg)\
    \ prev_t = -prev_t;\n\n    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r\
    \ / T(2), T(1)));\n    assert(::tools::abs(prev_t) <= ::std::max(a / prev_r /\
    \ T(2), T(1)));\n    return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n\
    }\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n\
    \      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return\
    \ -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) +\
    \ -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 7 \"tools/inv_mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T1, typename T2>\n  constexpr T2\
    \ inv_mod(const T1 x, const T2 m) {\n    const auto [x0, y0, gcd] = ::tools::extgcd(x,\
    \ m);\n    assert(gcd == 1);\n    return ::tools::mod(x0, m);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_INV_MOD_HPP\n#define TOOLS_INV_MOD_HPP\n\n#include <cassert>\n\
    #include \"tools/extgcd.hpp\"\n#include \"tools/mod.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T1, typename T2>\n  constexpr T2 inv_mod(const T1 x, const\
    \ T2 m) {\n    const auto [x0, y0, gcd] = ::tools::extgcd(x, m);\n    assert(gcd\
    \ == 1);\n    return ::tools::mod(x0, m);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/extgcd.hpp
  - tools/abs.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/inv_mod.hpp
  requiredBy:
  - tools/extended_lucas.hpp
  - tools/garner.hpp
  - tools/sqrt_mod.hpp
  - tools/log_mod.hpp
  - tools/tetration_mod.hpp
  - tools/extended_garner.hpp
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tetration_mod.test.cpp
  - tests/sqrt_mod.test.cpp
  - tests/extended_lucas.test.cpp
  - tests/extended_garner.test.cpp
  - tests/log_mod.test.cpp
documentation_of: tools/inv_mod.hpp
layout: document
title: $x^{-1} \pmod{M}$
---

```cpp
template <typename T1, typename T2>
constexpr T2 inv_mod(T1 x, T2 M);
```

It returns $x^{-1} \pmod{M}$.

## Constraints
- $M \geq 1$
- $\gcd(x, M) = 1$

## Time Complexity
- $O(\log(\min(\|x\|, M)))$

## License
- CC0

## Author
- anqooqie
