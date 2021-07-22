---
title: Counter clockwise function
documentation_of: //tools/ccw.hpp
---

```cpp
template <typename T>
std::int_fast64_t ccw(tools::vector2<T> a, tools::vector2<T> b, tools::vector2<T> c);
```

It returns 

$$\begin{align*}
\left\{\begin{array}{ll}
+1 & \text{(if $a$, $b$ and $c$ make a counterclockwise turn on the regular orthogonal coordinate system ($(\infty, 0)$ is on the right side and $(0, \infty)$ is on the upper side))}\\
-1 & \text{(if $a$, $b$ and $c$ make a clockwise turn on the regular orthogonal coordinate system)}\\
+2 & \text{(if $c$ - $a$ - $b$ are on a line in this order ($c \neq a$))}\\
-2 & \text{(if $a$ - $b$ - $c$ are on a line in this order ($c \neq b$))}\\
0 & \text{(otherwise; i.e., $a$ - $c$ - $b$ are on a line in this order, $c = a$, $c = b$ or $a = b$)}
\end{array}\right.&
\end{align*}$$

## Constraints
- None

## Time Complexity
- $O(1)$

## References
- [Spaghetti Source (ccw) - 点の進行方向](http://www.prefield.com/algorithm/geometry/ccw.html)

## License
- CC0

## Author
- anqooqie
