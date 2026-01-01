---
title: Coordinate compression
documentation_of: //tools/compressed.hpp
---

```cpp
(1)
template <tools::integral T, std::ranges::input_range R>
requires std::totally_ordered<std::ranges::range_value_t<R>>
std::vector<T> compressed(R&& a);

(2)
template <std::ranges::input_range R>
requires std::totally_ordered<std::ranges::range_value_t<R>>
std::vector<std::conditional_t<tools::integral<std::ranges::range_value_t<R>>, std::ranges::range_value_t<R>, int>> compressed(R&& a);
```

- (1)
    - Given a sequence $(a_0, a_1, \ldots, a_{n - 1})$, it returns $(b_0, b_1, \ldots, b_{n - 1})$ where $b_i$ is the number of distinct elements in $a$ less than $a_i$.
- (2)
    - It is almost equivalent to (1), but returns `std::vector<std::conditional_t<tools::integral<std::ranges::range_value_t<R>>, std::ranges::range_value_t<R>, int>>`.

### Constraints
- None

### Time Complexity
- $O(n \log n)$

### License
- CC0

### Author
- anqooqie
