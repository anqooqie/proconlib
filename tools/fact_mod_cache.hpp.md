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
    \ <cstdint>\n#include <cassert>\n\nnamespace tools {\n\n  /**\n   * factorial\
    \ mod\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * // calculates n! (mod\
    \ 3) for 0 <= n <= 5\n   * tools::fact_mod_cache<atcoder::static_modint<3>> cache(5);\n\
    \   *\n   * // obtains 5! (mod 3), that is 0\n   * cache.fact(5);\n   * ```\n\
    \   *\n   * @author anqooqie\n   * @param <M> `atcoder::modint`\n   */\n  template\
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
    \ * this->m_inv_data[r] : M(0);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_FACT_MOD_CACHE_HPP\n#define TOOLS_FACT_MOD_CACHE_HPP\n\n#include\
    \ <vector>\n#include <cstdint>\n#include <cassert>\n\nnamespace tools {\n\n  /**\n\
    \   * factorial mod\n   * License: CC0\n   *\n   * Usage:\n   * ```\n   * // calculates\
    \ n! (mod 3) for 0 <= n <= 5\n   * tools::fact_mod_cache<atcoder::static_modint<3>>\
    \ cache(5);\n   *\n   * // obtains 5! (mod 3), that is 0\n   * cache.fact(5);\n\
    \   * ```\n   *\n   * @author anqooqie\n   * @param <M> `atcoder::modint`\n  \
    \ */\n  template <class M>\n  class fact_mod_cache {\n  private:\n    ::std::vector<M>\
    \ m_data;\n    ::std::vector<M> m_inv_data;\n\n  public:\n    fact_mod_cache()\
    \ = default;\n    fact_mod_cache(const fact_mod_cache&) = default;\n    fact_mod_cache(fact_mod_cache&&)\
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
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/fact_mod_cache.test.cpp
documentation_of: tools/fact_mod_cache.hpp
layout: document
redirect_from:
- /library/tools/fact_mod_cache.hpp
- /library/tools/fact_mod_cache.hpp.html
title: tools/fact_mod_cache.hpp
---
