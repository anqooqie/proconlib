---
title: Cache for $n^{-1}, n!, n!^{-1} \pmod{P}$
documentation_of: //tools/fact_mod_cache.hpp
---

It caches $n^{-1}, n!, n!^{-1} \pmod{P}$ and returns them in $O(1)$ amortized time.
It also returns ${}_n \mathrm{C}_r, {}_n \mathrm{P}_r, {}_n \mathrm{H}_r \pmod{P}$ in logarithmic amortized time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) fact_mod_cache<M> cache();
(2) fact_mod_cache<M> cache(long long N);
```

- (1)
    - It creates an empty cache to store $n^{-1}, n!, n!^{-1} \pmod{P}$ where $P$ is `M::mod()`.
- (2)
    - It precomputes $n^{-1}, n!, n!^{-1} \pmod{P}$ for any $n$ such that $0 \leq n \leq N$, where $P$ is `M::mod()`.

### Constraints
- `tools::modint_compatible<M>` holds.
- `M::mod()` is a prime.

### Time Complexity
- (1)
    - $O(1)$
- (2)
    - $O(\min(N, P))$

## inv
```cpp
M cache.inv(long long n);
```

It returns $n^{-1} \pmod{P}$.

### Constraints
- $n \not\equiv 0 \pmod{P}$

### Time Complexity
- $O(\min(\|n\|, P))$ worst
- $O(1)$ amortized

## fact
```cpp
M cache.fact(long long n);
```

It returns $n! \pmod{P}$.

### Constraints
- $n \geq 0$

### Time Complexity
- $O(\min(n, P))$ worst
- $O(1)$ amortized

## fact_inv
```cpp
M cache.fact_inv(long long n);
```

It returns $n!^{-1} \pmod{P}$.

### Constraints
- $0 < n < P$

### Time Complexity
- $O(n)$ worst
- $O(1)$ amortized

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
    - $O(\min(n, P) + \log_P(n))$ worst
    - $O(\log_P(n))$ amortized
- ($n < 0$):
    - $O(\min(\|n\| + r, P) + \log_P(\|n\| + r))$ worst
    - $O(\log_P(\|n\| + r))$ amortized

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
- $O(\min(n, P) + \log_P(n))$ worst
- $O(\log_P(n))$ amortized

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
- $O(\min(n, P) + \log_P(n))$ worst
- $O(\log_P(n))$ amortized

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
- $O(\min(n + r, P) + \log_P(n + r))$ worst
- $O(\log_P(n + r))$ amortized
