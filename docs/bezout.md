---
title: Bézout's identity
documentation_of: //tools/bezout.hpp
---

```cpp
template <typename T>
std::optional<std::tuple<T, T, T, T>> bezout(T a, T b, T c);
```

It solves $ax + by = c$ for $x$ and $y$ over the integers.
It returns four integers $p, q, r, s$ if the solutions of the equation exist.
They mean that $x$ can be denoted as $pm + q$ and $y$ can be denoted as $rm + s$ for any integer $m$.

## Constraints
- $a \neq 0$
- $b \neq 0$

## Note
The solutions of the equation exist if and only if $c \equiv 0 \pmod{\gcd(a, b)}$.
If the solutions exist, the following equations hold when we denote a particular solution of $a x' + b y' = \gcd(a, b)$ as $(x'_0, y'_0)$.

$$\begin{align*}
p &= -\frac{b}{\gcd(a, b)}\\
q &= \frac{c}{\gcd(a, b)} x'_0\\
r &= \frac{a}{\gcd(a, b)}\\
s &= \frac{c}{\gcd(a, b)} y'_0
\end{align*}$$

If $a, b, c, x, y \geq 0$, $\left\lceil -\frac{c y'_0}{a} \right\rceil \leq m \leq \left\lfloor \frac{c x'_0}{b} \right\rfloor$ holds.

## License
- CC0

## Author
- anqooqie
