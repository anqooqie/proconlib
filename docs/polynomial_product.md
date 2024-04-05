---
title: Product of polynomials
documentation_of: //tools/polynomial_product.hpp
---

```cpp
(1)
template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type polynomial_product(InputIterator begin, InputIterator end);

(2)
template <typename P>
P polynomial_product(std::initializer_list<P> il);
```

Given $N$ polynomials $f_0(x), \cdots, f_{N - 1}(x)$, it returns $\prod_{i = 0}^{N - 1} f_i(x)$.
Note that it returns $1$ if $N = 0$.

### Constraints
- (1)
    - `typename std::iterator_traits<InputIterator>::value_type` is `tools::polynomial`.
- (2)
    - `P` is `tools::polynomial`.

### Time Complexity
- $O\left(D (\log D)^2\right)$ where $D$ is $\sum_{i = 0}^{N - 1} \mathrm{deg}(f_i)$

### License
- CC0

### Author
- anqooqie
