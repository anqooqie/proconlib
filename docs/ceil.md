---
title: $\left\lceil \frac{x}{y} \right\rceil$
documentation_of: //tools/ceil.hpp
---

```cpp
template <typename M, typename N>
std::common_type_t<M, N> ceil(M x, N y);
```

It returns $\left\lceil \frac{x}{y} \right\rceil$.

### Constraints
- $y \neq 0$
- $\lnot (x =$ `std::numeric_limits<std::common_type_t<M, N>>::min()` $\land\,y = -1)$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
