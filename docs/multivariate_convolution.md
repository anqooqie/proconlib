---
title: Multivariate convolution
documentation_of: //tools/multivariate_convolution.hpp
---

```cpp
template <typename M>
std::vector<M> multivariate_convolution(std::vector<M> f, std::vector<M> g, std::vector<int> N);
```

Given polynomials in $K$ variables over $\mathbb{F}\_M$, $f(x_1, x_2, \ldots, x_K)$ and $g(x_1, x_2, \ldots, x_K)$, it returns $fg \bmod (x_1^{N_1}, x_2^{N_2}, \ldots, x_K^{N_K})$.
$f$ and $g$ are given as the one-dimensional arrays of length $\prod\_{k=1}^K N_k$ where the $i_1 + i_2 N_1 + \cdots + i_K N_1 N_2 \cdots N_{K-1}$-th element is corresponded to the coefficient of $x_1^{i_1} x_2^{i_2} \cdots x_K^{i_K}$.

### Constraints
- $\forall N_k \in N. N_k \geq 0$
- $\|f\| = \|g\| = \prod_{k=1}^K N_k$
- `M` is `atcoder::static_modint`.
- $2 \leq M \leq 2 \times 10^9$
- $M$ is a prime.
- There is an integer $c$ with $2^c \mid (M - 1)$ and $2 \left(\prod_{k=1}^K N_k\right) - 1 \leq 2^c$.

### Time Complexity
- $O(L (\log L)^2)$ where $L = \prod_{k=1}^K N_k$

### License
- CC0

### Author
- anqooqie
