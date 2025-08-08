---
title: tools::integral except for bool
documentation_of: //tools/non_bool_integral.hpp
---

```cpp
template <typename T>
concept non_bool_integral = tools::is_integral_v<T> && !std::is_same_v<std::remove_cv_t<T>, bool>;
```

It is a concept that represents integral types except for `bool`.
It also supports `tools::int128_t` and `tools::uint128_t`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
