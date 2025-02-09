---
title: $\left\lfloor \frac{x}{y} \right\rfloor$
documentation_of: //tools/floor.hpp
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> floor(M x, N y) noexcept;
```

It returns $\left\lfloor \frac{x}{y} \right\rfloor$.

### Constraints
- `<M>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- `<N>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $y \neq 0$
- $\lfloor \frac{x}{y} \rfloor$ is representable in type `std::common_type_t<M, N>`.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
