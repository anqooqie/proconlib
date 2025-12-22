---
title: Run-length encoding
documentation_of: //tools/run_length.hpp
---

```cpp
template <tools::integral T, std::ranges::input_range R>
std::vector<std::pair<std::ranges::range_value_t<R>, T>> run_length(R&& r);

template <std::ranges::input_range R>
std::vector<std::pair<std::ranges::range_value_t<R>, int>> run_length(R&& r);
```

It replaces consecutive elements to a pair of the element and the number of occurrences, and returns the pairs with such a format. 

### Constraints
- None

### Time Complexity
- $O(\|r\|)$

### License
- CC0

### Author
- anqooqie
