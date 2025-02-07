---
title: std::is_signed extended for tools::int128_t and tools::uint128_t
documentation_of: //tools/is_signed.hpp
---

```cpp
template <typename T>
struct is_signed {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool is_signed_v = is_signed<T>::value;
```

`tools::is_signed_v<T>` is equivalent to `std::is_signed_v<T> || std::is_same_v<std::remove_cv_t<T>, tools::int128_t>`.
When using libstdc++ with `-std=c++...` option, `std::is_signed_v<tools::int128_t>` is treated as `false`, but with `tools::is_signed`, it can be treated as `true`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
