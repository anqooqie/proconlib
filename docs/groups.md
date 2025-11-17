---
title: Typical groups
documentation_of: //tools/groups.hpp
---

They are typical groups.

### License
- CC0

### Author
- anqooqie

## groups::bit_xor
```cpp
template <typename G> struct groups::bit_xor;
```

It is a group $(G, \oplus, 0)$.

### Constraints
- `tools::commutative_group<tools::groups::bit_xor<G>>` holds.

### Time Complexity
- Not applicable

## groups::bit_xor::T
```
using T = G;
```

It is an alias for `<G>`.

### Constraints
- None

### Time Complexity
- Not applicable

## groups::bit_xor::op
```
static G op(G x, G y);
```

It returns `x ^ y`.

### Constraints
- None

### Time Complexity
- Same as that of `x ^ y`

## groups::bit_xor::e
```
static G e();
```

It returns `G(0)`.

### Constraints
- None

### Time Complexity
- Same as that of `G(0)`

## groups::bit_xor::inv
```
static G inv(G x);
```

It returns `x`.

### Constraints
- None

### Time Complexity
- Same as that of `G(x)`

## groups::multiplies
```cpp
template <typename G> struct groups::multiplies;
```

It is a group $(G, \times, 1)$.

### Constraints
- `tools::group<tools::groups::multiplies<G>>` holds.

### Time Complexity
- Not applicable

## groups::multiplies::T
```
using T = G;
```

It is an alias for `<G>`.

### Constraints
- None

### Time Complexity
- Not applicable

## groups::multiplies::op
```
static G op(G x, G y);
```

It returns `x * y`.

### Constraints
- None

### Time Complexity
- Same as that of `x * y`

## groups::multiplies::e
```
static G e();
```

It returns `G(1)`.

### Constraints
- None

### Time Complexity
- Same as that of `G(1)`

## groups::multiplies::inv
```
static G inv(G x);
```

It returns `G(1) / x`.

### Constraints
- None

### Time Complexity
- Same as that of `G(1) / x`

## groups::plus
```cpp
template <typename G> struct groups::plus;
```

It is a group $(G, +, 0)$.

### Constraints
- `tools::commutative_group<tools::groups::plus<G>>` holds.

### Time Complexity
- Not applicable

## groups::plus::T
```
using T = G;
```

It is an alias for `<G>`.

### Constraints
- None

### Time Complexity
- Not applicable

## groups::plus::op
```
static G op(G x, G y);
```

It returns `x + y`.

### Constraints
- None

### Time Complexity
- Same as that of `x + y`

## groups::plus::e
```
static G e();
```

It returns `G(0)`.

### Constraints
- None

### Time Complexity
- Same as that of `G(0)`

## groups::plus::inv
```
static G inv(G x);
```

It returns `-x`.

### Constraints
- None

### Time Complexity
- Same as that of `-x`
