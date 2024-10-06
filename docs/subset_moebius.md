---
title: Subset Möbius transform
documentation_of: //tools/superset_moebius.hpp
---

## (1)
```cpp
template <typename InputIterator, typename OutputIterator>
void subset_moebius(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ to `result` such that

$$\begin{align*}
b_i &= \sum_{(i~\mathrm{OR}~j) = i} a_j
\end{align*}$$

### Constraints
- None
    - Note that `result` can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename RandomAccessIterator>
void subset_moebius(RandomAccessIterator begin, RandomAccessIterator end);
```

Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ to `begin` such that

$$\begin{align*}
b_i &= \sum_{(i~\mathrm{OR}~j) = i} a_j
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
