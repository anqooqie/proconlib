---
title: $2^{\left\lfloor \log_2(x) \right\rfloor}$
documentation_of: //tools/bit_floor.hpp
---

```cpp
constexpr auto bit_floor(auto&& x) -> std::remove_cvref_t<decltype(x)>;
```

It returns the following value.

$$\begin{align*}
\left\{\begin{array}{ll}
0 & \text{(if $x = 0$)}\\
2^{\lfloor \log_2(x) \rfloor} & \text{(if $x > 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- `tools::non_bool_integral<std::remove_cvref_t<decltype(x)>>` holds.
- $x \geq 0$

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
