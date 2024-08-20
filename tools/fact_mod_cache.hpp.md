---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
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
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':question:'
    path: tools/uint128_t.hpp
    title: 128 bit unsigned integer
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bell.hpp
    title: Bell numbers
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bernoulli.hpp
    title: Bernoulli numbers $B_k \pmod{P}$ for $0 \leq k \leq n$
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
  - icon: ':heavy_check_mark:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':heavy_check_mark:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':heavy_check_mark:'
    path: tools/sample_point_shift.hpp
    title: Shift of sampling points of polynomial
  - icon: ':heavy_check_mark:'
    path: tools/sparse_fps_pow.hpp
    title: Power of a sparse FPS
  - icon: ':heavy_check_mark:'
    path: tools/stirling_1st.hpp
    title: Signed Stirling numbers of the first kind
  - icon: ':heavy_check_mark:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind
  - icon: ':heavy_check_mark:'
    path: tools/twelvefold_way.hpp
    title: Twelvefold way
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bell/all.test.cpp
    title: tests/bell/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bell/consistent.test.cpp
    title: tests/bell/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bell/fixed_n.test.cpp
    title: tests/bell/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/berlekamp_massey.test.cpp
    title: tests/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bernoulli.test.cpp
    title: tests/bernoulli.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fact_mod_cache.test.cpp
    title: tests/fact_mod_cache.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/binomial.test.cpp
    title: tests/large_fact_mod_cache/binomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/large_fact_mod_cache/fact.test.cpp
    title: tests/large_fact_mod_cache/fact.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multidimensional.test.cpp
    title: tests/polynomial/multidimensional.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multipoint_evaluation.test.cpp
    title: tests/polynomial/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
    title: tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial/taylor_shift.test.cpp
    title: tests/polynomial/taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial_interpolation.test.cpp
    title: tests/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polynomial_product.test.cpp
    title: tests/polynomial_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sample_point_shift.test.cpp
    title: tests/sample_point_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sparse_fps_pow/fraction.test.cpp
    title: tests/sparse_fps_pow/fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/sparse_fps_pow/regular.test.cpp
    title: tests/sparse_fps_pow/regular.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/consistent.test.cpp
    title: tests/stirling_1st/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/fixed_k.test.cpp
    title: tests/stirling_1st/fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_1st/fixed_n.test.cpp
    title: tests/stirling_1st/fixed_n.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/all.test.cpp
    title: tests/stirling_2nd/all.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/consistent.test.cpp
    title: tests/stirling_2nd/consistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/fixed_k.test.cpp
    title: tests/stirling_2nd/fixed_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/stirling_2nd/fixed_n.test.cpp
    title: tests/stirling_2nd/fixed_n.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
    title: tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/fact_mod_cache.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <algorithm>\n#include <cmath>\n#line 1 \"tools/is_prime.hpp\"\
    \n\n\n\n#include <array>\n#line 1 \"tools/prod_mod.hpp\"\n\n\n\n#line 1 \"tools/uint128_t.hpp\"\
    \n\n\n\n#include <iostream>\n#include <string>\n#line 7 \"tools/uint128_t.hpp\"\
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
    \ 1 \"tools/ssize.hpp\"\n\n\n\n#line 6 \"tools/ssize.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 10 \"tools/fact_mod_cache.hpp\"\n\nnamespace tools {\n\n  template <class\
    \ M>\n  class fact_mod_cache {\n    ::std::vector<M> m_inv;\n    ::std::vector<M>\
    \ m_fact;\n    ::std::vector<M> m_fact_inv;\n\n  public:\n    fact_mod_cache()\
    \ : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1), M::raw(1)}), m_fact_inv({M::raw(1),\
    \ M::raw(1)}) {\n      assert(::tools::is_prime(M::mod()));\n    }\n    explicit\
    \ fact_mod_cache(const long long max) : fact_mod_cache() {\n      this->fact(::std::min<long\
    \ long>(max, M::mod() - 1));\n      this->fact_inv(::std::min<long long>(max,\
    \ M::mod() - 1));\n    }\n\n    M inv(const long long n) {\n      assert(n % M::mod()\
    \ != 0);\n      const long long size = ::tools::ssize(this->m_inv);\n      this->m_inv.resize(::std::clamp<long\
    \ long>(::std::abs(n) + 1, size, M::mod()));\n      for (long long i = size; i\
    \ < ::tools::ssize(this->m_inv); ++i) {\n        this->m_inv[i] = -this->m_inv[M::mod()\
    \ % i] * M::raw(M::mod() / i);\n      }\n      M result = this->m_inv[::std::abs(n)\
    \ % M::mod()];\n      if (n < 0) result = -result;\n      return result;\n   \
    \ }\n    M fact(const long long n) {\n      assert(n >= 0);\n      const long\
    \ long size = ::tools::ssize(this->m_fact);\n      this->m_fact.resize(::std::clamp<long\
    \ long>(n + 1, size, M::mod()));\n      for (long long i = size; i < ::tools::ssize(this->m_fact);\
    \ ++i) {\n        this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);\n      }\n\
    \      return n < M::mod() ? this->m_fact[n] : M::raw(0);\n    }\n    M fact_inv(const\
    \ long long n) {\n      assert(0 <= n && n < M::mod());\n      const long long\
    \ size = ::tools::ssize(this->m_fact_inv);\n      this->m_fact_inv.resize(::std::max<long\
    \ long>(size, n + 1));\n      this->inv(this->m_fact_inv.size() - 1);\n      for\
    \ (long long i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {\n        this->m_fact_inv[i]\
    \ = this->m_fact_inv[i - 1] * this->m_inv[i];\n      }\n      return this->m_fact_inv[n];\n\
    \    }\n\n    M binomial(long long n, long long r) {\n      if (r < 0) return\
    \ M::raw(0);\n      if (0 <= n && n < r) return M::raw(0);\n      if (n < 0) return\
    \ M(1 - ((r & 1) << 1)) * this->binomial(-n + r - 1, r);\n\n      this->fact(::std::min<long\
    \ long>(n, M::mod() - 1));\n      this->fact_inv(::std::min<long long>(n, M::mod()\
    \ - 1));\n      const auto c = [&](const long long nn, const long long rr) {\n\
    \        return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn -\
    \ rr] * this->m_fact_inv[rr] : M::raw(0);\n      };\n\n      M result(1);\n  \
    \    while (n > 0 || r > 0) {\n        result *= c(n % M::mod(), r % M::mod());\n\
    \        n /= M::mod();\n        r /= M::mod();\n      }\n\n      return result;\n\
    \    }\n    M combination(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->binomial(n, r);\n   \
    \ }\n    M permutation(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->binomial(n, r) * this->fact(r);\n\
    \    }\n    M combination_with_repetition(const long long n, const long long r)\
    \ {\n      if (n < 0 || r < 0) return M::raw(0);\n      return this->binomial(n\
    \ + r - 1, r);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_FACT_MOD_CACHE_HPP\n#define TOOLS_FACT_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <cassert>\n#include <algorithm>\n#include <cmath>\n#include\
    \ \"tools/is_prime.hpp\"\n#include \"tools/ssize.hpp\"\n\nnamespace tools {\n\n\
    \  template <class M>\n  class fact_mod_cache {\n    ::std::vector<M> m_inv;\n\
    \    ::std::vector<M> m_fact;\n    ::std::vector<M> m_fact_inv;\n\n  public:\n\
    \    fact_mod_cache() : m_inv({M::raw(0), M::raw(1)}), m_fact({M::raw(1), M::raw(1)}),\
    \ m_fact_inv({M::raw(1), M::raw(1)}) {\n      assert(::tools::is_prime(M::mod()));\n\
    \    }\n    explicit fact_mod_cache(const long long max) : fact_mod_cache() {\n\
    \      this->fact(::std::min<long long>(max, M::mod() - 1));\n      this->fact_inv(::std::min<long\
    \ long>(max, M::mod() - 1));\n    }\n\n    M inv(const long long n) {\n      assert(n\
    \ % M::mod() != 0);\n      const long long size = ::tools::ssize(this->m_inv);\n\
    \      this->m_inv.resize(::std::clamp<long long>(::std::abs(n) + 1, size, M::mod()));\n\
    \      for (long long i = size; i < ::tools::ssize(this->m_inv); ++i) {\n    \
    \    this->m_inv[i] = -this->m_inv[M::mod() % i] * M::raw(M::mod() / i);\n   \
    \   }\n      M result = this->m_inv[::std::abs(n) % M::mod()];\n      if (n <\
    \ 0) result = -result;\n      return result;\n    }\n    M fact(const long long\
    \ n) {\n      assert(n >= 0);\n      const long long size = ::tools::ssize(this->m_fact);\n\
    \      this->m_fact.resize(::std::clamp<long long>(n + 1, size, M::mod()));\n\
    \      for (long long i = size; i < ::tools::ssize(this->m_fact); ++i) {\n   \
    \     this->m_fact[i] = this->m_fact[i - 1] * M::raw(i);\n      }\n      return\
    \ n < M::mod() ? this->m_fact[n] : M::raw(0);\n    }\n    M fact_inv(const long\
    \ long n) {\n      assert(0 <= n && n < M::mod());\n      const long long size\
    \ = ::tools::ssize(this->m_fact_inv);\n      this->m_fact_inv.resize(::std::max<long\
    \ long>(size, n + 1));\n      this->inv(this->m_fact_inv.size() - 1);\n      for\
    \ (long long i = size; i < ::tools::ssize(this->m_fact_inv); ++i) {\n        this->m_fact_inv[i]\
    \ = this->m_fact_inv[i - 1] * this->m_inv[i];\n      }\n      return this->m_fact_inv[n];\n\
    \    }\n\n    M binomial(long long n, long long r) {\n      if (r < 0) return\
    \ M::raw(0);\n      if (0 <= n && n < r) return M::raw(0);\n      if (n < 0) return\
    \ M(1 - ((r & 1) << 1)) * this->binomial(-n + r - 1, r);\n\n      this->fact(::std::min<long\
    \ long>(n, M::mod() - 1));\n      this->fact_inv(::std::min<long long>(n, M::mod()\
    \ - 1));\n      const auto c = [&](const long long nn, const long long rr) {\n\
    \        return 0 <= rr && rr <= nn ? this->m_fact[nn] * this->m_fact_inv[nn -\
    \ rr] * this->m_fact_inv[rr] : M::raw(0);\n      };\n\n      M result(1);\n  \
    \    while (n > 0 || r > 0) {\n        result *= c(n % M::mod(), r % M::mod());\n\
    \        n /= M::mod();\n        r /= M::mod();\n      }\n\n      return result;\n\
    \    }\n    M combination(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->binomial(n, r);\n   \
    \ }\n    M permutation(const long long n, const long long r) {\n      if (!(0\
    \ <= r && r <= n)) return M::raw(0);\n      return this->binomial(n, r) * this->fact(r);\n\
    \    }\n    M combination_with_repetition(const long long n, const long long r)\
    \ {\n      if (n < 0 || r < 0) return M::raw(0);\n      return this->binomial(n\
    \ + r - 1, r);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/is_prime.hpp
  - tools/prod_mod.hpp
  - tools/uint128_t.hpp
  - tools/abs.hpp
  - tools/pow_mod.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/ssize.hpp
  isVerificationFile: false
  path: tools/fact_mod_cache.hpp
  requiredBy:
  - tools/sparse_fps_pow.hpp
  - tools/large_fact_mod_cache.hpp
  - tools/berlekamp_massey.hpp
  - tools/bell.hpp
  - tools/sample_point_shift.hpp
  - tools/polynomial.hpp
  - tools/stirling_2nd.hpp
  - tools/bernoulli.hpp
  - tools/bostan_mori.hpp
  - tools/stirling_1st.hpp
  - tools/polynomial_interpolation.hpp
  - tools/twelvefold_way.hpp
  timestamp: '2024-04-29 15:33:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/polynomial_product.test.cpp
  - tests/stirling_1st/fixed_k.test.cpp
  - tests/stirling_1st/consistent.test.cpp
  - tests/stirling_1st/fixed_n.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/fact_mod_cache.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/sample_point_shift.test.cpp
  - tests/large_fact_mod_cache/fact.test.cpp
  - tests/large_fact_mod_cache/binomial.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/stirling_2nd/fixed_k.test.cpp
  - tests/stirling_2nd/consistent.test.cpp
  - tests/stirling_2nd/all.test.cpp
  - tests/stirling_2nd/fixed_n.test.cpp
  - tests/bell/consistent.test.cpp
  - tests/bell/all.test.cpp
  - tests/bell/fixed_n.test.cpp
  - tests/bernoulli.test.cpp
