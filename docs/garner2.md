---
title: Garner's algorithm for $\bmod 167772161$ and $\bmod 469762049$
documentation_of: //tools/garner2.hpp
---

```cpp
std::int_fast64_t garner2(atcoder::static_modint<167772161> a, atcoder::static_modint<469762049> b, std::int_fast64_t m);
```

It solves the following modular equation system and returns $x \bmod m$.

$$\begin{align*}
\left\{\begin{array}{ll}
x \equiv a &\pmod{167772161}\\
x \equiv b &\pmod{469762049}
\end{array}\right.&
\end{align*}$$

It is useful to reconstruct $x$ less than $78812994116517889 \approx 7.8 \times 10^{16}$ from $x \bmod 167772161$ and $x \bmod 469762049$.

## Constraints
- $m \geq 1$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
