---
title: Bostan-Mori algorithm
documentation_of: //tools/bostan_mori.hpp
---

```cpp
template <typename M>
M bostan_mori(tools::polynomial<M> P, tools::polynomial<M> Q, unsigned long long n);
```

It returns $[x^n]\frac{P(x)}{Q(x)}$.

### Constraints
- $\gcd(Q(0), M) = 1$ where $M$ is `M::mod()`

### Time Complexity
- `<M>` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $O((\mathrm{deg}(P) + \mathrm{deg}(Q)) \log (\mathrm{deg}(P) + \mathrm{deg}(Q)) \log n + \log M)$

### References
- [線形漸化式を満たす数列の N 項目を計算するアルゴリズム](http://q.c.titech.ac.jp/docs/progs/polynomial_division.html)

### License
- CC0

### Author
- anqooqie
