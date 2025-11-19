---
title: Find the k-th largest integer using oracle
documentation_of: //tools/kth_largest_by_oracle.hpp
---

```cpp
template <typename F>
requires std::regular_invocable<F, long long>
      && std::assignable_from<long long&, std::invoke_result_t<F, long long>>
long long kth_largest_by_oracle(long long k, F f, long long l, long long r);
```

Suppose that we have a multiset $S$ of integers, and we cannot directly examine $S$, but we can get $f(x)$, the number of elements in $S$ that are greater than or equal to $x$.
Given $k$, $f$ and $[l, r]$, the domain of definition of $f$, it returns the $k$-th largest integer in $S$.

### Constraints
- $1 \leq k \leq f(l)$
- $l \leq r$
- For any $i$ and $j$ such that $l \leq i < j \leq r$, $f(i) \geq f(j)$

### Time Complexity
- $O(\log (r - l) \cdot T)$ where $T$ is the time required to get $f(x)$

### License
- CC0

### Author
- anqooqie
