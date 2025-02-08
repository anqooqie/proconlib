---
title: $\left\lfloor \log_2(x) \right\rfloor$
documentation_of: //tools/floor_log2.hpp
---

```cpp
template <typename T>
constexpr T floor_log2(T x) noexcept;
```

It returns $\left\lfloor \log_2(x) \right\rfloor$.

### Constraints
- `<T>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $x > 0$

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
