---
title: Concept for field
documentation_of: //tools/field.hpp
---

```cpp
template <typename F>
concept field = tools::commutative_ring<F> && tools::commutative_group<typename F::mul>;
```

It is a concept that represents a field.
Note that semantic constraints must be guaranteed by the user.

Semantically, you can define that the results of `F::add::op`, `F::add::inv`, `F::mul::op` and `F::mul::inv` are undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<F>` satisfies the concept of `tools::field`, the following conditions must also be satisfied.
    - Semantic constraints of `tools::commutative_ring<F>` hold.
    - Semantic constraints of `tools::commutative_group<typename F::mul>` hold.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
