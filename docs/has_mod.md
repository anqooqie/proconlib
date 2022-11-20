---
title: Check whether T has the member function mod()
documentation_of: //tools/has_mod.hpp
---

```cpp
template <typename T>
struct has_mod {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool has_mod_v = has_mod<T>::value;
```

`tools::has_mod<T>::value` will be `true` if `T` has the member function `mod()`.
Otherwise, it will be `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
