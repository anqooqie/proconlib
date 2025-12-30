---
title: Find $b$ from $a$ when $b_i = \sum_{j = 0}^i a_j$ holds
documentation_of: //tools/less_equal_zeta.hpp
---

```cpp
template <std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> less_equal_zeta(R&& a);

template <tools::monoid M, std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> less_equal_zeta(R&& a);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{0 \leq j \leq i} a_j
\end{align*}$$

Given $a$, it returns $b$.

### Constraints
- None

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
