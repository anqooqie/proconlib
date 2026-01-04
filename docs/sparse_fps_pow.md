---
title: Power of a sparse FPS
documentation_of: //tools/sparse_fps_pow.hpp
---

## (1)

```cpp
template <std::ranges::input_range R>
requires tools::integral<std::tuple_element_t<0, std::ranges::range_value_t<R>>>
      && tools::modint<std::tuple_element_t<1, std::ranges::range_value_t<R>>>
tools::fps<std::tuple_element_t<1, std::ranges::range_value_t<R>>> sparse_fps_pow(R&& f, unsigned long long k, int n);
```

It returns $f^k$, the element of the ring $(\mathbb{Z}/p\mathbb{Z})[x]/(x^n)$.
$f = \sum_{i = 0}^{m - 1} f_i x^{d_i}$ is given as the list of degree-coefficient pairs $((d_0, f_0), (d_1, f_1), \ldots, (d_{m - 1}, f_{m - 1}))$.

### Constraints
- For any $i$, $d_i \geq 0$.
- $(d_0, d_1, \ldots, d_{m - 1})$ are sorted in ascending order.
- $(d_0, d_1, \ldots, d_{m - 1})$ are distinct.
- $p$ is a prime where $p$ is `M::mod()`.
- $0 \leq n \leq p$

### Time Complexity
- $O(nm + \log k + \log p)$

### License
- CC0

### Author
- anqooqie

## (2)

```cpp
template <std::ranges::input_range R1, std::ranges::input_range R2>
requires tools::integral<std::tuple_element_t<0, std::ranges::range_value_t<R1>>>
      && tools::modint<std::tuple_element_t<1, std::ranges::range_value_t<R1>>>
      && tools::integral<std::tuple_element_t<0, std::ranges::range_value_t<R2>>>
      && std::same_as<std::tuple_element_t<1, std::ranges::range_value_t<R1>>, std::tuple_element_t<1, std::ranges::range_value_t<R2>>>
tools::fps<std::tuple_element_t<1, std::ranges::range_value_t<R1>>> sparse_fps_pow(R1&& f, R2&& g, unsigned long long k, int n);
```

It returns $\left(\frac{f}{g}\right)^k$, the element of the ring $(\mathbb{Z}/p\mathbb{Z})[x]/(x^n)$.
$f = \sum_{i = 0}^{m_1 - 1} f_i x^{d_i}$ is given as the list of degree-coefficient pairs $((d_0, f_0), (d_1, f_1), \ldots, (d_{m_1 - 1}, f_{m_1 - 1}))$.
Also, $g = \sum_{i = 0}^{m_2 - 1} g_i x^{e_i}$ is given as the list of degree-coefficient pairs $((e_0, g_0), (e_1, g_1), \ldots, (e_{m_2 - 1}, g_{m_2 - 1}))$.

### Constraints
- For any $i$, $d_i \geq 0$.
- $(d_0, d_1, \ldots, d_{m - 1})$ are sorted in ascending order.
- $(d_0, d_1, \ldots, d_{m - 1})$ are distinct.
- $m_2 > 0$
- For any $i$, $e_i \geq 0$.
- $(e_0, e_1, \ldots, e_{m - 1})$ are sorted in ascending order.
- $(e_0, e_1, \ldots, e_{m - 1})$ are distinct.
- $e_0 = 0$
- $g_0 \neq 0$
- $p$ is a prime where $p$ is `M::mod()`.
- $0 \leq n \leq p$

### Time Complexity
- $O(n m_1 m_2 + \log k + \log p)$

### License
- CC0

### Author
- anqooqie
