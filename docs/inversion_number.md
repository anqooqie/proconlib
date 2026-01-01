---
title: The number of inversions
documentation_of: //tools/inversion_number.hpp
---

```cpp
template <std::ranges::input_range R>
requires std::totally_ordered<std::ranges::range_value_t<R>>
long long inversion_number(R&& a);
```

Given a sequence $(a_0, a_1, \ldots, a_{n - 1})$, it returns the number of integer pairs $(i, j)$ such that $0 \leq i < j < n \land a_i > a_j$.

### Constraints
- None

### Time Complexity
- $O(n \log n)$

### License
- CC0

### Author
- anqooqie
