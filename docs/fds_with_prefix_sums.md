---
title: Formal Dirichlet series with prefix sums
documentation_of: //tools/fds_with_prefix_sums.hpp
---

It is a formal Dirichlet series that manages the prefix sums of the coefficients.

It is the formal Dirichlet series $\displaystyle D_f(s) := \sum\_{n=1}^\infty \frac{f(n)}{n^s}$ correspanding to an arithmetic function $f \colon \mathbb{Z}\_{>0} \to \mathbb{Z}/M\mathbb{Z}$.
However, since it is not possible to store an infinite number of coefficients, only $O(\sqrt{N})$ pieces of information about the coefficients are stored, with $N$ as parameter. 
The information to be stored is defined using the following items.

$$\begin{align*}
Q_N &:= \left\{ \left\lfloor \frac{N}{n} \right\rfloor \mid n \in \mathbb{Z} \land 1 \leq n \leq N \right\}\\
(a_0, a_1, \ldots, a_{|Q_N| - 1}) &:= \text{(the sequence of the integers contained in $Q_N$ arranged in ascending order)}\\
F(n) &:= \sum_{i=1}^n f(i)
\end{align*}$$

It stores $F(a_0), F(a_1), \ldots, F(a_{\|Q_N\| - 1})$.

Clearly, it contains information about the sum of the arithmetic function $f$ for integers up to $N$, that is $\displaystyle \sum\_{n=1}^N f(n) = F(N) = F(a\_{\|Q_N\| - 1})$.

Since the formal Dirichlet series forms a ring, it supports opeations as a ring.
Furthermore, $D_f(s)$ has a multiplicative inverse as a formal Dirichlet series if and only if $f(1)$ has a multiplicative inverse in the quotient ring $\mathbb{Z}/M\mathbb{Z}$.

### References
- [Dirichlet 積と、数論関数の累積和 \| maspyのHP](https://maspypy.com/dirichlet-%E7%A9%8D%E3%81%A8%E3%80%81%E6%95%B0%E8%AB%96%E9%96%A2%E6%95%B0%E3%81%AE%E7%B4%AF%E7%A9%8D%E5%92%8C)
- [Comment by ecnerwala posted on Codeforces blog](https://codeforces.com/blog/entry/117635?#comment-1041002)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1)
fds_with_prefix_sums<M> D_f(long long N);

(2)
template <typename PrefixSumFunction>
requires std::regular_invocable<PrefixSumFunction, long long>
      && std::assignable_from<M&, std::invoke_result_t<PrefixSumFunction, long long>>
fds_with_prefix_sums<M> D_f(long long N, PrefixSumFunction F);

(3)
template <std::ranges::input_range R>
requires std::assignable_from<M&, std::ranges::range_value_t<R>>
fds_with_prefix_sums<M> D_f(long long N, R&& prefix_sums);
```

- (1)
    - It creates $D_f(s) := 0$.
- (2)
    - Given $F$, it creates $D_f(s)$.
- (3)
    - Given $F(a_0), F(a_1), \ldots, F(a_{\|Q_N\| - 1})$, it creates $D_f(s)$.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $N \geq 1$
- (2)
    - For any positive integer $n$, $F(n)$ can be obtained.
- (3)
    - the length of `prefix_sums` is $\|Q_N\| = 2 \lfloor \sqrt{N} \rfloor - [ N < \lfloor \sqrt{N} \rfloor (\lfloor \sqrt{N} \rfloor + 1) ]$.

### Time Complexity
- (1), (3)
    - $O(\sqrt{N})$
- (2)
    - $\displaystyle O\left(\sum_{i=0}^{\|Q_N\| - 1} T(a_i)\right)$ where $T(n)$ is the time to get $F(n)$
        - If it takes $O(1)$ time to get $F(n)$, it takes $O(\sqrt{N})$ time to construct `D_f`.

## Member functions to get an iterator
```cpp
iterator D_f.begin();
iterator D_f.end();
```

It returns an iterator to enumerate $F(a_0), F(a_1), \ldots, F(a_{\|Q_N\| - 1})$.

### Constraints
- None

### Time Complexity
- $O(1)$

## Member functions to get a reverse iterator
```cpp
reverse_iterator D_f.rbegin();
reverse_iterator D_f.rend();
```

It returns an iterator to enumerate $F(a_{\|Q_N\| - 1}), F(a_{\|Q_N\| - 2}), \ldots, F(a_0)$.
In particular, you can obtain $\sum_{n=1}^N f(n)$ by `*D_f.rbegin()`.

### Constraints
- None

### Time Complexity
- $O(1)$

## Unary plus operator
```cpp
fds_with_prefix_sums<M> D_f.operator+();
```

It returns $D_f(s)$.

### Constraints
- None

### Time Complexity
- $O(\sqrt{N})$

## Unary minus operator
```cpp
fds_with_prefix_sums<M> D_f.operator-();
```

It returns $-D_f(s)$.

### Constraints
- None

### Time Complexity
- $O(\sqrt{N})$

## Addition operators
```cpp
(1) fds_with_prefix_sums<M> operator+(fds_with_prefix_sums<M> D_f, fds_with_prefix_sums<M> D_g);
(2) fds_with_prefix_sums<M>& D_f.operator+=(fds_with_prefix_sums<M> D_g);
```

It returns $D_f(s) + D_g(s)$.

### Constraints
- $N$ for $D_f$ is equal to $N$ for $D_g$.

### Time Complexity
- $O(\sqrt{N})$

## Subtraction operators
```cpp
(1) fds_with_prefix_sums<M> operator-(fds_with_prefix_sums<M> D_f, fds_with_prefix_sums<M> D_g);
(2) fds_with_prefix_sums<M>& D_f.operator-=(fds_with_prefix_sums<M> D_g);
```

It returns $D_f(s) - D_g(s)$.

### Constraints
- $N$ for $D_f$ is equal to $N$ for $D_g$.

### Time Complexity
- $O(\sqrt{N})$

## Multiplication operators
```cpp
(1) fds_with_prefix_sums<M> operator*(fds_with_prefix_sums<M> D_f, fds_with_prefix_sums<M> D_g);
(2) fds_with_prefix_sums<M>& D_f.operator*=(fds_with_prefix_sums<M> D_g);
```

It returns $D_f(s) D_g(s)$.

### Constraints
- $N$ for $D_f$ is equal to $N$ for $D_g$.

### Time Complexity
- $O\left(N^\frac{2}{3}\right)$

## Division operators
```cpp
(1) fds_with_prefix_sums<M> operator/(fds_with_prefix_sums<M> D_f, fds_with_prefix_sums<M> D_g);
(2) fds_with_prefix_sums<M>& D_f.operator/=(fds_with_prefix_sums<M> D_g);
```

It returns $\displaystyle \frac{D_f(s)}{D_g(s)}$.

### Constraints
- $N$ for $D_f$ is equal to $N$ for $D_g$.
- $\gcd(g(1), M) = 1$

### Time Complexity
- $O\left(N^\frac{2}{3}\right)$
