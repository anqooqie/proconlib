---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/find_cycle.hpp
    title: Floyd's cycle-finding algorithm
  - icon: ':heavy_check_mark:'
    path: tools/mod.hpp
    title: Minimum non-negative reminder
  - icon: ':heavy_check_mark:'
    path: tools/quo.hpp
    title: Quotient as integer division
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/rich_pow_mod_cache.hpp\"\n\n\n\n#include <cstdint>\n\
    #include <vector>\n#include <numeric>\n#include <cassert>\n#include <iterator>\n\
    #line 1 \"tools/find_cycle.hpp\"\n\n\n\n#include <utility>\n#line 6 \"tools/find_cycle.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T, typename F>\n  ::std::pair<::std::int_fast64_t,\
    \ ::std::int_fast64_t> find_cycle(const T& seed, const F& f) {\n    ::std::int_fast64_t\
    \ i = 1;\n    ::std::int_fast64_t j = 2;\n    T x = f(seed);\n    T y = f(f(seed));\n\
    \    for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));\n\n    i = 0;\n    x\
    \ = seed;\n    for (; x != y; ++i, ++j, x = f(x), y = f(y));\n\n    const ::std::int_fast64_t\
    \ head = i;\n\n    ++i;\n    j = i + 1;\n    x = f(x);\n    y = f(f(y));\n   \
    \ for (; x != y; ++i, j += 2, x = f(x), y = f(f(y)));\n\n    const ::std::int_fast64_t\
    \ cycle = j - i;\n\n    return ::std::make_pair(head, cycle);\n  }\n}\n\n\n#line\
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
    \    }\n  }\n}\n\n\n#line 11 \"tools/rich_pow_mod_cache.hpp\"\n\nnamespace tools\
    \ {\n\n  template <class M>\n  class rich_pow_mod_cache {\n  private:\n    bool\
    \ m_exists_inv;\n    ::std::int_fast64_t m_head;\n    ::std::int_fast64_t m_cycle;\n\
    \    ::std::vector<M> m_data;\n    ::std::vector<M> m_cumsum;\n\n    M cumsum(const\
    \ ::std::int_fast64_t l, const ::std::int_fast64_t r) const {\n      return this->m_cumsum[r]\
    \ - this->m_cumsum[l];\n    }\n\n  public:\n    rich_pow_mod_cache() = default;\n\
    \    rich_pow_mod_cache(const rich_pow_mod_cache&) = default;\n    rich_pow_mod_cache(rich_pow_mod_cache&&)\
    \ = default;\n    ~rich_pow_mod_cache() = default;\n    rich_pow_mod_cache& operator=(const\
    \ rich_pow_mod_cache&) = default;\n    rich_pow_mod_cache& operator=(rich_pow_mod_cache&&)\
    \ = default;\n\n    explicit rich_pow_mod_cache(const M& base) :\n      m_exists_inv(::std::gcd(base.val(),\
    \ M::mod()) == 1) {\n\n      const auto [head, cycle] = ::tools::find_cycle(M(1),\
    \ [&base](const M& prev) { return prev * base; });\n      this->m_head = head;\n\
    \      this->m_cycle = cycle;\n\n      // if modular multiplicative inverses exist,\
    \ head must be 0 according to Carmichael's theorem\n      assert(!this->m_exists_inv\
    \ || this->m_head == 0);\n\n      this->m_data.reserve(head + cycle);\n      this->m_data.emplace_back(1);\n\
    \      for (::std::int_fast64_t i = 1; i < head + cycle; ++i) {\n        this->m_data.push_back(this->m_data.back()\
    \ * base);\n      }\n      this->m_cumsum.reserve(head + cycle + 1);\n      this->m_cumsum.emplace_back(0);\n\
    \      ::std::partial_sum(this->m_data.begin(), this->m_data.end(), ::std::back_inserter(this->m_cumsum));\n\
    \    }\n\n    explicit rich_pow_mod_cache(const ::std::int_fast64_t base) :\n\
    \      rich_pow_mod_cache(M(base)) {\n    }\n\n    M operator[](const ::std::int_fast64_t\
    \ i) const {\n      if (i >= 0) {\n        if (i < this->m_head + this->m_cycle)\
    \ {\n          return this->m_data[i];\n        } else {\n          return this->m_data[(i\
    \ - this->m_head) % this->m_cycle + this->m_head];\n        }\n      } else {\n\
    \        assert(this->m_exists_inv);\n        return this->m_data[::tools::mod(i,\
    \ this->m_cycle)];\n      }\n    }\n\n    M sum(const ::std::int_fast64_t l, const\
    \ ::std::int_fast64_t r) const {\n      if (l <= r) {\n        if (l >= 0) {\n\
    \          static const auto f = [&](const ::std::int_fast64_t x) {\n        \
    \    if (x <= this->m_head + this->m_cycle) {\n              return this->cumsum(0,\
    \ x);\n            } else {\n              return this->cumsum(0, this->m_head)\
    \ +\n                this->cumsum(this->m_head, this->m_head + this->m_cycle)\
    \ * ((x - this->m_head) / this->m_cycle) +\n                this->cumsum(this->m_head,\
    \ (x - this->m_head) % this->m_cycle + this->m_head);\n            }\n       \
    \   };\n          return f(r) - f(l);\n        } else {\n          assert(this->m_exists_inv);\n\
    \          return (this->cumsum(0, this->m_cycle) * ((r - l) / this->m_cycle)\
    \ + this->cumsum(0, (r - l) % this->m_cycle)) * (*this)[l];\n        }\n     \
    \ } else {\n        return M(0);\n      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_RICH_POW_MOD_CACHE_HPP\n#define TOOLS_RICH_POW_MOD_CACHE_HPP\n\
    \n#include <cstdint>\n#include <vector>\n#include <numeric>\n#include <cassert>\n\
    #include <iterator>\n#include \"tools/find_cycle.hpp\"\n#include \"tools/mod.hpp\"\
    \n\nnamespace tools {\n\n  template <class M>\n  class rich_pow_mod_cache {\n\
    \  private:\n    bool m_exists_inv;\n    ::std::int_fast64_t m_head;\n    ::std::int_fast64_t\
    \ m_cycle;\n    ::std::vector<M> m_data;\n    ::std::vector<M> m_cumsum;\n\n \
    \   M cumsum(const ::std::int_fast64_t l, const ::std::int_fast64_t r) const {\n\
    \      return this->m_cumsum[r] - this->m_cumsum[l];\n    }\n\n  public:\n   \
    \ rich_pow_mod_cache() = default;\n    rich_pow_mod_cache(const rich_pow_mod_cache&)\
    \ = default;\n    rich_pow_mod_cache(rich_pow_mod_cache&&) = default;\n    ~rich_pow_mod_cache()\
    \ = default;\n    rich_pow_mod_cache& operator=(const rich_pow_mod_cache&) = default;\n\
    \    rich_pow_mod_cache& operator=(rich_pow_mod_cache&&) = default;\n\n    explicit\
    \ rich_pow_mod_cache(const M& base) :\n      m_exists_inv(::std::gcd(base.val(),\
    \ M::mod()) == 1) {\n\n      const auto [head, cycle] = ::tools::find_cycle(M(1),\
    \ [&base](const M& prev) { return prev * base; });\n      this->m_head = head;\n\
    \      this->m_cycle = cycle;\n\n      // if modular multiplicative inverses exist,\
    \ head must be 0 according to Carmichael's theorem\n      assert(!this->m_exists_inv\
    \ || this->m_head == 0);\n\n      this->m_data.reserve(head + cycle);\n      this->m_data.emplace_back(1);\n\
    \      for (::std::int_fast64_t i = 1; i < head + cycle; ++i) {\n        this->m_data.push_back(this->m_data.back()\
    \ * base);\n      }\n      this->m_cumsum.reserve(head + cycle + 1);\n      this->m_cumsum.emplace_back(0);\n\
    \      ::std::partial_sum(this->m_data.begin(), this->m_data.end(), ::std::back_inserter(this->m_cumsum));\n\
    \    }\n\n    explicit rich_pow_mod_cache(const ::std::int_fast64_t base) :\n\
    \      rich_pow_mod_cache(M(base)) {\n    }\n\n    M operator[](const ::std::int_fast64_t\
    \ i) const {\n      if (i >= 0) {\n        if (i < this->m_head + this->m_cycle)\
    \ {\n          return this->m_data[i];\n        } else {\n          return this->m_data[(i\
    \ - this->m_head) % this->m_cycle + this->m_head];\n        }\n      } else {\n\
    \        assert(this->m_exists_inv);\n        return this->m_data[::tools::mod(i,\
    \ this->m_cycle)];\n      }\n    }\n\n    M sum(const ::std::int_fast64_t l, const\
    \ ::std::int_fast64_t r) const {\n      if (l <= r) {\n        if (l >= 0) {\n\
    \          static const auto f = [&](const ::std::int_fast64_t x) {\n        \
    \    if (x <= this->m_head + this->m_cycle) {\n              return this->cumsum(0,\
    \ x);\n            } else {\n              return this->cumsum(0, this->m_head)\
    \ +\n                this->cumsum(this->m_head, this->m_head + this->m_cycle)\
    \ * ((x - this->m_head) / this->m_cycle) +\n                this->cumsum(this->m_head,\
    \ (x - this->m_head) % this->m_cycle + this->m_head);\n            }\n       \
    \   };\n          return f(r) - f(l);\n        } else {\n          assert(this->m_exists_inv);\n\
    \          return (this->cumsum(0, this->m_cycle) * ((r - l) / this->m_cycle)\
    \ + this->cumsum(0, (r - l) % this->m_cycle)) * (*this)[l];\n        }\n     \
    \ } else {\n        return M(0);\n      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/find_cycle.hpp
  - tools/mod.hpp
  - tools/quo.hpp
  isVerificationFile: false
  path: tools/rich_pow_mod_cache.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/rich_pow_mod_cache.hpp
layout: document
title: Precompute $b^n \pmod{M}$ for $-\infty < n < \infty$
---

It precomputes $b^n \pmod{M}$ for $0 \leq n < \infty$.
Additionaly, it precomputes $b^n \pmod{M}$ for $-\infty < n < 0$ if $\gcd(b, M) = 1$.
These features are based on the pigeonhole principle.

## Usage
```cpp
// calculates 10^n (mod 3), for every n
tools::rich_pow_mod_cache<atcoder::static_modint<3>> cache(10);

// obtains 10^123456789 (mod 3), that is 1
cache[123456789];

// obtains 10^10000 + 10^10001 + 10^10002 (mod 3), that is 0
cache.sum(10000, 10003);
```

## License
- CC0

## Author
- anqooqie
