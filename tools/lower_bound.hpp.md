---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/compress.hpp
    title: tools/compress.hpp
  - icon: ':heavy_check_mark:'
    path: tools/inversion_number.hpp
    title: tools/inversion_number.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/inversion_number.test.cpp
    title: tests/inversion_number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <algorithm>\n\nnamespace tools {\n\n  /**\n   * `std::lower_bound`, but returns\
    \ index\n   * License: CC0\n   * @author anqooqie\n   * @param <ForwardIterator>\
    \ type of iterator\n   * @param <T> type of value\n   * @return `std::distance(first,\
    \ std::lower_bound(first, last, value))`\n   */\n  template <class ForwardIterator,\
    \ class T>\n  typename ::std::iterator_traits<ForwardIterator>::difference_type\
    \ lower_bound(ForwardIterator first, ForwardIterator last, const T& value) {\n\
    \    return ::std::distance(first, ::std::lower_bound(first, last, value));\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_LOWER_BOUND_HPP\n#define TOOLS_LOWER_BOUND_HPP\n\n#include\
    \ <iterator>\n#include <algorithm>\n\nnamespace tools {\n\n  /**\n   * `std::lower_bound`,\
    \ but returns index\n   * License: CC0\n   * @author anqooqie\n   * @param <ForwardIterator>\
    \ type of iterator\n   * @param <T> type of value\n   * @return `std::distance(first,\
    \ std::lower_bound(first, last, value))`\n   */\n  template <class ForwardIterator,\
    \ class T>\n  typename ::std::iterator_traits<ForwardIterator>::difference_type\
    \ lower_bound(ForwardIterator first, ForwardIterator last, const T& value) {\n\
    \    return ::std::distance(first, ::std::lower_bound(first, last, value));\n\
    \  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/lower_bound.hpp
  requiredBy:
  - tools/compress.hpp
  - tools/inversion_number.hpp
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/inversion_number.test.cpp
documentation_of: tools/lower_bound.hpp
layout: document
redirect_from:
- /library/tools/lower_bound.hpp
- /library/tools/lower_bound.hpp.html
title: tools/lower_bound.hpp
---
