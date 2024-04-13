---
title: Largest rectangle in histogram
documentation_of: //tools/largest_rectangle_in_histogram.hpp
---

```cpp
template <typename Iterator>
typename ::std::iterator_traits<Iterator>::value_type largest_rectangle_in_histogram(Iterator begin, Iterator end);
```

It returns the area of the largest rectangle in a given histogram.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie
