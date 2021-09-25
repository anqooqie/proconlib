---
title: Minimum excluded value
documentation_of: //tools/mex.hpp
---

```
template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type mex(InputIterator begin, InputIterator end);
```

It returns the minimum non-negative integer which is not in a given set.

## Constraints
- `begin` $\leq$ `end`

## Time Complexity
- $O(n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
