---
title: The number of inversions
documentation_of: //tools/inversion_number.hpp
---

```cpp
template <typename Iterator>
typename std::iterator_traits<Iterator>::value_type inversion_number(Iterator begin, Iterator end);
```

It returns the number of inversions of a given integer sequence $(a_0, a_1, \ldots, a_{N - 1})$.

### Constraints
- None

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
