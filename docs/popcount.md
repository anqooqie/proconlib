---
title: Popcount
documentation_of: //tools/popcount.hpp
---

```cpp
template <typename T>
constexpr int popcount(T x) noexcept;
```

It returns the number of 1 bits in the value of $x$.

### Constraints
- `<T>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $x \geq 0$

### Time Complexity
- $O(\log\log x)$

### References
- Henry S. Warren Jr. (2013). "Hacker's Delight (2nd edition)"

### License
- CC0

### Author
- anqooqie
