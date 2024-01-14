---
title: Polynomial interpolation
documentation_of: //tools/polynomial_interpolation.hpp
---

```cpp
template <typename InputIterator>
tools::polynomial<tools::polynomial<std::decay_t<decltype(std::declval<InputIterator>()->first)>>> compress(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence of integer pairs $(x_0, y_0), (x_1, y_1), \ldots, (x_{N - 1}, y_{N - 1})$, it returns a polynomial $f(x) \in \mathbb{F}_P[x]$ of degree at most $N - 1$ such that $f(x_i) \equiv y_i \pmod{P}$ holds for each $i$.

### Constraints
- `std::decay_t<decltype(std::declval<InputIterator>()->first)>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `std::decay_t<decltype(std::declval<InputIterator>()->first)>` is same as `std::decay_t<decltype(std::declval<InputIterator>()->second)>`.
- $N \geq 1$
- $P$ is a prime.

### Time Complexity
- $O\left(n (\log n)^2\right)$

### License
- CC0

### Author
- anqooqie
