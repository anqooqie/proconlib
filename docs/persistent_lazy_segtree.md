---
title: Persistent segment tree with lazy propagation
documentation_of: //tools/persistent_lazy_segtree.hpp
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

## Constructor of buffer
```cpp
persistent_lazy_segtree<SM, FM, mapping>::buffer buffer();
```

It creates an empty buffer for `tools::persistent_lazy_segtree<SM, FM, mapping>`.
It defines $S$ by `typename SM::T`, $\mathrm{op}$ by `S SM::op(S x, S y)`, $\mathrm{e}$ by `S SM::e()`, $F$ by `typename FM::T`, $\mathrm{composition}$ by `F FM::op(F f, F g)`, $\mathrm{id}$ by `F FM::e()` and $\mathrm{mapping}$ by `S mapping(F f, S x)`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
(1) persistent_lazy_segtree<SM, FM, mapping> a(persistent_lazy_segtree<SM, FM, mapping>::buffer& buffer, long long l_star, long long r_star);
(2) persistent_lazy_segtree<SM, FM, mapping> a(persistent_lazy_segtree<SM, FM, mapping>::buffer& buffer, long long l_star, long long r_star, S x);
(3) persistent_lazy_segtree<SM, FM, mapping> a(persistent_lazy_segtree<SM, FM, mapping>::buffer& buffer, std::ranges::range v);
```

- (1)
    - It creates an array $(a_{l^\ast}, a_{l^\ast + 1}, \ldots, a_{r^\ast - 1})$. All the elements are initialized to `e()`.
- (2)
    - It creates an array $(a_{l^\ast}, a_{l^\ast + 1}, \ldots, a_{r^\ast - 1})$. All the elements are initialized to `x`.
- (3)
    - It creates an array $(a_0, a_1, \ldots, a_{\|v\| - 1})$, initialized to `v`.

The data will be stored on `buffer`.

### Constraints
- $\forall x \in S. \forall y \in S. \forall z \in S. \mathrm{op}(\mathrm{op}(x, y), z) = \mathrm{op}(x, \mathrm{op}(y, z))$
- $\forall x \in S. \mathrm{op}(\mathrm{e}(), x) = \mathrm{op}(x, \mathrm{e}()) = x$
- $\forall f \in F. \forall g \in F. \forall h \in F. \mathrm{composition}(\mathrm{composition}(f, g), h) = \mathrm{composition}(f, \mathrm{composition}(g, h))$
- $\forall f \in F. \mathrm{composition}(\mathrm{id}(), f) = \mathrm{composition}(f, \mathrm{id}()) = f$
- $\forall f \in F. \forall x \in S. \forall y \in S. \mathrm{mapping}(f, \mathrm{op}(x, y)) = \mathrm{op}(f(x), f(y))$
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

## set
```cpp
persistent_lazy_segtree<SM, FM, mapping> a.set(long long p, S x);
```

It creates $b$, a copy of $a$, assigns $x$ to $b_p$ and returns $b$.

### Constraints
- `buffer` is in its lifetime.
- $l^\ast \leq p < r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$

## get
```cpp
S a.get(long long p);
```

It returns $a_p$.

### Constraints
- `buffer` is in its lifetime.
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
- `buffer` is in its lifetime.
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
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## apply
```cpp
(1) persistent_lazy_segtree<SM, FM, mapping> a.apply(long long p, F f);
(2) persistent_lazy_segtree<SM, FM, mapping> a.apply(long long l, long long r, F f);
```

- (1)
    - It creates $b$, a copy of $a$, assigns $\mathrm{mapping}(f, b_p)$ to $b_p$ and returns $b$.
- (2)
    - It creates $b$, a copy of $a$, assigns $\mathrm{mapping}(f, b_i)$ to $b_i$ for all $i$ such that $l \leq i < r$ and returns $b$.

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
persistent_lazy_segtree<SM, FM, mapping> a.rollback(persistent_lazy_segtree<SM, FM, mapping> s, long long l, long long r);
```

It creates $b$, a copy of $a$, assigns $\mathrm{mapping}(f, s_i)$ to $b_i$ for all $i$ such that $l \leq i < r$ and returns $b$.

### Constraints
- `buffer` is in its lifetime.
- `a` and `s` shares the same `buffer`.
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
- `buffer` is in its lifetime.
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
- `buffer` is in its lifetime.
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- $g(\mathrm{e}()) = \top$
- $l^\ast \leq r \leq r^\ast$

### Time Complexity
- $O(\log (r^\ast - l^\ast))$
