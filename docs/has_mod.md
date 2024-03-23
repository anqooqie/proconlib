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

If an instance of `T` has the member function `mod()`, `tools::has_mod<T>::value` is `true`.
Otherwise, it is `false`.

## Constraints
- None

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
