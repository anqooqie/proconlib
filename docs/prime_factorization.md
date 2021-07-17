---
title: Pollard's rho algorithm
documentation_of: //tools/prime_factorization.hpp
---

```cpp
template <typename T>
std::map<T, T> prime_factorization(T n);
```

It returns the sorted distinct prime factors with the number of occurrences.

## Constraints
- $1 \leq n \leq 10^{18}$

## Time Complexity
- Supposed to be $O\left(n^\frac{1}{4} \text{polylog}(n)\right)$

## License
- CC0

## Author
- anqooqie
