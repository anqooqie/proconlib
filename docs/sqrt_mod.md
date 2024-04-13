---
title: $\sqrt{x} \pmod{P}$
documentation_of: //tools/sqrt_mod.hpp
---

```cpp
std::optional<long long> sqrt_mod(long long x, long long P);
```

It returns one of $y$s such that $y^2 \equiv x \pmod{P}$ if it exists.
If such $y$ does not exist, it returns `std::nullopt`.

### Constraints
- $P$ is a prime.

### Time Complexity
- $O\left(\left(\log P\right)^2\right)$

### License
- CC0

### Author
- anqooqie
