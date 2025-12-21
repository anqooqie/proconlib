---
title: Popcount
documentation_of: //tools/popcount.hpp
---

```cpp
constexpr int popcount(auto&& x);
```

It returns the number of 1 bits in the value of $x$.

### Constraints
- `tools::non_bool_integral<std::remove_cvref_t<decltype(x)>>` holds.
- $x \geq 0$

### Time Complexity
- $O(\log\log x)$

### References
- Henry S. Warren Jr. (2013). "Hacker's Delight (2nd edition)"

### License
- CC0

### Author
- anqooqie
