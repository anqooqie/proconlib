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

If `<T>` is `tools::rational`, `tools::is_rational<T>::value` is `true`.
Otherwise, it is `false`.

## Constraints
- None

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
