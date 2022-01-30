---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: tools/detail/polygon_and_triangle_2d.hpp
    title: tools/detail/polygon_and_triangle_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/largest_rectangle_in_histogram.hpp
    title: Largest rectangle in histogram
  - icon: ':warning:'
    path: tools/polygon_2d.hpp
    title: tools/polygon_2d.hpp
  - icon: ':warning:'
    path: tools/triangle_2d.hpp
    title: tools/triangle_2d.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/largest_rectangle_in_histogram.test.cpp
    title: tests/largest_rectangle_in_histogram.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/chmax.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmax(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs < rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CHMAX_HPP\n#define TOOLS_CHMAX_HPP\n\n#include <algorithm>\n\
    \nnamespace tools {\n\n  template <typename M, typename N>\n  bool chmax(M& lhs,\
    \ const N& rhs) {\n    const bool updated = lhs < rhs;\n    if (updated) lhs =\
    \ rhs;\n    return updated;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/chmax.hpp
  requiredBy:
  - tools/polygon_2d.hpp
  - tools/detail/polygon_and_triangle_2d.hpp
  - tools/largest_rectangle_in_histogram.hpp
  - tools/triangle_2d.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/largest_rectangle_in_histogram.test.cpp
documentation_of: tools/chmax.hpp
layout: document
title: chmax function
---

```cpp
template <typename M, typename N>
bool chmax(M& lhs, N rhs);
```

It runs `lhs = std::max(lhs, rhs);`.
It returns `true` if `lhs` has been updated.
Otherwise, it returns `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
