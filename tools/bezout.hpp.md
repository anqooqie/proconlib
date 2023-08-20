---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ <tuple>\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#line 5 \"tools/extgcd.hpp\"\n\
    #include <utility>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#include <type_traits>\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
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
    \n#line 7 \"tools/bezout.hpp\"\n\nnamespace tools {\n  template <typename T>\n\
    \  ::std::optional<::std::tuple<T, T, T, T>> bezout(const T a, const T b, const\
    \ T c) {\n    assert(a != T(0));\n    assert(b != T(0));\n    const auto [x0,\
    \ y0, gcd] = ::tools::extgcd(a, b);\n    return c % gcd == T(0) ? ::std::make_optional(::std::make_tuple(-b\
    \ / gcd, c / gcd * x0, a / gcd, c / gcd * y0)) : ::std::nullopt;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_BEZOUT_HPP\n#define TOOLS_BEZOUT_HPP\n\n#include <optional>\n\
    #include <tuple>\n#include \"tools/extgcd.hpp\"\n\nnamespace tools {\n  template\
    \ <typename T>\n  ::std::optional<::std::tuple<T, T, T, T>> bezout(const T a,\
    \ const T b, const T c) {\n    assert(a != T(0));\n    assert(b != T(0));\n  \
    \  const auto [x0, y0, gcd] = ::tools::extgcd(a, b);\n    return c % gcd == T(0)\
    \ ? ::std::make_optional(::std::make_tuple(-b / gcd, c / gcd * x0, a / gcd, c\
    \ / gcd * y0)) : ::std::nullopt;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/extgcd.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/bezout.hpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
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
