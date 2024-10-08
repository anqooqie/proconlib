---
title: Multiple Möbius transform
documentation_of: //tools/multiple_moebius.hpp
---

```cpp
(1)
template <typename InputIterator, typename OutputIterator>
void multiple_moebius(InputIterator begin, InputIterator end, OutputIterator result);

(2)
template <typename RandomAccessIterator>
void multiple_moebius(RandomAccessIterator begin, RandomAccessIterator end);
```

- (1)
    - Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ that satisfies the following relational equation to `result`.
- (2)
    - Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ that satisfies the following relational equation to `begin`.

The following relationship holds between $a$ and $b$.

$$\begin{align*}
b_i &= \left\{\begin{array}{ll}
a_0 & (i = 0)\\
\displaystyle \sum_{\substack{1 \leq j < N \\ i \mid j}} a_j & (i > 0)
\end{array}\right.
\end{align*}$$

### Constraints
- None
    - Note that `result` in (1) can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N \log \log N)$

### License
- CC0

### Author
- anqooqie
