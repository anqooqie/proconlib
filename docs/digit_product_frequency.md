---
title: Frequency table of digit products
documentation_of: //tools/digit_product_frequency.hpp
---

```cpp
template <typename T>
std::map<T, T> digit_product_frequency(T n);
```

Let $f(x)$ be the product of the digits of $x$.
It returns pairs of two integers $(k, v)$ such that

$$\begin{align*}
\left\{\begin{array}{l}
v = |\{x \in \mathbb{N} \mid 1 \leq x \leq n \land f(x) = k\}|\\
v > 0
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O\left(\left(\log n\right)^5\right)$

### License
- CC0

### Author
- anqooqie
