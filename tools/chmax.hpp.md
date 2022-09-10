---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':heavy_check_mark:'
    path: tools/detail/polygon_like_2d.hpp
    title: tools/detail/polygon_like_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/largest_rectangle_in_histogram.hpp
    title: Largest rectangle in histogram
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/with_radius.test.cpp
    title: tests/circle_2d/where/with_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/without_radius.test.cpp
    title: tests/circle_2d/where/without_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/largest_rectangle_in_histogram.test.cpp
    title: tests/largest_rectangle_in_histogram.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/next_matching.test.cpp
    title: tests/next_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
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
  - tools/largest_rectangle_in_histogram.hpp
  - tools/detail/polygon_like_2d.hpp
  - tools/triangle_2d.hpp
  - tools/circle_2d.hpp
  - tools/polygon_2d.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/next_matching.test.cpp
  - tests/largest_rectangle_in_histogram.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/rolling_hash.test.cpp
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
