---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/garner.hpp
    title: Garner's algorithm
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
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid
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
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/run_length.hpp
    title: Run-length encoding
  - icon: ':heavy_check_mark:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/tetration_mod.hpp\"\n\n\n\n#include <cstdint>\n#include\
    \ <limits>\n#include <vector>\n#include <utility>\n#include <iterator>\n#line\
    \ 1 \"tools/pow.hpp\"\n\n\n\n#include <cstddef>\n#line 1 \"tools/monoid.hpp\"\n\
    \n\n\n#include <algorithm>\n#line 6 \"tools/monoid.hpp\"\n#include <numeric>\n\
    \nnamespace tools {\n  namespace monoid {\n    template <typename Type, Type E\
    \ = ::std::numeric_limits<Type>::min()>\n    struct max {\n      using T = Type;\n\
    \      static T op(const T lhs, const T rhs) {\n        return ::std::max(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return E;\n      }\n    };\n\n\
    \    template <typename Type, Type E = ::std::numeric_limits<Type>::max()>\n \
    \   struct min {\n      using T = Type;\n      static T op(const T lhs, const\
    \ T rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename Type>\n    struct\
    \ multiplies {\n      using T = Type;\n      static T op(const T lhs, const T\
    \ rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n        return\
    \ T(1);\n      }\n    };\n\n    template <typename Type>\n    struct gcd {\n \
    \     using T = Type;\n      static T op(const T lhs, const T rhs) {\n       \
    \ return ::std::gcd(lhs, rhs);\n      }\n      static T e() {\n        return\
    \ T(0);\n      }\n    };\n\n    template <typename Type, Type E>\n    struct update\
    \ {\n      using T = Type;\n      static T op(const T lhs, const T rhs) {\n  \
    \      return lhs == E ? rhs : lhs;\n      }\n      static T e() {\n        return\
    \ E;\n      }\n    };\n  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5\
    \ \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename M>\n  typename\
    \ M::T square(const typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template\
    \ <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n#line 7 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T pow(const typename M::T& base, const ::std::size_t& exponent)\
    \ {\n    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n   \
    \     ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T>\n  T pow(const T& base,\
    \ const ::std::size_t& exponent) {\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base,\
    \ exponent);\n  }\n}\n\n\n#line 1 \"tools/prime_factorization.hpp\"\n\n\n\n#line\
    \ 5 \"tools/prime_factorization.hpp\"\n#include <cassert>\n#include <queue>\n\
    #line 8 \"tools/prime_factorization.hpp\"\n#include <cmath>\n#line 1 \"tools/is_prime.hpp\"\
    \n\n\n\n#line 5 \"tools/is_prime.hpp\"\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\
    \n\n\n\nnamespace tools {\n\n  template <typename T1, typename T2, typename T3>\n\
    \  constexpr T3 prod_mod(const T1 x, const T2 y, const T3 m) {\n    using u128\
    \ = unsigned __int128;\n    u128 prod_mod = u128(x >= 0 ? x : -x) * u128(y >=\
    \ 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^ (y >= 0)) prod_mod = u128(m) - prod_mod;\n\
    \    return prod_mod;\n  }\n}\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line\
    \ 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\
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
    \    return r;\n  }\n}\n\n\n#line 8 \"tools/is_prime.hpp\"\n\nnamespace tools\
    \ {\n\n  constexpr bool is_prime(const ::std::uint_fast64_t n) {\n    constexpr\
    \ ::std::array<::std::uint_fast64_t, 7> bases = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022};\n\n    if (n <= 1) return false;\n    if (n == 2) return\
    \ true;\n    if (n % 2 == 0) return false;\n\n    ::std::uint_fast64_t d = n -\
    \ 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const ::std::uint_fast64_t a\
    \ : bases) {\n      if (a % n == 0) return true;\n\n      ::std::uint_fast64_t\
    \ power = d;\n      ::std::uint_fast64_t target = ::tools::pow_mod(a, power, n);\n\
    \n      bool is_composite = true;\n      if (target == 1) is_composite = false;\n\
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
    \  }\n}\n\n\n#line 14 \"tools/prime_factorization.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T>\n  ::std::vector<T> prime_factorization(T n) {\n   \
    \ assert(1 <= n && n <= 1000000000000000000);\n    ::std::vector<T> result;\n\n\
    \    if (n == 1) return result;\n\n    ::std::queue<T> factors({n});\n    while\
    \ (!factors.empty()) {\n      const T factor = factors.front();\n      factors.pop();\n\
    \      if (::tools::is_prime(factor)) {\n        result.push_back(factor);\n \
    \     } else {\n        const T m = ::tools::pow2((::tools::floor_log2(factor)\
    \ + 1) / 8);\n        for (T c = 1; ; ++c) {\n          const auto f = [&](T&\
    \ x) {\n            x = ::tools::prod_mod(x, x, factor);\n            x += c;\n\
    \            if (x >= factor) x -= factor;\n          };\n          T y = 2;\n\
    \          T r = 1;\n          T q = 1;\n          T x, g, ys;\n          do {\n\
    \            x = y;\n            for (T i = 0; i < r; ++i) {\n              f(y);\n\
    \            }\n            T k = 0;\n            do {\n              ys = y;\n\
    \              for (T i = 0; i < ::std::min(m, r - k); ++i) {\n              \
    \  f(y);\n                q = ::tools::prod_mod(q, ::std::abs(x - y), factor);\n\
    \              }\n              g = ::std::gcd(q, factor);\n              k +=\
    \ m;\n            } while (k < r && g == 1);\n            r *= 2;\n          }\
    \ while (g == 1);\n          if (g == factor) {\n            do {\n          \
    \    f(ys);\n              g = ::std::gcd(::std::abs(x - ys), factor);\n     \
    \       } while (g == 1);\n          }\n          if (g < factor) {\n        \
    \    factors.push(g);\n            factors.push(factor / g);\n            break;\n\
    \          }\n        }\n      }\n    }\n\n    ::std::sort(result.begin(), result.end());\n\
    \    return result;\n  }\n}\n\n\n#line 1 \"tools/run_length.hpp\"\n\n\n\n#line\
    \ 7 \"tools/run_length.hpp\"\n\nnamespace tools {\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void run_length(const InputIterator& begin, const\
    \ InputIterator& end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    if (begin == end) return;\n\n    ::std::pair<T, ::std::int_fast64_t> prev;\n\
    \    for (auto [it, breaks] = ::std::make_pair(begin, false); !breaks; breaks\
    \ = it == end, it = ::std::next(it, breaks ? 0 : 1)) {\n      bool flg1, flg2;\n\
    \      if (it == begin) {\n        flg1 = false;\n        flg2 = true;\n     \
    \ } else if (it == end) {\n        flg1 = true;\n        flg2 = false;\n     \
    \ } else if (*it != prev.first) {\n        flg1 = true;\n        flg2 = true;\n\
    \      } else {\n        flg1 = false;\n        flg2 = false;\n      }\n     \
    \ if (flg1 || flg2) {\n        if (flg1) {\n          *result = prev;\n      \
    \    ++result;\n        }\n        if (flg2) {\n          prev.first = *it;\n\
    \          prev.second = 1;\n        }\n      } else {\n        ++prev.second;\n\
    \      }\n    }\n  }\n}\n\n\n#line 1 \"tools/totient.hpp\"\n\n\n\n#line 11 \"\
    tools/totient.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  T totient(const\
    \ T& x) {\n    assert(1 <= x && x <= 1000000000000000000);\n    T prod = 1;\n\
    \    const ::std::vector<T> prime_factors = ::tools::prime_factorization(x);\n\
    \    ::std::vector<::std::pair<T, T>> distinct_prime_factors;\n    ::tools::run_length(prime_factors.begin(),\
    \ prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n    for\
    \ (const auto& [p, q] : distinct_prime_factors) {\n      prod *= ::tools::pow(p,\
    \ q - 1) * (p - 1);\n    }\n    return prod;\n  }\n}\n\n\n#line 1 \"tools/garner.hpp\"\
    \n\n\n\n#line 1 \"tools/inv_mod.hpp\"\n\n\n\n#line 1 \"tools/extgcd.hpp\"\n\n\n\
    \n#include <tuple>\n#line 6 \"tools/extgcd.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {\n    T prev_s\
    \ = 1;\n    T prev_t = 0;\n    T s = 0;\n    T t = 1;\n    while (r != 0) {\n\
    \      const T q = ::tools::quo(prev_r, r);\n      const T next_r = prev_r - q\
    \ * r;\n      prev_r = r;\n      r = next_r;\n      const T next_s = prev_s -\
    \ q * s;\n      prev_s = s;\n      s = next_s;\n      const T next_t = prev_t\
    \ - q * t;\n      prev_t = t;\n      t = next_t;\n    }\n\n    if (prev_r < T(0))\
    \ prev_r = -prev_r;\n    return {prev_s, prev_t, prev_r};\n  }\n}\n\n\n#line 7\
    \ \"tools/inv_mod.hpp\"\n\nnamespace tools {\n\n  template <typename T1, typename\
    \ T2>\n  constexpr T2 inv_mod(const T1 x, const T2 m) {\n    const auto [x0, y0,\
    \ gcd] = ::tools::extgcd(x, m);\n    assert(gcd == 1);\n    return ::tools::mod(x0,\
    \ m);\n  }\n}\n\n\n#line 10 \"tools/garner.hpp\"\n\n// Source: https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n\
    // License: unknown\n// Author: drken\n\nnamespace tools {\n\n  template <typename\
    \ Iterator, typename ModType>\n  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t>\
    \ garner(const Iterator& begin, const Iterator& end, const ModType& mod) {\n \
    \   ::std::vector<::std::int_fast64_t> b, m;\n    for (auto it = begin; it !=\
    \ end; ++it) {\n      b.push_back(::tools::mod(it->first, it->second));\n    \
    \  m.push_back(it->second);\n    }\n\n    ::std::int_fast64_t lcm = 1;\n    for\
    \ (::std::size_t i = 0; i < b.size(); ++i) {\n      (lcm *= m[i]) %= mod;\n  \
    \  }\n\n    m.push_back(mod);\n    ::std::vector<::std::int_fast64_t> coeffs(m.size(),\
    \ 1);\n    ::std::vector<::std::int_fast64_t> constants(m.size(), 0);\n    for\
    \ (::std::size_t k = 0; k < b.size(); ++k) {\n      ::std::int_fast64_t t = ::tools::mod((b[k]\
    \ - constants[k]) * ::tools::inv_mod(coeffs[k], m[k]), m[k]);\n      for (::std::size_t\
    \ i = k + 1; i < m.size(); ++i) {\n        (constants[i] += t * coeffs[i]) %=\
    \ m[i];\n        (coeffs[i] *= m[k]) %= m[i];\n      }\n    }\n\n    return ::std::make_pair(constants.back(),\
    \ lcm);\n  }\n\n  template <typename M, typename Iterator>\n  ::std::pair<M, M>\
    \ garner(const Iterator& begin, const Iterator& end) {\n    const auto [y, z]\
    \ = ::tools::garner(begin, end, M::mod());\n    return ::std::make_pair(M::raw(y),\
    \ M::raw(z));\n  }\n}\n\n\n#line 15 \"tools/tetration_mod.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  T tetration_mod(const T a, const T b, const\
    \ T m) {\n    assert(a >= 0);\n    assert(b >= 0);\n    assert(m >= 1);\n\n  \
    \  if (m == 1) return 0;\n\n    // It returns min(fa^^fb, 2^63 - 1).\n    const\
    \ auto f = [](const ::std::int_fast64_t fa, const ::std::int_fast64_t fb) {\n\
    \      if (fa == 0) return 1 - fb % 2;\n      if (fa == 1) return ::std::int_fast64_t(1);\n\
    \      if (fb == 0) return ::std::int_fast64_t(1);\n      if (fb == 1) return\
    \ fa;\n      if (fb == 2 && fa <= 15) return ::tools::pow(fa, fa);\n      if (fb\
    \ == 3 && fa <= 3) return ::tools::pow(fa, ::tools::pow(fa, fa));\n      if (fb\
    \ == 4 && fa <= 2) return ::tools::pow(fa, ::tools::pow(fa, ::tools::pow(fa, fa)));\n\
    \n      // Too large\n      return ::std::numeric_limits<::std::int_fast64_t>::max();\n\
    \    };\n\n    if (f(a, b) < ::std::numeric_limits<::std::int_fast64_t>::max())\
    \ {\n      return f(a, b) % m;\n    }\n\n    ::std::vector<::std::pair<T, T>>\
    \ answers;\n    const ::std::vector<T> prime_factors = ::tools::prime_factorization(m);\n\
    \    ::std::vector<::std::pair<T, T>> distinct_prime_factors;\n    ::tools::run_length(prime_factors.begin(),\
    \ prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n    for\
    \ (const auto& [p, q] : distinct_prime_factors) {\n      const T P = ::tools::pow(p,\
    \ q);\n      if (::std::gcd(a, p) == 1) {\n        answers.emplace_back(::tools::pow_mod(a,\
    \ ::tools::tetration_mod(a, b - 1, ::tools::totient(P)), P), P);\n      } else\
    \ {\n        if (f(a, b - 1) >= q) {\n          answers.emplace_back(0, P);\n\
    \        } else {\n          answers.emplace_back(::tools::pow_mod(a, f(a, b -\
    \ 1), P), P);\n        }\n      }\n    }\n\n    return ::tools::garner(answers.begin(),\
    \ answers.end(), m).first;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_TETRATION_MOD_HPP\n#define TOOLS_TETRATION_MOD_HPP\n\n#include\
    \ <cstdint>\n#include <limits>\n#include <vector>\n#include <utility>\n#include\
    \ <iterator>\n#include \"tools/pow.hpp\"\n#include \"tools/prime_factorization.hpp\"\
    \n#include \"tools/run_length.hpp\"\n#include \"tools/totient.hpp\"\n#include\
    \ \"tools/pow_mod.hpp\"\n#include \"tools/garner.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename T>\n  T tetration_mod(const T a, const T b, const T m) {\n\
    \    assert(a >= 0);\n    assert(b >= 0);\n    assert(m >= 1);\n\n    if (m ==\
    \ 1) return 0;\n\n    // It returns min(fa^^fb, 2^63 - 1).\n    const auto f =\
    \ [](const ::std::int_fast64_t fa, const ::std::int_fast64_t fb) {\n      if (fa\
    \ == 0) return 1 - fb % 2;\n      if (fa == 1) return ::std::int_fast64_t(1);\n\
    \      if (fb == 0) return ::std::int_fast64_t(1);\n      if (fb == 1) return\
    \ fa;\n      if (fb == 2 && fa <= 15) return ::tools::pow(fa, fa);\n      if (fb\
    \ == 3 && fa <= 3) return ::tools::pow(fa, ::tools::pow(fa, fa));\n      if (fb\
    \ == 4 && fa <= 2) return ::tools::pow(fa, ::tools::pow(fa, ::tools::pow(fa, fa)));\n\
    \n      // Too large\n      return ::std::numeric_limits<::std::int_fast64_t>::max();\n\
    \    };\n\n    if (f(a, b) < ::std::numeric_limits<::std::int_fast64_t>::max())\
    \ {\n      return f(a, b) % m;\n    }\n\n    ::std::vector<::std::pair<T, T>>\
    \ answers;\n    const ::std::vector<T> prime_factors = ::tools::prime_factorization(m);\n\
    \    ::std::vector<::std::pair<T, T>> distinct_prime_factors;\n    ::tools::run_length(prime_factors.begin(),\
    \ prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n    for\
    \ (const auto& [p, q] : distinct_prime_factors) {\n      const T P = ::tools::pow(p,\
    \ q);\n      if (::std::gcd(a, p) == 1) {\n        answers.emplace_back(::tools::pow_mod(a,\
    \ ::tools::tetration_mod(a, b - 1, ::tools::totient(P)), P), P);\n      } else\
    \ {\n        if (f(a, b - 1) >= q) {\n          answers.emplace_back(0, P);\n\
    \        } else {\n          answers.emplace_back(::tools::pow_mod(a, f(a, b -\
    \ 1), P), P);\n        }\n      }\n    }\n\n    return ::tools::garner(answers.begin(),\
    \ answers.end(), m).first;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
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
  - tools/totient.hpp
  - tools/garner.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  isVerificationFile: false
  path: tools/tetration_mod.hpp
  requiredBy: []
  timestamp: '2021-12-31 20:01:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tetration_mod.test.cpp
documentation_of: tools/tetration_mod.hpp
layout: document
title: $x \uparrow\uparrow y \pmod{M}$
---

```cpp
template <typename T>
T tetration_mod(T x, T y, T M);
```

It returns $x \uparrow\uparrow y \pmod{M}$.

Note: In this function, $0^0$ is $1$.

## Constraints
- $x \geq 0$
- $y \geq 0$
- $M \geq 1$

## Time Complexity
- Not analyzed yet

## References
- [@maspy_stars - Twitter](https://twitter.com/maspy_stars/status/1363507553527734274)

## License
- CC0

## Author
- anqooqie
