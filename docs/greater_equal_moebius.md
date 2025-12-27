---
title: Find $a$ from $b$ when $b_i = \sum_{j = i}^{N - 1} a_j$ holds
documentation_of: //tools/greater_equal_moebius.hpp
---

```cpp
template <std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> greater_equal_moebius(R&& b);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{i \leq j < N} a_j
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
