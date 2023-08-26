---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/berlekamp_massey.hpp
    title: Berlekamp-Massey algorithm
  - icon: ':heavy_check_mark:'
    path: tools/bernoulli.hpp
    title: Bernoulli numbers $B_k \pmod{P}$ for $0 \leq k \leq n$
  - icon: ':heavy_check_mark:'
    path: tools/bostan_mori.hpp
    title: Bostan-Mori algorithm
  - icon: ':question:'
    path: tools/fps.hpp
    title: Formal power series
  - icon: ':heavy_check_mark:'
    path: tools/partially_persistent_dsu.hpp
    title: Partially persistent disjoint set union
  - icon: ':x:'
    path: tools/partition_function.hpp
    title: Partition function $P(i, i) \pmod{M}$ for $0 \leq i \leq n$ and $P(i, j)
      \pmod{M}$ for $0 \leq i \leq n, 0 \leq j \leq k$
  - icon: ':question:'
    path: tools/polynomial.hpp
    title: Polynomial
  - icon: ':x:'
    path: tools/sparse_fps_pow.hpp
    title: Power of a sparse FPS
  - icon: ':x:'
    path: tools/stirling_2nd.hpp
    title: Stirling numbers of the second kind $S(n, k) \pmod{P}$ for $0 \leq k \leq
      n$
  - icon: ':heavy_check_mark:'
    path: tools/wavelet_matrix.hpp
    title: Wavelet matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/berlekamp_massey.test.cpp
    title: tests/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bernoulli.test.cpp
    title: tests/bernoulli.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bostan_mori.test.cpp
    title: tests/bostan_mori.test.cpp
  - icon: ':x:'
    path: tests/fps/exp_mod998244353.test.cpp
    title: tests/fps/exp_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/exp_other_mods.test.cpp
    title: tests/fps/exp_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/inv_mod998244353.test.cpp
    title: tests/fps/inv_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/inv_other_mods.test.cpp
    title: tests/fps/inv_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/log_mod998244353.test.cpp
    title: tests/fps/log_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/log_other_mods.test.cpp
    title: tests/fps/log_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/pow_mod998244353.test.cpp
    title: tests/fps/pow_mod998244353.test.cpp
  - icon: ':x:'
    path: tests/fps/pow_other_mods.test.cpp
    title: tests/fps/pow_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/partially_persistent_dsu.test.cpp
    title: tests/partially_persistent_dsu.test.cpp
  - icon: ':x:'
    path: tests/partition_function/n.test.cpp
    title: tests/partition_function/n.test.cpp
  - icon: ':x:'
    path: tests/partition_function/n_k.test.cpp
    title: tests/partition_function/n_k.test.cpp
  - icon: ':x:'
    path: tests/polynomial/naive_division.test.cpp
    title: tests/polynomial/naive_division.test.cpp
  - icon: ':x:'
    path: tests/polynomial/ntt_division.test.cpp
    title: tests/polynomial/ntt_division.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/fraction.test.cpp
    title: tests/sparse_fps_pow/fraction.test.cpp
  - icon: ':x:'
    path: tests/sparse_fps_pow/regular.test.cpp
    title: tests/sparse_fps_pow/regular.test.cpp
  - icon: ':x:'
    path: tests/stirling_2nd.test.cpp
    title: tests/stirling_2nd.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/kth_smallest.test.cpp
    title: tests/wavelet_matrix/kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/next_points.test.cpp
    title: tests/wavelet_matrix/next_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/prev_points.test.cpp
    title: tests/wavelet_matrix/prev_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/range_freq.test.cpp
    title: tests/wavelet_matrix/range_freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/wavelet_matrix/range_prod.test.cpp
    title: tests/wavelet_matrix/range_prod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/less_by_first.hpp\"\n\n\n\n#include <utility>\n\n\
    namespace tools {\n\n  class less_by_first {\n  public:\n    template <class T1,\
    \ class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.first < y.first;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LESS_BY_FIRST_HPP\n#define TOOLS_LESS_BY_FIRST_HPP\n\n#include\
    \ <utility>\n\nnamespace tools {\n\n  class less_by_first {\n  public:\n    template\
    \ <class T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const\
    \ ::std::pair<T1, T2>& y) const {\n      return x.first < y.first;\n    }\n  };\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/less_by_first.hpp
  requiredBy:
  - tools/wavelet_matrix.hpp
  - tools/sparse_fps_pow.hpp
  - tools/bernoulli.hpp
  - tools/berlekamp_massey.hpp
  - tools/partition_function.hpp
  - tools/polynomial.hpp
  - tools/fps.hpp
  - tools/stirling_2nd.hpp
  - tools/bostan_mori.hpp
  - tools/partially_persistent_dsu.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/partition_function/n_k.test.cpp
  - tests/partition_function/n.test.cpp
  - tests/sparse_fps_pow/regular.test.cpp
  - tests/sparse_fps_pow/fraction.test.cpp
  - tests/polynomial/naive_division.test.cpp
  - tests/polynomial/ntt_division.test.cpp
  - tests/bostan_mori.test.cpp
  - tests/berlekamp_massey.test.cpp
  - tests/partially_persistent_dsu.test.cpp
  - tests/wavelet_matrix/range_freq.test.cpp
  - tests/wavelet_matrix/next_points.test.cpp
  - tests/wavelet_matrix/kth_smallest.test.cpp
  - tests/wavelet_matrix/range_prod.test.cpp
  - tests/wavelet_matrix/prev_points.test.cpp
  - tests/bernoulli.test.cpp
  - tests/stirling_2nd.test.cpp
  - tests/fps/log_mod998244353.test.cpp
  - tests/fps/inv_mod998244353.test.cpp
  - tests/fps/inv_other_mods.test.cpp
  - tests/fps/pow_other_mods.test.cpp
  - tests/fps/log_other_mods.test.cpp
  - tests/fps/exp_mod998244353.test.cpp
  - tests/fps/pow_mod998244353.test.cpp
  - tests/fps/exp_other_mods.test.cpp
documentation_of: tools/less_by_first.hpp
layout: document
title: std::less by first
---

It compares two pairs by the first element.

### Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::less_by_first());
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::less_by_first comp();
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T1, typename T2>
bool comp(std::pair<T1, T2> x, std::pair<T1, T2> y);
```

It returns `true` if `x.first < y.first`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
