---
title: Product of binomials
documentation_of: //tools/binomial_product.hpp
---

```cpp
template <std::ranges::input_range R>
requires tools::modint<std::tuple_element_t<0, std::ranges::range_value_t<R>>>
      && std::same_as<std::tuple_element_t<1, std::ranges::range_value_t<R>>, std::tuple_element_t<0, std::ranges::range_value_t<R>>>
      && std::integral<std::tuple_element_t<2, std::ranges::range_value_t<R>>>
      && std::integral<std::tuple_element_t<3, std::ranges::range_value_t<R>>>
tools::fps<std::tuple_element_t<0, std::ranges::range_value_t<R>>> binomial_product(R&& f, int n);
```

Given $(a_i, b_i, c_i, d_i) \in \mathbb{Z}/M\mathbb{Z} \times \mathbb{Z}/M\mathbb{Z} \times \mathbb{Z}\_{\geqslant 0} \times \mathbb{Z}\_{\geqslant 0}$ for $i = 0, 1, \ldots, m - 1$, it returns the first $n$ terms of $\prod_{i = 0}^{m - 1} (a_i + b_i x^{c_i})^{d_i}$.

### Constraints
- $0 \leq n \leq \mathrm{lpf}(M)$
- $c_i \geq 0$
- $d_i \geq 0$
- $i \neq j \Rightarrow c_i \neq c_j$

### Time Complexity
- $\displaystyle O\left(n \log n + \sum_{i=0}^{m - 1} \log d_i\right)$

### License
- CC0

### Author
- anqooqie
