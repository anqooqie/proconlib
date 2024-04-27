---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/is_monoid.hpp
    title: Check whether T is a monoid
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':heavy_check_mark:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/detail/rolling_hash.hpp
    title: tools/detail/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':heavy_check_mark:'
    path: tools/floor_kth_root.hpp
    title: $\left\lfloor x^\frac{1}{k} \right\rfloor$
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':heavy_check_mark:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':heavy_check_mark:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':heavy_check_mark:'
    path: tools/totient.hpp
    title: Euler's totient function
  - icon: ':heavy_check_mark:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/ceil_kth_root.test.cpp
    title: tests/ceil_kth_root.test.cpp
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
    path: tests/floor_kth_root.test.cpp
    title: tests/floor_kth_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/exp_other_mods.test.cpp
    title: tests/fps/exp_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/log_other_mods.test.cpp
    title: tests/fps/log_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/fps/pow_other_mods.test.cpp
    title: tests/fps/pow_other_mods.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/is_parallel_to.test.cpp
    title: tests/line_2d/is_parallel_to.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
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
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/quaternion/slerp.test.cpp
    title: tests/quaternion/slerp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
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
  bundledCode: "#line 1 \"tools/square.hpp\"\n\n\n\n#include <type_traits>\n#line\
    \ 1 \"tools/is_monoid.hpp\"\n\n\n\n#line 5 \"tools/is_monoid.hpp\"\n#include <utility>\n\
    \nnamespace tools {\n\n  template <typename M, typename = void>\n  struct is_monoid\
    \ : ::std::false_type {};\n\n  template <typename M>\n  struct is_monoid<M, ::std::enable_if_t<\n\
    \    ::std::is_same_v<typename M::T, decltype(M::op(::std::declval<typename M::T>(),\
    \ ::std::declval<typename M::T>()))> &&\n    ::std::is_same_v<typename M::T, decltype(M::e())>\n\
    \  , void>> : ::std::true_type {};\n\n  template <typename M>\n  inline constexpr\
    \ bool is_monoid_v = ::tools::is_monoid<M>::value;\n}\n\n\n#line 6 \"tools/square.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M>\n  ::std::enable_if_t<::tools::is_monoid_v<M>,\
    \ typename M::T> square(const typename M::T& x) {\n    return M::op(x, x);\n \
    \ }\n\n  template <typename T>\n  ::std::enable_if_t<!::tools::is_monoid_v<T>,\
    \ T> square(const T& x) {\n    return x * x;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_SQUARE_HPP\n#define TOOLS_SQUARE_HPP\n\n#include <type_traits>\n\
    #include \"tools/is_monoid.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  ::std::enable_if_t<::tools::is_monoid_v<M>, typename M::T> square(const\
    \ typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n\
    \  ::std::enable_if_t<!::tools::is_monoid_v<T>, T> square(const T& x) {\n    return\
    \ x * x;\n  }\n}\n\n#endif\n"
  dependsOn:
  - tools/is_monoid.hpp
  isVerificationFile: false
  path: tools/square.hpp
  requiredBy:
  - tools/modint_for_rolling_hash.hpp
  - tools/rolling_hash.hpp
  - tools/detail/rolling_hash.hpp
  - tools/detail/geometry_2d.hpp
  - tools/line_2d.hpp
  - tools/totient.hpp
  - tools/half_line_2d.hpp
  - tools/circle_2d.hpp
  - tools/polygon_2d.hpp
  - tools/ceil_kth_root.hpp
  - tools/floor_kth_root.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/tetration_mod.hpp
  - tools/quaternion.hpp
  - tools/triangle_2d.hpp
  - tools/pow.hpp
  timestamp: '2024-04-13 13:54:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/floor_kth_root.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/totient.test.cpp
  - tests/fps/exp_other_mods.test.cpp
  - tests/fps/pow_other_mods.test.cpp
  - tests/fps/log_other_mods.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/ceil_kth_root.test.cpp
  - tests/permutation.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/has_mod.test.cpp
documentation_of: tools/square.hpp
layout: document
title: $x^2$ under a given monoid
---

```cpp
(1)
template <typename M>
typename M::T square(typename M::T x);

(2)
template <typename T>
T square(T x);
```

It returns $x^2$ under a given monoid.
The default monoid is $(\mathbb{Z}, \times)$.

### Constraints
- (1)
    - None
- (2)
    - `x * x` is defined.

### Time Complexity
- (1)
    - Same as that of `M::op(x, x)`
- (2)
    - Same as that of `x * x`

### License
- CC0

### Author
- anqooqie
