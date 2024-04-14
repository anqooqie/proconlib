---
title: Extended Lucas' theorem
documentation_of: //tools/extended_lucas.hpp
---

It precomputes ${}_n C_r \pmod{M}$ for any $n$, any $r$ and a small fixed $M$.

### References
- [Combination （${}_n \mathrm{C}_r \bmod{m}$，Lucas の定理の拡張） \| cplib-cp](https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html)

### License
- MIT

### Author
- hitonanode

## Constructor
```cpp
tools::extended_lucas<T> cache();
```

It precomputes ${}_n \mathrm{C}_r \pmod{M}$ for any $n$ and $r$ where $M$ is `T::mod()`.

### Constraints
- `<T>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $\sum_{i = 1}^k p_i^{q_i} \leq 10^7$ where $M = p_1^{q_1} p_2^{q_2} \cdots p_k^{q_k}$

### Time Complexity
- $O\left( M^\frac{1}{4} + \sum_{i = 1}^k p_i^{q_i} \right)$

## fact
```cpp
M cache.fact(long long n);
```

It returns $n! \pmod{M}$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O( k \log n + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## binomial
```cpp
M cache.binomial(long long n, long long r);
```

It returns $\dbinom{n}{r} \pmod{M}$.
Note that $\dbinom{-n}{r} = (-1)^r \dbinom{n + r - 1}{r}$.

### Constraints
- None

### Time Complexity
- ($n \geq 0$):
    - $O(k \log n + k^2)$
- ($n < 0$):
    - $O(k \log (\|n\| + r) + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## combination
```cpp
M cache.combination(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{C}_r \pmod{M} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(k \log n + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## permutation
```cpp
M cache.permutation(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{P}_r \pmod{M} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(k \log n + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$

## combination_with_repetition
```cpp
M cache.combination_with_repetition(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{H}_r \pmod{M} & \text{(if $n \geq 0$ and $r \geq 0$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(k \log (n + r) + k^2)$
- Note: $k \in O\left( \frac{\log M}{\log \log M} \right)$
