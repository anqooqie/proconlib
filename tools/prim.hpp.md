---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/greater_by.hpp
    title: std::greater by key
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/prim/basic.test.cpp
    title: tests/prim/basic.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/prim/unconnected.test.cpp
    title: tests/prim/unconnected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/prim.hpp\"\n\n\n\n#include <cstddef>\n#include <vector>\n\
    #include <cassert>\n#include <utility>\n#include <algorithm>\n#include <limits>\n\
    #include <queue>\n#line 1 \"tools/greater_by.hpp\"\n\n\n\nnamespace tools {\n\n\
    \  template <class F>\n  class greater_by {\n  private:\n    F selector;\n\n \
    \ public:\n    greater_by(const F& selector) : selector(selector) {\n    }\n\n\
    \    template <class T>\n    bool operator()(const T& x, const T& y) const {\n\
    \      return selector(x) > selector(y);\n    }\n  };\n}\n\n\n#line 12 \"tools/prim.hpp\"\
    \n\nnamespace tools {\n\n  template <typename T>\n  class prim {\n  public:\n\
    \    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n     \
    \ ::std::size_t to;\n      T cost;\n    };\n\n  private:\n    ::std::vector<edge>\
    \ m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n\
    \    prim() = default;\n    prim(const ::tools::prim<T>&) = default;\n    prim(::tools::prim<T>&&)\
    \ = default;\n    ~prim() = default;\n    ::tools::prim<T>& operator=(const ::tools::prim<T>&)\
    \ = default;\n    ::tools::prim<T>& operator=(::tools::prim<T>&&) = default;\n\
    \n    prim(const ::std::size_t n) : m_graph(n) {\n    }\n\n    ::std::size_t size()\
    \ const {\n      return this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(::std::size_t\
    \ u, ::std::size_t v, const T w) {\n      assert(u < this->size());\n      assert(v\
    \ < this->size());\n      ::std::tie(u, v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n \
    \     this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::pair<::std::vector<::std::pair<T, ::std::vector<::std::size_t>>>,\
    \ ::std::vector<::std::size_t>> query() const {\n      ::std::pair<::std::vector<::std::pair<T,\
    \ ::std::vector<::std::size_t>>>, ::std::vector<::std::size_t>> res;\n      auto&\
    \ [groups, belongs_to] = res;\n      belongs_to.resize(this->size());\n      ::std::fill(belongs_to.begin(),\
    \ belongs_to.end(), ::std::numeric_limits<::std::size_t>::max());\n\n      for\
    \ (::std::size_t root = 0; root < this->size(); ++root) {\n        if (belongs_to[root]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n        const auto\
    \ greater_by_cost = ::tools::greater_by([&](const auto& pair) { return this->m_edges[pair.first].cost;\
    \ });\n        ::std::priority_queue<::std::pair<::std::size_t, ::std::size_t>,\
    \ ::std::vector<::std::pair<::std::size_t, ::std::size_t>>, decltype(greater_by_cost)>\
    \ pq(greater_by_cost);\n        groups.emplace_back(0, ::std::vector<::std::size_t>());\n\
    \        auto& [total_cost, edge_ids] = groups.back();\n\n        belongs_to[root]\
    \ = groups.size() - 1;\n        for (const auto e : this->m_graph[root]) {\n \
    \         const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ root;\n\
    \          if (belongs_to[next] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          pq.emplace(e, next);\n        }\n\n        while (!pq.empty())\
    \ {\n          const auto [from_edge_id, here] = pq.top();\n          pq.pop();\n\
    \n          if (belongs_to[here] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          belongs_to[here] = belongs_to[root];\n          total_cost\
    \ += this->m_edges[from_edge_id].cost;\n          edge_ids.push_back(from_edge_id);\n\
    \          for (const auto e : this->m_graph[here]) {\n            const auto\
    \ next = this->m_edges[e].from ^ this->m_edges[e].to ^ here;\n            if (belongs_to[next]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n            pq.emplace(e,\
    \ next);\n          }\n        }\n      }\n\n      return res;\n    }\n  };\n\
    }\n\n\n"
  code: "#ifndef TOOLS_PRIM_HPP\n#define TOOLS_PRIM_HPP\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <cassert>\n#include <utility>\n#include <algorithm>\n#include\
    \ <limits>\n#include <queue>\n#include \"tools/greater_by.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  class prim {\n  public:\n    struct edge {\n\
    \      ::std::size_t id;\n      ::std::size_t from;\n      ::std::size_t to;\n\
    \      T cost;\n    };\n\n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    prim() = default;\n    prim(const ::tools::prim<T>&)\
    \ = default;\n    prim(::tools::prim<T>&&) = default;\n    ~prim() = default;\n\
    \    ::tools::prim<T>& operator=(const ::tools::prim<T>&) = default;\n    ::tools::prim<T>&\
    \ operator=(::tools::prim<T>&&) = default;\n\n    prim(const ::std::size_t n)\
    \ : m_graph(n) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   ::std::tie(u, v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n \
    \     this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::pair<::std::vector<::std::pair<T, ::std::vector<::std::size_t>>>,\
    \ ::std::vector<::std::size_t>> query() const {\n      ::std::pair<::std::vector<::std::pair<T,\
    \ ::std::vector<::std::size_t>>>, ::std::vector<::std::size_t>> res;\n      auto&\
    \ [groups, belongs_to] = res;\n      belongs_to.resize(this->size());\n      ::std::fill(belongs_to.begin(),\
    \ belongs_to.end(), ::std::numeric_limits<::std::size_t>::max());\n\n      for\
    \ (::std::size_t root = 0; root < this->size(); ++root) {\n        if (belongs_to[root]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n        const auto\
    \ greater_by_cost = ::tools::greater_by([&](const auto& pair) { return this->m_edges[pair.first].cost;\
    \ });\n        ::std::priority_queue<::std::pair<::std::size_t, ::std::size_t>,\
    \ ::std::vector<::std::pair<::std::size_t, ::std::size_t>>, decltype(greater_by_cost)>\
    \ pq(greater_by_cost);\n        groups.emplace_back(0, ::std::vector<::std::size_t>());\n\
    \        auto& [total_cost, edge_ids] = groups.back();\n\n        belongs_to[root]\
    \ = groups.size() - 1;\n        for (const auto e : this->m_graph[root]) {\n \
    \         const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ root;\n\
    \          if (belongs_to[next] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          pq.emplace(e, next);\n        }\n\n        while (!pq.empty())\
    \ {\n          const auto [from_edge_id, here] = pq.top();\n          pq.pop();\n\
    \n          if (belongs_to[here] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          belongs_to[here] = belongs_to[root];\n          total_cost\
    \ += this->m_edges[from_edge_id].cost;\n          edge_ids.push_back(from_edge_id);\n\
    \          for (const auto e : this->m_graph[here]) {\n            const auto\
    \ next = this->m_edges[e].from ^ this->m_edges[e].to ^ here;\n            if (belongs_to[next]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n            pq.emplace(e,\
    \ next);\n          }\n        }\n      }\n\n      return res;\n    }\n  };\n\
    }\n\n#endif\n"
  dependsOn:
  - tools/greater_by.hpp
  isVerificationFile: false
  path: tools/prim.hpp
  requiredBy: []
  timestamp: '2022-10-01 12:09:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/prim/unconnected.test.cpp
  - tests/prim/basic.test.cpp
