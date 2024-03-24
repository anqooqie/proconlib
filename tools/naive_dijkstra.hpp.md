---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/naive_dijkstra.test.cpp
    title: tests/naive_dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/naive_dijkstra.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <limits>\n#include <cassert>\n#include <tuple>\n#include\
    \ <algorithm>\n#include <utility>\n#include <numeric>\n#include <iterator>\n#line\
    \ 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class F>\n \
    \ class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 1 \"tools/cmp_less.hpp\"\
    \n\n\n\n#include <type_traits>\n\nnamespace tools {\n  template <typename T, typename\
    \ U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n    using UT\
    \ = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n  \
    \  if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool\
    \ updated = ::tools::cmp_less(rhs, lhs);\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n\n#line 15 \"tools/naive_dijkstra.hpp\"\n\nnamespace tools\
    \ {\n\n  template <bool Directed, typename T>\n  class naive_dijkstra {\n  public:\n\
    \    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n     \
    \ ::std::size_t to;\n      T cost;\n    };\n\n  private:\n    ::std::size_t m_size;\n\
    \    ::std::vector<edge> m_edges;\n    ::std::vector<::std::size_t> m_graph;\n\
    \n  public:\n    naive_dijkstra() = default;\n    naive_dijkstra(const ::tools::naive_dijkstra<Directed,\
    \ T>&) = default;\n    naive_dijkstra(::tools::naive_dijkstra<Directed, T>&&)\
    \ = default;\n    ~naive_dijkstra() = default;\n    ::tools::naive_dijkstra<Directed,\
    \ T>& operator=(const ::tools::naive_dijkstra<Directed, T>&) = default;\n    ::tools::naive_dijkstra<Directed,\
    \ T>& operator=(::tools::naive_dijkstra<Directed, T>&&) = default;\n\n    explicit\
    \ naive_dijkstra(const ::std::size_t n) : m_size(n), m_graph(n * n, ::std::numeric_limits<::std::size_t>::max())\
    \ {\n    }\n\n    ::std::size_t size() const {\n      return this->m_size;\n \
    \   }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T&\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   assert(w >= 0);\n      if constexpr (!Directed) {\n        ::std::tie(u, v)\
    \ = ::std::minmax({u, v});\n      }\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v, w});\n      if (this->m_graph[u * this->size() + v] == ::std::numeric_limits<::std::size_t>::max()\
    \ || w < this->m_edges[this->m_graph[u * this->size() + v]].cost) {\n        this->m_graph[u\
    \ * this->size() + v] = this->m_edges.size() - 1;\n        if constexpr (!Directed)\
    \ {\n            this->m_graph[v * this->size() + u] = this->m_edges.size() -\
    \ 1;\n        }\n      }\n      return this->m_edges.size() - 1;\n    }\n\n  \
    \  const edge& get_edge(const ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n\
    \      return this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges()\
    \ const {\n      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>,\
    \ ::std::vector<::std::size_t>> query(const ::std::size_t s) const {\n      assert(s\
    \ < this->size());\n\n      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());\n\
    \      dist[s] = 0;\n      ::std::vector<::std::size_t> prev(this->size());\n\
    \      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\n      ::std::vector<::std::size_t>\
    \ Q(this->size());\n      ::std::iota(Q.begin(), Q.end(), 0);\n      while (!Q.empty())\
    \ {\n        const auto min_it = ::std::min_element(Q.begin(), Q.end(), ::tools::less_by([&](const\
    \ auto v) { return dist[v]; }));\n        const auto here = *min_it;\n       \
    \ if (dist[here] == ::std::numeric_limits<T>::max()) break;\n\n        ::std::iter_swap(min_it,\
    \ ::std::prev(Q.end()));\n        Q.pop_back();\n\n        for (const auto next\
    \ : Q) {\n          if (this->m_graph[here * this->size() + next] != ::std::numeric_limits<::std::size_t>::max()\
    \ && ::tools::chmin(dist[next], dist[here] + this->m_edges[this->m_graph[here\
    \ * this->size() + next]].cost)) {\n            prev[next] = this->m_graph[here\
    \ * this->size() + next];\n          }\n        }\n      }\n\n      return ::std::make_pair(dist,\
    \ prev);\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_NAIVE_DIJKSTRA_HPP\n#define TOOLS_NAIVE_DIJKSTRA_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <limits>\n#include <cassert>\n#include\
    \ <tuple>\n#include <algorithm>\n#include <utility>\n#include <numeric>\n#include\
    \ <iterator>\n#include \"tools/less_by.hpp\"\n#include \"tools/chmin.hpp\"\n\n\
    namespace tools {\n\n  template <bool Directed, typename T>\n  class naive_dijkstra\
    \ {\n  public:\n    struct edge {\n      ::std::size_t id;\n      ::std::size_t\
    \ from;\n      ::std::size_t to;\n      T cost;\n    };\n\n  private:\n    ::std::size_t\
    \ m_size;\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::size_t>\
    \ m_graph;\n\n  public:\n    naive_dijkstra() = default;\n    naive_dijkstra(const\
    \ ::tools::naive_dijkstra<Directed, T>&) = default;\n    naive_dijkstra(::tools::naive_dijkstra<Directed,\
    \ T>&&) = default;\n    ~naive_dijkstra() = default;\n    ::tools::naive_dijkstra<Directed,\
    \ T>& operator=(const ::tools::naive_dijkstra<Directed, T>&) = default;\n    ::tools::naive_dijkstra<Directed,\
    \ T>& operator=(::tools::naive_dijkstra<Directed, T>&&) = default;\n\n    explicit\
    \ naive_dijkstra(const ::std::size_t n) : m_size(n), m_graph(n * n, ::std::numeric_limits<::std::size_t>::max())\
    \ {\n    }\n\n    ::std::size_t size() const {\n      return this->m_size;\n \
    \   }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T&\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   assert(w >= 0);\n      if constexpr (!Directed) {\n        ::std::tie(u, v)\
    \ = ::std::minmax({u, v});\n      }\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v, w});\n      if (this->m_graph[u * this->size() + v] == ::std::numeric_limits<::std::size_t>::max()\
    \ || w < this->m_edges[this->m_graph[u * this->size() + v]].cost) {\n        this->m_graph[u\
    \ * this->size() + v] = this->m_edges.size() - 1;\n        if constexpr (!Directed)\
    \ {\n            this->m_graph[v * this->size() + u] = this->m_edges.size() -\
    \ 1;\n        }\n      }\n      return this->m_edges.size() - 1;\n    }\n\n  \
    \  const edge& get_edge(const ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n\
    \      return this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges()\
    \ const {\n      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>,\
    \ ::std::vector<::std::size_t>> query(const ::std::size_t s) const {\n      assert(s\
    \ < this->size());\n\n      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());\n\
    \      dist[s] = 0;\n      ::std::vector<::std::size_t> prev(this->size());\n\
    \      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\n      ::std::vector<::std::size_t>\
    \ Q(this->size());\n      ::std::iota(Q.begin(), Q.end(), 0);\n      while (!Q.empty())\
    \ {\n        const auto min_it = ::std::min_element(Q.begin(), Q.end(), ::tools::less_by([&](const\
    \ auto v) { return dist[v]; }));\n        const auto here = *min_it;\n       \
    \ if (dist[here] == ::std::numeric_limits<T>::max()) break;\n\n        ::std::iter_swap(min_it,\
    \ ::std::prev(Q.end()));\n        Q.pop_back();\n\n        for (const auto next\
    \ : Q) {\n          if (this->m_graph[here * this->size() + next] != ::std::numeric_limits<::std::size_t>::max()\
    \ && ::tools::chmin(dist[next], dist[here] + this->m_edges[this->m_graph[here\
    \ * this->size() + next]].cost)) {\n            prev[next] = this->m_graph[here\
    \ * this->size() + next];\n          }\n        }\n      }\n\n      return ::std::make_pair(dist,\
    \ prev);\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/less_by.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  isVerificationFile: false
  path: tools/naive_dijkstra.hpp
  requiredBy: []
  timestamp: '2024-03-24 16:56:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/naive_dijkstra.test.cpp
documentation_of: tools/naive_dijkstra.hpp
layout: document
title: Dijkstra's algorithm for dense graph
---

It solves the single source shortest path problem on a given graph which is not necessarily simple.
All the edges must have non-nagative costs.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
naive_dijkstra<Directed, T> graph(std::size_t n);
```

If the type parameter `<Directed>` is `true`, it creates a directed graph with $n$ vertices and $0$ edges.
If the type parameter `<Directed>` is `false`, it creates an undirected graph with $n$ vertices and $0$ edges.
The type parameter `<T>` represents the type of the cost.

### Constraints
- None

### Time Complexity
- $O(n^2)$

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

If `<Directed>` is `true`, it adds a directed edge oriented from $u$ to $v$ with cost `w`.
If `<Directed>` is `false`, it adds an undirected edge between $u$ and $v$ with cost `w`.
It returns an integer $k$ such that this is the $k$-th ($0$ indexed) edge that is added.

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
- $O(n^2)$
