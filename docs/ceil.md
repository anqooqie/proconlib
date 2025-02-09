---
title: $\left\lceil \frac{x}{y} \right\rceil$
documentation_of: //tools/ceil.hpp
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> ceil(M x, N y) noexcept;
```

It returns $\left\lceil \frac{x}{y} \right\rceil$.

### Constraints
- `<M>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- `<N>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $y \neq 0$
- $\lceil \frac{x}{y} \rceil$ is representable in type `std::common_type_t<M, N>`.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
