---
title: $\left\lfloor \frac{x}{y} \right\rfloor$
documentation_of: //tools/floor.hpp
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> floor(M x, N y);
```

It returns $\left\lfloor \frac{x}{y} \right\rfloor$.

### Constraints
- $y \neq 0$
- $\lnot (x =$ `std::numeric_limits<std::common_type_t<M, N>>::min()` $\land\,y = -1)$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
