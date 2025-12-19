---
title: $2^{\left\lceil \log_2(x) \right\rceil}$
documentation_of: //tools/bit_ceil.hpp
---

```cpp
constexpr auto bit_ceil(auto&& x) -> std::remove_cvref_t<decltype(x)>;
```

It returns the following value.

$$\begin{align*}
\left\{\begin{array}{ll}
1 & \text{(if $x = 0$)}\\
2^{\lceil \log_2(x) \rceil} & \text{(if $x > 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- `tools::non_bool_integral<std::remove_cvref_t<decltype(x)>>` holds.
- $x \geq 0$
- If $x > 0$, $2^{\lceil \log_2(x) \rceil}$ is representable in type `T`.

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
