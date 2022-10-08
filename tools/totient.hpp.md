---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':question:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':x:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':question:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':x:'
    path: tools/run_length.hpp
    title: Run-length encoding
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  _extendedRequiredBy:
  - icon: ':x:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':x:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/totient.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <vector>\n#include <utility>\n#include <iterator>\n#line 1 \"tools/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"tools/prime_factorization.hpp\"\n#include <queue>\n#line 8 \"\
    tools/prime_factorization.hpp\"\n#include <algorithm>\n#include <cmath>\n#include\
    \ <numeric>\n#line 1 \"tools/is_prime.hpp\"\n\n\n\n#include <array>\n#line 1 \"\
    tools/prod_mod.hpp\"\n\n\n\nnamespace tools {\n\n  template <typename T1, typename\
    \ T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m)\
    \ {\n    using u128 = unsigned __int128;\n    u128 prod_mod = u128(x >= 0 ? x\
    \ : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >= 0)) prod_mod\
    \ = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\
    \n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    if (lhs >= 0) {\n      return lhs / rhs;\n    } else {\n     \
    \ if (rhs >= 0) {\n        return -((-lhs - 1 + rhs) / rhs);\n      } else {\n\
    \        return (-lhs - 1 + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6\
    \ \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {\n    if\
    \ constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {\n      return\
    \ lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs, rhs) * rhs;\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T1, typename T2, typename T3>\n  constexpr T3 pow_mod(const T1 x,\
    \ T2 n, const T3 m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x,\
    \ m);\n    while (n > 0) {\n      if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r,\
    \ y, m);\n      }\n      y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n\
    \    return r;\n  }\n}\n\n\n#line 7 \"tools/is_prime.hpp\"\n\nnamespace tools\
    \ {\n\n  constexpr bool is_prime(const ::std::uint_fast64_t n) {\n    constexpr\
    \ ::std::array<unsigned long long, 7> bases = {2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022};\n\n    if (n <= 1) return false;\n    if (n == 2) return true;\n\
    \    if (n % 2 == 0) return false;\n\n    auto d = n - 1;\n    for (; d % 2 ==\
    \ 0; d /= 2);\n\n    for (const auto a : bases) {\n      if (a % n == 0) return\
    \ true;\n\n      auto power = d;\n      auto target = ::tools::pow_mod(a, power,\
    \ n);\n\n      bool is_composite = true;\n      if (target == 1) is_composite\
    \ = false;\n      for (; is_composite && power != n - 1; power *= 2, target =\
    \ ::tools::prod_mod(target, target, n)) {\n        if (target == n - 1) is_composite\
    \ = false;\n      }\n\n      if (is_composite) {\n        return false;\n    \
    \  }\n    }\n\n    return true;\n  }\n}\n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n\
    #line 5 \"tools/pow2.hpp\"\n#include <cstddef>\n\nnamespace tools {\n\n  template\
    \ <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n  constexpr T pow2(const T x) {\n    return static_cast<T>(1) <<\
    \ x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
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
    \    return result;\n  }\n}\n\n\n#line 1 \"tools/run_length.hpp\"\n\n\n\n#line\
    \ 8 \"tools/run_length.hpp\"\n\nnamespace tools {\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void run_length(const InputIterator& begin, const\
    \ InputIterator& end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    if (begin == end) return;\n\n    ::std::pair<T, ::std::size_t> prev;\n  \
    \  for (auto [it, breaks] = ::std::make_pair(begin, false); !breaks; breaks =\
    \ it == end, it = ::std::next(it, breaks ? 0 : 1)) {\n      bool flg1, flg2;\n\
    \      if (it == begin) {\n        flg1 = false;\n        flg2 = true;\n     \
    \ } else if (it == end) {\n        flg1 = true;\n        flg2 = false;\n     \
    \ } else if (*it != prev.first) {\n        flg1 = true;\n        flg2 = true;\n\
    \      } else {\n        flg1 = false;\n        flg2 = false;\n      }\n     \
    \ if (flg1 || flg2) {\n        if (flg1) {\n          *result = prev;\n      \
    \    ++result;\n        }\n        if (flg2) {\n          prev.first = *it;\n\
    \          prev.second = 1;\n        }\n      } else {\n        ++prev.second;\n\
    \      }\n    }\n  }\n}\n\n\n#line 1 \"tools/pow.hpp\"\n\n\n\n#line 1 \"tools/monoid.hpp\"\
    \n\n\n\n#line 7 \"tools/monoid.hpp\"\n\nnamespace tools {\n  namespace monoid\
    \ {\n    template <typename Type, Type E = ::std::numeric_limits<Type>::min()>\n\
    \    struct max {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::max()>\n    struct min {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::min(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type>\n    struct multiplies {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return lhs * rhs;\n  \
    \    }\n      static T e() {\n        return T(1);\n      }\n    };\n\n    template\
    \ <typename Type>\n    struct gcd {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::gcd(lhs, rhs);\n      }\n     \
    \ static T e() {\n        return T(0);\n      }\n    };\n\n    template <typename\
    \ Type, Type E>\n    struct update {\n      using T = Type;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n      }\n     \
    \ static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\
    \n\n\n\n#line 5 \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T square(const typename M::T& x) {\n    return M::op(x, x);\n\
    \  }\n\n  template <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 7 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T pow(const typename M::T& base, const ::std::size_t& exponent)\
    \ {\n    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n   \
    \     ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T>\n  T pow(const T& base,\
    \ const ::std::size_t& exponent) {\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base,\
    \ exponent);\n  }\n}\n\n\n#line 11 \"tools/totient.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T>\n  T totient(const T& x) {\n    assert(1 <= x && x <=\
    \ 1000000000000000000);\n    T prod = 1;\n    const ::std::vector<T> prime_factors\
    \ = ::tools::prime_factorization(x);\n    ::std::vector<::std::pair<T, T>> distinct_prime_factors;\n\
    \    ::tools::run_length(prime_factors.begin(), prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n\
    \    for (const auto& [p, q] : distinct_prime_factors) {\n      prod *= ::tools::pow(p,\
    \ q - 1) * (p - 1);\n    }\n    return prod;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_TOTIENT_HPP\n#define TOOLS_TOTIENT_HPP\n\n#include <cassert>\n\
    #include <vector>\n#include <utility>\n#include <iterator>\n#include \"tools/prime_factorization.hpp\"\
    \n#include \"tools/run_length.hpp\"\n#include \"tools/pow.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  T totient(const T& x) {\n    assert(1 <= x &&\
    \ x <= 1000000000000000000);\n    T prod = 1;\n    const ::std::vector<T> prime_factors\
    \ = ::tools::prime_factorization(x);\n    ::std::vector<::std::pair<T, T>> distinct_prime_factors;\n\
    \    ::tools::run_length(prime_factors.begin(), prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n\
    \    for (const auto& [p, q] : distinct_prime_factors) {\n      prod *= ::tools::pow(p,\
    \ q - 1) * (p - 1);\n    }\n    return prod;\n  }\n}\n\n#endif\n"
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
  - tools/run_length.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  isVerificationFile: false
  path: tools/totient.hpp
  requiredBy:
  - tools/tetration_mod.hpp
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/tetration_mod.test.cpp
  - tests/totient.test.cpp
documentation_of: tools/totient.hpp
layout: document
title: Euler's totient function
---

```cpp
template <typename T>
T totient(T x);
```

It returns $\varphi(x) = \|\\{n \in \mathbb{N} \| 1 \leq n \leq x \land \gcd(n, x) = 1\\}\|$.

## Constraints
- $1 \leq x \leq 10^{18}$.

## Time Complexity
- Supposed to be $O\left(x^\frac{1}{4} \text{polylog}(x)\right)$

## License
- CC0

## Author
- anqooqie
