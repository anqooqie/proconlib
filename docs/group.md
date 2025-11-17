---
title: Concept for group
documentation_of: //tools/group.hpp
---

```cpp
template <typename G>
concept group = tools::monoid<G> && requires(typename G::T x) {
  { G::inv(x) } -> std::same_as<typename G::T>;
};
```

It is a concept that represents a group.
Note that semantic constraints must be guaranteed by the user.

Semantically, you can define that the results of `G::op` and `G::inv` are undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<G>` satisfies the concept of `tools::group`, the following conditions must also be satisfied.
    - Semantic constraints of `tools::monoid<G>` hold.
    - For any $x$ such that `G::op(G::inv(x), x)` and `G::op(x, G::inv(x))` are defined, `G::op(G::inv(x), x)` $=$ `G::op(x, G::inv(x))` $=$ `G::e()`.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
