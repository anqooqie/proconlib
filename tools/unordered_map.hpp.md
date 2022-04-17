---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mo.test.cpp
    title: tests/mo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/unordered_map.hpp\"\n\n\n\n#include <functional>\n\
    #include <utility>\n#include <type_traits>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nnamespace tools {\n\n  template <typename Key, typename T, typename Hash = ::std::hash<Key>>\n\
    \  class unordered_map : public ::__gnu_pbds::gp_hash_table<Key, T, Hash> {\n\
    \  public:\n    using ::__gnu_pbds::gp_hash_table<Key, T, Hash>::gp_hash_table;\n\
    \n    template <typename... Args>\n    auto emplace(Args&&... args) {\n      return\
    \ this->insert(::std::make_pair(::std::forward<Args>(args)...));\n    }\n\n  \
    \  template <typename M>\n    auto insert_or_assign(const Key& k, M&& obj) {\n\
    \      if (auto it = this->find(k); it != this->end()) {\n        it->second =\
    \ obj;\n        return ::std::make_pair(it, false);\n      } else {\n        return\
    \ this->emplace(k, obj);\n      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_UNORDERED_MAP_HPP\n#define TOOLS_UNORDERED_MAP_HPP\n\n#include\
    \ <functional>\n#include <utility>\n#include <type_traits>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nnamespace tools {\n\n  template <typename Key, typename T, typename Hash = ::std::hash<Key>>\n\
    \  class unordered_map : public ::__gnu_pbds::gp_hash_table<Key, T, Hash> {\n\
    \  public:\n    using ::__gnu_pbds::gp_hash_table<Key, T, Hash>::gp_hash_table;\n\
    \n    template <typename... Args>\n    auto emplace(Args&&... args) {\n      return\
    \ this->insert(::std::make_pair(::std::forward<Args>(args)...));\n    }\n\n  \
    \  template <typename M>\n    auto insert_or_assign(const Key& k, M&& obj) {\n\
    \      if (auto it = this->find(k); it != this->end()) {\n        it->second =\
    \ obj;\n        return ::std::make_pair(it, false);\n      } else {\n        return\
    \ this->emplace(k, obj);\n      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/unordered_map.hpp
  requiredBy: []
  timestamp: '2022-04-16 19:14:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/mo.test.cpp
documentation_of: tools/unordered_map.hpp
layout: document
title: Alias for __gnu_pbds::gp_hash_table
---

`tools::unordered_map<Key, T, Hash = std::hash<Key>>` is an alias for `__gnu_pbds::gp_hash_table<Key, T, Hash>`.

## Constraints
- It requires GCC.

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
