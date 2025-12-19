---
title: Sign function
documentation_of: //tools/signum.hpp
---

```cpp
constexpr int signum(auto&& x);
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
-1 & \text{(if $x < 0$)}\\
0 & \text{(if $x = 0$)}\\
1 & \text{(if $x > 0$)}
\end{array}\right.&
\end{align*}$$

`tools::signum(x)` will be extended by other header files in my library.
For example, `tools::signum(tools::bigint)` gets available if you include `tools/bigint.hpp`.

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
