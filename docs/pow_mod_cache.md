---
title: Precompute $b^n \pmod{M}$
documentation_of: //tools/pow_mod_cache.hpp
---

It returns $b^n \pmod{M}$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) pow_mod_cache<M> cache(std::int_fast64_t b);
(2) pow_mod_cache<M> cache(M b);
(3) pow_mod_cache<M> cache(std::int_fast64_t b, std::int_fast64_t N);
(4) pow_mod_cache<M> cache(M b, std::int_fast64_t N);
```

- (1), (2)
    - It creates an empty cache to store $b^n \pmod{M}$.
- (3), (4)
    - It precomputes $b^n \pmod{M}$ for $0 \leq n \leq N$.

### Constraints
- (1), (2)
    - `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- (3), (4)
    - `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
    - $N \geq 0$

### Time Complexity
- (1), (2)
    - $O(1)$
- (3), (4)
    - $O(\min(N, M))$

## operator[]
```cpp
M cache.operator[](std::int_fast64_t n);
```

It returns $b^n \pmod{M}$.

### Constraints
- $\gcd(b, M) = 1 \lor n \geq 0$

### Time Complexity
- $O(\min(n, M))$ worst (if $n \geq 0$)
- $O(M)$ worst (if $n < 0$)
- $O(1)$ amortized

## sum
```cpp
M cache.sum(std::int_fast64_t l, std::int_fast64_t r);
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
- $O(\min(\max(1, r), M))$ worst (if $l \geq 0$)
- $O(M)$ worst (if $l < 0$)
- $O(1)$ amortized
