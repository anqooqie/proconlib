---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/dijkstra.hpp
    title: Dijkstra's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"tests/dijkstra.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <vector>\n#include <cstddef>\n\
    #include <iterator>\n#line 1 \"tools/dijkstra.hpp\"\n\n\n\n#line 6 \"tools/dijkstra.hpp\"\
    \n#include <limits>\n#include <cassert>\n#include <functional>\n#include <queue>\n\
    \nnamespace tools {\n\n  template <typename T>\n  class dijkstra {\n  private:\n\
    \    class edge {\n    public:\n      ::std::size_t from;\n      ::std::size_t\
    \ to;\n      T distance;\n      edge(const ::std::size_t from, const ::std::size_t\
    \ to, const T distance) :\n        from(from),\n        to(to),\n        distance(distance)\
    \ {\n      }\n    };\n\n    class task {\n    public:\n      ::std::size_t vertex;\n\
    \      T distance;\n      task(const ::std::size_t vertex, const ::std::size_t\
    \ distance) :\n        vertex(vertex), distance(distance) {\n      }\n    };\n\
    \n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n    static constexpr\
    \ T INF = ::std::numeric_limits<T>::max();\n    static constexpr ::std::size_t\
    \ NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class result {\n\
    \    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
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
    \  }\n  };\n}\n\n\n#line 9 \"tests/dijkstra.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  i64 N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n\n  tools::dijkstra<i64>\
    \ dijkstra(N);\n  for (i64 i = 0; i < M; ++i) {\n    i64 a, b, c;\n    std::cin\
    \ >> a >> b >> c;\n    dijkstra.add_edge(a, b, c);\n  }\n\n  const auto result\
    \ = dijkstra.query(s);\n  std::vector<i64> path;\n  for (std::size_t i = t; i\
    \ != tools::dijkstra<i64>::NONE; i = result.prev_nodes[i]) {\n    path.push_back(i);\n\
    \  }\n\n  if (result.distances[t] == tools::dijkstra<i64>::INF) {\n    std::cout\
    \ << -1 << '\\n';\n  } else {\n    std::cout << result.distances[t] << ' ' <<\
    \ path.size() - 1 << '\\n';\n    for (auto it = std::next(path.rbegin()), prev_it\
    \ = path.rbegin(); it != path.rend(); ++it, ++prev_it) {\n      std::cout << *prev_it\
    \ << ' ' << *it << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n#include <cstddef>\n#include\
    \ <iterator>\n#include \"tools/dijkstra.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  i64 N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n\n  tools::dijkstra<i64>\
    \ dijkstra(N);\n  for (i64 i = 0; i < M; ++i) {\n    i64 a, b, c;\n    std::cin\
    \ >> a >> b >> c;\n    dijkstra.add_edge(a, b, c);\n  }\n\n  const auto result\
    \ = dijkstra.query(s);\n  std::vector<i64> path;\n  for (std::size_t i = t; i\
    \ != tools::dijkstra<i64>::NONE; i = result.prev_nodes[i]) {\n    path.push_back(i);\n\
    \  }\n\n  if (result.distances[t] == tools::dijkstra<i64>::INF) {\n    std::cout\
    \ << -1 << '\\n';\n  } else {\n    std::cout << result.distances[t] << ' ' <<\
    \ path.size() - 1 << '\\n';\n    for (auto it = std::next(path.rbegin()), prev_it\
    \ = path.rbegin(); it != path.rend(); ++it, ++prev_it) {\n      std::cout << *prev_it\
    \ << ' ' << *it << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/dijkstra.hpp
  isVerificationFile: true
  path: tests/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2021-03-29 00:30:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/tests/dijkstra.test.cpp
- /verify/tests/dijkstra.test.cpp.html
title: tests/dijkstra.test.cpp
---
