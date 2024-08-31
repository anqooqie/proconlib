---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':question:'
    path: tools/fix.hpp
    title: Fixed point combinator
  - icon: ':question:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/gcd.hpp
    title: std::gcd(m, n) extended for my library
  - icon: ':question:'
    path: tools/is_monoid.hpp
    title: Check whether T is a monoid
  - icon: ':question:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':heavy_check_mark:'
    path: tools/ord_mod.hpp
    title: $\mathrm{ord}(x)$ for $x \in (\mathbb{Z}/p\mathbb{Z})^\times$
  - icon: ':question:'
    path: tools/popcount.hpp
    title: Popcount
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':question:'
    path: tools/pow_mod.hpp
    title: $x^y \pmod{M}$
  - icon: ':question:'
    path: tools/prime_factorization.hpp
    title: Pollard's rho algorithm
  - icon: ':question:'
    path: tools/prod_mod.hpp
    title: $x \cdot y \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':question:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/ord_mod.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/assert_that.hpp\"\n\n\n\n#line 5 \"tools/assert_that.hpp\"\
    \n#include <cstdlib>\n\n#define assert_that_impl(cond, file, line, func) do {\\\
    \n  if (!cond) {\\\n    ::std::cerr << file << ':' << line << \": \" << func <<\
    \ \": Assertion `\" << #cond << \"' failed.\" << '\\n';\\\n    ::std::exit(EXIT_FAILURE);\\\
    \n  }\\\n} while (false)\n#define assert_that(...) assert_that_impl((__VA_ARGS__),\
    \ __FILE__, __LINE__, __func__)\n\n\n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line\
    \ 1 \"tools/mod.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n\
    \      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return\
    \ -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) +\
    \ -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/prod_mod.hpp\"\
    \n\n\n\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\n#line 5 \"tools/uint128_t.hpp\"\
    \n#include <string>\n#include <cassert>\n#include <cstddef>\n#include <algorithm>\n\
    #line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr float abs(const\
    \ float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double abs(const double\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double abs(const long\
    \ double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int abs(const int\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const long x) {\n\
    \    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const long long x)\
    \ {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const unsigned\
    \ int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned long\
    \ x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 10 \"tools/uint128_t.hpp\"\n\
    \nnamespace tools {\n  using uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t\
    \ abs(const ::tools::uint128_t& x) {\n    return x;\n  }\n}\n\nconstexpr inline\
    \ ::tools::uint128_t UINT128_MAX = (::tools::uint128_t(1) << 127) | ((::tools::uint128_t(1)\
    \ << 127) - 1);\n\n::std::istream& operator>>(::std::istream& is, ::tools::uint128_t&\
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
    \n#line 6 \"tools/pow_mod.hpp\"\n\nnamespace tools {\n\n  template <typename T1,\
    \ typename T2, typename T3>\n  constexpr T3 pow_mod(const T1 x, T2 n, const T3\
    \ m) {\n    if (m == 1) return 0;\n    T3 r = 1;\n    T3 y = ::tools::mod(x, m);\n\
    \    while (n > 0) {\n      if ((n & 1) > 0) {\n        r = ::tools::prod_mod(r,\
    \ y, m);\n      }\n      y = ::tools::prod_mod(y, y, m);\n      n /= 2;\n    }\n\
    \    return r;\n  }\n}\n\n\n#line 1 \"tools/is_prime.hpp\"\n\n\n\n#include <array>\n\
    #line 7 \"tools/is_prime.hpp\"\n\nnamespace tools {\n\n  constexpr bool is_prime(const\
    \ unsigned long long n) {\n    constexpr ::std::array<unsigned long long, 7> bases\
    \ = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n    if (n <= 1) return\
    \ false;\n    if (n == 2) return true;\n    if (n % 2 == 0) return false;\n\n\
    \    auto d = n - 1;\n    for (; d % 2 == 0; d /= 2);\n\n    for (const auto a\
    \ : bases) {\n      if (a % n == 0) return true;\n\n      auto power = d;\n  \
    \    auto target = ::tools::pow_mod(a, power, n);\n\n      bool is_composite =\
    \ true;\n      if (target == 1) is_composite = false;\n      for (; is_composite\
    \ && power != n - 1; power *= 2, target = ::tools::prod_mod(target, target, n))\
    \ {\n        if (target == n - 1) is_composite = false;\n      }\n\n      if (is_composite)\
    \ {\n        return false;\n      }\n    }\n\n    return true;\n  }\n}\n\n\n#line\
    \ 1 \"tools/ord_mod.hpp\"\n\n\n\n#include <vector>\n#line 1 \"tools/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"tools/prime_factorization.hpp\"\n#include <queue>\n#include\
    \ <utility>\n#line 9 \"tools/prime_factorization.hpp\"\n#include <cmath>\n#include\
    \ <numeric>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\n\
    namespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
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
    \    return result;\n  }\n}\n\n\n#line 1 \"tools/pow.hpp\"\n\n\n\n#line 1 \"tools/monoid.hpp\"\
    \n\n\n\n#line 1 \"tools/gcd.hpp\"\n\n\n\n#line 6 \"tools/gcd.hpp\"\n\nnamespace\
    \ tools {\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> gcd(const M m, const N n) {\n    return ::std::gcd(m, n);\n  }\n}\n\n\n#line\
    \ 9 \"tools/monoid.hpp\"\n\nnamespace tools {\n  namespace monoid {\n    template\
    \ <typename M, M ...dummy>\n    struct max;\n\n    template <typename M>\n   \
    \ struct max<M> {\n      static_assert(::std::is_arithmetic_v<M>, \"M must be\
    \ a built-in arithmetic type.\");\n\n      using T = M;\n      static T op(const\
    \ T lhs, const T rhs) {\n        return ::std::max(lhs, rhs);\n      }\n     \
    \ static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n         \
    \ return ::std::numeric_limits<M>::min();\n        } else {\n          return\
    \ -::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\n    template\
    \ <typename M, M E>\n    struct max<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(E <= lhs);\n        assert(E\
    \ <= rhs);\n        return ::std::max(lhs, rhs);\n      }\n      static T e()\
    \ {\n        return E;\n      }\n    };\n\n    template <typename M, M ...dummy>\n\
    \    struct min;\n\n    template <typename M>\n    struct min<M> {\n      static_assert(::std::is_arithmetic_v<M>,\
    \ \"M must be a built-in arithmetic type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        return ::std::min(lhs, rhs);\n   \
    \   }\n      static T e() {\n        if constexpr (::std::is_integral_v<M>) {\n\
    \          return ::std::numeric_limits<M>::max();\n        } else {\n       \
    \   return ::std::numeric_limits<M>::infinity();\n        }\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct min<M, E> {\n      static_assert(::std::is_integral_v<M>,\
    \ \"M must be a built-in integral type.\");\n\n      using T = M;\n      static\
    \ T op(const T lhs, const T rhs) {\n        assert(lhs <= E);\n        assert(rhs\
    \ <= E);\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n    private:\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return lhs * rhs;\n      }\n      static T e() {\n \
    \       return T(1);\n      }\n    };\n\n    template <>\n    struct multiplies<bool>\
    \ {\n      using T = bool;\n      static T op(const bool lhs, const bool rhs)\
    \ {\n        return lhs && rhs;\n      }\n      static T e() {\n        return\
    \ true;\n      }\n    };\n\n    template <typename M>\n    struct gcd {\n    private:\n\
    \      static_assert(!::std::is_arithmetic_v<M> || (::std::is_integral_v<M> &&\
    \ !::std::is_same_v<M, bool>), \"If M is a built-in arithmetic type, it must be\
    \ integral except for bool.\");\n      using VR = ::std::conditional_t<::std::is_arithmetic_v<M>,\
    \ const M, const M&>;\n\n    public:\n      using T = M;\n      static T op(VR\
    \ lhs, VR rhs) {\n        return ::tools::gcd(lhs, rhs);\n      }\n      static\
    \ T e() {\n        return T(0);\n      }\n    };\n\n    template <typename M,\
    \ M E>\n    struct update {\n      static_assert(::std::is_integral_v<M>, \"M\
    \ must be a built-in integral type.\");\n\n      using T = M;\n      static T\
    \ op(const T lhs, const T rhs) {\n        return lhs == E ? rhs : lhs;\n     \
    \ }\n      static T e() {\n        return E;\n      }\n    };\n  }\n}\n\n\n#line\
    \ 1 \"tools/square.hpp\"\n\n\n\n#line 1 \"tools/is_monoid.hpp\"\n\n\n\n#line 6\
    \ \"tools/is_monoid.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ = void>\n  struct is_monoid : ::std::false_type {};\n\n  template <typename\
    \ M>\n  struct is_monoid<M, ::std::enable_if_t<\n    ::std::is_same_v<typename\
    \ M::T, decltype(M::op(::std::declval<typename M::T>(), ::std::declval<typename\
    \ M::T>()))> &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n  , void>>\
    \ : ::std::true_type {};\n\n  template <typename M>\n  inline constexpr bool is_monoid_v\
    \ = ::tools::is_monoid<M>::value;\n}\n\n\n#line 6 \"tools/square.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M>\n  ::std::enable_if_t<::tools::is_monoid_v<M>,\
    \ typename M::T> square(const typename M::T& x) {\n    return M::op(x, x);\n \
    \ }\n\n  template <typename T>\n  ::std::enable_if_t<!::tools::is_monoid_v<T>,\
    \ T> square(const T& x) {\n    return x * x;\n  }\n}\n\n\n#line 9 \"tools/pow.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ typename M::T> pow(const typename M::T& base, const E exponent) {\n    assert(exponent\
    \ >= 0);\n    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n\
    \        ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        :\
    \ M::op(::tools::pow<M>(base, exponent - 1), base);\n  }\n\n  template <typename\
    \ T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, T> pow(const T&\
    \ base, const E exponent) {\n    assert(exponent >= 0);\n    return ::tools::pow<::tools::monoid::multiplies<T>>(base,\
    \ exponent);\n  }\n\n  template <typename T, typename E>\n  auto pow(const T base,\
    \ const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>, decltype(::std::pow(base,\
    \ exponent))> {\n    return ::std::pow(base, exponent);\n  }\n}\n\n\n#line 1 \"\
    tools/fix.hpp\"\n\n\n\n#line 6 \"tools/fix.hpp\"\n\nnamespace tools {\n  template\
    \ <typename F>\n  struct fix : F {\n    template <typename G>\n    fix(G&& g)\
    \ : F({::std::forward<G>(g)}) {\n    }\n\n    template <typename... Args>\n  \
    \  decltype(auto) operator()(Args&&... args) const {\n      return F::operator()(*this,\
    \ ::std::forward<Args>(args)...);\n    }\n  };\n\n  template <typename F>\n  fix(F&&)\
    \ -> fix<::std::decay_t<F>>;\n}\n\n\n#line 12 \"tools/ord_mod.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T>\n  class ord_mod {\n  private:\n    T m_P;\n\
    \    ::std::vector<T> m_p;\n    ::std::vector<T> m_e;\n    ::std::vector<::std::vector<T>>\
    \ m_E;\n\n    ::std::size_t n() const {\n      return this->m_p.size();\n    }\n\
    \n  public:\n    ord_mod() = default;\n    ord_mod(const T P) : m_P(P) {\n   \
    \   assert(::tools::is_prime(P));\n\n      const auto factors = ::tools::prime_factorization(P\
    \ - 1);\n      for (::std::size_t l = 0, r = 0; l < factors.size(); l = r) {\n\
    \        for (; r < factors.size() && factors[l] == factors[r]; ++r);\n      \
    \  this->m_p.push_back(factors[l]);\n        this->m_e.push_back(r - l);\n   \
    \   }\n\n      this->m_E.resize(this->n() + 1);\n      for (::std::size_t l =\
    \ 0; l <= this->n(); ++l) {\n        this->m_E[l].resize(this->n() + 1);\n   \
    \     this->m_E[l][l] = 1;\n      }\n      for (::std::size_t l = 0; l + 1 <=\
    \ this->n(); ++l) {\n        this->m_E[l][l + 1] = ::tools::pow(this->m_p[l],\
    \ this->m_e[l]);\n      }\n      for (::std::size_t l = 0; l + 2 <= this->n();\
    \ ++l) {\n        for (::std::size_t r = l + 2; r <= this->n(); ++r) {\n     \
    \     this->m_E[l][r] = this->m_E[l][r - 1] * this->m_E[r - 1][r];\n        }\n\
    \      }\n    }\n\n    T query(const T x) const {\n      assert(1 <= x && x <\
    \ this->m_P);\n\n      T m = 1;\n      ::tools::fix([&](auto&& dfs, const ::std::size_t\
    \ l, const ::std::size_t r, const T Xbar_l_r) -> void {\n        switch (r - l)\
    \ {\n        case 0:\n          return;\n        case 1:\n          {\n      \
    \      ::std::size_t f_l;\n            T v;\n            for (f_l = 0, v = Xbar_l_r;\
    \ v != 1; ++f_l, v = ::tools::pow_mod(v, this->m_p[l], this->m_P));\n        \
    \    m *= ::tools::pow(this->m_p[l], f_l);\n          }\n          return;\n \
    \       default:\n          {\n            const auto m = (l + r) / 2;\n     \
    \       dfs(l, m, ::tools::pow_mod(Xbar_l_r, this->m_E[m][r], this->m_P));\n \
    \           dfs(m, r, ::tools::pow_mod(Xbar_l_r, this->m_E[l][m], this->m_P));\n\
    \          }\n          return;\n        }\n      })(0, this->n(), x);\n\n   \
    \   return m;\n    }\n  };\n}\n\n\n#line 8 \"tests/ord_mod.test.cpp\"\n\nusing\
    \ ll = long long;\n\nll naive(const ll x, const ll P) {\n  ll m;\n  for (m = 1;\
    \ tools::pow_mod(x, m, P) != 1; ++m);\n  return m;\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  for (ll P = 1; P <= 100; ++P) {\n\
    \    if (!tools::is_prime(P)) continue;\n    tools::ord_mod ord_mod(P);\n    for\
    \ (ll x = 1; x < P; ++x) {\n      assert_that(ord_mod.query(x) == naive(x, P));\n\
    \    }\n  }\n\n  tools::ord_mod ord_mod(999999999999999989);\n  assert_that(ord_mod.query(1)\
    \ == 1);\n  assert_that(ord_mod.query(2) == 999999999999999988);\n  assert_that(ord_mod.query(3)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(4) == 499999999999999994);\n\
    \  assert_that(ord_mod.query(5) == 249999999999999997);\n  assert_that(ord_mod.query(6)\
    \ == 499999999999999994);\n  assert_that(ord_mod.query(7) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(8) == 999999999999999988);\n  assert_that(ord_mod.query(9)\
    \ == 499999999999999994);\n  assert_that(ord_mod.query(10) == 999999999999999988);\n\
    \  assert_that(ord_mod.query(11) == 499999999999999994);\n  assert_that(ord_mod.query(12)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(13) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(14) == 999999999999999988);\n  assert_that(ord_mod.query(15)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(16) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(17) == 249999999999999997);\n  assert_that(ord_mod.query(18)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(19) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(20) == 499999999999999994);\n\n  std::cout << \"\
    Hello World\" << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include \"tools/assert_that.hpp\"\n#include \"tools/pow_mod.hpp\"\
    \n#include \"tools/is_prime.hpp\"\n#include \"tools/ord_mod.hpp\"\n\nusing ll\
    \ = long long;\n\nll naive(const ll x, const ll P) {\n  ll m;\n  for (m = 1; tools::pow_mod(x,\
    \ m, P) != 1; ++m);\n  return m;\n}\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  for (ll P = 1; P <= 100; ++P) {\n\
    \    if (!tools::is_prime(P)) continue;\n    tools::ord_mod ord_mod(P);\n    for\
    \ (ll x = 1; x < P; ++x) {\n      assert_that(ord_mod.query(x) == naive(x, P));\n\
    \    }\n  }\n\n  tools::ord_mod ord_mod(999999999999999989);\n  assert_that(ord_mod.query(1)\
    \ == 1);\n  assert_that(ord_mod.query(2) == 999999999999999988);\n  assert_that(ord_mod.query(3)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(4) == 499999999999999994);\n\
    \  assert_that(ord_mod.query(5) == 249999999999999997);\n  assert_that(ord_mod.query(6)\
    \ == 499999999999999994);\n  assert_that(ord_mod.query(7) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(8) == 999999999999999988);\n  assert_that(ord_mod.query(9)\
    \ == 499999999999999994);\n  assert_that(ord_mod.query(10) == 999999999999999988);\n\
    \  assert_that(ord_mod.query(11) == 499999999999999994);\n  assert_that(ord_mod.query(12)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(13) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(14) == 999999999999999988);\n  assert_that(ord_mod.query(15)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(16) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(17) == 249999999999999997);\n  assert_that(ord_mod.query(18)\
    \ == 999999999999999988);\n  assert_that(ord_mod.query(19) == 249999999999999997);\n\
    \  assert_that(ord_mod.query(20) == 499999999999999994);\n\n  std::cout << \"\
    Hello World\" << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  - tools/is_prime.hpp
  - tools/ord_mod.hpp
  - tools/prime_factorization.hpp
  - tools/pow2.hpp
  - tools/floor_log2.hpp
  - tools/popcount.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/gcd.hpp
  - tools/square.hpp
  - tools/is_monoid.hpp
  - tools/fix.hpp
  isVerificationFile: true
  path: tests/ord_mod.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 13:46:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/ord_mod.test.cpp
layout: document
redirect_from:
- /verify/tests/ord_mod.test.cpp
- /verify/tests/ord_mod.test.cpp.html
title: tests/ord_mod.test.cpp
---
