---
title: Dummy monoid
documentation_of: //tools/nop_monoid.hpp
---

```cpp
struct nop_monoid {
  using T = std::monostate;
  static T op(T, T) {
    return {};
  }
  static T e() {
    return {};
  }
};
```

It is a dummy monoid for `tools::lazy_segtree` and other variants.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
