---
title: Bit width required to represent a given integer
documentation_of: //tools/bit_width.hpp
---

```cpp
template <typename T>
constexpr int bit_width(T x) noexcept;
```

It returns the bit width required to represent $x$.
More precisely, it returns the following value.

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $x = 0$)}\\
\lfloor \log_2(x) \rfloor + 1 & \text{(if $x > 0$)}
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
