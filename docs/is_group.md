---
title: Check whether T is a group
documentation_of: //tools/is_group.hpp
---

```cpp
template <typename G>
struct is_group {
  static constexpr bool value;
};

template <typename G>
inline constexpr bool is_group_v = is_group<G>::value;
```

If `<G>` satisfies the following conditions, `tools::is_group<G>::value` is `true`.

- `typename G::T` exists.
- The static member function `typename G::T G::op(typename G::T, typename G::T)` exists.
- The static member function `typename G::T G::e()` exists.
- The static member function `typename G::T G::inv(typename G::T)` exists.

Otherwise, it is `false`.

## Constraints
- None

## Time Complexity
- Not applicable

## License
- CC0

## Author
- anqooqie
