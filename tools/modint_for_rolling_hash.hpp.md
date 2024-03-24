---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/abs.hpp
    title: std::abs(x) extended for my library
  - icon: ':question:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':question:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':question:'
    path: tools/extgcd.hpp
    title: Extended Euclidean algorithm
  - icon: ':question:'
    path: tools/find_cycle.hpp
    title: Floyd's cycle-finding algorithm
  - icon: ':question:'
    path: tools/floor.hpp
    title: $\left\lfloor \frac{x}{y} \right\rfloor$
  - icon: ':question:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  - icon: ':question:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':question:'
    path: tools/pow_mod_cache.hpp
    title: Cache of $b^n \pmod{M}$
  - icon: ':question:'
    path: tools/quo.hpp
    title: Quotient as integer division
  - icon: ':question:'
    path: tools/square.hpp
    title: $x^2$ under a given monoid
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/modint_for_rolling_hash.hpp\"\n\n\n\n#line 1 \"tools/detail/rolling_hash.hpp\"\
    \n\n\n\n#include <cstdint>\n#include <cassert>\n#include <tuple>\n#include <vector>\n\
    #line 1 \"tools/pow.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/pow.hpp\"\
    \n#include <cmath>\n#line 1 \"tools/monoid.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n\nnamespace tools {\n  namespace monoid\
    \ {\n    template <typename M, M E = ::std::numeric_limits<M>::lowest()>\n   \
    \ struct max {\n      using T = M;\n      static T op(const T& lhs, const T& rhs)\
    \ {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n   \
    \     return E;\n      }\n    };\n\n    template <typename M, M E = ::std::numeric_limits<M>::max()>\n\
    \    struct min {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n\n#line 1 \"tools/square.hpp\"\n\n\n\n#line 5 \"tools/square.hpp\"\n\
    \nnamespace tools {\n\n  template <typename M>\n  typename M::T square(const typename\
    \ M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n  T square(const\
    \ T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n  }\n\
    }\n\n\n#line 9 \"tools/pow.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>, typename M::T>\
    \ pow(const typename M::T& base, const E exponent) {\n    assert(exponent >= 0);\n\
    \    return exponent == 0\n      ? M::e()\n      : exponent % 2 == 0\n       \
    \ ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))\n        : M::op(::tools::pow<M>(base,\
    \ exponent - 1), base);\n  }\n\n  template <typename T, typename E>\n  ::std::enable_if_t<::std::is_integral_v<E>,\
    \ T> pow(const T& base, const E exponent) {\n    assert(exponent >= 0);\n    return\
    \ ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);\n  }\n\n  template\
    \ <typename T, typename E>\n  auto pow(const T base, const E exponent) -> ::std::enable_if_t<!::std::is_integral_v<E>,\
    \ decltype(::std::pow(base, exponent))> {\n    return ::std::pow(base, exponent);\n\
    \  }\n}\n\n\n#line 1 \"tools/extgcd.hpp\"\n\n\n\n#line 5 \"tools/extgcd.hpp\"\n\
    #include <utility>\n#line 1 \"tools/abs.hpp\"\n\n\n\nnamespace tools {\n  constexpr\
    \ float abs(const float x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr double\
    \ abs(const double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long double\
    \ abs(const long double x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr int\
    \ abs(const int x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long abs(const\
    \ long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr long long abs(const\
    \ long long x) {\n    return x < 0 ? -x : x;\n  }\n  constexpr unsigned int abs(const\
    \ unsigned int x) {\n    return x;\n  }\n  constexpr unsigned long abs(const unsigned\
    \ long x) {\n    return x;\n  }\n  constexpr unsigned long long abs(const unsigned\
    \ long long x) {\n    return x;\n  }\n}\n\n\n#line 9 \"tools/extgcd.hpp\"\n\n\
    namespace tools {\n\n  template <typename T>\n  ::std::tuple<T, T, T> extgcd(T\
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
    }\n\n\n#line 1 \"tools/pow_mod_cache.hpp\"\n\n\n\n#line 5 \"tools/pow_mod_cache.hpp\"\
    \n#include <optional>\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#line 5 \"tools/ssize.hpp\"\
    \n#include <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr\
    \ auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 1 \"tools/find_cycle.hpp\"\n\n\n\n\
    #line 5 \"tools/find_cycle.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T, typename F>\n  ::std::pair<long long, long long> find_cycle(const T& seed,\
    \ const F& f) {\n    auto i = 1LL;\n    auto j = 2LL;\n    T x = f(seed);\n  \
    \  T y = f(f(seed));\n    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));\n\
    \n    i = 0;\n    x = seed;\n    for (; x != y; ++i, ++j, x = f(x), y = f(y));\n\
    \n    const auto head = i;\n\n    ++i;\n    j = i + 1;\n    x = f(x);\n    y =\
    \ f(f(y));\n    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));\n\n    const\
    \ auto cycle = j - i;\n\n    return ::std::make_pair(head, cycle);\n  }\n}\n\n\
    \n#line 1 \"tools/mod.hpp\"\n\n\n\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"\
    tools/quo.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N rhs) {\n    using\
    \ T = ::std::common_type_t<M, N>;\n    if (lhs >= M(0)) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= N(0)) {\n        return -((-lhs - T(1)\
    \ + rhs) / rhs);\n      } else {\n        return (-lhs - T(1) + -rhs) / -rhs;\n\
    \      }\n    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const\
    \ M lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\n\n\n\n#line 6 \"\
    tools/floor.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> floor(const M lhs, const N rhs) {\n  \
    \  using T = ::std::common_type_t<M, N>;\n    assert(rhs != N(0));\n    return\
    \ lhs / rhs - T(((lhs > M(0) && rhs < N(0)) || (lhs < M(0) && rhs > N(0))) &&\
    \ lhs % rhs);\n  }\n}\n\n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 6 \"tools/ceil.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M lhs, const N rhs) {\n    using T = ::std::common_type_t<M, N>;\n\
    \    assert(rhs != N(0));\n    return lhs / rhs + T(((lhs > M(0) && rhs > N(0))\
    \ || (lhs < M(0) && rhs < N(0))) && lhs % rhs);\n  }\n}\n\n\n#line 14 \"tools/pow_mod_cache.hpp\"\
    \n\nnamespace tools {\n\n  template <class M>\n  class pow_mod_cache {\n  private:\n\
    \    ::std::vector<M> m_pow;\n    ::std::vector<M> m_cumsum;\n    ::std::vector<M>\
    \ m_inv_pow;\n    ::std::vector<M> m_inv_cumsum;\n    ::std::optional<::std::pair<long\
    \ long, long long>> m_period;\n\n  public:\n    pow_mod_cache() = default;\n \
    \   pow_mod_cache(const ::tools::pow_mod_cache<M>&) = default;\n    pow_mod_cache(::tools::pow_mod_cache<M>&&)\
    \ = default;\n    ~pow_mod_cache() = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(const ::tools::pow_mod_cache<M>&) = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(::tools::pow_mod_cache<M>&&) = default;\n\n    M operator[](const\
    \ long long n) {\n      if (!this->m_period) {\n        if (::std::max<long long>(::tools::ssize(this->m_pow)\
    \ - 1, n) - ::std::min<long long>(n, -(::tools::ssize(this->m_inv_pow) - 1)) +\
    \ 1 < M::mod() - 1) {\n          if (n >= 0) {\n            const long long size\
    \ = ::tools::ssize(this->m_pow);\n            this->m_pow.resize(::std::max(size,\
    \ n + 1));\n            for (long long i = size; i < ::tools::ssize(this->m_pow);\
    \ ++i) {\n              this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];\n\
    \            }\n            return this->m_pow[n];\n          } else {\n     \
    \       if (this->m_inv_pow.size() == 1) {\n              this->m_inv_pow.push_back(this->m_pow[1].inv());\n\
    \            }\n            const long long size = ::tools::ssize(this->m_inv_pow);\n\
    \            this->m_inv_pow.resize(::std::max(size, -n + 1));\n            for\
    \ (long long i = size; i < ::tools::ssize(this->m_inv_pow); ++i) {\n         \
    \     this->m_inv_pow[i] = this->m_inv_pow[i - 1] * this->m_inv_pow[1];\n    \
    \        }\n            return this->m_inv_pow[-n];\n          }\n        }\n\n\
    \        this->m_period = ::std::make_optional(::tools::find_cycle(this->m_pow[0],\
    \ [&](const M& prev) { return prev * this->m_pow[1]; }));\n        const long\
    \ long size = ::tools::ssize(this->m_pow);\n        this->m_pow.resize(this->m_period->first\
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
    \ n) - ::tools::ceil(l, n));\n      }\n    }\n\n    explicit pow_mod_cache(const\
    \ M& base) : m_pow({M(1), base}), m_cumsum({M(0)}), m_inv_pow({M(1)}), m_inv_cumsum({M(0)})\
    \ {\n    }\n    explicit pow_mod_cache(const long long base) : pow_mod_cache(M(base))\
    \ {\n    }\n  };\n}\n\n\n#line 1 \"tools/now.hpp\"\n\n\n\n#include <chrono>\n\n\
    namespace tools {\n  inline long long now() {\n    return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \  }\n}\n\n\n#line 12 \"tools/detail/rolling_hash.hpp\"\n\nnamespace tools {\n\
    \  class rolling_hash;\n\n  class modint_for_rolling_hash {\n  private:\n    static\
    \ constexpr ::std::uint64_t MASK30 = (::std::uint64_t(1) << 30) - 1;\n    static\
    \ constexpr ::std::uint64_t MASK31 = (::std::uint64_t(1) << 31) - 1;\n    static\
    \ constexpr ::std::uint64_t MOD = (::std::uint64_t(1) << 61) - 1;\n    static\
    \ constexpr ::std::uint64_t MASK61 = MOD;\n    static constexpr ::std::uint64_t\
    \ POSITIVIZER = MOD * 4;\n\n    ::std::uint64_t m_val;\n\n    modint_for_rolling_hash(const\
    \ ::std::uint64_t x, int) : m_val(x) {\n    }\n\n    static ::std::uint64_t mul(const\
    \ ::std::uint64_t a, const ::std::uint64_t b) {\n      assert(a < MOD);\n    \
    \  assert(b < MOD);\n      const ::std::uint64_t au = a >> 31;\n      const ::std::uint64_t\
    \ ad = a & MASK31;\n      const ::std::uint64_t bu = b >> 31;\n      const ::std::uint64_t\
    \ bd = b & MASK31;\n      const ::std::uint64_t mid = ad * bu + au * bd;\n   \
    \   const ::std::uint64_t midu = mid >> 30;\n      const ::std::uint64_t midd\
    \ = mid & MASK30;\n      return au * bu * 2 + midu + (midd << 31) + ad * bd;\n\
    \    }\n    static ::std::uint64_t calc_mod(const ::std::uint64_t x) {\n     \
    \ const ::std::uint64_t xu = x >> 61;\n      const ::std::uint64_t xd = x & MASK61;\n\
    \      ::std::uint64_t res = xu + xd;\n      if (res >= MOD) res -= MOD;\n   \
    \   return res;\n    }\n\n  public:\n    modint_for_rolling_hash() = default;\n\
    \    modint_for_rolling_hash(const ::tools::modint_for_rolling_hash&) = default;\n\
    \    modint_for_rolling_hash(::tools::modint_for_rolling_hash&&) = default;\n\
    \    ~modint_for_rolling_hash() = default;\n    ::tools::modint_for_rolling_hash&\
    \ operator=(const ::tools::modint_for_rolling_hash&) = default;\n    ::tools::modint_for_rolling_hash&\
    \ operator=(::tools::modint_for_rolling_hash&&) = default;\n\n    explicit modint_for_rolling_hash(const\
    \ ::std::uint64_t x) : m_val(calc_mod(x)) {\n    }\n\n    ::tools::modint_for_rolling_hash\
    \ pow(const long long n) const {\n      return ::tools::pow(*this, n);\n    }\n\
    \    ::tools::modint_for_rolling_hash inv() const {\n      assert(this->m_val\
    \ != 0);\n      return ::tools::modint_for_rolling_hash(::std::get<0>(::tools::extgcd(this->m_val,\
    \ MOD)));\n    }\n\n    ::tools::modint_for_rolling_hash operator+() const {\n\
    \      return *this;\n    }\n    ::tools::modint_for_rolling_hash operator-()\
    \ const {\n      return ::tools::modint_for_rolling_hash(POSITIVIZER - this->m_val);\n\
    \    }\n    friend ::tools::modint_for_rolling_hash operator+(const ::tools::modint_for_rolling_hash&\
    \ lhs, const ::tools::modint_for_rolling_hash& rhs) {\n      return ::tools::modint_for_rolling_hash(lhs.m_val\
    \ + rhs.m_val);\n    }\n    ::tools::modint_for_rolling_hash& operator+=(const\
    \ ::tools::modint_for_rolling_hash& other) {\n      this->m_val = calc_mod(this->m_val\
    \ + other.m_val);\n      return *this;\n    }\n    friend ::tools::modint_for_rolling_hash\
    \ operator-(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(lhs.m_val + POSITIVIZER\
    \ - rhs.m_val);\n    }\n    ::tools::modint_for_rolling_hash& operator-=(const\
    \ ::tools::modint_for_rolling_hash& other) {\n      this->m_val = calc_mod(this->m_val\
    \ + POSITIVIZER - other.m_val);\n      return *this;\n    }\n    friend ::tools::modint_for_rolling_hash\
    \ operator*(const ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(mul(lhs.m_val, rhs.m_val));\n\
    \    }\n    ::tools::modint_for_rolling_hash& operator*=(const ::tools::modint_for_rolling_hash&\
    \ other) {\n      this->m_val = calc_mod(mul(this->m_val, other.m_val));\n   \
    \   return *this;\n    }\n    friend ::tools::modint_for_rolling_hash operator/(const\
    \ ::tools::modint_for_rolling_hash& lhs, const ::tools::modint_for_rolling_hash&\
    \ rhs) {\n      return ::tools::modint_for_rolling_hash(mul(lhs.m_val, rhs.inv().m_val));\n\
    \    }\n    ::tools::modint_for_rolling_hash& operator/=(const ::tools::modint_for_rolling_hash&\
    \ other) {\n      this->m_val = calc_mod(mul(this->m_val, other.inv().m_val));\n\
    \      return *this;\n    }\n    ::tools::modint_for_rolling_hash& operator++()\
    \ {\n      this->m_val = calc_mod(this->m_val + 1);\n      return *this;\n   \
    \ }\n    ::tools::modint_for_rolling_hash operator++(int) {\n      const auto\
    \ result = *this;\n      ++(*this);\n      return result;\n    }\n    ::tools::modint_for_rolling_hash&\
    \ operator--() {\n      this->m_val = calc_mod(this->m_val + POSITIVIZER - 1);\n\
    \      return *this;\n    }\n    ::tools::modint_for_rolling_hash operator--(int)\
    \ {\n      const auto result = *this;\n      --(*this);\n      return result;\n\
    \    }\n\n    friend bool operator==(const ::tools::modint_for_rolling_hash& lhs,\
    \ const ::tools::modint_for_rolling_hash& rhs) {\n      return lhs.m_val == rhs.m_val;\n\
    \    }\n    friend bool operator!=(const ::tools::modint_for_rolling_hash& lhs,\
    \ const ::tools::modint_for_rolling_hash& rhs) {\n      return lhs.m_val != rhs.m_val;\n\
    \    }\n\n    long long val() const {\n      return this->m_val;\n    }\n\n  \
    \  static ::tools::modint_for_rolling_hash raw(const ::std::uint64_t x) {\n  \
    \    return ::tools::modint_for_rolling_hash(x, 0);\n    }\n    static long long\
    \ mod() {\n      return MOD;\n    }\n\n    friend ::tools::rolling_hash;\n  };\n\
    \n  class rolling_hash {\n  private:\n    using mint = ::tools::modint_for_rolling_hash;\n\
    \    inline static ::tools::pow_mod_cache<mint> m_pow_base = ::tools::pow_mod_cache<mint>(::tools::now());\n\
    \    ::std::vector<mint> m_hash;\n\n  public:\n    rolling_hash() = default;\n\
    \    rolling_hash(const ::tools::rolling_hash&) = default;\n    rolling_hash(::tools::rolling_hash&&)\
    \ = default;\n    ~rolling_hash() = default;\n    ::tools::rolling_hash& operator=(const\
    \ ::tools::rolling_hash&) = default;\n    ::tools::rolling_hash& operator=(::tools::rolling_hash&&)\
    \ = default;\n\n    template <typename InputIterator>\n    rolling_hash(InputIterator\
    \ begin, InputIterator end) {\n      this->m_hash.push_back(mint::raw(0));\n \
    \     const auto base = m_pow_base[1].m_val;\n      for (auto it = begin; it !=\
    \ end; ++it) {\n        this->m_hash.emplace_back(mint::mul(this->m_hash.back().m_val,\
    \ base) + *it);\n      }\n      m_pow_base[this->m_hash.size()];\n    }\n\n  \
    \  mint pow_base(const ::std::size_t i) const {\n      return m_pow_base[i];\n\
    \    }\n\n    mint slice(const ::std::size_t l, const ::std::size_t r) const {\n\
    \      assert(l <= r && r <= this->m_hash.size());\n      return mint(this->m_hash[r].m_val\
    \ + mint::POSITIVIZER - mint::mul(this->m_hash[l].m_val, m_pow_base[r - l].m_val));\n\
    \    }\n  };\n}\n\n\n#line 5 \"tools/modint_for_rolling_hash.hpp\"\n\n\n"
  code: '#ifndef TOOLS_MODINT_FOR_ROLLING_HASH_HPP

    #define TOOLS_MODINT_FOR_ROLLING_HASH_HPP


    #include "tools/detail/rolling_hash.hpp"


    #endif

    '
  dependsOn:
  - tools/detail/rolling_hash.hpp
  - tools/pow.hpp
  - tools/monoid.hpp
  - tools/square.hpp
  - tools/extgcd.hpp
  - tools/abs.hpp
  - tools/pow_mod_cache.hpp
  - tools/ssize.hpp
  - tools/find_cycle.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/floor.hpp
  - tools/ceil.hpp
  - tools/now.hpp
  isVerificationFile: false
  path: tools/modint_for_rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/has_mod.test.cpp
documentation_of: tools/modint_for_rolling_hash.hpp
layout: document
title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
---

It is the struct that treats the modular arithmetic on $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$.
It is compatible to `atcoder::static_modint`.

## Constraints
- Same as `atcoder::static_modint`

## Time Complexity
- Same as `atcoder::static_modint`

## License
- CC0

## Author
- anqooqie
