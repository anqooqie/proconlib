---
title: 2D disjoint sparse table
documentation_of: //tools/disjoint_sparse_table_2d.hpp
---


It is a data structure which can return $\prod_{d \leq i < u} \prod_{l \leq j < r} A_{i, j}$ under a given monoid for given $d, u, l, r$ in $\langle O(HW \log H \log W), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <std::ranges::input_range R>
requires std::ranges::input_range<std::ranges::range_reference_t<R>>
  && std::assignable_from<T&, std::ranges::range_value_t<std::ranges::range_reference_t<R>>>
disjoint_sparse_table_2d<M> dst(R&& A);
```

It constructs a data structure which can return $\prod_{d \leq i < u} \prod_{l \leq j < r} A_{i, j}$ under a given monoid for given $d, u, l, r$ in $\langle O(HW \log H \log W), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### Constraints
- `tools::commutative_monoid<M>` holds.
- For any $i$ and $j$ such that $0 \leq i < j < H$, $\|A_i\| = \|A_j\|$.

### Time Complexity
- $O(HW \log H \log W)$

## height
```cpp
int dst.height();
```

It returns $H$.

### Constraints
- None

### Time Complexity
- $O(1)$

## width
```cpp
int dst.width();
```

It returns $W$.

### Constraints
- None

### Time Complexity
- $O(1)$

## prod
```cpp
typename M::T dst.prod(int d, int u, int l, int r);
```

It returns $\prod_{d \leq i < u} \prod_{l \leq j < r} A_{i, j}$ under the monoid `<M>`.

### Constraints
- $0 \leq d \leq u \leq H$
- $0 \leq l \leq r \leq W$

### Time Complexity
- $O(1)$
