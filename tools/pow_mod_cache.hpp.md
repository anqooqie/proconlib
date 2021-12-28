---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/pow_mod_cache.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstdint>\n\nnamespace tools {\n\n  template <class M>\n  class pow_mod_cache\
    \ {\n  private:\n    ::std::vector<M> m_data;\n\n  public:\n    pow_mod_cache()\
    \ = default;\n    pow_mod_cache(const pow_mod_cache&) = default;\n    pow_mod_cache(pow_mod_cache&&)\
    \ = default;\n    ~pow_mod_cache() = default;\n    pow_mod_cache& operator=(const\
    \ pow_mod_cache&) = default;\n    pow_mod_cache& operator=(pow_mod_cache&&) =\
    \ default;\n\n    pow_mod_cache(const M& base, const ::std::int_fast64_t max)\
    \ :\n      m_data(max + 1) {\n      this->m_data[0] = M(1);\n      for (::std::int_fast64_t\
    \ i = 1; i <= max; ++i) {\n        this->m_data[i] = this->m_data[i - 1] * base;\n\
    \      }\n    }\n\n    pow_mod_cache(const ::std::int_fast64_t base, const ::std::int_fast64_t\
    \ max) :\n      pow_mod_cache(M(base), max) {\n    }\n\n    M operator[](const\
    \ ::std::int_fast64_t i) const {\n      return this->m_data[i];\n    }\n  };\n\
    }\n\n\n"
  code: "#ifndef TOOLS_POW_MOD_CACHE_HPP\n#define TOOLS_POW_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <cstdint>\n\nnamespace tools {\n\n  template <class M>\n\
    \  class pow_mod_cache {\n  private:\n    ::std::vector<M> m_data;\n\n  public:\n\
    \    pow_mod_cache() = default;\n    pow_mod_cache(const pow_mod_cache&) = default;\n\
    \    pow_mod_cache(pow_mod_cache&&) = default;\n    ~pow_mod_cache() = default;\n\
    \    pow_mod_cache& operator=(const pow_mod_cache&) = default;\n    pow_mod_cache&\
    \ operator=(pow_mod_cache&&) = default;\n\n    pow_mod_cache(const M& base, const\
    \ ::std::int_fast64_t max) :\n      m_data(max + 1) {\n      this->m_data[0] =\
    \ M(1);\n      for (::std::int_fast64_t i = 1; i <= max; ++i) {\n        this->m_data[i]\
    \ = this->m_data[i - 1] * base;\n      }\n    }\n\n    pow_mod_cache(const ::std::int_fast64_t\
    \ base, const ::std::int_fast64_t max) :\n      pow_mod_cache(M(base), max) {\n\
    \    }\n\n    M operator[](const ::std::int_fast64_t i) const {\n      return\
    \ this->m_data[i];\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/pow_mod_cache.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/pow_mod_cache.hpp
layout: document
title: Precompute $b^n \pmod{M}$ for $0 \leq n \leq N$
---

It precomputes $b^n \pmod{M}$ for $0 \leq n \leq N$.

## Usage
```cpp
// precomputs 10^n (mod 3) for 0 <= n <= 5
tools::pow_mod_cache<atcoder::static_modint<3>> cache(10, 5);

// obtains 10^5 (mod 3), that is 1
cache[5];
```

## License
- CC0

## Author
- anqooqie