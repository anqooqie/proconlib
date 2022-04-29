---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/detail/polygon_like_2d.hpp
    title: tools/detail/polygon_like_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':warning:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/abs.hpp\"\n\n\n\n#include <cmath>\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(::std::abs(v))\
    \ {\n    return ::std::abs(v);\n  }\n\n  template <typename T>\n  auto abs(const\
    \ T& v) -> decltype(v.abs()) {\n    return v.abs();\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_ABS_HPP\n#define TOOLS_ABS_HPP\n\n#include <cmath>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  auto abs(const T& v) -> decltype(::std::abs(v))\
    \ {\n    return ::std::abs(v);\n  }\n\n  template <typename T>\n  auto abs(const\
    \ T& v) -> decltype(v.abs()) {\n    return v.abs();\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/abs.hpp
  requiredBy:
  - tools/triangle_2d.hpp
  - tools/detail/polygon_like_2d.hpp
  - tools/polygon_2d.hpp
  timestamp: '2022-01-31 01:05:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
documentation_of: tools/abs.hpp
layout: document
title: Unified interface for std::abs(x) and x.abs()
---

```cpp
(1)
template <typename T>
auto abs(T x) -> decltype(std::abs(x));

(2)
template <typename T>
auto abs(T x) -> decltype(x.abs());
```

It returns `std::abs(x)` if `std::abs(x)` is available.
In addition, it returns `x.abs()` if `x.abs()` is available.

## Constraints
- `std::abs(x)` or `x.abs()` is available

## Time Complexity
- (1)
    - $O(1)$
- (2)
    - Same as `x.abs()`

## License
- CC0

## Author
- anqooqie
