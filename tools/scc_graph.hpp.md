---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/less_by.hpp
    title: std::less by key
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: tests/scc_graph/edges_to_scc.test.cpp
    title: tests/scc_graph/edges_to_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/scc_id.test.cpp
    title: tests/scc_graph/scc_id.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/scc_graph/sccs.test.cpp
    title: tests/scc_graph/sccs.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/scc_graph.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <utility>\n#include <cstddef>\n#include <cassert>\n#include <stack>\n#include\
    \ <algorithm>\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template\
    \ <class F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n   \
    \ less_by(const F& selector) : selector(selector) {\n    }\n\n    template <class\
    \ T>\n    bool operator()(const T& x, const T& y) const {\n      return selector(x)\
    \ < selector(y);\n    }\n  };\n}\n\n\n#line 11 \"tools/scc_graph.hpp\"\n\nnamespace\
    \ tools {\n  class scc_graph {\n  private:\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_rev_graph;\n    ::std::vector<::std::size_t>\
    \ m_vid2scc;\n    ::std::vector<::std::vector<::std::size_t>> m_sccs;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_edges_in_scc;\n    ::std::vector<::std::vector<::std::pair<::std::size_t,\
    \ ::std::vector<::std::size_t>>>> m_scc_graph;\n    ::std::vector<::std::vector<::std::pair<::std::size_t,\
    \ ::std::vector<::std::size_t>>>> m_rev_scc_graph;\n    bool m_built;\n\n  public:\n\
    \    scc_graph() = default;\n    scc_graph(const ::tools::scc_graph&) = default;\n\
    \    scc_graph(::tools::scc_graph&&) = default;\n    ~scc_graph() = default;\n\
    \    ::tools::scc_graph& operator=(const ::tools::scc_graph&) = default;\n   \
    \ ::tools::scc_graph& operator=(::tools::scc_graph&&) = default;\n\n    explicit\
    \ scc_graph(const ::std::size_t n) : m_graph(n), m_rev_graph(n), m_vid2scc(n),\
    \ m_built(false) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(const ::std::size_t from, const ::std::size_t\
    \ to) {\n      assert(from < this->size());\n      assert(to < this->size());\n\
    \      assert(!this->m_built);\n      const auto edge_id = this->m_edges.size();\n\
    \      this->m_edges.emplace_back(from, to);\n      this->m_graph[from].push_back(edge_id);\n\
    \      this->m_rev_graph[to].push_back(edge_id);\n      return edge_id;\n    }\n\
    \n    ::std::pair<::std::size_t, ::std::size_t> edge(const ::std::size_t i) const\
    \ {\n      assert(i < this->m_edges.size());\n      return this->m_edges[i];\n\
    \    }\n    const ::std::vector<::std::size_t>& edges_from(const ::std::size_t\
    \ i) const {\n      assert(i < this->size());\n      return this->m_graph[i];\n\
    \    }\n    const ::std::vector<::std::size_t>& edges_to(const ::std::size_t i)\
    \ const {\n      assert(i < this->size());\n      return this->m_rev_graph[i];\n\
    \    }\n\n    void build() {\n      assert(!this->m_built);\n      ::std::stack<::std::size_t>\
    \ ordered_by_dfs;\n      {\n        ::std::vector<bool> visited(this->size(),\
    \ false);\n        ::std::stack<::std::pair<bool, ::std::size_t>> stack;\n   \
    \     for (::std::size_t i = this->size(); i --> 0;) {\n          stack.emplace(true,\
    \ i);\n        }\n        while (!stack.empty()) {\n          const auto [pre,\
    \ here] = stack.top();\n          stack.pop();\n          if (pre) {\n       \
    \     if (visited[here]) continue;\n            visited[here] = true;\n      \
    \      stack.emplace(false, here);\n            for (const auto e : this->m_graph[here])\
    \ {\n              const auto next = this->m_edges[e].second;\n              if\
    \ (visited[next]) continue;\n              stack.emplace(true, next);\n      \
    \      }\n          } else {\n            ordered_by_dfs.push(here);\n       \
    \   }\n        }\n      }\n\n      {\n        ::std::vector<bool> visited(this->size(),\
    \ false);\n        while (!ordered_by_dfs.empty()) {\n          const auto root\
    \ = ordered_by_dfs.top();\n          ordered_by_dfs.pop();\n          if (visited[root])\
    \ continue;\n\n          const auto scc_id = this->m_sccs.size();\n          this->m_sccs.emplace_back();\n\
    \          this->m_edges_in_scc.emplace_back();\n          this->m_scc_graph.emplace_back();\n\
    \          this->m_rev_scc_graph.emplace_back();\n\n          ::std::stack<::std::size_t>\
    \ stack({root});\n          while (!stack.empty()) {\n            const auto here\
    \ = stack.top();\n            stack.pop();\n            if (visited[here]) continue;\n\
    \            visited[here] = true;\n\n            this->m_vid2scc[here] = scc_id;\n\
    \            this->m_sccs[scc_id].push_back(here);\n\n            for (const auto\
    \ e : this->m_rev_graph[here]) {\n              const auto next = this->m_edges[e].first;\n\
    \              if (visited[next]) continue;\n              stack.push(next);\n\
    \            }\n          }\n\n          ::std::vector<::std::size_t> buffer;\
    \ \n          for (const auto v : this->m_sccs[scc_id]) {\n            for (const\
    \ auto e : this->m_rev_graph[v]) {\n              const auto u = this->m_edges[e].first;\n\
    \              if (this->m_vid2scc[u] == this->m_vid2scc[v]) {\n             \
    \   this->m_edges_in_scc[scc_id].push_back(e);\n              } else {\n     \
    \           buffer.push_back(e);\n              }\n            }\n          }\n\
    \n          ::std::sort(buffer.begin(), buffer.end(), tools::less_by([&](const\
    \ auto e) { return this->m_vid2scc[this->m_edges[e].first]; }));\n          for\
    \ (::std::size_t l = 0, r = 0; l < buffer.size(); l = r) {\n            const\
    \ auto u_scc_id = this->m_vid2scc[this->m_edges[buffer[l]].first];\n         \
    \   this->m_rev_scc_graph[scc_id].emplace_back(u_scc_id, ::std::vector<::std::size_t>());\n\
    \            for (; r < buffer.size() && this->m_vid2scc[this->m_edges[buffer[l]].first]\
    \ == this->m_vid2scc[this->m_edges[buffer[r]].first]; ++r);\n            for (::std::size_t\
    \ i = l; i < r; ++i) {\n              this->m_rev_scc_graph[scc_id].back().second.push_back(buffer[i]);\n\
    \            }\n          }\n        }\n\n        for (::std::size_t v_scc_id\
    \ = 0; v_scc_id < this->m_sccs.size(); ++v_scc_id) {\n          for (const auto&\
    \ [u_scc_id, edge_ids] : this->m_rev_scc_graph[v_scc_id]) {\n            this->m_scc_graph[u_scc_id].emplace_back(v_scc_id,\
    \ edge_ids);\n          }\n        }\n      }\n\n      this->m_built = true;\n\
    \    }\n\n    ::std::size_t scc_id(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      assert(this->m_built);\n      return this->m_vid2scc[i];\n\
    \    }\n    const ::std::vector<::std::vector<::std::size_t>>& sccs() const {\n\
    \      assert(this->m_built);\n      return this->m_sccs;\n    }\n    const ::std::vector<::std::size_t>&\
    \ edges_in_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_edges_in_scc[i];\n    }\n\
    \    const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_from_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_scc_graph[i];\n    }\n   \
    \ const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_to_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_rev_scc_graph[i];\n    }\n\
    \  };\n}\n\n\n"
  code: "#ifndef TOOLS_SCC_GRAPH_HPP\n#define TOOLS_SCC_GRAPH_HPP\n\n#include <vector>\n\
    #include <utility>\n#include <cstddef>\n#include <cassert>\n#include <stack>\n\
    #include <algorithm>\n#include \"tools/less_by.hpp\"\n\nnamespace tools {\n  class\
    \ scc_graph {\n  private:\n    ::std::vector<::std::pair<::std::size_t, ::std::size_t>>\
    \ m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_rev_graph;\n    ::std::vector<::std::size_t> m_vid2scc;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_sccs;\n    ::std::vector<::std::vector<::std::size_t>> m_edges_in_scc;\n \
    \   ::std::vector<::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>>\
    \ m_scc_graph;\n    ::std::vector<::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>>\
    \ m_rev_scc_graph;\n    bool m_built;\n\n  public:\n    scc_graph() = default;\n\
    \    scc_graph(const ::tools::scc_graph&) = default;\n    scc_graph(::tools::scc_graph&&)\
    \ = default;\n    ~scc_graph() = default;\n    ::tools::scc_graph& operator=(const\
    \ ::tools::scc_graph&) = default;\n    ::tools::scc_graph& operator=(::tools::scc_graph&&)\
    \ = default;\n\n    explicit scc_graph(const ::std::size_t n) : m_graph(n), m_rev_graph(n),\
    \ m_vid2scc(n), m_built(false) {\n    }\n\n    ::std::size_t size() const {\n\
    \      return this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(const\
    \ ::std::size_t from, const ::std::size_t to) {\n      assert(from < this->size());\n\
    \      assert(to < this->size());\n      assert(!this->m_built);\n      const\
    \ auto edge_id = this->m_edges.size();\n      this->m_edges.emplace_back(from,\
    \ to);\n      this->m_graph[from].push_back(edge_id);\n      this->m_rev_graph[to].push_back(edge_id);\n\
    \      return edge_id;\n    }\n\n    ::std::pair<::std::size_t, ::std::size_t>\
    \ edge(const ::std::size_t i) const {\n      assert(i < this->m_edges.size());\n\
    \      return this->m_edges[i];\n    }\n    const ::std::vector<::std::size_t>&\
    \ edges_from(const ::std::size_t i) const {\n      assert(i < this->size());\n\
    \      return this->m_graph[i];\n    }\n    const ::std::vector<::std::size_t>&\
    \ edges_to(const ::std::size_t i) const {\n      assert(i < this->size());\n \
    \     return this->m_rev_graph[i];\n    }\n\n    void build() {\n      assert(!this->m_built);\n\
    \      ::std::stack<::std::size_t> ordered_by_dfs;\n      {\n        ::std::vector<bool>\
    \ visited(this->size(), false);\n        ::std::stack<::std::pair<bool, ::std::size_t>>\
    \ stack;\n        for (::std::size_t i = this->size(); i --> 0;) {\n         \
    \ stack.emplace(true, i);\n        }\n        while (!stack.empty()) {\n     \
    \     const auto [pre, here] = stack.top();\n          stack.pop();\n        \
    \  if (pre) {\n            if (visited[here]) continue;\n            visited[here]\
    \ = true;\n            stack.emplace(false, here);\n            for (const auto\
    \ e : this->m_graph[here]) {\n              const auto next = this->m_edges[e].second;\n\
    \              if (visited[next]) continue;\n              stack.emplace(true,\
    \ next);\n            }\n          } else {\n            ordered_by_dfs.push(here);\n\
    \          }\n        }\n      }\n\n      {\n        ::std::vector<bool> visited(this->size(),\
    \ false);\n        while (!ordered_by_dfs.empty()) {\n          const auto root\
    \ = ordered_by_dfs.top();\n          ordered_by_dfs.pop();\n          if (visited[root])\
    \ continue;\n\n          const auto scc_id = this->m_sccs.size();\n          this->m_sccs.emplace_back();\n\
    \          this->m_edges_in_scc.emplace_back();\n          this->m_scc_graph.emplace_back();\n\
    \          this->m_rev_scc_graph.emplace_back();\n\n          ::std::stack<::std::size_t>\
    \ stack({root});\n          while (!stack.empty()) {\n            const auto here\
    \ = stack.top();\n            stack.pop();\n            if (visited[here]) continue;\n\
    \            visited[here] = true;\n\n            this->m_vid2scc[here] = scc_id;\n\
    \            this->m_sccs[scc_id].push_back(here);\n\n            for (const auto\
    \ e : this->m_rev_graph[here]) {\n              const auto next = this->m_edges[e].first;\n\
    \              if (visited[next]) continue;\n              stack.push(next);\n\
    \            }\n          }\n\n          ::std::vector<::std::size_t> buffer;\
    \ \n          for (const auto v : this->m_sccs[scc_id]) {\n            for (const\
    \ auto e : this->m_rev_graph[v]) {\n              const auto u = this->m_edges[e].first;\n\
    \              if (this->m_vid2scc[u] == this->m_vid2scc[v]) {\n             \
    \   this->m_edges_in_scc[scc_id].push_back(e);\n              } else {\n     \
    \           buffer.push_back(e);\n              }\n            }\n          }\n\
    \n          ::std::sort(buffer.begin(), buffer.end(), tools::less_by([&](const\
    \ auto e) { return this->m_vid2scc[this->m_edges[e].first]; }));\n          for\
    \ (::std::size_t l = 0, r = 0; l < buffer.size(); l = r) {\n            const\
    \ auto u_scc_id = this->m_vid2scc[this->m_edges[buffer[l]].first];\n         \
    \   this->m_rev_scc_graph[scc_id].emplace_back(u_scc_id, ::std::vector<::std::size_t>());\n\
    \            for (; r < buffer.size() && this->m_vid2scc[this->m_edges[buffer[l]].first]\
    \ == this->m_vid2scc[this->m_edges[buffer[r]].first]; ++r);\n            for (::std::size_t\
    \ i = l; i < r; ++i) {\n              this->m_rev_scc_graph[scc_id].back().second.push_back(buffer[i]);\n\
    \            }\n          }\n        }\n\n        for (::std::size_t v_scc_id\
    \ = 0; v_scc_id < this->m_sccs.size(); ++v_scc_id) {\n          for (const auto&\
    \ [u_scc_id, edge_ids] : this->m_rev_scc_graph[v_scc_id]) {\n            this->m_scc_graph[u_scc_id].emplace_back(v_scc_id,\
    \ edge_ids);\n          }\n        }\n      }\n\n      this->m_built = true;\n\
    \    }\n\n    ::std::size_t scc_id(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      assert(this->m_built);\n      return this->m_vid2scc[i];\n\
    \    }\n    const ::std::vector<::std::vector<::std::size_t>>& sccs() const {\n\
    \      assert(this->m_built);\n      return this->m_sccs;\n    }\n    const ::std::vector<::std::size_t>&\
    \ edges_in_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_edges_in_scc[i];\n    }\n\
    \    const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_from_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_scc_graph[i];\n    }\n   \
    \ const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_to_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_rev_scc_graph[i];\n    }\n\
    \  };\n}\n\n#endif\n"
  dependsOn:
  - tools/less_by.hpp
  isVerificationFile: false
  path: tools/scc_graph.hpp
  requiredBy: []
  timestamp: '2022-06-05 16:52:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - tests/scc_graph/scc_id.test.cpp
  - tests/scc_graph/edges_to_scc.test.cpp
  - tests/scc_graph/sccs.test.cpp
