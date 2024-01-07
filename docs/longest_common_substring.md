---
title: Longest common substring
documentation_of: //tools/longest_common_substring.hpp
---

```cpp
template <typename InputIterator>
std::tuple<std::size_t, std::size_t, std::size_t, std::size_t> longest_common_substring(InputIterator S_begin, InputIterator S_end, InputIterator T_begin, InputIterator T_end);
```

It returns $(a, b, c, d)$ when a longest common continuous subsequence of $S$ and $T$ can be taken as $(S_a, \ldots, S_{b - 1})$ and $(T_c, \ldots, T_{d - 1})$.
If the longest common continuous subsequence is empty, it returns $(0, 0, 0, 0)$.

### Constraints
- `S_begin` $\leq$ `S_end`
- `T_begin` $\leq$ `T_end`
- `std::decay_t<decltype(*std::declval<InputIterator>())>` is `char`, `int`, `unsigned int`, `long long` or `unsigned long long`.

### Time Complexity
- (`std::decay_t<decltype(*std::declval<InputIterator>())>` is `char`): $O(\|S\| + \|T\|)$
- (otherwise): $O((\|S\| + \|T\|) \log (\|S\| + \|T\|))$

### License
- CC0

### Author
- anqooqie
