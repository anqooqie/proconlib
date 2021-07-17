---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/zero_one_bfs.hpp
    title: 01-BFS
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2945
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2945
  bundledCode: "#line 1 \"tests/zero_one_bfs.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2945\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <array>\n#include <utility>\n\
    #include <tuple>\n#line 1 \"tools/zero_one_bfs.hpp\"\n\n\n\n#include <cstddef>\n\
    #include <vector>\n#include <limits>\n#include <cassert>\n#include <deque>\n\n\
    namespace tools {\n\n  template <typename T>\n  class zero_one_bfs {\n  private:\n\
    \    class edge {\n    public:\n      ::std::size_t from;\n      ::std::size_t\
    \ to;\n      T distance;\n      edge(const ::std::size_t from, const ::std::size_t\
    \ to, const T distance) :\n        from(from),\n        to(to),\n        distance(distance)\
    \ {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n\
    \    static constexpr T INF = ::std::numeric_limits<T>::max();\n    static constexpr\
    \ ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\n    class\
    \ result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count, const ::std::size_t&\
    \ start_node) :\n        distances(node_count, INF),\n        prev_nodes(node_count,\
    \ NONE) {\n        this->distances[start_node] = 0;\n      }\n    };\n\n    zero_one_bfs(const\
    \ ::std::size_t& node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t\
    \ node_count() const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) {\n      assert(distance\
    \ == 0 || distance == 1);\n\n      this->edges[from].emplace_back(from, to, distance);\n\
    \    }\n\n    result query(const ::std::size_t& start_node) const {\n      assert(start_node\
    \ < this->node_count());\n\n      result result(this->node_count(), start_node);\n\
    \      ::std::vector<bool> visited(this->node_count(), false);\n      ::std::deque<::std::size_t>\
    \ deque;\n      deque.push_front(start_node);\n\n      while (!deque.empty())\
    \ {\n        const ::std::size_t vertex = deque.front();\n        deque.pop_front();\n\
    \        if (visited[vertex]) continue;\n        visited[vertex] = true;\n   \
    \     for (const edge& edge : this->edges[vertex]) {\n          const T new_distance\
    \ = result.distances[vertex] + edge.distance;\n          if (new_distance < result.distances[edge.to])\
    \ {\n            result.distances[edge.to] = new_distance;\n            result.prev_nodes[edge.to]\
    \ = edge.from;\n            if (edge.distance == 0) {\n              deque.push_front(edge.to);\n\
    \            } else {\n              deque.push_back(edge.to);\n            }\n\
    \          }\n        }\n      }\n\n      return result;\n    }\n  };\n}\n\n\n\
    #line 9 \"tests/zero_one_bfs.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const auto P = [](const i64 x, const i64 y) {\n    return 100 * y + x;\n \
    \ };\n  for (i64 N; std::cin >> N, N > 0;) {\n    i64 A, B, C, D;\n    std::cin\
    \ >> A >> B >> C >> D;\n    --A, --B;\n    tools::zero_one_bfs<i64> bfs(100 *\
    \ 100);\n    for (i64 x = 0; x < 100; ++x) {\n      for (i64 y = 0; y < 100; ++y)\
    \ {\n        for (const auto& [dx, dy] : std::array<std::pair<i64, i64>, 4>({std::make_pair(1,\
    \ 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)})) {\n\
    \          if (0 <= x + dx && x + dx < 100 && 0 <= y + dy && y + dy < 100) {\n\
    \            bfs.add_edge(P(x, y), P(x + dx, y + dy), A <= x + dx && x + dx <\
    \ C && B <= y + dy && y + dy < D ? 0 : 1);\n          }\n        }\n      }\n\
    \    }\n\n    i64 answer = 0;\n    i64 pX, pY;\n    std::cin >> pX >> pY;\n  \
    \  --pX, --pY;\n    for (i64 i = 0; i < N; ++i) {\n      i64 X, Y;\n      std::cin\
    \ >> X >> Y;\n      --X, --Y;\n      answer += bfs.query(P(pX, pY)).distances[P(X,\
    \ Y)];\n      std::tie(pX, pY) = std::make_pair(X, Y);\n    }\n\n    std::cout\
    \ << answer << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2945\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <array>\n#include <utility>\n#include\
    \ <tuple>\n#include \"tools/zero_one_bfs.hpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const auto P = [](const i64 x, const i64 y) {\n    return 100 * y + x;\n \
    \ };\n  for (i64 N; std::cin >> N, N > 0;) {\n    i64 A, B, C, D;\n    std::cin\
    \ >> A >> B >> C >> D;\n    --A, --B;\n    tools::zero_one_bfs<i64> bfs(100 *\
    \ 100);\n    for (i64 x = 0; x < 100; ++x) {\n      for (i64 y = 0; y < 100; ++y)\
    \ {\n        for (const auto& [dx, dy] : std::array<std::pair<i64, i64>, 4>({std::make_pair(1,\
    \ 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)})) {\n\
    \          if (0 <= x + dx && x + dx < 100 && 0 <= y + dy && y + dy < 100) {\n\
    \            bfs.add_edge(P(x, y), P(x + dx, y + dy), A <= x + dx && x + dx <\
    \ C && B <= y + dy && y + dy < D ? 0 : 1);\n          }\n        }\n      }\n\
    \    }\n\n    i64 answer = 0;\n    i64 pX, pY;\n    std::cin >> pX >> pY;\n  \
    \  --pX, --pY;\n    for (i64 i = 0; i < N; ++i) {\n      i64 X, Y;\n      std::cin\
    \ >> X >> Y;\n      --X, --Y;\n      answer += bfs.query(P(pX, pY)).distances[P(X,\
    \ Y)];\n      std::tie(pX, pY) = std::make_pair(X, Y);\n    }\n\n    std::cout\
    \ << answer << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/zero_one_bfs.hpp
  isVerificationFile: true
  path: tests/zero_one_bfs.test.cpp
  requiredBy: []
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/zero_one_bfs.test.cpp
layout: document
redirect_from:
- /verify/tests/zero_one_bfs.test.cpp
- /verify/tests/zero_one_bfs.test.cpp.html
title: tests/zero_one_bfs.test.cpp
---
