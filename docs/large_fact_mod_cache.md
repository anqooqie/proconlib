---
title: Precompute $n! \pmod{P}$ for $0 \leq n < P \approx 10^9$
documentation_of: //tools/large_fact_mod_cache.hpp
---

It returns $n! \pmod{P}$ in $\left\langle O\left(\sqrt{P \log P}\right), O\left(\sqrt{P \log P}\right) \right\rangle$ time.
It also returns ${}_n \mathrm{C}_r, {}_n \mathrm{P}_r, {}_n \mathrm{H}_r \pmod{P}$ in $O\left( \sqrt{\frac{P}{\log P}} \log n \right)$ time.
Their constant factors are drastically low.

### References
- [階乗 mod 素数 - suisen のブログ](https://suisen-kyopro.hatenablog.com/entry/2023/11/22/201600)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
large_fact_mod_cache<M> cache();
```

It precomputes $n! \pmod{P}$ where $P$ is `M::mod()`.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- `M::mod()` is a prime.

### Time Complexity
- $O\left(\sqrt{P \log P}\right)$

## fact
```cpp
M cache.fact(long long n);
```

It returns $n! \pmod{P}$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O\left(\sqrt{P \log P}\right)$

## binomial
```cpp
M cache.binomial(long long n, long long r);
```

It returns $\dbinom{n}{r} \pmod{P}$.
Note that $\dbinom{-n}{r} = (-1)^r \dbinom{n + r - 1}{r}$.

### Constraints
- None

### Time Complexity
- ($n \geq 0$):
    - $O\left( \sqrt{\frac{P}{\log P}} \log n \right)$
- ($n < 0$):
    - $O\left( \sqrt{\frac{P}{\log P}} \log (\|n\| + r) \right)$

## combination
```cpp
M cache.combination(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{C}_r \pmod{P} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O\left( \sqrt{\frac{P}{\log P}} \log n \right)$

## permutation
```cpp
M cache.permutation(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{P}_r \pmod{P} & \text{(if $0 \leq r \leq n$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O\left( \sqrt{\frac{P}{\log P}} \log n \right)$

## combination_with_repetition
```cpp
M cache.combination_with_repetition(long long n, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
{}_n \mathrm{H}_r \pmod{P} & \text{(if $n \geq 0$ and $r \geq 0$)}\\
0 \pmod{P} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O\left( \sqrt{\frac{P}{\log P}} \log (n + r) \right)$
