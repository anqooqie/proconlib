---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/bellman_ford.hpp
    title: Bellman-Ford algorithm
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B
  bundledCode: "#line 1 \"tests/bellman_ford.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <algorithm>\n#include <limits>\n\
    #line 1 \"tools/bellman_ford.hpp\"\n\n\n\n#include <cstddef>\n#include <vector>\n\
    #line 7 \"tools/bellman_ford.hpp\"\n#include <cassert>\n#line 1 \"tools/chmin.hpp\"\
    \n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ M, typename N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool updated\
    \ = lhs > rhs;\n    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n\
    #line 9 \"tools/bellman_ford.hpp\"\n\nnamespace tools {\n\n  template <typename\
    \ T>\n  class bellman_ford {\n  private:\n    class edge {\n    public:\n    \
    \  ::std::size_t from;\n      ::std::size_t to;\n      T distance;\n      edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) :\n       \
    \ from(from),\n        to(to),\n        distance(distance) {\n      }\n    };\n\
    \n    ::std::size_t m_node_count;\n    ::std::vector<edge> m_edges;\n\n  public:\n\
    \    constexpr inline static T POS_INF = ::std::numeric_limits<T>::max();\n  \
    \  constexpr inline static T NEG_INF = ::std::numeric_limits<T>::min();\n    constexpr\
    \ inline static ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();\n\
    \n    class result {\n    public:\n      ::std::vector<T> distances;\n      ::std::vector<::std::size_t>\
    \ prev_nodes;\n      result(const ::std::size_t& node_count) :\n        distances(node_count,\
    \ POS_INF),\n        prev_nodes(node_count, NONE) {\n      }\n    };\n\n    explicit\
    \ bellman_ford(const ::std::size_t& node_count) :\n      m_node_count(node_count),\n\
    \      m_edges() {\n    }\n\n    ::std::size_t node_count() const {\n      return\
    \ this->m_node_count;\n    }\n\n    void add_edge(const ::std::size_t& from, const\
    \ ::std::size_t& to, const T& distance) {\n      this->m_edges.emplace_back(from,\
    \ to, distance);\n    }\n\n    result query(const ::std::size_t& start_node) const\
    \ {\n      assert(start_node < this->m_node_count);\n      result result(this->m_node_count);\n\
    \      result.distances[start_node] = 0;\n      for (::std::size_t i = 0; i <\
    \ this->m_node_count - 1; ++i) {\n        for (const edge& edge : this->m_edges)\
    \ {\n          if (result.distances[edge.from] < POS_INF && ::tools::chmin(result.distances[edge.to],\
    \ result.distances[edge.from] + edge.distance)) {\n            result.prev_nodes[edge.to]\
    \ = edge.from;\n          }\n        }\n      }\n      for (const edge& edge :\
    \ this->m_edges) {\n        if (result.distances[edge.from] < POS_INF && result.distances[edge.from]\
    \ + (result.distances[edge.from] > NEG_INF ? edge.distance : 0) < result.distances[edge.to])\
    \ {\n          result.distances[edge.to] = NEG_INF;\n          result.prev_nodes[edge.to]\
    \ = edge.from;\n        }\n      }\n      for (::std::size_t i = 0; i < this->m_node_count;\
    \ ++i) {\n        for (const edge& edge : this->m_edges) {\n          if (result.distances[edge.from]\
    \ < POS_INF && ::tools::chmin(result.distances[edge.to], result.distances[edge.from]\
    \ + (result.distances[edge.from] > NEG_INF ? edge.distance : 0))) {\n        \
    \    result.prev_nodes[edge.to] = edge.from;\n          }\n        }\n      }\n\
    \      return result;\n    }\n  };\n}\n\n\n#line 8 \"tests/bellman_ford.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 V_size, E_size, r;\n  std::cin\
    \ >> V_size >> E_size >> r;\n\n  tools::bellman_ford<i64> bf(V_size);\n  for (i64\
    \ i = 0; i < E_size; ++i) {\n    i64 s, t, d;\n    std::cin >> s >> t >> d;\n\
    \    bf.add_edge(s, t, d);\n  }\n\n  const auto result = bf.query(r);\n  if (std::any_of(result.distances.begin(),\
    \ result.distances.end(), [](const i64& distance) { return distance == std::numeric_limits<i64>::min();\
    \ })) {\n    std::cout << \"NEGATIVE CYCLE\" << '\\n';\n  } else {\n    for (const\
    \ i64& distance : result.distances) {\n      if (distance == std::numeric_limits<i64>::max())\
    \ {\n        std::cout << \"INF\" << '\\n';\n      } else {\n        std::cout\
    \ << distance << '\\n';\n      }\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include <algorithm>\n#include <limits>\n\
    #include \"tools/bellman_ford.hpp\"\n\nusing i64 = std::int_fast64_t;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  i64\
    \ V_size, E_size, r;\n  std::cin >> V_size >> E_size >> r;\n\n  tools::bellman_ford<i64>\
    \ bf(V_size);\n  for (i64 i = 0; i < E_size; ++i) {\n    i64 s, t, d;\n    std::cin\
    \ >> s >> t >> d;\n    bf.add_edge(s, t, d);\n  }\n\n  const auto result = bf.query(r);\n\
    \  if (std::any_of(result.distances.begin(), result.distances.end(), [](const\
    \ i64& distance) { return distance == std::numeric_limits<i64>::min(); })) {\n\
    \    std::cout << \"NEGATIVE CYCLE\" << '\\n';\n  } else {\n    for (const i64&\
    \ distance : result.distances) {\n      if (distance == std::numeric_limits<i64>::max())\
    \ {\n        std::cout << \"INF\" << '\\n';\n      } else {\n        std::cout\
    \ << distance << '\\n';\n      }\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/bellman_ford.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2021-07-22 15:31:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/tests/bellman_ford.test.cpp
- /verify/tests/bellman_ford.test.cpp.html
title: tests/bellman_ford.test.cpp
---
