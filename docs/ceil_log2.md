---
title: $\left\lceil \log_2(x) \right\rceil$
documentation_of: //tools/ceil_log2.hpp
---

```cpp
template <typename T>
constexpr T ceil_log2(T x) noexcept;
```

It returns $\left\lceil \log_2(x) \right\rceil$.

### Constraints
- `<T>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $x > 0$

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
