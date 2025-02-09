---
title: Quotient as integer division
documentation_of: //tools/quo.hpp
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> quo(M a, N b) noexcept;
```

Given $a$ and $b (\neq 0)$, a pair of values $(q, r)$ satisfying the following conditions is uniquely determined.

$$\begin{align*}
\left\{\begin{array}{l}
a = qb + r\\
q \in \mathbb{Z}\\
0 \leq r < |b|
\end{array}\right.&
\end{align*}$$

It returns $q$.
Note that $q$ is also written as follows.

$$\begin{align*}
\left\{\begin{array}{ll}
\lfloor \frac{a}{b} \rfloor & \text{(if $b > 0$)}\\
\lceil \frac{a}{b} \rceil & \text{(if $b < 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- `<M>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- `<N>` is a built-in integral type, `tools::int128_t` or `tools::uint128_t`.
- $b \neq 0$
- $q$ is representable in type `std::common_type_t<M, N>`.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
