---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/tree_diameter.test.cpp
    title: tests/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/tree_diameter.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cstddef>\n#include <utility>\n#include <cassert>\n#include <tuple>\n#include\
    \ <limits>\n#include <queue>\n#include <iterator>\n#include <algorithm>\n#line\
    \ 1 \"tools/chmin.hpp\"\n\n\n\n#include <type_traits>\n#line 1 \"tools/cmp_less.hpp\"\
    \n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T, typename U>\n  constexpr bool cmp_less(const T t, const U u) noexcept {\n\
    \    using UT = ::std::make_unsigned_t<T>;\n    using UU = ::std::make_unsigned_t<U>;\n\
    \    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>) {\n      return\
    \ t < u;\n    } else if constexpr (::std::is_signed_v<T>) {\n      return t <\
    \ 0 ? true : UT(t) < u;\n    } else {\n      return u < 0 ? false : t < UU(u);\n\
    \    }\n  }\n}\n\n\n#line 6 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    bool updated;\n\
    \    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>) {\n   \
    \   updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated = rhs\
    \ < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 14 \"tools/tree_diameter.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class tree_diameter {\n  private:\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    ::std::vector<::std::pair<::std::size_t, T>> m_edges;\n\n  public:\n\
    \    tree_diameter() = default;\n    tree_diameter(const ::tools::tree_diameter<T>&)\
    \ = default;\n    tree_diameter(::tools::tree_diameter<T>&&) = default;\n    ~tree_diameter()\
    \ = default;\n    ::tools::tree_diameter<T>& operator=(const ::tools::tree_diameter<T>&)\
    \ = default;\n    ::tools::tree_diameter<T>& operator=(::tools::tree_diameter<T>&&)\
    \ = default;\n\n    explicit tree_diameter(const ::std::size_t n) :\n      m_graph(n)\
    \ {\n      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(const ::std::size_t\
    \ u, const ::std::size_t v, const T& w) {\n      assert(u < this->size());\n \
    \     assert(v < this->size());\n\n      this->m_graph[u].push_back(this->m_edges.size());\n\
    \      this->m_graph[v].push_back(this->m_edges.size());\n      this->m_edges.emplace_back(u\
    \ ^ v, w);\n      return this->m_edges.size() - 1;\n    }\n\n    ::std::tuple<T,\
    \ ::std::vector<::std::size_t>, ::std::vector<::std::size_t>> query() const {\n\
    \      assert(this->m_edges.size() + 1 == this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[0] = 0;\n \
    \     ::std::queue<::std::size_t> queue({0});\n      while (!queue.empty()) {\n\
    \        const auto here = queue.front();\n        queue.pop();\n        for (const\
    \ auto eid : this->m_graph[here]) {\n          const auto next = this->m_edges[eid].first\
    \ ^ here;\n          const auto w = this->m_edges[eid].second;\n          if (::tools::chmin(dist[next],\
    \ dist[here] + w)) {\n            queue.push(next);\n          }\n        }\n\
    \      }\n\n      queue.push(::std::distance(dist.begin(), ::std::max_element(dist.begin(),\
    \ dist.end())));\n      ::std::fill(dist.begin(), dist.end(), ::std::numeric_limits<T>::max());\n\
    \      dist[queue.front()] = 0;\n      ::std::vector<::std::size_t> prev(this->size(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      while (!queue.empty())\
    \ {\n        const auto here = queue.front();\n        queue.pop();\n        for\
    \ (const auto eid : this->m_graph[here]) {\n          const auto next = this->m_edges[eid].first\
    \ ^ here;\n          const auto w = this->m_edges[eid].second;\n          if (::tools::chmin(dist[next],\
    \ dist[here] + w)) {\n            prev[next] = eid;\n            queue.push(next);\n\
    \          }\n        }\n      }\n\n      ::std::tuple<T, ::std::vector<::std::size_t>,\
    \ ::std::vector<::std::size_t>> result;\n      ::std::get<0>(result) = 0;\n  \
    \    ::std::size_t v;\n      for (v = ::std::distance(dist.begin(), ::std::max_element(dist.begin(),\
    \ dist.end())); prev[v] != ::std::numeric_limits<::std::size_t>::max(); v = this->m_edges[prev[v]].first\
    \ ^ v) {\n        ::std::get<0>(result) += this->m_edges[prev[v]].second;\n  \
    \      ::std::get<1>(result).push_back(v);\n        ::std::get<2>(result).push_back(prev[v]);\n\
    \      }\n      ::std::get<1>(result).push_back(v);\n      return result;\n  \
    \  }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_TREE_DIAMETER_HPP\n#define TOOLS_TREE_DIAMETER_HPP\n\n#include\
    \ <vector>\n#include <cstddef>\n#include <utility>\n#include <cassert>\n#include\
    \ <tuple>\n#include <limits>\n#include <queue>\n#include <iterator>\n#include\
    \ <algorithm>\n#include \"tools/chmin.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class tree_diameter {\n  private:\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    ::std::vector<::std::pair<::std::size_t, T>> m_edges;\n\n  public:\n\
    \    tree_diameter() = default;\n    tree_diameter(const ::tools::tree_diameter<T>&)\
    \ = default;\n    tree_diameter(::tools::tree_diameter<T>&&) = default;\n    ~tree_diameter()\
    \ = default;\n    ::tools::tree_diameter<T>& operator=(const ::tools::tree_diameter<T>&)\
    \ = default;\n    ::tools::tree_diameter<T>& operator=(::tools::tree_diameter<T>&&)\
    \ = default;\n\n    explicit tree_diameter(const ::std::size_t n) :\n      m_graph(n)\
    \ {\n      assert(n >= 1);\n    }\n\n    ::std::size_t size() const {\n      return\
    \ this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(const ::std::size_t\
    \ u, const ::std::size_t v, const T& w) {\n      assert(u < this->size());\n \
    \     assert(v < this->size());\n\n      this->m_graph[u].push_back(this->m_edges.size());\n\
    \      this->m_graph[v].push_back(this->m_edges.size());\n      this->m_edges.emplace_back(u\
    \ ^ v, w);\n      return this->m_edges.size() - 1;\n    }\n\n    ::std::tuple<T,\
    \ ::std::vector<::std::size_t>, ::std::vector<::std::size_t>> query() const {\n\
    \      assert(this->m_edges.size() + 1 == this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[0] = 0;\n \
    \     ::std::queue<::std::size_t> queue({0});\n      while (!queue.empty()) {\n\
    \        const auto here = queue.front();\n        queue.pop();\n        for (const\
    \ auto eid : this->m_graph[here]) {\n          const auto next = this->m_edges[eid].first\
    \ ^ here;\n          const auto w = this->m_edges[eid].second;\n          if (::tools::chmin(dist[next],\
    \ dist[here] + w)) {\n            queue.push(next);\n          }\n        }\n\
    \      }\n\n      queue.push(::std::distance(dist.begin(), ::std::max_element(dist.begin(),\
    \ dist.end())));\n      ::std::fill(dist.begin(), dist.end(), ::std::numeric_limits<T>::max());\n\
    \      dist[queue.front()] = 0;\n      ::std::vector<::std::size_t> prev(this->size(),\
    \ ::std::numeric_limits<::std::size_t>::max());\n      while (!queue.empty())\
    \ {\n        const auto here = queue.front();\n        queue.pop();\n        for\
    \ (const auto eid : this->m_graph[here]) {\n          const auto next = this->m_edges[eid].first\
    \ ^ here;\n          const auto w = this->m_edges[eid].second;\n          if (::tools::chmin(dist[next],\
    \ dist[here] + w)) {\n            prev[next] = eid;\n            queue.push(next);\n\
    \          }\n        }\n      }\n\n      ::std::tuple<T, ::std::vector<::std::size_t>,\
    \ ::std::vector<::std::size_t>> result;\n      ::std::get<0>(result) = 0;\n  \
    \    ::std::size_t v;\n      for (v = ::std::distance(dist.begin(), ::std::max_element(dist.begin(),\
    \ dist.end())); prev[v] != ::std::numeric_limits<::std::size_t>::max(); v = this->m_edges[prev[v]].first\
    \ ^ v) {\n        ::std::get<0>(result) += this->m_edges[prev[v]].second;\n  \
    \      ::std::get<1>(result).push_back(v);\n        ::std::get<2>(result).push_back(prev[v]);\n\
    \      }\n      ::std::get<1>(result).push_back(v);\n      return result;\n  \
    \  }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  isVerificationFile: false
  path: tools/tree_diameter.hpp
  requiredBy: []
  timestamp: '2024-03-24 19:16:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree_diameter.test.cpp
documentation_of: tools/tree_diameter.hpp
layout: document
title: Diameter of a tree
---

It returns the diameter of the given tree.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
tree_diameter<T> tree(std::size_t n);
```

It creates a graph with $n$ vertices and $0$ edges.
The type parameter `<T>` is the type of the weight of edges.

### Constraints
- $n \geq 1$

### Time Complexity
- $O(n)$

## size
```cpp
std::size_t tree.size();
```

It returns $n$.

### Constraints
- None

### Time Complexity
- $O(1)$

## add_edge
```cpp
std::size_t tree.add_edge(std::size_t u, std::size_t v, T w);
```

It adds an undirected edge connecting $u$ and $v$ with weight $w$ to the graph, and returns the index of the added edge.

### Constraints
- $0 \leq u < n$
- $0 \leq v < n$

### Time Complexity
- $O(1)$ amortized

## query
```cpp
std::tuple<T, std::vector<std::size_t>, std::vector<std::size_t>> tree.query();
```

It returns the distance of the path from $u$ to $v$ where $(u, v)$ is one of the farthest pairs in the tree.
Also, it returns the indices of the vertices which are contained in the path, and the indices of the edges which are contained in the path.

### Constraints
- The graph is a tree.

### Time Complexity
- $O(n)$
