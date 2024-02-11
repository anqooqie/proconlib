---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/longest_common_substring.hpp
    title: Longest common substring
  - icon: ':heavy_check_mark:'
    path: tools/range_count_distinct.hpp
    title: Range count distinct
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/longest_common_substring.test.cpp
    title: tests/longest_common_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/mex.test.cpp
    title: tests/mex.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/range_count_distinct.test.cpp
    title: tests/range_count_distinct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/mex.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <utility>\n#include <vector>\n#include <cstddef>\n#include <cassert>\n#include\
    \ <algorithm>\n\nnamespace tools {\n\n  template <typename InputIterator>\n  ::std::decay_t<decltype(*::std::declval<InputIterator>())>\
    \ mex(InputIterator begin, InputIterator end) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const ::std::size_t n = orig.size();\n\
    \n    assert(::std::all_of(orig.begin(), orig.end(), [](const auto& o) { return\
    \ o >= 0; }));\n\n    ::std::vector<bool> exists(n, false);\n    for (const ::std::size_t\
    \ o : orig) {\n      if (o < n) {\n        exists[o] = true;\n      }\n    }\n\
    \    for (::std::size_t i = 0; i < n; ++i) {\n      if (!exists[i]) {\n      \
    \  return i;\n      }\n    }\n    return n;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MEX_HPP\n#define TOOLS_MEX_HPP\n\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n#include <cstddef>\n#include <cassert>\n\
    #include <algorithm>\n\nnamespace tools {\n\n  template <typename InputIterator>\n\
    \  ::std::decay_t<decltype(*::std::declval<InputIterator>())> mex(InputIterator\
    \ begin, InputIterator end) {\n    using T = ::std::decay_t<decltype(*::std::declval<InputIterator>())>;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const ::std::size_t n = orig.size();\n\
    \n    assert(::std::all_of(orig.begin(), orig.end(), [](const auto& o) { return\
    \ o >= 0; }));\n\n    ::std::vector<bool> exists(n, false);\n    for (const ::std::size_t\
    \ o : orig) {\n      if (o < n) {\n        exists[o] = true;\n      }\n    }\n\
    \    for (::std::size_t i = 0; i < n; ++i) {\n      if (!exists[i]) {\n      \
    \  return i;\n      }\n    }\n    return n;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/mex.hpp
  requiredBy:
  - tools/range_count_distinct.hpp
  - tools/longest_common_substring.hpp
  timestamp: '2024-01-07 15:56:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/mex.test.cpp
  - tests/range_count_distinct.test.cpp
  - tests/longest_common_substring.test.cpp
documentation_of: tools/mex.hpp
layout: document
title: Minimum excluded value
---

```cpp
template <typename InputIterator>
std::decay_t<decltype(*std::declval<InputIterator>())> mex(InputIterator begin, InputIterator end);
```

It returns the minimum non-negative integer which is not in a given sequence.

## Constraints
- `begin` $\leq$ `end`
- `std::decay_t<decltype(*std::declval<InputIterator>())>` is an integral type.
- All the integers in the sequence are non-negative.

## Time Complexity
- $O(n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
