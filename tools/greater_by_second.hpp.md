---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/dijkstra.hpp
    title: Dijkstra's algorithm
  - icon: ':x:'
    path: tools/mcf_graph.hpp
    title: Solver of minimum-cost flow problem
  - icon: ':x:'
    path: tools/weighted_bipartite_matching.hpp
    title: Matching on weighted bipartite graph
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra/directed.test.cpp
    title: tests/dijkstra/directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra/undirected.test.cpp
    title: tests/dijkstra/undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/persistent_stack.test.cpp
    title: tests/persistent_stack.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  - icon: ':x:'
    path: tests/weighted_bipartite_matching/multiple_calls.test.cpp
    title: tests/weighted_bipartite_matching/multiple_calls.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#include <utility>\n\
    \nnamespace tools {\n\n  class greater_by_second {\n  public:\n    template <class\
    \ T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.second > y.second;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_GREATER_BY_SECOND_HPP\n#define TOOLS_GREATER_BY_SECOND_HPP\n\
    \n#include <utility>\n\nnamespace tools {\n\n  class greater_by_second {\n  public:\n\
    \    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.second > y.second;\n\
    \    }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/greater_by_second.hpp
  requiredBy:
  - tools/mcf_graph.hpp
  - tools/weighted_bipartite_matching.hpp
  - tools/dijkstra.hpp
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/persistent_stack.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
  - tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/dijkstra/undirected.test.cpp
  - tests/dijkstra/directed.test.cpp
documentation_of: tools/greater_by_second.hpp
layout: document
title: std::greater by second
---

It compares two pairs by the second element.

### Usage
```cpp
std::vector<std::pair<int, int>> a;
std::sort(a.begin(), a.end(), tools::greater_by_second());
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tools::greater_by_second comp();
```

It creates a comparator.

### Constraints
- None

### Time Complexity
- $O(1)$

## operator()
```cpp
template <typename T1, typename T2>
bool comp(std::pair<T1, T2> x, std::pair<T1, T2> y);
```

It returns `true` if `x.second > y.second`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(1)$
