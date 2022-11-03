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
  - icon: ':question:'
    path: tools/detail/geometry_2d.hpp
    title: tools/detail/geometry_2d.hpp
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
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/quaternion.hpp
    title: Quaternion
  - icon: ':x:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  - icon: ':question:'
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
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tuple_hash.test.cpp
    title: tests/tuple_hash.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h
  bundledCode: "#line 1 \"tools/tuple_hash.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <tuple>\n#include <chrono>\n#include <functional>\n\n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
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
    \ tools {\n  template <typename... Ts>\n  class tuple_hash {\n  public:\n    using\
    \ result_type = ::std::size_t;\n    using argument_type = ::std::tuple<Ts...>;\n\
    \n  private:\n    static constexpr result_type k_mul = 0x9ddfea08eb382d69ULL;\n\
    \n  public:\n    template <int I = int(sizeof...(Ts)) - 1>\n      result_type\
    \ operator()(const argument_type& key) const {\n      if constexpr (I == -1) {\n\
    \        static const result_type seed = ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \        return seed;\n      } else {\n        static const ::std::hash<::std::tuple_element_t<I,\
    \ argument_type>> hasher;\n        result_type seed = this->operator()<I - 1>(key);\n\
    \        result_type a = (hasher(::std::get<I>(key)) ^ seed) * k_mul;\n      \
    \  a ^= (a >> 47);\n        result_type b = (seed ^ a) * k_mul;\n        b ^=\
    \ (b >> 47);\n        seed = b * k_mul;\n        return seed;\n      }\n    }\n\
    \  };\n}\n\n\n"
  code: "#ifndef TOOLS_TUPLE_HASH_HPP\n#define TOOLS_TUPLE_HASH_HPP\n\n#include <cstddef>\n\
    #include <tuple>\n#include <chrono>\n#include <functional>\n\n// Source: https://github.com/google/cityhash/blob/f5dc54147fcce12cefd16548c8e760d68ac04226/src/city.h\n\
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
    \ tools {\n  template <typename... Ts>\n  class tuple_hash {\n  public:\n    using\
    \ result_type = ::std::size_t;\n    using argument_type = ::std::tuple<Ts...>;\n\
    \n  private:\n    static constexpr result_type k_mul = 0x9ddfea08eb382d69ULL;\n\
    \n  public:\n    template <int I = int(sizeof...(Ts)) - 1>\n      result_type\
    \ operator()(const argument_type& key) const {\n      if constexpr (I == -1) {\n\
    \        static const result_type seed = ::std::chrono::duration_cast<::std::chrono::nanoseconds>(::std::chrono::high_resolution_clock::now().time_since_epoch()).count();\n\
    \        return seed;\n      } else {\n        static const ::std::hash<::std::tuple_element_t<I,\
    \ argument_type>> hasher;\n        result_type seed = this->operator()<I - 1>(key);\n\
    \        result_type a = (hasher(::std::get<I>(key)) ^ seed) * k_mul;\n      \
    \  a ^= (a >> 47);\n        result_type b = (seed ^ a) * k_mul;\n        b ^=\
    \ (b >> 47);\n        seed = b * k_mul;\n        return seed;\n      }\n    }\n\
    \  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/tuple_hash.hpp
  requiredBy:
  - tools/triangle_2d.hpp
  - tools/greater_by_arg.hpp
  - tools/detail/geometry_2d.hpp
  - tools/directed_line_segment_2d.hpp
  - tools/ccw.hpp
  - tools/vector2.hpp
  - tools/vector4.hpp
  - tools/line_2d.hpp
  - tools/quaternion.hpp
  - tools/half_line_2d.hpp
  - tools/greater_by_arg_total.hpp
  - tools/polygon_2d.hpp
  - tools/convex_hull.hpp
  - tools/vector3.hpp
  - tools/less_by_arg_total.hpp
  - tools/circle_2d.hpp
  - tools/less_by_arg.hpp
  timestamp: '2022-10-29 17:35:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
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
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/greater_by_arg_total.test.cpp
  - tests/directed_line_segment_2d/squared_distance.test.cpp
  - tests/directed_line_segment_2d/cross_point.test.cpp
  - tests/directed_line_segment_2d/intersection.test.cpp
  - tests/ccw.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/convex_hull.test.cpp
  - tests/tuple_hash.test.cpp
documentation_of: tools/tuple_hash.hpp
layout: document
title: Hash of std::tuple
---

```cpp
template <typename... Ts>
struct tuple_hash {
  using result_type = std::size_t;
  using argument_type = std::tuple<Ts...>;
  result_type operator()(argument_type key);
};
```

It returns hash of `std::tuple<Ts...>`.

## References
- [c++ - How to create a good hash_combine with 64 bit output (inspired by boost::hash_combine) - Stack Overflow](https://stackoverflow.com/questions/8513911/how-to-create-a-good-hash-combine-with-64-bit-output-inspired-by-boosthash-co/8980550#8980550)

## License
- MIT

## Author
- Google Inc.
