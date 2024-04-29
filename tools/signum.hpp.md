---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':question:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':question:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':question:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':question:'
    path: tools/rational.hpp
    title: Rational number
  - icon: ':question:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/cast_to_long_long.test.cpp
    title: tests/bigdecimal/cast_to_long_long.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/divides.test.cpp
    title: tests/bigdecimal/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/hand.test.cpp
    title: tests/bigdecimal/hand.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/minus.test.cpp
    title: tests/bigdecimal/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/multiplies.test.cpp
    title: tests/bigdecimal/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/plus.test.cpp
    title: tests/bigdecimal/plus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/random.test.cpp
    title: tests/bigdecimal/random.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigdecimal/rounding.test.cpp
    title: tests/bigdecimal/rounding.test.cpp
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
  - icon: ':x:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
  - icon: ':x:'
    path: tests/rational/minus.test.cpp
    title: tests/rational/minus.test.cpp
  - icon: ':x:'
    path: tests/rational/multiplies.test.cpp
    title: tests/rational/multiplies.test.cpp
  - icon: ':x:'
    path: tests/rational/plus.test.cpp
    title: tests/rational/plus.test.cpp
  - icon: ':x:'
    path: tests/rational/random.test.cpp
    title: tests/rational/random.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/signum.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  constexpr int signum(const T x) noexcept\
    \ {\n    if constexpr (::std::is_signed_v<T>) {\n      return (T(0) < x) - (x\
    \ < T(0));\n    } else {\n      return T(0) < x;\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SIGNUM_HPP\n#define TOOLS_SIGNUM_HPP\n\n#include <type_traits>\n\
    \nnamespace tools {\n\n  template <typename T>\n  constexpr int signum(const T\
    \ x) noexcept {\n    if constexpr (::std::is_signed_v<T>) {\n      return (T(0)\
    \ < x) - (x < T(0));\n    } else {\n      return T(0) < x;\n    }\n  }\n}\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/signum.hpp
  requiredBy:
  - tools/detail/geometry_2d.hpp
  - tools/line_2d.hpp
  - tools/rational.hpp
  - tools/half_line_2d.hpp
  - tools/circle_2d.hpp
  - tools/polygon_2d.hpp
  - tools/bigdecimal.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/triangle_2d.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/random.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/bigdecimal/rounding.test.cpp
documentation_of: tools/signum.hpp
layout: document
title: Sign function
---

```cpp
template <typename T>
constexpr int signum(T x) noexcept;
```

It returns

$$\begin{align*}
\left\{\begin{array}{ll}
-1 & \text{(if $x < 0$)}\\
0 & \text{(if $x = 0$)}\\
1 & \text{(if $x > 0$)}
\end{array}\right.&
\end{align*}$$

### Constraints
- None

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie
