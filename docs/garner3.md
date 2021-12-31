---
title: Garner's algorithm for $\bmod 167772161$, $\bmod 469762049$ and $\bmod 754974721$
documentation_of: //tools/garner3.hpp
---

```cpp
std::int_fast64_t garner3(atcoder::static_modint<167772161> a, atcoder::static_modint<469762049> b, atcoder::static_modint<754974721> c, std::int_fast64_t m);
```

It solves the following modular equation system and returns $x \bmod m$.

$$\begin{align*}
\left\{\begin{array}{ll}
x \equiv a &\pmod{167772161}\\
x \equiv b &\pmod{469762049}\\
x \equiv c &\pmod{754974721}
\end{array}\right.&
\end{align*}$$

It is useful to reconstruct $x$ less than $59501818244292734739283969 \approx 5.9 \times 10^{25}$ from $x \bmod 167772161$, $x \bmod 469762049$ and $x \bmod 754974721$.

## Constraints
- $m \geq 1$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
