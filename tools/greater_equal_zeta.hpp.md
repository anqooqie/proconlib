---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/greater_equal_zeta.test.cpp
    title: tests/greater_equal_zeta.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/greater_equal_zeta.hpp\"\n\n\n\n#include <iterator>\n\
    #include <vector>\n#include <algorithm>\n\nnamespace tools {\n  template <typename\
    \ RandomAccessIterator>\n  void greater_equal_zeta(const RandomAccessIterator\
    \ begin, const RandomAccessIterator end) {\n    const int N = end - begin;\n \
    \   for (int i = N - 2; i >= 0; --i) {\n      begin[i] += begin[i + 1];\n    }\n\
    \  }\n\n  template <typename InputIterator, typename OutputIterator>\n  void greater_equal_zeta(const\
    \ InputIterator begin, const InputIterator end, const OutputIterator result) {\n\
    \    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n \
    \   ::std::vector<T> a(begin, end);\n    ::tools::greater_equal_zeta(a.begin(),\
    \ a.end());\n    ::std::move(a.begin(), a.end(), result);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_GREATER_EQUAL_ZETA_HPP\n#define TOOLS_GREATER_EQUAL_ZETA_HPP\n\
    \n#include <iterator>\n#include <vector>\n#include <algorithm>\n\nnamespace tools\
    \ {\n  template <typename RandomAccessIterator>\n  void greater_equal_zeta(const\
    \ RandomAccessIterator begin, const RandomAccessIterator end) {\n    const int\
    \ N = end - begin;\n    for (int i = N - 2; i >= 0; --i) {\n      begin[i] +=\
    \ begin[i + 1];\n    }\n  }\n\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void greater_equal_zeta(const InputIterator begin, const InputIterator end,\
    \ const OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> a(begin, end);\n    ::tools::greater_equal_zeta(a.begin(),\
    \ a.end());\n    ::std::move(a.begin(), a.end(), result);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/greater_equal_zeta.hpp
  requiredBy: []
  timestamp: '2024-11-02 18:34:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/greater_equal_zeta.test.cpp
documentation_of: tools/greater_equal_zeta.hpp
layout: document
title: Find $b$ from $a$ when $b_i = \sum_{j = i}^{N - 1} a_j$ holds
---

```cpp
(1)
template <typename InputIterator, typename OutputIterator>
void greater_equal_zeta(InputIterator begin, InputIterator end, OutputIterator result);

(2)
template <typename RandomAccessIterator>
void greater_equal_zeta(RandomAccessIterator begin, RandomAccessIterator end);
```

- (1)
    - Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ that satisfies the following relational equation to `result`.
- (2)
    - Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ that satisfies the following relational equation to `begin`.

The following relationship holds between $a$ and $b$.

$$\begin{align*}
b_i &= \sum_{i \leq j < N} a_j
\end{align*}$$

### Constraints
- None
    - Note that `result` in (1) can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N)$

### License
- CC0

### Author
- anqooqie
