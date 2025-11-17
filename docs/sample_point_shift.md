---
title: Shift of sampling points of polynomial
documentation_of: //tools/sample_point_shift.hpp
---

## (1)
```cpp
template <std::ranges::input_range R>
requires tools::modint<std::ranges::range_value_t<R>>
std::ranges::range_value_t<R> sample_point_shift(R&& f, std::ranges::range_value_t<R> c);
```

Given sampling points $f(0), f(1), \ldots, f(N - 1) \pmod{P}$ of polynomial $f(x)$ of degree less than $N$, it returns $f(c) \pmod{P}$ where $P$ is `std::ranges::range_value_t<R>::mod()`.

### Constraints
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
template <std::ranges::input_range R>
requires tools::modint<std::ranges::range_value_t<R>>
std::vector<std::ranges::range_value_t<R>> sample_point_shift(R&& f, std::ranges::range_value_t<R> c, int M);
```

Given sampling points $f(0), f(1), \ldots, f(N - 1) \pmod{P}$ of polynomial $f(x)$ of degree less than $N$, it returns $f(c), f(c + 1), \ldots, f(c + M - 1) \pmod{P}$ where $P$ is `std::ranges::range_value_t<R>::mod()`.

### References
- [Shift of Sampling Points of Polynomialの実装 \| Mathlog](https://mathlog.info/articles/3351)

### Constraints
- $P$ is a prime.
- $1 \leq N \leq P$
- $M \geq 0$

### Time Complexity
- $O\left( (N + M) \log(N + M) \right)$

### License
- CC0

### Author
- anqooqie
