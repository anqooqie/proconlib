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
  bundledCode: "#line 1 \"tools/set.hpp\"\n\n\n\n#include <functional>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    \nnamespace tools {\n  template <typename Key, typename Compare = ::std::less<Key>>\n\
    \  using set = ::__gnu_pbds::tree<Key, ::__gnu_pbds::null_type, Compare, ::__gnu_pbds::rb_tree_tag,\
    \ ::__gnu_pbds::tree_order_statistics_node_update>;\n}\n\n\n"
  code: "#ifndef TOOLS_SET_HPP\n#define TOOLS_SET_HPP\n\n#include <functional>\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n#include\
    \ <ext/pb_ds/tag_and_trait.hpp>\n\nnamespace tools {\n  template <typename Key,\
    \ typename Compare = ::std::less<Key>>\n  using set = ::__gnu_pbds::tree<Key,\
    \ ::__gnu_pbds::null_type, Compare, ::__gnu_pbds::rb_tree_tag, ::__gnu_pbds::tree_order_statistics_node_update>;\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/set.hpp
  requiredBy: []
  timestamp: '2022-04-16 19:14:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/set.hpp
layout: document
title: Alias for __gnu_pbds::tree
---

`tools::set<Key, Compare = std::less<Key>>` is an alias for `__gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>`.

## Constraints
- It requires GCC.

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie