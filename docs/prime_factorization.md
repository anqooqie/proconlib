---
title: Pollard's rho algorithm
documentation_of: //tools/prime_factorization.hpp
---

```cpp
template <typename T>
std::vector<T> prime_factorization(T n);
```

It returns the prime factors of $n$ in ascending order.

## Constraints
- $1 \leq n \leq 10^{18}$

## Time Complexity
- Supposed to be $O\left(n^\frac{1}{4} \text{polylog}(n)\right)$

## License
- CC0

## Author
- anqooqie
