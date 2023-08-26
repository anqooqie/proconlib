---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/hash_combine.hpp
    title: Combine hash values
  - icon: ':question:'
    path: tools/now.hpp
    title: The number of nanoseconds that have elapsed since epoch
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/ccw.hpp
    title: Counter clockwise function
  - icon: ':heavy_check_mark:'
    path: tools/circle_2d.hpp
    title: Two-dimensional circle
  - icon: ':question:'
    path: tools/convex_hull.hpp
    title: Convex hull
  - icon: ':question:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/directed_line_segment_2d.hpp
    title: Two-dimensional directed line segment
  - icon: ':heavy_check_mark:'
    path: tools/extend_hash.hpp
    title: Extend std::hash
  - icon: ':x:'
    path: tools/greater_by_arg.hpp
    title: std::greater by the argument
  - icon: ':x:'
    path: tools/greater_by_arg_total.hpp
    title: std::greater by the argument (total order)
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':x:'
    path: tools/less_by_arg.hpp
    title: std::less by the argument
  - icon: ':x:'
    path: tools/less_by_arg_total.hpp
    title: std::less by the argument (total order)
  - icon: ':question:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':x:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':x:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':x:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  - icon: ':heavy_check_mark:'
    path: tools/util.hpp
    title: Commonly used utilities for competitive programming
  - icon: ':question:'
    path: tools/vector2.hpp
    title: Two dimensional vector
  - icon: ':x:'
    path: tools/vector3.hpp
    title: Three dimensional vector
  - icon: ':x:'
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
    path: tests/extend_hash.test.cpp
    title: tests/extend_hash.test.cpp
  - icon: ':x:'
    path: tests/greater_by_arg.test.cpp
    title: tests/greater_by_arg.test.cpp
  - icon: ':x:'
    path: tests/greater_by_arg_total.test.cpp
    title: tests/greater_by_arg_total.test.cpp
  - icon: ':x:'
    path: tests/less_by_arg.test.cpp
    title: tests/less_by_arg.test.cpp
  - icon: ':x:'
    path: tests/less_by_arg_total.test.cpp
    title: tests/less_by_arg_total.test.cpp
  - icon: ':x:'
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
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tuple_hash.test.cpp
    title: tests/tuple_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/util.test.cpp
    title: tests/util.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/tuple_hash.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <tuple>\n#include <limits>\n#include <functional>\n#line 1 \"tools/now.hpp\"\
    \n\n\n\n#include <chrono>\n\nnamespace tools {\n  inline long long now() {\n \
    \   return ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \  }\n}\n\n\n#line 1 \"tools/hash_combine.hpp\"\n\n\n\n#line 6 \"tools/hash_combine.hpp\"\
    \n\n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
    // License: MIT\n// Author: Google Inc.\n\n// Copyright (c) 2011 Google, Inc.\n\
    //\n// Permission is hereby granted, free of charge, to any person obtaining a\
    \ copy\n// of this software and associated documentation files (the \"Software\"\
    ), to deal\n// in the Software without restriction, including without limitation\
    \ the rights\n// to use, copy, modify, merge, publish, distribute, sublicense,\
    \ and/or sell\n// copies of the Software, and to permit persons to whom the Software\
    \ is\n// furnished to do so, subject to the following conditions:\n//\n// The\
    \ above copyright notice and this permission notice shall be included in\n// all\
    \ copies or substantial portions of the Software.\n//\n// THE SOFTWARE IS PROVIDED\
    \ \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n// IMPLIED, INCLUDING BUT\
    \ NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n// FITNESS FOR A PARTICULAR\
    \ PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n// AUTHORS OR COPYRIGHT\
    \ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n// LIABILITY, WHETHER IN\
    \ AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n// OUT OF OR IN CONNECTION\
    \ WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN\n// THE SOFTWARE.\n\nnamespace\
    \ tools {\n  template <typename T>\n  void hash_combine(::std::size_t& seed, const\
    \ T& v) {\n    static const ::std::hash<T> hasher;\n    static constexpr ::std::size_t\
    \ k_mul = 0x9ddfea08eb382d69ULL;\n    ::std::size_t a = (hasher(v) ^ seed) * k_mul;\n\
    \    a ^= (a >> 47);\n    ::std::size_t b = (seed ^ a) * k_mul;\n    b ^= (b >>\
    \ 47);\n    seed = b * k_mul;\n  }\n}\n\n\n#line 11 \"tools/tuple_hash.hpp\"\n\
    \nnamespace tools {\n  template <typename... Ts>\n  struct tuple_hash {\n    template\
    \ <::std::size_t I = sizeof...(Ts) - 1>\n    ::std::size_t operator()(const ::std::tuple<Ts...>&\
    \ key) const {\n      if constexpr (I == ::std::numeric_limits<::std::size_t>::max())\
    \ {\n        static const ::std::size_t seed = ::tools::now();\n        return\
    \ seed;\n      } else {\n        ::std::size_t seed = this->operator()<I - 1>(key);\n\
    \        ::tools::hash_combine(seed, ::std::get<I>(key));\n        return seed;\n\
    \      }\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_TUPLE_HASH_HPP\n#define TOOLS_TUPLE_HASH_HPP\n\n#include <cstddef>\n\
    #include <tuple>\n#include <limits>\n#include <functional>\n#include <tuple>\n\
    #include \"tools/now.hpp\"\n#include \"tools/hash_combine.hpp\"\n\nnamespace tools\
    \ {\n  template <typename... Ts>\n  struct tuple_hash {\n    template <::std::size_t\
    \ I = sizeof...(Ts) - 1>\n    ::std::size_t operator()(const ::std::tuple<Ts...>&\
    \ key) const {\n      if constexpr (I == ::std::numeric_limits<::std::size_t>::max())\
    \ {\n        static const ::std::size_t seed = ::tools::now();\n        return\
    \ seed;\n      } else {\n        ::std::size_t seed = this->operator()<I - 1>(key);\n\
    \        ::tools::hash_combine(seed, ::std::get<I>(key));\n        return seed;\n\
    \      }\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/now.hpp
  - tools/hash_combine.hpp
  isVerificationFile: false
  path: tools/tuple_hash.hpp
  requiredBy:
  - tools/less_by_arg.hpp
  - tools/util.hpp
  - tools/quaternion.hpp
  - tools/extend_hash.hpp
  - tools/line_2d.hpp
  - tools/less_by_arg_total.hpp
  - tools/polygon_2d.hpp
  - tools/vector4.hpp
  - tools/greater_by_arg_total.hpp
  - tools/half_line_2d.hpp
  - tools/convex_hull.hpp
  - tools/detail/geometry_2d.hpp
  - tools/vector3.hpp
  - tools/triangle_2d.hpp
  - tools/ccw.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/vector2.hpp
  - tools/greater_by_arg.hpp
  - tools/circle_2d.hpp
  timestamp: '2022-11-12 12:10:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
  - tests/circle_2d/where/with_radius.test.cpp
  - tests/circle_2d/where/without_radius.test.cpp
  - tests/circle_2d/intersection_to_circle.test.cpp
  - tests/circle_2d/intersection_to_line.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/less_by_arg.test.cpp
  - tests/greater_by_arg_total.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/quaternion/slerp.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/look_rotation.test.cpp
  - tests/convex_hull.test.cpp
  - tests/greater_by_arg.test.cpp
  - tests/ccw.test.cpp
  - tests/util.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/extend_hash.test.cpp
  - tests/tuple_hash.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/less_by_arg_total.test.cpp
documentation_of: tools/tuple_hash.hpp
layout: document
title: Hash of std::tuple
---

```cpp
template <typename... Ts>
struct tuple_hash {
  std::size_t operator()(std::tuple<Ts...> key);
};
```

It is a class for calculating the hash value of `std::tuple<Ts...>`.

## License
- CC0

## Author
- anqooqie
