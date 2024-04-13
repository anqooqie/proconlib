---
title: Minimum excluded value
documentation_of: //tools/mex.hpp
---

```cpp
template <typename InputIterator>
std::decay_t<decltype(*std::declval<InputIterator>())> mex(InputIterator begin, InputIterator end);
```

It returns the minimum non-negative integer which is not in a given sequence.

### Constraints
- `begin` $\leq$ `end`
- `std::decay_t<decltype(*std::declval<InputIterator>())>` is an integral type.
- All the integers in the sequence are non-negative.

### Time Complexity
- $O(n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie
