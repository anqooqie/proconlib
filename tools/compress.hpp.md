---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/inversion_number.hpp
    title: The number of inversions
  - icon: ':x:'
    path: tools/range_count_distinct.hpp
    title: Range count distinct
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/inversion_number.test.cpp
    title: tests/inversion_number.test.cpp
  - icon: ':x:'
    path: tests/range_count_distinct.test.cpp
    title: tests/range_count_distinct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/compress.hpp\"\n\n\n\n#include <iterator>\n#include\
    \ <vector>\n#include <algorithm>\n#line 1 \"tools/lower_bound.hpp\"\n\n\n\n#line\
    \ 6 \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template <class ForwardIterator,\
    \ class T>\n  auto lower_bound(ForwardIterator first, ForwardIterator last, const\
    \ T& value) {\n    return ::std::distance(first, ::std::lower_bound(first, last,\
    \ value));\n  }\n\n  template <class ForwardIterator, class T, class Compare>\n\
    \  auto lower_bound(ForwardIterator first, ForwardIterator last, const T& value,\
    \ Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 8 \"tools/compress.hpp\"\n\nnamespace\
    \ tools {\n  template <typename InputIterator, typename OutputIterator>\n  void\
    \ compress(InputIterator begin, InputIterator end, OutputIterator result) {\n\
    \    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n \
    \   ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n \
    \   ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_COMPRESS_HPP\n#define TOOLS_COMPRESS_HPP\n\n#include <iterator>\n\
    #include <vector>\n#include <algorithm>\n#include \"tools/lower_bound.hpp\"\n\n\
    namespace tools {\n  template <typename InputIterator, typename OutputIterator>\n\
    \  void compress(InputIterator begin, InputIterator end, OutputIterator result)\
    \ {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
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
  - tools/range_count_distinct.hpp
  - tools/inversion_number.hpp
  timestamp: '2023-06-28 13:29:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/inversion_number.test.cpp
  - tests/range_count_distinct.test.cpp
documentation_of: tools/compress.hpp
layout: document
title: Compress values
---

```cpp
template <typename InputIterator, typename OutputIterator>
void compress(InputIterator begin, InputIterator end, OutputIterator result);
```

It maps the $i$-th ($0$-indexed) least integer in a given integer sequence from `begin` to `end` to $i$ and returns the mapped integer sequence.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie
