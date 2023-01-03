---
title: Power of a sparse FPS
documentation_of: //tools/sparse_fps_pow.hpp
---

## (1)

```cpp
template <typename InputIterator>
tools::fps<std::decay_t<decltype(std::declval<InputIterator>()->second)>> sparse_fps_pow(InputIterator begin, InputIterator end, unsigned long long k, std::size_t n);
```

It returns $f^k$, the element of the ring $(\mathbb{Z}/p\mathbb{Z})[x]/(x^n)$.
$f$ is given as the list of degree-coefficient pairs.

### Constraints
- `begin` $\leq$ `end`
- `*begin` is convertible to `std::pair<int, M>` where `M` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `std::all_of(begin, end, [](std::pair<int, M> pair) { return pair.first >= 0; })`
- `std::is_sorted(begin, end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; })`
- `std::unique(begin, end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; }) == end`
- $p$ is a prime where $p$ is `M::mod()`.
- $n \leq p$

### Time Complexity
- $O(nm + \log k + \log p)$ where $m$ is `end` $-$ `begin`

### License
- CC0

### Author
- anqooqie

## (2)

```cpp
template <typename InputIterator>
tools::fps<std::decay_t<decltype(std::declval<InputIterator>()->second)>> sparse_fps_pow(InputIterator f_begin, InputIterator f_end, InputIterator g_begin, InputIterator g_end, unsigned long long k, std::size_t n);
```

It returns $\left(\frac{f}{g}\right)^k$, the element of the ring $(\mathbb{Z}/p\mathbb{Z})[x]/(x^n)$.
Each of $f$ and $g$ is given as the list of degree-coefficient pairs.

### Constraints
- `f_begin` $\leq$ `f_end`
- `*f_begin` is convertible to `std::pair<int, M>` where `M` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `std::all_of(f_begin, f_end, [](std::pair<int, M> pair) { return pair.first >= 0; })`
- `std::is_sorted(f_begin, f_end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; })`
- `std::unique(f_begin, f_end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; }) == f_end`
- `g_begin` $<$ `g_end`
- `*g_begin` is convertible to `std::pair<int, M>`.
- `std::all_of(g_begin, g_end, [](std::pair<int, M> pair) { return pair.first >= 0; })`
- `std::is_sorted(g_begin, g_end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; })`
- `std::unique(g_begin, g_end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; }) == g_end`
- `g_begin->first == 0`
- `g_begin->second != M(0)`
- $p$ is a prime where $p$ is `M::mod()`.
- $n \leq p$

### Time Complexity
- $O(n m_1 m_2 + \log k + \log p)$ where $m_1$ is `f_end` $-$ `f_begin` and $m_2$ is `g_end` $-$ `g_begin`

### License
- CC0

### Author
- anqooqie
