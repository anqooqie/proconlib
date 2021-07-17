---
title: Check whether T is a range type
documentation_of: //tools/is_range.hpp
---

```cpp
template <typename T>
struct is_range {
  static const bool value;
};
```

`tools::is_range<T>::value` will be `true` if and only if an instance of `T` can be passed to `std::begin` and `std::end`.
Otherwise, it will be `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
