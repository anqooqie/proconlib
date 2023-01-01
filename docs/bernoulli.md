---
title: Bernoulli numbers $B_k \pmod{P}$ for $0 \leq k \leq n$
documentation_of: //tools/bernoulli.hpp
---

```cpp
template <typename M>
tools::fps<M> bernoulli(int n);
```

It returns bernoulli numbers $B_k$ on $\mathbb{F}_P$ for all $k$ such that $0 \leq k \leq n$, where $P$ is `M::mod()`.
$B_k$ are defined as the coefficients of the following equation.

$$\begin{align*}
\frac{x}{e^x - 1} &= \sum_{k = 0}^\infty \frac{B_k}{k!} x^k
\end{align*}$$

## Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $0 \leq n < P$

## Time Complexity
- $O(n \log n)$

## License
- CC0

## Author
- anqooqie
