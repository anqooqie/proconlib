---
title: Extended Lucas' theorem
documentation_of: //tools/extended_lucas.hpp
---

It precomputes ${}_n C_r \pmod{M}$ for any $n$ and $r$.

### References
- [Combination （${}_n \mathrm{C}_r \bmod{m}$，Lucas の定理の拡張） \| cplib-cp](https://hitonanode.github.io/cplib-cpp/number/combination.hpp.html)

### License
- MIT

### Author
- hitonanode

## Constructor
```cpp
tools::extended_lucas<T> cache();
```

It precomputes ${}_n \mathrm{C}_r \pmod{M}$ for any $n$ and $r$ where $M$ is `T::mod()`.

### Constraints
- `<T>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $1 \leq M \leq 10^7$

### Time Complexity
- $O(M)$

## combination
```cpp
T cache.combination(long long n, long long r);
```

If $0 \leq r \leq n$, it returns ${}_n \mathrm{C}_r \pmod{M}$.
Otherwise, it returns $0$.

### Constraints
- None

### Time Complexity
- $O(\frac{\log M}{\log \log M} \log n)$
