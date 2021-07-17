---
title: Euler's totient function
documentation_of: //tools/totient.hpp
---

```cpp
template <typename T>
T totient(T x);
```

It returns $\varphi(x) = \|\\{n \in \mathbb{N} \| 1 \leq n \leq x \land \gcd(n, x) = 1\\}\|$.

## Constraints
- $1 \leq x \leq 10^{18}$.

## Time Complexity
- Supposed to be $O\left(x^\frac{1}{4} \text{polylog}(x)\right)$

## License
- CC0

## Author
- anqooqie
