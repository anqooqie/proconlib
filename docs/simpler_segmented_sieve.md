---
title: Simpler segmented sieve
documentation_of: //tools/simpler_segmented_sieve.hpp
---

For all positive integers $n$ such that $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$, it determines if they are prime.

This header is a lightweight and faster alternative to `tools::segmented_sieve`.
By providing only primality test and prime enumeration, it skips the least prime factor table that `tools::segmented_sieve` builds for factor-related queries, which results in lower memory consumption and a smaller constant factor in construction.
Use this header when you only need primality / prime enumeration over $[L, R]$; use `tools::segmented_sieve` when you also need prime factorization, distinct prime factor decomposition, or divisor enumeration.

Prime enumeration is split into two distinct methods, [small_prime_range](#small_prime_range) for $[1, \lfloor \sqrt{R} \rfloor]$ and [large_prime_range](#large_prime_range) for $[L, R]$.
(`tools::segmented_sieve::prime_range` unifies these into a single method whose available input range conditionally depends on whether $\lfloor \sqrt{R} \rfloor + 1 < L$ holds.)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
simpler_segmented_sieve sieve(long long L, long long R);
```

For all positive integers $n$ such that $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$, it determines if they are prime.

### Constraints
- $1 \leq L \leq R$

### Time Complexity
- $O(\sqrt{R} \log \log \sqrt{R} + (R - L) \log \log R)$

## sqrt_r
```cpp
long long sieve.sqrt_r();
```

It returns $\lfloor \sqrt{R} \rfloor$.

### Constraints
- None

### Time Complexity
- $O(1)$

## l
```cpp
long long sieve.l();
```

It returns $L$.

### Constraints
- None

### Time Complexity
- $O(1)$

## r
```cpp
long long sieve.r();
```

It returns $R$.

### Constraints
- None

### Time Complexity
- $O(1)$

## is_prime
```cpp
bool sieve.is_prime(long long i);
```

It returns whether $i$ is a prime or not.

### Constraints
- $1 \leq i \leq \lfloor \sqrt{R} \rfloor$ or $L \leq i \leq R$

### Time Complexity
- $O(1)$

## small_prime_range
```cpp
struct small_prime_view : public std::ranges::view_interface<small_prime_view> {
  struct iterator {
    long long operator*();
    iterator& operator++();
    iterator operator++(int);
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
  std::size_t size();
};
small_prime_view sieve.small_prime_range(long long l, long long r);
```

It returns the primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- $1 \leq l \leq r \leq \lfloor \sqrt{R} \rfloor$

### Time Complexity
- If you just call `small_prime_range`, it takes only $O(1)$ time.
- If you enumerate all the primes $p$ such that $l \leq p \leq r$, it takes $O(r - l)$ time.

## large_prime_range
```cpp
struct large_prime_view : public std::ranges::view_interface<large_prime_view> {
  struct iterator {
    long long operator*();
    iterator& operator++();
    iterator operator++(int);
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
  std::size_t size();
};
large_prime_view sieve.large_prime_range(long long l, long long r);
```

It returns the primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- $L \leq l \leq r \leq R$

### Time Complexity
- If you just call `large_prime_range`, it takes only $O(1)$ time.
- If you enumerate all the primes $p$ such that $l \leq p \leq r$, it takes $O(r - l)$ time.
