---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/sqrt_mod.hpp
    title: $\sqrt{x} \pmod{P}$
  - icon: ':heavy_check_mark:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sqrt_mod
    links:
    - https://judge.yosupo.jp/problem/sqrt_mod
  bundledCode: "#line 1 \"tests/sqrt_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\
    \n\n#include <iostream>\n#line 1 \"tools/sqrt_mod.hpp\"\n\n\n\n#include <optional>\n\
    #include <cassert>\n#include <vector>\n#line 1 \"tools/is_prime.hpp\"\n\n\n\n\
    #include <array>\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\
    \n\n\n\n#line 5 \"tools/uint128_t.hpp\"\n#include <string>\n#line 7 \"tools/uint128_t.hpp\"\
    \n#include <cstddef>\n#include <algorithm>\n\nnamespace tools {\n  using uint128_t\
    \ = unsigned __int128;\n}\n\n::std::istream& operator>>(::std::istream& is, ::tools::uint128_t&\
    \ x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for\
    \ (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n\
    ::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n  if (x\
    \ == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n    s.push_back('0'\
    \ + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(), s.end());\n\n  return\
    \ os << s;\n}\n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x,\
    \ const T2 y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n    u128 prod_mod\
    \ = u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0)\
    \ ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\
    \n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\n\
    namespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \ <tuple>\n#include <utility>\n#line 7 \"tools/extgcd.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r)\
    \ {\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n    T t(1);\n    while (r\
    \ != T(0)) {\n      const T q = ::tools::quo(prev_r, r);\n      ::std::tie(prev_r,\
    \ r) = ::std::make_pair(r, prev_r - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s,\
    \ prev_s - q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t -\
    \ q * t);\n    }\n\n    if (prev_r < T(0)) prev_r = -prev_r;\n    return ::std::make_tuple(prev_s,\
    \ prev_t, prev_r);\n  }\n}\n\n\n#line 7 \"tools/inv_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T1, typename T2>\n  constexpr T2 inv_mod(const T1\
    \ x, const T2 m) {\n    const auto [x0, y0, gcd] = ::tools::extgcd(x, m);\n  \
    \  assert(gcd == 1);\n    return ::tools::mod(x0, m);\n  }\n}\n\n\n#line 12 \"\
    tools/sqrt_mod.hpp\"\n\nnamespace tools {\n  inline ::std::optional<long long>\
    \ sqrt_mod(long long a, const long long p) {\n    assert(::tools::is_prime(p));\n\
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
    \ - t_ - 1], p);\n    }\n\n    return x;\n  }\n}\n\n\n#line 5 \"tests/sqrt_mod.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll T;\n  std::cin >> T;\n  for (ll t = 0; t < T; ++t) {\n    ll Y, P;\n  \
    \  std::cin >> Y >> P;\n    const auto answer = ::tools::sqrt_mod(Y, P);\n   \
    \ std::cout << (answer ? *answer : -1) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_mod\"\n\n#include\
    \ <iostream>\n#include \"tools/sqrt_mod.hpp\"\n\nusing ll = long long;\n\nint\
    \ main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll T;\n  std::cin >> T;\n  for (ll t = 0; t < T; ++t) {\n    ll Y, P;\n  \
    \  std::cin >> Y >> P;\n    const auto answer = ::tools::sqrt_mod(Y, P);\n   \
    \ std::cout << (answer ? *answer : -1) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/sqrt_mod.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  isVerificationFile: true
  path: tests/sqrt_mod.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 17:29:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/sqrt_mod.test.cpp
layout: document
redirect_from:
- /verify/tests/sqrt_mod.test.cpp
- /verify/tests/sqrt_mod.test.cpp.html
title: tests/sqrt_mod.test.cpp
---
