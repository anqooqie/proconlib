---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/and_convolution.test.cpp
    title: tests/and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/and_convolution.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <vector>\n#include <cstddef>\n#include <iterator>\n#include <algorithm>\n\
    #line 1 \"tools/pow2.hpp\"\n\n\n\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 10 \"tools/and_convolution.hpp\"\
    \n\nnamespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void and_convolution(InputIterator a_begin, InputIterator a_end, InputIterator\
    \ b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end)\
    \ {\n    using T = ::std::decay_t<decltype(*a_begin)>;\n    ::std::vector<T> a(a_begin,\
    \ a_end);\n    ::std::vector<T> b(b_begin, b_end);\n    const ::std::size_t N\
    \ = a.size();\n    const ::std::size_t M = b.size();\n    const ::std::size_t\
    \ K = ::std::distance(c_begin, c_end);\n\n    for (::std::size_t i = 0; ::tools::pow2(i)\
    \ < N; ++i) {\n      for (::std::size_t state = 0, lower, upper; lower = ((state\
    \ & ~(::tools::pow2(i) - 1)) << 1) | (state & (::tools::pow2(i) - 1)), (upper\
    \ = lower | ::tools::pow2(i)) < N; ++state) {\n        a[lower] += a[upper];\n\
    \      }\n    }\n    for (::std::size_t i = 0; ::tools::pow2(i) < M; ++i) {\n\
    \      for (::std::size_t state = 0, lower, upper; lower = ((state & ~(::tools::pow2(i)\
    \ - 1)) << 1) | (state & (::tools::pow2(i) - 1)), (upper = lower | ::tools::pow2(i))\
    \ < M; ++state) {\n        b[lower] += b[upper];\n      }\n    }\n\n    for (::std::size_t\
    \ i = 0; i < ::std::min({N, M, K}); ++i) {\n      c_begin[i] = a[i] * b[i];\n\
    \    }\n    ::std::fill(::std::next(c_begin, ::std::min({N, M, K})), c_end, T(0));\n\
    \n    for (::std::size_t i = 0; ::tools::pow2(i) < K; ++i) {\n      for (::std::size_t\
    \ state = 0, lower, upper; lower = ((state & ~(::tools::pow2(i) - 1)) << 1) |\
    \ (state & (::tools::pow2(i) - 1)), (upper = lower | ::tools::pow2(i)) < K; ++state)\
    \ {\n        c_begin[lower] -= c_begin[upper];\n      }\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_AND_CONVOLUTION_HPP\n#define TOOLS_AND_CONVOLUTION_HPP\n\n\
    #include <type_traits>\n#include <vector>\n#include <cstddef>\n#include <iterator>\n\
    #include <algorithm>\n#include \"tools/pow2.hpp\"\n\nnamespace tools {\n  template\
    \ <typename InputIterator, typename OutputIterator>\n  void and_convolution(InputIterator\
    \ a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator\
    \ c_begin, OutputIterator c_end) {\n    using T = ::std::decay_t<decltype(*a_begin)>;\n\
    \    ::std::vector<T> a(a_begin, a_end);\n    ::std::vector<T> b(b_begin, b_end);\n\
    \    const ::std::size_t N = a.size();\n    const ::std::size_t M = b.size();\n\
    \    const ::std::size_t K = ::std::distance(c_begin, c_end);\n\n    for (::std::size_t\
    \ i = 0; ::tools::pow2(i) < N; ++i) {\n      for (::std::size_t state = 0, lower,\
    \ upper; lower = ((state & ~(::tools::pow2(i) - 1)) << 1) | (state & (::tools::pow2(i)\
    \ - 1)), (upper = lower | ::tools::pow2(i)) < N; ++state) {\n        a[lower]\
    \ += a[upper];\n      }\n    }\n    for (::std::size_t i = 0; ::tools::pow2(i)\
    \ < M; ++i) {\n      for (::std::size_t state = 0, lower, upper; lower = ((state\
    \ & ~(::tools::pow2(i) - 1)) << 1) | (state & (::tools::pow2(i) - 1)), (upper\
    \ = lower | ::tools::pow2(i)) < M; ++state) {\n        b[lower] += b[upper];\n\
    \      }\n    }\n\n    for (::std::size_t i = 0; i < ::std::min({N, M, K}); ++i)\
    \ {\n      c_begin[i] = a[i] * b[i];\n    }\n    ::std::fill(::std::next(c_begin,\
    \ ::std::min({N, M, K})), c_end, T(0));\n\n    for (::std::size_t i = 0; ::tools::pow2(i)\
    \ < K; ++i) {\n      for (::std::size_t state = 0, lower, upper; lower = ((state\
    \ & ~(::tools::pow2(i) - 1)) << 1) | (state & (::tools::pow2(i) - 1)), (upper\
    \ = lower | ::tools::pow2(i)) < K; ++state) {\n        c_begin[lower] -= c_begin[upper];\n\
    \      }\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/and_convolution.hpp
  requiredBy: []
  timestamp: '2022-09-17 11:30:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/and_convolution.test.cpp
documentation_of: tools/and_convolution.hpp
layout: document
title: Bitwise AND convolution
---

```cpp
template <typename InputIterator, typename OutputIterator>
void and_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, OutputIterator c_begin, OutputIterator c_end);
```

Given two infinite sequences $(a_0, a_1, \ldots, a_{N - 1}, 0, 0, \ldots)$ and $(b_0, b_1, \ldots, b_{M - 1}, 0, 0, \ldots)$, it returns the first $K$ terms of the infinite sequence $(c_0, c_1, \ldots)$ where

$$\begin{align*}
N &= \mathrm{a\_end} - \mathrm{a\_begin}\\
M &= \mathrm{b\_end} - \mathrm{b\_begin}\\
K &= \mathrm{c\_end} - \mathrm{c\_begin}\\
c_k &= \sum_{(i \& j) = k} a_i b_j
\end{align*}$$

### Constraints
- `a_begin` $\leq$ `a_end`
- `b_begin` $\leq$ `b_end`
- `c_begin` $\leq$ `c_end`

### Time Complexity
- $O(N \log N + M \log M + K \log K)$

### License
- CC0

### Author
- anqooqie
