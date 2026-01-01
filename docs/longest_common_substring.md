---
title: Longest common substring
documentation_of: //tools/longest_common_substring.hpp
---

```cpp
template <std::ranges::input_range R1, std::ranges::input_range R2>
requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>> && (
  std::same_as<std::ranges::range_value_t<R1>, char> ||
  std::same_as<std::ranges::range_value_t<R1>, int> ||
  std::same_as<std::ranges::range_value_t<R1>, unsigned int> ||
  std::same_as<std::ranges::range_value_t<R1>, long long> ||
  std::same_as<std::ranges::range_value_t<R1>, unsigned long long> 
)
std::tuple<int, int, int, int> longest_common_substring(R1&& S, R2&& T);
```

It returns $(a, b, c, d)$ when a longest common continuous subsequence of $S$ and $T$ can be taken as $(S_a, \ldots, S_{b - 1})$ and $(T_c, \ldots, T_{d - 1})$.
If the longest common continuous subsequence is empty, it returns $(0, 0, 0, 0)$.

### Constraints
- None

### Time Complexity
- (`std::ranges::range_value_t<R1>` is `char`): $O(\|S\| + \|T\|)$
- (otherwise): $O((\|S\| + \|T\|) \log (\|S\| + \|T\|))$

### License
- CC0

### Author
- anqooqie
