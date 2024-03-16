---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/pow2.hpp
    title: $2^x$
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tsort/count.test.cpp
    title: tests/tsort/count.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/tsort/query.test.cpp
    title: tests/tsort/query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/tsort.hpp\"\n\n\n\n#include <cstddef>\n#include <vector>\n\
    #include <cassert>\n#include <queue>\n#include <cstdint>\n#line 1 \"tools/pow2.hpp\"\
    \n\n\n\n#include <type_traits>\n#line 6 \"tools/pow2.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(1) << x;\n  }\n\n  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value,\
    \ ::std::nullptr_t>::type = nullptr>\n  constexpr T pow2(const T x) {\n    return\
    \ static_cast<T>(static_cast<typename ::std::make_unsigned<T>::type>(1) << static_cast<typename\
    \ ::std::make_unsigned<T>::type>(x));\n  }\n}\n\n\n#line 10 \"tools/tsort.hpp\"\
    \n\nnamespace tools {\n\n  class tsort {\n  public:\n    struct edge {\n     \
    \ ::std::size_t id;\n      ::std::size_t from;\n      ::std::size_t to;\n    };\n\
    \n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    tsort() = default;\n    tsort(const ::tools::tsort&)\
    \ = default;\n    tsort(::tools::tsort&&) = default;\n    ~tsort() = default;\n\
    \    ::tools::tsort& operator=(const ::tools::tsort&) = default;\n    ::tools::tsort&\
    \ operator=(::tools::tsort&&) = default;\n\n    explicit tsort(const ::std::size_t\
    \ n) : m_graph(n) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t\
    \ v) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   this->m_edges.push_back(edge{this->m_edges.size(), u, v});\n      this->m_graph[u].push_back(this->m_edges.size()\
    \ - 1);\n      return this->m_edges.size() - 1;\n    }\n\n    const edge& get_edge(const\
    \ ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n      return\
    \ this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges() const {\n\
    \      return this->m_edges;\n    }\n\n    ::std::vector<::std::size_t> query()\
    \ const {\n      ::std::vector<::std::size_t> indegs(this->size(), 0);\n     \
    \ for (::std::size_t u = 0; u < this->size(); ++u) {\n        for (const auto\
    \ e : this->m_graph[u]) {\n          ++indegs[this->m_edges[e].to];\n        }\n\
    \      }\n\n      ::std::queue<::std::size_t> queue;\n      for (::std::size_t\
    \ v = 0; v < this->size(); ++v) {\n        if (indegs[v] == 0) {\n          queue.push(v);\n\
    \        }\n      }\n\n      ::std::vector<::std::size_t> result;\n      result.reserve(this->size());\n\
    \      while (!queue.empty()) {\n        const ::std::size_t u = queue.front();\n\
    \        queue.pop();\n        result.push_back(u);\n        for (const auto e\
    \ : this->m_graph[u]) {\n          const auto v = this->m_edges[e].to;\n     \
    \     --indegs[v];\n          if (indegs[v] == 0) {\n            queue.push(v);\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n\n    template\
    \ <typename R = long long>\n    R count() const {\n      using u32 = ::std::uint_fast32_t;\n\
    \n      assert(this->size() < 32);\n\n      ::std::vector<u32> graph(this->size());\n\
    \      for (const auto& edge : this->m_edges) {\n        graph[edge.from] |= u32(1)\
    \ << edge.to;\n      }\n\n      ::std::vector<R> dp(::tools::pow2(this->size()));\n\
    \      dp[0] = R(1);\n      for (u32 state = 1; state < ::tools::pow2(this->size());\
    \ ++state) {\n        dp[state] = R(0);\n        for (::std::size_t v = 0; v <\
    \ this->size(); ++v) {\n          if (const auto prev_state = state & ~(u32(1)\
    \ << v); ((state >> v) & 1) && !(graph[v] & prev_state)) {\n            dp[state]\
    \ += dp[prev_state];\n          }\n        }\n      }\n\n      return dp[::tools::pow2(this->size())\
    \ - 1];\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_TSORT_HPP\n#define TOOLS_TSORT_HPP\n\n#include <cstddef>\n\
    #include <vector>\n#include <cassert>\n#include <queue>\n#include <cstdint>\n\
    #include \"tools/pow2.hpp\"\n\nnamespace tools {\n\n  class tsort {\n  public:\n\
    \    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n     \
    \ ::std::size_t to;\n    };\n\n  private:\n    ::std::vector<edge> m_edges;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n    tsort()\
    \ = default;\n    tsort(const ::tools::tsort&) = default;\n    tsort(::tools::tsort&&)\
    \ = default;\n    ~tsort() = default;\n    ::tools::tsort& operator=(const ::tools::tsort&)\
    \ = default;\n    ::tools::tsort& operator=(::tools::tsort&&) = default;\n\n \
    \   explicit tsort(const ::std::size_t n) : m_graph(n) {\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_graph.size();\n    }\n\n    ::std::size_t\
    \ add_edge(const ::std::size_t u, const ::std::size_t v) {\n      assert(u < this->size());\n\
    \      assert(v < this->size());\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v});\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n     \
    \ return this->m_edges.size() - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t\
    \ k) const {\n      assert(k < this->m_edges.size());\n      return this->m_edges[k];\n\
    \    }\n\n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::vector<::std::size_t> query() const {\n      ::std::vector<::std::size_t>\
    \ indegs(this->size(), 0);\n      for (::std::size_t u = 0; u < this->size();\
    \ ++u) {\n        for (const auto e : this->m_graph[u]) {\n          ++indegs[this->m_edges[e].to];\n\
    \        }\n      }\n\n      ::std::queue<::std::size_t> queue;\n      for (::std::size_t\
    \ v = 0; v < this->size(); ++v) {\n        if (indegs[v] == 0) {\n          queue.push(v);\n\
    \        }\n      }\n\n      ::std::vector<::std::size_t> result;\n      result.reserve(this->size());\n\
    \      while (!queue.empty()) {\n        const ::std::size_t u = queue.front();\n\
    \        queue.pop();\n        result.push_back(u);\n        for (const auto e\
    \ : this->m_graph[u]) {\n          const auto v = this->m_edges[e].to;\n     \
    \     --indegs[v];\n          if (indegs[v] == 0) {\n            queue.push(v);\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n\n    template\
    \ <typename R = long long>\n    R count() const {\n      using u32 = ::std::uint_fast32_t;\n\
    \n      assert(this->size() < 32);\n\n      ::std::vector<u32> graph(this->size());\n\
    \      for (const auto& edge : this->m_edges) {\n        graph[edge.from] |= u32(1)\
    \ << edge.to;\n      }\n\n      ::std::vector<R> dp(::tools::pow2(this->size()));\n\
    \      dp[0] = R(1);\n      for (u32 state = 1; state < ::tools::pow2(this->size());\
    \ ++state) {\n        dp[state] = R(0);\n        for (::std::size_t v = 0; v <\
    \ this->size(); ++v) {\n          if (const auto prev_state = state & ~(u32(1)\
    \ << v); ((state >> v) & 1) && !(graph[v] & prev_state)) {\n            dp[state]\
    \ += dp[prev_state];\n          }\n        }\n      }\n\n      return dp[::tools::pow2(this->size())\
    \ - 1];\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/pow2.hpp
  isVerificationFile: false
  path: tools/tsort.hpp
  requiredBy: []
  timestamp: '2023-02-11 13:12:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tsort/count.test.cpp
  - tests/tsort/query.test.cpp
documentation_of: tools/tsort.hpp
layout: document
title: Topological sorting
---

It is a class about topological sorting.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tsort graph(std::size_t n);
```

It creates a directed graph with $n$ vertices and $0$ edges.

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

It adds a directed edge oriented from $u$ to $v$.
It returns an integer $k$ such that this is the $k$-th edge that is added.

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
edge graph.get_edge(std::size_t k);
```

It returns the $k$-th edge.

### Constraints
- $0 \leq k < \|E\|$ where $\|E\|$ is the number of edges

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
std::vector<std::size_t> graph.query();
```

Topological sorting is a linear ordering of vertices such that for every directed edge from $u$ to $v$, vertex $u$ comes before $v$ in the ordering.
It returns one of the topological sortings for the graph.

### Constraints
- The graph is a DAG.

### Time Complexity
- $O(n)$

## count
```cpp
template <typename R = long long>
R graph.count();
```

It returns the number of the topological sortings for the graph.

### Constraints
- $n < 32$

### Time Complexity
- $O(2^n n)$
