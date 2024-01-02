---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
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
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bernoulli.hpp
    title: Bernoulli numbers $B_k \pmod{P}$ for $0 \leq k \leq n$
  - icon: ':question:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':question:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':question:'
    path: tools/convolution.hpp
    title: Convolution
  - icon: ':heavy_check_mark:'
    path: tools/divisors.hpp
    title: List all divisors
  - icon: ':heavy_check_mark:'
    path: tools/extended_lucas.hpp
    title: Extended Lucas' theorem
  - icon: ':question:'
    path: tools/fact_mod_cache.hpp
    title: Precompute $n^{-1} \pmod{P}, n! \pmod{P}, n!^{-1} \pmod{P}, {}_n C_r \pmod{P},
      {}_n P_r \pmod{P}$
  - icon: ':question:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':question:'
    path: tools/garner2.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$ and $\mathbb{Z} /
      M_2 \mathbb{Z}$
  - icon: ':question:'
    path: tools/garner3.hpp
    title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$, $\mathbb{Z} / M_2
      \mathbb{Z}$ and $\mathbb{Z} / M_3 \mathbb{Z}$
  - icon: ':question:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/log_mod.hpp
    title: $\log_x y \pmod{M}$
  - icon: ':x:'
    path: tools/partition_function.hpp
    title: Partition function $P(i, i) \pmod{M}$ for $0 \leq i \leq n$ and $P(i, j)
      \pmod{M}$ for $0 \leq i \leq n, 0 \leq j \leq k$
  - icon: ':question:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':question:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':heavy_check_mark:'
    path: tools/primitive_root.hpp
    title: Primitive root
  - icon: ':question:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':x:'
    path: tools/sparse_fps_pow.hpp
    title: Power of a sparse FPS
  - icon: ':heavy_check_mark:'
    path: tools/sqrt_mod.hpp
    title: $\sqrt{x} \pmod{P}$
  - icon: ':x:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind $S(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  - icon: ':x:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':x:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/berlekamp_massey.test.cpp
    title: tests/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bernoulli.test.cpp
    title: tests/bernoulli.test.cpp
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
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/double.test.cpp
    title: tests/convolution/double.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/dynamic_mod.test.cpp
    title: tests/convolution/dynamic_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/mod1000000007.test.cpp
    title: tests/convolution/mod1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convolution/mod998244353.test.cpp
    title: tests/convolution/mod998244353.test.cpp
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
    path: tests/divisors.test.cpp
    title: tests/divisors.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fact_mod_cache.test.cpp
    title: tests/fact_mod_cache.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fastio/string.test.cpp
    title: tests/fastio/string.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_mod998244353.test.cpp
    title: tests/fps/exp_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/exp_other_mods.test.cpp
    title: tests/fps/exp_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/inv_mod998244353.test.cpp
    title: tests/fps/inv_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/inv_other_mods.test.cpp
    title: tests/fps/inv_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/log_mod998244353.test.cpp
    title: tests/fps/log_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/log_other_mods.test.cpp
    title: tests/fps/log_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/pow_mod998244353.test.cpp
    title: tests/fps/pow_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/pow_other_mods.test.cpp
    title: tests/fps/pow_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/is_prime.test.cpp
    title: tests/is_prime.test.cpp
  - icon: ':x:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/log_mod.test.cpp
    title: tests/log_mod.test.cpp
  - icon: ':x:'
    path: tests/partition_function/n.test.cpp
    title: tests/partition_function/n.test.cpp
  - icon: ':x:'
    path: tests/partition_function/n_k.test.cpp
    title: tests/partition_function/n_k.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':x:'
    path: tests/polynomial/multidimensional.test.cpp
    title: tests/polynomial/multidimensional.test.cpp
  - icon: ':x:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':x:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/prime_factorization.test.cpp
    title: tests/prime_factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/primitive_root.test.cpp
    title: tests/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/minus.test.cpp
    title: tests/rational/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/multiplies.test.cpp
    title: tests/rational/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/plus.test.cpp
    title: tests/rational/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/random.test.cpp
    title: tests/rational/random.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/fraction.test.cpp
    title: tests/sparse_fps_pow/fraction.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/regular.test.cpp
    title: tests/sparse_fps_pow/regular.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sqrt_mod.test.cpp
    title: tests/sqrt_mod.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd.test.cpp
    title: tests/stirling_2nd.test.cpp
  - icon: ':x:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':x:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\
    \n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    if (lhs >= M(0)) {\n      return lhs / rhs;\n    } else {\n      if (rhs\
    \ >= N(0)) {\n        return -((-lhs - T(1) + rhs) / rhs);\n      } else {\n \
    \       return (-lhs - T(1) + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line\
    \ 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n\
    \    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n   \
    \   return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs)\
    \ * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"\
    tools/uint128_t.hpp\"\n\n\n\n#include <iostream>\n#include <string>\n#include\
    \ <cassert>\n#include <cstddef>\n#include <algorithm>\n#line 1 \"tools/abs.hpp\"\
    \n\n\n\nnamespace tools {\n  constexpr float abs(const float x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr long double abs(const long double x) {\n   \
    \ return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return\
    \ x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0\
    \ ? -x : x;\n  }\n  constexpr long long abs(const long long x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n \
    \   return x;\n  }\n  constexpr unsigned long abs(const unsigned long x) {\n \
    \   return x;\n  }\n  constexpr unsigned long long abs(const unsigned long long\
    \ x) {\n    return x;\n  }\n}\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\nnamespace\
    \ tools {\n  using uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t\
    \ abs(const ::tools::uint128_t& x) {\n    return x;\n  }\n}\n\n::std::istream&\
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
    \ = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T1, typename T2, typename T3>\n\
    \  constexpr T3 pow_mod(const T1 x, T2 n, const T3 m) {\n    if (m == 1) return\
    \ 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x, m);\n    while (n > 0) {\n   \
    \   if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r, y, m);\n      }\n   \
    \   y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n    return r;\n  }\n\
    }\n\n\n"
  code: "#ifndef TOOLS_POW_MOD_HPP\n#define TOOLS_POW_MOD_HPP\n\n#include \"tools/mod.hpp\"\
    \n#include \"tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const T1 x, T2 n, const\
    \ T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x,\
    \ m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r,\
    \ y, m);\n      }\n      y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n\
    \    return r;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  isVerificationFile: false
  path: tools/pow_mod.hpp
  requiredBy:
  - tools/partition_function.hpp
  - tools/berlekamp_massey.hpp
  - tools/fps.hpp
  - tools/prime_factorization.hpp
  - tools/bigdecimal.hpp
  - tools/garner2.hpp
  - tools/extended_lucas.hpp
  - tools/sqrt_mod.hpp
  - tools/log_mod.hpp
  - tools/bostan_mori.hpp
  - tools/sparse_fps_pow.hpp
  - tools/fact_mod_cache.hpp
  - tools/bernoulli.hpp
  - tools/rational.hpp
  - tools/convolution.hpp
  - tools/bigint.hpp
  - tools/totient.hpp
  - tools/divisors.hpp
  - tools/is_prime.hpp
  - tools/polynomial.hpp
  - tools/stirling_2nd.hpp
  - tools/tetration_mod.hpp
  - tools/primitive_root.hpp
  - tools/garner3.hpp
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/bigint/modulus.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/fps/exp_other_mods.test.cpp
  - tests/fps/log_mod998244353.test.cpp
  - tests/fps/inv_mod998244353.test.cpp
  - tests/fps/inv_other_mods.test.cpp
  - tests/fps/exp_mod998244353.test.cpp
  - tests/fps/pow_other_mods.test.cpp
  - tests/fps/pow_mod998244353.test.cpp
  - tests/fps/log_other_mods.test.cpp
  - tests/convolution/mod1000000007.test.cpp
  - tests/convolution/dynamic_mod.test.cpp
  - tests/convolution/double.test.cpp
  - tests/convolution/mod998244353.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/fact_mod_cache.test.cpp
  - tests/primitive_root.test.cpp
  - tests/divisors.test.cpp
  - tests/partition_function/n.test.cpp
  - tests/partition_function/n_k.test.cpp
  - tests/totient.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/log_mod.test.cpp
  - tests/rational/random.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/minus.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/sqrt_mod.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/is_prime.test.cpp
  - tests/prime_factorization.test.cpp
  - tests/bernoulli.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/stirling_2nd.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/fastio/string.test.cpp
  - tests/extended_lucas.test.cpp
documentation_of: tools/pow_mod.hpp
layout: document
title: $x^y \pmod{M}$
---

```cpp
template <typename T1, typename T2, typename T3>
constexpr T3 pow_mod(T1 x, T2 y, T3 M);
```

It returns $x^y \pmod{M}$.

Note: In this function, $0^0$ is $1$.

## Constraints
- $y \geq 0$
- $M \geq 1$

## Time Complexity
- $O(\log y)$

## License
- CC0

## Author
- anqooqie
