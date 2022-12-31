---
title: Convolution
documentation_of: //tools/convolution.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator result);
```

Let $R$ be `std::decay_t<decltype(*std::declval<InputIterator>())>`.
Given two sequences $(a_0, a_1, \ldots, a_{N - 1})$ and $(b_0, b_1, \ldots, b_{M - 1})$ on a commutative ring $R$, it returns the sequence $(c_0, c_1, \ldots, c_{N + M - 2})$ on $R$ where

$$\begin{align*}
c_i = \sum_{j = 0}^i a_j b_{i - j}
\end{align*}$$

It returns an empty sequence if at least one of $a$ and $b$ are empty.

## Constraints
- $R$ is a commutative ring.
- $R$ is assignable to `*result`.
- If $R$ is `atcoder::static_modint` or `atcoder::dynamic_modint`, $N + M \leq 2^{25} + 1 = 33554433$.
- If $R$ is a built-in integer type, $N + M \leq 2^{24} + 1 = 16777217$ and all the elements of the array are in $R$ after convolution.

## Time Complexity
- ($R$ is `atcoder::static_modint`): $O((N + M) \log (N + M))$
- ($R$ is `atcoder::dynamic_modint`): $O((N + M) \log (N + M))$
- ($R$ is `float`): $O((N + M) \log (N + M))$
- ($R$ is `double`): $O((N + M) \log (N + M))$
- ($R$ is `long double`): $O((N + M) \log (N + M))$
- ($R$ is `std::complex<float>`): $O((N + M) \log (N + M))$
- ($R$ is `std::complex<double>`): $O((N + M) \log (N + M))$
- ($R$ is `std::complex<lond double>`): $O((N + M) \log (N + M))$
- ($R$ is a built-in integer type): $O((N + M) \log (N + M))$
- (otherwise): $O(NM)$

## License
- CC0

## Author
- anqooqie
