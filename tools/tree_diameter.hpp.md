---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
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
  bundledCode: "#line 1 \"tools/tree_diameter.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <cassert>\n#include <numeric>\n#include <limits>\n#include\
    \ <queue>\n#include <iterator>\n#include <algorithm>\n#line 1 \"tools/chmin.hpp\"\
    \n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool updated\
    \ = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 13 \"tools/tree_diameter.hpp\"\n\nnamespace tools {\n  template <typename\
    \ T>\n  class tree_diameter {\n  private:\n    class edge {\n    public:\n   \
    \   ::std::size_t from;\n      ::std::size_t to;\n      T distance;\n      edge(const\
    \ ::std::size_t from, const ::std::size_t to, const T& distance) :\n        from(from),\n\
    \        to(to),\n        distance(distance) {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>>\
    \ edges;\n\n  public:\n    tree_diameter(const ::std::size_t node_count) :\n \
    \     edges(node_count) {\n    }\n\n    ::std::size_t node_count() const {\n \
    \     return this->edges.size();\n    }\n\n    void add_edge(const ::std::size_t\
    \ from, const ::std::size_t to, const T& distance) {\n      this->edges[from].emplace_back(from,\
    \ to, distance);\n      this->edges[to].emplace_back(to, from, distance);\n  \
    \  }\n\n    T query() const {\n      assert(::std::accumulate(this->edges.begin(),\
    \ this->edges.end(), ::std::size_t(0), [](const ::std::size_t sum, const ::std::vector<edge>&\
    \ e) { return sum + e.size(); }) + 2 == this->node_count() * 2);\n\n      ::std::vector<T>\
    \ distances(this->node_count(), ::std::numeric_limits<T>::max());\n      distances[0]\
    \ = 0;\n      ::std::queue<::std::size_t> queue({0});\n      while (!queue.empty())\
    \ {\n        const ::std::size_t from = queue.front();\n        queue.pop();\n\
    \        for (const edge& edge : edges[from]) {\n          if (::tools::chmin(distances[edge.to],\
    \ distances[from] + edge.distance)) {\n            queue.push(edge.to);\n    \
    \      }\n        }\n      }\n\n      queue.push(::std::distance(distances.begin(),\
    \ ::std::max_element(distances.begin(), distances.end())));\n      ::std::fill(distances.begin(),\
    \ distances.end(), ::std::numeric_limits<T>::max());\n      distances[queue.front()]\
    \ = 0;\n      while (!queue.empty()) {\n        const ::std::size_t from = queue.front();\n\
    \        queue.pop();\n        for (const edge& edge : edges[from]) {\n      \
    \    if (::tools::chmin(distances[edge.to], distances[from] + edge.distance))\
    \ {\n            queue.push(edge.to);\n          }\n        }\n      }\n\n   \
    \   return *std::max_element(distances.begin(), distances.end());\n    }\n  };\n\
    }\n\n\n"
  code: "#ifndef TOOLS_TREE_DIAMETER_HPP\n#define TOOLS_TREE_DIAMETER_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <cassert>\n#include <numeric>\n#include\
    \ <limits>\n#include <queue>\n#include <iterator>\n#include <algorithm>\n#include\
    \ \"tools/chmin.hpp\"\n\nnamespace tools {\n  template <typename T>\n  class tree_diameter\
    \ {\n  private:\n    class edge {\n    public:\n      ::std::size_t from;\n  \
    \    ::std::size_t to;\n      T distance;\n      edge(const ::std::size_t from,\
    \ const ::std::size_t to, const T& distance) :\n        from(from),\n        to(to),\n\
    \        distance(distance) {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>>\
    \ edges;\n\n  public:\n    tree_diameter(const ::std::size_t node_count) :\n \
    \     edges(node_count) {\n    }\n\n    ::std::size_t node_count() const {\n \
    \     return this->edges.size();\n    }\n\n    void add_edge(const ::std::size_t\
    \ from, const ::std::size_t to, const T& distance) {\n      this->edges[from].emplace_back(from,\
    \ to, distance);\n      this->edges[to].emplace_back(to, from, distance);\n  \
    \  }\n\n    T query() const {\n      assert(::std::accumulate(this->edges.begin(),\
    \ this->edges.end(), ::std::size_t(0), [](const ::std::size_t sum, const ::std::vector<edge>&\
    \ e) { return sum + e.size(); }) + 2 == this->node_count() * 2);\n\n      ::std::vector<T>\
    \ distances(this->node_count(), ::std::numeric_limits<T>::max());\n      distances[0]\
    \ = 0;\n      ::std::queue<::std::size_t> queue({0});\n      while (!queue.empty())\
    \ {\n        const ::std::size_t from = queue.front();\n        queue.pop();\n\
    \        for (const edge& edge : edges[from]) {\n          if (::tools::chmin(distances[edge.to],\
    \ distances[from] + edge.distance)) {\n            queue.push(edge.to);\n    \
    \      }\n        }\n      }\n\n      queue.push(::std::distance(distances.begin(),\
    \ ::std::max_element(distances.begin(), distances.end())));\n      ::std::fill(distances.begin(),\
    \ distances.end(), ::std::numeric_limits<T>::max());\n      distances[queue.front()]\
    \ = 0;\n      while (!queue.empty()) {\n        const ::std::size_t from = queue.front();\n\
    \        queue.pop();\n        for (const edge& edge : edges[from]) {\n      \
    \    if (::tools::chmin(distances[edge.to], distances[from] + edge.distance))\
    \ {\n            queue.push(edge.to);\n          }\n        }\n      }\n\n   \
    \   return *std::max_element(distances.begin(), distances.end());\n    }\n  };\n\
    }\n\n#endif\n"
  dependsOn:
  - tools/chmin.hpp
  isVerificationFile: false
  path: tools/tree_diameter.hpp
  requiredBy: []
  timestamp: '2021-05-16 03:32:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/tree_diameter.test.cpp
documentation_of: tools/tree_diameter.hpp
layout: document
title: Diameter of tree
---

It returns the diameter of the given tree.

## Usage
```cpp
tools::tree_diameter<int> tree(node_count);
tree.add_edge(from_node, to_node, cost);
tree.query();
```

The type parameter `<T>` is the type of weight of edges.

## License
- CC0

## Author
- anqooqie
