---
title: Divisor Möbius transform
documentation_of: //tools/divisor_moebius.hpp
---

```cpp
template <std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> multiple_moebius(R&& b);

template <tools::commutative_group G, std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> multiple_moebius(R&& b);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \left\{\begin{array}{ll}
a_0 & (i = 0)\\
\displaystyle \sum_{\substack{1 \leq j < N \\ j \mid i}} a_j & (i > 0)
\end{array}\right.
\end{align*}$$

Given $b$, it returns $a$.

### Constraints
- None

### Time Complexity
- $O(N \log \log N)$

### License
- CC0

### Author
- anqooqie
