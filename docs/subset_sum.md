---
title: Subset sum
documentation_of: //tools/subset_sum.hpp
---

```cpp
template <tools::modint M, std::ranges::input_range R>
requires std::integral<std::ranges::range_value_t<R>>
tools::fps<M> subset_sum(R&& s, int T);
```

Given $N$ non-negative integers $s_0, s_1, \ldots, s_{N - 1}$ and a non-negative integer $T$, it returns the number of subset $I \subseteq \\{0, 1, \ldots, N - 1\\}$ such that $\sum_{i \in I} s_i = t$ for $t = 0, 1, \ldots, T$.

### Constraints
- $0 \leq T < \mathrm{lpf}(M)$
- $s_i \geq 0$

### Time Complexity
- $O(N + T \log T)$

### License
- CC0

### Author
- anqooqie
