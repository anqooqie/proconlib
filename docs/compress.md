---
title: Compress values
documentation_of: //tools/compress.hpp
---

```cpp
template <std::ranges::range R, typename OutputIterator>
void compress(R&& a, OutputIterator result);
```

Given a sequence $(a_0, a_1, \ldots, a_{n - 1})$, it stores the integer sequence $(b_0, b_1, \ldots, b_{n - 1})$ to `result` where $b_i$ is the number of distinct elements in $a$ less than $a_i$.

### Constraints
- For any integer pairs $(l, r)$ such that $0 \leq l < r < n$, $a_i < a_j$ is defined.

### Time Complexity
- $O(n \log n)$

### License
- CC0

### Author
- anqooqie
