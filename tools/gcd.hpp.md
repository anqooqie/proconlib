---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bigdecimal.hpp
    title: Arbitrary precision floating-point number
  - icon: ':heavy_check_mark:'
    path: tools/bigint.hpp
    title: Arbitrary precision integer
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
    path: tests/bigint/divides.test.cpp
    title: tests/bigint/divides.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/minus.test.cpp
    title: tests/bigint/minus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/modulus.test.cpp
    title: tests/bigint/modulus.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/multiplies.test.cpp
    title: tests/bigint/multiplies.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/bigint/plus.test.cpp
    title: tests/bigint/plus.test.cpp
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
    path: tests/fastio/string.test.cpp
    title: tests/fastio/string.test.cpp
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
  bundledCode: "#line 1 \"tools/gcd.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <numeric>\n\nnamespace tools {\n  template <typename M, typename N>\n  constexpr\
    \ ::std::common_type_t<M, N> gcd(const M m, const N n) {\n    return ::std::gcd(m,\
    \ n);\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_GCD_HPP\n#define TOOLS_GCD_HPP\n\n#include <type_traits>\n\
    #include <numeric>\n\nnamespace tools {\n  template <typename M, typename N>\n\
    \  constexpr ::std::common_type_t<M, N> gcd(const M m, const N n) {\n    return\
    \ ::std::gcd(m, n);\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/gcd.hpp
  requiredBy:
  - tools/bigdecimal.hpp
  - tools/rational.hpp
  - tools/bigint.hpp
  timestamp: '2022-11-03 23:21:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/bigdecimal/multiplies.test.cpp
  - tests/bigdecimal/rounding.test.cpp
  - tests/bigdecimal/minus.test.cpp
  - tests/bigdecimal/divides.test.cpp
  - tests/bigdecimal/hand.test.cpp
  - tests/bigdecimal/cast_to_long_long.test.cpp
  - tests/bigdecimal/plus.test.cpp
  - tests/bigdecimal/random.test.cpp
  - tests/fastio/string.test.cpp
  - tests/rational/multiplies.test.cpp
  - tests/rational/minus.test.cpp
  - tests/rational/plus.test.cpp
  - tests/rational/random.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/bigint/multiplies.test.cpp
  - tests/bigint/minus.test.cpp
  - tests/bigint/divides.test.cpp
  - tests/bigint/plus.test.cpp
  - tests/bigint/modulus.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
documentation_of: tools/gcd.hpp
layout: document
title: std::gcd(m, n) extended for my library
---

```cpp
template <typename M, typename N>
constexpr std::common_type_t<M, N> gcd(M m, N n);
```

If `std::gcd(m, n)` is available, it returns `std::gcd(m, n)`.

`tools::gcd(m, n)` will be extended by other header files in my library.
For example, `tools::gcd(tools::bigint, tools::bigint)` gets available if you include `tools/bigint.hpp`.

## Constraints
- See the standard or the explanation of the corresponding header file.

## Time Complexity
- See the standard or the explanation of the corresponding header file.

## License
- CC0

## Author
- anqooqie
