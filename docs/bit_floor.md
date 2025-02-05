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
- $x \geq 0$

### Time Complexity
- $O(\log\log x)$

### License
- CC0

### Author
- anqooqie
