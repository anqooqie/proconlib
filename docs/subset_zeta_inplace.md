---
title: In-place subset Zeta transform
documentation_of: //tools/subset_zeta_inplace.hpp
---

```cpp
template <std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void subset_zeta_inplace(R&& a);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{\substack{0 \leq j < N \\ (i~\mathrm{OR}~j) = i}} a_j
\end{align*}$$

Given $a$, it updates $a$ to $b$.

### Constraints
- $N$ is a power of two.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
