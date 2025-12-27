---
title: Update $a$ to $b$ such that $b_i = \sum_{j = 0}^i a_j$ holds
documentation_of: //tools/less_equal_zeta_inplace.hpp
---

```cpp
template <std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void less_equal_zeta_inplace(R&& a);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{0 \leq j \leq i} a_j
\end{align*}$$

Given $a$, it updates $a$ to $b$.

### Constraints
- None

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
