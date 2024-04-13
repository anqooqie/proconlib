---
title: Minimum non-negative reminder
documentation_of: //tools/mod.hpp
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> mod(M a, N b);
```

It returns $r$, which satisfies $a = qb + r$ and $0 \leq r < \|b\|$.

### Constraints
- $b \neq 0$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
