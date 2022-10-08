---
title: Berlekamp-Massey algorithm
documentation_of: //tools/berlekamp_massey.hpp
---

```cpp
template <typename InputIterator, typename OutputIterator>
void berlekamp_massey(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence of elements $(a_0, a_1, \ldots, a_{N - 1})$ on a field $K$, it finds a sequence of elements $(1, c_1, c_2, \ldots, c_d)$ on $K$ of the minimum length $d \geq 0$ such that $a_i + \sum_{j=1}^d c_j a_{i - j} \equiv 0$ for $d \leq i < N$.

Berlekamp-Massey algorithm can be used in the following situation.
We have the first $2d$ terms of an infinite sequence.
The sequence is known to be generated from a linear recurrence equation of at most degree $d$.
If we give the first $2d$ terms to Berlekamp-Massey algorithm, we can identify the coefficients of the linear recurrence equation.

Example:
Assume that we have the first $4$ terms $(0, 1, 1, 2)$ of an infinite sequence $(a_0, a_1, \ldots)$.
The sequence is known to be generated from a linear recurrence equation of at most degree $2$.
We can find that the sequence is generated from $a_{n+2} - a_{n+1} - a_n \equiv 0$ by Berlekamp-Massey algorithm.
The infinite sequence is the Fibonacci sequence.

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