---
title: Garner's algorithm for $\mathbb{Z} / M_1 \mathbb{Z}$, $\mathbb{Z} / M_2 \mathbb{Z}$ and $\mathbb{Z} / M_3 \mathbb{Z}$
documentation_of: //tools/garner3.hpp
---

```cpp
template <typename M, typename M1, typename M2, typename M3>
M garner3(M1 a, M2 b, M3 c, M m);
```

It solves the following modular equation system and returns $(x \bmod M_1 M_2 M_3) \bmod m$ where $M_1$ is `M1::mod()`, $M_2$ is `M2::mod()` and $M_3$ is `M3::mod()`.

$$\begin{align*}
\left\{\begin{array}{ll}
x \equiv a &\pmod{M_1}\\
x \equiv b &\pmod{M_2}\\
x \equiv c &\pmod{M_3}
\end{array}\right.&
\end{align*}$$

It is useful to reconstruct $x$ less than $M_1 M_2 M_3$ from $x \bmod M_1$, $x \bmod M_2$ and $x \bmod M_3$.

## Constraints
- `M1` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M2` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M3` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `M` is a built-in integral type.
- $M_1$ is a prime.
- $M_2$ is a prime.
- $M_3$ is a prime.
- $M_1 < M_2 < M_3$
- $m \geq 1$

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
