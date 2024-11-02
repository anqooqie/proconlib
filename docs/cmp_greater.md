---
title: Polyfill of std::cmp_greater
documentation_of: //tools/cmp_greater.hpp
---

```cpp
template <typename T, typename U>
constexpr bool cmp_greater(T t, U u) noexcept;
```

It is identical to `std::cmp_greater` in C++20.

### Constraints
- `<T>` is an integral type.
- `<U>` is an integral type.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie