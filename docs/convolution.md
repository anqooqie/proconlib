---
title: Convolution
documentation_of: //tools/convolution.hpp
---

## (1)
```cpp
template <typename AG, typename MM, typename InputIterator1, typename InputIterator2, typename OutputIterator>
void convolution(InputIterator1 a_begin, InputIterator1 a_end, InputIterator2 b_begin, InputIterator2 b_end, OutputIterator result);
```

It is convolution on a commutative ring $(R, +, \cdot)$.
The additive group $(R, +, 0)$ is defined by $($ `typename AG::T` $, $ `AG::op` $, $ `AG::e()` $)$.
The multiplicative monoid $(R, \cdot, 1)$ is defined by $($ `typename MM::T` $, $ `MM::op` $, $ `MM::e()` $)$.

Given two sequences $(a_0, a_1, \ldots, a_{N - 1})$ and $(b_0, b_1, \ldots, b_{M - 1})$ on $R$, it returns the sequence $(c_0, c_1, \ldots, c_{N + M - 2})$ on $R$ where

$$\begin{align*}
c_i = \sum_{j = 0}^i a_j \cdot b_{i - j}
\end{align*}$$

It returns an empty sequence if at least one of $a$ and $b$ are empty.

### Constraints
- `std::decay_t<decltype(*std::declval<InputIterator1>())>`, `std::decay_t<decltype(*std::declval<InputIterator2>())>`, `typename AG::T` and `typename MM::T` are the same type $R$.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `AG::op(AG::op(x, y), z)` $=$ `AG::op(x, AG::op(y, z))`.
- For all $x$ in $R$, `AG::op(AG::e(), x)` $=$ `AG::op(x, AG::e())` $= x$.
- For all $x$ in $R$, `AG::op(AG::inv(x), x)` $=$ `AG::op(x, AG::inv(x))` $=$ `AG::e()`.
- For all $x$ in $R$ and $y$ in $R$, `AG::op(x, y)` $=$ `AG::op(y, x)`.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(MM::op(x, y), z)` $=$ `MM::op(x, MM::op(y, z))`.
- For all $x$ in $R$, `MM::op(MM::e(), x)` $=$ `MM::op(x, MM::e())` $= x$.
- For all $x$ in $R$ and $y$ in $R$, `MM::op(x, y)` $=$ `MM::op(y, x)`.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(x, AG::op(y, z))` $=$ `AG::op(MM::op(x, y), MM::op(x, z))`.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(AG::op(x, y), z)` $=$ `AG::op(MM::op(x, z), MM::op(y, z))`.
- $R$ is assignable to `*result`.
- If $R$ is `atcoder::static_modint` or `atcoder::dynamic_modint`, $N + M \leq 2^{25} + 1 = 33554433$.
- If $R$ is an integral type, $N + M \leq 2^{24} + 1 = 16777217$ and all the elements of the array are in $R$ after convolution.

### Time Complexity
- (`AG` is `tools::group::plus<atcoder::static_modint<?>>` and `MM` is either of `tools::monoid::multiplies<atcoder::static_modint<?>>` or `tools::group::multiplies<atcoder::static_modint<?>>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<atcoder::dynamic_modint<?>>` and `MM` is either of `tools::monoid::multiplies<atcoder::dynamic_modint<?>>` or `tools::group::multiplies<atcoder::dynamic_modint<?>>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<float>` and `MM` is either of `tools::monoid::multiplies<float>` or `tools::group::multiplies<float>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<double>` and `MM` is either of `tools::monoid::multiplies<double>` or `tools::group::multiplies<double>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<long double>` and `MM` is either of `tools::monoid::multiplies<long double>` or `tools::group::multiplies<long double>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<std::complex<float>>` and `MM` is either of `tools::monoid::multiplies<std::complex<float>>` or `tools::group::multiplies<std::complex<float>>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<std::complex<double>>` and `MM` is either of `tools::monoid::multiplies<std::complex<double>>` or `tools::group::multiplies<std::complex<double>>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<std::complex<long double>>` and `MM` is either of `tools::monoid::multiplies<std::complex<long double>>` or `tools::group::multiplies<std::complex<long double>>`): $O((N + M) \log (N + M))$
- (`AG` is `tools::group::plus<R>` and `MM` is `tools::monoid::multiplies<R>` where $R$ is an integral type): $O((N + M) \log (N + M))$
- (otherwise): $O(NM \alpha \beta)$ where `AG::op` takes $\alpha$ time and `MM::op` takes $\beta$ time

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
void convolution(InputIterator1 a_begin, InputIterator1 a_end, InputIterator2 b_begin, InputIterator2 b_end, OutputIterator result);
```

It is equivalent to `convolution<tools::group::plus<R>, tools::monoid::multiplies<R>>(a_begin, a_end, b_begin, b_end)` where `R` is `std::decay_t<decltype(*std::declval<InputIterator1>())>`.

### Constraints
- `std::decay_t<decltype(*std::declval<InputIterator1>())>` and `std::decay_t<decltype(*std::declval<InputIterator2>())>` are the same type $R$.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $(x + y) + z = x + (y + z)$.
- For all $x$ in $R$, $0 + x = x + 0 = x$.
- For all $x$ in $R$, $(-x) + x = x + (-x) = 0$.
- For all $x$ in $R$ and $y$ in $R$, $x + y = y + x$.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $(x \cdot y) \cdot z = x \cdot (y \cdot z)$.
- For all $x$ in $R$, $1 \cdot x = x \cdot 1 = x$.
- For all $x$ in $R$ and $y$ in $R$, $x \cdot y = y \cdot x$.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $x \cdot (y + z) = (x \cdot y) + (x \cdot z)$.
- For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, $(x + y) \cdot z = (x \cdot z) + (y \cdot z)$.
- $R$ is assignable to `*result`.
- If $R$ is `atcoder::static_modint` or `atcoder::dynamic_modint`, $N + M \leq 2^{25} + 1 = 33554433$.
- If $R$ is an integral type, $N + M \leq 2^{24} + 1 = 16777217$ and all the elements of the array are in $R$ after convolution.

### Time Complexity
- ($R$ is `atcoder::static_modint`): $O((N + M) \log (N + M))$
- ($R$ is `atcoder::dynamic_modint`): $O((N + M) \log (N + M))$
- ($R$ is `float`): $O((N + M) \log (N + M))$
- ($R$ is `double`): $O((N + M) \log (N + M))$
- ($R$ is `long double`): $O((N + M) \log (N + M))$
- ($R$ is `std::complex<float>`): $O((N + M) \log (N + M))$
- ($R$ is `std::complex<double>`): $O((N + M) \log (N + M))$
- ($R$ is `std::complex<lond double>`): $O((N + M) \log (N + M))$
- ($R$ is an integral type): $O((N + M) \log (N + M))$
- (otherwise): $O(NM)$

### License
- CC0

### Author
- anqooqie
