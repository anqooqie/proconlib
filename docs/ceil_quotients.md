---
title: Enumerate the range of $\left\lceil \frac{A}{x} \right\rceil$
documentation_of: //tools/ceil_quotients.hpp
---

```cpp
template <typename T>
std::vector<std::tuple<T, T, T>> ceil_quotients(T A);
```

It returns the tuples such that the $i$-th tuple $(l_i, r_i, q_i)$ satisfies $l_i \leq x < r_i \Rightarrow \left\lceil \frac{A}{x} \right\rceil = q_i$, in ascending order of $l_i$.
The last tuple would be

$$\begin{align*}
\left\{\begin{array}{ll}
(A, \infty, 1) & \text{(if $A > 0$)}\\
(1, \infty, 0) & \text{(if $A = 0$)}
\end{array}\right.&
\end{align*}$$

mathematically, but it actually returns `std::numeric_limits<T>::max()` instead of $\infty$ since a integral type `<T>` cannot represent infinity.

### Constraints
- `<T>` is a built-in integral type.
- $A \geq 0$

### Time Complexity
- $O(\sqrt{A})$

### License
- CC0

### Author
- anqooqie
