---
title: Prime factorization
documentation_of: //tools/prime_factorization.hpp
---

```cpp
template <typename T, typename OutputIterator>
void prime_factorization(T n, OutputIterator result);
```

It inserts ordered prime factors into `result`.
It implements Pollard's rho algorithm.

## Constraints
- $1 \leq n \leq 10^{18}$

## License
- CC0

## Author
- anqooqie
