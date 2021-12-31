---
title: Arbitrary modulus convolution
documentation_of: //tools/convolution.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator result);
```

Given two sequences $(a_0, a_1, \ldots, a_{N - 1})$ and $(b_0, b_1, \ldots, b_{M - 1})$ under $\mathbb{Z}/m\mathbb{Z}$, it returns the sequence $(c_0, c_1, \ldots, c_{N + M - 2})$ under $\mathbb{Z}/m\mathbb{Z}$ where

$$\begin{align*}
c_i = \sum_{j = 0}^i a_j b_{i - j}
\end{align*}$$

## Constraints
- `std::decay_t<decltype(*a_begin)>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $N + M - 1 \leq 2^{23} = 8388608$ if $m = 998244353$
- $N + M - 1 \leq 2^{25} = 33554432$ if $m = 167772161$
- $N + M - 1 \leq 2^{26} = 67108864$ if $m = 469762049$
- $N + M - 1 \leq 2^{24} = 16777216$ if $m \notin \\{998244353, 167772161, 469762049\\}$

## Time Complexity
- $O((N + M) \log (N + M))$

## License
- CC0

## Author
- anqooqie
