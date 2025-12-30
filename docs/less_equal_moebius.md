---
title: Find $a$ from $b$ when $b_i = \sum_{j = 0}^i a_j$ holds
documentation_of: //tools/less_equal_moebius.hpp
---

```cpp
template <std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> less_equal_moebius(R&& b);

template <tools::group G, std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> less_equal_moebius(R&& b);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{0 \leq j \leq i} a_j
\end{align*}$$

Given $b$, it returns $a$.

### Constraints
- None

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
