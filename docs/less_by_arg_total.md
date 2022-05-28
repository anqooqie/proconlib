---
title: std::less by the argument (total order)
documentation_of: //tools/less_by_arg_total.hpp
---

It compares two vectors by the argument.
More precisely, it maps a vector $v$ to $(\mathrm{class}\_{d - o}(v - o), \mathrm{arg}\_{d - o}(v - o), \|v - o\|)$ and compares two vectors by the mapped value in lexicographical order.

Given a vector $d$, $\mathrm{class}_d(v)$ is defined as follows.

$$\begin{align*}
\mathrm{class}_d(v) &= \left\{\begin{array}{ll}
0 & \text{(if $\mathrm{arg}(d) = \mathrm{arg}(v) \land \|d\| \leq \|v\|$)}\\
1 & \text{(if $\mathrm{arg}(d) \neq \mathrm{arg}(v)$)}\\
2 & \text{(if $\mathrm{arg}(d) = \mathrm{arg}(v) \land \|v\| < \|d\|$)}
\end{array}\right.&
\end{align*}$$

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
tools::less_by_arg_total<T> comp(tools::vector2<T> o, tools::vector2<T> d);
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
bool comp(tools::vector2<T> a, tools::vector2<T> b);
```

It returns the following.

$$\begin{align*}
\left\{\begin{array}{ll}
\text{true} & \text{(if $(\mathrm{class}_{d - o}(a), \mathrm{arg}_{d - o}(a), \|a\|) < (\mathrm{class}_{d - o}(b), \mathrm{arg}_{d - o}(b), \|b\|)$ in lexicographical order)}\\
\text{false} & \text{(otherwise)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$
