---
title: 2D cumulative sum
documentation_of: //tools/cumsum2d.hpp
---

It is a data structure which can return $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$ for given $r_1, r_2, c_1, c_2$ in $\langle O(HW), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
template <typename Range>
cumsum2d<T> cumsum(Range A);

(2)
template <typename Range>
cumsum2d<G> cumsum(Range A);
```

- (1)
    - It is identical to `cumsum2d<tools::groups::plus<T>> cumsum(A);`.
- (2)
    - It constructs a data structure which can return $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$ for a given $r_1, r_2, c_1, c_2$ in $\langle O(HW), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### Constraints
- `std::begin(range)` and `std::end(range)` are compilable and has the same type.
- `std::begin(*std::begin(range))` and `std::end(*std::begin(range))` are compilable and has the same type.
- The type of `*std::begin(*std::begin(range))` is `typename G::T`.
- For all $a$ in `typename G::T`, $b$ in `typename G::T` and $c$ in `typename G::T`, `G::op(G::op(a, b), c)` $=$ `G::op(a, G::op(b, c))`.
- For all $a$ in `typename G::T`, `G::op(G::e(), a)` $=$ `G::op(a, G::e())` $=$ `a`.
- For all $a$ in `typename G::T`, `G::op(G::inv(a), a)` $=$ `G::op(a, G::inv(a))` $=$ `G::e()`.

### Time Complexity
- $O(HW)$ where $H$ is the number of rows of $A$ and $W$ is the number of columns of $A$

## query
```cpp
typename G::T cumsum.query(std::size_t r1, std::size_t r2, std::size_t c1, std::size_t c2);
```

It returns $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$.

### Constraints
- $0 \leq r_1 \leq r_2 \leq H$
- $0 \leq c_1 \leq c_2 \leq W$

### Time Complexity
- $O(1)$
