---
title: Check whether T is tools::rational
documentation_of: //tools/is_rational.hpp
---

```cpp
template <typename T>
struct is_rational {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool is_rational_v = is_rational<T>::value;
```

`tools::is_rational<T>::value` will be `true` if `T` is `tools::rational`.
Otherwise, it will be `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
