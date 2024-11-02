---
title: Check whether $(r, c)$ is in a grid of height $h$ and width $w$
documentation_of: //tools/is_in_grid.hpp
---

```cpp
template <typename T1, typename T2, typename T3, typename T4>
bool is_in_grid(T1 r, T2 c, T3 h, T4 w);
```

It returns $0 \leq r < h \land 0 \leq c < w$.

### Constraints
- `<T1>` is an integral type.
- `<T2>` is an integral type.
- `<T3>` is an integral type.
- `<T4>` is an integral type.
- $h \geq 0$
- $w \geq 0$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
