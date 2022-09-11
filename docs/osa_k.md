---
title: osa_k's algorithm
documentation_of: //tools/osa_k.hpp
---

It creates a table storing the least prime factor of positive integers.
It provides various operations related to prime factors by using the table.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
osa_k<T> osa_k(T N);
```

It calculates the least prime factor for each positive integer $n$ such that $1 \leq n < N$.

### Constraints
- $N \geq 1$

### Time Complexity
- $O(N \log\log N)$

## divisor_count
```cpp
T osa_k.divisor_count(T n);
```

It returns the number of divisors of $n$.

### Constraints
- $1 \leq n < N$

### Time Complexity
- $O(1)$

## prime_factor_range
```cpp
struct {
  struct iterator {
    T operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
} osa_k.prime_factor_range(T n);
```

It returns the prime factors of $n$ in ascending order.

### Constraints
- $1 \leq n < N$

### Time Complexity
- If you just call `prime_factor_range`, it takes only $O(1)$.
- If you enumerate all the prime factors of $n$, it takes $O(\log n)$.

## distinct_prime_factor_range
```cpp
struct {
  struct iterator {
    std::pair<T, T> operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
} osa_k.distinct_prime_factor_range(T n);
```

By using some primes $p_1 < p_2 < \cdots < p_k$ and some positive integers $q_1, q_2, \ldots, q_k$, we can denote $n$ as $p_1^{q_1} p_2^{q_2} \cdots p_k^{q_k}$.
It returns $((p_1, q_1), (p_2, q_2), \ldots, (p_k, q_k))$.

### Constraints
- $1 \leq n < N$

### Time Complexity
- If you just call `distinct_prime_factor_range`, it takes only $O(1)$.
- If you enumerate all the distinct prime factors of $n$, it takes $O(\log n)$.

## prime_range
```cpp
struct {
  struct iterator {
    T operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
} osa_k.prime_range(T l, T r);
```

It returns the primes $p$ such that $l \leq p < r$ in ascending order.

### Constraints
- $1 \leq l \leq r \leq N$

### Time Complexity
- If you just call `prime_range`, it takes only $O(1)$.
- If you enumerate all the primes $p$ such that $l \leq p < r$, it takes $O(r - l)$.

## divisors
```cpp
std::vector<T> osa_k.divisors(T n);
```

It returns the divisors of $n$ in ascending order.

### Constraints
- $1 \leq n < N$

### Time Complexity
- $O\left(n^\frac{1}{\log\log n} \frac{\log n}{\log\log n}\right)$
