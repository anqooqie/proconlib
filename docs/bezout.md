---
title: Bézout's identity
documentation_of: //tools/bezout.hpp
---

```cpp
template <typename T>
std::optional<std::tuple<T, T, T, T>> bezout(T a, T b, T c);
```

It solves $ax + by = c$ for $x$ and $y$ over the integers.
It returns four integers $p, q, r, s$ if solutions of the equation exist.
They mean $x = pm + q$ and $y = rm + s$ for any integer $m$.

## Constraints
- $a \neq 0$
- $b \neq 0$

## Note
If $a, b, c, x, y \geq 0$, $\left\lceil -\frac{s}{r} \right\rceil \leq m \leq \left\lfloor -\frac{q}{p} \right\rfloor$ is established.

## License
- CC0

## Author
- anqooqie
