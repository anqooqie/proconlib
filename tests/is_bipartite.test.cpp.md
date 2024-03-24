---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/is_bipartite.hpp
    title: Check whether a given graph is bipartite
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc327/tasks/abc327_d
    links:
    - https://atcoder.jp/contests/abc327/tasks/abc327_d
  bundledCode: "#line 1 \"tests/is_bipartite.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc327/tasks/abc327_d\"\
    \n\n#include <iostream>\n#include <vector>\n#line 1 \"tools/is_bipartite.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 6 \"tools/is_bipartite.hpp\"\n#include <cassert>\n\
    #include <tuple>\n#include <algorithm>\n#include <string>\n#include <queue>\n\n\
    namespace tools {\n\n  class is_bipartite {\n  public:\n    struct edge {\n  \
    \    ::std::size_t id;\n      ::std::size_t from;\n      ::std::size_t to;\n \
    \   };\n\n  private:\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n\n  public:\n    is_bipartite() = default;\n    explicit is_bipartite(const\
    \ ::std::size_t n) : m_graph(n) {\n    }\n\n    ::std::size_t size() const {\n\
    \      return this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(::std::size_t\
    \ u, ::std::size_t v) {\n      assert(u < this->size());\n      assert(v < this->size());\n\
    \      ::std::tie(u, v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v});\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n     \
    \ this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    bool query() const {\n      ::std::string belongs(this->size(),\
    \ '?');\n      for (::std::size_t root = 0; root < this->size(); ++root) {\n \
    \       if (belongs[root] == '?') {\n          ::std::queue<::std::size_t> queue({root});\n\
    \          belongs[root] = '0';\n          while (!queue.empty()) {\n        \
    \    const auto here = queue.front();\n            queue.pop();\n            for\
    \ (const auto edge_id : this->m_graph[here]) {\n              const auto& edge\
    \ = this->m_edges[edge_id];\n              const auto next = edge.from ^ edge.to\
    \ ^ here;\n              if (belongs[next] == '?') {\n                belongs[next]\
    \ = ((belongs[here] - '0') ^ 1) + '0';\n                queue.push(next);\n  \
    \            } else {\n                if (belongs[here] == belongs[next]) {\n\
    \                  return false;\n                }\n              }\n       \
    \     }\n          }\n        }\n      }\n\n      return true;\n    }\n  };\n\
    }\n\n\n#line 6 \"tests/is_bipartite.test.cpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  int N, M;\n  std::cin >> N >> M;\n\
    \  std::vector<int> A(M), B(M);\n  for (auto& A_i : A) {\n    std::cin >> A_i;\n\
    \    --A_i;\n  }\n  for (auto& B_i : B) {\n    std::cin >> B_i;\n    --B_i;\n\
    \  }\n\n  tools::is_bipartite graph(N);\n  for (int i = 0; i < M; ++i) {\n   \
    \ graph.add_edge(A[i], B[i]);\n  }\n\n  std::cout << (graph.query() ? \"Yes\"\
    \ : \"No\") << '\\n';\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc327/tasks/abc327_d\"\n\n\
    #include <iostream>\n#include <vector>\n#include \"tools/is_bipartite.hpp\"\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  int N, M;\n  std::cin >> N >> M;\n  std::vector<int> A(M), B(M);\n  for (auto&\
    \ A_i : A) {\n    std::cin >> A_i;\n    --A_i;\n  }\n  for (auto& B_i : B) {\n\
    \    std::cin >> B_i;\n    --B_i;\n  }\n\n  tools::is_bipartite graph(N);\n  for\
    \ (int i = 0; i < M; ++i) {\n    graph.add_edge(A[i], B[i]);\n  }\n\n  std::cout\
    \ << (graph.query() ? \"Yes\" : \"No\") << '\\n';\n  return 0;\n}\n"
  dependsOn:
  - tools/is_bipartite.hpp
  isVerificationFile: true
  path: tests/is_bipartite.test.cpp
  requiredBy: []
  timestamp: '2024-03-24 16:56:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/is_bipartite.test.cpp
layout: document
redirect_from:
- /verify/tests/is_bipartite.test.cpp
- /verify/tests/is_bipartite.test.cpp.html
title: tests/is_bipartite.test.cpp
---
