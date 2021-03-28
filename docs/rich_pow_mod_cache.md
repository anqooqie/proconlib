---
title: Precompute $b^n \pmod{M}$ for $0 \leq n < \infty$
documentation_of: //tools/rich_pow_mod_cache.hpp
---

It precomputes $b^n \pmod{M}$ for $0 \leq n < \infty$.
It also provides some other rich interfaces.
Their features are built on the pigeonhole principle.

## Usage
```cpp
// calculates 10^n (mod 3), for every n
tools::rich_pow_mod_cache<atcoder::static_modint<3>> cache(10);

// obtains 10^123456789 (mod 3), that is 1
cache[123456789];

// obtains 10^10000 + 10^10001 + 10^10002 (mod 3), that is 0
cache.sum(10000, 10003);
```

## License
- CC0

## Author
- anqooqie
