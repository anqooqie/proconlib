---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_second.hpp
    title: std::greater by second
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra.test.cpp
    title: tests/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dijkstra.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <limits>\n#include <cassert>\n#include <functional>\n#include\
    \ <queue>\n#line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#include <utility>\n\
    \nnamespace tools {\n\n  class greater_by_second {\n  public:\n    template <class\
    \ T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.second > y.second;\n    }\n  };\n}\n\n\n#line\
    \ 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace tools {\n\n \
    \ template <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n  \
    \  const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n\
    \  }\n}\n\n\n#line 12 \"tools/dijkstra.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  class dijkstra {\n  private:\n    class edge {\n    public:\n\
    \      ::std::size_t from;\n      ::std::size_t to;\n      T distance;\n     \
    \ edge(const ::std::size_t from, const ::std::size_t to, const T distance) :\n\
    \        from(from),\n        to(to),\n        distance(distance) {\n      }\n\
    \    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n    static\
    \ constexpr T INF = ::std::numeric_limits<T>::max();\n    static constexpr ::std::size_t\
    \ NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class result {\n\
    \    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count, const ::std::size_t&\
    \ start_node) :\n        distances(node_count, INF),\n        prev_nodes(node_count,\
    \ NONE) {\n        this->distances[start_node] = 0;\n      }\n    };\n\n    dijkstra(const\
    \ ::std::size_t& node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t\
    \ node_count() const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) {\n      this->edges[from].emplace_back(from,\
    \ to, distance);\n    }\n\n    result query(const ::std::size_t& start_node) const\
    \ {\n      assert(start_node < this->node_count());\n\n      result result(this->node_count(),\
    \ start_node);\n      ::std::priority_queue<::std::pair<::std::size_t, T>, ::std::vector<::std::pair<::std::size_t,\
    \ T>>, ::tools::greater_by_second> tasks;\n      tasks.emplace(start_node, 0);\n\
    \n      while (!tasks.empty()) {\n        const auto [here, d] = tasks.top();\n\
    \        tasks.pop();\n        if (result.distances[here] < d) continue;\n   \
    \     for (const edge& edge : this->edges[here]) {\n          if (::tools::chmin(result.distances[edge.to],\
    \ result.distances[here] + edge.distance)) {\n            result.prev_nodes[edge.to]\
    \ = edge.from;\n            tasks.emplace(edge.to, result.distances[edge.to]);\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DIJKSTRA_HPP\n#define TOOLS_DIJKSTRA_HPP\n\n#include <cstddef>\n\
    #include <vector>\n#include <limits>\n#include <cassert>\n#include <functional>\n\
    #include <queue>\n#include \"tools/greater_by_second.hpp\"\n#include \"tools/chmin.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  class dijkstra {\n  private:\n\
    \    class edge {\n    public:\n      ::std::size_t from;\n      ::std::size_t\
    \ to;\n      T distance;\n      edge(const ::std::size_t from, const ::std::size_t\
    \ to, const T distance) :\n        from(from),\n        to(to),\n        distance(distance)\
    \ {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n\
    \    static constexpr T INF = ::std::numeric_limits<T>::max();\n    static constexpr\
    \ ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class\
    \ result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count, const ::std::size_t&\
    \ start_node) :\n        distances(node_count, INF),\n        prev_nodes(node_count,\
    \ NONE) {\n        this->distances[start_node] = 0;\n      }\n    };\n\n    dijkstra(const\
    \ ::std::size_t& node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t\
    \ node_count() const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) {\n      this->edges[from].emplace_back(from,\
    \ to, distance);\n    }\n\n    result query(const ::std::size_t& start_node) const\
    \ {\n      assert(start_node < this->node_count());\n\n      result result(this->node_count(),\
    \ start_node);\n      ::std::priority_queue<::std::pair<::std::size_t, T>, ::std::vector<::std::pair<::std::size_t,\
    \ T>>, ::tools::greater_by_second> tasks;\n      tasks.emplace(start_node, 0);\n\
    \n      while (!tasks.empty()) {\n        const auto [here, d] = tasks.top();\n\
    \        tasks.pop();\n        if (result.distances[here] < d) continue;\n   \
    \     for (const edge& edge : this->edges[here]) {\n          if (::tools::chmin(result.distances[edge.to],\
    \ result.distances[here] + edge.distance)) {\n            result.prev_nodes[edge.to]\
    \ = edge.from;\n            tasks.emplace(edge.to, result.distances[edge.to]);\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/greater_by_second.hpp
  - tools/chmin.hpp
  isVerificationFile: false
  path: tools/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-03-08 22:34:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dijkstra.test.cpp
documentation_of: tools/dijkstra.hpp
layout: document
title: Dijkstra's algorithm
---

It solves the single source shortest path problem on a given graph which is not necessarily simple.
All the edges must have the non-nagative weight.

### Usage
```cpp
tools::dijkstra<int> dijkstra(node_count);
dijkstra.add_edge(from_node, to_node, cost);
const tools::dijkstra<int>::result result = dijkstra.query(start_node);
for (const int& distance : result.distances) {
  // ...
}
```

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
dijkstra<T> dijkstra(::std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the weight of edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## add_edge
```cpp
void dijkstra.add_edge(::std::size_t s, ::std::size_t t, T w);
```

It adds a edge from $s$ to $t$ with the weight `w`.

### Constraints
- $0 \leq s < n$
- $0 \leq t < n$
- $w \geq 0$

### Time Complexity
- amortized $O(1)$

## query
```cpp
struct {
  ::std::vector<T> distances;
  ::std::vector<::std::size_t> prev_nodes;
} dijkstra.query(::std::size_t s);
```

It solves the single source shortest path problem on the graph.
`distances[t]` represents the distance from $s$ to $t$.
`prev_nodes[t]` represents the previous vertex on the shortest path from $s$ to $t$.
`prev_nodes[s]` will be `std::numeric_limits<std::size_t>::max()` instead of the previous vertex since the previous vertex of $s$ does not exist.

### Constraints
- $0 \leq s < n$

### Time Complexity
- $O((n + \|E\|) \log n)$ where $\|E\|$ is the number of edges
