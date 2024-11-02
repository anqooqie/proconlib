---
title: Find $b$ from $a$ when $b_i = \sum_{j = 0}^i a_j$ holds
documentation_of: //tools/less_equal_zeta.hpp
---

```cpp
(1)
template <typename InputIterator, typename OutputIterator>
void less_equal_zeta(InputIterator begin, InputIterator end, OutputIterator result);

(2)
template <typename RandomAccessIterator>
void less_equal_zeta(RandomAccessIterator begin, RandomAccessIterator end);
```

- (1)
    - Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ that satisfies the following relational equation to `result`.
- (2)
    - Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ that satisfies the following relational equation to `begin`.

The following relationship holds between $a$ and $b$.

$$\begin{align*}
b_i &= \sum_{0 \leq j \leq i} a_j
\end{align*}$$

### Constraints
- None
    - Note that `result` in (1) can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
