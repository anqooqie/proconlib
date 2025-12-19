---
title: Bit width required to represent a given integer
documentation_of: //tools/bit_width.hpp
---

```cpp
constexpr int bit_width(auto&& x);
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
- `tools::non_bool_integral<std::remove_cvref_t<decltype(x)>>` holds.
- $x \geq 0$

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
