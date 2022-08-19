---
title: Barlekamp-Massey algorithm
documentation_of: //tools/barlekamp_massey.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void barlekamp_massey(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence of elements $(a_0, a_1, \ldots, a_{N - 1})$ on a field $K$, it returns a sequence of elements $(1, c_1, c_2, \ldots, c_d)$ on $K$ of the minimum length $d \geq 0$ such that $a_i + \sum_{j=1}^d c_j a_{i - j} \equiv 0$ for $d \leq i < N$.

### Constraints
- None

### Time Complexity
- $O(N^2)$

### References
- [数列の漸化式の特定と第N項の計算    [いかたこのたこつぼ]](https://ikatakos.com/pot/programming_algorithm/number_theory/barlekamp_massey)

### License
- CC0

### Author
- anqooqie
