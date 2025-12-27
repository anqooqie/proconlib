---
title: Check whether a given integer is $2^n$
documentation_of: //tools/has_single_bit.hpp
---

```cpp
template <tools::integral T>
constexpr bool has_single_bit(T x);
```

It returns whether $x$ is in $\\{2^n \mid n \in \mathbb{Z}_{\geqslant 0}\\} = \\{1, 2, 4, 8, \ldots\\}$.

### Constraints
- $x \geq 0$

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
