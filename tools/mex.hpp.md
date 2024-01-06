---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: tools/range_count_distinct.hpp
    title: Range count distinct
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/mex.test.cpp
    title: tests/mex.test.cpp
  - icon: ':x:'
    path: tests/range_count_distinct.test.cpp
    title: tests/range_count_distinct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/mex.hpp\"\n\n\n\n#include <iterator>\n#include <vector>\n\
    \nnamespace tools {\n\n  template <typename InputIterator>\n  typename ::std::iterator_traits<InputIterator>::value_type\
    \ mex(InputIterator begin, InputIterator end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const T n = orig.size();\n\
    \    ::std::vector<bool> exists(n, false);\n    for (const auto& o : orig) {\n\
    \      if (0 <= o && o < n) {\n        exists[o] = true;\n      }\n    }\n   \
    \ for (T i = 0; i < n; ++i) {\n      if (!exists[i]) {\n        return i;\n  \
    \    }\n    }\n    return n;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_MEX_HPP\n#define TOOLS_MEX_HPP\n\n#include <iterator>\n#include\
    \ <vector>\n\nnamespace tools {\n\n  template <typename InputIterator>\n  typename\
    \ ::std::iterator_traits<InputIterator>::value_type mex(InputIterator begin, InputIterator\
    \ end) {\n    using T = typename ::std::iterator_traits<InputIterator>::value_type;\n\
    \    const ::std::vector<T> orig(begin, end);\n    const T n = orig.size();\n\
    \    ::std::vector<bool> exists(n, false);\n    for (const auto& o : orig) {\n\
    \      if (0 <= o && o < n) {\n        exists[o] = true;\n      }\n    }\n   \
    \ for (T i = 0; i < n; ++i) {\n      if (!exists[i]) {\n        return i;\n  \
    \    }\n    }\n    return n;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/mex.hpp
  requiredBy:
  - tools/range_count_distinct.hpp
  timestamp: '2021-09-25 15:53:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/mex.test.cpp
  - tests/range_count_distinct.test.cpp
documentation_of: tools/mex.hpp
layout: document
title: Minimum excluded value
---

```
template <typename InputIterator>
typename std::iterator_traits<InputIterator>::value_type mex(InputIterator begin, InputIterator end);
```

It returns the minimum non-negative integer which is not in a given set.

## Constraints
- `begin` $\leq$ `end`

## Time Complexity
- $O(n)$ where $n$ is `end` - `begin`

## License
- CC0

## Author
- anqooqie
