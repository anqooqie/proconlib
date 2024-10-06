---
title: Divisor Zeta transform
documentation_of: //tools/divisor_zeta.hpp
---

## (1)
```cpp
template <typename InputIterator, typename OutputIterator>
void divisor_zeta(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ to `result` such that

$$\begin{align*}
b_i &= \sum_{\mathrm{lcm}(i, j) = i} a_j
\end{align*}$$

In other words, $b_i (i > 0)$ is the sum of $a_j$ for $j$ such that $j$ is a positive divisor of $i$.
Note that we define $\mathrm{lcm}(x, 0) = \mathrm{lcm}(0, y) = \mathrm{lcm}(0, 0) = 0$ in this function.

### Constraints
- None
    - Note that `result` can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N \log \log N)$

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename RandomAccessIterator>
void divisor_zeta(RandomAccessIterator begin, RandomAccessIterator end);
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ to `begin` such that

$$\begin{align*}
b_i &= \sum_{\mathrm{lcm}(i, j) = i} a_j
\end{align*}$$

In other words, $b_i (i > 0)$ is the sum of $a_j$ for $j$ such that $j$ is a positive divisor of $i$.
Note that we define $\mathrm{lcm}(x, 0) = \mathrm{lcm}(0, y) = \mathrm{lcm}(0, 0) = 0$ in this function.

### Constraints
- None

### Time Complexity
- $O(N \log \log N)$

### License
- CC0

### Author
- anqooqie
