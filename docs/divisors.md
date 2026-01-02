---
title: List all positive divisors
documentation_of: //tools/divisors.hpp
---

```cpp
template <std::integral T>
std::vector<T> divisors(T n);
```

It returns the sorted positive divisors of $n$.

### Constraints
- $n \geq 1$

### Time Complexity
- Supposed to be $O\left(n^\frac{1}{4}\right)$ expected

### License
- CC0

### Author
- anqooqie
