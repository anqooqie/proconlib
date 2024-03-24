---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/is_bipartite.test.cpp
    title: tests/is_bipartite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/is_bipartite.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <cassert>\n#include <tuple>\n#include <algorithm>\n#include\
    \ <string>\n#include <queue>\n\nnamespace tools {\n\n  class is_bipartite {\n\
    \  public:\n    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n\
    \      ::std::size_t to;\n    };\n\n  private:\n    ::std::vector<edge> m_edges;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n    is_bipartite()\
    \ = default;\n    explicit is_bipartite(const ::std::size_t n) : m_graph(n) {\n\
    \    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v) {\n   \
    \   assert(u < this->size());\n      assert(v < this->size());\n      ::std::tie(u,\
    \ v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v});\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n     \
    \ this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    bool query() const {\n      ::std::string belongs(this->size(),\
    \ '?');\n      for (::std::size_t root = 0; root < this->size(); ++root) {\n \
    \       if (belongs[root] == '?') {\n          ::std::queue<::std::size_t> queue({root});\n\
    \          belongs[root] = '0';\n          while (!queue.empty()) {\n        \
    \    const auto here = queue.front();\n            queue.pop();\n            for\
    \ (const auto edge_id : this->m_graph[here]) {\n              const auto& edge\
    \ = this->m_edges[edge_id];\n              const auto next = edge.from ^ edge.to\
    \ ^ here;\n              if (belongs[next] == '?') {\n                belongs[next]\
    \ = ((belongs[here] - '0') ^ 1) + '0';\n                queue.push(next);\n  \
    \            } else {\n                if (belongs[here] == belongs[next]) {\n\
    \                  return false;\n                }\n              }\n       \
    \     }\n          }\n        }\n      }\n\n      return true;\n    }\n  };\n\
    }\n\n\n"
  code: "#ifndef TOOLS_IS_BIPARTITE_HPP\n#define TOOLS_IS_BIPARTITE_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <cassert>\n#include <tuple>\n#include\
    \ <algorithm>\n#include <string>\n#include <queue>\n\nnamespace tools {\n\n  class\
    \ is_bipartite {\n  public:\n    struct edge {\n      ::std::size_t id;\n    \
    \  ::std::size_t from;\n      ::std::size_t to;\n    };\n\n  private:\n    ::std::vector<edge>\
    \ m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n\
    \    is_bipartite() = default;\n    explicit is_bipartite(const ::std::size_t\
    \ n) : m_graph(n) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v) {\n   \
    \   assert(u < this->size());\n      assert(v < this->size());\n      ::std::tie(u,\
    \ v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v});\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n     \
    \ this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    bool query() const {\n      ::std::string belongs(this->size(),\
    \ '?');\n      for (::std::size_t root = 0; root < this->size(); ++root) {\n \
    \       if (belongs[root] == '?') {\n          ::std::queue<::std::size_t> queue({root});\n\
    \          belongs[root] = '0';\n          while (!queue.empty()) {\n        \
    \    const auto here = queue.front();\n            queue.pop();\n            for\
    \ (const auto edge_id : this->m_graph[here]) {\n              const auto& edge\
    \ = this->m_edges[edge_id];\n              const auto next = edge.from ^ edge.to\
    \ ^ here;\n              if (belongs[next] == '?') {\n                belongs[next]\
    \ = ((belongs[here] - '0') ^ 1) + '0';\n                queue.push(next);\n  \
    \            } else {\n                if (belongs[here] == belongs[next]) {\n\
    \                  return false;\n                }\n              }\n       \
    \     }\n          }\n        }\n      }\n\n      return true;\n    }\n  };\n\
    }\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/is_bipartite.hpp
  requiredBy: []
  timestamp: '2024-03-24 16:56:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/is_bipartite.test.cpp
documentation_of: tools/is_bipartite.hpp
layout: document
title: Check whether a given graph is bipartite
---

It checks whether a given undirected graph is bipartite.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
is_bipartite graph(std::size_t n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.

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
std::size_t graph.add_edge(std::size_t u, std::size_t v);
```

It adds an undirected edge between $u$ and $v$.
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
};
const edge& graph.get_edge(std::size_t k);
```

It returns the $k$-th ($0$ indexed) edge.

### Constraints
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

### Time Complexity
- $O(1)$

## edges
```cpp
const std::vector<edge>& graph.edges();
```

It returns all the edges in the graph.
The edges are ordered in the same order as added by `add_edge`.

### Constraints
- None

### Time Complexity
- $O(1)$

## query
```cpp
bool graph.query();
```

If the graph is bipartite, it returns `true`.
Otherwise, it returns `false`.

### Constraints
- None

### Time Complexity
- $O(n + \|E\|)$ where $\|E\|$ is the number of edges
