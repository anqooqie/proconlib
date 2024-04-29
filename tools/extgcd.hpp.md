---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
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
  - icon: ':question:'
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
  - icon: ':x:'
    path: tools/twelvefold_way.hpp
    title: Twelvefold way
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
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#include <utility>\n\
    #include <cassert>\n#include <algorithm>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace\
    \ tools {\n  constexpr float abs(const float x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr double abs(const double x) {\n    return x < 0 ? -x : x;\n \
    \ }\n  constexpr long double abs(const long double x) {\n    return x < 0 ? -x\
    \ : x;\n  }\n  constexpr int abs(const int x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr long abs(const long x) {\n    return x < 0 ? -x : x;\n  }\n\
    \  constexpr long long abs(const long long x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr unsigned int abs(const unsigned int x) {\n    return x;\n  }\n\
    \  constexpr unsigned long abs(const unsigned long x) {\n    return x;\n  }\n\
    \  constexpr unsigned long long abs(const unsigned long long x) {\n    return\
    \ x;\n  }\n}\n\n\n#line 9 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {\n    const bool\
    \ prev_r_is_neg = prev_r < T(0);\n    const bool r_is_neg = r < T(0);\n\n    if\
    \ (prev_r_is_neg) prev_r = -prev_r;\n    if (r_is_neg) r = -r;\n\n    #ifndef\
    \ NDEBUG\n    const T a = prev_r;\n    const T b = r;\n    #endif\n\n    T prev_s(1);\n\
    \    T prev_t(0);\n    T s(0);\n    T t(1);\n    while (r != T(0)) {\n      const\
    \ T q = prev_r / r;\n      ::std::tie(prev_r, r) = ::std::make_pair(r, prev_r\
    \ - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s, prev_s - q * s);\n\
    \      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t - q * t);\n    }\n\n\
    \    if (prev_r_is_neg) prev_s = -prev_s;\n    if (r_is_neg) prev_t = -prev_t;\n\
    \n    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r / T(2), T(1)));\n \
    \   assert(::tools::abs(prev_t) <= ::std::max(a / prev_r / T(2), T(1)));\n   \
    \ return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_EXTGCD_HPP\n#define TOOLS_EXTGCD_HPP\n\n#include <tuple>\n\
    #include <utility>\n#include <cassert>\n#include <algorithm>\n#include \"tools/abs.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T\
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
    }\n\n#endif\n"
  dependsOn:
  - tools/abs.hpp
  isVerificationFile: false
  path: tools/extgcd.hpp
  requiredBy:
  - tools/garner.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  - tools/inv_mod.hpp
  - tools/extended_garner.hpp
  - tools/log_mod.hpp
  - tools/extended_lucas.hpp
  - tools/tetration_mod.hpp
  - tools/sqrt_mod.hpp
  - tools/twelvefold_way.hpp
  - tools/bezout.hpp
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/sqrt_mod.test.cpp
  - tests/log_mod.test.cpp
  - tests/extended_lucas.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/extended_garner.test.cpp
  - tests/bezout.test.cpp
  - tests/extgcd.test.cpp
  - tests/has_mod.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
documentation_of: tools/extgcd.hpp
layout: document
title: Extended Euclidean algorithm
---

```cpp
template <typename T>
std::tuple<T, T, T> extgcd(T a, T b);
```

It returns $(x_0, y_0, \gcd(a, b))$ which satisfies

$$\begin{align*}
\left\{\begin{array}{l}
a x_0 + b y_0 = \gcd(a, b)\\
|x_0| \leq \max\left(1, \left\lfloor\frac{|b|}{2 \gcd(a, b)}\right\rfloor\right)\\
|y_0| \leq \max\left(1, \left\lfloor\frac{|a|}{2 \gcd(a, b)}\right\rfloor\right)
\end{array}\right.&
\end{align*}$$

In this function, we define $\gcd(a, 0) = a$, $\gcd(0, b) = b$ and $\gcd(0, 0) = 0$.

### Constraints
- None

### Time Complexity
- $O(\log(\min(\|a\|, \|b\|)))$

### License
- CC0

### Author
- anqooqie
