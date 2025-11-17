---
title: Online difference array
documentation_of: //tools/online_imos.hpp
---

It is an array with an auxiliary difference array to perform range update queries, but allows you to construct the final array by online.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) online_imos<T, Forward = true> a(int n = 0);
(2) online_imos<M, Forward = true> a(int n = 0);
(3) online_imos<G, Forward = true> a(int n = 0);
```

- (1)
    - It is identical to `online_imos<tools::groups::plus<T>, Forward> a(n);`
- (2)
    - Given a commutative monoid `M`, it creates an array of type `typename M::T` and length $n$ filled with `M::e()`.
    - In $a$, multiplication is defined by `M`. In other words, $x \cdot y$ is defined by `M::op(x, y)` and the identity is defined by `M::e()`.
    - If `Forward` is `true`, you can get $a_i$ in the order $i = 0, 1, \ldots, {n - 1}$.
    - If `Forward` is `false`, you can get $a_i$ in the order $i = n - 1, n - 2, \ldots, 0$.
    - Once $a_i$ is got, it is fixed and cannot be updated thereafter.
- (3)
    - Given a commutative group `G`, it creates an array of type `typename G::T` and length $n$ filled with `G::e()`.
    - In $a$, multiplication is defined by `G`. In other words, $x \cdot y$ is defined by `G::op(x, y)`, the identity is defined by `G::e()` and $x^{-1}$ is defined by `G::inv(x)`.
    - If `Forward` is `true`, you can get $a_i$ in the order $i = 0, 1, \ldots, {n - 1}$.
    - If `Forward` is `false`, you can get $a_i$ in the order $i = n - 1, n - 2, \ldots, 0$.
    - Once $a_i$ is got, it is fixed and cannot be updated thereafter.

### Constraints
- (1)
    - `tools::commutative_monoid<T>` does not hold.
- (2)
    - `tools::commutaitve_monoid<M>` holds, but `tools::commutative_group<M>` does not hold.
- (3)
    - `tools::commutative_group<G>` holds.
- $n \geq 0$

### Time Complexity
- $O(n)$

## size
```cpp
int a.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator[]
```cpp
(see below) a.operator[](int i);
```

It returns the const reference to $a_i$.

The return type is as follows.

- (`a` is constructed by the constructor (1)): `const T&`
- (`a` is constructed by the constructor (2)): `const typename M::T&`
- (`a` is constructed by the constructor (3)): `const typename G::T&`

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(1)$ amortized

## apply
```cpp
void a.apply(int l, int r, (see below) x);
```

It updates $a_i$ to $x \cdot a_i$ for $i$ such that $l \leq i < r$.
Note that the multiplication is defined by the template parameter.

The type of $x$ is as follows.

- (`a` is constructed by the constructor (1)): `T`
- (`a` is constructed by the constructor (2)): `typename M::T`
- (`a` is constructed by the constructor (3)): `typename G::T`

### Constraints
- $0 \leq l \leq r \leq n$
- (`Forward` is `true`): $i^\ast < l$ where $i^\ast$ is the largest $i$ in `a[i]` called so far or $-1$ (if you have not called it so far).
- (`Forward` is `false`): $r \leq i^\ast$ where $i^\ast$ is the smallest $i$ in `a[i]` called so far or $n$ (if you have not called it so far).
- (`a` is constructed by the constructor (2) and `Forward` is `true`): $r = n$
- (`a` is constructed by the constructor (2) and `Forward` is `false`): $l = 0$

### Time Complexity
- $O(1)$

## add
```cpp
void a.add(int l, int r, (see below) x);
```

It is an alias for `a.apply(l, r, x)`.

The type of $x$ is as follows.

- (`a` is constructed by the constructor (1)): `T`
- (`a` is constructed by the constructor (2)): `typename M::T`
- (`a` is constructed by the constructor (3)): `typename G::T`

### Constraints
- `a` is constructed by the constructor (1).
- $0 \leq l \leq r \leq n$
- (`Forward` is `true`): $i^\ast < l$ where $i^\ast$ is the largest $i$ in `a[i]` called so far or $-1$ (if you have not called it so far).
- (`Forward` is `false`): $r \leq i^\ast$ where $i^\ast$ is the smallest $i$ in `a[i]` called so far or $n$ (if you have not called it so far).

### Time Complexity
- $O(1)$
