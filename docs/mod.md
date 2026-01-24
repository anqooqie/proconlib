---
title: Minimum non-negative reminder
documentation_of: //tools/mod.hpp
---

```cpp
template <tools::non_bool_integral M, tools::non_bool_integral N>
constexpr std::common_type_t<M, N> mod(M a, N b) noexcept;
```

Given $a$ and $b (\neq 0)$, a pair of values $(q, r)$ satisfying the following conditions is uniquely determined.

$$\begin{align*}
\left\{\begin{array}{l}
a = qb + r\\
q \in \mathbb{Z}\\
0 \leq r < |b|
\end{array}\right.&
\end{align*}$$

It returns $r$.

### Constraints
- $b \neq 0$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
