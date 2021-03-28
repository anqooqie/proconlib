---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/lower_bound.hpp
    title: tools/lower_bound.hpp
  _extendedRequiredBy:
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
  bundledCode: "#line 1 \"tools/compress.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <vector>\n#include <algorithm>\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#line\
    \ 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  /**\n   * `std::lower_bound`,\
    \ but returns index\n   * License: CC0\n   * @author anqooqie\n   * @param <ForwardIterator>\
    \ type of iterator\n   * @param <T> type of value\n   * @return `std::distance(first,\
    \ std::lower_bound(first, last, value))`\n   */\n  template <class ForwardIterator,\
    \ class T>\n  typename ::std::iterator_traits<ForwardIterator>::difference_type\
    \ lower_bound(ForwardIterator first, ForwardIterator last, const T& value) {\n\
    \    return ::std::distance(first, ::std::lower_bound(first, last, value));\n\
    \  }\n}\n\n\n#line 8 \"tools/compress.hpp\"\n\nnamespace tools {\n\n  /**\n  \
    \ * compresses the values while keeping its magnitude relationship\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param <InputIterator> type of the input iterators\n\
    \   * @param <OutputIterator> type of the output iterator\n   * @param begin beginning\
    \ of the input iterator\n   * @param end end of the input iterator\n   * @param\
    \ result beginning of the output iterator\n   */\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void compress(InputIterator begin, InputIterator\
    \ end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n\
    \    ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_COMPRESS_HPP\n#define TOOLS_COMPRESS_HPP\n\n#include <iterator>\n\
    #include <vector>\n#include <algorithm>\n#include \"tools/lower_bound.hpp\"\n\n\
    namespace tools {\n\n  /**\n   * compresses the values while keeping its magnitude\
    \ relationship\n   * License: CC0\n   * @author anqooqie\n   * @param <InputIterator>\
    \ type of the input iterators\n   * @param <OutputIterator> type of the output\
    \ iterator\n   * @param begin beginning of the input iterator\n   * @param end\
    \ end of the input iterator\n   * @param result beginning of the output iterator\n\
    \   */\n  template <typename InputIterator, typename OutputIterator>\n  void compress(InputIterator\
    \ begin, InputIterator end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n\
    \    ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/lower_bound.hpp
  isVerificationFile: false
  path: tools/compress.hpp
  requiredBy:
  - tools/inversion_number.hpp
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/inversion_number.test.cpp
documentation_of: tools/compress.hpp
layout: document
redirect_from:
- /library/tools/compress.hpp
- /library/tools/compress.hpp.html
title: tools/compress.hpp
---
