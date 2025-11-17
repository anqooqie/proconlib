---
title: Typical fields
documentation_of: //tools/fields.hpp
---

They are typical fields.

### License
- CC0

### Author
- anqooqie

## fields::of
```cpp
template <tools::commutative_group A, tools::commutative_group M>
struct fields::of {
  using add = A;
  using mul = M;
};
```

It is a template to create a field.

### Constraints
- `tools::field<tools::fields::of<A, M>>` holds.

### Time Complexity
- Not applicable

## fields::plus_multiplies
```cpp
template <typename F>
struct fields::plus_multiplies {
  using add = tools::groups::plus<F>;
  using mul = tools::groups::multiplies<F>;
};
```

It is a field $(F, +, \times)$.

### Constraints
- `tools::field<tools::fields::plus_multiplies<F>>` holds.

### Time Complexity
- Not applicable
