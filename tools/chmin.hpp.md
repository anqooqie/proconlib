---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bellman_ford.hpp
    title: Bellman-Ford algorithm
  - icon: ':heavy_check_mark:'
    path: tools/dijkstra.hpp
    title: Dijkstra's algorithm
  - icon: ':x:'
    path: tools/mcf_graph.hpp
    title: Solver of minimum-cost flow problem
  - icon: ':x:'
    path: tools/segmented_sieve.hpp
    title: Segmented sieve
  - icon: ':x:'
    path: tools/tree_diameter.hpp
    title: Diameter of a tree
  - icon: ':x:'
    path: tools/weighted_bipartite_matching.hpp
    title: Matching on weighted bipartite graph
  - icon: ':x:'
    path: tools/xor_basis.hpp
    title: Basis of xor
  - icon: ':question:'
    path: tools/zero_one_bfs.hpp
    title: 01-BFS
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bellman_ford.test.cpp
    title: tests/bellman_ford.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra/directed.test.cpp
    title: tests/dijkstra/directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra/undirected.test.cpp
    title: tests/dijkstra/undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/persistent_stack.test.cpp
    title: tests/persistent_stack.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/prim/unconnected.test.cpp
    title: tests/prim/unconnected.test.cpp
  - icon: ':x:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  - icon: ':x:'
    path: tests/tree_diameter.test.cpp
    title: tests/tree_diameter.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/multiple_calls.test.cpp
    title: tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - icon: ':x:'
    path: tests/xor_basis.test.cpp
    title: tests/xor_basis.test.cpp
  - icon: ':x:'
    path: tests/zero_one_bfs/directed.test.cpp
    title: tests/zero_one_bfs/directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_bfs/undirected.test.cpp
    title: tests/zero_one_bfs/undirected.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CHMIN_HPP\n#define TOOLS_CHMIN_HPP\n\n#include <algorithm>\n\
    \nnamespace tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs,\
    \ const N& rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs =\
    \ rhs;\n    return updated;\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/chmin.hpp
  requiredBy:
  - tools/tree_diameter.hpp
  - tools/segmented_sieve.hpp
  - tools/mcf_graph.hpp
  - tools/zero_one_bfs.hpp
  - tools/bellman_ford.hpp
  - tools/weighted_bipartite_matching.hpp
  - tools/xor_basis.hpp
  - tools/dijkstra.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/persistent_stack.test.cpp
  - tests/bellman_ford.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/xor_basis.test.cpp
  - tests/zero_one_bfs/undirected.test.cpp
  - tests/zero_one_bfs/directed.test.cpp
  - tests/prim/unconnected.test.cpp
  - tests/tree_diameter.test.cpp
  - tests/dijkstra/undirected.test.cpp
  - tests/dijkstra/directed.test.cpp
  - tests/segmented_sieve.test.cpp
documentation_of: tools/chmin.hpp
layout: document
title: chmin function
---

```cpp
template <typename M, typename N>
bool chmin(M& lhs, N rhs);
```

It runs `lhs = std::min(lhs, rhs);`.
It returns `true` if `lhs` has been updated.
Otherwise, it returns `false`.

## Constraints
- None

## Time Complexity
- $O(1)$

## License
- CC0

## Author
- anqooqie
