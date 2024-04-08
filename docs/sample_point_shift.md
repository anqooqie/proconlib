---
title: Shift of sampling points of polynomial
documentation_of: //tools/sample_point_shift.hpp
---

```cpp
(1)
template <typename InputIterator>
std::vector<typename std::iterator_traits<InputIterator>::value_type> sample_point_shift(InputIterator begin, InputIterator end, typename std::iterator_traits<InputIterator>::value_type c, int M);

(2)
template <typename T>
std::vector<T> sample_point_shift(std::initializer_list<T> il, T c, int M);
```

- (1)
    - Given sampling points $f(0), f(1), \ldots, f(N - 1) \pmod{P}$ of polynomial $f(x)$ of degree less than $N$, it returns $f(c), f(c + 1), \ldots, f(c + M - 1) \pmod{P}$ where $P$ is `std::iterator_traits<InputIterator>::value_type::mod()`.
- (2)
    - It is equivalent to `sample_point_shift(il.begin(), il.end(), c, M)`.

### References
- [Shift of Sampling Points of Polynomialの実装 \| Mathlog](https://mathlog.info/articles/3351)

### Constraints
- (1)
    - `typename std::iterator_traits<InputIterator>::value_type` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
    - `begin` $\neq$ `end`
- (2)
    - `T` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
    - `il` is not empty.
- (1), (2)
    - $P$ is a prime.
    - $1 \leq N \leq P$
    - $M \geq 0$

### Time Complexity
- $O\left( (N + M) \log(N + M) \right)$

### License
- CC0

### Author
- anqooqie
