---
title: Concept for arithmetic types including tools::int128_t and tools::uint128_t
documentation_of: //tools/arithmetic.hpp
---

```cpp
template <typename T>
concept arithmetic = tools::integral<T> || std::floating_point<T>;
```

It is a concept that represents arithmetic types.
It also supports `tools::int128_t` and `tools::uint128_t`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
