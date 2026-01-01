---
title: Minimum excluded value
documentation_of: //tools/mex.hpp
---

```cpp
template <std::ranges::input_range R>
requires tools::integral<std::ranges::range_value_t<R>>
std::ranges::range_value_t<R> mex(R&& a);
```

It returns the minimum non-negative integer which is not in a given sequence.

### Constraints
- All the integers in the sequence are non-negative.

### Time Complexity
- $O(\|a\|)$

### License
- CC0

### Author
- anqooqie
