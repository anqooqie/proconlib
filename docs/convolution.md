---
title: Arbitrary modulus convolution
documentation_of: //tools/convolution.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator result);
```

Given two sequences $(a_0, a_1, \ldots, a_{N - 1})$ and $(b_0, b_1, \ldots, b_{M - 1})$, it returns the sequence $(c_0, c_1, \ldots, c_{N + M - 2})$ where

$$\begin{align*}
c_i = \sum_{j = 0}^i a_j b_{i - j}
\end{align*}$$

## Constraints
- `std::decay_t<decltype(*a_begin)>` is `atcoder::static_modint` or `atcoder::dynamic_modint`

## Time Complexity
- $O((N + M) \log (N + M))$

## License
- CC0

## Author
- anqooqie
