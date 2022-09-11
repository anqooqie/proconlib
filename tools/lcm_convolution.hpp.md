---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/osa_k.hpp
    title: osa_k's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/lcm_convolution.test.cpp
    title: tests/lcm_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tools/lcm_convolution.hpp: line 9: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#ifndef TOOLS_LCM_CONVOLUTION_HPP\n#define TOOLS_LCM_CONVOLUITON_HPP\n\n\
    #include <type_traits>\n#include <vector>\n#include <algorithm>\n#include <cstddef>\n\
    #include <iterator>\n#include \"tools/osa_k.hpp\"\n\nnamespace tools {\n  template\
    \ <typename InputIterator, typename OutputIterator>\n  void lcm_convolution(InputIterator\
    \ a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator\
    \ c_begin, OutputIterator c_end) {\n    if (c_begin == c_end) return;\n\n    using\
    \ T = ::std::decay_t<decltype(*a_begin)>;\n    ::std::vector<T> a(a_begin, a_end);\n\
    \    ::std::vector<T> b(b_begin, b_end);\n    ::std::fill(c_begin, c_end, T(0));\n\
    \    if (a.empty() || b.empty()) {\n      return;\n    }\n    const ::std::size_t\
    \ N = a.size();\n    const ::std::size_t M = b.size();\n    const ::std::size_t\
    \ K = ::std::distance(c_begin, c_end);\n\n    c_begin[0] = a[0] * b[0];\n    for\
    \ (::std::size_t i = 1; i < N; ++i) {\n      c_begin[0] += a[i] * b[0];\n    }\n\
    \    for (::std::size_t i = 1; i < M; ++i) {\n      c_begin[0] += a[0] * b[i];\n\
    \    }\n\n    a.resize(K, T(0));\n    b.resize(K, T(0));\n    ::tools::osa_k<::std::size_t>\
    \ osa_k(K);\n    for (const auto p : osa_k.prime_range(1, K)) {\n      for (::std::size_t\
    \ k = 1; k * p < K; ++k) {\n        a[k * p] += a[k];\n        b[k * p] += b[k];\n\
    \      }\n    }\n\n    for (::std::size_t i = 1; i < K; ++i) {\n      c_begin[i]\
    \ = a[i] * b[i];\n    }\n\n    for (const auto p : osa_k.prime_range(1, K)) {\n\
    \      for (::std::size_t k = (K - 1) / p; k >= 1; --k) {\n        c_begin[k *\
    \ p] -= c_begin[k];\n      }\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/osa_k.hpp
  isVerificationFile: false
  path: tools/lcm_convolution.hpp
  requiredBy: []
  timestamp: '2022-09-11 13:33:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/lcm_convolution.test.cpp
documentation_of: tools/lcm_convolution.hpp
layout: document
title: LCM convolution
---

```cpp
template <typename InputIterator, typename OutputIterator>
void gcd_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end);
```

Given two infinite sequences $(a_0, a_1, \ldots, a_{N - 1}, 0, 0, \ldots)$ and $(b_0, b_1, \ldots, b_{M - 1}, 0, 0, \ldots)$, it returns the first $K$ terms of the infinite sequence $(c_0, c_1, \ldots)$ where

$$\begin{align*}
N &= \mathrm{a\_end} - \mathrm{a\_begin}\\
M &= \mathrm{b\_end} - \mathrm{b\_begin}\\
K &= \mathrm{c\_end} - \mathrm{c\_begin}\\
c_k &= \sum_{\mathrm{lcm}(i, j) = k} a_i b_j
\end{align*}$$

Note that we define $\mathrm{lcm}(x, 0) = \mathrm{lcm}(0, y) = \mathrm{lcm}(0, 0) = 0$ in this function.

## Constraints
- `a_begin` $\leq$ `a_end`
- `b_begin` $\leq$ `b_end`
- `c_begin` $\leq$ `c_end`

## Time Complexity
- $O(N + M + K \log\log K)$

## License
- CC0

## Author
- anqooqie
