---
title: Stirling numbers of the second kind $S(n, k) \pmod{P}$ for $0 \leq k \leq n$
documentation_of: //tools/stirling_2nd.hpp
---

```cpp
template <typename M>
tools::fps<M> stirling_2nd(int n);
```

It returns $S(n, k) = \frac{1}{k!} \sum_{i = 0}^k (-1)^{k - i} {}_k C_i i^n$ on $\mathbb{F}_P$ for all $k$ such that $0 \leq k \leq n$, where $P$ is `M::mod()`.

## Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $0 \leq n < P$

## Time Complexity
- $O(n \log n)$

## Algorithm
The following equation holds.

$$\begin{align*}
S(n, k) &= \frac{1}{k!} \sum_{i = 0}^k (-1)^{k - i} {}_k C_i i^n\\
&= \frac{1}{k!} \sum_{i = 0}^k (-1)^{k - i} \frac{k!}{i! (k - i)!} i^n\\
&= \sum_{i = 0}^k (-1)^{k - i} \frac{1}{i! (k - i)!} i^n\\
&= \sum_{i = 0}^k \frac{i^n}{i!} \frac{(-1)^{k - i}}{(k - i)!}\\
a_i &:= \frac{i^n}{i!} & (0 \leq i \leq k)\\
b_i &:= \frac{(-1)^i}{i!} & (0 \leq i \leq k)\\
S(n, k) &= \sum_{i = 0}^k a_i b_{k - i}
\end{align*}$$

Therefore, $S(n, k)$ can be calculated by convolution.

## License
- CC0

## Author
- anqooqie
