---
title: Extended Euclidean algorithm
documentation_of: //tools/extgcd.hpp
---

```cpp
template <typename T>
requires (!std::unsigned_integral<T>)
std::tuple<T, T, T> extgcd(T a, T b);
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

### Constraints
- None

### Time Complexity
- $O(\log(\min(\|a\|, \|b\|)))$

### License
- CC0

### Author
- anqooqie
