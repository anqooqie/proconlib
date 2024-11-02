---
title: Polyfill of std::cmp_less_equal
documentation_of: //tools/cmp_less_equal.hpp
---

```cpp
template <typename T, typename U>
constexpr bool cmp_less_equal(T t, U u) noexcept;
```

It is identical to `std::cmp_less_equal` in C++20.

### Constraints
- `<T>` is an integral type.
- `<U>` is an integral type.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
