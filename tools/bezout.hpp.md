---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bezout.test.cpp
    title: tests/bezout.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/bezout.hpp\"\n\n\n\n#include <optional>\n#include\
    \ <tuple>\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#line 1 \"tools/quo.hpp\"\n\n\n\
    \n#include <type_traits>\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N rhs) {\n\
    \    if (lhs >= 0) {\n      return lhs / rhs;\n    } else {\n      if (rhs >=\
    \ 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      } else {\n        return\
    \ (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/extgcd.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T\
    \ prev_r, T r) {\n    T prev_s = 1;\n    T prev_t = 0;\n    T s = 0;\n    T t\
    \ = 1;\n    while (r != 0) {\n      const T q = ::tools::quo(prev_r, r);\n   \
    \   const T next_r = prev_r - q * r;\n      prev_r = r;\n      r = next_r;\n \
    \     const T next_s = prev_s - q * s;\n      prev_s = s;\n      s = next_s;\n\
    \      const T next_t = prev_t - q * t;\n      prev_t = t;\n      t = next_t;\n\
    \    }\n\n    if (prev_r < T(0)) prev_r = -prev_r;\n    return {prev_s, prev_t,\
    \ prev_r};\n  }\n}\n\n\n#line 7 \"tools/bezout.hpp\"\n\nnamespace tools {\n  template\
    \ <typename T>\n  ::std::optional<::std::tuple<T, T, T, T>> bezout(const T a,\
    \ const T b, const T c) {\n    assert(a != 0);\n    assert(b != 0);\n    const\
    \ auto [x0, y0, gcd] = ::tools::extgcd(a, b);\n    return c % gcd == 0 ? ::std::make_optional(::std::make_tuple(-b\
    \ / gcd, c / gcd * x0, a / gcd, c / gcd * y0)) : ::std::nullopt;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_BEZOUT_HPP\n#define TOOLS_BEZOUT_HPP\n\n#include <optional>\n\
    #include <tuple>\n#include \"tools/extgcd.hpp\"\n\nnamespace tools {\n  template\
    \ <typename T>\n  ::std::optional<::std::tuple<T, T, T, T>> bezout(const T a,\
    \ const T b, const T c) {\n    assert(a != 0);\n    assert(b != 0);\n    const\
    \ auto [x0, y0, gcd] = ::tools::extgcd(a, b);\n    return c % gcd == 0 ? ::std::make_optional(::std::make_tuple(-b\
    \ / gcd, c / gcd * x0, a / gcd, c / gcd * y0)) : ::std::nullopt;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/extgcd.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/bezout.hpp
  requiredBy: []
  timestamp: '2021-06-19 01:30:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bezout.test.cpp
documentation_of: tools/bezout.hpp
layout: document
title: "B\xE9zout's identity"
---

```cpp
template <typename T>
std::optional<std::tuple<T, T, T, T>> bezout(T a, T b, T c);
```

It solves $ax + by = c$ for $x$ and $y$ over the integers.
It returns four integers $p, q, r, s$ if the solutions of the equation exist.
They mean that $x$ can be denoted as $pm + q$ and $y$ can be denoted as $rm + s$ for any integer $m$.

## Constraints
- $a \neq 0$
- $b \neq 0$

## Time Complexity
- $O(\log(\min(\|a\|, \|b\|)))$

## Note
The solutions of the equation exist if and only if $c \equiv 0 \pmod{\gcd(a, b)}$.
If the solutions exist, the following equations hold when we denote a particular solution of $a x' + b y' = \gcd(a, b)$ as $(x'_0, y'_0)$.

$$\begin{align*}
p &= -\frac{b}{\gcd(a, b)}\\
q &= \frac{c}{\gcd(a, b)} x'_0\\
r &= \frac{a}{\gcd(a, b)}\\
s &= \frac{c}{\gcd(a, b)} y'_0
\end{align*}$$

If $a, b, c, x, y \geq 0$, $\left\lceil -\frac{c y'_0}{a} \right\rceil \leq m \leq \left\lfloor \frac{c x'_0}{b} \right\rfloor$ holds.

## License
- CC0

## Author
- anqooqie
