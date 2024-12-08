---
title: List all divisors of a divisor of $n$
documentation_of: //tools/divisors_of_divisor.hpp
---

Given a positive divisor $d$ of a positive integer $n$, it enumerates all the positive divisors of $d$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
divisors_of_divisor<T> ds(T n);
```

It constructs a data structure that allows enumeration of all the positive divisors of $d$ where $d$ is a positive divisor of $n$.

### Constraints
- `<T>` is an integral type.
- $1 \leq n \leq 10^{18}$

### Time Complexity
- Supposed to be $O\left(n^\frac{1}{4}\right)$ expected

## divisors (1)
```cpp
const std::vector<T>& ds.divisors();
```

It returns all the positive divisors of $n$.

The elements of `ds.divisors()` are stored in the following order:
By using some primes $p_0 < p_1 < \cdots < p_{k - 1}$ and some positive integers $q_0, q_1, \ldots, q_{k - 1}$, we can denote $n$ as $p_0^{q_0} p_1^{q_1} \cdots p_{k - 1}^{q_{k - 1}}$.
Also, by using some non-negative integers $e_0, e_1, \ldots, e_{k - 1}$ such that $0 \leq e_0 \leq q_0, 0 \leq e_1 \leq q_1, \ldots, 0 \leq e_{k - 1} \leq q_{k - 1}$, we can denote a positive divisor $d$ of $n$ as $p_0^{e_0} p_1^{e_1} \cdots p_{k - 1}^{e_{k - 1}}$.
$d$ is stored in `ds.divisors()[s]` where $s$ is $\sum_{i = 0}^{k - 1} \left( e_i \prod_{j = 0}^{i - 1} (q_j + 1) \right)$.

### Constraints
- None

### Time Complexity
- $O(1)$

## find
```cpp
typename std::vector<T>::const_iterator ds.find(T x);
```

If $x$ is a positive divisor of $n$, it returns the iterator of `ds.divisors()` referring to $x$.
Otherwise, it returns `ds.divisors().end()`.

### Constraints
- None

### Time Complexity
- $O\left( \frac{\log n}{\log \log n} \right)$

## contains
```cpp
bool ds.contains(T x);
```

It returns whether $x$ is a positive divisor of $n$ or not.

### Constraints
- None

### Time Complexity
- $O\left( \frac{\log n}{\log \log n} \right)$

## divisors (2)
```cpp
struct divisors_iterable {
  struct iterator {
    T operator*();
    iterator& operator++();
    iterator operator++(int):
    iterator& operator--();
    iterator operator--(int):
    friend bool operator==(iterator lhs, iterator rhs);
    friend bool operator!=(iterator lhs, iterator rhs);
    operator typename std::vector<T>::const_iterator();
  };
  iterator begin();
  iterator end();
};
divisors_iterable ds.divisors(typename std::vector<T>::const_iterator it);
```

Given the iterator of `ds.divisors()` referring to a positive divisor $d$ of $n$, it enumerates all the positive divisors of $d$.

### Constraints
- `it` is an iterator of `ds.divisors()`.
- `it != ds.divisors().end()`

### Time Complexity
- If you just call `divisors`, it takes only $O(1)$ time.
- If you enumerate all the positive divisors of $d$, it takes $O\left( 2^\frac{\log d}{\log \log d} \frac{\log n}{\log \log n} \right)$ time.

## divisors (3)
```cpp
divisors_iterable ds.divisors(T d);
```

It is equivalent to `ds.divisors(ds.find(d))`.

### Constraints
- $d$ is a positive divisor of $n$.

### Time Complexity
- If you just call `divisors`, it takes only $O\left( \frac{\log n}{\log \log n} \right)$ time.
- If you enumerate all the positive divisors of $d$, it takes $O\left( 2^\frac{\log d}{\log \log d} \frac{\log n}{\log \log n} \right)$ time.
