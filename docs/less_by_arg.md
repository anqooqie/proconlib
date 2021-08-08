---
title: std::less by the argument
documentation_of: //tools/less_by_arg.hpp
---

It compares two vectors by the argument.
More precisely, it maps a vector $v$ to $(\mathrm{class}_d(v), \mathrm{arg}_d(v), \|v\|)$ and compares two vectors by the mapped value in lexicographical order.

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

$\mathrm{arg}(v)$ is $0$ if $v = (0, 0)$.
Otherwise, $\mathrm{arg}(v)$ is the unique real velue $\theta$ which satisfies $0 \leq \theta < 2 \pi \land \|v\| \cos(\theta) = v_x \land \|v\| \sin(\theta) = v_y$.

### References
- [How do you polar sort? - Codeforces](https://codeforces.com/blog/entry/72815)

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
(1) tools::less_by_arg<true, int> comp();
(2) tools::less_by_arg<false, T> comp(tools::vector2<T> d);
```

It creates a comparator.

- (1)
    - It is recommended to use the form like `const auto comp = tools::less_by_arg();`. $(0, 0)$ will be used as $d$.
- (2)
    - It is recommended to use the form like `const auto comp = tools::less_by_arg(d);`.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
(1) template <typename T> bool comp(tools::vector2<T> a, tools::vector2<T> b);
(2) bool comp(tools::vector2<T> a, tools::vector2<T> b);
```

It returns `true` if $(\mathrm{class}_d(a), \mathrm{arg}_d(a), \|a\|) < (\mathrm{class}_d(b), \mathrm{arg}_d(b), \|b\|)$ in lexicographical order.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
