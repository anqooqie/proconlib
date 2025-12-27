---
title: GCD convolution
documentation_of: //tools/gcd_convolution.hpp
---

## (1)
```cpp
template <std::ranges::input_range R1, std::ranges::input_range R2>
std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> gcd_convolution(R1&& a, R2&& b, int K);
```

Given the first $N$ terms of an infinite sequence $(a_0, a_1, \ldots, a_{N - 1}, 0, 0, \ldots)$ and the first $M$ terms of an infinite sequence $(b_0, b_1, \ldots, b_{M - 1}, 0, 0, \ldots)$, it returns the first $K$ terms of the infinite sequence $(c_0, c_1, \ldots)$ where

$$\begin{align*}
c_k &= \sum_{\gcd(i, j) = k} a_i b_j
\end{align*}$$

Note that we define $\gcd(x, 0) = x$, $\gcd(0, y) = y$ and $\gcd(0, 0) = 0$ in this function.

### Constraints
- $K \geq 0$

### Time Complexity
- $O(N \log \log N + M \log \log M + K)$

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <std::ranges::input_range R1, std::ranges::input_range R2>
std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> gcd_convolution(R1&& a, R2&& b);
```

Under the assumption that $N = \|a\| = \|b\|$, it returns `tools::gcd_convolution(a, b, N)`.

### Constraints
- $\|a\| = \|b\|$

### Time Complexity
- $O(N \log \log N)$

### License
- CC0

### Author
- anqooqie
