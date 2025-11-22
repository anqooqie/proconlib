---
title: $\left\lfloor \frac{x}{y} \right\rfloor$
documentation_of: //tools/floor.hpp
---

```cpp
template <tools::non_bool_integral M, tools::non_bool_integral N>
constexpr std::common_type_t<M, N> floor(M x, N y) noexcept;
```

It returns $\left\lfloor \frac{x}{y} \right\rfloor$.

### Constraints
- $y \neq 0$
- $\lfloor \frac{x}{y} \rfloor$ is representable in type `std::common_type_t<M, N>`.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
