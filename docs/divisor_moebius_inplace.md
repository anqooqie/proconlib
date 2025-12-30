---
title: In-place divisor Möbius transform
documentation_of: //tools/divisor_moebius_inplace.hpp
---

```cpp
template <std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void divisor_moebius_inplace(R&& b);

template <tools::commutative_group G, std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void divisor_moebius_inplace(R&& b);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \left\{\begin{array}{ll}
a_0 & (i = 0)\\
\displaystyle \sum_{\substack{1 \leq j < N \\ j \mid i}} a_j & (i > 0)
\end{array}\right.
\end{align*}$$

Given $b$, it updates $b$ to $a$.

### Constraints
- None

### Time Complexity
- $O(N \log \log N)$

### License
- CC0

### Author
- anqooqie
