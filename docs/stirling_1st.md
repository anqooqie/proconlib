---
title: Stirling numbers of the first kind $s(n, k) \pmod{P}$ for $0 \leq k \leq n$
documentation_of: //tools/stirling_1st.hpp
---

```cpp
template <typename M>
tools::fps<M> stirling_1st(int n);
```

It returns $s(n, k) \pmod{P}$ for all $k$ such that $0 \leq k \leq n$, where $P$ is `M::mod()`.
$s(n, k)$ are defined as the coefficients in the identity.

$$\begin{align*}
x (x - 1) \cdots (x - (n - 1)) &= \sum_{k = 0}^n s(n, k) x^k
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
