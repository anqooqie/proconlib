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
  bundledCode: "#line 1 \"tools/unordered_set.hpp\"\n\n\n\n#include <functional>\n\
    #include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    \nnamespace tools {\n  template <typename Key, typename Hash = ::std::hash<Key>>\n\
    \  using unordered_set = ::__gnu_pbds::gp_hash_table<Key, ::__gnu_pbds::null_type,\
    \ Hash>;\n}\n\n\n"
  code: "#ifndef TOOLS_UNORDERED_SET_HPP\n#define TOOLS_UNORDERED_SET_HPP\n\n#include\
    \ <functional>\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    \nnamespace tools {\n  template <typename Key, typename Hash = ::std::hash<Key>>\n\
    \  using unordered_set = ::__gnu_pbds::gp_hash_table<Key, ::__gnu_pbds::null_type,\
    \ Hash>;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/unordered_set.hpp
  requiredBy: []
  timestamp: '2022-05-15 23:41:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/unordered_set.hpp
layout: document
title: Alias for __gnu_pbds::gp_hash_table&amp;lt;Key, __gnu_pbds::null_type, Hash&amp;gt;
---

`tools::unordered_set<Key, Hash = std::hash<Key>>` is an alias for `__gnu_pbds::gp_hash_table<Key, __gnu_pbds::null_type, Hash>`.

### Constraints
- It requires GCC.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