documentation_of: tools/fact_mod_cache.hpp
layout: document
title: Cache for $n^{-1}, n!, n!^{-1} \pmod{P}$
---

It caches $n^{-1}, n!, n!^{-1} \pmod{P}$ and returns them in $O(1)$ amortized time.
It also returns ${}_n \mathrm{C}_r, {}_n \mathrm{P}_r, {}_n \mathrm{H}_r \pmod{P}$ in logarithmic amortized time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) fact_mod_cache<M> cache();
(2) fact_mod_cache<M> cache(long long N);
```

- (1)
    - It creates an empty cache to store $n^{-1}, n!, n!^{-1} \pmod{P}$ where $P$ is `M::mod()`.
- (2)
    - It precomputes $n^{-1}, n!, n!^{-1} \pmod{P}$ for any $n$ such that $0 \leq n \leq N$, where $P$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- `M::mod()` is a prime

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(\min(N, P))$

## inv
```cpp
M cache.inv(long long n);
```

It returns $n^{-1} \pmod{P}$.

### Constraints
- $n \not\equiv 0 \pmod{P}$

### Time Complexity
- $O(\min(\|n\|, P))$ worst
- $O(1)$ amortized

## fact
```cpp
M cache.fact(long long n);
```

It returns $n! \pmod{P}$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(\min(n, P))$ worst
- $O(1)$ amortized

## fact_inv
```cpp
M cache.fact_inv(long long n);
```

It returns $n!^{-1} \pmod{P}$.

### Constraints
- $0 < n < P$

### Time Complexity
- $O(n)$ worst
- $O(1)$ amortized

## binomial
```cpp
M cache.binomial(long long n, long long r);
```

It returns $\dbinom{n}{r} \pmod{P}$.
Note that $\dbinom{-n}{r} = (-1)^r \dbinom{n + r - 1}{r}$.

### Constraints
- None

### Time Complexity
- ($n \geq 0$):
    - $O(\min(n, P) + \log_P(n))$ worst
    - $O(\log_P(n))$ amortized
- ($n < 0$):
    - $O(\min(\|n\| + r, P) + \log_P(\|n\| + r))$ worst
    - $O(\log_P(\|n\| + r))$ amortized

## combination
```cpp
M cache.combination(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{C}_r \pmod{P} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(\min(n, P) + \log_P(n))$ worst
- $O(\log_P(n))$ amortized

## permutation
```cpp
M cache.permutation(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{P}_r \pmod{P} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(\min(n, P) + \log_P(n))$ worst
- $O(\log_P(n))$ amortized

## combination_with_repetition
```cpp
M cache.combination_with_repetition(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{H}_r \pmod{P} & \text{(if $n \geq 0$ and $r \geq 0$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(\min(n + r, P) + \log_P(n + r))$ worst
- $O(\log_P(n + r))$ amortized
