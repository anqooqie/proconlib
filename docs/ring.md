---
title: Concept for ring
documentation_of: //tools/ring.hpp
---

```cpp
template <typename R>
concept ring = tools::semiring<R> && tools::commutative_group<typename R::add>;
```

It is a concept that represents a ring.
Note that semantic constraints must be guaranteed by the user.

Semantically, you can define that the results of `R::add::op`, `R::add::inv` and `R::mul::op` are undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<R>` satisfies the concept of `tools::ring`, the following conditions must also be satisfied.
    - Semantic constraints of `tools::semiring<R>` hold.
    - Semantic constraints of `tools::commutative_group<typename R::add>` hold.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
