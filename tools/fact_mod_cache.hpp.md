---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/fact_mod_cache.test.cpp
    title: tests/fact_mod_cache.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/fact_mod_cache.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstdint>\n#include <cassert>\n\nnamespace tools {\n\n  template <class M>\n\
    \  class fact_mod_cache {\n  private:\n    ::std::vector<M> m_data;\n    ::std::vector<M>\
    \ m_inv_data;\n\n  public:\n    fact_mod_cache() = default;\n    fact_mod_cache(const\
    \ fact_mod_cache&) = default;\n    fact_mod_cache(fact_mod_cache&&) = default;\n\
    \    ~fact_mod_cache() = default;\n    fact_mod_cache& operator=(const fact_mod_cache&)\
    \ = default;\n    fact_mod_cache& operator=(fact_mod_cache&&) = default;\n\n \
    \   fact_mod_cache(const ::std::int_fast64_t max) :\n      m_data(max + 1),\n\
    \      m_inv_data(max + 1) {\n      assert(max < M::mod());\n      this->m_data[0]\
    \ = M(1);\n      for (::std::int_fast64_t i = 1; i <= max; ++i) {\n        this->m_data[i]\
    \ = this->m_data[i - 1] * M(i);\n      }\n      this->m_inv_data[max] = this->m_data[max].inv();\n\
    \      for (::std::int_fast64_t i = max - 1; i >= 0; --i) {\n        this->m_inv_data[i]\
    \ = this->m_inv_data[i + 1] * M(i + 1);\n      }\n    }\n\n    M fact(const ::std::int_fast64_t\
    \ i) const {\n      return this->m_data[i];\n    }\n\n    M inv_fact(const ::std::int_fast64_t\
    \ i) const {\n      return this->m_inv_data[i];\n    }\n\n    M permutation(const\
    \ ::std::int_fast64_t n, const ::std::int_fast64_t r) const {\n      return 0\
    \ <= r && r <= n ? this->m_data[n] * this->m_inv_data[n - r] : M(0);\n    }\n\n\
    \    M combination(const ::std::int_fast64_t n, const ::std::int_fast64_t r) const\
    \ {\n      return 0 <= r && r <= n ? this->m_data[n] * this->m_inv_data[n - r]\
    \ * this->m_inv_data[r] : M(0);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_FACT_MOD_CACHE_HPP\n#define TOOLS_FACT_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <cstdint>\n#include <cassert>\n\nnamespace tools {\n\n  template\
    \ <class M>\n  class fact_mod_cache {\n  private:\n    ::std::vector<M> m_data;\n\
    \    ::std::vector<M> m_inv_data;\n\n  public:\n    fact_mod_cache() = default;\n\
    \    fact_mod_cache(const fact_mod_cache&) = default;\n    fact_mod_cache(fact_mod_cache&&)\
    \ = default;\n    ~fact_mod_cache() = default;\n    fact_mod_cache& operator=(const\
    \ fact_mod_cache&) = default;\n    fact_mod_cache& operator=(fact_mod_cache&&)\
    \ = default;\n\n    fact_mod_cache(const ::std::int_fast64_t max) :\n      m_data(max\
    \ + 1),\n      m_inv_data(max + 1) {\n      assert(max < M::mod());\n      this->m_data[0]\
    \ = M(1);\n      for (::std::int_fast64_t i = 1; i <= max; ++i) {\n        this->m_data[i]\
    \ = this->m_data[i - 1] * M(i);\n      }\n      this->m_inv_data[max] = this->m_data[max].inv();\n\
    \      for (::std::int_fast64_t i = max - 1; i >= 0; --i) {\n        this->m_inv_data[i]\
    \ = this->m_inv_data[i + 1] * M(i + 1);\n      }\n    }\n\n    M fact(const ::std::int_fast64_t\
    \ i) const {\n      return this->m_data[i];\n    }\n\n    M inv_fact(const ::std::int_fast64_t\
    \ i) const {\n      return this->m_inv_data[i];\n    }\n\n    M permutation(const\
    \ ::std::int_fast64_t n, const ::std::int_fast64_t r) const {\n      return 0\
    \ <= r && r <= n ? this->m_data[n] * this->m_inv_data[n - r] : M(0);\n    }\n\n\
    \    M combination(const ::std::int_fast64_t n, const ::std::int_fast64_t r) const\
    \ {\n      return 0 <= r && r <= n ? this->m_data[n] * this->m_inv_data[n - r]\
    \ * this->m_inv_data[r] : M(0);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/fact_mod_cache.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/fact_mod_cache.test.cpp
documentation_of: tools/fact_mod_cache.hpp
layout: document
title: Precompute $n! \pmod{M}$ for $0 \leq n \leq N$
---

It precomputes $n! \pmod{M}$ for $0 \leq n \leq N$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::fact_mod_cache<T> cache(std::int_fast64_t N);
```

It precomputes $n! \pmod{M}$ for $0 \leq n \leq N$ where $M$ is `T::mod()`.

### Constraints
- `<T>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $M$ is a prime
- $0 \leq N < M$

### Time Complexity
- $O(N + \log M)$

## fact
```cpp
T cache.fact(::std::int_fast64_t n);
```

It returns $n! \pmod{M}$.

### Constraints
- $0 \leq n \leq N$

### Time Complexity
- $O(1)$

## inv_fact
```cpp
T cache.inv_fact(::std::int_fast64_t n);
```

It returns $n!^{-1} \pmod{M}$.

### Constraints
- $0 \leq n \leq N$

### Time Complexity
- $O(1)$

## permutation
```cpp
T cache.permutation(::std::int_fast64_t n, ::std::int_fast64_t r);
```

It returns ${}_n P_r \pmod{M}$ if $0 \leq r \leq n$.
Otherwise, it returns $0$.

### Constraints
- $n \leq N$

### Time Complexity
- $O(1)$

## combination
```cpp
T cache.combination(::std::int_fast64_t n, ::std::int_fast64_t r);
```

It returns ${}_n C_r \pmod{M}$ if $0 \leq r \leq n$.
Otherwise, it returns $0$.

### Constraints
- $n \leq N$

### Time Complexity
- $O(1)$
