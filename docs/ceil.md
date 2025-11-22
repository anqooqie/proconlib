---
title: $\left\lceil \frac{x}{y} \right\rceil$
documentation_of: //tools/ceil.hpp
---

```cpp
template <tools::non_bool_integral M, tools::non_bool_integral N>
constexpr std::common_type_t<M, N> ceil(M x, N y) noexcept;
```

It returns $\left\lceil \frac{x}{y} \right\rceil$.

### Constraints
- $y \neq 0$
- $\lceil \frac{x}{y} \rceil$ is representable in type `std::common_type_t<M, N>`.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
