---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/safe_sum.hpp
    title: $A + B$ but not causing overflow
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
    \ <vector>\n#include <limits>\n#include <cassert>\n#line 1 \"tools/safe_sum.hpp\"\
    \n\n\n\n#line 5 \"tools/safe_sum.hpp\"\n#include <stdexcept>\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  T safe_sum(const T& lhs, const T& rhs) {\n \
    \   if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::max())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ && rhs == ::std::numeric_limits<T>::min()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::min())\
    \ return ::std::numeric_limits<T>::min();\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::max()) return ::std::numeric_limits<T>::max();\n\
    \    return lhs + rhs;\n  }\n}\n\n\n#line 9 \"tools/bellman_ford.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename T>\n  class bellman_ford {\n  private:\n   \
    \ class edge {\n    public:\n      ::std::size_t from;\n      ::std::size_t to;\n\
    \      T distance;\n      edge(const ::std::size_t& from, const ::std::size_t&\
    \ to, const T& distance) :\n        from(from),\n        to(to),\n        distance(distance)\
    \ {\n      }\n    };\n\n    ::std::size_t m_node_count;\n    ::std::vector<edge>\
    \ m_edges;\n\n  public:\n    constexpr inline static T POS_INF = ::std::numeric_limits<T>::max();\n\
    \    constexpr inline static T NEG_INF = ::std::numeric_limits<T>::min();\n  \
    \  constexpr inline static ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\
    \n    class result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count) :\n        distances(node_count,\
    \ POS_INF),\n        prev_nodes(node_count, NONE) {\n      }\n    };\n\n    bellman_ford(const\
    \ ::std::size_t& node_count) :\n      m_node_count(node_count),\n      m_edges()\
    \ {\n    }\n\n    ::std::size_t node_count() const {\n      return this->m_node_count;\n\
    \    }\n\n    void add_edge(const ::std::size_t& from, const ::std::size_t& to,\
    \ const T& distance) {\n      this->m_edges.emplace_back(from, to, distance);\n\
    \    }\n\n    result query(const ::std::size_t& start_node) const {\n      assert(start_node\
    \ < this->m_node_count);\n      result result(this->m_node_count);\n      result.distances[start_node]\
    \ = 0;\n      for (::std::size_t i = 0; i < this->m_node_count - 1; ++i) {\n \
    \       for (const edge& edge : this->m_edges) {\n          if (::tools::safe_sum(result.distances[edge.from],\
    \ edge.distance) < result.distances[edge.to]) {\n            result.distances[edge.to]\
    \ = ::tools::safe_sum(result.distances[edge.from], edge.distance);\n         \
    \   result.prev_nodes[edge.to] = edge.from;\n          }\n        }\n      }\n\
    \      for (const edge& edge : this->m_edges) {\n        if (::tools::safe_sum(result.distances[edge.from],\
    \ edge.distance) < result.distances[edge.to]) {\n          result.distances[edge.to]\
    \ = NEG_INF;\n          result.prev_nodes[edge.to] = edge.from;\n        }\n \
    \     }\n      for (::std::size_t i = 0; i < this->m_node_count; ++i) {\n    \
    \    for (const edge& edge : this->m_edges) {\n          if (::tools::safe_sum(result.distances[edge.from],\
    \ edge.distance) < result.distances[edge.to]) {\n            result.distances[edge.to]\
    \ = ::tools::safe_sum(result.distances[edge.from], edge.distance);\n         \
    \   result.prev_nodes[edge.to] = edge.from;\n          }\n        }\n      }\n\
    \      return result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_BELLMAN_FORD_HPP\n#define TOOLS_BELLMAN_FORD_HPP\n\n#include\
    \ <cstddef>\n#include <vector>\n#include <limits>\n#include <cassert>\n#include\
    \ \"tools/safe_sum.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  class\
    \ bellman_ford {\n  private:\n    class edge {\n    public:\n      ::std::size_t\
    \ from;\n      ::std::size_t to;\n      T distance;\n      edge(const ::std::size_t&\
    \ from, const ::std::size_t& to, const T& distance) :\n        from(from),\n \
    \       to(to),\n        distance(distance) {\n      }\n    };\n\n    ::std::size_t\
    \ m_node_count;\n    ::std::vector<edge> m_edges;\n\n  public:\n    constexpr\
    \ inline static T POS_INF = ::std::numeric_limits<T>::max();\n    constexpr inline\
    \ static T NEG_INF = ::std::numeric_limits<T>::min();\n    constexpr inline static\
    \ ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class\
    \ result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count) :\n        distances(node_count,\
    \ POS_INF),\n        prev_nodes(node_count, NONE) {\n      }\n    };\n\n    bellman_ford(const\
    \ ::std::size_t& node_count) :\n      m_node_count(node_count),\n      m_edges()\
    \ {\n    }\n\n    ::std::size_t node_count() const {\n      return this->m_node_count;\n\
    \    }\n\n    void add_edge(const ::std::size_t& from, const ::std::size_t& to,\
    \ const T& distance) {\n      this->m_edges.emplace_back(from, to, distance);\n\
    \    }\n\n    result query(const ::std::size_t& start_node) const {\n      assert(start_node\
    \ < this->m_node_count);\n      result result(this->m_node_count);\n      result.distances[start_node]\
    \ = 0;\n      for (::std::size_t i = 0; i < this->m_node_count - 1; ++i) {\n \
    \       for (const edge& edge : this->m_edges) {\n          if (::tools::safe_sum(result.distances[edge.from],\
    \ edge.distance) < result.distances[edge.to]) {\n            result.distances[edge.to]\
    \ = ::tools::safe_sum(result.distances[edge.from], edge.distance);\n         \
    \   result.prev_nodes[edge.to] = edge.from;\n          }\n        }\n      }\n\
    \      for (const edge& edge : this->m_edges) {\n        if (::tools::safe_sum(result.distances[edge.from],\
    \ edge.distance) < result.distances[edge.to]) {\n          result.distances[edge.to]\
    \ = NEG_INF;\n          result.prev_nodes[edge.to] = edge.from;\n        }\n \
    \     }\n      for (::std::size_t i = 0; i < this->m_node_count; ++i) {\n    \
    \    for (const edge& edge : this->m_edges) {\n          if (::tools::safe_sum(result.distances[edge.from],\
    \ edge.distance) < result.distances[edge.to]) {\n            result.distances[edge.to]\
    \ = ::tools::safe_sum(result.distances[edge.from], edge.distance);\n         \
    \   result.prev_nodes[edge.to] = edge.from;\n          }\n        }\n      }\n\
    \      return result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/safe_sum.hpp
  isVerificationFile: false
  path: tools/bellman_ford.hpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bellman_ford.test.cpp
documentation_of: tools/bellman_ford.hpp
layout: document
title: Bellman-Ford algorithm
---

It is Bellman-Ford algorithm.

## Usage
```cpp
tools::bellman_ford<int> bf(node_count);
bf.add_edge(from_node, to_node, cost);
const tools::bellman_ford<int>::result result = bf.query(start_node);
for (const int& distance : result.distances) {
  // ...
}
```

The type parameter `<T>` is the type of weight of edges.

## License
- CC0

## Author
- anqooqie
