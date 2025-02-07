---
title: $2^{\left\lfloor \log_2(x) \right\rfloor}$
documentation_of: //tools/bit_floor.hpp
---

```cpp
template <typename T>
constexpr T bit_floor(T x);
```

It returns the following value.

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $x = 0$)}\\
2^{\lfloor \log_2(x) \rfloor} & \text{(if $x > 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- `<T>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $x \geq 0$

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
