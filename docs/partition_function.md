---
title: Partition function $P(i, i) \pmod{M}$ for $0 \leq i \leq n$ and $P(i, j) \pmod{M}$ for $0 \leq i \leq n, 0 \leq j \leq k$
documentation_of: //tools/partition_function.hpp
---

## (1)

```cpp
template <typename M>
tools::fps<M> partition_function(int n);
```

It returns values of the partition function $P(i, i)$ on $\mathbb{Z} / M \mathbb{Z}$ for all $i$ such that $0 \leq i \leq n$.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$

### Time Complexity
- $O(n \log n)$

### Algorithm
The following equation holds.

$$\begin{align*}
P(n, n) &= [x^n] \prod_{i = 0}^\infty \sum_{j = 0}^\infty x^{ij}\\
&= [x^n] \prod_{i = 0}^\infty \frac{1}{1 - x^i}\\
&= [x^n] \frac{1}{\prod_{i = 0}^\infty (1 - x^i)}\\
&= [x^n] \frac{1}{1 + \sum_{i = 1}^\infty (-1)^i \left(x^\frac{i (3i + 1)}{2} + x^\frac{i (3i - 1)}{2}\right)} & \text{(by the Euler's pentagonal number theorem)}
\end{align*}$$

Therefore, $P(n, n)$ can be calculated by inversion of the formal power series.

### License
- CC0

### Author
- anqooqie

## (2)

```cpp
template <typename M>
std::vector<std::vector<M>> partition_function(int n, int k);
```

It returns values of the partition function $P(i, j)$ on $\mathbb{Z} / M \mathbb{Z}$ for all $i$ such that $0 \leq i \leq n$ and all $j$ such that $0 \leq j \leq k$.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $n \geq 0$
- $k \geq 0$

### Time Complexity
- $O(nk)$

### Algorithm
The following equation holds.

$$\begin{align*}
P(n, k) &= \left\{\begin{array}{ll}
0 & \text{(if $n < 0$ or $k < 0$)}\\
1 & \text{(if $n = 0$ and $k = 0$)}\\
P(n, k - 1) + P(n - k, k) & \text{(otherwise)}
\end{array}\right.
\end{align*}$$

Therefore, $P(n, k)$ can be calculated by dynamic programming.

### License
- CC0

### Author
- anqooqie
