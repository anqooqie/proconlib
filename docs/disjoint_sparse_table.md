---
title: Disjoint sparse table
documentation_of: //tools/disjoint_sparse_table.hpp
---

It is a data structure which can return $\prod_{l \leq i < r} a_i$ under a given monoid in $\langle O(N \log N), O(1) \rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
disjoint_sparse_table<M> table(InputIterator begin, InputIterator end);
```

It takes a sequence $(a_1, a_2, \ldots, a_N)$, and constructs a data structure which can return $\prod_{l \leq i < r} a_i$ under a given monoid $M$.

### Constraints
- For all $a$ in `typename M::T`, $b$ in `typename M::T` and $c$ in `typename M::T`, `M::op(M::op(a, b), c)` $=$ `M::op(a, M::op(b, c))`.
- For all $a$ in `typename M::T`, `M::op(M::e(), a)` $=$ `M::op(a, M::e())` $=$ `a`.

### Time Complexity
- $O(N \log N)$

## size
```cpp
std::size_t table.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## prod
```cpp
typename M::T table.prod(std::size_t l, std::size_t r);
```

It returns $\prod_{l \leq i < r} a_i$ under the monoid $M$.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(1)$
