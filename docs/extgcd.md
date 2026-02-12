---
title: Extended Euclidean algorithm
documentation_of: //tools/extgcd.hpp
---

```cpp
constexpr std::tuple<T, T, T> extgcd(auto&& a, auto&& b);
// where T = std::common_type_t<std::remove_cvref_t<decltype(a)>, std::remove_cvref_t<decltype(b)>>
```

It returns $(x_0, y_0, \gcd(a, b))$ which satisfies

$$\begin{align*}
\left\{\begin{array}{l}
a x_0 + b y_0 = \gcd(a, b)\\
|x_0| \leq \max\left(1, \left\lfloor\frac{|b|}{2 \gcd(a, b)}\right\rfloor\right)\\
|y_0| \leq \max\left(1, \left\lfloor\frac{|a|}{2 \gcd(a, b)}\right\rfloor\right)
\end{array}\right.&
\end{align*}$$

In this function, we define $\gcd(a, 0) = a$, $\gcd(0, b) = b$ and $\gcd(0, 0) = 0$.

`tools::extgcd(a, b)` will be extended by other header files in my library.

### Constraints
- `a` and `b` satisfy `tools::signed_integral`.

### Time Complexity
- $O(\log(\min(\|a\|, \|b\|)))$

### License
- CC0

### Author
- anqooqie
