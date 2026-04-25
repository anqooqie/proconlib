---
title: Sort ranges at once
documentation_of: //tools/batch_sort.hpp
---

```cpp
template <std::strict_weak_order<int, int> Compare, typename R0, typename... Rs>
requires std::ranges::random_access_range<R0> && (std::ranges::random_access_range<Rs> && ...)
      && std::ranges::sized_range<R0> && (std::ranges::sized_range<Rs> && ...)
tools::permutation<int> batch_sort(Compare comp, R0& r0, Rs&... rs);
```

It sorts ranges $r_0, r_1, \ldots, r_m$ at once by a common ordering, where $m = $`sizeof...(Rs)`. The ordering is specified by `comp`, which compares indices into the ranges (not values).

Strictly speaking, let $n = \|r_0\|$. The function computes a permutation $q$ of $(0, 1, \ldots, n - 1)$ such that `comp(i, j)` implies $q_i < q_j$ for all $0 \leq i, j < n$, then simultaneously performs the assignments

$$\begin{align*}
\left\{\begin{array}{ll}
r_{k, q_0} & \leftarrow r_{k, 0}\\
r_{k, q_1} & \leftarrow r_{k, 1}\\
\vdots &\\
r_{k, q_{n - 1}} & \leftarrow r_{k, n - 1}
\end{array}\right.&
\end{align*}$$

for each $k = 0, 1, \ldots, m$, and returns $q$.

The returned $q$ maps each pre-sort index to its post-sort index, so it is intended for translating indices that referred to the original positions. For example, if a graph's edge list refers to vertex indices that are about to be reordered by `batch_sort`, applying $q$ to each endpoint rewrites the edges to use the new indices.

### Constraints
- $\|r_0\| = \|r_1\| = \cdots = \|r_m\|$

### Time Complexity
- $O(Tn \log n + mn)$, where $T$ is the cost of a single call to `comp`.

### License
- CC0

### Author
- anqooqie
