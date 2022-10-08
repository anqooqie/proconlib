---
title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$ and $\mathbb{Z} / M_2 \mathbb{Z}$
documentation_of: //tools/garner2.hpp
---

```cpp
template <typename M1, typename M2>
long long garner2(M1 a, M2 b);
```

It solves the following modular equation system and returns $x \bmod M_1 M_2$ where $M_1$ is `M1::mod()` and $M_2$ is `M2::mod()`.

$$\begin{align*}
\left\{\begin{array}{ll}
x \equiv a &\pmod{M_1}\\
x \equiv b &\pmod{M_2}
\end{array}\right.&
\end{align*}$$

It is useful to reconstruct $x$ less than $M_1 M_2$ from $x \bmod M_1$ and $x \bmod M_2$.

## Constraints
- `M1` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M2` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- $M_1$ is a prime.
- $M_2$ is a prime.
- $M_1 < M_2$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
