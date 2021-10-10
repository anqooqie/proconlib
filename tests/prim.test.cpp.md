---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/prim.hpp
    title: Prim's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A
  bundledCode: "#line 1 \"tests/prim.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/prim.hpp\"\n\n\n\n\
    #include <cstddef>\n#include <vector>\n#include <queue>\n#include <functional>\n\
    #include <limits>\n\nnamespace tools {\n\n  template <typename T>\n  class prim\
    \ {\n  public:\n    class edge {\n    private:\n      ::std::size_t m_from;\n\
    \      ::std::size_t m_to;\n      T m_distance;\n\n    public:\n      edge(const\
    \ ::std::size_t& from, const ::std::size_t& to, const T& distance) :\n       \
    \ m_from(from),\n        m_to(to),\n        m_distance(distance) {\n      }\n\n\
    \      ::std::size_t from() const {\n        return this->m_from;\n      }\n \
    \     ::std::size_t to() const {\n        return this->m_to;\n      }\n      T\
    \ distance() const {\n        return this->m_distance;\n      }\n    };\n\n  \
    \  class result {\n    public:\n      T total_distance;\n      ::std::vector<edge>\
    \ edges;\n      result() :\n        total_distance(0), edges() {\n      }\n  \
    \  };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n    prim(const ::std::size_t&\
    \ node_count) :\n      edges(node_count) {\n    }\n\n    ::std::size_t node_count()\
    \ const {\n      return this->edges.size();\n    }\n\n    void add_edge(const\
    \ ::std::size_t& v1, const ::std::size_t& v2, const T& distance) {\n      this->edges[v1].emplace_back(v1,\
    \ v2, distance);\n      this->edges[v2].emplace_back(v2, v1, distance);\n    }\n\
    \n    result query() const {\n      result result;\n      ::std::vector<bool>\
    \ visited(this->node_count(), false);\n      const auto greater_by_distance =\
    \ [](const edge& x, const edge& y) {\n        return x.distance() > y.distance();\n\
    \      };\n      ::std::priority_queue<edge, ::std::vector<edge>, decltype(greater_by_distance)>\
    \ tasks(greater_by_distance);\n      tasks.emplace(::std::numeric_limits<::std::size_t>::max(),\
    \ 0, 0);\n      bool is_first_task = true;\n\n      while (!tasks.empty()) {\n\
    \        const edge task = tasks.top();\n        tasks.pop();\n        if (visited[task.to()])\
    \ continue;\n        if (is_first_task) {\n          is_first_task = false;\n\
    \        } else {\n          result.total_distance += task.distance();\n     \
    \     result.edges.push_back(task);\n        }\n        visited[task.to()] = true;\n\
    \        for (const edge& edge : this->edges[task.to()]) {\n          if (!visited[edge.to()])\
    \ {\n            tasks.push(edge);\n          }\n        }\n      }\n\n      return\
    \ result;\n    }\n  };\n}\n\n\n#line 6 \"tests/prim.test.cpp\"\n\nusing i64 =\
    \ std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 V, E;\n  std::cin >> V >> E;\n  tools::prim<i64> prim(V);\n  for (i64\
    \ i = 0; i < E; ++i) {\n    i64 s, t, w;\n    std::cin >> s >> t >> w;\n    prim.add_edge(s,\
    \ t, w);\n  }\n\n  std::cout << prim.query().total_distance << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include \"tools/prim.hpp\"\n\nusing\
    \ i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 V, E;\n  std::cin >> V >> E;\n  tools::prim<i64> prim(V);\n  for (i64\
    \ i = 0; i < E; ++i) {\n    i64 s, t, w;\n    std::cin >> s >> t >> w;\n    prim.add_edge(s,\
    \ t, w);\n  }\n\n  std::cout << prim.query().total_distance << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/prim.hpp
  isVerificationFile: true
  path: tests/prim.test.cpp
  requiredBy: []
  timestamp: '2021-10-10 17:49:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/prim.test.cpp
layout: document
redirect_from:
- /verify/tests/prim.test.cpp
- /verify/tests/prim.test.cpp.html
title: tests/prim.test.cpp
---
