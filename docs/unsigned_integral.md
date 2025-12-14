---
title: Concept for unsigned integral types including tools::uint128_t
documentation_of: //tools/unsigned_integral.hpp
---

```cpp
template <typename T>
concept unsigned_integral = tools::integral<T> && tools::is_unsigned_v<T>;
```

It is a concept that represents unsigned integral types.
It also supports `tools::uint128_t`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
