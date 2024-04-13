---
title: chmin function
documentation_of: //tools/chmin.hpp
---

```cpp
template <typename M, typename N>
bool chmin(M& lhs, N rhs);
```

It runs `lhs = std::min(lhs, rhs);`.
It returns `true` if `lhs` has been updated.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
