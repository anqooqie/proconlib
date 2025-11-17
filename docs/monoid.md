---
title: Concept for monoid
documentation_of: //tools/monoid.hpp
---

```cpp
template <typename M>
concept monoid = requires(typename M::T x, typename M::T y) {
  { M::op(x, y) } -> std::same_as<typename M::T>;
  { M::e() } -> std::same_as<typename M::T>;
};
```

It is a concept that represents a monoid.
Note that semantic constraints must be guaranteed by a user.

Semantically, you can define that the result of `M::op` is undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<M>` satisfies the concept of `tools::monoid`, the following conditions must also be satisfied.
    - For any $x$, $y$ and $z$ such that `M::op(M::op(x, y), z)` and `M::op(x, M::op(y, z))` are defined, `M::op(M::op(x, y), z)` $=$ `M::op(x, M::op(y, z))`.
    - For any $x$ such that `M::op(M::e(), x)` and `M::op(x, M::e())` are defined, `M::op(M::e(), x)` $=$ `M::op(x, M::e())` $= x$.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
