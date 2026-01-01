---
title: std::cmp_greater extended for my library
documentation_of: //tools/cmp_greater.hpp
---

```cpp
template <tools::integral T, tools::integral U>
constexpr bool cmp_greater(T t, U u) noexcept;
```

It is almost identical to `std::cmp_greater`, but compatible with user-defined extended integral types.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
