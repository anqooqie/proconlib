---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/compress.hpp
    title: Compress values
  - icon: ':heavy_check_mark:'
    path: tools/inversion_number.hpp
    title: The number of inversions
  - icon: ':heavy_check_mark:'
    path: tools/lis.hpp
    title: Longest increasing subsequence
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/inversion_number.test.cpp
    title: tests/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/lis.test.cpp
    title: tests/lis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tsort.test.cpp
    title: tests/tsort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <algorithm>\n\nnamespace tools {\n\n  template <class ForwardIterator, class\
    \ T>\n  typename ::std::iterator_traits<ForwardIterator>::difference_type lower_bound(ForwardIterator\
    \ first, ForwardIterator last, const T& value) {\n    return ::std::distance(first,\
    \ ::std::lower_bound(first, last, value));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_LOWER_BOUND_HPP\n#define TOOLS_LOWER_BOUND_HPP\n\n#include\
    \ <iterator>\n#include <algorithm>\n\nnamespace tools {\n\n  template <class ForwardIterator,\
    \ class T>\n  typename ::std::iterator_traits<ForwardIterator>::difference_type\
    \ lower_bound(ForwardIterator first, ForwardIterator last, const T& value) {\n\
    \    return ::std::distance(first, ::std::lower_bound(first, last, value));\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/lower_bound.hpp
  requiredBy:
  - tools/lis.hpp
  - tools/compress.hpp
  - tools/inversion_number.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/inversion_number.test.cpp
  - tests/tsort.test.cpp
  - tests/lis.test.cpp
documentation_of: tools/lower_bound.hpp
layout: document
title: std::lower_bound, but returns index
---

```cpp
template <class ForwardIterator, class T>
typename ::std::iterator_traits<ForwardIterator>::difference_type lower_bound(ForwardIterator first, ForwardIterator last, T value);
```

It returns `std::distance(first, std::lower_bound(first, last, value))`;

## License
- CC0

## Author
- anqooqie
