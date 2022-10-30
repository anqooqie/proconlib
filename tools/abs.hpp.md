---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':heavy_check_mark:'
    path: tools/convex_hull.hpp
    title: Convex hull
  - icon: ':heavy_check_mark:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/vector_common.hpp
    title: tools/detail/vector_common.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_arg.hpp
    title: std::greater by the argument
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_arg_total.hpp
    title: std::greater by the argument (total order)
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/less_by_arg.hpp
    title: std::less by the argument
  - icon: ':heavy_check_mark:'
    path: tools/less_by_arg_total.hpp
    title: std::less by the argument (total order)
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: tools/quaternion.hpp
  - icon: ':heavy_check_mark:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  - icon: ':heavy_check_mark:'
    path: tools/vector.hpp
    title: Vector
  - icon: ':heavy_check_mark:'
    path: tools/vector2.hpp
    title: Two dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/vector3.hpp
    title: Three dimensional vector
  - icon: ':heavy_check_mark:'
    path: tools/vector4.hpp
    title: Four dimensional vector
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ccw.test.cpp
    title: tests/ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/intersection_to_circle.test.cpp
    title: tests/circle_2d/intersection_to_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/intersection_to_line.test.cpp
    title: tests/circle_2d/intersection_to_line.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/with_radius.test.cpp
    title: tests/circle_2d/where/with_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/circle_2d/where/without_radius.test.cpp
    title: tests/circle_2d/where/without_radius.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/convex_hull.test.cpp
    title: tests/convex_hull.test.cpp
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
    path: tests/greater_by_arg.test.cpp
    title: tests/greater_by_arg.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/greater_by_arg_total.test.cpp
    title: tests/greater_by_arg_total.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/less_by_arg.test.cpp
    title: tests/less_by_arg.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/less_by_arg_total.test.cpp
    title: tests/less_by_arg_total.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/is_parallel_to.test.cpp
    title: tests/line_2d/is_parallel_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/determinant.test.cpp
    title: tests/matrix/determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/inv.test.cpp
    title: tests/matrix/inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/multiplies.test.cpp
    title: tests/matrix/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/matrix/solve.test.cpp
    title: tests/matrix/solve.test.cpp
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
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
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
  - tools/greater_by_arg.hpp
  - tools/detail/geometry_2d.hpp
  - tools/detail/vector_common.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/ccw.hpp
  - tools/vector2.hpp
  - tools/vector4.hpp
  - tools/line_2d.hpp
  - tools/quaternion.hpp
  - tools/half_line_2d.hpp
  - tools/greater_by_arg_total.hpp
  - tools/vector.hpp
  - tools/polygon_2d.hpp
  - tools/matrix.hpp
  - tools/convex_hull.hpp
  - tools/vector3.hpp
  - tools/less_by_arg_total.hpp
  - tools/circle_2d.hpp
  - tools/less_by_arg.hpp
  timestamp: '2022-01-31 01:05:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/less_by_arg_total.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/less_by_arg.test.cpp
  - tests/greater_by_arg.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/matrix/determinant.test.cpp
  - tests/matrix/inv.test.cpp
  - tests/matrix/multiplies.test.cpp
  - tests/matrix/solve.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/greater_by_arg_total.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/ccw.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/convex_hull.test.cpp
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

If `std::abs(x)` is available, it returns `std::abs(x)`.
If `x.abs()` is available, it returns `x.abs()`.

## Constraints
- Either `std::abs(x)` or `x.abs()` is available.

## Time Complexity
- (1)
    - $O(1)$
- (2)
    - Same as `x.abs()`

## License
- CC0

## Author
- anqooqie
