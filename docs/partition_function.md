---
title: Partition function $P(k, k) \pmod{M}$ for $0 \leq k \leq n$
documentation_of: //tools/partition_function.hpp
---

```cpp
template <typename M>
tools::fps<M> partition_function(int n);
```

It returns values of the partition function $P(k, k)$ on $\mathbb{Z} / M \mathbb{Z}$ for all $k$ such that $0 \leq k \leq n$.

## Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$

## Time Complexity
- $O(n \log n)$

## Algorithm
The following equation holds.

$$\begin{align*}
P(k, k) &= [x^k] \prod_{i = 0}^\infty \sum_{j = 0}^\infty x^{ij}\\
&= [x^k] \prod_{i = 0}^\infty \frac{1}{1 - x^i}\\
&= [x^k] \frac{1}{\prod_{i = 0}^\infty (1 - x^i)}\\
&= [x^k] \frac{1}{1 + \sum_{i = 1}^\infty (-1)^i \left(x^\frac{i (3i + 1)}{2} + x^\frac{i (3i - 1)}{2}\right)} & \text{(by the Euler's pentagonal number theorem)}
\end{align*}$$

Therefore, $P(k, k)$ can be calculated by inversion of the formal power series.

## License
- CC0

## Author
- anqooqie
