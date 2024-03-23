---
title: Online cumulative sum
documentation_of: //tools/online_cumsum.hpp
---

It is a cumulative sum, but allows you to construct it by online.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) online_cumsum<T, Forward = true> a();
(2) online_cumsum<T, Forward = true> a(std::size_t n);
(3) online_cumsum<G, Forward = true> a();
(4) online_cumsum<G, Forward = true> a(std::size_t n);
```

- (1)
    - It is identical to `online_cumsum<tools::group::plus<T>, Forward> a(0);`.
- (2)
    - It is identical to `online_cumsum<tools::group::plus<T>, Forward> a(n);`
- (3)
    - It is identical to `online_cumsum<G, Forward> a(0);`.
- (4)
    - It creates an array of type `typename G::T` and length $n$ filled with indeterminate values.
    - In $a$, addition is defined by `G`. In other words, $x + y$ is defined by `G::op(x, y)`, the additive identity is defined by `G::e()` and $-x$ is defined by `G::inv(x)`.
    - If `Forward` is `true`, you can set $a_i$ in the order $i = 0, 1, \cdots, {n - 1}$.
    - If `Forward` is `false`, you can set $a_i$ in the order $i = n - 1, n - 2, \cdots, 0$.

### Constraints
- (1), (2)
    - `tools::is_group_v<T>` does not hold.
- (3), (4)
    - `tools::is_group_v<G>` holds.
    - For all $x$ in `typename G::T`, $y$ in `typename G::T` and $z$ in `typename G::T`, `G::op(G::op(x, y), z)` $=$ `G::op(x, G::op(y, z))`.
    - For all $x$ in `typename G::T`, `G::op(G::e(), x)` $=$ `G::op(x, G::e())` $= x$.
    - For all $x$ in `typename G::T`, `G::op(G::inv(x), x)` $=$ `G::op(x, G::inv(x))` $=$ `G::e()`.

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t a.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
typename G::T& a.operator[](std::size_t i);
```

It returns the reference to $a_i$.

### Constraints
- (For reading): $0 \leq i < n$
- (For writing and `Forward` is `true`): $r^\ast \leq i < n$ where $r^\ast$ is the largest $r$ in `a.sum(l, r)` called so far or $0$ (if you have not called it so far).
- (For writing and `Forward` is `false`): $0 \leq i < l^\ast$ where $l^\ast$ is the smallest $l$ in `a.sum(l, r)` called so far or $n$ (if you have not called it so far).

### Time Complexity
- $O(1)$

## sum
```cpp
typename G::T a.sum(std::size_t l, std::size_t r);
```

It returns $\sum_{i = l}^{r - 1} a_i$.
Note that the addition is defined by `G`.

### Constraints
- $0 \leq l \leq r \leq n$
- (`Forward` is `true`): For all $0 \leq i < r$, $a_i$ is not indeterminate.
- (`Forward` is `false`): For all $l \leq i < n$, $a_i$ is not indeterminate.

### Time Complexity
- $O(1)$ amortized
