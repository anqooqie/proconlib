---
title: Check whether T is a monoid
documentation_of: //tools/is_monoid.hpp
---

```cpp
template <typename M>
struct is_monoid {
  static constexpr bool value;
};

template <typename M>
inline constexpr bool is_monoid_v = is_monoid<M>::value;
```

If `<M>` satisfies the following conditions, `tools::is_monoid<M>::value` is `true`.

- `typename M::T` exists.
- The static member function `typename M::T M::op(typename M::T, typename M::T)` exists.
- The static member function `typename M::T M::e()` exists.

Otherwise, it is `false`.

### Constraints
- None

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
