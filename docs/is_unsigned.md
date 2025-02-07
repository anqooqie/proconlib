---
title: std::is_unsigned extended for tools::int128_t and tools::uint128_t
documentation_of: //tools/is_unsigned.hpp
---

```cpp
template <typename T>
struct is_unsigned {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool is_unsigned_v = is_unsigned<T>::value;
```

`tools::is_unsigned_v<T>` is equivalent to `std::is_unsigned_v<T> || std::is_same_v<std::remove_cv_t<T>, tools::uint128_t>`.
When using libstdc++ with `-std=c++...` option, `std::is_unsigned_v<tools::uint128_t>` is treated as `false`, but with `tools::is_unsigned`, it can be treated as `true`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
