---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/ceil.hpp
    title: $\left\lceil \frac{x}{y} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/detail/ceil_and_floor.hpp
    title: tools/detail/ceil_and_floor.hpp
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
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':warning:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pow_mod_cache.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <optional>\n#include <utility>\n#include <cstdint>\n#include <algorithm>\n#include\
    \ <cassert>\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto\
    \ ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 1 \"tools/find_cycle.hpp\"\n\n\n\n\
    #line 6 \"tools/find_cycle.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T, typename F>\n  ::std::pair<::std::int_fast64_t, ::std::int_fast64_t> find_cycle(const\
    \ T& seed, const F& f) {\n    ::std::int_fast64_t i = 1;\n    ::std::int_fast64_t\
    \ j = 2;\n    T x = f(seed);\n    T y = f(f(seed));\n    for (; x != y; ++i, j\
    \ += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x = seed;\n    for (; x !=\
    \ y; ++i, ++j, x = f(x), y = f(y));\n\n    const ::std::int_fast64_t head = i;\n\
    \n    ++i;\n    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n    for (; x != y;\
    \ ++i, j += 2, x = f(x), y = f(f(y)));\n\n    const ::std::int_fast64_t cycle\
    \ = j - i;\n\n    return ::std::make_pair(head, cycle);\n  }\n}\n\n\n#line 1 \"\
    tools/mod.hpp\"\n\n\n\n#line 1 \"tools/quo.hpp\"\n\n\n\n#line 5 \"tools/quo.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> quo(const M lhs, const N rhs) {\n    if (lhs >= 0) {\n      return lhs /\
    \ rhs;\n    } else {\n      if (rhs >= 0) {\n        return -((-lhs - 1 + rhs)\
    \ / rhs);\n      } else {\n        return (-lhs - 1 + -rhs) / -rhs;\n      }\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/mod.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> mod(const M\
    \ lhs, const N rhs) {\n    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>)\
    \ {\n      return lhs % rhs;\n    } else {\n      return lhs - ::tools::quo(lhs,\
    \ rhs) * rhs;\n    }\n  }\n}\n\n\n#line 1 \"tools/floor.hpp\"\n\n\n\n#line 1 \"\
    tools/detail/ceil_and_floor.hpp\"\n\n\n\n#line 5 \"tools/detail/ceil_and_floor.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> floor(const M& lhs, const N& rhs);\n\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs);\n  \n\
    \  template <typename M, typename N>\n  constexpr ::std::common_type_t<M, N> floor(const\
    \ M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >= 0 ?\n        lhs\
    \ / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::ceil(-lhs, rhs) :\n\
    \      lhs >= 0 && rhs < 0 ?\n        -::tools::ceil(lhs, -rhs) :\n        ::tools::floor(-lhs,\
    \ -rhs);\n  }\n  \n  template <typename M, typename N>\n  constexpr ::std::common_type_t<M,\
    \ N> ceil(const M& lhs, const N& rhs) {\n    return\n      lhs >= 0 && rhs >=\
    \ 0 ?\n        (lhs - 1 + rhs) / rhs :\n      lhs < 0 && rhs >= 0 ?\n        -::tools::floor(-lhs,\
    \ rhs) :\n      lhs >= 0 && rhs < 0 ?\n        -::tools::floor(lhs, -rhs) :\n\
    \        ::tools::ceil(-lhs, -rhs);\n  }\n}\n\n\n#line 5 \"tools/floor.hpp\"\n\
    \n\n#line 1 \"tools/ceil.hpp\"\n\n\n\n#line 5 \"tools/ceil.hpp\"\n\n\n#line 15\
    \ \"tools/pow_mod_cache.hpp\"\n\nnamespace tools {\n\n  template <class M>\n \
    \ class pow_mod_cache {\n  private:\n    ::std::vector<M> m_pow;\n    ::std::vector<M>\
    \ m_cumsum;\n    ::std::optional<::std::pair<::std::int_fast64_t, ::std::int_fast64_t>>\
    \ m_period;\n\n  public:\n    pow_mod_cache() = default;\n    pow_mod_cache(const\
    \ ::tools::pow_mod_cache<M>&) = default;\n    pow_mod_cache(::tools::pow_mod_cache<M>&&)\
    \ = default;\n    ~pow_mod_cache() = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(const ::tools::pow_mod_cache<M>&) = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(::tools::pow_mod_cache<M>&&) = default;\n\n    M operator[](const\
    \ ::std::int_fast64_t n) {\n      if (!this->m_period) {\n        if (0 <= n &&\
    \ n < M::mod() - 2) {\n          const ::std::int_fast64_t size = ::tools::ssize(this->m_pow);\n\
    \          this->m_pow.resize(::std::max(size, n + 1));\n          for (::std::int_fast64_t\
    \ i = size; i < ::tools::ssize(this->m_pow); ++i) {\n            this->m_pow[i]\
    \ = this->m_pow[i - 1] * this->m_pow[1];\n          }\n          return this->m_pow[n];\n\
    \        }\n\n        this->m_period = ::std::make_optional(::tools::find_cycle(this->m_pow[0],\
    \ [&](const M& prev) { return prev * this->m_pow[1]; }));\n        const ::std::int_fast64_t\
    \ size = ::tools::ssize(this->m_pow);\n        this->m_pow.resize(this->m_period->first\
    \ + this->m_period->second);\n        for (::std::int_fast64_t i = size; i < ::tools::ssize(this->m_pow);\
    \ ++i) {\n          this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];\n  \
    \      }\n      }\n\n      if (this->m_period->first == 0) {\n        return this->m_pow[::tools::mod(n,\
    \ this->m_period->second)];\n      } else {\n        assert(n >= 0);\n       \
    \ if (n < this->m_period->first + this->m_period->second) {\n          return\
    \ this->m_pow[n];\n        } else {\n          return this->m_pow[(n - this->m_period->first)\
    \ % this->m_period->second + this->m_period->first];\n        }\n      }\n   \
    \ }\n\n    M sum(const ::std::int_fast64_t l, const ::std::int_fast64_t r) {\n\
    \      if (l >= r) return M::raw(0);\n\n      (*this)[r - 1];\n      (*this)[l];\n\
    \n      const ::std::int_fast64_t size = ::tools::ssize(this->m_cumsum);\n   \
    \   this->m_cumsum.resize(this->m_pow.size() + 1);\n      for (::std::int_fast64_t\
    \ i = size; i < ::tools::ssize(this->m_cumsum); ++i) {\n        this->m_cumsum[i]\
    \ = this->m_cumsum[i - 1] + this->m_pow[i - 1];\n      }\n\n      static const\
    \ auto cumsum = [&](const ::std::int_fast64_t ll, const ::std::int_fast64_t rr)\
    \ {\n        return this->m_cumsum[rr] - this->m_cumsum[ll];\n      };\n\n   \
    \   if (!this->m_period) {\n        return cumsum(l, r);\n      }\n\n      if\
    \ (l >= 0) {\n        static const auto f = [&](const ::std::int_fast64_t x) {\n\
    \          if (x <= this->m_period->first + this->m_period->second) {\n      \
    \      return cumsum(0, x);\n          } else {\n            return cumsum(0,\
    \ this->m_period->first) +\n              cumsum(this->m_period->first, this->m_period->first\
    \ + this->m_period->second) * ((x - this->m_period->first) / this->m_period->second)\
    \ +\n              cumsum(this->m_period->first, (x - this->m_period->first) %\
    \ this->m_period->second + this->m_period->first);\n          }\n        };\n\
    \        return f(r) - f(l);\n      } else {\n        const auto& n = this->m_period->second;\n\
    \        return cumsum(::tools::mod(l, n), n) + cumsum(0, ::tools::mod(r, n))\
    \ + cumsum(0, n) * M(::tools::floor(r, n) - ::tools::ceil(l, n));\n      }\n \
    \   }\n\n    explicit pow_mod_cache(const M& base) : m_pow({M(1), base}), m_cumsum({M(0)})\
    \ {\n    }\n    explicit pow_mod_cache(const ::std::int_fast64_t base) : pow_mod_cache(M(base))\
    \ {\n    }\n    pow_mod_cache(const M& base, const ::std::int_fast64_t max) :\
    \ pow_mod_cache(base) {\n      assert(max >= 0);\n      (*this)[max];\n    }\n\
    \    pow_mod_cache(const ::std::int_fast64_t base, const ::std::int_fast64_t max)\
    \ : pow_mod_cache(M(base), max) {\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_POW_MOD_CACHE_HPP\n#define TOOLS_POW_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <optional>\n#include <utility>\n#include <cstdint>\n#include\
    \ <algorithm>\n#include <cassert>\n#include \"tools/ssize.hpp\"\n#include \"tools/find_cycle.hpp\"\
    \n#include \"tools/mod.hpp\"\n#include \"tools/floor.hpp\"\n#include \"tools/ceil.hpp\"\
    \n\nnamespace tools {\n\n  template <class M>\n  class pow_mod_cache {\n  private:\n\
    \    ::std::vector<M> m_pow;\n    ::std::vector<M> m_cumsum;\n    ::std::optional<::std::pair<::std::int_fast64_t,\
    \ ::std::int_fast64_t>> m_period;\n\n  public:\n    pow_mod_cache() = default;\n\
    \    pow_mod_cache(const ::tools::pow_mod_cache<M>&) = default;\n    pow_mod_cache(::tools::pow_mod_cache<M>&&)\
    \ = default;\n    ~pow_mod_cache() = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(const ::tools::pow_mod_cache<M>&) = default;\n    ::tools::pow_mod_cache<M>&\
    \ operator=(::tools::pow_mod_cache<M>&&) = default;\n\n    M operator[](const\
    \ ::std::int_fast64_t n) {\n      if (!this->m_period) {\n        if (0 <= n &&\
    \ n < M::mod() - 2) {\n          const ::std::int_fast64_t size = ::tools::ssize(this->m_pow);\n\
    \          this->m_pow.resize(::std::max(size, n + 1));\n          for (::std::int_fast64_t\
    \ i = size; i < ::tools::ssize(this->m_pow); ++i) {\n            this->m_pow[i]\
    \ = this->m_pow[i - 1] * this->m_pow[1];\n          }\n          return this->m_pow[n];\n\
    \        }\n\n        this->m_period = ::std::make_optional(::tools::find_cycle(this->m_pow[0],\
    \ [&](const M& prev) { return prev * this->m_pow[1]; }));\n        const ::std::int_fast64_t\
    \ size = ::tools::ssize(this->m_pow);\n        this->m_pow.resize(this->m_period->first\
    \ + this->m_period->second);\n        for (::std::int_fast64_t i = size; i < ::tools::ssize(this->m_pow);\
    \ ++i) {\n          this->m_pow[i] = this->m_pow[i - 1] * this->m_pow[1];\n  \
    \      }\n      }\n\n      if (this->m_period->first == 0) {\n        return this->m_pow[::tools::mod(n,\
    \ this->m_period->second)];\n      } else {\n        assert(n >= 0);\n       \
    \ if (n < this->m_period->first + this->m_period->second) {\n          return\
    \ this->m_pow[n];\n        } else {\n          return this->m_pow[(n - this->m_period->first)\
    \ % this->m_period->second + this->m_period->first];\n        }\n      }\n   \
    \ }\n\n    M sum(const ::std::int_fast64_t l, const ::std::int_fast64_t r) {\n\
    \      if (l >= r) return M::raw(0);\n\n      (*this)[r - 1];\n      (*this)[l];\n\
    \n      const ::std::int_fast64_t size = ::tools::ssize(this->m_cumsum);\n   \
    \   this->m_cumsum.resize(this->m_pow.size() + 1);\n      for (::std::int_fast64_t\
    \ i = size; i < ::tools::ssize(this->m_cumsum); ++i) {\n        this->m_cumsum[i]\
    \ = this->m_cumsum[i - 1] + this->m_pow[i - 1];\n      }\n\n      static const\
    \ auto cumsum = [&](const ::std::int_fast64_t ll, const ::std::int_fast64_t rr)\
    \ {\n        return this->m_cumsum[rr] - this->m_cumsum[ll];\n      };\n\n   \
    \   if (!this->m_period) {\n        return cumsum(l, r);\n      }\n\n      if\
    \ (l >= 0) {\n        static const auto f = [&](const ::std::int_fast64_t x) {\n\
    \          if (x <= this->m_period->first + this->m_period->second) {\n      \
    \      return cumsum(0, x);\n          } else {\n            return cumsum(0,\
    \ this->m_period->first) +\n              cumsum(this->m_period->first, this->m_period->first\
    \ + this->m_period->second) * ((x - this->m_period->first) / this->m_period->second)\
    \ +\n              cumsum(this->m_period->first, (x - this->m_period->first) %\
    \ this->m_period->second + this->m_period->first);\n          }\n        };\n\
    \        return f(r) - f(l);\n      } else {\n        const auto& n = this->m_period->second;\n\
    \        return cumsum(::tools::mod(l, n), n) + cumsum(0, ::tools::mod(r, n))\
    \ + cumsum(0, n) * M(::tools::floor(r, n) - ::tools::ceil(l, n));\n      }\n \
    \   }\n\n    explicit pow_mod_cache(const M& base) : m_pow({M(1), base}), m_cumsum({M(0)})\
    \ {\n    }\n    explicit pow_mod_cache(const ::std::int_fast64_t base) : pow_mod_cache(M(base))\
    \ {\n    }\n    pow_mod_cache(const M& base, const ::std::int_fast64_t max) :\
    \ pow_mod_cache(base) {\n      assert(max >= 0);\n      (*this)[max];\n    }\n\
    \    pow_mod_cache(const ::std::int_fast64_t base, const ::std::int_fast64_t max)\
    \ : pow_mod_cache(M(base), max) {\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ssize.hpp
  - tools/find_cycle.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  - tools/floor.hpp
  - tools/detail/ceil_and_floor.hpp
  - tools/ceil.hpp
  isVerificationFile: false
  path: tools/pow_mod_cache.hpp
  requiredBy:
  - tools/rolling_hash.hpp
  - tools/modint_for_rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  timestamp: '2022-05-21 18:45:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/rolling_hash.test.cpp
