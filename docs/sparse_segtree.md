---
title: Sparse segment tree
documentation_of: //tools/sparse_segtree.hpp
---

It is the data structure for [monoids](https://en.wikipedia.org/wiki/Monoid) $(S, \cdot: S \times S \to S, e \in S)$, i.e., the algebraic structure that satisfies the following properties.

- associativity: $(a \cdot b) \cdot c = a \cdot (b \cdot c)$ for all $a, b, c \in S$
- existence of the identity element: $a \cdot e = e \cdot a = a$ for all $a \in S$

Given an array $S$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Updating an element
- Calculating the product of the elements of an interval

For simplicity, in this document, we assume that the oracles `op` and `e` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) sparse_segtree<SM> a(long long l_star, long long r_star);
(2) sparse_segtree<SM> a(long long l_star, long long r_star, S x);
```

It defines $S$ by `typename SM::T`, $\mathrm{op}$ by `S SM::op(S x, S y)` and $\mathrm{e}$ by `S SM::e()`.

- (1)
    - It creates an array $(a_{l^\ast}, a_{l^\ast + 1}, \ldots, a_{r^\ast - 1})$. All the elements are initialized to `e()`.
- (2)
    - It creates an array $(a_{l^\ast}, a_{l^\ast + 1}, \ldots, a_{r^\ast - 1})$. All the elements are initialized to `x`.

### Constraints
- $\forall x \in S. \forall y \in S. \forall z \in S. \mathrm{op}(\mathrm{op}(x, y), z) = \mathrm{op}(x, \mathrm{op}(y, z))$
- $\forall x \in S. \mathrm{op}(\mathrm{e}(), x) = \mathrm{op}(x, \mathrm{e}()) = x$
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
