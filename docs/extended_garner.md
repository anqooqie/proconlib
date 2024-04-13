---
title: Extended Garner's algorithm
documentation_of: //tools/extended_garner.hpp
---

```cpp
template <typename Iterator, typename ModType>
std::optional<std::pair<long long, long long>> extended_garner(Iterator begin, Iterator end, ModType M);

template <typename M, typename Iterator>
std::optional<std::pair<M, M>> extended_garner(Iterator begin, Iterator end);
```

Given an array of the pairs $(r_i, m_i)$ with length $n$, it solves the modular equation system

$$\begin{align*}
x \equiv r_i \pmod{m_i}, \forall i \in \{0, 1, \ldots, n - 1\}
\end{align*}$$

If there is no solution, it returns `std::nullopt`.
Otherwise, all the solutions can be written as the form $x \equiv y \pmod{z}$, using integers $y, z \, (0 \leq y < z = \mathrm{lcm}(m_i))$.
It returns this $(y \pmod{m}, z \pmod{m})$ as a pair.
If $n = 0$, it returns $(0, 1)$.

### Constraints
- $m_i \geq 1$
- $M \geq 1$

### Time Complexity
- $O(n^2 \log(\min(m_i)))$

### References
- [中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ - Qiita](https://qiita.com/drken/items/ae02240cd1f8edfc86fd)

### License
- unknown

### Author
- drken
