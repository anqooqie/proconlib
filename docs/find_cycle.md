---
title: Floyd's cycle-finding algorithm
documentation_of: //tools/find_cycle.hpp
---

```cpp
template <typename T, typename F>
std::pair<long long, long long> find_cycle(T x0, F f);
```

It returns the minimum $(a, b)$ in lexicographical order such that $a \geq 0$, $b \geq 1$ and $f^a(x_0) = f^{a + b}(x_0)$.

### Constraints
- $(a, b)$ such that $a \geq 0$, $b \geq 1$ and $f^a(x_0) = f^{a + b}(x_0)$ exists.

### Time Complexity
- $O(a + b)$

### License
- CC0

### Author
- anqooqie
