---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':question:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/sqrt_mod.test.cpp
    title: tests/sqrt_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/sqrt_mod.hpp\"\n\n\n\n#include <optional>\n#include\
    \ <cassert>\n#include <vector>\n#line 1 \"tools/is_prime.hpp\"\n\n\n\n#include\
    \ <array>\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\
    \n\n\n\n#include <iostream>\n#include <string>\n#line 7 \"tools/uint128_t.hpp\"\
    \n#include <cstddef>\n#include <algorithm>\n#line 1 \"tools/abs.hpp\"\n\n\n\n\
    namespace tools {\n  constexpr float abs(const float x) {\n    return x < 0 ?\
    \ -x : x;\n  }\n  constexpr double abs(const double x) {\n    return x < 0 ? -x\
    \ : x;\n  }\n  constexpr long double abs(const long double x) {\n    return x\
    \ < 0 ? -x : x;\n  }\n  constexpr int abs(const int x) {\n    return x < 0 ? -x\
    \ : x;\n  }\n  constexpr long abs(const long x) {\n    return x < 0 ? -x : x;\n\
    \  }\n  constexpr long long abs(const long long x) {\n    return x < 0 ? -x :\
    \ x;\n  }\n  constexpr unsigned int abs(const unsigned int x) {\n    return x;\n\
    \  }\n  constexpr unsigned long abs(const unsigned long x) {\n    return x;\n\
    \  }\n  constexpr unsigned long long abs(const unsigned long long x) {\n    return\
    \ x;\n  }\n}\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\nnamespace tools {\n  using\
    \ uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t abs(const ::tools::uint128_t&\
    \ x) {\n    return x;\n  }\n}\n\n::std::istream& operator>>(::std::istream& is,\
    \ ::tools::uint128_t& x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\
    \n  x = 0;\n  for (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0'\
    \ <= s[i] && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n\
    }\n\n::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n\
    \  if (x == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n  \
    \  s.push_back('0' + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(),\
    \ s.end());\n\n  return os << s;\n}\n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3\
    \ prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n\
    \    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n\
    \    if ((x >= 0) ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n\
    \  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\
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
    \ * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const\
    \ T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3\
    \ y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n   \
    \     r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n#line 7 \"tools/is_prime.hpp\"\
    \n\nnamespace tools {\n\n  constexpr bool is_prime(const unsigned long long n)\
    \ {\n    constexpr ::std::array<unsigned long long, 7> bases = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if\
    \ (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n    auto d = n -\
    \ 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const auto a : bases) {\n  \
    \    if (a % n == 0) return true;\n\n      auto power = d;\n      auto target\
    \ = ::tools::pow_mod(a, power, n);\n\n      bool is_composite = true;\n      if\
    \ (target == 1) is_composite = false;\n      for (; is_composite && power != n\
    \ - 1; power *= 2, target = ::tools::prod_mod(target, target, n)) {\n        if\
    \ (target == n - 1) is_composite = false;\n      }\n\n      if (is_composite)\
    \ {\n        return false;\n      }\n    }\n\n    return true;\n  }\n}\n\n\n#line\
    \ 1 \"tools/inv_mod.hpp\"\n\n\n\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include\
    \ <tuple>\n#include <utility>\n#line 9 \"tools/extgcd.hpp\"\n\nnamespace tools\
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
    }\n\n\n#line 7 \"tools/inv_mod.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2>\n  constexpr T2 inv_mod(const T1 x, const T2 m) {\n    const\
    \ auto [x0, y0, gcd] = ::tools::extgcd(x, m);\n    assert(gcd == 1);\n    return\
    \ ::tools::mod(x0, m);\n  }\n}\n\n\n#line 12 \"tools/sqrt_mod.hpp\"\n\nnamespace\
    \ tools {\n  inline ::std::optional<long long> sqrt_mod(long long a, const long\
    \ long p) {\n    assert(::tools::is_prime(p));\n    a = ::tools::mod(a, p);\n\n\
    \    if (p == 2) return a;\n    if (a == 0) return 0;\n    if (::tools::pow_mod(a,\
    \ (p - 1) / 2, p) != 1) return ::std::nullopt;\n\n    long long s, t;\n    for\
    \ (s = p - 1, t = 0; s % 2 == 0; s /= 2, ++t);\n\n    long long u;\n    for (u\
    \ = 1; ::tools::pow_mod(u, (p - 1) / 2, p) == 1; ++u);\n\n    ::std::vector<long\
    \ long> u_s(t);\n    u_s[0] = ::tools::pow_mod(u, s, p);\n    for (long long i\
    \ = 1; i < t; ++i) {\n      u_s[i] = ::tools::prod_mod(u_s[i - 1], u_s[i - 1],\
    \ p);\n    }\n\n    const long long ia = ::tools::inv_mod(a, p);\n\n    long long\
    \ x = ::tools::pow_mod(a, (s + 1) / 2, p);\n    while (true) {\n      long long\
    \ t_ = 0;\n      for (long long base = ::tools::prod_mod(ia, ::tools::prod_mod(x,\
    \ x, p), p); base != 1; base = ::tools::prod_mod(base, base, p), ++t_);\n    \
    \  if (t_ == 0) break;\n      x = ::tools::prod_mod(x, u_s[t - t_ - 1], p);\n\
    \    }\n\n    return x;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SQRT_MOD_HPP\n#define TOOLS_SQRT_MOD_HPP\n\n#include <optional>\n\
    #include <cassert>\n#include <vector>\n#include \"tools/is_prime.hpp\"\n#include\
    \ \"tools/mod.hpp\"\n#include \"tools/pow_mod.hpp\"\n#include \"tools/prod_mod.hpp\"\
    \n#include \"tools/inv_mod.hpp\"\n\nnamespace tools {\n  inline ::std::optional<long\
    \ long> sqrt_mod(long long a, const long long p) {\n    assert(::tools::is_prime(p));\n\
    \    a = ::tools::mod(a, p);\n\n    if (p == 2) return a;\n    if (a == 0) return\
    \ 0;\n    if (::tools::pow_mod(a, (p - 1) / 2, p) != 1) return ::std::nullopt;\n\
    \n    long long s, t;\n    for (s = p - 1, t = 0; s % 2 == 0; s /= 2, ++t);\n\n\
    \    long long u;\n    for (u = 1; ::tools::pow_mod(u, (p - 1) / 2, p) == 1; ++u);\n\
    \n    ::std::vector<long long> u_s(t);\n    u_s[0] = ::tools::pow_mod(u, s, p);\n\
    \    for (long long i = 1; i < t; ++i) {\n      u_s[i] = ::tools::prod_mod(u_s[i\
    \ - 1], u_s[i - 1], p);\n    }\n\n    const long long ia = ::tools::inv_mod(a,\
    \ p);\n\n    long long x = ::tools::pow_mod(a, (s + 1) / 2, p);\n    while (true)\
    \ {\n      long long t_ = 0;\n      for (long long base = ::tools::prod_mod(ia,\
    \ ::tools::prod_mod(x, x, p), p); base != 1; base = ::tools::prod_mod(base, base,\
    \ p), ++t_);\n      if (t_ == 0) break;\n      x = ::tools::prod_mod(x, u_s[t\
    \ - t_ - 1], p);\n    }\n\n    return x;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  isVerificationFile: false
  path: tools/sqrt_mod.hpp
  requiredBy: []
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/sqrt_mod.test.cpp
documentation_of: tools/sqrt_mod.hpp
layout: document
title: $\sqrt{x} \pmod{P}$
---

```cpp
std::optional<long long> sqrt_mod(long long x, long long P);
```

It returns one of $y$s such that $y^2 \equiv x \pmod{P}$ if it exists.
If such $y$ does not exist, it returns `std::nullopt`.

## Constraints
- $P$ is a prime.

## Time Complexity
- $O\left(\left(\log P\right)^2\right)$

## License
- CC0

## Author
- anqooqie
