---
title: $x^{-1} \pmod{M}$
documentation_of: //tools/inv_mod.hpp
---

```cpp
template <typename T1, typename T2>
constexpr T2 inv_mod(T1 x, T2 M);
```

It returns $x^{-1} \pmod{M}$.

## Constraints
- $x \neq 0$
- $M \geq 1$
- $\gcd(x, M) = 1$

## Time Complexity
- $O(\log(\min(\|x\|, M)))$

## License
- CC0

## Author
- anqooqie
