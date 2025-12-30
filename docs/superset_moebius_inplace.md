---
title: In-place superset Möbius transform
documentation_of: //tools/superset_moebius_inplace.hpp
---

```cpp
template <std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void superset_moebius_inplace(R&& b);

template <tools::commutative_group G, std::ranges::random_access_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
void superset_moebius_inplace(R&& b);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{\substack{0 \leq j < N \\ (i~\mathrm{AND}~j) = i}} a_j
\end{align*}$$

Given $b$, it updates $b$ to $a$.

### Constraints
- $N$ is a power of two.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
