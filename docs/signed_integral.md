---
title: Concept for signed integral types including tools::int128_t
documentation_of: //tools/signed_integral.hpp
---

```cpp
template <typename T>
concept signed_integral = tools::integral<T> && tools::is_signed_v<T>;
```

It is a concept that represents signed integral types.
It also supports `tools::int128_t`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
