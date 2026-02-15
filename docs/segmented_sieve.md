---
title: Segmented sieve
documentation_of: //tools/segmented_sieve.hpp
---

It creates a table storing the least prime factor of a positive integer $n$ such that $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$.
It provides various operations related to prime factors by using the table.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
segmented_sieve sieve(long long L, long long R);
```

It calculates the least prime factor for each positive integer $n$ such that $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$.

### Constraints
- $1 \leq L \leq R$

### Time Complexity
- $\sqrt{R} + (R - L) \log \log R$

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
bool sieve.is_prime(long long n);
```

It returns whether $n$ is a prime or not.

### Constraints
- $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$

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
prime_factor_view sieve.prime_factor_range(long long n);
```

It returns the prime factors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$

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
distinct_prime_factor_view sieve.distinct_prime_factor_range(long long n);
```

By using some primes $p_1 < p_2 < \cdots < p_k$ and some positive integers $q_1, q_2, \ldots, q_k$, we can denote $n$ as $p_1^{q_1} p_2^{q_2} \cdots p_k^{q_k}$.
It returns $((p_1, q_1, p_1^{q_1}), (p_2, q_2, p_2^{q_2}), \ldots, (p_k, q_k, p_k^{q_k}))$.

### Constraints
- $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$

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
prime_view sieve.prime_range(long long l, long long r);
```

It returns the primes $p$ such that $l \leq p \leq r$ in ascending order.

### Constraints
- ($\lfloor \sqrt{R} \rfloor + 1 < L$): $1 \leq l \leq r \leq \lfloor \sqrt{R} \rfloor$ or $L \leq l \leq r \leq R$
- (otherwise): $1 \leq l \leq r \leq R$

### Time Complexity
- If you just call `prime_range`, it takes only $O(\log R)$ time.
- If you enumerate all the primes $p$ such that $l \leq p \leq r$, it takes $O\left(\log R + \frac{r}{\log r} - \frac{l}{\log l}\right)$ time.

## divisors
```cpp
std::vector<long long> sieve.divisors(long long n);
```

It returns the positive divisors of $n$.
Note that the order of divisors is undefined.

### Constraints
- $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$

### Time Complexity
- $O(d(n))$

## sorted_divisors
```cpp
std::vector<long long> sieve.sorted_divisors(long long n);
```

It returns the positive divisors of $n$ in ascending order.

### Constraints
- $1 \leq n \leq \lfloor \sqrt{R} \rfloor$ or $L \leq n \leq R$

### Time Complexity
- $O(d(n) \log(d(n)))$

## divisor_counts
```cpp
std::pair<std::vector<long long>, std::vector<long long>> sieve.divisor_counts();
```

It returns $(d(0), d(1), \ldots, d(\lfloor \sqrt{R} \rfloor))$ and $(d(L), d(L + 1), \ldots, d(R))$.
For convenience, we define $d(0)$ as $0$.

### Constraints
- None

### Time Complexity
- $O(\sqrt{R} + (R - L) \log \log R)$
