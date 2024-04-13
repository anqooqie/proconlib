---
title: Polyfill of std::cmp_less
documentation_of: //tools/cmp_less.hpp
---

```cpp
template <typename T, typename U>
constexpr bool cmp_less(T t, U u) noexcept;
```

It is identical to `std::cmp_less` in C++20.

### Constraints
- `<T>` is an integral type.
- `<U>` is an integral type.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
