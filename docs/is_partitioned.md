---
title: Check whether a given boolean function is partitioned
documentation_of: //tools/is_partitioned.hpp
---

```cpp
template <typename T, typename F>
bool is_partitioned(T l, T r, F f);
```

It returns whether the indices $i$ such that $l \leq i \leq r$ are partitioned with respect to the expression `f(i)` or `!f(i)`.

### Constraints
- `<T>` is a built-in integral type.
- $l \leq r$
- $f$ accepts `T` and returns `bool`.

### Time Complexity
- It calls `f` up to $r - l + 1$ times.

### License
- CC0

### Author
- anqooqie
