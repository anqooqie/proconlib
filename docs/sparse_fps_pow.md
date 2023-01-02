---
title: $f^k$ where $f$ is a sparse FPS
documentation_of: //tools/sparse_fps_pow.hpp
---

```cpp
template <typename InputIterator>
tools::fps<std::decay_t<decltype(std::declval<InputIterator>()->second)>> sparse_fps_pow(InputIterator begin, InputIterator end, unsigned long long k, std::size_t n);
```

It returns $f^k$, the element of the ring $(\mathbb{Z}/p\mathbb{Z})[x]/(x^n)$.
$f$ is given as the list of degree-coefficient pairs.

## Constraints
- `begin` $\leq$ `end`
- `*begin` is convertible to `std::pair<int, M>` where `M` is `atcoder::static_modint` or `atcoder::dynamic_modint`.
- `std::all_of(begin, end, [](std::pair<int, M> pair) { return pair.first >= 0; })`
- `std::is_sorted(begin, end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; })`
- `std::unique(begin, end, [](std::pair<int, M> pair1, std::pair<int, M> pair2) { return pair1.first < pair2.first; }) == end`
- $p$ is a prime where $p$ is `M::mod()`.
- $n \leq p$

## Time Complexity
- $O(nm + \log k + \log p)$ where $m$ is `end` $-$ `begin`

## License
- CC0

## Author
- anqooqie
