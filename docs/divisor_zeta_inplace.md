---
title: In-place divisor Zeta transform
documentation_of: //tools/divisor_zeta_inplace.hpp
---

```cpp
template <std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void divisor_zeta_inplace(R&& a);

template <tools::commutative_monoid M, std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void divisor_zeta_inplace(R&& a);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \left\{\begin{array}{ll}
a_0 & (i = 0)\\
\displaystyle \sum_{\substack{1 \leq j < N \\ j \mid i}} a_j & (i > 0)
\end{array}\right.
\end{align*}$$

Given $a$, it updates $a$ to $b$.

### Constraints
- None

### Time Complexity
- $O(N \log \log N)$

### License
- CC0

### Author
- anqooqie
