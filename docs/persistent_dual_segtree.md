---
title: Persistent dual segment tree
documentation_of: //tools/persistent_dual_segtree.hpp
---

It is the data structure for [monoids](https://en.wikipedia.org/wiki/Monoid), a set $F$ of $S \to S$ mappings that satisfies the following properties.

- $F$ contains the identity map $\mathrm{id}$, where the identity map is the map that satisfies $\mathrm{id}(x) = x$ for all $x \in S$.
- $F$ is closed under composition, i.e., $f \circ g \in F$ holds for all $f, g \in F$.

Given an array $F$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Compositing the function $f \in F$ for all the functions on an interval
- Calculating the composed function for an element

For simplicity, in this document, we assume that the oracles `composition` and `id` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
persistent_dual_segtree<FM>::buffer buffer();
```

It creates an empty buffer for `tools::persistent_dual_segtree<FM>`.
It defines $F$ by `typename FM::T`, $\mathrm{composition}$ by `F FM::op(F f, F g)` and $\mathrm{id}$ by `F FM::e()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
persistent_dual_segtree<FM> a(persistent_dual_segtree<FM>::buffer& buffer, long long l_star, long long r_star);
```

It creates an array $(a_{l^\ast}, a_{l^\ast + 1}, \ldots, a_{r^\ast - 1})$. All the elements are initialized to `id()`.
The data will be stored on `buffer`.

### Constraints
- $\forall f \in F. \forall g \in F. \forall h \in F. \mathrm{composition}(\mathrm{composition}(f, g), h) = \mathrm{composition}(f, \mathrm{composition}(g, h))$
- $\forall f \in F. \mathrm{composition}(\mathrm{id}(), f) = \mathrm{composition}(f, \mathrm{id}()) = f$
- `buffer` has not been used so far.
- $-4 \times 10^{18} \leq l^\ast \leq r^\ast \leq 4 \times 10^{18}$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## lower_bound
```cpp
long long a.lower_bound();
```

It returns $l^\ast$.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## upper_bound
```cpp
long long a.upper_bound();
```

It returns $r^\ast$.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## get
```cpp
F a.get(long long p);
```

It returns $a_p$.

### Constraints
- `buffer` is in its lifetime.
- $l^\ast \leq p < r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## apply
```cpp
(1) persistent_dual_segtree<FM> a.apply(long long p, F f);
(2) persistent_dual_segtree<FM> a.apply(long long l, long long r, F f);
```

- (1)
    - It creates $b$, a copy of $a$, assigns $\mathrm{composition}(f, b_p)$ to $b_p$ and returns $b$.
- (2)
    - It creates $b$, a copy of $a$, assigns $\mathrm{composition}(f, b_i)$ to $b_i$ for all $i$ such that $l \leq i < r$ and returns $b$.

### Constraints
- `buffer` is in its lifetime.
- (1)
    - $l^\ast \leq p < r^\ast$
- (2)
    - $l^\ast \leq l \leq r \leq r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## rollback
```cpp
persistent_dual_segtree<FM> a.rollback(persistent_dual_segtree<FM> s, long long l, long long r);
```

It creates $b$, a copy of $a$, assigns $s_i$ to $b_i$ for all $i$ such that $l \leq i < r$ and returns $b$.

### Constraints
- `buffer` is in its lifetime.
- `a` and `s` shares the same `buffer`.
- $l^\ast \leq l \leq r \leq r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$
