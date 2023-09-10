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
template <typename Range>
disjoint_sparse_table_2d<M> dst(Range A);
```

It constructs a data structure which can return $\prod_{d \leq i < u} \prod_{l \leq j < r} A_{i, j}$ under a given monoid for given $d, u, l, r$ in $\langle O(HW \log H \log W), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### Constraints
- `std::begin(range)` and `std::end(range)` are compilable and has the same type.
- `std::begin(*std::begin(range))` and `std::end(*std::begin(range))` are compilable and has the same type.
- The type of `*std::begin(*std::begin(range))` is `typename M::T`.
- For all $a$ in `typename M::T`, $b$ in `typename M::T` and $c$ in `typename M::T`, `M::op(M::op(a, b), c)` $=$ `M::op(a, M::op(b, c))`.
- For all $a$ in `typename M::T`, `M::op(M::e(), a)` $=$ `M::op(a, M::e())` $=$ `a`.
- For all $a$ in `typename M::T` and $b$ in `typename M::T`, `M::op(a, b)` $=$ `M::op(b, a)`.

### Time Complexity
- $O(HW \log H \log W)$

## height
```cpp
std::size_t dst.height();
```

It returns $H$.

### Constraints
- None

### Time Complexity
- $O(1)$

## width
```cpp
std::size_t dst.width();
```

It returns $W$.

### Constraints
- None

### Time Complexity
- $O(1)$

## prod
```cpp
typename M::T dst.prod(std::size_t d, std::size_t u, std::size_t l, std::size_t r);
```

It returns $\prod_{d \leq i < u} \prod_{l \leq j < r} A_{i, j}$ under the monoid `<M>`.

### Constraints
- $0 \leq d \leq u \leq H$
- $0 \leq l \leq r \leq W$

### Time Complexity
- $O(1)$
