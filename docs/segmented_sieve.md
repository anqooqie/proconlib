---
title: Segmented sieve
documentation_of: //tools/segmented_sieve.hpp
---

It can list all primes $p$ such that $L \leq p \leq R$.
Also, it can list all prime factors of $n$ such that $L \leq n \leq R$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) segmented_sieve<T> sieve(T K, T L, T R);
(2) segmented_sieve<T> sieve(T L, T R);
```

- (1)
    - It constructs two sieves, $1 \leq p \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ and $L \leq p \leq R$. They can list all primes $p$ in them, and list all prime factors of $n$ in them.
- (2)
    - It is the same as `sieve(0, L, R)`.

### Constraints
- $1 \leq L \leq R$
- $K \leq R$

### Time Complexity
- $O\left(\left(\max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right) + R - L\right) \log\log\left(\max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)\right)\right)$

## lpf_max
```cpp
T sieve.lpf_max();
```

It returns $\max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l
```cpp
T sieve.l();
```

It returns $L$.

### Constraints
- None

### Time Complexity
- $O(1)$

## r
```cpp
T sieve.r();
```

It returns $R$.

### Constraints
- None

### Time Complexity
- $O(1)$

## prime_range
```cpp
struct {
  segmented_sieve<T>::prime_iterable::iterator begin();
  segmented_sieve<T>::prime_iterable::iterator end();
} sieve.prime_range(T l, T r);
```

It returns all primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- $1 \leq l \leq r \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ or $L \leq l \leq r \leq R$

### Time Complexity
- $O(1)$

## prime_factor_range
```cpp
struct {
  segmented_sieve<T>::prime_factor_iterable::iterator begin();
  segmented_sieve<T>::prime_factor_iterable::iterator end();
} sieve.prime_factor_range(T n);
```

It returns all prime factors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ or $L \leq n \leq R$

### Time Complexity
- $O(1)$

## distinct_prime_factor_range
```cpp
struct {
  segmented_sieve<T>::distinct_prime_factor_iterable::iterator begin();
  segmented_sieve<T>::distinct_prime_factor_iterable::iterator end();
} sieve.distinct_prime_factor_range(T n);
```

It returns all distinct prime factors of $n$ and the numbers of occurrences of them, in ascending order of primes.
For example, `sieve.distinct_prime_factor_range(360)` returns $((2, 3), (3, 2), (5, 1))$ since $360 = 2^3 \times 3^2 \times 5^1$.

### Constraints
- $1 \leq n \leq \max\left(\left\lfloor\sqrt{R}\right\rfloor, K\right)$ or $L \leq n \leq R$

### Time Complexity
- $O(1)$
