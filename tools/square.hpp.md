---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/monoid.hpp
    title: Typical monoids
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/ceil_kth_root.hpp
    title: $\left\lceil x^\frac{1}{k} \right\rceil$
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':question:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':x:'
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
  - icon: ':question:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':x:'
    path: tools/modint_for_rolling_hash.hpp
    title: $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$
  - icon: ':x:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':question:'
    path: tools/pow.hpp
    title: $b^n$ under a given monoid, and std::pow(b, n) extended for my library
  - icon: ':x:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':x:'
    path: tools/rolling_hash.hpp
    title: Rolling hash
  - icon: ':x:'
    path: tools/tetration_mod.hpp
    title: $x \uparrow\uparrow y \pmod{M}$
  - icon: ':x:'
    path: tools/totient.hpp
    title: Euler's totient function
  - icon: ':x:'
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
  - icon: ':x:'
    path: tests/fps/exp_other_mods.test.cpp
    title: tests/fps/exp_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/log_other_mods.test.cpp
    title: tests/fps/log_other_mods.test.cpp
  - icon: ':x:'
    path: tests/fps/pow_other_mods.test.cpp
    title: tests/fps/pow_other_mods.test.cpp
  - icon: ':x:'
    path: tests/has_mod.test.cpp
    title: tests/has_mod.test.cpp
  - icon: ':x:'
    path: tests/line_2d/is_parallel_to.test.cpp
    title: tests/line_2d/is_parallel_to.test.cpp
  - icon: ':x:'
    path: tests/line_2d/projection.test.cpp
    title: tests/line_2d/projection.test.cpp
  - icon: ':x:'
    path: tests/permutation.test.cpp
    title: tests/permutation.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
  - icon: ':x:'
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':x:'
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':x:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':x:'
    path: tests/quaternion/slerp.test.cpp
    title: tests/quaternion/slerp.test.cpp
  - icon: ':x:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':x:'
    path: tests/tetration_mod.test.cpp
    title: tests/tetration_mod.test.cpp
  - icon: ':x:'
    path: tests/totient.test.cpp
    title: tests/totient.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/square.hpp\"\n\n\n\n#line 1 \"tools/monoid.hpp\"\n\
    \n\n\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\nnamespace\
    \ tools {\n  namespace monoid {\n    template <typename M, M E = ::std::numeric_limits<M>::lowest()>\n\
    \    struct max {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::max(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M, M E = ::std::numeric_limits<M>::max()>\n\
    \    struct min {\n      using T = M;\n      static T op(const T& lhs, const T&\
    \ rhs) {\n        return ::std::min(lhs, rhs);\n      }\n      static T e() {\n\
    \        return E;\n      }\n    };\n\n    template <typename M>\n    struct multiplies\
    \ {\n      using T = M;\n      static T op(const T& lhs, const T& rhs) {\n   \
    \     return lhs * rhs;\n      }\n      static T e() {\n        return T(1);\n\
    \      }\n    };\n\n    template <typename M>\n    struct gcd {\n      using T\
    \ = M;\n      static T op(const T& lhs, const T& rhs) {\n        return ::std::gcd(lhs,\
    \ rhs);\n      }\n      static T e() {\n        return T(0);\n      }\n    };\n\
    \n    template <typename M, M E>\n    struct update {\n      using T = M;\n  \
    \    static T op(const T& lhs, const T& rhs) {\n        return lhs == E ? rhs\
    \ : lhs;\n      }\n      static T e() {\n        return E;\n      }\n    };\n\
    \  }\n}\n\n\n#line 5 \"tools/square.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M>\n  typename M::T square(const typename M::T& x) {\n    return M::op(x, x);\n\
    \  }\n\n  template <typename T>\n  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n\n"
  code: "#ifndef TOOLS_SQUARE_HPP\n#define TOOLS_SQUARE_HPP\n\n#include \"tools/monoid.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M>\n  typename M::T square(const\
    \ typename M::T& x) {\n    return M::op(x, x);\n  }\n\n  template <typename T>\n\
    \  T square(const T& x) {\n    return ::tools::square<::tools::monoid::multiplies<T>>(x);\n\
    \  }\n}\n\n#endif\n"
  dependsOn:
  - tools/monoid.hpp
  isVerificationFile: false
  path: tools/square.hpp
  requiredBy:
  - tools/detail/geometry_2d.hpp
  - tools/detail/rolling_hash.hpp
  - tools/pow.hpp
  - tools/ceil_kth_root.hpp
  - tools/polygon_2d.hpp
  - tools/quaternion.hpp
  - tools/rolling_hash.hpp
  - tools/circle_2d.hpp
  - tools/totient.hpp
  - tools/half_line_2d.hpp
  - tools/triangle_2d.hpp
  - tools/floor_kth_root.hpp
  - tools/line_2d.hpp
  - tools/tetration_mod.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/modint_for_rolling_hash.hpp
  timestamp: '2024-01-03 03:48:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/ceil_kth_root.test.cpp
  - tests/fps/exp_other_mods.test.cpp
  - tests/fps/pow_other_mods.test.cpp
  - tests/fps/log_other_mods.test.cpp
  - tests/totient.test.cpp
  - tests/floor_kth_root.test.cpp
  - tests/has_mod.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/tetration_mod.test.cpp
  - tests/permutation.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/quaternion/look_rotation.test.cpp
documentation_of: tools/square.hpp
layout: document
title: $x^2$ under a given monoid
---

```cpp
template <typename M>
typename M::T square(typename M::T x);

template <typename T>
T square(T x);
```

It returns $x^2$ under a given monoid.
The default monoid is $(\mathbb{Z}, \times)$.

## License
- CC0

## Author
- anqooqie
