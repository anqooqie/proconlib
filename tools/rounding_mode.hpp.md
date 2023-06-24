---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':heavy_check_mark:'
    path: tools/rational.hpp
    title: Rational number
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
    path: tests/directed_line_segment_2d/cross_point.test.cpp
    title: tests/directed_line_segment_2d/cross_point.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/intersection.test.cpp
    title: tests/directed_line_segment_2d/intersection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/directed_line_segment_2d/squared_distance.test.cpp
    title: tests/directed_line_segment_2d/squared_distance.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/rounding_mode.hpp\"\n\n\n\nnamespace tools {\n  enum\
    \ class rounding_mode {\n    ceiling,\n    down,\n    floor,\n    half_down,\n\
    \    half_even,\n    half_up,\n    up\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_ROUNDING_MODE_HPP\n#define TOOLS_ROUNDING_MODE_HPP\n\nnamespace\
    \ tools {\n  enum class rounding_mode {\n    ceiling,\n    down,\n    floor,\n\
    \    half_down,\n    half_even,\n    half_up,\n    up\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/rounding_mode.hpp
  requiredBy:
  - tools/bigdecimal.hpp
  - tools/rational.hpp
  timestamp: '2022-01-25 13:00:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/line_2d/projection.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/random.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
documentation_of: tools/rounding_mode.hpp
layout: document
title: Rounding mode
---

```cpp
enum class rounding_mode {
  ceiling,
  down,
  floor,
  half_down,
  half_even,
  half_up,
  up
};
```

It is a rounding mode for `tools::bigdecimal`.

- `ceiling`
    - It is a rounding mode to round towards positive infinity.
- `down`
    - It is a rounding mode to round towards zero.
- `floor`
    - It is a rounding mode to round towards negative infinity.
- `half_down`
    - It is a rounding mode to round towards the nearest neighbor unless both neighbors are equidistant, in which case round towards zero.
- `half_even`
    - It is a rounding mode to round towards the nearest neighbor unless both neighbors are equidistant, in which case round towards the even neighbor.
- `half_up`
    - It is a rounding mode to round towards the nearest neighbor unless both neighbors are equidistant, in which case round away from zero.
- `up`
    - It is a rounding mode to round away from zero.

## Constraints
- None

## Time Complexity
- Not available

## License
- CC0

## Author
- anqooqie
