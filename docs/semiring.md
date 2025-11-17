---
title: Concept for semiring
documentation_of: //tools/semiring.hpp
---

```cpp
template <typename R>
concept semiring = tools::commutative_monoid<typename R::add> && tools::monoid<typename R::mul> && std::same_as<typename R::add::T, typename R::mul::T>;
```

It is a concept that represents a semiring.
Note that semantic constraints must be guaranteed by the user.

Semantically, you can define that the results of `R::add::op` and `R::mul::op` are undefined depending on the arguments.
For example, you can define that integer addition is not defined for overflowing pairs.

### Constraints
- When a user declares that a type `<R>` satisfies the concept of `tools::semiring`, the following conditions must also be satisfied.
    - Semantic constraints of `tools::commutative_monoid<typename R::add>` hold.
    - Semantic constraints of `tools::monoid<typename R::mul>` hold.
    - For any $x$, $y$ and $z$ such that `R::mul::op(x, R::add::op(y, z))` and `R::add::op(R::mul::op(x, y), R::mul::op(x, z))` are defined, `R::mul::op(x, R::add::op(y, z))` $=$ `R::add::op(R::mul::op(x, y), R::mul::op(x, z))`.
    - For any $x$, $y$ and $z$ such that `R::mul::op(R::add::op(x, y), z)` and `R::add::op(R::mul::op(x, z), R::mul::op(y, z))` are defined, `R::mul::op(R::add::op(x, y), z)` $=$ `R::add::op(R::mul::op(x, z), R::mul::op(y, z))`.
    - For any $x$ such that , `R::mul::op(R::add::e(), x)` and `R::mul::op(x, R::add::e())` are defined, `R::mul::op(R::add::e(), x)` $=$ `R::mul::op(x, R::add::e())` = `R::add::e()`.

### Time Complexity
- Not applicable

### License
- CC0

### Author
- anqooqie
