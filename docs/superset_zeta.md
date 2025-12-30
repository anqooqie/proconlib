---
title: Superset Zeta transform
documentation_of: //tools/superset_zeta.hpp
---

```cpp
template <std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> superset_zeta(R&& a);

template <tools::commutative_monoid M, std::ranges::input_range R>
std::vector<std::ranges::range_value_t<R>> superset_zeta(R&& a);
```

Assume that the following relationship holds between $a = (a_0, a_1, \ldots, a_{N - 1})$ and $b = (b_0, b_1, \ldots, b_{N - 1})$.

$$\begin{align*}
b_i &= \sum_{\substack{0 \leq j < N \\ (i~\mathrm{AND}~j) = i}} a_j
\end{align*}$$

Given $a$, it returns $b$.

### Constraints
- $N$ is a power of two.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
