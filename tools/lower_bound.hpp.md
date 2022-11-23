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
    path: tools/li_chao_segtree.hpp
    title: Li Chao segment tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/inversion_number.test.cpp
    title: tests/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_segtree/line.test.cpp
    title: tests/li_chao_segtree/line.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/li_chao_segtree/segment.test.cpp
    title: tests/li_chao_segtree/segment.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/range_of_digit_products.test.cpp
    title: tests/range_of_digit_products.test.cpp
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
    \ T>\n  auto lower_bound(ForwardIterator first, ForwardIterator last, const T&\
    \ value) {\n    return ::std::distance(first, ::std::lower_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_LOWER_BOUND_HPP\n#define TOOLS_LOWER_BOUND_HPP\n\n#include\
    \ <iterator>\n#include <algorithm>\n\nnamespace tools {\n\n  template <class ForwardIterator,\
    \ class T>\n  auto lower_bound(ForwardIterator first, ForwardIterator last, const\
    \ T& value) {\n    return ::std::distance(first, ::std::lower_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/lower_bound.hpp
  requiredBy:
  - tools/li_chao_segtree.hpp
  - tools/inversion_number.hpp
  - tools/compress.hpp
  timestamp: '2022-05-30 15:17:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/li_chao_segtree/segment.test.cpp
  - tests/li_chao_segtree/line.test.cpp
  - tests/tsort.test.cpp
  - tests/range_of_digit_products.test.cpp
  - tests/inversion_number.test.cpp
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
