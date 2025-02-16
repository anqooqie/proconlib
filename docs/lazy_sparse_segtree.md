---
title: Sparse segment tree with lazy propagation
documentation_of: //tools/lazy_sparse_segtree.hpp
---

It is the data structure for the pair of a [monoid](https://en.wikipedia.org/wiki/Monoid) $(S, \cdot: S \times S \to S, e \in S)$ and a set $F$ of $S \to S$ mappings that satisfies the following properties.

- $F$ contains the identity map $\mathrm{id}$, where the identity map is the map that satisfies $\mathrm{id}(x) = x$ for all $x \in S$.
- $F$ is closed under composition, i.e., $f \circ g \in F$ holds for all $f, g \in F$.
- $f(x \cdot y) = f(x) \cdot f(y)$ holds for all $f \in F$ and $x, y \in S$.

Given an array $S$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Acting the map $f\in F$ (cf. $x = f(x)$) on all the elements of an interval
- Calculating the product of the elements of an interval

For simplicity, in this document, we assume that the oracles `op`, `e`, `mapping`, `composition`, and `id` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) lazy_sparse_segtree<SM, FM, mapping> a(long long l_star, long long r_star);
(2) lazy_sparse_segtree<SM, FM, mapping> a(long long l_star, long long r_star, S x);
```

It defines $S$ by `typename SM::T`, $\mathrm{op}$ by `S SM::op(S x, S y)`, $\mathrm{e}$ by `S SM::e()`, $F$ by `typename FM::T`, $\mathrm{composition}$ by `F FM::op(F f, F g)`, $\mathrm{id}$ by `F FM::e()` and $\mathrm{mapping}$ by `S mapping(F f, S x)`.

- (1)
    - It creates an array $(a_{l^\ast}, a_{l^\ast + 1}, \ldots, a_{r^\ast - 1})$. All the elements are initialized to `e()`.
- (2)
    - It creates an array $(a_{l^\ast}, a_{l^\ast + 1}, \ldots, a_{r^\ast - 1})$. All the elements are initialized to `x`.

### Constraints
- $\forall x \in S. \forall y \in S. \forall z \in S. \mathrm{op}(\mathrm{op}(x, y), z) = \mathrm{op}(x, \mathrm{op}(y, z))$
- $\forall x \in S. \mathrm{op}(\mathrm{e}(), x) = \mathrm{op}(x, \mathrm{e}()) = x$
- $\forall f \in F. \forall g \in F. \forall h \in F. \mathrm{composition}(\mathrm{composition}(f, g), h) = \mathrm{composition}(f, \mathrm{composition}(g, h))$
- $\forall f \in F. \mathrm{composition}(\mathrm{id}(), f) = \mathrm{composition}(f, \mathrm{id}()) = f$
- $\forall f \in F. \forall x \in S. \forall y \in S. \mathrm{mapping}(f, \mathrm{op}(x, y)) = \mathrm{op}(f(x), f(y))$
- $-4 \times 10^{18} \leq l^\ast \leq r^\ast \leq 4 \times 10^{18}$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## lower_bound
```cpp
long long a.lower_bound();
```

It returns $l^\ast$.

### Constraints
- None

### Time Complexity
- $O(1)$

## upper_bound
```cpp
long long a.upper_bound();
```

It returns $r^\ast$.

### Constraints
- None

### Time Complexity
- $O(1)$

## set
```cpp
void a.set(long long p, S x);
```

It assigns $x$ to $a_p$.

### Constraints
- $l^\ast \leq p < r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## get
```cpp
S a.get(long long p);
```

It returns $a_p$.

### Constraints
- $l^\ast \leq p < r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## prod
```cpp
S a.prod(long long l, long long r);
```

It returns $\mathrm{op}(a_l, \ldots, a_{r - 1})$, assuming the properties of the monoid.
It returns $\mathrm{e}()$ if $l = r$.

### Constraints
- $l^\ast \leq l \leq r \leq r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## all_prod
```cpp
S a.all_prod();
```

It returns $\mathrm{op}(a_{l^\ast}, \ldots, a_{r^\ast - 1})$, assuming the properties of the monoid.
It returns $\mathrm{e}()$ if $l^\ast = r^\ast$.

### Constraints
- None

### Time Complexity
- $O(1)$

## apply
```cpp
(1) void a.apply(long long p, F f);
(2) void a.apply(long long l, long long r, F f);
```

- (1)
    - It assigns $\mathrm{mapping}(f, a_p)$ to $a_p$.
- (2)
    - It assigns $\mathrm{mapping}(f, a_i)$ to $a_i$ for all $i$ such that $l \leq i < r$.

### Constraints
- (1)
    - $l^\ast \leq p < r^\ast$
- (2)
    - $l^\ast \leq l \leq r \leq r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## max_right
```cpp
long long a.max_right<G>(long long l, G g)
```
It returns an index $r$ that satisfies both of the followings.

- $r = l$ or $g(\mathrm{op}(a_l, a_{l + 1}, \ldots, a_{r - 1})) = \top$
- $r = r^\ast$ or $g(\mathrm{op}(a_l, a_{l + 1}, \ldots, a_r)) = \bot$

If $g$ is monotone, this is the maximum $r$ that satisfies $g(\mathrm{op}(a_l, a_{l + 1}, \ldots, a_{r - 1})) = \top$.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- $g(\mathrm{e}()) = \top$
- $l^\ast \leq l \leq r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## min_left
```cpp
long long a.min_left<G>(long long r, G g)
```
It returns an index $l$ that satisfies both of the followings.

- $l = r$ or $g(\mathrm{op}(a_l, a_{l + 1}, \ldots, a_{r - 1})) = \top$
- $l = l^\ast$ or $g(\mathrm{op}(a_{l - 1}, a_{l + 1}, \ldots, a_{r - 1})) = \bot$

If $g$ is monotone, this is the minimum $l$ that satisfies $g(\mathrm{op}(a_l, a_{l + 1}, \ldots, a_{r - 1})) = \top$.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- $g(\mathrm{e}()) = \top$
- $l^\ast \leq r \leq r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$
