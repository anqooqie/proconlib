---
title: LCM convolution
documentation_of: //tools/lcm_convolution.hpp
---

```cpp
template <typename InputIterator, typename RandomAccessIterator>
void lcm_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, RandomAccessIterator c_begin, RandomAccessIterator c_end);
```

Given two infinite sequences $(a_0, a_1, \ldots, a_{N - 1}, 0, 0, \ldots)$ and $(b_0, b_1, \ldots, b_{M - 1}, 0, 0, \ldots)$, it returns the first $K$ terms of the infinite sequence $(c_0, c_1, \ldots)$ where

$$\begin{align*}
N &= \mathrm{a\_end} - \mathrm{a\_begin}\\
M &= \mathrm{b\_end} - \mathrm{b\_begin}\\
K &= \mathrm{c\_end} - \mathrm{c\_begin}\\
c_k &= \sum_{\mathrm{lcm}(i, j) = k} a_i b_j
\end{align*}$$

Note that we define $\mathrm{lcm}(x, 0) = \mathrm{lcm}(0, y) = \mathrm{lcm}(0, 0) = 0$ in this function.

### Constraints
- `InputIterator` is an input iterator type.
- `RandomAccessIterator` is a random access iterator type.

### Time Complexity
- $O(N + M + K \log\log K)$

### License
- CC0

### Author
- anqooqie
