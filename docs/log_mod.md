---
title: $\log_x y \pmod{M}$
documentation_of: //tools/log_mod.hpp
---

```cpp
long long log_mod(long long x, long long y, long long M);
```

It returns the minimum non-negative integer $k$ such that $x^k \equiv y \pmod{M}$ if it exists.
If $k$ does not exist, it returns `std::nullopt`.

Note that we define $0^0 = 1$ in this function.

## Constraints
- $M \geq 1$

## Time Complexity
- $O(\sqrt{M})$

## References
- [離散対数問題 (Discrete Logarithm Problem) を任意 mod で解く - Qiita](https://qiita.com/suisen_cp/items/d597c8ec576ae32ee2d7)

## License
- CC0

## Author
- anqooqie
