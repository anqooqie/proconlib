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
    path: tools/extended_garner.hpp
    title: Extended Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':heavy_check_mark:'
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':heavy_check_mark:'
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
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace tools {\n\n  template <typename M,\
    \ typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N\
    \ rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else {\n      if\
    \ (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      } else {\n  \
    \      return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"\
    tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T,\
    \ T, T> extgcd(T prev_r, T r) {\n    T prev_s = 1;\n    T prev_t = 0;\n    T s\
    \ = 0;\n    T t = 1;\n    while (r != 0) {\n      const T q = ::tools::quo(prev_r,\
    \ r);\n      const T next_r = prev_r - q * r;\n      prev_r = r;\n      r = next_r;\n\
    \      const T next_s = prev_s - q * s;\n      prev_s = s;\n      s = next_s;\n\
    \      const T next_t = prev_t - q * t;\n      prev_t = t;\n      t = next_t;\n\
    \    }\n\n    if (prev_r < T(0)) prev_r = -prev_r;\n    return {prev_s, prev_t,\
    \ prev_r};\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_EXTGCD_HPP\n#define TOOLS_EXTGCD_HPP\n\n#include <tuple>\n\
    #include \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n \
    \ ::std::tuple<T, T, T> extgcd(T prev_r, T r) {\n    T prev_s = 1;\n    T prev_t\
    \ = 0;\n    T s = 0;\n    T t = 1;\n    while (r != 0) {\n      const T q = ::tools::quo(prev_r,\
    \ r);\n      const T next_r = prev_r - q * r;\n      prev_r = r;\n      r = next_r;\n\
    \      const T next_s = prev_s - q * s;\n      prev_s = s;\n      s = next_s;\n\
    \      const T next_t = prev_t - q * t;\n      prev_t = t;\n      t = next_t;\n\
    \    }\n\n    if (prev_r < T(0)) prev_r = -prev_r;\n    return {prev_s, prev_t,\
    \ prev_r};\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/extgcd.hpp
  requiredBy:
  - tools/extended_garner.hpp
  - tools/bezout.hpp
  - tools/inv_mod.hpp
  - tools/extended_lucas.hpp
  - tools/garner.hpp
  - tools/tetration_mod.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/extended_lucas.test.cpp
  - tests/extended_garner.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/extgcd.test.cpp
  - tests/bezout.test.cpp
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
