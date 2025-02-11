---
title: Lazy segment tree
documentation_of: //tools/lazy_segtree.hpp
---

It is the data structure for the pair of a [monoid](https://en.wikipedia.org/wiki/Monoid) $(S, \cdot: S \times S \to S, e \in S)$ and a set $F$ of $S \to S$ mappings that satisfies the following properties.

- $F$ contains the identity map $\mathrm{id}$, where the identity map is the map that satisfies $\mathrm{id}(x) = x$ for all $x \in S$.
- $F$ is closed under composition, i.e., $f \circ g \in F$ holds for all $f, g \in F$.
- $f(x \cdot y) = f(x) \cdot f(y)$ holds for all $f \in F$ and $x, y \in S$.

Given an array $S$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Acting the map $f\in F$ (cf. $x = f(x)$) on all the elements of an interval
- Calculating the product of the elements of an interval

For simplicity, in this document, we assume that the oracles `op`, `e`, `mapping`, `composition`, and `id` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### Note
This class is just a sample implementation to serve as a basis for other extensions of segment trees with lazy propagation.
For practical purposes, use `atcoder::lazy_segtree`.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) lazy_segtree<SM, FM, mapping> a(int n);
(2) lazy_segtree<SM, FM, mapping> a(std::ranges::range v);
```

It defines $S$ by `typename SM::T`, $\mathrm{op}$ by `S SM::op(S x, S y)`, $\mathrm{e}$ by `S SM::e()`, $F$ by `typename FM::T`, $\mathrm{composition}$ by `F FM::op(F f, F g)`, $\mathrm{id}$ by `F FM::e()` and $\mathrm{mapping}$ by `S mapping(F f, S x)`.

- (1)
    - It creates an array `a` of length `n`. All the elements are initialized to `e()`.
- (2)
    - It creates an array `a` of length `n = v.size()`, initialized to `v`.

### Constraints
- $\forall x \in S. \forall y \in S. \forall z \in S. \mathrm{op}(\mathrm{op}(x, y), z) = \mathrm{op}(x, \mathrm{op}(y, z))$
- $\forall x \in S. \mathrm{op}(\mathrm{e}(), x) = \mathrm{op}(x, \mathrm{e}()) = x$
- $\forall f \in F. \forall g \in F. \forall h \in F. \mathrm{composition}(\mathrm{composition}(f, g), h) = \mathrm{composition}(f, \mathrm{composition}(g, h))$
- $\forall f \in F. \mathrm{composition}(\mathrm{id}(), f) = \mathrm{composition}(f, \mathrm{id}()) = f$
- $\forall f \in F. \forall x \in S. \forall y \in S. \mathrm{mapping}(f, \mathrm{op}(x, y)) = \mathrm{op}(f(x), f(y))$
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

## set
```cpp
void a.set(int p, S x);
```

`a[p] = x`

### Constraints
- $0 \leq p < n$

### Time Complexity
- $O(\log n)$

## get
```cpp
S a.get(int p);
```

It returns `a[p]`.

### Constraints
- $0 \leq p < n$

### Time Complexity
- $O(\log n)$

## prod
```cpp
S a.prod(int l, int r);
```

It returns `op(a[l], ..., a[r - 1])`, assuming the properties of the monoid.
It returns `e()` if $l = r$.

### Constraints
- $0 \leq l \leq r \leq n$

### Time Complexity
- $O(\log n)$

## all_prod
```cpp
S a.all_prod();
```

It returns `op(a[0], ..., a[n - 1])`, assuming the properties of the monoid.
It returns `e()` if $n = 0$.

### Constraints
- None

### Time Complexity
- $O(1)$

## apply
```cpp
(1) void a.apply(int p, F f);
(2) void a.apply(int l, int r, F f);
```

- (1)
    - It applies `a[p] = f(a[p])`.
- (2)
    - It applies `a[i] = f(a[i])` for all `i = l..r-1`.

### Constraints
- (1)
    - $0 \leq p < n$
- (2)
    - $0 \leq l \leq r \leq n$

### Time Complexity
- $O(\log n)$

## max_right
```cpp
int a.max_right<G>(int l, G g)
```
It returns an index `r` that satisfies both of the followings.

- `r = l` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = a.size()` or `g(op(a[l], a[l + 1], ..., a[r])) = false`

If `g` is monotone, this is the maximum `r` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq l \leq n$

### Time Complexity
- $O(\log n)$

## min_left
```cpp
int a.min_left<G>(int l, G g)
```
It returns an index `l` that satisfies both of the followings.

- `l = r` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` or `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

If `g` is monotone, this is the minimum `l` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq r \leq n$

### Time Complexity
- $O(\log n)$
