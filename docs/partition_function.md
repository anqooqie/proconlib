---
title: Partition function
documentation_of: //tools/partition_function.hpp
---

It calculates the partition function $P(n, k)$, which is the number of partitions of a nonnegative integer $n$ into $k$ nonnegative integers.

### List of $P(n, k)$

|$n \backslash k$|$0$|$1$|$2$| $3$| $4$| $5$|  $6$|  $7$|  $8$|  $9$| $10$| $11$| $12$| $13$| $14$| $15$|
|             $0$|$1$|$1$|$1$| $1$| $1$| $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|
|             $1$|$0$|$1$|$1$| $1$| $1$| $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|  $1$|
|             $2$|$0$|$1$|$2$| $2$| $2$| $2$|  $2$|  $2$|  $2$|  $2$|  $2$|  $2$|  $2$|  $2$|  $2$|  $2$|
|             $3$|$0$|$1$|$2$| $3$| $3$| $3$|  $3$|  $3$|  $3$|  $3$|  $3$|  $3$|  $3$|  $3$|  $3$|  $3$|
|             $4$|$0$|$1$|$3$| $4$| $5$| $5$|  $5$|  $5$|  $5$|  $5$|  $5$|  $5$|  $5$|  $5$|  $5$|  $5$|
|             $5$|$0$|$1$|$3$| $5$| $6$| $7$|  $7$|  $7$|  $7$|  $7$|  $7$|  $7$|  $7$|  $7$|  $7$|  $7$|
|             $6$|$0$|$1$|$4$| $7$| $9$|$10$| $11$| $11$| $11$| $11$| $11$| $11$| $11$| $11$| $11$| $11$|
|             $7$|$0$|$1$|$4$| $8$|$11$|$13$| $14$| $15$| $15$| $15$| $15$| $15$| $15$| $15$| $15$| $15$|
|             $8$|$0$|$1$|$5$|$10$|$15$|$18$| $20$| $21$| $22$| $22$| $22$| $22$| $22$| $22$| $22$| $22$|
|             $9$|$0$|$1$|$5$|$12$|$18$|$23$| $26$| $28$| $29$| $30$| $30$| $30$| $30$| $30$| $30$| $30$|
|            $10$|$0$|$1$|$6$|$14$|$23$|$30$| $35$| $38$| $40$| $41$| $42$| $42$| $42$| $42$| $42$| $42$|
|            $11$|$0$|$1$|$6$|$16$|$27$|$37$| $44$| $49$| $52$| $54$| $55$| $56$| $56$| $56$| $56$| $56$|
|            $12$|$0$|$1$|$7$|$19$|$34$|$47$| $58$| $65$| $70$| $73$| $75$| $76$| $77$| $77$| $77$| $77$|
|            $13$|$0$|$1$|$7$|$21$|$39$|$57$| $71$| $82$| $89$| $94$| $97$| $99$|$100$|$101$|$101$|$101$|
|            $14$|$0$|$1$|$8$|$24$|$47$|$70$| $90$|$105$|$116$|$123$|$128$|$131$|$133$|$134$|$135$|$135$|
|            $15$|$0$|$1$|$8$|$27$|$54$|$84$|$110$|$131$|$146$|$157$|$164$|$169$|$172$|$174$|$175$|$176$|

## partition_function::diagonal
```cpp
template <typename M>
tools::fps<M> partition_function::diagonal(int N);
```

It returns $P(n, n) \pmod{M}$ for all $n$ such that $0 \leq n \leq N$, where $M$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $N \geq 0$

### Time Complexity
- $O(N \log N)$

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

## partition_function::all
```cpp
template <typename M>
std::vector<std::vector<M>> partition_function::all(int N, int K);
```

It returns $P(n, k) \pmod{M}$ for all $n$ such that $0 \leq n \leq N$ and all $k$ such that $0 \leq k \leq K$, where $M$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $N \geq 0$
- $K \geq 0$

### Time Complexity
- $O(NK)$

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
