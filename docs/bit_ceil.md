---
title: $2^{\left\lceil \log_2(x) \right\rceil}$
documentation_of: //tools/bit_ceil.hpp
---

```cpp
template <typename T>
constexpr T bit_ceil(T x);
```

It returns the following value.

$$\begin{align*}
\left\{\begin{array}{ll}
1 & \text{(if $x = 0$)}\\
2^{\lceil \log_2(x) \rceil} & \text{(if $x > 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- `<T>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $x \geq 0$
- If $x > 0$, $2^{\lceil \log_2(x) \rceil}$ is representable in type `T`.

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
