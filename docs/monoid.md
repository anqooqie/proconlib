---
title: Typical monoids
documentation_of: //tools/monoid.hpp
---

They are typical monoids.

### License
- CC0

### Author
- anqooqie

## monoid::bit_and
```cpp
template <typename M> struct monoid::bit_and;
```

It is a monoid $(M, \mathrm{AND}, $`std::numeric_limits<M>::max()`$)$.

### Constraints
- If `x` is `<M>` and `y` is `<M>`, then `x & y` is also `<M>`.
- For all `x` in `<M>`, `y` in `<M>` and `z` in `<M>`, `(x & y) & z` $=$ `x & (y & z)`.
- For all `x` in `<M>`, `std::numeric_limits<M>::max() & x` $=$ `x & std::numeric_limits<M>::max()` $=$ `x`.

### Time Complexity
- Not applicable

## monoid::bit_and::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::bit_and::op
```
static M op(M x, M y);
```

It returns `x & y`.

### Constraints
- None

### Time Complexity
- Same as that of `x & y`

## monoid::bit_and::e
```
static M e();
```

It returns `std::numeric_limits<M>::max()`.

### Constraints
- None

### Time Complexity
- Same as that of `std::numeric_limits<M>::max()`

## monoid::bit_or
```cpp
template <typename M> struct monoid::bit_or;
```

It is a monoid $(M, \mathrm{OR}, 0)$.

### Constraints
- If `x` is `<M>` and `y` is `<M>`, then `x | y` is also `<M>`.
- For all `x` in `<M>`, `y` in `<M>` and `z` in `<M>`, `(x | y) | z` $=$ `x | (y | z)`.
- For all `x` in `<M>`, `M(0) | x` $=$ `x | M(0)` $=$ `x`.

### Time Complexity
- Not applicable

## monoid::bit_or::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::bit_or::op
```
static M op(M x, M y);
```

It returns `x | y`.

### Constraints
- None

### Time Complexity
- Same as that of `x | y`

## monoid::bit_or::e
```
static M e();
```

It returns `M(0)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(0)`

## monoid::gcd
```cpp
template <typename M> struct monoid::gcd;
```

It is a monoid $(M, \gcd, 0)$.
Note that we define $\gcd(a, 0) = a$, $\gcd(0, b) = b$ and $\gcd(0, 0) = 0$ in this monoid.

### Constraints
- `tools::gcd(x, y)` is defined for `x` and `y` of type `<M>`. In particular, `<M>` is neither a built-in floating-point type nor `bool`.

### Time Complexity
- Not applicable

## monoid::gcd::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::gcd::op
```
static M op(M x, M y);
```

It returns `tools::gcd(x, y)`.
For a built-in integral type `<M>`, this is equivalent to returning `std::gcd(x, y)`.

### Constraints
- None

### Time Complexity
- Same as that of `tools::gcd(x, y)`

## monoid::gcd::e
```
static M e();
```

It returns `M(0)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(0)`.

## monoid::max
```cpp
(1) template <typename M> struct monoid::max;
(2) template <typename M, M E> struct monoid::max;
```

It is a monoid $(M, \max, E)$.

- (1)
    - If `tools::is_integral_v<M>`, let $E$ be `std::numeric_limits<M>::min()`.
    - If `std::is_floating_point_v<M>`, let $E$ be `-std::numeric_limits<M>::infinity()`.

### Constraints
- (1)
    - `tools::is_arithemtic_v<M>` is `true`.

### Time Complexity
- Not applicable

## monoid::max::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::max::op
```
static M op(M x, M y);
```

It returns $\max(x, y)$.

### Constraints
- $E \leq x$
- $E \leq y$

### Time Complexity
- $O(1)$

## monoid::max::e
```
static M e();
```

It returns $E$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoid::min
```cpp
(1) template <typename M> struct monoid::min;
(2) template <typename M, M E> struct monoid::min;
```

It is a monoid $(M, \min, E)$.

- (1)
    - If `tools::is_integral_v<M>`, let $E$ be `std::numeric_limits<M>::max()`.
    - If `std::is_floating_point_v<M>`, let $E$ be `std::numeric_limits<M>::infinity()`.

### Constraints
- (1)
    - `tools::is_arithemtic_v<M>` is `true`.

### Time Complexity
- Not applicable

## monoid::min::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::min::op
```
static M op(M x, M y);
```

It returns $\min(x, y)$.

### Constraints
- $x \leq E$
- $y \leq E$

### Time Complexity
- $O(1)$

## monoid::min::e
```
static M e();
```

It returns $E$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoid::multiplies
```cpp
template <typename M> struct monoid::multiplies;
```

It is a monoid $(M, \times, 1)$.

### Constraints
- If `x` is `<M>` and `y` is `<M>`, then `x * y` is also `<M>`.
- For all `x` in `<M>`, `y` in `<M>` and `z` in `<M>`, `(x * y) * z` $=$ `x * (y * z)`.
- For all `x` in `<M>`, `M(1) * x` $=$ `x * M(1)` $=$ `x`.

### Time Complexity
- Not applicable

## monoid::multiplies::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::multiplies::op
```
static M op(M x, M y);
```

It returns `x * y`.

### Constraints
- None

### Time Complexity
- Same as that of `x * y`

## monoid::multiplies::e
```
static M e();
```

It returns `M(1)`.

### Constraints
- None

### Time Complexity
- Same as that of `M(1)`

## monoid::update
```cpp
template <typename M, M E> struct monoid::update;
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

## monoid::update::T
```
using T = M;
```

It is an alias for `<M>`.

### Constraints
- None

### Time Complexity
- Not applicable

## monoid::update::op
```
static M op(M x, M y);
```

It returns $U(x, y)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## monoid::update::e
```
static M e();
```

It returns `E`.

### Constraints
- None

### Time Complexity
- $O(1)$
