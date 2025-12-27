---
title: Bitwise AND convolution
documentation_of: //tools/and_convolution.hpp
---

```cpp
template <std::ranges::input_range R1, std::ranges::input_range R2>
std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> and_convolution(R1&& a, R2&& b);
```

Given two sequences $(a_0, a_1, \ldots, a_{N - 1})$ and $(b_0, b_1, \ldots, b_{N - 1})$, it returns the sequence $(c_0, c_1, \ldots, c_{N - 1})$ where

$$\begin{align*}
c_k &= \sum_{(i~\mathrm{AND}~j) = k} a_i b_j
\end{align*}$$

### Constraints
- $\|a\| = \|b\|$
- $N$ is a power of two.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
