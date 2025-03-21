---
title: Linear sieve
documentation_of: //tools/linear_sieve.hpp
---

It creates a table storing the least prime factor of positive integers.
It provides various operations related to prime factors by using the table.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
linear_sieve<T> sieve(int N);
```

It calculates the least prime factor for each positive integer $n$ such that $1 \leq n \leq N$.

### Constraints
- $N \geq 1$

### Time Complexity
- $O(N \log\log N)$

## is_prime
```cpp
bool sieve.is_prime(int n);
```

It returns whether $n$ is a prime or not.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- $O(1)$

## prime_factor_range
```cpp
struct prime_factor_view : public std::ranges::view_interface<prime_factor_view> {
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
prime_factor_view sieve.prime_factor_range(int n);
```

It returns the prime factors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- If you just call `prime_factor_range`, it takes only $O(1)$ time.
- If you enumerate all the prime factors of $n$, it takes $O(\log n)$ time.

## distinct_prime_factor_range
```cpp
struct distinct_prime_factor_view : public std::ranges::view_interface<distinct_prime_factor_view> {
  struct iterator {
    std::tuple<T, T, T> operator*();
    iterator& operator++();
    iterator operator++(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
  };
  iterator begin();
  iterator end();
};
distinct_prime_factor_view sieve.distinct_prime_factor_range(int n);
```

By using some primes $p_1 < p_2 < \cdots < p_k$ and some positive integers $q_1, q_2, \ldots, q_k$, we can denote $n$ as $p_1^{q_1} p_2^{q_2} \cdots p_k^{q_k}$.
It returns $((p_1, q_1, p_1^{q_1}), (p_2, q_2, p_2^{q_2}), \ldots, (p_k, q_k, p_k^{q_k}))$.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- If you just call `distinct_prime_factor_range`, it takes only $O(1)$ time.
- If you enumerate all the distinct prime factors of $n$, it takes $O\left(\frac{\log n}{\log \log n}\right)$ time.

## prime_range
```cpp
struct prime_view : public std::ranges::view_interface<prime_view> {
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
prime_view sieve.prime_range(int l, int r);
```

It returns the primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- $1 \leq l \leq r \leq N$

### Time Complexity
- If you just call `prime_range`, it takes only $O(1)$ time.
- If you enumerate all the primes $p$ such that $l \leq p \leq r$, it takes $O\left(\log N + \frac{r}{\log r} - \frac{l}{\log l}\right)$ time.

## divisors
```cpp
std::vector<T> sieve.divisors(int n);
```

It returns the positive divisors of $n$.
Note that the order of divisors is undefined.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- $O\left(n^\frac{1}{\log\log n}\right)$

## sorted_divisors
```cpp
std::vector<T> sieve.sorted_divisors(int n);
```

It returns the positive divisors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq N$

### Time Complexity
- $O\left(n^\frac{1}{\log\log n} \frac{\log n}{\log\log n}\right)$
