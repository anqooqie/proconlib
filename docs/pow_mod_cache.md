---
title: Cache of $b^n \pmod{M}$
documentation_of: //tools/pow_mod_cache.hpp
---

It returns $b^n \pmod{M}$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
pow_mod_cache<M> cache(long long b);
pow_mod_cache<M> cache(M b);
```

It creates an empty cache to store $b^n \pmod{M}$.

### Constraints
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`

### Time Complexity
- $O(1)$

## operator[]
```cpp
M cache.operator[](long long n);
```

It returns $b^n \pmod{M}$.

### Constraints
- $\gcd(b, M) = 1 \lor n \geq 0$

### Time Complexity
- $O(\min(\log M + \|n\|, M))$ worst
- $O(1)$ amortized

## sum
```cpp
M cache.sum(long long l, long long r);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
\sum_{i = l}^{r - 1} b^i \pmod{M} & \text{(if $l < r$)}\\
0 \pmod{M} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $\gcd(b, M) = 1 \lor l \geq 0$

### Time Complexity
- $O(\min(\log M + \max(0, r - l), M))$ worst
- $O(1)$ amortized
