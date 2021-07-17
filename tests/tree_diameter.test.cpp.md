---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/tree_diameter.hpp
    title: Diameter of tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
  bundledCode: "#line 1 \"tests/tree_diameter.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\
    \n\n#include <cstdint>\n#include <iostream>\n#line 1 \"tools/tree_diameter.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <vector>\n#include <cassert>\n#include <numeric>\n\
    #include <limits>\n#include <queue>\n#include <iterator>\n#include <algorithm>\n\
    #line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs)\
    \ {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n\n#line 13 \"tools/tree_diameter.hpp\"\n\nnamespace tools\
    \ {\n  template <typename T>\n  class tree_diameter {\n  private:\n    class edge\
    \ {\n    public:\n      ::std::size_t from;\n      ::std::size_t to;\n      T\
    \ distance;\n      edge(const ::std::size_t from, const ::std::size_t to, const\
    \ T& distance) :\n        from(from),\n        to(to),\n        distance(distance)\
    \ {\n      }\n    };\n\n    ::std::vector<::std::vector<edge>> edges;\n\n  public:\n\
    \    tree_diameter(const ::std::size_t node_count) :\n      edges(node_count)\
    \ {\n    }\n\n    ::std::size_t node_count() const {\n      return this->edges.size();\n\
    \    }\n\n    void add_edge(const ::std::size_t from, const ::std::size_t to,\
    \ const T& distance) {\n      this->edges[from].emplace_back(from, to, distance);\n\
    \      this->edges[to].emplace_back(to, from, distance);\n    }\n\n    T query()\
    \ const {\n      assert(::std::accumulate(this->edges.begin(), this->edges.end(),\
    \ ::std::size_t(0), [](const ::std::size_t sum, const ::std::vector<edge>& e)\
    \ { return sum + e.size(); }) + 2 == this->node_count() * 2);\n\n      ::std::vector<T>\
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
    }\n\n\n#line 6 \"tests/tree_diameter.test.cpp\"\n\nusing i64 = std::int_fast64_t;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  i64 n;\n  std::cin >> n;\n  tools::tree_diameter<i64> tree(n);\n  for (i64\
    \ i = 0; i < n - 1; ++i) {\n    i64 s, t, w;\n    std::cin >> s >> t >> w;\n \
    \   tree.add_edge(s, t, w);\n  }\n  std::cout << tree.query() << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A\"\n\n\
    #include <cstdint>\n#include <iostream>\n#include \"tools/tree_diameter.hpp\"\n\
    \nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n \
    \ std::ios_base::sync_with_stdio(false);\n\n  i64 n;\n  std::cin >> n;\n  tools::tree_diameter<i64>\
    \ tree(n);\n  for (i64 i = 0; i < n - 1; ++i) {\n    i64 s, t, w;\n    std::cin\
    \ >> s >> t >> w;\n    tree.add_edge(s, t, w);\n  }\n  std::cout << tree.query()\
    \ << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/tree_diameter.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2021-07-17 23:00:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/tests/tree_diameter.test.cpp
- /verify/tests/tree_diameter.test.cpp.html
title: tests/tree_diameter.test.cpp
---
