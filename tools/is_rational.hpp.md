---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/detail/line_like_2d.hpp
    title: tools/detail/line_like_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/polygon_like_2d.hpp
    title: tools/detail/polygon_like_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':warning:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/is_parallel_to.test.cpp
    title: tests/line_2d/is_parallel_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
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
    path: tests/rational/minus.test.cpp
    title: tests/rational/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/multiplies.test.cpp
    title: tests/rational/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/plus.test.cpp
    title: tests/rational/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rational/random.test.cpp
    title: tests/rational/random.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/is_rational.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  struct is_rational {\n    static constexpr bool value = false;\n\
    \  };\n\n  template <typename T>\n  inline constexpr bool is_rational_v = ::tools::is_rational<T>::value;\n\
    }\n\n\n"
  code: "#ifndef TOOLS_IS_RATIONAL_HPP\n#define TOOLS_IS_RATIONAL_HPP\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  struct is_rational {\n    static constexpr\
    \ bool value = false;\n  };\n\n  template <typename T>\n  inline constexpr bool\
    \ is_rational_v = ::tools::is_rational<T>::value;\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/is_rational.hpp
  requiredBy:
  - tools/half_line_2d.hpp
  - tools/detail/polygon_like_2d.hpp
  - tools/detail/line_like_2d.hpp
  - tools/polygon_2d.hpp
  - tools/rational.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/line_2d.hpp
  - tools/triangle_2d.hpp
  timestamp: '2022-01-29 15:03:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/random.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/multiplies.test.cpp
documentation_of: tools/is_rational.hpp
layout: document
title: Check whether T is tools::rational
---

```cpp
template <typename T>
struct is_rational {
  static constexpr bool value;
};

template <typename T>
inline constexpr bool is_rational_v = is_rational<T>::value;
```

`tools::is_rational<T>::value` will be `true` if `T` is `tools::rational`.
Otherwise, it will be `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie