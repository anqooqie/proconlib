---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/dijkstra.hpp
    title: Dijkstra's algorithm
  - icon: ':question:'
    path: tools/greater_by_second.hpp
    title: std::greater by second
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
    #line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#include <utility>\n\nnamespace\
    \ tools {\n\n  class greater_by_second {\n  public:\n    template <class T1, class\
    \ T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1,\
    \ T2>& y) const {\n      return x.second > y.second;\n    }\n  };\n}\n\n\n#line\
    \ 1 \"tools/chmin.hpp\"\n\n\n\n#include <algorithm>\n\nnamespace tools {\n\n \
    \ template <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n  \
    \  const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n\
    \  }\n}\n\n\n#line 12 \"tools/dijkstra.hpp\"\n\nnamespace tools {\n\n  template\
    \ <typename T>\n  class dijkstra {\n  private:\n    class edge {\n    public:\n\
    \      ::std::size_t from;\n      ::std::size_t to;\n      T distance;\n     \
    \ edge(const ::std::size_t from, const ::std::size_t to, const T distance) :\n\
    \        from(from),\n        to(to),\n        distance(distance) {\n      }\n\
    \    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n    static\
    \ constexpr T INF = ::std::numeric_limits<T>::max();\n    static constexpr ::std::size_t\
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
    \ start_node);\n      ::std::priority_queue<::std::pair<::std::size_t, T>, ::std::vector<::std::pair<::std::size_t,\
    \ T>>, ::tools::greater_by_second> tasks;\n      tasks.emplace(start_node, 0);\n\
    \n      while (!tasks.empty()) {\n        const auto [here, d] = tasks.top();\n\
    \        tasks.pop();\n        if (result.distances[here] < d) continue;\n   \
    \     for (const edge& edge : this->edges[here]) {\n          if (::tools::chmin(result.distances[edge.to],\
    \ result.distances[here] + edge.distance)) {\n            result.prev_nodes[edge.to]\
    \ = edge.from;\n            tasks.emplace(edge.to, result.distances[edge.to]);\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n  };\n}\n\n\n\
    #line 9 \"tests/dijkstra.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  i64\
    \ N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n\n  tools::dijkstra<i64> dijkstra(N);\n\
    \  for (i64 i = 0; i < M; ++i) {\n    i64 a, b, c;\n    std::cin >> a >> b >>\
    \ c;\n    dijkstra.add_edge(a, b, c);\n  }\n\n  const auto result = dijkstra.query(s);\n\
    \  std::vector<i64> path;\n  for (std::size_t i = t; i != tools::dijkstra<i64>::NONE;\
    \ i = result.prev_nodes[i]) {\n    path.push_back(i);\n  }\n\n  if (result.distances[t]\
    \ == tools::dijkstra<i64>::INF) {\n    std::cout << -1 << '\\n';\n  } else {\n\
    \    std::cout << result.distances[t] << ' ' << path.size() - 1 << '\\n';\n  \
    \  for (auto it = std::next(path.rbegin()), prev_it = path.rbegin(); it != path.rend();\
    \ ++it, ++prev_it) {\n      std::cout << *prev_it << ' ' << *it << '\\n';\n  \
    \  }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n#include <cstddef>\n#include\
    \ <iterator>\n#include \"tools/dijkstra.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n\n  tools::dijkstra<i64>\
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
  - tools/greater_by_second.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2022-03-08 22:34:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/tests/dijkstra.test.cpp
- /verify/tests/dijkstra.test.cpp.html
title: tests/dijkstra.test.cpp
---
