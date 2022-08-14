---
title: std::less by the argument
documentation_of: //tools/less_by_arg.hpp
---

It compares two vectors by the argument.
More precisely, it maps a vector $v$ to $\mathrm{arg}_{d - o}(v - o)$ and compares two vectors by the mapped value.

Given a vector $d$, $\mathrm{arg}_d(v)$ is defined as follows.

$$\begin{align*}
\mathrm{arg}_d(v) &= \mathrm{mod}(\mathrm{arg}(v) - \mathrm{arg}(d), 2 \pi)
\end{align*}$$

$\mathrm{arg}(v)$ is defined as follows.

$$\begin{align*}
\mathrm{arg}(v) &= \left\{\begin{array}{ll}
0 & \text{(if $v = (0, 0)$)}\\
\text{the unique real value $\theta$ which satisfies $0 \leq \theta < 2 \pi$, $\|v\| \cos(\theta) = v_x$ and $\|v\| \sin(\theta) = v_y$} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### References
- [How do you polar sort? - Codeforces](https://codeforces.com/blog/entry/72815)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::less_by_arg<T> comp(tools::vector2<T> o, tools::vector2<T> d);
```

It creates a comparator.

### Constraints
- $d \neq o$

### Time Complexity
- $O(1)$

## operator()
```cpp
bool comp(tools::vector2<T> a, tools::vector2<T> b);
```

It returns the following.

$$\begin{align*}
\left\{\begin{array}{ll}
\text{true} & \text{(if $\mathrm{arg}_{d - o}(a - o) < \mathrm{arg}_{d - o}(b - o)$)}\\
\text{false} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- $a \neq o$
- $b \neq o$

### Time Complexity
- $O(1)$
