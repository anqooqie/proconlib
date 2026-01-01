---
title: In-place coordinate compression
documentation_of: //tools/compress.hpp
---

```cpp
template <std::ranges::forward_range R>
requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
      && tools::integral<std::ranges::range_value_t<R>>
void compress(R&& a);
```

Given a sequence $(a_0, a_1, \ldots, a_{n - 1})$, it calculates the integer sequence $(b_0, b_1, \ldots, b_{n - 1})$ where $b_i$ is the number of distinct elements in $a$ less than $a_i$, and updates $a$ to $b$.

### Constraints
- None

### Time Complexity
- $O(n \log n)$

### License
- CC0

### Author
- anqooqie
