---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
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
    #include <utility>\n#include <cassert>\n#include <algorithm>\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\nnamespace tools {\n  constexpr float abs(const float x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr long double abs(const long double x) {\n   \
    \ return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0\
    \ ? -x : x;\n  }\n  constexpr long long abs(const long long x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n \
    \   return x;\n  }\n  constexpr unsigned long abs(const unsigned long x) {\n \
    \   return x;\n  }\n  constexpr unsigned long long abs(const unsigned long long\
    \ x) {\n    return x;\n  }\n}\n\n\n#line 9 \"tools/extgcd.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r)\
    \ {\n    const bool prev_r_is_neg = prev_r < T(0);\n    const bool r_is_neg =\
    \ r < T(0);\n\n    if (prev_r_is_neg) prev_r = -prev_r;\n    if (r_is_neg) r =\
    \ -r;\n\n    #ifndef NDEBUG\n    const T a = prev_r;\n    const T b = r;\n   \
    \ #endif\n\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n    T t(1);\n   \
    \ while (r != T(0)) {\n      const T q = prev_r / r;\n      ::std::tie(prev_r,\
    \ r) = ::std::make_pair(r, prev_r - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s,\
    \ prev_s - q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t -\
    \ q * t);\n    }\n\n    if (prev_r_is_neg) prev_s = -prev_s;\n    if (r_is_neg)\
    \ prev_t = -prev_t;\n\n    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r\
    \ / T(2), T(1)));\n    assert(::tools::abs(prev_t) <= ::std::max(a / prev_r /\
    \ T(2), T(1)));\n    return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n\
    }\n\n\n#line 7 \"tools/bezout.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  ::std::optional<::std::tuple<T, T, T, T>> bezout(const T a, const T b,\
    \ const T c) {\n    assert(a != T(0));\n    assert(b != T(0));\n    const auto\
    \ [x0, y0, gcd] = ::tools::extgcd(a, b);\n    return c % gcd == T(0) ? ::std::make_optional(::std::make_tuple(-b\
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
  - tools/abs.hpp
  isVerificationFile: false
  path: tools/bezout.hpp
  requiredBy: []
  timestamp: '2023-08-26 14:07:16+09:00'
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
- $ac$ is in `<T>`.
- $bc$ is in `<T>`.

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
