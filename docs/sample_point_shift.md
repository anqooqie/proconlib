---
title: Shift of sampling points of polynomial
documentation_of: //tools/sample_point_shift.hpp
---

## (1)
```cpp
template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type sample_point_shift(InputIterator begin, InputIterator end, typename std::iterator_traits<InputIterator>::value_type c);
```

Given sampling points $f(0), f(1), \ldots, f(N - 1) \pmod{P}$ of polynomial $f(x)$ of degree less than $N$, it returns $f(c) \pmod{P}$ where $P$ is `std::iterator_traits<InputIterator>::value_type::mod()`.

### Constraints
- `typename std::iterator_traits<InputIterator>::value_type` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $1 \leq N \leq P$

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename T>
T sample_point_shift(std::initializer_list<T> il, T c);
```

It is equivalent to `sample_point_shift(il.begin(), il.end(), c)`.

### Constraints
- `T` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $1 \leq N \leq P$

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie

## (3)
```cpp
template <typename InputIterator>
std::vector<typename std::iterator_traits<InputIterator>::value_type> sample_point_shift(InputIterator begin, InputIterator end, typename std::iterator_traits<InputIterator>::value_type c, int M);
```

Given sampling points $f(0), f(1), \ldots, f(N - 1) \pmod{P}$ of polynomial $f(x)$ of degree less than $N$, it returns $f(c), f(c + 1), \ldots, f(c + M - 1) \pmod{P}$ where $P$ is `std::iterator_traits<InputIterator>::value_type::mod()`.

### References
- [Shift of Sampling Points of Polynomialの実装 \| Mathlog](https://mathlog.info/articles/3351)

### Constraints
- `typename std::iterator_traits<InputIterator>::value_type` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $1 \leq N \leq P$
- $M \geq 0$

### Time Complexity
- $O\left( (N + M) \log(N + M) \right)$

### License
- CC0

### Author
- anqooqie

## (4)
```cpp
template <typename T>
std::vector<T> sample_point_shift(std::initializer_list<T> il, T c, int M);
```

It is equivalent to `sample_point_shift(il.begin(), il.end(), c, M)`.

### Constraints
- `T` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $P$ is a prime.
- $1 \leq N \leq P$
- $M \geq 0$

### Time Complexity
- $O\left( (N + M) \log(N + M) \right)$

### License
- CC0

### Author
- anqooqie
