---
title: Convolution
documentation_of: //tools/convolution.hpp
---

## (1)
```cpp
template <tools::ring R, std::ranges::input_range R1, std::ranges::input_range R2>
requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
      && std::assignable_from<typename R::add::T&, std::ranges::range_value_t<R1>>
std::vector<typename R::add::T> convolution(R1&& a, R2&& b);
```

It is convolution on a commutative ring $R = (T, +, \cdot)$.
The additive group $(T, +, 0)$ is defined by $($ `typename R::add::T` $, $ `R::add::op` $, $ `R::add::e()` $)$.
The multiplicative monoid $(T, \cdot, 1)$ is defined by $($ `typename R::mul::T` $, $ `R::mul::op` $, $ `R::mul::e()` $)$.

Given two sequences $(a_0, a_1, \ldots, a_{N - 1})$ and $(b_0, b_1, \ldots, b_{M - 1})$ on $R$, it returns the sequence $(c_0, c_1, \ldots, c_{N + M - 2})$ on $R$ where

$$\begin{align*}
c_i = \sum_{j = 0}^i a_j \cdot b_{i - j}
\end{align*}$$

It returns an empty sequence if at least one of $a$ and $b$ are empty.

### Constraints
- If $T$ is `atcoder::static_modint` or `atcoder::dynamic_modint`, $N + M \leq 2^{25} + 1 = 33554433$.
- If $T$ is an integral type, $N + M \leq 2^{24} + 1 = 16777217$ and all the elements of the array are in $R$ after convolution.

### Time Complexity
- (`R` is `tools::rings::plus_multiplies<T>` such that `T` is either `atcoder::static_modint`, `atcoder::dynamic_modint`, `std::floating_point`, `std::complex` or `std::integral`): $O((N + M) \log (N + M))$
- (otherwise): $O(NM \alpha \beta)$ where `R::add::op` takes $\alpha$ time and `R::mul::op` takes $\beta$ time

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <std::ranges::input_range R1, std::ranges::input_range R2>
requires std::same_as<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>
std::vector<std::ranges::range_value_t<R1>> convolution(R1&& a, R2&& b);
```

It is equivalent to `convolution<tools::rings::plus_multiplies<T>>(a, b)` where `T` is `std::ranges::range_value_t<R1>`.

### Constraints
- `tools::ring<tools::rings::plus_multiplies<T>>` holds.
- If $T$ is `atcoder::static_modint` or `atcoder::dynamic_modint`, $N + M \leq 2^{25} + 1 = 33554433$.
- If $T$ is an integral type, $N + M \leq 2^{24} + 1 = 16777217$ and all the elements of the array are in $R$ after convolution.

### Time Complexity
- (`T` is either `atcoder::static_modint`, `atcoder::dynamic_modint`, `std::floating_point`, `std::complex` or `std::integral`): $O((N + M) \log (N + M))$
- (otherwise): $O(NM)$

### License
- CC0

### Author
- anqooqie
