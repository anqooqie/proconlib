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
  - icon: ':heavy_check_mark:'
    path: tools/mcf_graph.hpp
    title: Solver of minimum-cost flow problem
  - icon: ':heavy_check_mark:'
    path: tools/segmented_sieve.hpp
    title: Segmented sieve
  - icon: ':heavy_check_mark:'
    path: tools/tree_diameter.hpp
    title: Diameter of a tree
  - icon: ':heavy_check_mark:'
    path: tools/tsp.hpp
    title: Traveling salesman problem
  - icon: ':heavy_check_mark:'
    path: tools/weighted_bipartite_matching.hpp
    title: Matching on weighted bipartite graph
  - icon: ':heavy_check_mark:'
    path: tools/xor_basis.hpp
    title: Basis of xor
  - icon: ':heavy_check_mark:'
    path: tools/zero_one_bfs.hpp
    title: 01-BFS
  - icon: ':heavy_check_mark:'
    path: tools/zero_one_knapsack.hpp
    title: 0-1 knapsack problem
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
  - icon: ':heavy_check_mark:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/suffix_array_remove_if.test.cpp
    title: tests/suffix_array_remove_if.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tree_diameter.test.cpp
    title: tests/tree_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tsp.test.cpp
    title: tests/tsp.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/multiple_calls.test.cpp
    title: tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/xor_basis.test.cpp
    title: tests/xor_basis.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_bfs/directed.test.cpp
    title: tests/zero_one_bfs/directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_bfs/undirected.test.cpp
    title: tests/zero_one_bfs/undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
    title: tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
    title: tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
    title: tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - tools/weighted_bipartite_matching.hpp
  - tools/zero_one_bfs.hpp
  - tools/mcf_graph.hpp
  - tools/segmented_sieve.hpp
  - tools/bellman_ford.hpp
  - tools/xor_basis.hpp
  - tools/tsp.hpp
  - tools/dijkstra.hpp
  - tools/tree_diameter.hpp
  - tools/zero_one_knapsack.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree_diameter.test.cpp
  - tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
  - tests/prim/unconnected.test.cpp
  - tests/xor_basis.test.cpp
  - tests/dijkstra/directed.test.cpp
  - tests/dijkstra/undirected.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/suffix_array_remove_if.test.cpp
  - tests/persistent_stack.test.cpp
  - tests/segmented_sieve.test.cpp
  - tests/tsp.test.cpp
  - tests/bellman_ford.test.cpp
  - tests/zero_one_bfs/directed.test.cpp
  - tests/zero_one_bfs/undirected.test.cpp
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
