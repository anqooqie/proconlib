---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ <vector>\n#include <cassert>\n#include <utility>\n#include <limits>\n#include\
    \ <queue>\n#line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#line 5 \"tools/greater_by_second.hpp\"\
    \n\nnamespace tools {\n\n  class greater_by_second {\n  public:\n    template\
    \ <class T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const\
    \ ::std::pair<T1, T2>& y) const {\n      return x.second > y.second;\n    }\n\
    \  };\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n#line 12 \"tools/dijkstra.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class dijkstra {\n  public:\n    struct\
    \ edge {\n      ::std::size_t id;\n      ::std::size_t from;\n      ::std::size_t\
    \ to;\n      T cost;\n    };\n\n  private:\n    ::std::vector<edge> m_edges;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n    dijkstra()\
    \ = default;\n    dijkstra(const ::tools::dijkstra<T>&) = default;\n    dijkstra(::tools::dijkstra<T>&&)\
    \ = default;\n    ~dijkstra() = default;\n    ::tools::dijkstra<T>& operator=(const\
    \ ::tools::dijkstra<T>&) = default;\n    ::tools::dijkstra<T>& operator=(::tools::dijkstra<T>&&)\
    \ = default;\n\n    dijkstra(const ::std::size_t n) : m_graph(n) {\n    }\n\n\
    \    ::std::size_t size() const {\n      return this->m_graph.size();\n    }\n\
    \n    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t v, const\
    \ T& w) {\n      assert(u < this->size());\n      assert(v < this->size());\n\
    \      assert(w >= 0);\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n \
    \     return this->m_edges.size() - 1;\n    }\n\n    const edge& get_edge(const\
    \ ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n      return\
    \ this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges() const {\n\
    \      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>>\
    \ query(const ::std::size_t s) {\n      assert(s < this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[s] = 0;\n \
    \     ::std::vector<::std::size_t> prev(this->size());\n      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\
    \      ::std::priority_queue<::std::pair<::std::size_t, T>, ::std::vector<::std::pair<::std::size_t,\
    \ T>>, ::tools::greater_by_second> pq;\n      pq.emplace(s, 0);\n\n      while\
    \ (!pq.empty()) {\n        const auto [here, d] = pq.top();\n        pq.pop();\n\
    \        if (dist[here] < d) continue;\n        for (const auto edge_id : this->m_graph[here])\
    \ {\n          const auto& edge = this->m_edges[edge_id];\n          if (::tools::chmin(dist[edge.to],\
    \ dist[here] + edge.cost)) {\n            prev[edge.to] = edge.id;\n         \
    \   pq.emplace(edge.to, dist[edge.to]);\n          }\n        }\n      }\n\n \
    \     return ::std::make_pair(dist, prev);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DIJKSTRA_HPP\n#define TOOLS_DIJKSTRA_HPP\n\n#include <cstddef>\n\
    #include <vector>\n#include <cassert>\n#include <utility>\n#include <limits>\n\
    #include <queue>\n#include \"tools/greater_by_second.hpp\"\n#include \"tools/chmin.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  class dijkstra {\n  public:\n\
    \    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n     \
    \ ::std::size_t to;\n      T cost;\n    };\n\n  private:\n    ::std::vector<edge>\
    \ m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n\
    \    dijkstra() = default;\n    dijkstra(const ::tools::dijkstra<T>&) = default;\n\
    \    dijkstra(::tools::dijkstra<T>&&) = default;\n    ~dijkstra() = default;\n\
    \    ::tools::dijkstra<T>& operator=(const ::tools::dijkstra<T>&) = default;\n\
    \    ::tools::dijkstra<T>& operator=(::tools::dijkstra<T>&&) = default;\n\n  \
    \  dijkstra(const ::std::size_t n) : m_graph(n) {\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_graph.size();\n    }\n\n    ::std::size_t\
    \ add_edge(const ::std::size_t u, const ::std::size_t v, const T& w) {\n     \
    \ assert(u < this->size());\n      assert(v < this->size());\n      assert(w >=\
    \ 0);\n      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));\n\
    \      this->m_graph[u].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>> query(const\
    \ ::std::size_t s) {\n      assert(s < this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[s] = 0;\n \
    \     ::std::vector<::std::size_t> prev(this->size());\n      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\
    \      ::std::priority_queue<::std::pair<::std::size_t, T>, ::std::vector<::std::pair<::std::size_t,\
    \ T>>, ::tools::greater_by_second> pq;\n      pq.emplace(s, 0);\n\n      while\
    \ (!pq.empty()) {\n        const auto [here, d] = pq.top();\n        pq.pop();\n\
    \        if (dist[here] < d) continue;\n        for (const auto edge_id : this->m_graph[here])\
    \ {\n          const auto& edge = this->m_edges[edge_id];\n          if (::tools::chmin(dist[edge.to],\
    \ dist[here] + edge.cost)) {\n            prev[edge.to] = edge.id;\n         \
    \   pq.emplace(edge.to, dist[edge.to]);\n          }\n        }\n      }\n\n \
    \     return ::std::make_pair(dist, prev);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/greater_by_second.hpp
  - tools/chmin.hpp
  isVerificationFile: false
  path: tools/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-07-16 04:36:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dijkstra.test.cpp
documentation_of: tools/dijkstra.hpp
layout: document
title: Dijkstra's algorithm
---

It solves the single source shortest path problem on a given graph which is not necessarily simple.
All the edges must have non-nagative costs.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
dijkstra<T> graph(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the cost.

### Constraints
- None

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t graph.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
std::size_t graph.add_edge(std::size_t u, std::size_t v, T w);
```

It adds an edge oriented from $u$ to $v$ with cost `w`.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$
- $w \geq 0$

### Time Complexity
- $O(1)$ amortized

## get_edge
```cpp
struct edge {
  std::size_t id;
  std::size_t from;
  std::size_t to;
  T cost;
};
edge graph.get_edge(std::size_t k);
```

It returns the $k$-th edge.

### Constraints
- None

### Time Complexity
- $O(1)$

## edges
```cpp
std::vector<edge> graph.edges();
```

It returns all the edges in the graph.
The edges are ordered in the same order as added by `add_edge`.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
std::pair<std::vector<T>, std::vector<std::size_t>> graph.query(std::size_t s);
```

It solves the single source shortest path problem on the graph.
It returns two vectors `dist` and `prev`.
`dist[t]` represents the smallest value as the sum of the costs of the edges that make up the path from $s$ to $t$.
`prev[t]` represents the index of the edge from the parent of $t$ to $t$ in the shortest path tree rooted at $s$.
Because `s` has no parent, `prev[s]` will be `std::numeric_limits<std::size_t>::max()` instead of a valid value.

### Constraints
- $0 \leq s < n$

### Time Complexity
- $O((n + \|E\|) \log n)$ where $\|E\|$ is the number of edges
