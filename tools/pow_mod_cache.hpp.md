---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/find_cycle.hpp
    title: Floyd's cycle-finding algorithm
  - icon: ':heavy_check_mark:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':heavy_check_mark:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bell.hpp
    title: Bell numbers
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/large_fact_mod_cache.hpp
    title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':heavy_check_mark:'
    path: tools/polynomial_interpolation.hpp
    title: Polynomial interpolation
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
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
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
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
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
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
  bundledCode: "#line 1 \"tools/pow_mod_cache.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <optional>\n#include <utility>\n#include <type_traits>\n#include <cstddef>\n\
    #include <algorithm>\n#include <cassert>\n#line 1 \"tools/ssize.hpp\"\n\n\n\n\
    #line 6 \"tools/ssize.hpp\"\n\nnamespace tools {\n\n  template <typename C>\n\
    \  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 1 \"tools/find_cycle.hpp\"\n\n\n\n#line 5 \"tools/find_cycle.hpp\"\n\n\
    namespace tools {\n\n  template <typename T, typename F>\n  ::std::pair<long long,\
    \ long long> find_cycle(const T& seed, const F& f) {\n    auto i = 1LL;\n    auto\
    \ j = 2LL;\n    T x = f(seed);\n    T y = f(f(seed));\n    for (; x != y; ++i,\
    \ j += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x = seed;\n    for (; x !=\
    \ y; ++i, ++j, x = f(x), y = f(y));\n\n    const auto head = i;\n\n    ++i;\n\
    \    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n    for (; x != y; ++i, j +=\
    \ 2, x = f(x), y = f(f(y)));\n\n    const auto cycle = j - i;\n\n    return ::std::make_pair(head,\
    \ cycle);\n  }\n}\n\n\n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 1 \"tools/quo.hpp\"\
    \n\n\n\n#line 5 \"tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> quo(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n\
    \      return lhs / rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return\
    \ -((-lhs - T(1) + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) +\
    \ -rhs) / -rhs;\n      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> mod(const M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M>\
    \ && ::std::is_unsigned_v<N>) {\n      return lhs % rhs;\n    } else {\n     \
    \ return lhs - ::tools::quo(lhs, rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\
    \n\n\n\n#line 6 \"tools/floor.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const M lhs, const\
    \ N rhs) {\n    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n\
    \    return lhs / rhs - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs >\
    \ N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6\
    \ \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {\n\
    \    using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 16 \"tools/pow_mod_cache.hpp\"\n\nnamespace tools\
    \ {\n\n  template <class M>\n  class pow_mod_cache {\n    ::std::vector<M> m_pow;\n\
    \    ::std::vector<M> m_cumsum;\n    ::std::vector<M> m_inv_pow;\n    ::std::vector<M>\
    \ m_inv_cumsum;\n    ::std::optional<::std::pair<long long, long long>> m_period;\n\
    \n  public:\n    pow_mod_cache() = default;\n    explicit pow_mod_cache(const\
    \ M base) : m_pow({M(1), base}), m_cumsum({M::raw(0)}), m_inv_pow({M(1)}), m_inv_cumsum({M::raw(0)})\
    \ {\n      if (base == M(-1)) {\n        if (M::mod() > 2) {\n          this->m_period\
    \ = ::std::make_pair(0LL, 2LL);\n        } else {\n          this->m_period =\
    \ ::std::make_pair(0LL, 1LL);\n          this->m_pow.resize(1);\n        }\n \
    \       this->m_inv_pow.clear();\n        this->m_inv_cumsum.clear();\n      }\n\
    \    }\n    template <typename Z, ::std::enable_if_t<::std::is_integral_v<Z>,\
    \ ::std::nullptr_t> = nullptr>\n    explicit pow_mod_cache(const Z base) : pow_mod_cache(M(base))\
    \ {\n    }\n\n    M operator[](const long long n) {\n      if (!this->m_period)\
    \ {\n        if (::std::max<long long>(::tools::ssize(this->m_pow) - 1, n) - ::std::min<long\
    \ long>(n, -(::tools::ssize(this->m_inv_pow) - 1)) + 1 < M::mod() - 1) {\n   \
    \       if (n >= 0) {\n            const long long size = ::tools::ssize(this->m_pow);\n\
    \            this->m_pow.resize(::std::max(size, n + 1));\n            for (long\
    \ long i = size; i < ::tools::ssize(this->m_pow); ++i) {\n              this->m_pow[i]\
    \ = this->m_pow[i - 1] * this->m_pow[1];\n            }\n            return this->m_pow[n];\n\
    \          } else {\n            if (this->m_inv_pow.size() == 1) {\n        \
    \      this->m_inv_pow.push_back(this->m_pow[1].inv());\n            }\n     \
    \       const long long size = ::tools::ssize(this->m_inv_pow);\n            this->m_inv_pow.resize(::std::max(size,\
    \ -n + 1));\n            for (long long i = size; i < ::tools::ssize(this->m_inv_pow);\
    \ ++i) {\n              this->m_inv_pow[i] = this->m_inv_pow[i - 1] * this->m_inv_pow[1];\n\
    \            }\n            return this->m_inv_pow[-n];\n          }\n       \
    \ }\n\n        this->m_period = ::tools::find_cycle(this->m_pow[0], [&](const\
    \ M& prev) { return prev * this->m_pow[1]; });\n        const long long size =\
    \ ::tools::ssize(this->m_pow);\n        this->m_pow.resize(this->m_period->first\
    \ + this->m_period->second);\n        for (long long i = size; i < ::tools::ssize(this->m_pow);\
    \ ++i) {\n          this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];\n  \
    \      }\n        this->m_inv_pow.clear();\n        this->m_inv_cumsum.clear();\n\
    \      }\n\n      if (this->m_period->first == 0) {\n        return this->m_pow[::tools::mod(n,\
    \ this->m_period->second)];\n      } else {\n        assert(n >= 0);\n       \
    \ if (n < this->m_period->first + this->m_period->second) {\n          return\
    \ this->m_pow[n];\n        } else {\n          return this->m_pow[(n - this->m_period->first)\
    \ % this->m_period->second + this->m_period->first];\n        }\n      }\n   \
    \ }\n\n    M sum(const long long l, const long long r) {\n      if (l >= r) return\
    \ M::raw(0);\n\n      (*this)[r - 1];\n      (*this)[l];\n\n      {\n        const\
    \ long long size = ::tools::ssize(this->m_cumsum);\n        this->m_cumsum.resize(this->m_pow.size()\
    \ + 1);\n        for (long long i = size; i < ::tools::ssize(this->m_cumsum);\
    \ ++i) {\n          this->m_cumsum[i] = this->m_cumsum[i - 1] + this->m_pow[i\
    \ - 1];\n        }\n      }\n\n      if (!this->m_period) {\n        const long\
    \ long size = ::tools::ssize(this->m_inv_cumsum);\n        this->m_inv_cumsum.resize(this->m_inv_pow.size()\
    \ + 1);\n        for (long long i = size; i < ::tools::ssize(this->m_inv_cumsum);\
    \ ++i) {\n          this->m_inv_cumsum[i] = this->m_inv_cumsum[i - 1] + this->m_pow[i\
    \ - 1];\n        }\n\n        if (l >= 0) {\n          return this->m_cumsum[r]\
    \ - this->m_cumsum[l];\n        } else if (r <= 0) {\n          return this->m_inv_cumsum[-l]\
    \ - this->m_inv_cumsum[-r];\n        } else {\n          return (this->m_inv_cumsum[-l]\
    \ - this->m_inv_cumsum[1]) + (this->m_cumsum[r] - this->m_cumsum[0]);\n      \
    \  }\n      }\n\n      static const auto cumsum = [&](const long long ll, const\
    \ long long rr) {\n        return this->m_cumsum[rr] - this->m_cumsum[ll];\n \
    \     };\n\n      if (l >= 0) {\n        static const auto f = [&](const long\
    \ long x) {\n          if (x <= this->m_period->first + this->m_period->second)\
    \ {\n            return cumsum(0, x);\n          } else {\n            return\
    \ cumsum(0, this->m_period->first) +\n              cumsum(this->m_period->first,\
    \ this->m_period->first + this->m_period->second) * ((x - this->m_period->first)\
    \ / this->m_period->second) +\n              cumsum(this->m_period->first, (x\
    \ - this->m_period->first) % this->m_period->second + this->m_period->first);\n\
    \          }\n        };\n        return f(r) - f(l);\n      } else {\n      \
    \  const auto& n = this->m_period->second;\n        return cumsum(::tools::mod(l,\
    \ n), n) + cumsum(0, ::tools::mod(r, n)) + cumsum(0, n) * M(::tools::floor(r,\
    \ n) - ::tools::ceil(l, n));\n      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_POW_MOD_CACHE_HPP\n#define TOOLS_POW_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <optional>\n#include <utility>\n#include <type_traits>\n\
    #include <cstddef>\n#include <algorithm>\n#include <cassert>\n#include \"tools/ssize.hpp\"\
    \n#include \"tools/find_cycle.hpp\"\n#include \"tools/mod.hpp\"\n#include \"tools/floor.hpp\"\
    \n#include \"tools/ceil.hpp\"\n\nnamespace tools {\n\n  template <class M>\n \
    \ class pow_mod_cache {\n    ::std::vector<M> m_pow;\n    ::std::vector<M> m_cumsum;\n\
    \    ::std::vector<M> m_inv_pow;\n    ::std::vector<M> m_inv_cumsum;\n    ::std::optional<::std::pair<long\
    \ long, long long>> m_period;\n\n  public:\n    pow_mod_cache() = default;\n \
    \   explicit pow_mod_cache(const M base) : m_pow({M(1), base}), m_cumsum({M::raw(0)}),\
    \ m_inv_pow({M(1)}), m_inv_cumsum({M::raw(0)}) {\n      if (base == M(-1)) {\n\
    \        if (M::mod() > 2) {\n          this->m_period = ::std::make_pair(0LL,\
    \ 2LL);\n        } else {\n          this->m_period = ::std::make_pair(0LL, 1LL);\n\
    \          this->m_pow.resize(1);\n        }\n        this->m_inv_pow.clear();\n\
    \        this->m_inv_cumsum.clear();\n      }\n    }\n    template <typename Z,\
    \ ::std::enable_if_t<::std::is_integral_v<Z>, ::std::nullptr_t> = nullptr>\n \
    \   explicit pow_mod_cache(const Z base) : pow_mod_cache(M(base)) {\n    }\n\n\
    \    M operator[](const long long n) {\n      if (!this->m_period) {\n       \
    \ if (::std::max<long long>(::tools::ssize(this->m_pow) - 1, n) - ::std::min<long\
    \ long>(n, -(::tools::ssize(this->m_inv_pow) - 1)) + 1 < M::mod() - 1) {\n   \
    \       if (n >= 0) {\n            const long long size = ::tools::ssize(this->m_pow);\n\
    \            this->m_pow.resize(::std::max(size, n + 1));\n            for (long\
    \ long i = size; i < ::tools::ssize(this->m_pow); ++i) {\n              this->m_pow[i]\
    \ = this->m_pow[i - 1] * this->m_pow[1];\n            }\n            return this->m_pow[n];\n\
    \          } else {\n            if (this->m_inv_pow.size() == 1) {\n        \
    \      this->m_inv_pow.push_back(this->m_pow[1].inv());\n            }\n     \
    \       const long long size = ::tools::ssize(this->m_inv_pow);\n            this->m_inv_pow.resize(::std::max(size,\
    \ -n + 1));\n            for (long long i = size; i < ::tools::ssize(this->m_inv_pow);\
    \ ++i) {\n              this->m_inv_pow[i] = this->m_inv_pow[i - 1] * this->m_inv_pow[1];\n\
    \            }\n            return this->m_inv_pow[-n];\n          }\n       \
    \ }\n\n        this->m_period = ::tools::find_cycle(this->m_pow[0], [&](const\
    \ M& prev) { return prev * this->m_pow[1]; });\n        const long long size =\
    \ ::tools::ssize(this->m_pow);\n        this->m_pow.resize(this->m_period->first\
    \ + this->m_period->second);\n        for (long long i = size; i < ::tools::ssize(this->m_pow);\
    \ ++i) {\n          this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];\n  \
    \      }\n        this->m_inv_pow.clear();\n        this->m_inv_cumsum.clear();\n\
    \      }\n\n      if (this->m_period->first == 0) {\n        return this->m_pow[::tools::mod(n,\
    \ this->m_period->second)];\n      } else {\n        assert(n >= 0);\n       \
    \ if (n < this->m_period->first + this->m_period->second) {\n          return\
    \ this->m_pow[n];\n        } else {\n          return this->m_pow[(n - this->m_period->first)\
    \ % this->m_period->second + this->m_period->first];\n        }\n      }\n   \
    \ }\n\n    M sum(const long long l, const long long r) {\n      if (l >= r) return\
    \ M::raw(0);\n\n      (*this)[r - 1];\n      (*this)[l];\n\n      {\n        const\
    \ long long size = ::tools::ssize(this->m_cumsum);\n        this->m_cumsum.resize(this->m_pow.size()\
    \ + 1);\n        for (long long i = size; i < ::tools::ssize(this->m_cumsum);\
    \ ++i) {\n          this->m_cumsum[i] = this->m_cumsum[i - 1] + this->m_pow[i\
    \ - 1];\n        }\n      }\n\n      if (!this->m_period) {\n        const long\
    \ long size = ::tools::ssize(this->m_inv_cumsum);\n        this->m_inv_cumsum.resize(this->m_inv_pow.size()\
    \ + 1);\n        for (long long i = size; i < ::tools::ssize(this->m_inv_cumsum);\
    \ ++i) {\n          this->m_inv_cumsum[i] = this->m_inv_cumsum[i - 1] + this->m_pow[i\
    \ - 1];\n        }\n\n        if (l >= 0) {\n          return this->m_cumsum[r]\
    \ - this->m_cumsum[l];\n        } else if (r <= 0) {\n          return this->m_inv_cumsum[-l]\
    \ - this->m_inv_cumsum[-r];\n        } else {\n          return (this->m_inv_cumsum[-l]\
    \ - this->m_inv_cumsum[1]) + (this->m_cumsum[r] - this->m_cumsum[0]);\n      \
    \  }\n      }\n\n      static const auto cumsum = [&](const long long ll, const\
    \ long long rr) {\n        return this->m_cumsum[rr] - this->m_cumsum[ll];\n \
    \     };\n\n      if (l >= 0) {\n        static const auto f = [&](const long\
    \ long x) {\n          if (x <= this->m_period->first + this->m_period->second)\
    \ {\n            return cumsum(0, x);\n          } else {\n            return\
    \ cumsum(0, this->m_period->first) +\n              cumsum(this->m_period->first,\
    \ this->m_period->first + this->m_period->second) * ((x - this->m_period->first)\
    \ / this->m_period->second) +\n              cumsum(this->m_period->first, (x\
    \ - this->m_period->first) % this->m_period->second + this->m_period->first);\n\
    \          }\n        };\n        return f(r) - f(l);\n      } else {\n      \
    \  const auto& n = this->m_period->second;\n        return cumsum(::tools::mod(l,\
    \ n), n) + cumsum(0, ::tools::mod(r, n)) + cumsum(0, n) * M(::tools::floor(r,\
    \ n) - ::tools::ceil(l, n));\n      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ssize.hpp
  - tools/find_cycle.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/floor.hpp
  - tools/ceil.hpp
  isVerificationFile: false
  path: tools/pow_mod_cache.hpp
  requiredBy:
  - tools/detail/rolling_hash.hpp
  - tools/bostan_mori.hpp
  - tools/bell.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/stirling_1st.hpp
  - tools/polynomial_interpolation.hpp
  - tools/twelvefold_way.hpp
  - tools/polynomial.hpp
  - tools/stirling_2nd.hpp
  - tools/rolling_hash.hpp
  - tools/berlekamp_massey.hpp
  - tools/large_fact_mod_cache.hpp
  timestamp: '2024-04-13 13:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_unlabeled_box_at_most_1.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_unrestricted.test.cpp
  - tests/twelvefold_way/unlabeled_ball_labeled_box_at_least_1.test.cpp
  - tests/twelvefold_way/labeled_ball_unlabeled_box_unrestricted.test.cpp
  - tests/polynomial_product.test.cpp
  - tests/has_mod.test.cpp
  - tests/stirling_2nd/all.test.cpp
  - tests/stirling_2nd/consistent.test.cpp
  - tests/stirling_2nd/fixed_k.test.cpp
  - tests/stirling_2nd/fixed_n.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/stirling_1st/consistent.test.cpp
  - tests/stirling_1st/fixed_k.test.cpp
  - tests/stirling_1st/fixed_n.test.cpp
  - tests/polynomial_interpolation.test.cpp
  - tests/bell/all.test.cpp
  - tests/bell/consistent.test.cpp
  - tests/bell/fixed_n.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/large_fact_mod_cache/fact.test.cpp
  - tests/large_fact_mod_cache/binomial.test.cpp
  - tests/polynomial/taylor_shift.test.cpp
  - tests/polynomial/multipoint_evaluation_other_mods.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/polynomial/multidimensional.test.cpp
  - tests/polynomial/multipoint_evaluation.test.cpp
  - tests/polynomial/naive_division.test.cpp
documentation_of: tools/pow_mod_cache.hpp
layout: document
title: Cache for $b^n \pmod{M}$
---

It caches $b^n \pmod{M}$ and returns them in $O(1)$ amortized time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
pow_mod_cache<M> cache(M b);

(2)
template <typename Z>
pow_mod_cache<M> cache(Z b);
```

It creates an empty cache to store $b^n \pmod{M}$.

### Constraints
- (1)
    - `<M>` is `atcoder::static_modint`, `atcoder::dynamic_modint` or `tools::modint_for_rolling_hash`
- (2)
    - `<Z>` is an integral type.

### Time Complexity
- $O(1)$

## operator[]
```cpp
M cache.operator[](long long n);
```

It returns $b^n \pmod{M}$.

### Constraints
- $\gcd(b, M) = 1 \lor n \geq 0$

### Time Complexity
- $O(\min(\log M + \|n\|, M))$ worst
- $O(1)$ amortized

## sum
```cpp
M cache.sum(long long l, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
\sum_{i = l}^{r - 1} b^i \pmod{M} & \text{(if $l < r$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $\gcd(b, M) = 1 \lor l \geq 0$

### Time Complexity
- $O(\min(\log M + \max(0, r - l), M))$ worst
- $O(1)$ amortized
