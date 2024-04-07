---
title: Shift of sampling points of polynomial
documentation_of: //tools/sample_point_shift.hpp
---

```cpp
(1)
template <typename InputIterator>
std::vector<typename std::iterator_traits<InputIterator>::value_type> sample_point_shift(InputIterator begin, InputIterator end, long long L, long long R);

(2)
template <typename M>
std::vector<M> sample_point_shift(std::initializer_list<M> il, long long L, long long R);
```

- (1)
    - Given sampling points $f(0), f(1), \ldots, f(N) \pmod{P}$ of polynomial $f(x)$ of degree at most $N$, it returns $f(L), f(L + 1), \ldots, f(R - 1) \pmod{P}$ where $P$ is `std::iterator_traits<InputIterator>::value_type::mod()`.
- (2)
    - It is equivalent to `sample_point_shift(il.begin(), il.end(), L, R)`.

### References
- [Shift of Sampling Points of Polynomialの実装 \| Mathlog](https://mathlog.info/articles/3351)

### Constraints
- (1)
    - `typename std::iterator_traits<InputIterator>::value_type` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
    - `begin` $\neq$ `end`
- (2)
    - `M` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
    - `il` is not empty.
- (1), (2)
    - $P$ is a prime.
    - $0 \leq N < P$
    - $L \leq R \leq L + P$

### Time Complexity
- $O\left( (N + (R - L)) \log(N + (R - L)) \right)$

### License
- CC0

### Author
- anqooqie
