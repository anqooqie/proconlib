---
title: Lazy reversible self-balancing binary search tree based on AVL tree
documentation_of: //tools/avl_tree.hpp
---

It is the data structure for the pair of a [monoid](https://en.wikipedia.org/wiki/Monoid) $(S, \cdot: S \times S \to S, e \in S)$ and a set $F$ of $S \to S$ mappings that satisfies the following properties.

- $F$ contains the identity map $\mathrm{id}$, where the identity map is the map that satisfies $\mathrm{id}(x) = x$ for all $x \in S$.
- $F$ is closed under composition, i.e., $f \circ g \in F$ holds for all $f, g \in F$.
- $f(x \cdot y) = f(x) \cdot f(y)$ holds for all $f \in F$ and $x, y \in S$.

Given an array $S$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Acting the map $f\in F$ (cf. $x = f(x)$) on all the elements of an interval
- Calculating the product of the elements of an interval
- Inserting an element $x \in S$ to the array
- Removing an element from the array
- Spliting the array into the two subarrays
- Merging the two arrays into one array
- Reversing the elements of an interval

For simplicity, in this document, we assume that the oracles `op`, `e`, `mapping`, `composition`, and `id` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### References
- [AVL木(split/merge) - Qiita](https://qiita.com/QCFium/items/3cf26a6dc2d49ef490d7)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) avl_tree<SM, FM, mapping> avl_tree();
(2) avl_tree<SM, FM, mapping> avl_tree(int n);
(3) avl_tree<SM, FM, mapping> avl_tree(std::vector<S> v);
```

It defines $S$ as `typename SM::T`, $\mathrm{op}$ as `S SM::op(S x, S y)`, $\mathrm{e}$ as `S SM::e()`, $F$ as `typename FM::T`, $\mathrm{composition}$ as `F FM::op(F f, F g)`, $\mathrm{id}$ as `F FM::e()` and $\mathrm{mapping}$ as `S mapping(F f, S x)`.

- (1)
    - It creates an empty array `a`.
- (2)
    - It creates an array `a` of length `n`. All the elements are initialized to `e()`.
- (3)
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

## empty
```cpp
bool avl_tree.empty();
```

It returns whether $\|a\| = 0$ or not.

### Constraints
- None

### Time Complexity
- $O(1)$

## size
```cpp
int avl_tree.size();
```

It returns $\|a\|$.

### Constraints
- None

### Time Complexity
- $O(1)$

## set
```cpp
void avl_tree.set(int p, S x);
```

`a[p] = x`

### Constraints
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## get
```cpp
S avl_tree.get(int p);
```

It returns `a[p]`.

### Constraints
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## prod
```cpp
S avl_tree.prod(int l, int r);
```

It returns `op(a[l], ..., a[r - 1])`, assuming the properties of the monoid.
It returns `e()` if $l = r$.

### Constraints
- $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## all_prod
```cpp
S avl_tree.all_prod();
```

It returns `op(a[0], ..., a[a.size() - 1])`, assuming the properties of the monoid.
It returns `e()` if $\|a\| = 0$.

### Constraints
- None

### Time Complexity
- $O(1)$

## apply
```cpp
(1) void avl_tree.apply(int p, F f);
(2) void avl_tree.apply(int l, int r, F f);
```

- (1)
    - It applies `a[p] = f(a[p])`.
- (2)
    - It applies `a[i] = f(a[i])` for all `i = l..r-1`.

### Constraints
- (1)
    - $0 \leq p < \|a\|$
- (2)
    - $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## insert
```cpp
void avl_tree.insert(int p, S x);
```

If $p < \|a\|$, it inserts $x$ immediately before `a[i]`.
If $p = \|a\|$, it inserts $x$ to the end of `a`.

### Constraints
- $0 \leq p \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## erase
```cpp
void avl_tree.erase(int p);
```

It removes `a[i]`. (remaining elements will be concatenated)

### Constraints
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## merge
```cpp
void avl_tree.merge(avl_tree<SM, FM, mapping> other);
```

It appends the sequence represented by `other` to the end of `a`.
`other` gets unavailable after call of this function.

### Constraints
- None

### Time Complexity
- $O(\log \|a\| + \log \|b\|)$ where $\|b\|$ is `other.size()`

## split
```cpp
std::pair<avl_tree<SM, FM, mapping>, avl_tree<SM, FM, mapping>> avl_tree.split(int i);
```

It splits `a` into the two sequences `a[0], a[1], ..., a[i - 1]` and `a[i], a[i + 1], ..., a[a.size() - 1]`.

### Constraints
- $0 \leq i \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## reverse
```cpp
void avl_tree.reverse(int l, int r);
```

It reverses `a[l], a[l + 1], ..., a[r - 1]`.

### Constraints
- $0 \leq l \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## max_right
```cpp
int avl_tree.max_right<G>(int l, G g)
```
It returns an index `r` that satisfies both of the followings.

- `r = l` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `r = a.size()` or `g(op(a[l], a[l + 1], ..., a[r])) = false`

If `g` is monotone, this is the maximum `r` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq l \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## min_left
```cpp
int avl_tree.min_left<G>(int l, G g)
```
It returns an index `l` that satisfies both of the followings.

- `l = r` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` or `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

If `g` is monotone, this is the minimum `l` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$