documentation_of: tools/prim.hpp
layout: document
title: Prim's algorithm
---

It constructs minimum spanning trees for each connected components of a given undirected graph which is not necessarily simple based on Prim's algorithm.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
prim<T> graph(std::size_t n);
```

It creates an undirected graph with $n$ vertices and $0$ edges.
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

It adds an undirected edge between $u$ and $v$ with cost `w`.
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
std::pair<std::vector<std::pair<T, std::vector<std::size_t>>>, std::vector<std::size_t>> graph.query();
```

It constructs minimum spanning trees for each connected components of the graph, and returns the information about the minimum spanning trees in the following layout.
The order of minimum spanning trees is undefined.

```
(
  [
    (
      total cost of the 0th MST,
      [
        index of an edge in the 0th MST,
        index of another edge in the 0th MST,
        ...
      ]
    ),
    (
      total cost of the 1st MST,
      [
        index of an edge in the 1st MST,
        index of another edge in the 1st MST,
        ...
      ]
    ),
    (
      total cost of the 2nd MST,
      [
        index of an edge in the 2nd MST,
        index of another edge in the 2nd MST,
        ...
      ]
    ),
    ...
  ],
  [
    index of the MST which contains the 0th vertex,
    index of the MST which contains the 1st vertex,
    index of the MST which contains the 2nd vertex,
    ...
  ]
)
```

### Constraints
- None

### Time Complexity
- $O((n + \|E\|) \log n)$ where $\|E\|$ is the number of edges
