---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/bellman_ford.test.cpp
    title: tests/bellman_ford.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/bellman_ford.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <cassert>\n#include <utility>\n#include <limits>\n#line 1\
    \ \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool\
    \ updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 10 \"tools/bellman_ford.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  class bellman_ford {\n  public:\n    struct edge {\n      ::std::size_t\
    \ id;\n      ::std::size_t from;\n      ::std::size_t to;\n      T cost;\n   \
    \ };\n\n  private:\n    ::std::size_t m_size;\n    ::std::vector<edge> m_edges;\n\
    \n  public:\n    bellman_ford() = default;\n    bellman_ford(const ::tools::bellman_ford<T>&)\
    \ = default;\n    bellman_ford(::tools::bellman_ford<T>&&) = default;\n    ~bellman_ford()\
    \ = default;\n    ::tools::bellman_ford<T>& operator=(const ::tools::bellman_ford<T>&)\
    \ = default;\n    ::tools::bellman_ford<T>& operator=(::tools::bellman_ford<T>&&)\
    \ = default;\n\n    explicit bellman_ford(const ::std::size_t n) : m_size(n) {\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->m_size;\n    }\n\
    \n    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t v, const\
    \ T& w) {\n      assert(u < this->size());\n      assert(v < this->size());\n\
    \      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));\n     \
    \ return this->m_edges.size() - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t\
    \ k) const {\n      assert(k < this->m_edges.size());\n      return this->m_edges[k];\n\
    \    }\n\n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>> query(const\
    \ ::std::size_t s) {\n      assert(s < this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[s] = 0;\n \
    \     ::std::vector<::std::size_t> prev(this->size());\n      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\
    \n      for (::std::size_t i = 0; i + 1 < this->size(); ++i) {\n        for (const\
    \ auto& edge : this->m_edges) {\n          if (dist[edge.from] < ::std::numeric_limits<T>::max()\
    \ && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {\n         \
    \   prev[edge.to] = edge.id;\n          }\n        }\n      }\n      for (const\
    \ auto& edge : this->m_edges) {\n        if (dist[edge.from] < ::std::numeric_limits<T>::max()\
    \ && dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost\
    \ : 0) < dist[edge.to]) {\n          dist[edge.to] = ::std::numeric_limits<T>::min();\n\
    \          prev[edge.to] = edge.id;\n        }\n      }\n      for (::std::size_t\
    \ i = 0; i + 1 < this->size(); ++i) {\n        for (const auto& edge : this->m_edges)\
    \ {\n          if (dist[edge.from] < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to],\
    \ dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost\
    \ : 0))) {\n            prev[edge.to] = edge.id;\n          }\n        }\n   \
    \   }\n\n      return ::std::make_pair(dist, prev);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_BELLMAN_FORD_HPP\n#define TOOLS_BELLMAN_FORD_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <cassert>\n#include <utility>\n#include\
    \ <limits>\n#include \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  class bellman_ford {\n  public:\n    struct edge {\n      ::std::size_t\
    \ id;\n      ::std::size_t from;\n      ::std::size_t to;\n      T cost;\n   \
    \ };\n\n  private:\n    ::std::size_t m_size;\n    ::std::vector<edge> m_edges;\n\
    \n  public:\n    bellman_ford() = default;\n    bellman_ford(const ::tools::bellman_ford<T>&)\
    \ = default;\n    bellman_ford(::tools::bellman_ford<T>&&) = default;\n    ~bellman_ford()\
    \ = default;\n    ::tools::bellman_ford<T>& operator=(const ::tools::bellman_ford<T>&)\
    \ = default;\n    ::tools::bellman_ford<T>& operator=(::tools::bellman_ford<T>&&)\
    \ = default;\n\n    explicit bellman_ford(const ::std::size_t n) : m_size(n) {\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->m_size;\n    }\n\
    \n    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t v, const\
    \ T& w) {\n      assert(u < this->size());\n      assert(v < this->size());\n\
    \      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));\n     \
    \ return this->m_edges.size() - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t\
    \ k) const {\n      assert(k < this->m_edges.size());\n      return this->m_edges[k];\n\
    \    }\n\n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>> query(const\
    \ ::std::size_t s) {\n      assert(s < this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[s] = 0;\n \
    \     ::std::vector<::std::size_t> prev(this->size());\n      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\
    \n      for (::std::size_t i = 0; i + 1 < this->size(); ++i) {\n        for (const\
    \ auto& edge : this->m_edges) {\n          if (dist[edge.from] < ::std::numeric_limits<T>::max()\
    \ && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {\n         \
    \   prev[edge.to] = edge.id;\n          }\n        }\n      }\n      for (const\
    \ auto& edge : this->m_edges) {\n        if (dist[edge.from] < ::std::numeric_limits<T>::max()\
    \ && dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost\
    \ : 0) < dist[edge.to]) {\n          dist[edge.to] = ::std::numeric_limits<T>::min();\n\
    \          prev[edge.to] = edge.id;\n        }\n      }\n      for (::std::size_t\
    \ i = 0; i + 1 < this->size(); ++i) {\n        for (const auto& edge : this->m_edges)\
    \ {\n          if (dist[edge.from] < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to],\
    \ dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost\
    \ : 0))) {\n            prev[edge.to] = edge.id;\n          }\n        }\n   \
    \   }\n\n      return ::std::make_pair(dist, prev);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/chmin.hpp
  isVerificationFile: false
  path: tools/bellman_ford.hpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bellman_ford.test.cpp
documentation_of: tools/bellman_ford.hpp
layout: document
title: Bellman-Ford algorithm
---

It solves the single source shortest path problem on a given graph which is not necessarily simple.
The graph can have negative cycles.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
bellman_ford<T> graph(std::size_t n);
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
It returns an integer $k$ such that this is the $k$-th ($0$ indexed) edge that is added.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

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

It returns the $k$-th ($0$ indexed) edge.

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
If $t = s$ or $t$ is unrechable from $s$, `prev[t]` is `std::numeric_limits<std::size_t>::max()`.

### Constraints
- $0 \leq s < n$

### Time Complexity
- $O(n\|E\|)$ where $\|E\|$ is the number of edges
