---
title: __gnu_pbds::tree, but more compatible with std::set
documentation_of: //tools/set.hpp
---

`tools::set<Key, Compare = std::less<Key>>` is almost like `__gnu_pbds::tree<Key, __gnu_pbds::null_type, Compare, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>`, but its interface is more compatible with `std::set<Key, Compare>`.

### Constraints
- It requires libstdc++, usually bundled with GCC.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
