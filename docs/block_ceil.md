---
title: $\left\lceil \frac{x}{y} \right\rceil y$
documentation_of: //tools/block_ceil.hpp
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> block_ceil(M x, N y) noexcept;
```

It returns $\left\lceil \frac{x}{y} \right\rceil y$.

### Constraints
- `<M>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- `<N>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $y > 0$
- $\lceil \frac{x}{y} \rceil y$ is representable in type `std::common_type_t<M, N>`.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
