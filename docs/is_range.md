---
title: Check whether T is a range type
documentation_of: //tools/is_range.hpp
---

```cpp
template <typename T>
struct is_range {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool is_range_v = is_range<T>::value;
```

If an instance of `T` can be passed to `std::begin` and `std::end`, `tools::is_range<T>::value` is `true`.
Otherwise, it is `false`.

## Constraints
- None

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
