---
title: Superset Möbius transform
documentation_of: //tools/superset_moebius.hpp
---

```cpp
(1)
template <typename InputIterator, typename OutputIterator>
void superset_moebius(InputIterator begin, InputIterator end, OutputIterator result);

(2)
template <typename RandomAccessIterator>
void superset_moebius(RandomAccessIterator begin, RandomAccessIterator end);
```

- (1)
    - Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ that satisfies the following relational equation to `result`.
- (2)
    - Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ that satisfies the following relational equation to `begin`.

The following relationship holds between $a$ and $b$.

$$\begin{align*}
b_i &= \sum_{\substack{0 \leq j < N \\ (i~\mathrm{AND}~j) = i}} a_j
\end{align*}$$

### Constraints
- None
    - Note that `result` in (1) can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
