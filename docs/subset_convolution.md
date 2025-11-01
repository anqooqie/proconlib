---
title: Subset convolution
documentation_of: //tools/subset_convolution.hpp
---

```cpp
(1)
template <std::ranges::input_range R1, std::ranges::input_range R2>
std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_type_t<R2>>> subset_convolution(R1&& a, R2&& b);

(2)
template <typename AG, typename MM, std::ranges::input_range R1, std::ranges::input_range R2>
std::vector<typename AG::T> subset_convolution(R1&& a, R2&& b);
```

Given size $2^N$ sequences $(a_0, a_1, \ldots, a_{2^N - 1})$ and $(b_0, b_1, \ldots, b_{2^N - 1})$, it returns the sequence $(c_0, c_1, \ldots, c_{2^N - 1})$ where $\displaystyle c_k = \sum_{\substack{(i~\mathrm{AND}~j) = 0\\\\ (i~\mathrm{OR}~j) = k}} a_i b_j$.
In (2), addition is defined by `AG` and multiplication is defined by `MM`.

### Constraints
- $\|a\|$ is a power of $2$.
- $\|b\|$ is a power of $2$.
- $\|a\| = \|b\|$
- (2)
    - `typename AG::T` and `typename MM::T` are the same.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `AG::op(AG::op(x, y), z)` $=$ `AG::op(x, AG::op(y, z))`.
    - For all $x$ in $R$, `AG::op(AG::e(), x)` $=$ `AG::op(x, AG::e())` $= x$.
    - For all $x$ in $R$, `AG::op(AG::inv(x), x)` $=$ `AG::op(x, AG::inv(x))` $=$ `AG::e()`.
    - For all $x$ in $R$ and $y$ in $R$, `AG::op(x, y)` $=$ `AG::op(y, x)`.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(MM::op(x, y), z)` $=$ `MM::op(x, MM::op(y, z))`.
    - For all $x$ in $R$, `MM::op(MM::e(), x)` $=$ `MM::op(x, MM::e())` $= x$.
    - For all $x$ in $R$ and $y$ in $R$, `MM::op(x, y)` $=$ `MM::op(y, x)`.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(x, AG::op(y, z))` $=$ `AG::op(MM::op(x, y), MM::op(x, z))`.
    - For all $x$ in $R$, $y$ in $R$ and $z$ in $R$, `MM::op(AG::op(x, y), z)` $=$ `AG::op(MM::op(x, z), MM::op(y, z))`.
    - `std::ranges::range_value_t<R1>` is assignable to `typename AG::T`.
    - `std::ranges::range_value_t<R2>` is assignable to `typename AG::T`.

### Time Complexity
- $O(2^N N^2)$

### License
- CC0

### Author
- anqooqie
