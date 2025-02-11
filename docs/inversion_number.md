---
title: The number of inversions
documentation_of: //tools/inversion_number.hpp
---

```cpp
template <::std::ranges::range R>
long long inversion_number(R&& a);
```

It returns the number of inversions of a given sequence $(a_0, a_1, \ldots, a_{n - 1})$.

### Constraints
- For any integer pairs $(l, r)$ such that $0 \leq l < r < n$, $a_i < a_j$ is defined.

### Time Complexity
- $O(n \log n)$

### License
- CC0

### Author
- anqooqie
