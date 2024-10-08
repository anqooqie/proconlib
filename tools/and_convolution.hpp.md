---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  - icon: ':heavy_check_mark:'
    path: tools/superset_moebius.hpp
    title: "Superset M\xF6bius transform"
  - icon: ':heavy_check_mark:'
    path: tools/superset_zeta.hpp
    title: Superset Zeta transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/and_convolution/different_lengths.test.cpp
    title: tests/and_convolution/different_lengths.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/and_convolution/regular.test.cpp
    title: tests/and_convolution/regular.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/and_convolution.hpp\"\n\n\n\n#include <iterator>\n\
    #include <vector>\n#include <algorithm>\n#line 1 \"tools/superset_zeta.hpp\"\n\
    \n\n\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n#include <cstddef>\n\
    \nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 8 \"tools/superset_zeta.hpp\"\
    \n\nnamespace tools {\n  template <typename RandomAccessIterator>\n  void superset_zeta(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end) {\n    const int\
    \ N = end - begin;\n\n    for (int w = 0; ::tools::pow2(w) < N; ++w) {\n     \
    \ for (int i = 0; ; i += ::tools::pow2(w)) {\n        for (; !((i >> w) & 1);\
    \ ++i) {\n          if (!(i + ::tools::pow2(w) < N)) goto NEXT_W;\n          begin[i]\
    \ += begin[i + ::tools::pow2(w)];\n        }\n      }\n    NEXT_W:\n      ;\n\
    \    }\n  }\n\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void superset_zeta(const InputIterator begin, const InputIterator end, const\
    \ OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> a(begin, end);\n    ::tools::superset_zeta(a.begin(), a.end());\n\
    \    ::std::move(a.begin(), a.end(), result);\n  }\n}\n\n\n#line 1 \"tools/superset_moebius.hpp\"\
    \n\n\n\n#line 8 \"tools/superset_moebius.hpp\"\n\nnamespace tools {\n  template\
    \ <typename RandomAccessIterator>\n  void superset_moebius(const RandomAccessIterator\
    \ begin, const RandomAccessIterator end) {\n    const int N = end - begin;\n\n\
    \    for (int w = 0; ::tools::pow2(w) < N; ++w) {\n      for (int i = 0; ; i +=\
    \ ::tools::pow2(w)) {\n        for (; !((i >> w) & 1); ++i) {\n          if (!(i\
    \ + ::tools::pow2(w) < N)) goto NEXT_W;\n          begin[i] -= begin[i + ::tools::pow2(w)];\n\
    \        }\n      }\n    NEXT_W:\n      ;\n    }\n  }\n\n  template <typename\
    \ InputIterator, typename OutputIterator>\n  void superset_moebius(const InputIterator\
    \ begin, const InputIterator end, const OutputIterator result) {\n    using T\
    \ = typename ::std::iterator_traits<InputIterator>::value_type;\n    ::std::vector<T>\
    \ b(begin, end);\n    ::tools::superset_moebius(b.begin(), b.end());\n    ::std::move(b.begin(),\
    \ b.end(), result);\n  }\n}\n\n\n#line 9 \"tools/and_convolution.hpp\"\n\nnamespace\
    \ tools {\n  template <typename InputIterator, typename RandomAccessIterator>\n\
    \  void and_convolution(InputIterator a_begin, InputIterator a_end, InputIterator\
    \ b_begin, InputIterator b_end, RandomAccessIterator c_begin, RandomAccessIterator\
    \ c_end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> a(a_begin, a_end);\n    ::std::vector<T> b(b_begin, b_end);\n\
    \    const int N = a.size();\n    const int M = b.size();\n    const int K = ::std::distance(c_begin,\
    \ c_end);\n\n    ::tools::superset_zeta(a.begin(), a.end());\n    ::tools::superset_zeta(b.begin(),\
    \ b.end());\n\n    if (::std::min(N, M) <= K) {\n      for (int i = 0; i < ::std::min(N,\
    \ M); ++i) {\n        c_begin[i] = a[i] * b[i];\n      }\n      ::tools::superset_moebius(c_begin,\
    \ c_begin + ::std::min(N, M));\n      ::std::fill(c_begin + ::std::min(N, M),\
    \ c_end, T(0));\n    } else {\n      ::std::vector<T> c;\n      c.reserve(::std::min(N,\
    \ M));\n      for (int i = 0; i < ::std::min(N, M); ++i) {\n        c.push_back(a[i]\
    \ * b[i]);\n      }\n      ::tools::superset_moebius(c.begin(), c.end());\n  \
    \    ::std::move(c.begin(), c.begin() + K, c_begin);\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_AND_CONVOLUTION_HPP\n#define TOOLS_AND_CONVOLUTION_HPP\n\n\
    #include <iterator>\n#include <vector>\n#include <algorithm>\n#include \"tools/superset_zeta.hpp\"\
    \n#include \"tools/superset_moebius.hpp\"\n\nnamespace tools {\n  template <typename\
    \ InputIterator, typename RandomAccessIterator>\n  void and_convolution(InputIterator\
    \ a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, RandomAccessIterator\
    \ c_begin, RandomAccessIterator c_end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> a(a_begin, a_end);\n    ::std::vector<T> b(b_begin, b_end);\n\
    \    const int N = a.size();\n    const int M = b.size();\n    const int K = ::std::distance(c_begin,\
    \ c_end);\n\n    ::tools::superset_zeta(a.begin(), a.end());\n    ::tools::superset_zeta(b.begin(),\
    \ b.end());\n\n    if (::std::min(N, M) <= K) {\n      for (int i = 0; i < ::std::min(N,\
    \ M); ++i) {\n        c_begin[i] = a[i] * b[i];\n      }\n      ::tools::superset_moebius(c_begin,\
    \ c_begin + ::std::min(N, M));\n      ::std::fill(c_begin + ::std::min(N, M),\
    \ c_end, T(0));\n    } else {\n      ::std::vector<T> c;\n      c.reserve(::std::min(N,\
    \ M));\n      for (int i = 0; i < ::std::min(N, M); ++i) {\n        c.push_back(a[i]\
    \ * b[i]);\n      }\n      ::tools::superset_moebius(c.begin(), c.end());\n  \
    \    ::std::move(c.begin(), c.begin() + K, c_begin);\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/superset_zeta.hpp
  - tools/pow2.hpp
  - tools/superset_moebius.hpp
  isVerificationFile: false
  path: tools/and_convolution.hpp
  requiredBy: []
  timestamp: '2024-10-08 23:47:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/and_convolution/different_lengths.test.cpp
  - tests/and_convolution/regular.test.cpp
documentation_of: tools/and_convolution.hpp
layout: document
title: Bitwise AND convolution
---

```cpp
template <typename InputIterator, typename RandomAccessIterator>
void and_convolution(InputIterator a_begin, InputIterator a_end, InputIterator b_begin, InputIterator b_end, RandomAccessIterator c_begin, RandomAccessIterator c_end);
```

Given two infinite sequences $(a_0, a_1, \ldots, a_{N - 1}, 0, 0, \ldots)$ and $(b_0, b_1, \ldots, b_{M - 1}, 0, 0, \ldots)$, it returns the first $K$ terms of the infinite sequence $(c_0, c_1, \ldots)$ where

$$\begin{align*}
N &= \mathrm{a\_end} - \mathrm{a\_begin}\\
M &= \mathrm{b\_end} - \mathrm{b\_begin}\\
K &= \mathrm{c\_end} - \mathrm{c\_begin}\\
c_k &= \sum_{(i~\mathrm{AND}~j) = k} a_i b_j
\end{align*}$$

### Constraints
- `InputIterator` is an input iterator type.
- `RandomAccessIterator` is a random access iterator type.

### Time Complexity
- $O(N \log N + M \log M + K)$

### License
- CC0

### Author
- anqooqie
