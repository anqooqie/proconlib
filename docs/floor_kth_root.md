---
title: $\left\lfloor x^\frac{1}{k} \right\rfloor$
documentation_of: //tools/floor_kth_root.hpp
---

```cpp
template <typename T, typename U>
T floor_kth_root(T x, U k);
```

It returns $\left\lfloor x^\frac{1}{k} \right\rfloor$.

### Constraints
- $x \geq 0$
- $k \geq 1$

### Time Complexity
- $O\left(\frac{\log x \log k}{k}\right)$

### License
- CC0

### Author
- anqooqie
