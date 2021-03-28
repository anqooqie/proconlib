---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/dijkstra.test.cpp
    title: tests/dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/dijkstra.hpp\"\n\n\n\n#include <cstddef>\n#include\
    \ <vector>\n#include <limits>\n#include <cassert>\n#include <functional>\n#include\
    \ <queue>\n\nnamespace tools {\n\n  /**\n   * Dijkstra's algorithm\n   * License:\
    \ CC0\n   *\n   * Usage:\n   * ```\n   * tools::dijkstra<int> dijkstra(node_count);\n\
    \   * dijkstra.add_edge(from_node, to_node, cost);\n   * const tools::dijkstra<int>::result\
    \ result = dijkstra.query(start_node);\n   * for (const int& distance : result.distances)\
    \ {\n   *   // ...\n   * }\n   * ```\n   *\n   * @author anqooqie\n   * @param\
    \ <T> type of weight of edges\n   */\n  template <typename T>\n  class dijkstra\
    \ {\n  private:\n    class edge {\n    public:\n      ::std::size_t from;\n  \
    \    ::std::size_t to;\n      T distance;\n      edge(const ::std::size_t from,\
    \ const ::std::size_t to, const T distance) :\n        from(from),\n        to(to),\n\
    \        distance(distance) {\n      }\n    };\n\n    class task {\n    public:\n\
    \      ::std::size_t vertex;\n      T distance;\n      task(const ::std::size_t\
    \ vertex, const ::std::size_t distance) :\n        vertex(vertex), distance(distance)\
    \ {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n\
    \    static constexpr T INF = ::std::numeric_limits<T>::max();\n    static constexpr\
    \ ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class\
    \ result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count, const ::std::size_t&\
    \ start_node) :\n        distances(node_count, INF),\n        prev_nodes(node_count,\
    \ NONE) {\n        this->distances[start_node] = 0;\n      }\n    };\n\n    dijkstra(const\
    \ ::std::size_t& node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t\
    \ node_count() const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) {\n      this->edges[from].emplace_back(from,\
    \ to, distance);\n    }\n\n    result query(const ::std::size_t& start_node) const\
    \ {\n      assert(start_node < this->node_count());\n\n      result result(this->node_count(),\
    \ start_node);\n      ::std::vector<bool> visited(this->node_count(), false);\n\
    \      const auto compare = [](const task& x, const task& y) {\n        return\
    \ x.distance > y.distance;\n      };\n      ::std::priority_queue<task, ::std::vector<task>,\
    \ decltype(compare)> tasks(compare);\n      tasks.emplace(start_node, 0);\n\n\
    \      while (!tasks.empty()) {\n        const task task = tasks.top();\n    \
    \    tasks.pop();\n        if (visited[task.vertex]) continue;\n        visited[task.vertex]\
    \ = true;\n        for (const edge& edge : this->edges[task.vertex]) {\n     \
    \     const T new_distance = task.distance + edge.distance;\n          if (new_distance\
    \ < result.distances[edge.to]) {\n            result.distances[edge.to] = new_distance;\n\
    \            result.prev_nodes[edge.to] = edge.from;\n            tasks.emplace(edge.to,\
    \ new_distance);\n          }\n        }\n      }\n\n      return result;\n  \
    \  }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_DIJKSTRA_HPP\n#define TOOLS_DIJKSTRA_HPP\n\n#include <cstddef>\n\
    #include <vector>\n#include <limits>\n#include <cassert>\n#include <functional>\n\
    #include <queue>\n\nnamespace tools {\n\n  /**\n   * Dijkstra's algorithm\n  \
    \ * License: CC0\n   *\n   * Usage:\n   * ```\n   * tools::dijkstra<int> dijkstra(node_count);\n\
    \   * dijkstra.add_edge(from_node, to_node, cost);\n   * const tools::dijkstra<int>::result\
    \ result = dijkstra.query(start_node);\n   * for (const int& distance : result.distances)\
    \ {\n   *   // ...\n   * }\n   * ```\n   *\n   * @author anqooqie\n   * @param\
    \ <T> type of weight of edges\n   */\n  template <typename T>\n  class dijkstra\
    \ {\n  private:\n    class edge {\n    public:\n      ::std::size_t from;\n  \
    \    ::std::size_t to;\n      T distance;\n      edge(const ::std::size_t from,\
    \ const ::std::size_t to, const T distance) :\n        from(from),\n        to(to),\n\
    \        distance(distance) {\n      }\n    };\n\n    class task {\n    public:\n\
    \      ::std::size_t vertex;\n      T distance;\n      task(const ::std::size_t\
    \ vertex, const ::std::size_t distance) :\n        vertex(vertex), distance(distance)\
    \ {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n\
    \    static constexpr T INF = ::std::numeric_limits<T>::max();\n    static constexpr\
    \ ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class\
    \ result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count, const ::std::size_t&\
    \ start_node) :\n        distances(node_count, INF),\n        prev_nodes(node_count,\
    \ NONE) {\n        this->distances[start_node] = 0;\n      }\n    };\n\n    dijkstra(const\
    \ ::std::size_t& node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t\
    \ node_count() const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) {\n      this->edges[from].emplace_back(from,\
    \ to, distance);\n    }\n\n    result query(const ::std::size_t& start_node) const\
    \ {\n      assert(start_node < this->node_count());\n\n      result result(this->node_count(),\
    \ start_node);\n      ::std::vector<bool> visited(this->node_count(), false);\n\
    \      const auto compare = [](const task& x, const task& y) {\n        return\
    \ x.distance > y.distance;\n      };\n      ::std::priority_queue<task, ::std::vector<task>,\
    \ decltype(compare)> tasks(compare);\n      tasks.emplace(start_node, 0);\n\n\
    \      while (!tasks.empty()) {\n        const task task = tasks.top();\n    \
    \    tasks.pop();\n        if (visited[task.vertex]) continue;\n        visited[task.vertex]\
    \ = true;\n        for (const edge& edge : this->edges[task.vertex]) {\n     \
    \     const T new_distance = task.distance + edge.distance;\n          if (new_distance\
    \ < result.distances[edge.to]) {\n            result.distances[edge.to] = new_distance;\n\
    \            result.prev_nodes[edge.to] = edge.from;\n            tasks.emplace(edge.to,\
    \ new_distance);\n          }\n        }\n      }\n\n      return result;\n  \
    \  }\n  };\n}\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/dijkstra.hpp
  requiredBy: []
  timestamp: '2021-02-14 17:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/dijkstra.test.cpp
documentation_of: tools/dijkstra.hpp
layout: document
redirect_from:
- /library/tools/dijkstra.hpp
- /library/tools/dijkstra.hpp.html
title: tools/dijkstra.hpp
---
