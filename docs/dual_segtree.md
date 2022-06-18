---
title: Dual segment tree
documentation_of: //tools/dual_segtree.hpp
---

It is a pair of a monoid $(S, \cdot, e)$ and a sequence $(a_0, a_1, \ldots, a_{n - 1})$ on $S$.
It provides the following operations.

- It can update $a_i$ to $x \cdot a_i$ for all $i$ such that $l \leq i < r$, in $O(\log n)$ time.
- It can access $a_i$ in $O(\log n)$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
dual_segtree<M> a(std::size_t n);
```

It creates a sequence $(a_0, a_1, \ldots, a_{n - 1})$ filled in `M::e()`.

### Constraints
- For all $x$ in `typename M::T`, $y$ in `typename M::T` and $z$ in `typename M::T`, `M::op(M::op(x, y), z)` $=$ `M::op(x, M::op(y, z))`.
- For all $x$ in `typename M::T`, `M::op(M::e(), x)` $=$ `M::op(x, M::e())` $=$ `x`.

### Time Complexity
- $O(n)$

## apply
```cpp
void a.apply(std::size_t l, std::size_t r, typename M::T x);
```

For all $i$ such that $l \leq i < r$, it updates $a_i$ to `M::op`$(x, a_i)$.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O(\log n)$

## get
```cpp
typename M::T a.get(std::size_t i);
```

It returns $a_i$.

### Constraints
- $0 \leq i < n$

### Time Complexity
- $O(\log n)$
