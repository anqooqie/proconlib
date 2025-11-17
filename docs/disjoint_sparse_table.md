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
disjoint_sparse_table<M> table(std::ranges::input_range auto&& a);
template <std::input_iterator F, std::sentinel_for<F> S>
disjoint_sparse_table<M> table(F first, S last);
```

It takes a sequence $(a_1, a_2, \ldots, a_N)$, and constructs a data structure which can return $\prod_{l \leq i < r} a_i$ under a given monoid $M$.

### Constraints
- `tools::monoid<M>` holds.

### Time Complexity
- $O(N \log N)$

## size
```cpp
int table.size();
```

It returns $N$.

### Constraints
- None

### Time Complexity
- $O(1)$

## prod
```cpp
typename M::T table.prod(int l, int r);
```

It returns $\prod_{l \leq i < r} a_i$ under the monoid $M$.

### Constraints
- $0 \leq l \leq r \leq N$

### Time Complexity
- $O(1)$
