---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/superset_zeta.test.cpp
    title: tests/superset_zeta.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/superset_zeta.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <vector>\n#include <algorithm>\n#line 1 \"tools/pow2.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <cstddef>\n\nnamespace tools {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
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
    \    ::std::move(a.begin(), a.end(), result);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SUPERSET_ZETA_HPP\n#define TOOLS_SUPERSET_ZETA_HPP\n\n#include\
    \ <iterator>\n#include <vector>\n#include <algorithm>\n#include \"tools/pow2.hpp\"\
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
    \    ::std::move(a.begin(), a.end(), result);\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/superset_zeta.hpp
  requiredBy: []
  timestamp: '2024-10-07 00:03:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/superset_zeta.test.cpp
documentation_of: tools/superset_zeta.hpp
layout: document
title: Superset Zeta transform
---

## (1)
```cpp
template <typename InputIterator, typename OutputIterator>
void superset_zeta(InputIterator begin, InputIterator end, OutputIterator result);
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ to `result` such that

$$\begin{align*}
b_i &= \sum_{(i~\mathrm{AND}~j) = i} a_j
\end{align*}$$

### Constraints
- None
    - Note that `result` can be the same as `begin`, but it would be better to use (2) in that case.

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie

## (2)
```cpp
template <typename RandomAccessIterator>
void superset_zeta(RandomAccessIterator begin, RandomAccessIterator end);
```

Given a sequence $(a_0, a_1, \ldots, a_{N - 1})$ from `begin` and `end`, it stores the sequence $(b_0, b_1, \ldots, b_{N - 1})$ to `begin` such that

$$\begin{align*}
b_i &= \sum_{(i~\mathrm{AND}~j) = i} a_j
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(N \log N)$

### License
- CC0

### Author
- anqooqie
