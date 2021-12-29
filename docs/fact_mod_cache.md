---
title: Precompute $n! \pmod{M}$ for $0 \leq n \leq N < M$
documentation_of: //tools/fact_mod_cache.hpp
---

It precomputes $n! \pmod{M}$ for $0 \leq n \leq N < M$.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::fact_mod_cache<T> cache(std::int_fast64_t N);
```

It precomputes $n! \pmod{M}$ for $0 \leq n \leq N$ where $M$ is `T::mod()`.

### Constraints
- `<T>` is `atcoder::static_modint` or `atcoder::dynamic_modint`
- $M$ is a prime
- $0 \leq N < M$

### Time Complexity
- $O(N + \log M)$

## fact
```cpp
T cache.fact(::std::int_fast64_t n);
```

It returns $n! \pmod{M}$.

### Constraints
- $0 \leq n \leq N$

### Time Complexity
- $O(1)$

## inv_fact
```cpp
T cache.inv_fact(::std::int_fast64_t n);
```

It returns $n!^{-1} \pmod{M}$.

### Constraints
- $0 \leq n \leq N$

### Time Complexity
- $O(1)$

## permutation
```cpp
T cache.permutation(::std::int_fast64_t n, ::std::int_fast64_t r);
```

It returns ${}_n P_r \pmod{M}$ if $0 \leq r \leq n$.
Otherwise, it returns $0$.

### Constraints
- $n \leq N$

### Time Complexity
- $O(1)$

## combination
```cpp
T cache.combination(::std::int_fast64_t n, ::std::int_fast64_t r);
```

It returns ${}_n C_r \pmod{M}$ if $0 \leq r \leq n$.
Otherwise, it returns $0$.

### Constraints
- $n \leq N$

### Time Complexity
- $O(1)$
