---
title: Concept for integral types including tools::int128_t and tools::uint128_t
documentation_of: //tools/integral.hpp
---

```cpp
template <typename T>
concept integral = tools::is_integral_v<T>;
```

It is a concept that represents integral types.
It also supports `tools::int128_t` and `tools::uint128_t`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
