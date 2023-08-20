---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/range_of_digit_products.test.cpp
    title: tests/range_of_digit_products.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/upper_bound.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <algorithm>\n\nnamespace tools {\n\n  template <class ForwardIterator, class\
    \ T>\n  auto upper_bound(ForwardIterator first, ForwardIterator last, const T&\
    \ value) {\n    return ::std::distance(first, ::std::upper_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto upper_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::upper_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_UPPER_BOUND_HPP\n#define TOOLS_UPPER_BOUND_HPP\n\n#include\
    \ <iterator>\n#include <algorithm>\n\nnamespace tools {\n\n  template <class ForwardIterator,\
    \ class T>\n  auto upper_bound(ForwardIterator first, ForwardIterator last, const\
    \ T& value) {\n    return ::std::distance(first, ::std::upper_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto upper_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::upper_bound(first,\
    \ last, value, comp));\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/upper_bound.hpp
  requiredBy: []
  timestamp: '2022-05-30 15:17:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/range_of_digit_products.test.cpp
documentation_of: tools/upper_bound.hpp
layout: document
title: std::upper_bound, but returns index
---

```cpp
template <class ForwardIterator, class T>
typename ::std::iterator_traits<ForwardIterator>::difference_type upper_bound(ForwardIterator first, ForwardIterator last, T value);
```

It returns `std::distance(first, std::upper_bound(first, last, value))`;

## License
- CC0

## Author
- anqooqie
