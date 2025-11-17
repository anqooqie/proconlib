---
title: Typical semirings
documentation_of: //tools/semirings.hpp
---

They are typical semirings.

### License
- CC0

### Author
- anqooqie

## semirings::of
```cpp
template <tools::commutative_monoid A, tools::monoid M>
struct semirings::of {
  using add = A;
  using mul = M;
};
```

It is a template to create a semiring.

### Constraints
- `tools::semiring<tools::semirings::of<A, M>>` holds.

### Time Complexity
- Not applicable

## semirings::min_plus
```cpp
template <typename R>
struct semirings::min_plus {
  using add = tools::monoids::min<R>;
  using mul = tools::groups::plus<R>;
};
```

It is a semiring $(R, \min, +)$.

### Constraints
- `tools::semiring<tools::semirings::min_plus<R>>` holds.

### Time Complexity
- Not applicable

## semirings::max_plus
```cpp
template <typename R>
struct semirings::max_plus {
  using add = tools::monoids::max<R>;
  using mul = tools::groups::plus<R>;
};
```

It is a semiring $(R, \max, +)$.

### Constraints
- `tools::semiring<tools::semirings::max_plus<R>>` holds.

### Time Complexity
- Not applicable

## semirings::min_max
```cpp
template <typename R>
struct semirings::min_max {
  using add = tools::monoids::min<R>;
  using mul = tools::monoids::max<R>;
};
```

It is a semiring $(R, \min, \max)$.

### Constraints
- `tools::semiring<tools::semirings::min_max<R>>` holds.

### Time Complexity
- Not applicable

## semirings::max_min
```cpp
template <typename R>
struct semirings::max_min {
  using add = tools::monoids::max<R>;
  using mul = tools::monoids::min<R>;
};
```

It is a semiring $(R, \max, \min)$.

### Constraints
- `tools::semiring<tools::semirings::max_min<R>>` holds.

### Time Complexity
- Not applicable
