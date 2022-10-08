---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tools/lower_bound.hpp
    title: std::lower_bound, but returns index
  _extendedRequiredBy:
  - icon: ':x:'
    path: tools/inversion_number.hpp
    title: The number of inversions
  - icon: ':x:'
    path: tools/lis.hpp
    title: Longest increasing subsequence
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/inversion_number.test.cpp
    title: tests/inversion_number.test.cpp
  - icon: ':x:'
    path: tests/lis.test.cpp
    title: tests/lis.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/compress.hpp\"\n\n\n\n#include <utility>\n#include\
    \ <map>\n#include <iterator>\n#include <vector>\n#include <algorithm>\n#line 1\
    \ \"tools/lower_bound.hpp\"\n\n\n\n#line 6 \"tools/lower_bound.hpp\"\n\nnamespace\
    \ tools {\n\n  template <class ForwardIterator, class T>\n  auto lower_bound(ForwardIterator\
    \ first, ForwardIterator last, const T& value) {\n    return ::std::distance(first,\
    \ ::std::lower_bound(first, last, value));\n  }\n\n  template <class ForwardIterator,\
    \ class T, class Compare>\n  auto lower_bound(ForwardIterator first, ForwardIterator\
    \ last, const T& value, Compare comp) {\n    return ::std::distance(first, ::std::lower_bound(first,\
    \ last, value, comp));\n  }\n}\n\n\n#line 10 \"tools/compress.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename InputIterator>\n  ::std::pair<\n    ::std::map<\n\
    \      typename ::std::iterator_traits<InputIterator>::value_type,\n      typename\
    \ ::std::iterator_traits<InputIterator>::value_type\n    >,\n    ::std::vector<typename\
    \ ::std::iterator_traits<InputIterator>::value_type>\n  > compress(InputIterator\
    \ begin, InputIterator end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \n    ::std::vector<T> g(begin, end);\n    ::std::sort(g.begin(), g.end());\n\
    \    g.erase(::std::unique(g.begin(), g.end()), g.end());\n\n    ::std::map<T,\
    \ T> f;\n    for (T i = 0; i < T(g.size()); ++i) {\n      f.emplace(g[i], i);\n\
    \    }\n\n    return ::std::make_pair(f, g);\n  }\n\n  template <typename InputIterator,\
    \ typename OutputIterator>\n  void compress(InputIterator begin, InputIterator\
    \ end, OutputIterator result) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    ::std::vector<T> orig(begin, end);\n    ::std::vector<T> sorted(orig);\n\
    \    ::std::sort(sorted.begin(), sorted.end());\n    sorted.erase(::std::unique(sorted.begin(),\
    \ sorted.end()), sorted.end());\n    for (auto it = orig.begin(); it != orig.end();\
    \ ++it, ++result) {\n      *result = ::tools::lower_bound(sorted.begin(), sorted.end(),\
    \ *it);\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_COMPRESS_HPP\n#define TOOLS_COMPRESS_HPP\n\n#include <utility>\n\
    #include <map>\n#include <iterator>\n#include <vector>\n#include <algorithm>\n\
    #include \"tools/lower_bound.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ InputIterator>\n  ::std::pair<\n    ::std::map<\n      typename ::std::iterator_traits<InputIterator>::value_type,\n\
    \      typename ::std::iterator_traits<InputIterator>::value_type\n    >,\n  \
    \  ::std::vector<typename ::std::iterator_traits<InputIterator>::value_type>\n\
    \  > compress(InputIterator begin, InputIterator end) {\n    using T = typename\
    \ ::std::iterator_traits<InputIterator>::value_type;\n\n    ::std::vector<T> g(begin,\
    \ end);\n    ::std::sort(g.begin(), g.end());\n    g.erase(::std::unique(g.begin(),\
    \ g.end()), g.end());\n\n    ::std::map<T, T> f;\n    for (T i = 0; i < T(g.size());\
    \ ++i) {\n      f.emplace(g[i], i);\n    }\n\n    return ::std::make_pair(f, g);\n\
    \  }\n\n  template <typename InputIterator, typename OutputIterator>\n  void compress(InputIterator\
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
  - tools/lis.hpp
  - tools/inversion_number.hpp
  timestamp: '2022-05-30 15:17:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - tests/lis.test.cpp
  - tests/inversion_number.test.cpp
documentation_of: tools/compress.hpp
layout: document
title: Compress values
---

## (1)

```cpp
template <typename InputIterator>
std::pair<std::map<typename std::iterator_traits<InputIterator>::value_type, typename std::iterator_traits<InputIterator>::value_type>, std::vector<typename std::iterator_traits<InputIterator>::value_type>> compress(InputIterator begin, InputIterator end);
```

It maps the $i$-th least integer in a given integer set to $i - 1$ and returns the mapping and the inverse mapping.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie

## (2)

```cpp
template <typename InputIterator, typename OutputIterator>
void compress(InputIterator begin, InputIterator end, OutputIterator result);
```

It maps the $i$-th least integer in a given integer sequence from `begin` to `end` to $i - 1$ and returns the mapped integer sequence.

### Constraints
- `begin` $\leq$ `end`

### Time Complexity
- $O(n \log n)$ where $n$ is `end` - `begin`

### License
- CC0

### Author
- anqooqie
