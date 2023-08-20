---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':question:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':question:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':question:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':question:'
    path: tools/rational.hpp
    title: Rational number
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/cast_to_long_long.test.cpp
    title: tests/bigdecimal/cast_to_long_long.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/divides.test.cpp
    title: tests/bigdecimal/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/hand.test.cpp
    title: tests/bigdecimal/hand.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/minus.test.cpp
    title: tests/bigdecimal/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/multiplies.test.cpp
    title: tests/bigdecimal/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/plus.test.cpp
    title: tests/bigdecimal/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/random.test.cpp
    title: tests/bigdecimal/random.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/rounding.test.cpp
    title: tests/bigdecimal/rounding.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/divides.test.cpp
    title: tests/bigint/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/minus.test.cpp
    title: tests/bigint/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/modulus.test.cpp
    title: tests/bigint/modulus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/multiplies.test.cpp
    title: tests/bigint/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/plus.test.cpp
    title: tests/bigint/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fastio/string.test.cpp
    title: tests/fastio/string.test.cpp
  - icon: ':x:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':x:'
    path: tests/rational/minus.test.cpp
    title: tests/rational/minus.test.cpp
  - icon: ':x:'
    path: tests/rational/multiplies.test.cpp
    title: tests/rational/multiplies.test.cpp
  - icon: ':x:'
    path: tests/rational/plus.test.cpp
    title: tests/rational/plus.test.cpp
  - icon: ':x:'
    path: tests/rational/random.test.cpp
    title: tests/rational/random.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/garner2.hpp\"\n\n\n\n#include <cassert>\n#line 1 \"\
    tools/is_prime.hpp\"\n\n\n\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\n\
    \n\n\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\n#include <iostream>\n#include <string>\n\
    #line 7 \"tools/uint128_t.hpp\"\n#include <cstddef>\n#include <algorithm>\n\n\
    namespace tools {\n  using uint128_t = unsigned __int128;\n}\n\n::std::istream&\
    \ operator>>(::std::istream& is, ::tools::uint128_t& x) {\n  ::std::string s;\n\
    \  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for (::std::size_t i = s[0]\
    \ == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i] && s[i] <= '9');\n    x\
    \ = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream&\
    \ os, ::tools::uint128_t x) {\n  if (x == 0) return os << '0';\n\n  ::std::string\
    \ s;\n  while (x > 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n \
    \ ::std::reverse(s.begin(), s.end());\n\n  return os << s;\n}\n\n\n#line 5 \"\
    tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template <typename T1, typename\
    \ T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m)\
    \ {\n    using u128 = ::tools::uint128_t;\n    u128 prod_mod = u128(x >= 0 ? x\
    \ : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >= 0)) prod_mod\
    \ = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\
    \n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n\
    \      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return\
    \ -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) +\
    \ -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T1, typename T2, typename T3>\n\
    \  constexpr T3 pow_mod(const T1 x, T2 n, const T3 m) {\n    if (m == 1) return\
    \ 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x, m);\n    while (n > 0) {\n   \
    \   if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r, y, m);\n      }\n   \
    \   y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n    return r;\n  }\n\
    }\n\n\n#line 7 \"tools/is_prime.hpp\"\n\nnamespace tools {\n\n  constexpr bool\
    \ is_prime(const unsigned long long n) {\n    constexpr ::std::array<unsigned\
    \ long long, 7> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n\
    \    if (n <= 1) return false;\n    if (n == 2) return true;\n    if (n % 2 ==\
    \ 0) return false;\n\n    auto d = n - 1;\n    for (; d % 2 == 0; d /= 2);\n\n\
    \    for (const auto a : bases) {\n      if (a % n == 0) return true;\n\n    \
    \  auto power = d;\n      auto target = ::tools::pow_mod(a, power, n);\n\n   \
    \   bool is_composite = true;\n      if (target == 1) is_composite = false;\n\
    \      for (; is_composite && power != n - 1; power *= 2, target = ::tools::prod_mod(target,\
    \ target, n)) {\n        if (target == n - 1) is_composite = false;\n      }\n\
    \n      if (is_composite) {\n        return false;\n      }\n    }\n\n    return\
    \ true;\n  }\n}\n\n\n#line 6 \"tools/garner2.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M1, typename M2>\n  long long garner2(const M1& a, const M2& b) {\n\
    \    using ull = unsigned long long;\n    static constexpr ull m1_m2 = ull(M1::mod())\
    \ * ull(M2::mod());\n    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\
    \n    assert(M1::mod() < M2::mod());\n    assert(::tools::is_prime(M1::mod()));\n\
    \    assert(::tools::is_prime(M2::mod()));\n\n    // t = (b - a) / M1; (mod M2)\n\
    \    // return a + t * M1;\n    const M2 t = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n\
    \    ull r = t.val();\n    r *= M1::mod();\n    r += a.val();\n    if (r >= m1_m2)\
    \ r -= m1_m2;\n    return r;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_GARNER2_HPP\n#define TOOLS_GARNER2_HPP\n\n#include <cassert>\n\
    #include \"tools/is_prime.hpp\"\n\nnamespace tools {\n\n  template <typename M1,\
    \ typename M2>\n  long long garner2(const M1& a, const M2& b) {\n    using ull\
    \ = unsigned long long;\n    static constexpr ull m1_m2 = ull(M1::mod()) * ull(M2::mod());\n\
    \    static const M2 m1_inv_mod_m2 = M2::raw(M1::mod()).inv();\n\n    assert(M1::mod()\
    \ < M2::mod());\n    assert(::tools::is_prime(M1::mod()));\n    assert(::tools::is_prime(M2::mod()));\n\
    \n    // t = (b - a) / M1; (mod M2)\n    // return a + t * M1;\n    const M2 t\
    \ = (b - M2::raw(a.val())) * m1_inv_mod_m2;\n    ull r = t.val();\n    r *= M1::mod();\n\
    \    r += a.val();\n    if (r >= m1_m2) r -= m1_m2;\n    return r;\n  }\n}\n\n\
    #endif\n"
  dependsOn:
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/garner2.hpp
  requiredBy:
  - tools/bigint.hpp
  - tools/bigdecimal.hpp
  - tools/rational.hpp
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/bigint/modulus.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/fastio/string.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/random.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/line_2d/projection.test.cpp
documentation_of: tools/garner2.hpp
layout: document
title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$ and $\mathbb{Z} / M_2
  \mathbb{Z}$
---

```cpp
template <typename M1, typename M2>
long long garner2(M1 a, M2 b);
```

It solves the following modular equation system and returns $x \bmod M_1 M_2$ where $M_1$ is `M1::mod()` and $M_2$ is `M2::mod()`.

$$\begin{align*}
\left\{\begin{array}{ll}
x \equiv a &\pmod{M_1}\\
x \equiv b &\pmod{M_2}
\end{array}\right.&
\end{align*}$$

It is useful to reconstruct $x$ less than $M_1 M_2$ from $x \bmod M_1$ and $x \bmod M_2$.

## Constraints
- `M1` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M2` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $M_1$ is a prime.
- $M_2$ is a prime.
- $M_1 < M_2$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
