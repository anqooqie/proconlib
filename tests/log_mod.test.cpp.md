---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':question:'
    path: tools/ceil_sqrt.hpp
    title: $\left\lceil \sqrt{x} \right\rceil$
  - icon: ':question:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':question:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/inv_mod.hpp
    title: $x^{-1} \pmod{M}$
  - icon: ':x:'
    path: tools/log_mod.hpp
    title: $\log_x y \pmod{M}$
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
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
    title: Alias for unsigned __int128
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"tests/log_mod.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <iostream>\n#line 1 \"tools/log_mod.hpp\"\n\n\n\n#include <optional>\n\
    #include <cassert>\n#include <numeric>\n#include <unordered_map>\n#line 1 \"tools/mod.hpp\"\
    \n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const M\
    \ lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor_log2.hpp\"\n\n\n\n#line\
    \ 6 \"tools/floor_log2.hpp\"\n#include <limits>\n#line 1 \"tools/popcount.hpp\"\
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
    \ 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\nnamespace\
    \ tools {\n  using uint128_t = unsigned __int128;\n}\n\n\n#line 5 \"tools/prod_mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T1, typename T2, typename T3>\n\
    \  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128\
    \ = ::tools::uint128_t;\n    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >=\
    \ 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n\
    \    return prod_mod;\n  }\n}\n\n\n#line 1 \"tools/inv_mod.hpp\"\n\n\n\n#line\
    \ 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#include <utility>\n#line 7\
    \ \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T,\
    \ T, T> extgcd(T prev_r, T r) {\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n\
    \    T t(1);\n    while (r != 0) {\n      const T q = ::tools::quo(prev_r, r);\n\
    \      ::std::tie(prev_r, r) = ::std::make_pair(r, prev_r - q * r);\n      ::std::tie(prev_s,\
    \ s) = ::std::make_pair(s, prev_s - q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t,\
    \ prev_t - q * t);\n    }\n\n    if (prev_r < T(0)) prev_r = -prev_r;\n    return\
    \ ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n}\n\n\n#line 7 \"tools/inv_mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T1, typename T2>\n  constexpr T2\
    \ inv_mod(const T1 x, const T2 m) {\n    const auto [x0, y0, gcd] = ::tools::extgcd(x,\
    \ m);\n    assert(gcd == 1);\n    return ::tools::mod(x0, m);\n  }\n}\n\n\n#line\
    \ 1 \"tools/ceil_sqrt.hpp\"\n\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"\
    tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n   \
    \ assert(rhs != 0);\n    return lhs / rhs + (((lhs > 0 && rhs > 0) || (lhs < 0\
    \ && rhs < 0)) && lhs % rhs);\n  }\n}\n\n\n#line 6 \"tools/ceil_sqrt.hpp\"\n\n\
    namespace tools {\n\n  template <typename T>\n  T ceil_sqrt(const T n) {\n   \
    \ assert(n >= 0);\n\n    if (n == 0) return 0;\n\n    T ok = 1;\n    T ng;\n \
    \   for (ng = 2; ng - 1 < tools::ceil(n, ng - 1); ng *= 2);\n\n    while (ng -\
    \ ok > 1) {\n      const T mid = ok + (ng - ok) / 2;\n      if (mid - 1 < tools::ceil(n,\
    \ mid - 1)) {\n        ok = mid;\n      } else {\n        ng = mid;\n      }\n\
    \    }\n\n    return ok;\n  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line\
    \ 6 \"tools/pow_mod.hpp\"\n\nnamespace tools {\n\n  template <typename T1, typename\
    \ T2, typename T3>\n  constexpr T3 pow_mod(const T1 x, T2 n, const T3 m) {\n \
    \   if (m == 1) return 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x, m);\n   \
    \ while (n > 0) {\n      if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r,\
    \ y, m);\n      }\n      y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n\
    \    return r;\n  }\n}\n\n\n#line 14 \"tools/log_mod.hpp\"\n\nnamespace tools\
    \ {\n  inline ::std::optional<long long> log_mod(long long a, long long b, long\
    \ long m) {\n    assert(m >= 1);\n    a = ::tools::mod(a, m);\n    b = ::tools::mod(b,\
    \ m);\n\n    const auto d = ::tools::floor_log2(m);\n    long long a_d;\n    {\n\
    \      auto& a_x = a_d;\n      a_x = 1;\n      for (long long x = 0; x < d; ++x,\
    \ a_x = ::tools::prod_mod(a_x, a, m)) {\n        if (a_x == b) return x;\n   \
    \   }\n    }\n\n    if (m == 1 || b == 1) return 0;\n\n    const auto g = ::std::gcd(a_d,\
    \ m);\n    if (b % g != 0) return ::std::nullopt;\n    if (m == g) return d;\n\
    \n    m /= g;\n    a %= m;\n    b = ::tools::prod_mod(b, ::tools::inv_mod(a_d,\
    \ m), m);\n\n    const auto p = ::tools::ceil_sqrt(m);\n    ::std::unordered_map<long\
    \ long, long long> map;\n    for (long long q = 0, a_q = 1; q < p; ++q, a_q =\
    \ ::tools::prod_mod(a_q, a, m)) {\n      if (map.find(a_q) == map.end()) {\n \
    \       map.emplace(a_q, q);\n      }\n    }\n\n    const auto aux = ::tools::pow_mod(::tools::inv_mod(a,\
    \ m), p, m);\n    for (long long i = 0, aux_i = 1; i < p; ++i, aux_i = ::tools::prod_mod(aux_i,\
    \ aux, m)) {\n      if (const auto it = map.find(::tools::prod_mod(b, aux_i, m));\
    \ it != map.end()) {\n        return d + p * i + it->second;\n      }\n    }\n\
    \n    return ::std::nullopt;\n  }\n}\n\n\n#line 5 \"tests/log_mod.test.cpp\"\n\
    \nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll T;\n  std::cin >> T;\n  for (ll t = 0; t < T; ++t) {\n    ll X, Y, M;\n\
    \    std::cin >> X >> Y >> M;\n    if (const auto answer = ::tools::log_mod(X,\
    \ Y, M); answer) {\n      std::cout << *answer << '\\n';\n    } else {\n     \
    \ std::cout << -1 << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <iostream>\n#include \"tools/log_mod.hpp\"\n\nusing ll = long long;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll T;\n  std::cin >> T;\n  for (ll t = 0; t < T; ++t) {\n    ll X, Y, M;\n\
    \    std::cin >> X >> Y >> M;\n    if (const auto answer = ::tools::log_mod(X,\
    \ Y, M); answer) {\n      std::cout << *answer << '\\n';\n    } else {\n     \
    \ std::cout << -1 << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/log_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  - tools/ceil_sqrt.hpp
  - tools/ceil.hpp
  - tools/pow_mod.hpp
  isVerificationFile: true
  path: tests/log_mod.test.cpp
  requiredBy: []
  timestamp: '2022-11-20 17:00:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/log_mod.test.cpp
layout: document
redirect_from:
- /verify/tests/log_mod.test.cpp
- /verify/tests/log_mod.test.cpp.html
title: tests/log_mod.test.cpp
---
