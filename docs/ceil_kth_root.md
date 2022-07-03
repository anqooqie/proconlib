---
title: $\left\lceil x^\frac{1}{k} \right\rceil$
documentation_of: //tools/ceil_kth_root.hpp
---

```cpp
template <typename T, typename U>
T ceil_kth_root(T x, U k);
```

It returns $\left\lceil x^\frac{1}{k} \right\rceil$.

## Constraints
- $x \geq 0$
- $k \geq 1$

## Time Complexity
- $O\left(\frac{\log x \log k}{k}\right)$

## License
- CC0

## Author
- anqooqie
