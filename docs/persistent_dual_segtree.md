---
title: Persistent dual segment tree
documentation_of: //tools/persistent_dual_segtree.hpp
---

It is a pair of a monoid $(S, \cdot, e)$ and a sequence $(a_0, a_1, \ldots, a_{n - 1})$ on $S$.
It provides the following operations.

- It can return a new pair of the monoid $(S, \cdot, e)$ and a new sequence $(b_0, b_1, \ldots, b_{n - 1})$ such that $b_i = x \cdot a_i$ if $l \leq i < r$ and $b_i = a_i$ if $i < l$ or $r \leq i$, in $O(\log n)$ time.
- It can access $a_i$ in $O(\log n)$ time.

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
persistent_dual_segtree<M>::buffer buffer();
```

It creates an empty buffer for `tools::persistent_dual_segtree<M>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
persistent_dual_segtree<M> a(persistent_dual_segtree<M>::buffer& buffer, std::size_t n);
```

It creates a sequence $(a_0, a_1, \ldots, a_{n - 1})$ filled in `M::e()`.
The data will be stored on `buffer`.

### Constraints
- For all $x$ in `typename M::T`, $y$ in `typename M::T` and $z$ in `typename M::T`, `M::op(M::op(x, y), z)` $=$ `M::op(x, M::op(y, z))`.
- For all $x$ in `typename M::T`, `M::op(M::e(), x)` $=$ `M::op(x, M::e())` $=$ `x`.

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

## apply
```cpp
persistent_dual_segtree<M> a.apply(std::size_t l, std::size_t r, typename M::T x);
```

It returns a new sequence $(b_0, b_1, \ldots, b_{n - 1})$ which satisfies the following.

$$\begin{align*}
b_i &= \left\{\begin{array}{ll}
\mathrm{M::op}(x, a_i) & \text{(if $l \leq i < r$)}\\
a_i & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

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
