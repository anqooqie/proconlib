---
title: Bostan-Mori algorithm
documentation_of: //tools/nth_term.hpp
---

```cpp
template <typename InputIterator>
auto nth_term(InputIterator a_begin, InputIterator a_end, InputIterator c_begin, InputIterator c_end, unsigned long long n) -> std::decay_t<decltype(*a_begin)>;
```

Given a sequence of elements $(a_0, a_1, \ldots, a_{d - 1})$ on a field $K$ and a linear recurrence equation $a_i + \sum_{j=1}^d c_j a_{i - j} \equiv 0$ for $i \geq d$, it returns $a_n$.

### Constraints
- `a_end` $-$ `a_begin` $+ 1 =$ `c_end` $-$ `c_begin`
- `*c_begin` $\equiv 1$

### Time Complexity
- $O(d \log d \log n)$

### References
- [数列の漸化式の特定と第N項の計算    [いかたこのたこつぼ]](https://ikatakos.com/pot/programming_algorithm/number_theory/barlekamp_massey)

### License
- CC0

### Author
- anqooqie
