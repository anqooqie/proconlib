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
template <std::ranges::input_range R>
requires std::ranges::input_range<std::ranges::range_reference_t<R>>
      && std::assignable_from<T&, std::ranges::range_value_t<std::ranges::range_reference_t<R>>>
cumsum2d<T> cumsum(R&& A);

(2)
template <std::ranges::input_range R>
requires std::ranges::input_range<std::ranges::range_reference_t<R>>
      && std::assignable_from<typename G::T&, std::ranges::range_value_t<std::ranges::range_reference_t<R>>>
cumsum2d<G> cumsum(R&& A);
```

- (1)
    - It is identical to `cumsum2d<tools::groups::plus<T>> cumsum(A);`.
- (2)
    - It constructs a data structure which can return $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$ for a given $r_1, r_2, c_1, c_2$ in $\langle O(HW), O(1) \rangle$ time, where $H$ is the number of rows of $A$, and $W$ is the number of columns of $A$.

### Constraints
- (1)
    - `tools::commutative_group<T>` does not hold.
    - `tools::commutaitve_group<tools::groups::plus<T>>` holds.
- (2)
    - `tools::commutative_group<G>` holds.

### Time Complexity
- $O(HW)$ where $H$ is the number of rows of $A$ and $W$ is the number of columns of $A$

## query
```cpp
typename G::T cumsum.query(int r1, int r2, int c1, int c2);
```

It returns $\sum_{r = r_1}^{r_2 - 1} \sum_{c = c_1}^{c_2 - 1} A_{r,c}$.

### Constraints
- $0 \leq r_1 \leq r_2 \leq H$
- $0 \leq c_1 \leq c_2 \leq W$

### Time Complexity
- $O(1)$
