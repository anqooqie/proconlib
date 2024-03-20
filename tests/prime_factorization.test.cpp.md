---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':heavy_check_mark:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':heavy_check_mark:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
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
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"tests/prime_factorization.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/factorize\"\n\n#include <iostream>\n#include <vector>\n\
    #line 1 \"tools/prime_factorization.hpp\"\n\n\n\n#line 5 \"tools/prime_factorization.hpp\"\
    \n#include <cassert>\n#include <queue>\n#include <utility>\n#include <algorithm>\n\
    #include <cmath>\n#include <numeric>\n#line 1 \"tools/is_prime.hpp\"\n\n\n\n#include\
    \ <array>\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\
    \n\n\n\n#line 5 \"tools/uint128_t.hpp\"\n#include <string>\n#line 7 \"tools/uint128_t.hpp\"\
    \n#include <cstddef>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr\
    \ float abs(const float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double\
    \ abs(const double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double\
    \ abs(const long double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int\
    \ abs(const int x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const\
    \ long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const\
    \ long long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const\
    \ unsigned int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned\
    \ long x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\
    \nnamespace tools {\n  using uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t\
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
    \ true;\n  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 6 \"tools/floor_log2.hpp\"\n#include <limits>\n#line 1 \"tools/popcount.hpp\"\
    \n\n\n\n#line 7 \"tools/popcount.hpp\"\n#include <cstdint>\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  T popcount(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x >= 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::popcount<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      if constexpr (::std::numeric_limits<T>::digits == 8) {\n   \
    \     x = (x & UINT8_C(0x55)) + (x >> 1 & UINT8_C(0x55));\n        x = (x & UINT8_C(0x33))\
    \ + (x >> 2 & UINT8_C(0x33));\n        x = (x & UINT8_C(0x0f)) + (x >> 4 & UINT8_C(0x0f));\n\
    \      } else if constexpr (::std::numeric_limits<T>::digits == 16) {\n      \
    \  x = (x & UINT16_C(0x5555)) + (x >> 1 & UINT16_C(0x5555));\n        x = (x &\
    \ UINT16_C(0x3333)) + (x >> 2 & UINT16_C(0x3333));\n        x = (x & UINT16_C(0x0f0f))\
    \ + (x >> 4 & UINT16_C(0x0f0f));\n        x = (x & UINT16_C(0x00ff)) + (x >> 8\
    \ & UINT16_C(0x00ff));\n      } else if constexpr (::std::numeric_limits<T>::digits\
    \ == 32) {\n        x = (x & UINT32_C(0x55555555)) + (x >> 1 & UINT32_C(0x55555555));\n\
    \        x = (x & UINT32_C(0x33333333)) + (x >> 2 & UINT32_C(0x33333333));\n \
    \       x = (x & UINT32_C(0x0f0f0f0f)) + (x >> 4 & UINT32_C(0x0f0f0f0f));\n  \
    \      x = (x & UINT32_C(0x00ff00ff)) + (x >> 8 & UINT32_C(0x00ff00ff));\n   \
    \     x = (x & UINT32_C(0x0000ffff)) + (x >> 16 & UINT32_C(0x0000ffff));\n   \
    \   } else if constexpr (::std::numeric_limits<T>::digits == 64) {\n        x\
    \ = (x & UINT64_C(0x5555555555555555)) + (x >> 1 & UINT64_C(0x5555555555555555));\n\
    \        x = (x & UINT64_C(0x3333333333333333)) + (x >> 2 & UINT64_C(0x3333333333333333));\n\
    \        x = (x & UINT64_C(0x0f0f0f0f0f0f0f0f)) + (x >> 4 & UINT64_C(0x0f0f0f0f0f0f0f0f));\n\
    \        x = (x & UINT64_C(0x00ff00ff00ff00ff)) + (x >> 8 & UINT64_C(0x00ff00ff00ff00ff));\n\
    \        x = (x & UINT64_C(0x0000ffff0000ffff)) + (x >> 16 & UINT64_C(0x0000ffff0000ffff));\n\
    \        x = (x & UINT64_C(0x00000000ffffffff)) + (x >> 32 & UINT64_C(0x00000000ffffffff));\n\
    \      }\n\n      return x;\n    }\n  }\n}\n\n\n#line 8 \"tools/floor_log2.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  T floor_log2(T x) {\n    static_assert(::std::is_integral_v<T>);\n\
    \    assert(x > 0);\n    if constexpr (::std::is_signed_v<T>) {\n      return\
    \ static_cast<T>(::tools::floor_log2<::std::make_unsigned_t<T>>(x));\n    } else\
    \ {\n      const auto log2 = [](const int w) {\n        if (w == 8) return 3;\n\
    \        if (w == 16) return 4;\n        if (w == 32) return 5;\n        if (w\
    \ == 64) return 6;\n        return -1;\n      };\n      static_assert(log2(::std::numeric_limits<T>::digits)\
    \ >= 0);\n\n      x |= (x >> 1);\n      x |= (x >> 2);\n      x |= (x >> 4);\n\
    \      if constexpr (::std::numeric_limits<T>::digits > 8) x |= (x >> 8);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 16) x |= (x >> 16);\n  \
    \    if constexpr (::std::numeric_limits<T>::digits > 32) x |= (x >> 32);\n  \
    \    return ::tools::popcount(x) - static_cast<T>(1);\n    }\n  }\n}\n\n\n#line\
    \ 15 \"tools/prime_factorization.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  ::std::vector<T> prime_factorization(T n) {\n    assert(1 <= n && n <=\
    \ 1000000000000000000);\n    ::std::vector<T> result;\n\n    if (n == 1) return\
    \ result;\n\n    ::std::queue<::std::pair<T, T>> factors({::std::pair<T, T>(n,\
    \ 1)});\n    while (!factors.empty()) {\n      const T factor = factors.front().first;\n\
    \      const T occurrences = factors.front().second;\n      factors.pop();\n \
    \     if (::tools::is_prime(factor)) {\n        for (T i = 0; i < occurrences;\
    \ ++i) {\n          result.push_back(factor);\n        }\n      } else {\n   \
    \     const T m = ::tools::pow2((::tools::floor_log2(factor) + 1) / 8);\n    \
    \    for (T c = 1; ; ++c) {\n          const auto f = [&](T& x) {\n          \
    \  x = ::tools::prod_mod(x, x, factor);\n            x += c;\n            if (x\
    \ >= factor) x -= factor;\n          };\n          T y = 2;\n          T r = 1;\n\
    \          T q = 1;\n          T x, g, ys;\n          do {\n            x = y;\n\
    \            for (T i = 0; i < r; ++i) {\n              f(y);\n            }\n\
    \            T k = 0;\n            do {\n              ys = y;\n             \
    \ for (T i = 0; i < ::std::min(m, r - k); ++i) {\n                f(y);\n    \
    \            q = ::tools::prod_mod(q, ::std::abs(x - y), factor);\n          \
    \    }\n              g = ::std::gcd(q, factor);\n              k += m;\n    \
    \        } while (k < r && g == 1);\n            r *= 2;\n          } while (g\
    \ == 1);\n          if (g == factor) {\n            do {\n              f(ys);\n\
    \              g = ::std::gcd(::std::abs(x - ys), factor);\n            } while\
    \ (g == 1);\n          }\n          if (g < factor) {\n            T h = factor\
    \ / g;\n            if (h < g) ::std::swap(g, h);\n            T n = 1;\n    \
    \        while (h % g == 0) {\n              h /= g;\n              ++n;\n   \
    \         }\n            factors.emplace(g, occurrences * n);\n            if\
    \ (h > 1) factors.emplace(h, occurrences);\n            break;\n          }\n\
    \        }\n      }\n    }\n\n    ::std::sort(result.begin(), result.end());\n\
    \    return result;\n  }\n}\n\n\n#line 6 \"tests/prime_factorization.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll Q;\n  std::cin >> Q;\n  for (ll i = 0; i < Q; ++i) {\n    ll a_i;\n   \
    \ std::cin >> a_i;\n\n    const ::std::vector<ll> prime_factors = tools::prime_factorization(a_i);\n\
    \    std::cout << prime_factors.size();\n    for (const ll& p : prime_factors)\
    \ {\n      std::cout << ' ' << p;\n    }\n    std::cout << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"tools/prime_factorization.hpp\"\n\n\
    using ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll Q;\n  std::cin >> Q;\n  for (ll i = 0; i < Q; ++i) {\n    ll a_i;\n   \
    \ std::cin >> a_i;\n\n    const ::std::vector<ll> prime_factors = tools::prime_factorization(a_i);\n\
    \    std::cout << prime_factors.size();\n    for (const ll& p : prime_factors)\
    \ {\n      std::cout << ' ' << p;\n    }\n    std::cout << '\\n';\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/prime_factorization.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/prime_factorization.test.cpp
  requiredBy: []
  timestamp: '2023-08-26 14:07:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/prime_factorization.test.cpp
layout: document
redirect_from:
- /verify/tests/prime_factorization.test.cpp
- /verify/tests/prime_factorization.test.cpp.html
title: tests/prime_factorization.test.cpp
---
