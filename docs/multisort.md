---
title: Sort multiple ranges at once
documentation_of: //tools/multisort.hpp
---

```cpp
template <std::strict_weak_order<int, int> Compare, typename R0, typename... Rs>
requires std::ranges::random_access_range<R0> && (std::ranges::random_access_range<Rs> && ...)
      && std::ranges::sized_range<R0> && (std::ranges::sized_range<Rs> && ...)
tools::permutation<int> multisort(Compare comp, R0& r0, Rs&... rs);
```

It sorts ranges $r_0, r_1, \ldots, r_m$ at once by a common ordering, where $m = $`sizeof...(Rs)`. The ordering is specified by `comp`, which compares indices into the ranges (not values).

Strictly speaking, let $n = \|r_0\|$. The function computes the permutation $p$ of $(0, 1, \ldots, n - 1)$ such that $p_0 \leq p_1 \leq \cdots \leq p_{n - 1}$, where $i \leq j$ is defined by `!comp(j, i)`. It then performs the following assignments and returns $p$.

$$\begin{align*}
\left\{\begin{array}{ll}
r_{0, 0} & \leftarrow r_{0, p_0}\\
r_{0, 1} & \leftarrow r_{0, p_1}\\
\vdots &\\
r_{0, n - 1} & \leftarrow r_{0, p_{n - 1}}\\
r_{1, 0} & \leftarrow r_{1, p_0}\\
\vdots &\\
r_{m, n - 1} & \leftarrow r_{m, p_{n - 1}}
\end{array}\right.&
\end{align*}$$

### Constraints
- $\|r_0\| = \|r_1\| = \cdots = \|r_m\|$

### Time Complexity
- $O(Tn \log n + mn)$, where $T$ is the cost of a single call to `comp`.

### License
- CC0

### Author
- anqooqie