documentation_of: tools/scc_graph.hpp
layout: document
title: Strongly connected component decomposition
---

It takes a directed graph with $n$ vertices as input, and decomposes the graph into strongly connected components.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
scc_graph graph(std::size_t n);
```

It creates a directed graph with $n$ vertices and $0$ edges.

### Constraints
- $n \geq 0$

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

It adds a directed edge from $u$ to $v$ to the graph, and returns the index of the added edge.

### Constraints
- `graph.build()` has not been called ever.
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## edge
```cpp
std::pair<std::size_t, std::size_t> graph.edge(std::size_t i);
```

It returns the source and destination of the $i$-th edge of the graph.

### Constraints
- $0 \leq i < m$ where $m$ is the number of edges

### Time Complexity
- $O(1)$

## edges_from
```cpp
const std::vector<std::size_t>& graph.edges_from(std::size_t v);
```

It returns the indices of the edges from the vertex $v$.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## edges_to
```cpp
const std::vector<std::size_t>& graph.edges_to(std::size_t v);
```

It returns the indices of the edges to the vertex $v$.

### Constraints
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## build
```cpp
void graph.build();
```

It decomposes the graph into strongly connected components.

### Constraints
- `graph.build()` has not been called ever.

### Time Complexity
- $O(n + m \log m)$ where $m$ is the number of edges

## scc_id
```cpp
std::size_t graph.scc_id(std::size_t v);
```

It returns the index of the strongly connected components which contains the vertex $v$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq v < n$

### Time Complexity
- $O(1)$

## sccs
```cpp
const std::vector<std::vector<std::size_t>>& graph.sccs();
```

It returns the list of the "list of the vertices" that satisfies the following.

- Each vertex is in exactly one "list of the vertices".
- Each "list of the vertices" corresponds to the vertex set of a strongly connected component. The order of the vertices in the list is undefined.
- The list of "list of the vertices" are sorted in topological order, i.e., for two vertices $u, v$ in different strongly connected components, if there is a directed path from $u$ to $v$, the list contains $u$ appears earlier than the list contains $v$.

### Constraints
- `graph.build()` has been called ever.

### Time Complexity
- $O(1)$

## edges_in_scc
```cpp
const std::vector<std::size_t>& graph.edges_in_scc(std::size_t x);
```

Let $E$ be the edges whose source is a vertex in the $x$-th strongly connected component and destination is a vertex in the $x$-th strongly connected component.
It returns $E$.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq x < $ `graph.sccs().size()`

### Time Complexity
- $O(1)$

## edges_from_scc
```cpp
const std::vector<std::pair<std::size_t, std::vector<std::size_t>>>& graph.edges_from_scc(std::size_t x);
```

Let $E$ be the edges whose source is a vertex in the $x$-th strongly connected component and destination is a vertex not in the $x$-th strongly connected component.
It groups $E$ by the strongly connected component which contains the destination, and returns the list of the groups.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq x < $ `graph.sccs().size()`

### Time Complexity
- $O(1)$

## edges_to_scc
```cpp
const std::vector<std::pair<std::size_t, std::vector<std::size_t>>>& graph.edges_to_scc(std::size_t x);
```

Let $E$ be the edges whose source is a vertex not in the $x$-th strongly connected component and destination is a vertex in the $x$-th strongly connected component.
It groups $E$ by the strongly connected component which contains the source, and returns the list of the groups.

### Constraints
- `graph.build()` has been called ever.
- $0 \leq x < $ `graph.sccs().size()`

### Time Complexity
- $O(1)$
