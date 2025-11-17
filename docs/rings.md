---
title: Typical rings
documentation_of: //tools/rings.hpp
---

They are typical rings.

### License
- CC0

### Author
- anqooqie

## rings::of
```cpp
template <tools::commutative_group A, tools::monoid M>
struct rings::of {
  using add = A;
  using mul = M;
};
```

It is a template to create a ring.

### Constraints
- `tools::ring<tools::rings::of<A, M>>` holds.

### Time Complexity
- Not applicable

## rings::plus_multiplies
```cpp
template <typename R>
struct rings::plus_multiplies {
  using add = tools::groups::plus<R>;
  using mul = tools::monoids::multiplies<R>;
};
```

It is a ring $(R, +, \times)$.

### Constraints
- `tools::ring<tools::rings::plus_multiplies<R>>` holds.

### Time Complexity
- Not applicable

## rings::xor_and
```cpp
template <typename R>
struct rings::xor_and {
  using add = tools::groups::bit_xor<R>;
  using mul = tools::monoids::bit_and<R>;
};
```

It is a commutative ring $(R, \oplus, \land)$.

### Constraints
- `tools::ring<tools::rings::xor_and<R>>` holds.

### Time Complexity
- Not applicable
