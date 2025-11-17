---
title: Subset convolution
documentation_of: //tools/subset_convolution.hpp
---

```cpp
(1)
template <std::ranges::input_range R1, std::ranges::input_range R2>
std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> subset_convolution(R1&& a, R2&& b);

(2)
template <tools::ring R, std::ranges::input_range R1, std::ranges::input_range R2>
requires std::assignable_from<typename R::add::T&, std::ranges::range_value_t<R1>>
      && std::assignable_from<typename R::add::T&, std::ranges::range_value_t<R2>>
std::vector<typename R::add::T> subset_convolution(R1&& a, R2&& b);
```

Given size $2^N$ sequences $(a_0, a_1, \ldots, a_{2^N - 1})$ and $(b_0, b_1, \ldots, b_{2^N - 1})$, it returns the sequence $(c_0, c_1, \ldots, c_{2^N - 1})$ where $\displaystyle c_k = \sum_{\substack{(i~\mathrm{AND}~j) = 0\\\\ (i~\mathrm{OR}~j) = k}} a_i b_j$.
In (2), addition and multiplication are defined by `R`.

### Constraints
- $\|a\|$ is a power of $2$.
- $\|b\|$ is a power of $2$.
- $\|a\| = \|b\|$

### Time Complexity
- $O(2^N N^2)$

### License
- CC0

### Author
- anqooqie
