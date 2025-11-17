---
title: Concept for commutative monoid
documentation_of: //tools/commutative_monoid.hpp
---

```cpp
template <typename M>
concept commutative_monoid = tools::monoid<M>;
```

It is a concept that represents a commutative monoid.
Note that semantic constraints must be guaranteed by the user.

Semantically, you can define that the result of `M::op` is undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<M>` satisfies the concept of `tools::commutative_monoid`, the following conditions must also be satisfied.
    - Semantic constraints of `tools::monoid<M>` hold.
    - For any $x$ and $y$ such that `M::op(x, y)` and `M::op(y, x)` are defined, `M::op(x, y)` $=$ `M::op(y, x)`.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
