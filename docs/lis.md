---
title: Longest increasing subsequence
documentation_of: //tools/lis.hpp
---

```cpp
template <typename Iterator>
std::int_fast64_t lis(Iterator begin, Iterator end, bool strict);
```

If `strict` is true, it returns the length of the longest strictly increasing subsequence.
If `strict` is false, it returns the length of the longest non-decreasing subsequence.

## Constraints
- `begin` $\leq$ `end`

## Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
