---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
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
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
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
    https://judge.yosupo.jp/problem/factorize\"\n\n#include <cstdint>\n#include <iostream>\n\
    #include <vector>\n#line 1 \"tools/prime_factorization.hpp\"\n\n\n\n#line 5 \"\
    tools/prime_factorization.hpp\"\n#include <cassert>\n#include <queue>\n#include\
    \ <utility>\n#include <algorithm>\n#include <cmath>\n#include <numeric>\n#line\
    \ 1 \"tools/is_prime.hpp\"\n\n\n\n#line 5 \"tools/is_prime.hpp\"\n#include <array>\n\
    #line 1 \"tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2\
    \ y, const T3 m) {\n    using u128 = unsigned __int128;\n    u128 prod_mod = u128(x\
    \ >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >=\
    \ 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line\
    \ 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const M\
    \ lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const\
    \ T1 x, T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3\
    \ y = ::tools::mod(x, m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n   \
    \     r = ::tools::prod_mod(r, y, m);\n      }\n      y = ::tools::prod_mod(y,\
    \ y, m);\n      n /= 2;\n    }\n    return r;\n  }\n}\n\n\n#line 8 \"tools/is_prime.hpp\"\
    \n\nnamespace tools {\n\n  constexpr bool is_prime(const ::std::uint_fast64_t\
    \ n) {\n    constexpr ::std::array<::std::uint_fast64_t, 7> bases = {2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if\
    \ (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n    ::std::uint_fast64_t\
    \ d = n - 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const ::std::uint_fast64_t\
    \ a : bases) {\n      if (a % n == 0) return true;\n\n      ::std::uint_fast64_t\
    \ power = d;\n      ::std::uint_fast64_t target = ::tools::pow_mod(a, power, n);\n\
    \n      bool is_composite = true;\n      if (target == 1) is_composite = false;\n\
    \      for (; is_composite && power != n - 1; power *= 2, target = ::tools::prod_mod(target,\
    \ target, n)) {\n        if (target == n - 1) is_composite = false;\n      }\n\
    \n      if (is_composite) {\n        return false;\n      }\n    }\n\n    return\
    \ true;\n  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 5 \"tools/pow2.hpp\"\
    \n#include <cstddef>\n\nnamespace tools {\n\n  template <typename T, typename\
    \ ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>\n\
    \  constexpr T pow2(const T x) {\n    return static_cast<T>(1) << x;\n  }\n\n\
    \  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\
    \n\n\n\n#line 1 \"tools/popcount.hpp\"\n\n\n\n#line 5 \"tools/popcount.hpp\"\n\
    \nnamespace tools {\n\n  inline ::std::uint32_t popcount(::std::uint32_t x) {\n\
    \    x = (x & static_cast<::std::uint32_t>(0x55555555ull)) + (x >> static_cast<::std::uint32_t>(1)\
    \ & static_cast<::std::uint32_t>(0x55555555ull));\n    x = (x & static_cast<::std::uint32_t>(0x33333333ull))\
    \ + (x >> static_cast<::std::uint32_t>(2) & static_cast<::std::uint32_t>(0x33333333ull));\n\
    \    x = (x & static_cast<::std::uint32_t>(0x0f0f0f0full)) + (x >> static_cast<::std::uint32_t>(4)\
    \ & static_cast<::std::uint32_t>(0x0f0f0f0full));\n    x = (x & static_cast<::std::uint32_t>(0x00ff00ffull))\
    \ + (x >> static_cast<::std::uint32_t>(8) & static_cast<::std::uint32_t>(0x00ff00ffull));\n\
    \    return (x & static_cast<::std::uint32_t>(0x0000ffffull)) + (x >> static_cast<::std::uint32_t>(16)\
    \ & static_cast<::std::uint32_t>(0x0000ffffull));\n  }\n\n  inline ::std::uint64_t\
    \ popcount(::std::uint64_t x) {\n    x = (x & static_cast<::std::uint64_t>(0x5555555555555555ull))\
    \ + (x >> static_cast<::std::uint64_t>(1) & static_cast<::std::uint64_t>(0x5555555555555555ull));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x3333333333333333ull)) + (x >> static_cast<::std::uint64_t>(2)\
    \ & static_cast<::std::uint64_t>(0x3333333333333333ull));\n    x = (x & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full))\
    \ + (x >> static_cast<::std::uint64_t>(4) & static_cast<::std::uint64_t>(0x0f0f0f0f0f0f0f0full));\n\
    \    x = (x & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull)) + (x >> static_cast<::std::uint64_t>(8)\
    \ & static_cast<::std::uint64_t>(0x00ff00ff00ff00ffull));\n    x = (x & static_cast<::std::uint64_t>(0x0000ffff0000ffffull))\
    \ + (x >> static_cast<::std::uint64_t>(16) & static_cast<::std::uint64_t>(0x0000ffff0000ffffull));\n\
    \    return (x & static_cast<::std::uint64_t>(0x00000000ffffffffull)) + (x >>\
    \ static_cast<::std::uint64_t>(32) & static_cast<::std::uint64_t>(0x00000000ffffffffull));\n\
    \  }\n\n  inline ::std::int32_t popcount(::std::int32_t x) {\n    return static_cast<::std::int32_t>(::tools::popcount(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t popcount(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::popcount(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 6 \"tools/floor_log2.hpp\"\n\nnamespace tools {\n\n  inline\
    \ ::std::uint32_t floor_log2(::std::uint32_t x) {\n    x |= (x >> static_cast<::std::uint32_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(2));\n    x |= (x >> static_cast<::std::uint32_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint32_t>(8));\n    x |= (x >> static_cast<::std::uint32_t>(16));\n\
    \    return ::tools::popcount(x) - static_cast<::std::uint32_t>(1);\n  }\n\n \
    \ inline ::std::uint64_t floor_log2(::std::uint64_t x) {\n    x |= (x >> static_cast<::std::uint64_t>(1));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(2));\n    x |= (x >> static_cast<::std::uint64_t>(4));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(8));\n    x |= (x >> static_cast<::std::uint64_t>(16));\n\
    \    x |= (x >> static_cast<::std::uint64_t>(32));\n    return ::tools::popcount(x)\
    \ - static_cast<::std::uint64_t>(1);\n  }\n\n  inline ::std::int32_t floor_log2(::std::int32_t\
    \ x) {\n    return static_cast<::std::int32_t>(::tools::floor_log2(static_cast<::std::uint32_t>(x)));\n\
    \  }\n\n  inline ::std::int64_t floor_log2(::std::int64_t x) {\n    return static_cast<::std::int64_t>(::tools::floor_log2(static_cast<::std::uint64_t>(x)));\n\
    \  }\n}\n\n\n#line 15 \"tools/prime_factorization.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T>\n  ::std::vector<T> prime_factorization(T n) {\n   \
    \ assert(1 <= n && n <= 1000000000000000000);\n    ::std::vector<T> result;\n\n\
    \    if (n == 1) return result;\n\n    ::std::queue<::std::pair<T, T>> factors({::std::pair<T,\
    \ T>(n, 1)});\n    while (!factors.empty()) {\n      const T factor = factors.front().first;\n\
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
    \    return result;\n  }\n}\n\n\n#line 7 \"tests/prime_factorization.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 Q;\n  std::cin >> Q;\n  for\
    \ (i64 i = 0; i < Q; ++i) {\n    i64 a_i;\n    std::cin >> a_i;\n\n    const ::std::vector<i64>\
    \ prime_factors = tools::prime_factorization(a_i);\n    std::cout << prime_factors.size();\n\
    \    for (const i64& p : prime_factors) {\n      std::cout << ' ' << p;\n    }\n\
    \    std::cout << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n#include \"tools/prime_factorization.hpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 Q;\n  std::cin >> Q;\n  for\
    \ (i64 i = 0; i < Q; ++i) {\n    i64 a_i;\n    std::cin >> a_i;\n\n    const ::std::vector<i64>\
    \ prime_factors = tools::prime_factorization(a_i);\n    std::cout << prime_factors.size();\n\
    \    for (const i64& p : prime_factors) {\n      std::cout << ' ' << p;\n    }\n\
    \    std::cout << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/prime_factorization.hpp
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  isVerificationFile: true
  path: tests/prime_factorization.test.cpp
  requiredBy: []
  timestamp: '2022-02-05 17:57:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/prime_factorization.test.cpp
layout: document
redirect_from:
- /verify/tests/prime_factorization.test.cpp
- /verify/tests/prime_factorization.test.cpp.html
title: tests/prime_factorization.test.cpp
---
