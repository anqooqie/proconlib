---
title: Precompute $b^n \pmod{M}$ for $0 \leq n \leq N$
documentation_of: //tools/pow_mod_cache.hpp
---

It precomputes $b^n \pmod{M}$ for $0 \leq n \leq N$.

## Usage
```cpp
// precomputs 10^n (mod 3) for 0 <= n <= 5
tools::pow_mod_cache<atcoder::static_modint<3>> cache(10, 5);

// obtains 10^5 (mod 3), that is 1
cache[5];
```

## License
- CC0

## Author
- anqooqie
