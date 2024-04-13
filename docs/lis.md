---
title: Longest increasing subsequence
documentation_of: //tools/lis.hpp
---

```cpp
template <typename Iterator>
auto lis(Iterator begin, Iterator end, bool strict) -> std::pair<std::vector<std::decay_t<decltype(*begin)>>, std::vector<std::size_t>>;
```

If `strict` is true, it returns one of the longest strictly increasing subsequence.
If `strict` is false, it returns one of the longest non-decreasing subsequence.

The first element is the subsequence itself.
The second element is the indices of the subsequence.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie
