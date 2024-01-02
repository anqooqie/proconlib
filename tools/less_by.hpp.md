---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  - icon: ':warning:'
    path: tools/half_line_2d.hpp
    title: Two-dimensional half line
  - icon: ':heavy_check_mark:'
    path: tools/hld.hpp
    title: Heavy-light decomposition
  - icon: ':heavy_check_mark:'
    path: tools/line_2d.hpp
    title: Two-dimensional line
  - icon: ':heavy_check_mark:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/scc_graph.hpp
    title: Strongly connected component decomposition
  - icon: ':x:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
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
    path: tests/hld/epath.test.cpp
    title: tests/hld/epath.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/hld/lca.test.cpp
    title: tests/hld/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/hld/vancestor.test.cpp
    title: tests/hld/vancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/hld/vpath.test.cpp
    title: tests/hld/vpath.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/hld/vsubtree.test.cpp
    title: tests/hld/vsubtree.test.cpp
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
  - icon: ':x:'
    path: tests/quaternion/angle_axis.test.cpp
    title: tests/quaternion/angle_axis.test.cpp
  - icon: ':x:'
    path: tests/quaternion/dice_rotations.test.cpp
    title: tests/quaternion/dice_rotations.test.cpp
  - icon: ':x:'
    path: tests/quaternion/look_rotation.test.cpp
    title: tests/quaternion/look_rotation.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/real_interval_set.test.cpp
    title: tests/real_interval_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/edges_to_scc.test.cpp
    title: tests/scc_graph/edges_to_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/scc_id.test.cpp
    title: tests/scc_graph/scc_id.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/sccs.test.cpp
    title: tests/scc_graph/sccs.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/circumcircle.test.cpp
    title: tests/triangle_2d/circumcircle.test.cpp
  - icon: ':x:'
    path: tests/triangle_2d/incircle.test.cpp
    title: tests/triangle_2d/incircle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/undoable_dsu.test.cpp
    title: tests/undoable_dsu.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <class F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n   \
    \ less_by(const F& selector) : selector(selector) {\n    }\n\n    template <class\
    \ T>\n    bool operator()(const T& x, const T& y) const {\n      return selector(x)\
    \ < selector(y);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_LESS_BY_HPP\n#define TOOLS_LESS_BY_HPP\n\nnamespace tools {\n\
    \n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n\
    \    less_by(const F& selector) : selector(selector) {\n    }\n\n    template\
    \ <class T>\n    bool operator()(const T& x, const T& y) const {\n      return\
    \ selector(x) < selector(y);\n    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/less_by.hpp
  requiredBy:
  - tools/detail/geometry_2d.hpp
  - tools/polygon_2d.hpp
  - tools/hld.hpp
  - tools/circle_2d.hpp
  - tools/half_line_2d.hpp
  - tools/triangle_2d.hpp
  - tools/scc_graph.hpp
  - tools/line_2d.hpp
  - tools/convex_hull.hpp
  - tools/directed_line_segment_2d.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/hld/epath.test.cpp
  - tests/hld/vsubtree.test.cpp
  - tests/hld/lca.test.cpp
  - tests/hld/vancestor.test.cpp
  - tests/hld/vpath.test.cpp
  - tests/convex_hull.test.cpp
  - tests/scc_graph/scc_id.test.cpp
  - tests/scc_graph/sccs.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
  - tests/triangle_2d/incircle.test.cpp
  - tests/triangle_2d/circumcircle.test.cpp
  - tests/line_2d/is_parallel_to.test.cpp
  - tests/line_2d/projection.test.cpp
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
  - tests/real_interval_set.test.cpp
  - tests/undoable_dsu.test.cpp
  - tests/quaternion/angle_axis.test.cpp
  - tests/quaternion/dice_rotations.test.cpp
  - tests/quaternion/look_rotation.test.cpp
documentation_of: tools/less_by.hpp
layout: document
title: std::less by key
---

It compares two values by a given key selector.

### Usage
```cpp
std::sort(a.begin(), a.end(), tools::less_by([](int a_i) { return std::abs(x); }));
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::less_by<F> comp(F f);
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T>
bool comp(T x, T y);
```

It returns `true` if `f(x) < f(y)`.
Otherwise, it returns `false`.

### Constraints
- `f` has `operator()(T x)`
- `f(x)` is comparable

### Time Complexity
- $O(1)$ if `f(x)` takes constant time
