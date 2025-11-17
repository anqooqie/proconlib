---
title: Concept for commutative ring
documentation_of: //tools/commutative_ring.hpp
---

```cpp
template <typename R>
concept commutative_ring = tools::ring<R> && tools::commutative_monoid<typename R::mul>;
```

It is a concept that represents a commutative ring.
Note that semantic constraints must be guaranteed by the user.

Semantically, you can define that the results of `R::add::op`, `R::add::inv` and `R::mul::op` are undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<R>` satisfies the concept of `tools::commutative_ring`, the following conditions must also be satisfied.
    - Semantic constraints of `tools::ring<R>` hold.
    - Semantic constraints of `tools::commutative_monoid<typename R::mul>` hold.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
