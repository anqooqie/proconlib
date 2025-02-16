---
title: Dummy mapping
documentation_of: //tools/nop_mapping.hpp
---

```cpp
template <typename F, typename S>
S nop_mapping(F f, S e);
```

It is a dummy `mapping` function for `tools::lazy_segtree` and other variants.
It returns $e$ regardless of $f$.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
