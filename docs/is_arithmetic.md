---
title: std::is_arithmetic extended for tools::int128_t and tools::uint128_t
documentation_of: //tools/is_arithmetic.hpp
---

```cpp
template <typename T>
struct is_arithmetic {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool is_arithmetic_v = is_arithmetic<T>::value;
```

`tools::is_arithmetic_v<T>` is equivalent to `std::is_arithmetic_v<T> || std::is_same_v<std::remove_cv_t<T>, tools::int128_t> || std::is_same_v<std::remove_cv_t<T>, tools::uint128_t>`.
When using libstdc++ with `-std=c++...` option, `std::is_arithmetic_v<tools::int128_t>` and `std::is_arithmetic_v<tools::uint128_t>` are treated as `false`, but with `tools::is_arithmetic`, they can be treated as `true`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