documentation_of: tools/pow_mod_cache.hpp
layout: document
title: Precompute $b^n \pmod{M}$
---

It returns $b^n \pmod{M}$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) pow_mod_cache<M> cache(std::int_fast64_t b);
(2) pow_mod_cache<M> cache(M b);
(3) pow_mod_cache<M> cache(std::int_fast64_t b, std::int_fast64_t N);
(4) pow_mod_cache<M> cache(M b, std::int_fast64_t N);
```

- (1), (2)
    - It creates an empty cache to store $b^n \pmod{M}$.
- (3), (4)
    - It precomputes $b^n \pmod{M}$ for $0 \leq n \leq N$.

### Constraints
- (1), (2)
    - `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- (3), (4)
    - `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
    - $N \geq 0$

### Time Complexity
- (1), (2)
    - $O(1)$
- (3), (4)
    - $O(\min(N, M))$

## operator[]
```cpp
M cache.operator[](std::int_fast64_t n);
```

It returns $b^n \pmod{M}$.

### Constraints
- $\gcd(b, M) = 1 \lor n \geq 0$

### Time Complexity
- $O(\min(n, M))$ worst (if $n \geq 0$)
- $O(M)$ worst (if $n < 0$)
- $O(1)$ amortized

## sum
```cpp
M cache.sum(std::int_fast64_t l, std::int_fast64_t r);
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
- $O(\min(\max(1, r), M))$ worst (if $l \geq 0$)
- $O(M)$ worst (if $l < 0$)
- $O(1)$ amortized
