---
title: std::midpoint(a, b) extended for my library
documentation_of: //tools/midpoint.hpp
---

```cpp
template <tools::non_bool_integral T>
constexpr T midpoint(T a, T b) noexcept;
```

It returns $\frac{a + b}{2}$ rounded towards $a$.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
