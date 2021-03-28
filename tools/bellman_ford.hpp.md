---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/safe_sum.hpp
    title: tools/safe_sum.hpp
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
    \ {\n\n  /**\n   * computes $A + B$ but handles `std::numeric_limits<T>::max()`\
    \ as $\\infty$ and `std::numeric_limits<T>::min()` as $-\\infty$\n   * License:\
    \ CC0\n   * @author anqooqie\n   * @param <T> an underlying set of the sum operation\n\
    \   * @param lhs left hand side operand\n   * @param rhs right hand side operand\n\
    \   * @return $\\mathrm{lhs} + \\mathrm{rhs}$ when we regard `std::numeric_limits<T>::max()`\
    \ as $\\infty$ and `std::numeric_limits<T>::min()` as $-\\infty$\n   * @throws\
    \ std::runtime_error if $\\mathrm{lhs} + \\mathrm{rhs}$ is indefinite.\n   */\n\
    \  template <typename T>\n  T safe_sum(const T& lhs, const T& rhs) {\n    if (lhs\
    \ == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::max())\
    \ throw std::runtime_error(\"Indefinite.\");\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ && rhs == ::std::numeric_limits<T>::min()) throw std::runtime_error(\"Indefinite.\"\
    );\n    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::min())\
    \ return ::std::numeric_limits<T>::min();\n    if (lhs == ::std::numeric_limits<T>::max()\
    \ || rhs == ::std::numeric_limits<T>::max()) return ::std::numeric_limits<T>::max();\n\
    \    return lhs + rhs;\n  }\n}\n\n\n#line 9 \"tools/bellman_ford.hpp\"\n\nnamespace\
    \ tools {\n\n  /**\n   * Bellman-Ford algorithm\n   * License: CC0\n   *\n   *\
    \ Usage:\n   * ```\n   * tools::bellman_ford<int> bf(node_count);\n   * bf.add_edge(from_node,\
    \ to_node, cost);\n   * const tools::bellman_ford<int>::result result = bf.query(start_node);\n\
    \   * for (const int& distance : result.distances) {\n   *   // ...\n   * }\n\
    \   * ```\n   *\n   * @author anqooqie\n   * @param <T> type of weight of edges\n\
    \   */\n  template <typename T>\n  class bellman_ford {\n  private:\n    class\
    \ edge {\n    public:\n      ::std::size_t from;\n      ::std::size_t to;\n  \
    \    T distance;\n      edge(const ::std::size_t& from, const ::std::size_t& to,\
    \ const T& distance) :\n        from(from),\n        to(to),\n        distance(distance)\
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
    \ \"tools/safe_sum.hpp\"\n\nnamespace tools {\n\n  /**\n   * Bellman-Ford algorithm\n\
    \   * License: CC0\n   *\n   * Usage:\n   * ```\n   * tools::bellman_ford<int>\
    \ bf(node_count);\n   * bf.add_edge(from_node, to_node, cost);\n   * const tools::bellman_ford<int>::result\
    \ result = bf.query(start_node);\n   * for (const int& distance : result.distances)\
    \ {\n   *   // ...\n   * }\n   * ```\n   *\n   * @author anqooqie\n   * @param\
    \ <T> type of weight of edges\n   */\n  template <typename T>\n  class bellman_ford\
    \ {\n  private:\n    class edge {\n    public:\n      ::std::size_t from;\n  \
    \    ::std::size_t to;\n      T distance;\n      edge(const ::std::size_t& from,\
    \ const ::std::size_t& to, const T& distance) :\n        from(from),\n       \
    \ to(to),\n        distance(distance) {\n      }\n    };\n\n    ::std::size_t\
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
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/bellman_ford.test.cpp
documentation_of: tools/bellman_ford.hpp
layout: document
redirect_from:
- /library/tools/bellman_ford.hpp
- /library/tools/bellman_ford.hpp.html
title: tools/bellman_ford.hpp
---
