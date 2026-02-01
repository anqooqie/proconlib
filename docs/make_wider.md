---
title: Wider integral type
documentation_of: //tools/make_wider.hpp
---

```cpp
template <tools::non_bool_integral T>
struct make_wider {
  using type = ...;
};

template <tools::non_bool_integral T>
using make_wider_t = typename make_wider<T>::type;
```

The integral type `W = tools::make_wider_t<T>` is guaranteed to satisfy the following properties.

- `std::numeric_limits<T>::digits * 2 <= std::numeric_limits<W>::digits`
- `std::is_const_v<T> == std::is_const_v<W>`
- `std::is_volatile_v<T> == std::is_volatile_v<W>`

If such the type does not exist, `tools::make_wider_t<T>` is `void`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
