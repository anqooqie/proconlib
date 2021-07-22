---
title: Extended Lucas' theorem
documentation_of: //tools/extended_lucas.hpp
---

It precomputes ${}_n C_r \pmod{M}$ for any $n$ and $r$.

### References
- [nCr mod mの求め方 - uwicoder - atwiki（アットウィキ）](https://w.atwiki.jp/uwicoder/pages/2118.html#id_6779f709)

### License
- unknown

### Author
- uwi

## Constructor
```cpp
tools::extended_lucas<T> cache();
```

It precomputes ${}_n C_r \pmod{M}$ for any $n$ and $r$ where $M$ is `T::mod()`.

### Constraints
- `<T>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $1 \leq M \leq 10^7$

### Time Complexity
- $O(M \log M)$

## combination
```cpp
T cache.combination(std::int_fast64_t n, std::int_fast64_t r);
```

It returns ${}_n C_r \pmod{M}$ if $0 \leq r \leq n$.
Otherwise, it returns $0$.

### Constraints
- None

### Time Complexity
- $O(\log n + \log r)$
