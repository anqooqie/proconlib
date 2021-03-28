---
title: Precompute $n! \pmod{M}$ for $0 \leq n \leq N$ 
documentation_of: //tools/fact_mod_cache.hpp
---

It precomputes $n! \pmod{M}$ for $0 \leq n \leq N$.

## Usage
```cpp
// precomputes n! (mod 3) for 0 <= n <= 5
tools::fact_mod_cache<atcoder::static_modint<3>> cache(5);

// obtains 5! (mod 3), that is 0
cache.fact(5);
```

## License
- CC0

## Author
- anqooqie
