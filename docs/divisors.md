---
title: List all divisors
documentation_of: //tools/divisors.hpp
---

```cpp
template <typename T>
std::vector<T> divisors(T n);
```

It returns the sorted divisors of $n$.

## Constraints
- $1 \leq n \leq 10^{18}$

## Time Complexity
- Supposed to be $O\left(n^\frac{1}{4} \text{polylog}(n)\right)$

## License
- CC0

## Author
- anqooqie
