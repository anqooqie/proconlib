---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/assert_that.hpp
    title: Assertion macro
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/divisors.hpp
    title: List all divisors
  - icon: ':heavy_check_mark:'
    path: tools/divisors_of_divisor.hpp
    title: List all divisors of a divisor of $n$
  - icon: ':heavy_check_mark:'
    path: tools/floor_log2.hpp
    title: $\left\lfloor \log_2(x) \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/is_prime.hpp
    title: Miller-Rabin primality test
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/run_length.hpp
    title: Run-length encoding
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"tests/divisors_of_divisor.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <iterator>\n#line 1 \"tools/assert_that.hpp\"\
    \n\n\n\n#line 5 \"tools/assert_that.hpp\"\n#include <cstdlib>\n\n#define assert_that_impl(cond,\
    \ file, line, func) do {\\\n  if (!cond) {\\\n    ::std::cerr << file << ':' <<\
    \ line << \": \" << func << \": Assertion `\" << #cond << \"' failed.\" << '\\\
    n';\\\n    ::std::exit(EXIT_FAILURE);\\\n  }\\\n} while (false)\n#define assert_that(...)\
    \ assert_that_impl((__VA_ARGS__), __FILE__, __LINE__, __func__)\n\n\n#line 1 \"\
    tools/divisors_of_divisor.hpp\"\n\n\n\n#line 5 \"tools/divisors_of_divisor.hpp\"\
    \n#include <cstddef>\n#line 8 \"tools/divisors_of_divisor.hpp\"\n#include <cassert>\n\
    #include <numeric>\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#include <type_traits>\n\
    #line 6 \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/prime_factorization.hpp\"\n\n\n\n#line\
    \ 6 \"tools/prime_factorization.hpp\"\n#include <queue>\n#include <utility>\n\
    #line 9 \"tools/prime_factorization.hpp\"\n#include <cmath>\n#line 1 \"tools/is_prime.hpp\"\
    \n\n\n\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\
    \n\n\n\n#line 5 \"tools/uint128_t.hpp\"\n#include <string>\n#line 1 \"tools/abs.hpp\"\
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
    \n#line 1 \"tools/pow_mod.hpp\"\n\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line\
    \ 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const\
    \ M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs\
    \ >= M(0)) {\n      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n\
    \        return -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return\
    \ (-lhs - T(1) + -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
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
    \    return result;\n  }\n}\n\n\n#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5\
    \ \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename T, typename\
    \ U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n    using UT\
    \ = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n  \
    \  if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n\
    \  template <class F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n\
    \    less_by(const F& selector) : selector(selector) {\n    }\n\n    template\
    \ <class T>\n    bool operator()(const T& x, const T& y) const {\n      return\
    \ selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line 14 \"tools/divisors_of_divisor.hpp\"\
    \n\nnamespace tools {\n  template <typename T>\n  class divisors_of_divisor {\n\
    \    ::std::vector<T> m_divisors;\n    ::std::vector<int> m_sorted_divisors;\n\
    \    ::std::vector<int> m_Q;\n\n  public:\n    class divisors_iterable {\n   \
    \   const ::tools::divisors_of_divisor<T> *m_parent;\n      int m_s;\n\n    public:\n\
    \      class iterator {\n        const ::tools::divisors_of_divisor<T> *m_parent;\n\
    \        int m_s;\n        int m_t;\n\n      public:\n        using difference_type\
    \ = ::std::ptrdiff_t;\n        using value_type = T;\n        using reference\
    \ = const T&;\n        using pointer = const T*;\n        using iterator_category\
    \ = ::std::bidirectional_iterator_tag;\n\n        iterator() = default;\n    \
    \    iterator(const ::tools::divisors_of_divisor<T> * const parent, const int\
    \ s, const int t) : m_parent(parent), m_s(s), m_t(t) {\n        }\n\n        reference\
    \ operator*() const {\n          return this->m_parent->m_divisors[this->m_t];\n\
    \        }\n        pointer operator->() const {\n          return &(*(*this));\n\
    \        }\n\n        iterator& operator++() {\n          ++this->m_t;\n     \
    \     for (\n            auto it = ::std::next(this->m_parent->m_Q.begin());\n\
    \            this->m_t < this->m_parent->m_Q.back() && this->m_parent->m_divisors[this->m_s]\
    \ % this->m_parent->m_divisors[this->m_t] != 0;\n            ++it\n          )\
    \ {\n            this->m_t = ::tools::ceil(this->m_t, *it) * *it;\n          }\n\
    \          return *this;\n        }\n        iterator operator++(int) {\n    \
    \      const auto self = *this;\n          ++*this;\n          return self;\n\
    \        }\n        iterator& operator--() {\n          --this->m_t;\n       \
    \   for (int i = 0, max = 0; this->m_parent->m_divisors[this->m_s] % this->m_parent->m_divisors[this->m_t]\
    \ != 0; ++i) {\n            const auto q = this->m_s % this->m_parent->m_Q[i +\
    \ 1] / this->m_parent->m_Q[i];\n            max += q * this->m_parent->m_Q[i];\n\
    \            this->m_t = this->m_t / this->m_parent->m_Q[i + 1] * this->m_parent->m_Q[i\
    \ + 1] + ::std::min(this->m_t % this->m_parent->m_Q[i + 1], max);\n          }\n\
    \          return *this;\n        }\n        iterator operator--(int) {\n    \
    \      const auto self = *this;\n          --*this;\n          return self;\n\
    \        }\n        friend bool operator==(const iterator lhs, const iterator\
    \ rhs) {\n          assert(lhs.m_parent == rhs.m_parent);\n          assert(lhs.m_s\
    \ == rhs.m_s);\n          return lhs.m_t == rhs.m_t;\n        }\n        friend\
    \ bool operator!=(const iterator lhs, const iterator rhs) {\n          assert(lhs.m_parent\
    \ == rhs.m_parent);\n          assert(lhs.m_s == rhs.m_s);\n          return lhs.m_t\
    \ != rhs.m_t;\n        }\n\n        operator typename ::std::vector<T>::const_iterator()\
    \ const {\n          return this->m_parent->m_divisors.cbegin() + this->m_t;\n\
    \        }\n      };\n\n      divisors_iterable() = default;\n      divisors_iterable(const\
    \ ::tools::divisors_of_divisor<T> * const parent, const int s) : m_parent(parent),\
    \ m_s(s) {\n      }\n\n      iterator begin() const {\n        return iterator(this->m_parent,\
    \ this->m_s, 0);\n      }\n      iterator end() const {\n        return iterator(this->m_parent,\
    \ this->m_s, this->m_parent->m_Q.back());\n      }\n    };\n\n    divisors_of_divisor()\
    \ = default;\n    divisors_of_divisor(const T n) {\n      const auto factors =\
    \ ::tools::prime_factorization(n);\n      this->m_divisors.push_back(1);\n   \
    \   this->m_Q.push_back(1);\n      for (int l = 0, r = 0; ::tools::cmp_less(l,\
    \ factors.size()); l = r) {\n        for (; ::tools::cmp_less(r, factors.size())\
    \ && factors[l] == factors[r]; ++r);\n        const auto& p = factors[l];\n  \
    \      const auto q = r - l;\n        const int divisors_size = this->m_divisors.size();\n\
    \        T pe = 1;\n        for (int e = 1; e <= q; ++e) {\n          pe *= p;\n\
    \          for (int i = 0; i < divisors_size; ++i) {\n            this->m_divisors.push_back(this->m_divisors[i]\
    \ * pe);\n          }\n        }\n        this->m_Q.push_back(this->m_Q.back()\
    \ * (q + 1));\n      }\n\n      this->m_sorted_divisors.resize(this->m_divisors.size());\n\
    \      ::std::iota(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(),\
    \ 0);\n      ::std::sort(this->m_sorted_divisors.begin(), this->m_sorted_divisors.end(),\
    \ ::tools::less_by([&](const auto i) { return this->m_divisors[i]; }));\n    }\n\
    \n    typename ::std::vector<T>::const_iterator find(const T x) const {\n    \
    \  if (const auto it = ::std::partition_point(this->m_sorted_divisors.begin(),\
    \ this->m_sorted_divisors.end(), [&](const auto i) { return this->m_divisors[i]\
    \ < x; }); it != this->m_sorted_divisors.end()) {\n        if (this->m_divisors[*it]\
    \ == x) {\n          return this->m_divisors.cbegin() + *it;\n        } else {\n\
    \          return this->m_divisors.cend();\n        }\n      } else {\n      \
    \  return this->m_divisors.cend();\n      }\n    }\n    bool contains(const T\
    \ x) const {\n      return this->find(x) != this->m_divisors.cend();\n    }\n\n\
    \    const ::std::vector<T>& divisors() const {\n      return this->m_divisors;\n\
    \    }\n    divisors_iterable divisors(const typename ::std::vector<T>::const_iterator\
    \ it) const {\n      assert(it != this->m_divisors.cend());\n      return divisors_iterable(this,\
    \ ::std::distance(this->m_divisors.cbegin(), it));\n    }\n    divisors_iterable\
    \ divisors(const T d) const {\n      return this->divisors(this->find(d));\n \
    \   }\n  };\n}\n\n\n#line 1 \"tools/divisors.hpp\"\n\n\n\n#line 1 \"tools/run_length.hpp\"\
    \n\n\n\n#line 8 \"tools/run_length.hpp\"\n\nnamespace tools {\n  template <typename\
    \ InputIterator, typename OutputIterator>\n  void run_length(const InputIterator&\
    \ begin, const InputIterator& end, OutputIterator result) {\n    using T = typename\
    \ ::std::iterator_traits<InputIterator>::value_type;\n    if (begin == end) return;\n\
    \n    ::std::pair<T, ::std::size_t> prev;\n    for (auto [it, breaks] = ::std::make_pair(begin,\
    \ false); !breaks; breaks = it == end, it = ::std::next(it, breaks ? 0 : 1)) {\n\
    \      bool flg1, flg2;\n      if (it == begin) {\n        flg1 = false;\n   \
    \     flg2 = true;\n      } else if (it == end) {\n        flg1 = true;\n    \
    \    flg2 = false;\n      } else if (*it != prev.first) {\n        flg1 = true;\n\
    \        flg2 = true;\n      } else {\n        flg1 = false;\n        flg2 = false;\n\
    \      }\n      if (flg1 || flg2) {\n        if (flg1) {\n          *result =\
    \ prev;\n          ++result;\n        }\n        if (flg2) {\n          prev.first\
    \ = *it;\n          prev.second = 1;\n        }\n      } else {\n        ++prev.second;\n\
    \      }\n    }\n  }\n}\n\n\n#line 11 \"tools/divisors.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  ::std::vector<T> divisors(const T& n) {\n  \
    \  const ::std::vector<T> prime_factors = ::tools::prime_factorization(n);\n \
    \   ::std::vector<::std::pair<T, T>> distinct_prime_factors;\n    ::tools::run_length(prime_factors.begin(),\
    \ prime_factors.end(), ::std::back_inserter(distinct_prime_factors));\n\n    ::std::vector<T>\
    \ result({1});\n    for (const auto& [p, q] : distinct_prime_factors) {\n    \
    \  const ::std::size_t prev_size = result.size();\n      for (::std::size_t i\
    \ = 0; i < prev_size; ++i) {\n        for (T e = 1, p_e = p; e <= q; ++e, p_e\
    \ *= p) {\n          result.push_back(result[i] * p_e);\n        }\n      }\n\
    \    }\n    ::std::sort(result.begin(), result.end());\n    return result;\n \
    \ }\n}\n\n\n#line 10 \"tests/divisors_of_divisor.test.cpp\"\n\nusing ll = long\
    \ long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  {\n    std::vector<std::vector<ll>> divisors(101);\n    for (ll n = 1; n <=\
    \ 100; ++n) {\n      divisors[n] = tools::divisors(n);\n    }\n\n    for (ll n\
    \ = 1; n <= 100; ++n) {\n      tools::divisors_of_divisor<ll> ds(n);\n\n     \
    \ assert_that([&]() {\n        std::vector<ll> v(ds.divisors().begin(), ds.divisors().end());\n\
    \        std::sort(v.begin(), v.end());\n        return v;\n      }() == divisors[n]);\n\
    \n      for (ll m = 0; m <= 100; ++m) {\n        assert_that(ds.contains(m) ==\
    \ (std::find(divisors[n].begin(), divisors[n].end(), m) != divisors[n].end()));\n\
    \        if (ds.contains(m)) {\n          assert_that(*ds.find(m) == m);\n   \
    \     } else {\n          assert_that(ds.find(m) == ds.divisors().end());\n  \
    \      }\n      }\n\n      for (auto it = ds.divisors().begin(); it != ds.divisors().end();\
    \ ++it) {\n        assert_that([&]() {\n          std::vector<ll> v(ds.divisors(it).begin(),\
    \ ds.divisors(it).end());\n          std::sort(v.begin(), v.end());\n        \
    \  return v;\n        }() == divisors[*it]);\n        assert_that([&]() {\n  \
    \        std::vector<ll> v(std::make_reverse_iterator(ds.divisors(it).end()),\
    \ std::make_reverse_iterator(ds.divisors(it).begin()));\n          std::sort(v.begin(),\
    \ v.end());\n          return v;\n        }() == divisors[*it]);\n      }\n  \
    \  }\n  }\n\n  {\n    const ll n = 897612484786617600;\n    const auto divisors\
    \ = tools::divisors(n);\n\n    tools::divisors_of_divisor<ll> ds(n);\n\n    assert_that([&]()\
    \ {\n      std::vector<ll> v(ds.divisors().begin(), ds.divisors().end());\n  \
    \    std::sort(v.begin(), v.end());\n      return v;\n    }() == divisors);\n\n\
    \    for (auto it = ds.divisors().begin(); it != ds.divisors().end(); ++it) {\n\
    \      assert_that(std::all_of(ds.divisors(it).begin(), ds.divisors(it).end(),\
    \ [&](const auto d) { return *it % d == 0; }));\n      assert_that(std::all_of(std::make_reverse_iterator(ds.divisors(it).end()),\
    \ std::make_reverse_iterator(ds.divisors(it).begin()), [&](const auto d) { return\
    \ *it % d == 0; }));\n    }\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <iostream>\n#include <vector>\n#include <algorithm>\n#include <iterator>\n\
    #include \"tools/assert_that.hpp\"\n#include \"tools/divisors_of_divisor.hpp\"\
    \n#include \"tools/divisors.hpp\"\n\nusing ll = long long;\n\nint main() {\n \
    \ std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  {\n  \
    \  std::vector<std::vector<ll>> divisors(101);\n    for (ll n = 1; n <= 100; ++n)\
    \ {\n      divisors[n] = tools::divisors(n);\n    }\n\n    for (ll n = 1; n <=\
    \ 100; ++n) {\n      tools::divisors_of_divisor<ll> ds(n);\n\n      assert_that([&]()\
    \ {\n        std::vector<ll> v(ds.divisors().begin(), ds.divisors().end());\n\
    \        std::sort(v.begin(), v.end());\n        return v;\n      }() == divisors[n]);\n\
    \n      for (ll m = 0; m <= 100; ++m) {\n        assert_that(ds.contains(m) ==\
    \ (std::find(divisors[n].begin(), divisors[n].end(), m) != divisors[n].end()));\n\
    \        if (ds.contains(m)) {\n          assert_that(*ds.find(m) == m);\n   \
    \     } else {\n          assert_that(ds.find(m) == ds.divisors().end());\n  \
    \      }\n      }\n\n      for (auto it = ds.divisors().begin(); it != ds.divisors().end();\
    \ ++it) {\n        assert_that([&]() {\n          std::vector<ll> v(ds.divisors(it).begin(),\
    \ ds.divisors(it).end());\n          std::sort(v.begin(), v.end());\n        \
    \  return v;\n        }() == divisors[*it]);\n        assert_that([&]() {\n  \
    \        std::vector<ll> v(std::make_reverse_iterator(ds.divisors(it).end()),\
    \ std::make_reverse_iterator(ds.divisors(it).begin()));\n          std::sort(v.begin(),\
    \ v.end());\n          return v;\n        }() == divisors[*it]);\n      }\n  \
    \  }\n  }\n\n  {\n    const ll n = 897612484786617600;\n    const auto divisors\
    \ = tools::divisors(n);\n\n    tools::divisors_of_divisor<ll> ds(n);\n\n    assert_that([&]()\
    \ {\n      std::vector<ll> v(ds.divisors().begin(), ds.divisors().end());\n  \
    \    std::sort(v.begin(), v.end());\n      return v;\n    }() == divisors);\n\n\
    \    for (auto it = ds.divisors().begin(); it != ds.divisors().end(); ++it) {\n\
    \      assert_that(std::all_of(ds.divisors(it).begin(), ds.divisors(it).end(),\
    \ [&](const auto d) { return *it % d == 0; }));\n      assert_that(std::all_of(std::make_reverse_iterator(ds.divisors(it).end()),\
    \ std::make_reverse_iterator(ds.divisors(it).begin()), [&](const auto d) { return\
    \ *it % d == 0; }));\n    }\n  }\n\n  std::cout << \"Hello World\" << '\\n';\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/assert_that.hpp
  - tools/divisors_of_divisor.hpp
  - tools/ceil.hpp
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
  - tools/cmp_less.hpp
  - tools/less_by.hpp
  - tools/divisors.hpp
  - tools/run_length.hpp
  isVerificationFile: true
  path: tests/divisors_of_divisor.test.cpp
  requiredBy: []
  timestamp: '2024-12-08 17:34:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/divisors_of_divisor.test.cpp
layout: document
redirect_from:
- /verify/tests/divisors_of_divisor.test.cpp
- /verify/tests/divisors_of_divisor.test.cpp.html
title: tests/divisors_of_divisor.test.cpp
---
