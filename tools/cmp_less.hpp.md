---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/bellman_ford.hpp
    title: Bellman-Ford algorithm
  - icon: ':heavy_check_mark:'
    path: tools/chmax.hpp
    title: chmax function
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/dijkstra.hpp
    title: Dijkstra's algorithm
  - icon: ':heavy_check_mark:'
    path: tools/largest_rectangle_in_histogram.hpp
    title: Largest rectangle in histogram
  - icon: ':heavy_check_mark:'
    path: tools/longest_common_substring.hpp
    title: Longest common substring
  - icon: ':heavy_check_mark:'
    path: tools/mcf_graph.hpp
    title: Solver of minimum-cost flow problem
  - icon: ':heavy_check_mark:'
    path: tools/naive_dijkstra.hpp
    title: Dijkstra's algorithm for dense graph
  - icon: ':heavy_check_mark:'
    path: tools/segmented_sieve.hpp
    title: Segmented sieve
  - icon: ':heavy_check_mark:'
    path: tools/suffix_array.hpp
    title: Wrapper of atcoder::suffix_array and atcoder::lcp_array
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
    path: tests/cartesian_tree/interval.test.cpp
    title: tests/cartesian_tree/interval.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra/directed.test.cpp
    title: tests/dijkstra/directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra/undirected.test.cpp
    title: tests/dijkstra/undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/largest_rectangle_in_histogram.test.cpp
    title: tests/largest_rectangle_in_histogram.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/longest_common_substring.test.cpp
    title: tests/longest_common_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/naive_dijkstra.test.cpp
    title: tests/naive_dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/next_matching.test.cpp
    title: tests/next_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/persistent_stack.test.cpp
    title: tests/persistent_stack.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/prim/unconnected.test.cpp
    title: tests/prim/unconnected.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/rolling_hash.test.cpp
    title: tests/rolling_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/segmented_sieve.test.cpp
    title: tests/segmented_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/suffix_array.test.cpp
    title: tests/suffix_array.test.cpp
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
  bundledCode: "#line 1 \"tools/cmp_less.hpp\"\n\n\n\n#include <type_traits>\n\nnamespace\
    \ tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n"
  code: "#ifndef TOOLS_CMP_LESS_HPP\n#define TOOLS_CMP_LESS_HPP\n\n#include <type_traits>\n\
    \nnamespace tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/cmp_less.hpp
  requiredBy:
  - tools/tree_diameter.hpp
  - tools/mcf_graph.hpp
  - tools/largest_rectangle_in_histogram.hpp
  - tools/suffix_array.hpp
  - tools/longest_common_substring.hpp
  - tools/dijkstra.hpp
  - tools/chmax.hpp
  - tools/bellman_ford.hpp
  - tools/chmin.hpp
  - tools/weighted_bipartite_matching.hpp
  - tools/naive_dijkstra.hpp
  - tools/zero_one_bfs.hpp
  - tools/xor_basis.hpp
  - tools/tsp.hpp
  - tools/segmented_sieve.hpp
  - tools/zero_one_knapsack.hpp
  timestamp: '2024-03-20 23:37:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/largest_rectangle_in_histogram.test.cpp
  - tests/prim/unconnected.test.cpp
  - tests/cartesian_tree/interval.test.cpp
  - tests/zero_one_knapsack/solve_by_meet_in_the_middle.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_minimizing_weight.test.cpp
  - tests/zero_one_knapsack/solve_by_dp_maximizing_value.test.cpp
  - tests/segmented_sieve.test.cpp
  - tests/persistent_stack.test.cpp
  - tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/dijkstra/undirected.test.cpp
  - tests/dijkstra/directed.test.cpp
  - tests/zero_one_bfs/undirected.test.cpp
  - tests/zero_one_bfs/directed.test.cpp
  - tests/suffix_array.test.cpp
  - tests/naive_dijkstra.test.cpp
  - tests/rolling_hash.test.cpp
  - tests/xor_basis.test.cpp
  - tests/tree_diameter.test.cpp
  - tests/longest_common_substring.test.cpp
  - tests/tsp.test.cpp
  - tests/next_matching.test.cpp
  - tests/bellman_ford.test.cpp
documentation_of: tools/cmp_less.hpp
layout: document
title: Polyfill of std::cmp_less
---

```cpp
template <typename T, typename U>
constexpr bool cmp_less(T t, U u) noexcept;
```

It is identical to `std::cmp_less` in C++20.

### Constraints
- `<T>` is an integral type.
- `<U>` is an integral type.

### Time Complexity
- $O(1)$

### License
- CC0

### Author
- anqooqie