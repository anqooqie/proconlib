---
title: $x^y \pmod{M}$
documentation_of: //tools/pow_mod.hpp
---

```cpp
template <typename T1, typename T2, typename T3>
constexpr T3 pow_mod(T1 x, T2 y, T3 M);
```

It returns $x^y \pmod{M}$.

## Constraints
- $y \geq 0$
- $M \geq 1$

## Time Complexity
- $O(\log y)$

## License
- CC0

## Author
- anqooqie
