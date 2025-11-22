---
title: Product of polynomials
documentation_of: //tools/polynomial_product.hpp
---

```cpp
template <std::ranges::input_range R>
requires tools::specialization_of<std::ranges::range_value_t<R>, tools::polynomial>
std::ranges::range_value_t<R> polynomial_product(R&& f);
```

Given $N$ polynomials $f_0(x), \cdots, f_{N - 1}(x)$, it returns $\prod_{i = 0}^{N - 1} f_i(x)$.
Note that it returns $1$ if $N = 0$.

### Constraints
- None

### Time Complexity
- $O\left(D (\log D)^2\right)$ where $D$ is $\sum_{i = 0}^{N - 1} \mathrm{deg}(f_i)$

### License
- CC0

### Author
- anqooqie
