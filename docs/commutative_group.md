---
title: Concept for commutative group
documentation_of: //tools/commutative_group.hpp
---

```cpp
template <typename G>
concept commutative_group = tools::group<G> && tools::commutative_monoid<G>;
```

It is a concept that represents a commutative group.
Note that semantic constraints must be guaranteed by the user.

Semantically, you can define that the results of `G::op` and `G::inv` are undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<G>` satisfies the concept of `tools::commutative_group`, the following conditions must also be satisfied.
    - Semantic constraints of `tools::group<G>` hold.
    - Semantic constraints of `tools::commutative_monoid<G>` hold.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
