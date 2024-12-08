---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/and_convolution.hpp
    title: Bitwise AND convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/and_convolution/different_lengths.test.cpp
    title: tests/and_convolution/different_lengths.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/and_convolution/regular.test.cpp
    title: tests/and_convolution/regular.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/superset_moebius.test.cpp
    title: tests/superset_moebius.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/superset_moebius.hpp\"\n\n\n\n#include <iterator>\n\
    #include <vector>\n#include <algorithm>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include\
    \ <type_traits>\n#include <cstddef>\n\nnamespace tools {\n\n  template <typename\
    \ T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type\
    \ = nullptr>\n  constexpr T pow2(const T x) {\n    return static_cast<T>(1) <<\
    \ x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 8 \"tools/superset_moebius.hpp\"\
    \n\nnamespace tools {\n  template <typename RandomAccessIterator>\n  void superset_moebius(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end) {\n    const int\
    \ N = end - begin;\n\n    for (int w = 0; ::tools::pow2(w) < N; ++w) {\n     \
    \ for (int i = 0; ; i += ::tools::pow2(w)) {\n        for (; !((i >> w) & 1);\
    \ ++i) {\n          if (!(i + ::tools::pow2(w) < N)) goto NEXT_W;\n          begin[i]\
    \ -= begin[i + ::tools::pow2(w)];\n        }\n      }\n    NEXT_W:\n      ;\n\
    \    }\n  }\n\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void superset_moebius(const InputIterator begin, const InputIterator end, const\
    \ OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> b(begin, end);\n    ::tools::superset_moebius(b.begin(),\
    \ b.end());\n    ::std::move(b.begin(), b.end(), result);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SUPERSET_MOEBIUS_HPP\n#define TOOLS_SUPERSET_MOEBIUS_HPP\n\n\
    #include <iterator>\n#include <vector>\n#include <algorithm>\n#include \"tools/pow2.hpp\"\
    \n\nnamespace tools {\n  template <typename RandomAccessIterator>\n  void superset_moebius(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end) {\n    const int\
    \ N = end - begin;\n\n    for (int w = 0; ::tools::pow2(w) < N; ++w) {\n     \
    \ for (int i = 0; ; i += ::tools::pow2(w)) {\n        for (; !((i >> w) & 1);\
    \ ++i) {\n          if (!(i + ::tools::pow2(w) < N)) goto NEXT_W;\n          begin[i]\
    \ -= begin[i + ::tools::pow2(w)];\n        }\n      }\n    NEXT_W:\n      ;\n\
    \    }\n  }\n\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void superset_moebius(const InputIterator begin, const InputIterator end, const\
    \ OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> b(begin, end);\n    ::tools::superset_moebius(b.begin(),\
    \ b.end());\n    ::std::move(b.begin(), b.end(), result);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/superset_moebius.hpp
  requiredBy:
  - tools/and_convolution.hpp
  timestamp: '2024-10-07 00:03:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/and_convolution/regular.test.cpp
  - tests/and_convolution/different_lengths.test.cpp
  - tests/superset_moebius.test.cpp
documentation_of: tools/superset_moebius.hpp
layout: document
title: "Superset M\xF6bius transform"
---

```cpp
(1)
template <typename InputIterator, typename OutputIterator>
void superset_moebius(InputIterator begin, InputIterator end, OutputIterator result);

(2)
template <typename RandomAccessIterator>
void superset_moebius(RandomAccessIterator begin, RandomAccessIterator end);
```

- (1)
    - Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ that satisfies the following relational equation to `result`.
- (2)
    - Given a sequence $(b_0, b_1, \ldots, b_{N - 1})$ from `begin` and `end`, it stores the sequence $(a_0, a_1, \ldots, a_{N - 1})$ that satisfies the following relational equation to `begin`.

The following relationship holds between $a$ and $b$.

$$\begin{align*}
b_i &= \sum_{\substack{0 \leq j < N \\ (i~\mathrm{AND}~j) = i}} a_j
\end{align*}$$

### Constraints
- None
    - Note that `result` in (1) can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
