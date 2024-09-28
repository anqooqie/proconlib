---
title: Sieve of Eratosthenes
documentation_of: //tools/eratosthenes_sieve.hpp
---

For all positive integers less than or equal to $n$, it determines if they are prime.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
eratosthenes_sieve<T> sieve(int n);
```

For all positive integers less than or equal to $n$, it determines if they are prime.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n \log\log n)$

## is_prime
```cpp
bool sieve.is_prime(int i);
```

It returns whether $i$ is a prime or not.

### Constraints
- $1 \leq i \leq n$

### Time Complexity
- $O(1)$

## prime_range
```cpp
struct prime_iterable {
  struct iterator {
    T operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
prime_iterable sieve.prime_range(int l, int r);
```

It returns the primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- $1 \leq l \leq r \leq n$

### Time Complexity
- If you just call `prime_range`, it takes only $O(1)$ time.
- If you enumerate all the primes $p$ such that $l \leq p \leq r$, it takes $O(r - l)$ time.
