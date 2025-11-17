---
title: Typical monoids
documentation_of: //tools/monoids.hpp
---

They are typical monoids.

### License
- CC0

### Author
- anqooqie

## monoids::bit_and
```cpp
template <typename M> struct monoids::bit_and;
```

It is a commutative monoid $(M, \mathrm{AND}, $`std::numeric_limits<M>::max()`$)$.

### Constraints
- `tools::commutative_monoid<tools::monoids::bit_and<M>>` holds.

### Time Complexity
- Not applicable

## monoids::bit_and::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::bit_and::op
```
static M op(M x, M y);
```

It returns `x & y`.

### Constraints
- None

### Time Complexity
- Same as that of `x & y`

## monoids::bit_and::e
```
static M e();
```

It returns `std::numeric_limits<M>::max()`.

### Constraints
- None

### Time Complexity
- Same as that of `std::numeric_limits<M>::max()`

## monoids::bit_or
```cpp
template <typename M> struct monoids::bit_or;
```

It is a commutative monoid $(M, \mathrm{OR}, 0)$.

### Constraints
- `tools::commutative_monoid<tools::monoids::bit_or<M>>` holds.

### Time Complexity
- Not applicable

## monoids::bit_or::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::bit_or::op
```
static M op(M x, M y);
```

It returns `x | y`.

### Constraints
- None

### Time Complexity
- Same as that of `x | y`

## monoids::bit_or::e
```
static M e();
```

It returns `M(0)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(0)`

## monoids::gcd
```cpp
template <typename M> struct monoids::gcd;
```

It is a commutative monoid $(M, \gcd, 0)$.
Note that we define $\gcd(a, 0) = a$, $\gcd(0, b) = b$ and $\gcd(0, 0) = 0$ in this monoid.

### Constraints
- `tools::gcd(x, y)` is defined for `x` and `y` of type `<M>`. In particular, `<M>` is neither a built-in floating-point type nor `bool`.

### Time Complexity
- Not applicable

## monoids::gcd::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::gcd::op
```
static M op(M x, M y);
```

It returns `tools::gcd(x, y)`.
For a built-in non-bool integral type `<M>`, this is equivalent to returning `std::gcd(x, y)`.

### Constraints
- None

### Time Complexity
- Same as that of `tools::gcd(x, y)`

## monoids::gcd::e
```
static M e();
```

It returns `M(0)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(0)`.

## monoids::max
```cpp
(1) template <tools::arithmetic M> struct monoids::max;
(2) template <std::totally_ordered M, M E> struct monoids::max;
```

It is a commutative monoid $(M, \max, E)$.

- (1)
    - If `tools::integral<M>`, let $E$ be `std::numeric_limits<M>::min()`.
    - If `std::floating_point<M>`, let $E$ be `-std::numeric_limits<M>::infinity()`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::max::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::max::op
```
static M op(M x, M y);
```

It returns $\max(x, y)$.

### Constraints
- $E \leq x$
- $E \leq y$

### Time Complexity
- $O(1)$

## monoids::max::e
```
static M e();
```

It returns $E$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoids::min
```cpp
(1) template <tools::arithmetic M> struct monoids::min;
(2) template <std::totally_ordered M, M E> struct monoids::min;
```

It is a commutative monoid $(M, \min, E)$.

- (1)
    - If `tools::integral<M>`, let $E$ be `std::numeric_limits<M>::max()`.
    - If `std::floating_point<M>`, let $E$ be `std::numeric_limits<M>::infinity()`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::min::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::min::op
```
static M op(M x, M y);
```

It returns $\min(x, y)$.

### Constraints
- $x \leq E$
- $y \leq E$

### Time Complexity
- $O(1)$

## monoids::min::e
```
static M e();
```

It returns $E$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoids::multiplies
```cpp
template <typename M> struct monoids::multiplies;
```

It is a monoid $(M, \times, 1)$.

### Constraints
- `tools::monoid<tools::monoids::multiplies<M>>` holds.

### Time Complexity
- Not applicable

## monoids::multiplies::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::multiplies::op
```
static M op(M x, M y);
```

It returns `x * y`.

### Constraints
- None

### Time Complexity
- Same as that of `x * y`

## monoids::multiplies::e
```
static M e();
```

It returns `M(1)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(1)`

## monoids::update
```cpp
template <typename M, M E> struct monoids::update;
```

It is a monoid $(M, U, E)$ where

$$\begin{align*}
U(x, y) &= \left\{\begin{array}{ll}
y & \text{(if $x = E$)}\\
x & \text{(if $x \neq E$)}
\end{array}\right.
\end{align*}$$

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::update::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoids::update::op
```
static M op(M x, M y);
```

It returns $U(x, y)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoids::update::e
```
static M e();
```

It returns `E`.

### Constraints
- None

### Time Complexity
- $O(1)$
