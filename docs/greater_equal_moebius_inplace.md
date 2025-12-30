---
title: Update $b$ to $a$ such that $b_i = \sum_{j = i}^{N - 1} a_j$ holds
documentation_of: //tools/greater_equal_moebius_inplace.hpp
---

```cpp
template <std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void greater_equal_moebius_inplace(R&& b);

template <tools::group G, std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void greater_equal_moebius_inplace(R&& b);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{i \leq j < N} a_j
\end{align*}$$

Given $b$, it updates $b$ to $a$.

### Constraints
- None

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
