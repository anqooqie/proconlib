---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/dijkstra.hpp
    title: Dijkstra's algorithm
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"tests/dijkstra/directed.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <limits>\n#include <vector>\n\
    #include <algorithm>\n#include <cstddef>\n#line 1 \"tools/dijkstra.hpp\"\n\n\n\
    \n#line 6 \"tools/dijkstra.hpp\"\n#include <cassert>\n#include <utility>\n#line\
    \ 10 \"tools/dijkstra.hpp\"\n#include <queue>\n#line 1 \"tools/greater_by_second.hpp\"\
    \n\n\n\n#line 5 \"tools/greater_by_second.hpp\"\n\nnamespace tools {\n\n  class\
    \ greater_by_second {\n  public:\n    template <class T1, class T2>\n    bool\
    \ operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1, T2>& y) const\
    \ {\n      return x.second > y.second;\n    }\n  };\n}\n\n\n#line 1 \"tools/chmin.hpp\"\
    \n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool updated\
    \ = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 13 \"tools/dijkstra.hpp\"\n\nnamespace tools {\n\n  template <bool Directed,\
    \ typename T>\n  class dijkstra {\n  public:\n    struct edge {\n      ::std::size_t\
    \ id;\n      ::std::size_t from;\n      ::std::size_t to;\n      T cost;\n   \
    \ };\n\n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    dijkstra() = default;\n    dijkstra(const ::tools::dijkstra<Directed,\
    \ T>&) = default;\n    dijkstra(::tools::dijkstra<Directed, T>&&) = default;\n\
    \    ~dijkstra() = default;\n    ::tools::dijkstra<Directed, T>& operator=(const\
    \ ::tools::dijkstra<Directed, T>&) = default;\n    ::tools::dijkstra<Directed,\
    \ T>& operator=(::tools::dijkstra<Directed, T>&&) = default;\n\n    dijkstra(const\
    \ ::std::size_t n) : m_graph(n) {\n    }\n\n    ::std::size_t size() const {\n\
    \      return this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(::std::size_t\
    \ u, ::std::size_t v, const T& w) {\n      assert(u < this->size());\n      assert(v\
    \ < this->size());\n      assert(w >= 0);\n      if constexpr (!Directed) {\n\
    \        ::std::tie(u, v) = ::std::minmax({u, v});\n      }\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n \
    \     if constexpr (!Directed) {\n        this->m_graph[v].push_back(this->m_edges.size()\
    \ - 1);\n      }\n      return this->m_edges.size() - 1;\n    }\n\n    const edge&\
    \ get_edge(const ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n\
    \      return this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges()\
    \ const {\n      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>,\
    \ ::std::vector<::std::size_t>> query(const ::std::size_t s) {\n      assert(s\
    \ < this->size());\n\n      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());\n\
    \      dist[s] = 0;\n      ::std::vector<::std::size_t> prev(this->size());\n\
    \      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n      ::std::priority_queue<::std::pair<::std::size_t,\
    \ T>, ::std::vector<::std::pair<::std::size_t, T>>, ::tools::greater_by_second>\
    \ pq;\n      pq.emplace(s, 0);\n\n      while (!pq.empty()) {\n        const auto\
    \ [here, d] = pq.top();\n        pq.pop();\n        if (dist[here] < d) continue;\n\
    \        for (const auto edge_id : this->m_graph[here]) {\n          const auto&\
    \ edge = this->m_edges[edge_id];\n          const auto next = edge.to ^ (Directed\
    \ ? 0 : edge.from ^ here);\n          if (::tools::chmin(dist[next], dist[here]\
    \ + edge.cost)) {\n            prev[next] = edge.id;\n            pq.emplace(next,\
    \ dist[next]);\n          }\n        }\n      }\n\n      return ::std::make_pair(dist,\
    \ prev);\n    }\n  };\n}\n\n\n#line 10 \"tests/dijkstra/directed.test.cpp\"\n\n\
    using i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n\n  tools::dijkstra<true,\
    \ i64> graph(N);\n  for (i64 i = 0; i < M; ++i) {\n    i64 a, b, c;\n    std::cin\
    \ >> a >> b >> c;\n    graph.add_edge(a, b, c);\n  }\n\n  const auto [dist, prev]\
    \ = graph.query(s);\n  if (dist[t] == std::numeric_limits<i64>::max()) {\n   \
    \ std::cout << -1 << '\\n';\n  } else {\n    std::vector<i64> path;\n    for (auto\
    \ v = t; v != s; v = graph.get_edge(prev[v]).from) {\n      path.push_back(v);\n\
    \    }\n    path.push_back(s);\n    std::reverse(path.begin(), path.end());\n\n\
    \    std::cout << dist[t] << ' ' << path.size() - 1 << '\\n';\n    for (::std::size_t\
    \ i = 0; i + 1 < path.size(); ++i) {\n      std::cout << path[i] << ' ' << path[i\
    \ + 1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <limits>\n#include <vector>\n#include\
    \ <algorithm>\n#include <cstddef>\n#include \"tools/dijkstra.hpp\"\n\nusing i64\
    \ = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 N, M, s, t;\n  std::cin >> N >> M >> s >> t;\n\n  tools::dijkstra<true,\
    \ i64> graph(N);\n  for (i64 i = 0; i < M; ++i) {\n    i64 a, b, c;\n    std::cin\
    \ >> a >> b >> c;\n    graph.add_edge(a, b, c);\n  }\n\n  const auto [dist, prev]\
    \ = graph.query(s);\n  if (dist[t] == std::numeric_limits<i64>::max()) {\n   \
    \ std::cout << -1 << '\\n';\n  } else {\n    std::vector<i64> path;\n    for (auto\
    \ v = t; v != s; v = graph.get_edge(prev[v]).from) {\n      path.push_back(v);\n\
    \    }\n    path.push_back(s);\n    std::reverse(path.begin(), path.end());\n\n\
    \    std::cout << dist[t] << ' ' << path.size() - 1 << '\\n';\n    for (::std::size_t\
    \ i = 0; i + 1 < path.size(); ++i) {\n      std::cout << path[i] << ' ' << path[i\
    \ + 1] << '\\n';\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/dijkstra.hpp
  - tools/greater_by_second.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/dijkstra/directed.test.cpp
  requiredBy: []
  timestamp: '2022-10-01 12:56:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/dijkstra/directed.test.cpp
layout: document
redirect_from:
- /verify/tests/dijkstra/directed.test.cpp
- /verify/tests/dijkstra/directed.test.cpp.html
title: tests/dijkstra/directed.test.cpp
---
