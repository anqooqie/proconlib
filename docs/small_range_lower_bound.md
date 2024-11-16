---
title: std::lower_bound in $\left\langle O(N + \max(A_i) - \min(A_i)), O(1) \right\rangle$ time
documentation_of: //tools/small_range_lower_bound.hpp
---

Given a sorted integer sequence $(A_0, A_1, \ldots, A_{N - 1})$, it returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < N \land A_i < x \\}\|$ in $\left\langle O(N + A_{N - 1} - A_0), O(1) \right\rangle$ time.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
template <typename InputIterator>
small_range_lower_bound<T> lower_bound(InputIterator begin, InputIterator end);
```

Given a sorted integer sequence $(A_0, A_1, \ldots, A_{N - 1})$, it constructs a data structure that allows $\|\\{i \in \mathbb{N} \mid 0 \leq i < N \land A_i < x \\}\|$ to be returned in $O(1)$ time.

### Constraints
- `<T>` is an integral type.

### Time Complexity
- $O(N + A_{N - 1} - A_0)$

## query
```cpp
T lower_bound.query(T x);
```

It returns $\|\\{i \in \mathbb{N} \mid 0 \leq i < N \land A_i < x \\}\|$.

### Constraints
- None

### Time Complexity
- $O(1)$
