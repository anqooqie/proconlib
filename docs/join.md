---
title: Join elements with delimiter
documentation_of: //tools/join.hpp
---

```cpp
template <std::ranges::range R>
std::string join(R e, std::string d);
```

Given $n$ elements $e_0, e_1, \cdots, e_{n - 1}$, it returns $e_0 + d + e_1 + d + \cdots + d + e_{n - 1}$ where $+$ is string concatenation.
Note that it returns an empty string if $n = 0$.

### Constraints
- `operator<<(std::ostream, std::ranges::range_value_t<R>)` is defined.

### Time Complexity
- $\sum_{i = 0}^{n - 1} \|e_i\| + n \|d\|$

### License
- CC0

### Author
- anqooqie
