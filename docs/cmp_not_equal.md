---
title: std::cmp_not_equal extended for my library
documentation_of: //tools/cmp_not_equal.hpp
---

```cpp
template <tools::integral T, tools::integral U>
constexpr bool cmp_not_equal(T t, U u) noexcept;
```

It is almost identical to `std::cmp_not_equal`, but compatible with user-defined extended integral types.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
