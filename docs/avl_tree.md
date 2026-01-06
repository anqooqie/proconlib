---
title: Reversible self-balancing binary search tree based on AVL tree
documentation_of: //tools/avl_tree.hpp
---

It is the data structure for [monoids](https://en.wikipedia.org/wiki/Monoid) $(S, \cdot: S \times S \to S, e \in S)$, i.e., the algebraic structure that satisfies the following properties.

- associativity: $(a \cdot b) \cdot c$ = $a \cdot (b \cdot c)$ for all $a, b, c \in S$
- existence of the identity element: $a \cdot e$ = $e \cdot a$ = $a$ for all $a \in S$

Given an array $S$ of length $N$, it processes the following queries in $O(\log N)$ time.

- Updating an element
- Calculating the product of the elements of an interval
- Inserting an element $x \in S$ to the array
- Removing an element from the array
- Spliting the array into two subarrays
- Merging the two arrays into one array
- Reversing the elements of an interval

For simplicity, in this document, we assume that the oracles `op` and `e` work in constant time. If these oracles work in $O(T)$ time, each time complexity appear in this document is multipled by $O(T)$.

### References
- [AVL木(split/merge) - Qiita](https://qiita.com/QCFium/items/3cf26a6dc2d49ef490d7)

### License
- CC0

### Author
- anqooqie

## Constructor of buffer
```cpp
(1) avl_tree<M>::buffer buffer();
(2) avl_tree<M, Reversible>::buffer buffer();
```

- (1)
    - It is identical to `avl_tree<M, false>::buffer buffer()`.
- (2)
    - It creates an empty buffer for `tools::avl_tree<M, Reversible>`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Constructor
```cpp
(1) avl_tree<M> avl_tree(avl_tree<M>::buffer& buffer);
(2) avl_tree<M> avl_tree(avl_tree<M>::buffer& buffer, int n);
(3) avl_tree<M> avl_tree(avl_tree<M>::buffer& buffer, std::ranges::input_range auto&& v)
    requires std::assignable_from<S&, std::ranges::range_reference_t<R>>;
(4) avl_tree<M, Reversible> avl_tree(avl_tree<M, Reversible>::buffer& buffer);
(5) avl_tree<M, Reversible> avl_tree(avl_tree<M, Reversible>::buffer& buffer, int n);
(6) avl_tree<M, Reversible> avl_tree(avl_tree<M, Reversible>::buffer& buffer, std::ranges::input_range auto&& v)
    requires std::assignable_from<S&, std::ranges::range_reference_t<R>>;
```

It defines $S$ by `typename M::T`, $\mathrm{op}$ by `S M::op(S x, S y)` and $\mathrm{e}$ by `S M::e()`.
If `Reversible` is `true`, it enables `reverse` member function.

- (1)
    - It is identical to `avl_tree<M, false> avl_tree(buffer);`.
- (2)
    - It is identical to `avl_tree<M, false> avl_tree(buffer, n);`.
- (3)
    - It is identical to `avl_tree<M, false> avl_tree(buffer, v);`.
- (4)
    - It creates an empty array `a`.
- (5)
    - It creates an array `a` of length `n`. All the elements are initialized to `e()`.
- (6)
    - It creates an array `a` of length `n = v.size()`, initialized to `v`.

### Constraints
- $\forall x \in S. \forall y \in S. \forall z \in S. \mathrm{op}(\mathrm{op}(x, y), z) = \mathrm{op}(x, \mathrm{op}(y, z))$
- $\forall x \in S. \mathrm{op}(\mathrm{e}(), x) = \mathrm{op}(x, \mathrm{e}()) = x$
- $n \geq 0$

### Time Complexity
- $O(n)$

## empty
```cpp
bool avl_tree.empty();
```

It returns whether $\|a\| = 0$ or not.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## size
```cpp
int avl_tree.size();
```

It returns $\|a\|$.

### Constraints
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## set
```cpp
void avl_tree.set(int p, S x);
```

`a[p] = x`

### Constraints
- `buffer` is in its lifetime.
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## get
```cpp
S avl_tree.get(int p);
```

It returns `a[p]`.

### Constraints
- `buffer` is in its lifetime.
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
- `buffer` is in its lifetime.
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
- `buffer` is in its lifetime.

### Time Complexity
- $O(1)$

## insert
```cpp
void avl_tree.insert(int p, S x);
```

If $p < \|a\|$, it inserts $x$ immediately before `a[p]`.
If $p = \|a\|$, it inserts $x$ to the end of `a`.

### Constraints
- `buffer` is in its lifetime.
- $0 \leq p \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## erase
```cpp
void avl_tree.erase(int p);
```

It removes `a[p]`. (remaining elements will be concatenated)

### Constraints
- `buffer` is in its lifetime.
- $0 \leq p < \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## merge
```cpp
void avl_tree.merge(avl_tree<M, Reversible>&& other);
```

It appends the sequence represented by `other` to the end of `a`.
`other` gets empty after call of this function.

### Constraints
- `buffer` is in its lifetime.
- `avl_tree` and `other` shares the same buffer.

### Time Complexity
- $O(\log \|a\| + \log \|b\|)$ where $\|b\|$ is `other.size()`

## split
```cpp
std::pair<avl_tree<M, Reversible>, avl_tree<M, Reversible>> std::move(avl_tree).split(int i);
```

It splits `a` into the two sequences `a[0], a[1], ..., a[i - 1]` and `a[i], a[i + 1], ..., a[a.size() - 1]`.
`avl_tree` gets empty after call of this function.

### Constraints
- `buffer` is in its lifetime.
- $0 \leq i \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## reverse
```cpp
void avl_tree.reverse(int l, int r);
```

It reverses `a[l], a[l + 1], ..., a[r - 1]`.

### Constraints
- `<Reversible>` is `true`.
- `buffer` is in its lifetime.
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
- `buffer` is in its lifetime.
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq l \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$

## min_left
```cpp
int avl_tree.min_left<G>(int r, G g)
```
It returns an index `l` that satisfies both of the followings.

- `l = r` or `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`
- `l = 0` or `g(op(a[l - 1], a[l], ..., a[r - 1])) = false`

If `g` is monotone, this is the minimum `l` that satisfies `g(op(a[l], a[l + 1], ..., a[r - 1])) = true`.

### Constraints
- `buffer` is in its lifetime.
- The function object that takes `S` as the argument and returns `bool` should be defined.
- if `g` is called with the same argument, it returns the same value, i.e., `g` has no side effect.
- `g(e()) = true`
- $0 \leq r \leq \|a\|$

### Time Complexity
- $O(\log \|a\|)$
