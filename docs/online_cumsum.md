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
(1) online_cumsum<T, Forward = true> a(std::size_t n = 0);
(2) online_cumsum<M, Forward = true> a(std::size_t n = 0);
(3) online_cumsum<G, Forward = true> a(std::size_t n = 0);
```

- (1)
    - It is identical to `online_cumsum<tools::group::plus<T>, Forward> a(n);`
- (2)
    - Given a monoid `M`, it creates an array of type `typename M::T` and length $n$ filled with indeterminate values.
    - In $a$, multiplication is defined by `M`. In other words, $x \cdot y$ is defined by `M::op(x, y)` and the identity is defined by `M::e()`.
    - If `Forward` is `true`, you can set $a_i$ in the order $i = 0, 1, \ldots, {n - 1}$.
    - If `Forward` is `false`, you can set $a_i$ in the order $i = n - 1, n - 2, \ldots, 0$.
- (3)
    - Given a group `G`, it creates an array of type `typename G::T` and length $n$ filled with indeterminate values.
    - In $a$, multiplication is defined by `G`. In other words, $x \cdot y$ is defined by `G::op(x, y)`, the identity is defined by `G::e()` and $x^{-1}$ is defined by `G::inv(x)`.
    - If `Forward` is `true`, you can set $a_i$ in the order $i = 0, 1, \ldots, {n - 1}$.
    - If `Forward` is `false`, you can set $a_i$ in the order $i = n - 1, n - 2, \ldots, 0$.

### Constraints
- (1)
    - `tools::is_monoid_v<T>` does not hold.
- (2)
    - `tools::is_monoid_v<M>` holds, but `tools::is_group_v<M>` does not hold.
    - For all $x$ in `typename M::T`, $y$ in `typename M::T` and $z$ in `typename M::T`, `M::op(M::op(x, y), z)` $=$ `M::op(x, M::op(y, z))`.
    - For all $x$ in `typename M::T`, `M::op(M::e(), x)` $=$ `M::op(x, M::e())` $= x$.
- (3)
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
(see below) a.operator[](std::size_t i);
```

It returns the reference to $a_i$.

The return type is as follows.

- (`a` is constructed by the constructor (1)): `T&`
- (`a` is constructed by the constructor (2)): `typename M::T&`
- (`a` is constructed by the constructor (3)): `typename G::T&`

### Constraints
- (Read):
    - $0 \leq i < n$
    - $a_i$ is not indeterminate.
- (Write):
    - (`Forward` is `true`): $r^\ast \leq i < n$ where $r^\ast$ is the largest $r$ in `a.sum(l, r)` called so far or $0$ (if you have not called it so far).
    - (`Forward` is `false`): $0 \leq i < l^\ast$ where $l^\ast$ is the smallest $l$ in `a.sum(l, r)` called so far or $n$ (if you have not called it so far).

### Time Complexity
- $O(1)$

## prod
```cpp
(see below) a.prod(std::size_t l, std::size_t r);
```

It returns $a_l \cdot a_{l + 1} \cdot \ldots \cdot a_{r - 1}$.
Note that the multiplication is defined by the template parameter.

The return type is as follows.

- (`a` is constructed by the constructor (1)): `T`
- (`a` is constructed by the constructor (2)): `typename M::T`
- (`a` is constructed by the constructor (3)): `typename G::T`

### Constraints
- $0 \leq l \leq r \leq n$
- (`Forward` is `true`): For all $0 \leq i < r$, $a_i$ is not indeterminate.
- (`Forward` is `false`): For all $l \leq i < n$, $a_i$ is not indeterminate.
- (`a` is constructed by the constructor (2) and `Forward` is `true`): $l = 0$
- (`a` is constructed by the constructor (2) and `Forward` is `false`): $r = n$

### Time Complexity
- $O(1)$ amortized

## sum
```cpp
T a.sum(std::size_t l, std::size_t r);
```

It is an alias for `a.prod(l, r)`.

### Constraints
- `a` is constructed by the constructor (1).
- $0 \leq l \leq r \leq n$
- (`Forward` is `true`): For all $0 \leq i < r$, $a_i$ is not indeterminate.
- (`Forward` is `false`): For all $l \leq i < n$, $a_i$ is not indeterminate.

### Time Complexity
- $O(1)$ amortized
