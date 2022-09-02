---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: tools/convex_hull.hpp
    title: Convex hull
  - icon: ':question:'
    path: tools/detail/polygon_like_2d.hpp
    title: tools/detail/polygon_like_2d.hpp
  - icon: ':heavy_check_mark:'
    path: tools/hld.hpp
    title: Heavy-light decomposition
  - icon: ':question:'
    path: tools/polygon_2d.hpp
    title: Two-dimensional polygon
  - icon: ':heavy_check_mark:'
    path: tools/scc_graph.hpp
    title: Strongly connected component decomposition
  - icon: ':warning:'
    path: tools/triangle_2d.hpp
    title: Two-dimensional triangle
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/convex_hull.test.cpp
    title: tests/convex_hull.test.cpp
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
  - icon: ':x:'
    path: tests/polygon_2d/area.test.cpp
    title: tests/polygon_2d/area.test.cpp
  - icon: ':x:'
    path: tests/polygon_2d/minimum_bounding_circle.test.cpp
    title: tests/polygon_2d/minimum_bounding_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/polygon_2d/where.test.cpp
    title: tests/polygon_2d/where.test.cpp
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
  - tools/detail/polygon_like_2d.hpp
  - tools/triangle_2d.hpp
  - tools/scc_graph.hpp
  - tools/convex_hull.hpp
  - tools/polygon_2d.hpp
  - tools/hld.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/real_interval_set.test.cpp
  - tests/convex_hull.test.cpp
  - tests/polygon_2d/minimum_bounding_circle.test.cpp
  - tests/polygon_2d/area.test.cpp
  - tests/polygon_2d/where.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
  - tests/scc_graph/scc_id.test.cpp
  - tests/scc_graph/sccs.test.cpp
  - tests/hld/vancestor.test.cpp
  - tests/hld/vpath.test.cpp
  - tests/hld/epath.test.cpp
  - tests/hld/vsubtree.test.cpp
  - tests/hld/lca.test.cpp
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
