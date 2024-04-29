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
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':question:'
    path: tools/garner.hpp
    title: Garner's algorithm
  - icon: ':question:'
    path: tools/int128_t.hpp
    title: 128 bit signed integer
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
    path: tools/popcount.hpp
    title: Popcount
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
    path: tools/run_length.hpp
    title: Run-length encoding
  - icon: ':question:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/twelvefold_way.hpp
    title: Twelvefold way
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/extended_lucas.test.cpp
    title: tests/extended_lucas.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - icon: ':x:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html
  bundledCode: "#line 1 \"tools/extended_lucas.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <utility>\n#include <iterator>\n#line 1 \"tools/int128_t.hpp\"\
    \n\n\n\n#include <iostream>\n#include <string>\n#line 7 \"tools/int128_t.hpp\"\
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
    \ x;\n  }\n}\n\n\n#line 1 \"tools/uint128_t.hpp\"\n\n\n\n#line 10 \"tools/uint128_t.hpp\"\
    \n\nnamespace tools {\n  using uint128_t = unsigned __int128;\n\n  constexpr ::tools::uint128_t\
    \ abs(const ::tools::uint128_t& x) {\n    return x;\n  }\n}\n\nconstexpr inline\
    \ ::tools::uint128_t UINT128_MAX = (::tools::uint128_t(1) << 127) | ((::tools::uint128_t(1)\
    \ << 127) - 1);\n\n::std::istream& operator>>(::std::istream& is, ::tools::uint128_t&\
    \ x) {\n  ::std::string s;\n  is >> s;\n  assert(!s.empty());\n\n  x = 0;\n  for\
    \ (::std::size_t i = s[0] == '+'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  return is;\n}\n\n\
    ::std::ostream& operator<<(::std::ostream& os, ::tools::uint128_t x) {\n  if (x\
    \ == 0) return os << '0';\n\n  ::std::string s;\n  while (x > 0) {\n    s.push_back('0'\
    \ + x % 10);\n    x /= 10;\n  }\n  ::std::reverse(s.begin(), s.end());\n\n  return\
    \ os << s;\n}\n\n\n#line 11 \"tools/int128_t.hpp\"\n\nnamespace tools {\n  using\
    \ int128_t = __int128;\n\n  constexpr ::tools::int128_t abs(const ::tools::int128_t&\
    \ x) {\n    return x < 0 ? -x : x;\n  }\n}\n\nconstexpr inline ::tools::int128_t\
    \ INT128_MAX = (::tools::int128_t(1) << 126) | ((::tools::int128_t(1) << 126)\
    \ - 1);\nconstexpr inline ::tools::int128_t INT128_MIN = -INT128_MAX - 1;\n\n\
    ::std::istream& operator>>(::std::istream& is, ::tools::int128_t& x) {\n  ::std::string\
    \ s;\n  is >> s;\n  assert(!s.empty());\n\n  if (s == \"-170141183460469231731687303715884105728\"\
    ) {\n    x = INT128_MIN;\n    return is;\n  }\n\n  x = 0;\n  for (::std::size_t\
    \ i = s[0] == '+' || s[0] == '-'; i < s.size(); ++i) {\n    assert('0' <= s[i]\
    \ && s[i] <= '9');\n    x = 10 * x + (s[i] - '0');\n  }\n\n  if (s[0] == '-')\
    \ x = -x;\n\n  return is;\n}\n\n::std::ostream& operator<<(::std::ostream& os,\
    \ ::tools::int128_t x) {\n  if (x == 0) return os << '0';\n  if (x == INT128_MIN)\
    \ return os << \"-170141183460469231731687303715884105728\";\n\n  ::std::string\
    \ s;\n  const bool negative = x < 0;\n\n  if (negative) x = -x;\n  while (x >\
    \ 0) {\n    s.push_back('0' + x % 10);\n    x /= 10;\n  }\n\n  if (negative) s.push_back('-');\n\
    \  ::std::reverse(s.begin(), s.end());\n  return os << s;\n}\n\n\n#line 1 \"tools/prime_factorization.hpp\"\
    \n\n\n\n#line 6 \"tools/prime_factorization.hpp\"\n#include <queue>\n#line 9 \"\
    tools/prime_factorization.hpp\"\n#include <cmath>\n#include <numeric>\n#line 1\
    \ \"tools/is_prime.hpp\"\n\n\n\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\
    \n\n\n\n#line 5 \"tools/prod_mod.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2, typename T3>\n  constexpr T3 prod_mod(const T1 x, const T2\
    \ y, const T3 m) {\n    using u128 = ::tools::uint128_t;\n    u128 prod_mod =\
    \ u128(x >= 0 ? x : -x) * u128(y >= 0 ? y : -y) % u128(m);\n    if ((x >= 0) ^\
    \ (y >= 0)) prod_mod = u128(m) - prod_mod;\n    return prod_mod;\n  }\n}\n\n\n\
    #line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#include\
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
    \ 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools {\n\
    \n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
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
    \      }\n    }\n  }\n}\n\n\n#line 1 \"tools/garner.hpp\"\n\n\n\n#line 1 \"tools/inv_mod.hpp\"\
    \n\n\n\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#include <tuple>\n#line 9 \"tools/extgcd.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T\
    \ prev_r, T r) {\n    const bool prev_r_is_neg = prev_r < T(0);\n    const bool\
    \ r_is_neg = r < T(0);\n\n    if (prev_r_is_neg) prev_r = -prev_r;\n    if (r_is_neg)\
    \ r = -r;\n\n    #ifndef NDEBUG\n    const T a = prev_r;\n    const T b = r;\n\
    \    #endif\n\n    T prev_s(1);\n    T prev_t(0);\n    T s(0);\n    T t(1);\n\
    \    while (r != T(0)) {\n      const T q = prev_r / r;\n      ::std::tie(prev_r,\
    \ r) = ::std::make_pair(r, prev_r - q * r);\n      ::std::tie(prev_s, s) = ::std::make_pair(s,\
    \ prev_s - q * s);\n      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t -\
    \ q * t);\n    }\n\n    if (prev_r_is_neg) prev_s = -prev_s;\n    if (r_is_neg)\
    \ prev_t = -prev_t;\n\n    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r\
    \ / T(2), T(1)));\n    assert(::tools::abs(prev_t) <= ::std::max(a / prev_r /\
    \ T(2), T(1)));\n    return ::std::make_tuple(prev_s, prev_t, prev_r);\n  }\n\
    }\n\n\n#line 7 \"tools/inv_mod.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T1, typename T2>\n  constexpr T2 inv_mod(const T1 x, const T2 m) {\n    const\
    \ auto [x0, y0, gcd] = ::tools::extgcd(x, m);\n    assert(gcd == 1);\n    return\
    \ ::tools::mod(x0, m);\n  }\n}\n\n\n#line 9 \"tools/garner.hpp\"\n\n// Source:\
    \ https://qiita.com/drken/items/ae02240cd1f8edfc86fd\n// License: unknown\n//\
    \ Author: drken\n\nnamespace tools {\n\n  template <typename Iterator, typename\
    \ ModType>\n  ::std::pair<long long, long long> garner(const Iterator& begin,\
    \ const Iterator& end, const ModType& mod) {\n    ::std::vector<long long> b,\
    \ m;\n    for (auto it = begin; it != end; ++it) {\n      b.push_back(::tools::mod(it->first,\
    \ it->second));\n      m.push_back(it->second);\n    }\n\n    auto lcm = 1LL;\n\
    \    for (::std::size_t i = 0; i < b.size(); ++i) {\n      (lcm *= m[i]) %= mod;\n\
    \    }\n\n    m.push_back(mod);\n    ::std::vector<long long> coeffs(m.size(),\
    \ 1);\n    ::std::vector<long long> constants(m.size(), 0);\n    for (::std::size_t\
    \ k = 0; k < b.size(); ++k) {\n      long long t = ::tools::mod((b[k] - constants[k])\
    \ * ::tools::inv_mod(coeffs[k], m[k]), m[k]);\n      for (::std::size_t i = k\
    \ + 1; i < m.size(); ++i) {\n        (constants[i] += t * coeffs[i]) %= m[i];\n\
    \        (coeffs[i] *= m[k]) %= m[i];\n      }\n    }\n\n    return ::std::make_pair(constants.back(),\
    \ lcm);\n  }\n\n  template <typename M, typename Iterator>\n  ::std::pair<M, M>\
    \ garner(const Iterator& begin, const Iterator& end) {\n    const auto [y, z]\
    \ = ::tools::garner(begin, end, M::mod());\n    return ::std::make_pair(M::raw(y),\
    \ M::raw(z));\n  }\n}\n\n\n#line 12 \"tools/extended_lucas.hpp\"\n\n// Source:\
    \ https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html\n// License:\
    \ MIT\n// Author: hitonanode\n\n// MIT License\n// \n// Copyright (c) 2019 Ryotaro\
    \ Sato\n// \n// Permission is hereby granted, free of charge, to any person obtaining\
    \ a copy\n// of this software and associated documentation files (the \"Software\"\
    ), to deal\n// in the Software without restriction, including without limitation\
    \ the rights\n// to use, copy, modify, merge, publish, distribute, sublicense,\
    \ and/or sell\n// copies of the Software, and to permit persons to whom the Software\
    \ is\n// furnished to do so, subject to the following conditions:\n// \n// The\
    \ above copyright notice and this permission notice shall be included in all\n\
    // copies or substantial portions of the Software.\n// \n// THE SOFTWARE IS PROVIDED\
    \ \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED, INCLUDING BUT\
    \ NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS FOR A PARTICULAR\
    \ PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS OR COPYRIGHT\
    \ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY, WHETHER IN\
    \ AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF OR IN CONNECTION\
    \ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n// SOFTWARE.\n\nnamespace\
    \ tools {\n\n  template <class M>\n  class extended_lucas {\n    struct combination_prime_pow\
    \ {\n      int p, q, m;\n      ::std::vector<int> fac, invfac, ppow;\n\n     \
    \ long long ej(long long n) const {\n        long long ret = 0;\n        while\
    \ (n) ret += n, n /= this->p;\n        return ret;\n      }\n\n      combination_prime_pow(const\
    \ int p_, const int q_) : p(p_), q(q_), m(1), ppow{1} {\n        for (int t =\
    \ 0; t < this->q; ++t) this->m *= this->p, this->ppow.push_back(this->m);\n  \
    \      this->fac.assign(this->m, 1);\n        this->invfac.assign(this->m, 1);\n\
    \        for (int i = 1; i < this->m; ++i) this->fac[i] = static_cast<long long>(this->fac[i\
    \ - 1]) * (i % this->p ? i : 1) % this->m;\n        this->invfac[this->m - 1]\
    \ = this->fac[this->m - 1]; // Same as Wilson's theorem\n        assert(1LL *\
    \ this->fac.back() * this->invfac.back() % this->m == 1);\n        for (int i\
    \ = this->m - 1; i; --i) this->invfac[i - 1] = static_cast<long long>(this->invfac[i])\
    \ * (i % this->p ? i : 1) % this->m;\n      }\n\n      int fact(const long long\
    \ n) const {\n        assert(n >= 0);\n        const auto q0 = this->ej(n / this->p);\n\
    \        return q0 < this->q ? static_cast<long long>(this->fac[n]) * this->ppow[q0]\
    \ % this->m : 0;\n      }\n\n      int combination(long long n, long long r) const\
    \ {\n        assert(0 <= r && r <= n);\n        if (this->p == 2 && this->q ==\
    \ 1) return !((~n) & r); // Lucas\n        long long k = n - r;\n        const\
    \ long long e0 = this->ej(n / this->p) - this->ej(r / this->p) - this->ej(k /\
    \ this->p);\n        if (e0 >= q) return 0;\n\n        long long ret = this->ppow[e0];\n\
    \        if (this->q == 1) { // Lucas\n          while (n) {\n            ret\
    \ = ::tools::int128_t(ret) * this->fac[n % this->p] * this->invfac[r % this->p]\
    \ * this->invfac[k % this->p] % this->p;\n            n /= this->p, r /= this->p,\
    \ k /= this->p;\n          }\n          return static_cast<int>(ret);\n      \
    \  } else {\n          if ((p > 2 || q < 3) && (this->ej(n / this->m) - this->ej(r\
    \ / this->m) - this->ej(k / this->m)) & 1) ret = this->m - ret;\n          while\
    \ (n) {\n            ret = ::tools::int128_t(ret) * this->fac[n % this->m] * this->invfac[r\
    \ % this->m] * this->invfac[k % this->m] % this->m;\n            n /= this->p,\
    \ r /= this->p, k /= this->p;\n          }\n          return static_cast<int>(ret);\n\
    \        }\n      }\n    };\n\n    ::std::vector<combination_prime_pow> m_cpps;\n\
    \n  public:\n    extended_lucas() {\n      const auto prime_factors = ::tools::prime_factorization(M::mod());\n\
    \      ::std::vector<::std::pair<int, int>> distinct_prime_factors;\n      ::tools::run_length(prime_factors.begin(),\
    \ prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n      for\
    \ (const auto& [p, q] : distinct_prime_factors) {\n        this->m_cpps.emplace_back(p,\
    \ q);\n      }\n    }\n\n    M fact(const long long n) const {\n      assert(n\
    \ >= 0);\n      ::std::vector<::std::pair<int, int>> rs;\n      for (const auto&\
    \ cpp : this->m_cpps) rs.emplace_back(cpp.fact(n), cpp.m);\n      return ::tools::garner<M>(rs.begin(),\
    \ rs.end()).first;\n    }\n    M binomial(const long long n, const long long r)\
    \ const {\n      if (r < 0) return M::raw(0);\n      if (0 <= n && n < r) return\
    \ M::raw(0);\n      if (n < 0) return M((r & 1) ? -1 : 1) * this->binomial(-n\
    \ + r - 1, r);\n\n      ::std::vector<::std::pair<int, int>> rs;\n      for (const\
    \ auto& cpp : this->m_cpps) rs.emplace_back(cpp.combination(n, r), cpp.m);\n \
    \     return ::tools::garner<M>(rs.begin(), rs.end()).first;\n    }\n    M combination(const\
    \ long long n, const long long r) const {\n      if (!(0 <= r && r <= n)) return\
    \ M::raw(0);\n      return this->binomial(n, r);\n    }\n    M permutation(const\
    \ long long n, const long long r) const {\n      if (!(0 <= r && r <= n)) return\
    \ M::raw(0);\n      return this->binomial(n, r) * this->fact(r);\n    }\n    M\
    \ combination_with_repetition(const long long n, const long long r) const {\n\
    \      if (n < 0 || r < 0) return M::raw(0);\n      return this->binomial(n +\
    \ r - 1, r);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_EXTENDED_LUCAS_HPP\n#define TOOLS_EXTENDED_LUCAS_HPP\n\n#include\
    \ <vector>\n#include <cassert>\n#include <utility>\n#include <iterator>\n#include\
    \ \"tools/int128_t.hpp\"\n#include \"tools/prime_factorization.hpp\"\n#include\
    \ \"tools/run_length.hpp\"\n#include \"tools/garner.hpp\"\n\n// Source: https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html\n\
    // License: MIT\n// Author: hitonanode\n\n// MIT License\n// \n// Copyright (c)\
    \ 2019 Ryotaro Sato\n// \n// Permission is hereby granted, free of charge, to\
    \ any person obtaining a copy\n// of this software and associated documentation\
    \ files (the \"Software\"), to deal\n// in the Software without restriction, including\
    \ without limitation the rights\n// to use, copy, modify, merge, publish, distribute,\
    \ sublicense, and/or sell\n// copies of the Software, and to permit persons to\
    \ whom the Software is\n// furnished to do so, subject to the following conditions:\n\
    // \n// The above copyright notice and this permission notice shall be included\
    \ in all\n// copies or substantial portions of the Software.\n// \n// THE SOFTWARE\
    \ IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED,\
    \ INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS\
    \ FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS\
    \ OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY,\
    \ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF\
    \ OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n// SOFTWARE.\n\
    \nnamespace tools {\n\n  template <class M>\n  class extended_lucas {\n    struct\
    \ combination_prime_pow {\n      int p, q, m;\n      ::std::vector<int> fac, invfac,\
    \ ppow;\n\n      long long ej(long long n) const {\n        long long ret = 0;\n\
    \        while (n) ret += n, n /= this->p;\n        return ret;\n      }\n\n \
    \     combination_prime_pow(const int p_, const int q_) : p(p_), q(q_), m(1),\
    \ ppow{1} {\n        for (int t = 0; t < this->q; ++t) this->m *= this->p, this->ppow.push_back(this->m);\n\
    \        this->fac.assign(this->m, 1);\n        this->invfac.assign(this->m, 1);\n\
    \        for (int i = 1; i < this->m; ++i) this->fac[i] = static_cast<long long>(this->fac[i\
    \ - 1]) * (i % this->p ? i : 1) % this->m;\n        this->invfac[this->m - 1]\
    \ = this->fac[this->m - 1]; // Same as Wilson's theorem\n        assert(1LL *\
    \ this->fac.back() * this->invfac.back() % this->m == 1);\n        for (int i\
    \ = this->m - 1; i; --i) this->invfac[i - 1] = static_cast<long long>(this->invfac[i])\
    \ * (i % this->p ? i : 1) % this->m;\n      }\n\n      int fact(const long long\
    \ n) const {\n        assert(n >= 0);\n        const auto q0 = this->ej(n / this->p);\n\
    \        return q0 < this->q ? static_cast<long long>(this->fac[n]) * this->ppow[q0]\
    \ % this->m : 0;\n      }\n\n      int combination(long long n, long long r) const\
    \ {\n        assert(0 <= r && r <= n);\n        if (this->p == 2 && this->q ==\
    \ 1) return !((~n) & r); // Lucas\n        long long k = n - r;\n        const\
    \ long long e0 = this->ej(n / this->p) - this->ej(r / this->p) - this->ej(k /\
    \ this->p);\n        if (e0 >= q) return 0;\n\n        long long ret = this->ppow[e0];\n\
    \        if (this->q == 1) { // Lucas\n          while (n) {\n            ret\
    \ = ::tools::int128_t(ret) * this->fac[n % this->p] * this->invfac[r % this->p]\
    \ * this->invfac[k % this->p] % this->p;\n            n /= this->p, r /= this->p,\
    \ k /= this->p;\n          }\n          return static_cast<int>(ret);\n      \
    \  } else {\n          if ((p > 2 || q < 3) && (this->ej(n / this->m) - this->ej(r\
    \ / this->m) - this->ej(k / this->m)) & 1) ret = this->m - ret;\n          while\
    \ (n) {\n            ret = ::tools::int128_t(ret) * this->fac[n % this->m] * this->invfac[r\
    \ % this->m] * this->invfac[k % this->m] % this->m;\n            n /= this->p,\
    \ r /= this->p, k /= this->p;\n          }\n          return static_cast<int>(ret);\n\
    \        }\n      }\n    };\n\n    ::std::vector<combination_prime_pow> m_cpps;\n\
    \n  public:\n    extended_lucas() {\n      const auto prime_factors = ::tools::prime_factorization(M::mod());\n\
    \      ::std::vector<::std::pair<int, int>> distinct_prime_factors;\n      ::tools::run_length(prime_factors.begin(),\
    \ prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n      for\
    \ (const auto& [p, q] : distinct_prime_factors) {\n        this->m_cpps.emplace_back(p,\
    \ q);\n      }\n    }\n\n    M fact(const long long n) const {\n      assert(n\
    \ >= 0);\n      ::std::vector<::std::pair<int, int>> rs;\n      for (const auto&\
    \ cpp : this->m_cpps) rs.emplace_back(cpp.fact(n), cpp.m);\n      return ::tools::garner<M>(rs.begin(),\
    \ rs.end()).first;\n    }\n    M binomial(const long long n, const long long r)\
    \ const {\n      if (r < 0) return M::raw(0);\n      if (0 <= n && n < r) return\
    \ M::raw(0);\n      if (n < 0) return M((r & 1) ? -1 : 1) * this->binomial(-n\
    \ + r - 1, r);\n\n      ::std::vector<::std::pair<int, int>> rs;\n      for (const\
    \ auto& cpp : this->m_cpps) rs.emplace_back(cpp.combination(n, r), cpp.m);\n \
    \     return ::tools::garner<M>(rs.begin(), rs.end()).first;\n    }\n    M combination(const\
    \ long long n, const long long r) const {\n      if (!(0 <= r && r <= n)) return\
    \ M::raw(0);\n      return this->binomial(n, r);\n    }\n    M permutation(const\
    \ long long n, const long long r) const {\n      if (!(0 <= r && r <= n)) return\
    \ M::raw(0);\n      return this->binomial(n, r) * this->fact(r);\n    }\n    M\
    \ combination_with_repetition(const long long n, const long long r) const {\n\
    \      if (n < 0 || r < 0) return M::raw(0);\n      return this->binomial(n +\
    \ r - 1, r);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/int128_t.hpp
  - tools/abs.hpp
  - tools/uint128_t.hpp
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
  - tools/garner.hpp
  - tools/inv_mod.hpp
  - tools/extgcd.hpp
  isVerificationFile: false
  path: tools/extended_lucas.hpp
  requiredBy:
  - tools/twelvefold_way.hpp
  timestamp: '2024-04-29 15:33:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/extended_lucas.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
documentation_of: tools/extended_lucas.hpp
layout: document
title: Extended Lucas' theorem
---

It precomputes ${}_n C_r \pmod{M}$ for any $n$, any $r$ and a small fixed $M$.

### References
- [Combination （${}_n \mathrm{C}_r \bmod{m}$，Lucas の定理の拡張） \| cplib-cp](https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html)

### License
- MIT

### Author
- hitonanode

## Constructor
```cpp
tools::extended_lucas<T> cache();
```

It precomputes ${}_n \mathrm{C}_r \pmod{M}$ for any $n$ and $r$ where $M$ is `T::mod()`.

### Constraints
- `<T>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $\sum_{i = 1}^k p_i^{q_i} \leq 10^7$ where $M = p_1^{q_1} p_2^{q_2} \cdots p_k^{q_k}$

### Time Complexity
- $O\left( M^\frac{1}{4} + \sum_{i = 1}^k p_i^{q_i} \right)$

## fact
```cpp
M cache.fact(long long n);
```

It returns $n! \pmod{M}$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O( k \log n + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## binomial
```cpp
M cache.binomial(long long n, long long r);
```

It returns $\dbinom{n}{r} \pmod{M}$.
Note that $\dbinom{-n}{r} = (-1)^r \dbinom{n + r - 1}{r}$.

### Constraints
- None

### Time Complexity
- ($n \geq 0$):
    - $O(k \log n + k^2)$
- ($n < 0$):
    - $O(k \log (\|n\| + r) + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## combination
```cpp
M cache.combination(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{C}_r \pmod{M} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(k \log n + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## permutation
```cpp
M cache.permutation(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{P}_r \pmod{M} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(k \log n + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## combination_with_repetition
```cpp
M cache.combination_with_repetition(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{H}_r \pmod{M} & \text{(if $n \geq 0$ and $r \geq 0$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(k \log (n + r) + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$
