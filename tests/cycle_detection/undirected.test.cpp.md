---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cycle_detection.hpp
    title: Cycle detection on a graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2891
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2891
  bundledCode: "#line 1 \"tests/cycle_detection/undirected.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2891\"\n\n#include <cstdint>\n#include\
    \ <iostream>\n#include <vector>\n#line 1 \"tools/cycle_detection.hpp\"\n\n\n\n\
    #line 5 \"tools/cycle_detection.hpp\"\n#include <cstddef>\n#include <utility>\n\
    #include <cassert>\n#include <optional>\n#include <stack>\n#include <tuple>\n\
    #include <limits>\n#include <algorithm>\n\nnamespace tools {\n  template <bool\
    \ DIRECTED>\n  class cycle_detection {\n  private:\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_graph;\n    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> m_edges;\n\
    \n  public:\n    cycle_detection() = default;\n    cycle_detection(const ::tools::cycle_detection<DIRECTED>&)\
    \ = default;\n    cycle_detection(::tools::cycle_detection<DIRECTED>&&) = default;\n\
    \    ~cycle_detection() = default;\n    ::tools::cycle_detection<DIRECTED>& operator=(const\
    \ ::tools::cycle_detection<DIRECTED>&) = default;\n    ::tools::cycle_detection<DIRECTED>&\
    \ operator=(::tools::cycle_detection<DIRECTED>&&) = default;\n\n    explicit cycle_detection(const\
    \ ::std::size_t n) :\n      m_graph(n) {\n    }\n\n    ::std::size_t size() const\
    \ {\n      return this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(::std::size_t\
    \ u, ::std::size_t v) {\n      assert(u < this->size());\n      assert(v < this->size());\n\
    \n      this->m_graph[u].push_back(this->m_edges.size());\n      if (!DIRECTED)\
    \ {\n        this->m_graph[v].push_back(this->m_edges.size());\n      }\n    \
    \  this->m_edges.emplace_back(u, v);\n      return this->m_edges.size() - 1;\n\
    \    }\n\n    ::std::optional<::std::pair<::std::vector<::std::size_t>, ::std::vector<::std::size_t>>>\
    \ query() const {\n      ::std::stack<std::tuple<bool, ::std::size_t, ::std::size_t>>\
    \ stack;\n      for (::std::size_t v = 0; v < this->size(); ++v) {\n        stack.emplace(false,\
    \ v, ::std::numeric_limits<::std::size_t>::max());\n        stack.emplace(true,\
    \ v, ::std::numeric_limits<::std::size_t>::max());\n      }\n      ::std::vector<bool>\
    \ pre(this->size(), false);\n      ::std::vector<bool> post(this->size(), false);\n\
    \      ::std::vector<::std::size_t> prev(this->size(), ::std::numeric_limits<::std::size_t>::max());\n\
    \      while (!stack.empty()) {\n        const auto [is_pre, here, from] = stack.top();\n\
    \        stack.pop();\n        if (post[here]) continue;\n\n        if (is_pre)\
    \ {\n          prev[here] = from;\n          if (pre[here]) {\n            ::std::vector<::std::size_t>\
    \ vids, eids({from});\n            for (::std::size_t v = this->m_edges[from].first\
    \ ^ (DIRECTED ? 0 : this->m_edges[from].second ^ here); v != here; v = this->m_edges[prev[v]].first\
    \ ^ (DIRECTED ? 0 : this->m_edges[prev[v]].second ^ v)) {\n              vids.push_back(v);\n\
    \              eids.push_back(prev[v]);\n            }\n            vids.push_back(here);\n\
    \            ::std::reverse(vids.begin(), vids.end());\n            ::std::reverse(eids.begin(),\
    \ eids.end());\n            return ::std::make_optional(::std::make_pair(vids,\
    \ eids));\n          }\n          pre[here] = true;\n          for (const auto\
    \ eid : this->m_graph[here]) {\n            if (eid != from) {\n             \
    \ stack.emplace(false, this->m_edges[eid].second ^ (DIRECTED ? 0 : this->m_edges[eid].first\
    \ ^ here), eid);\n              stack.emplace(true, this->m_edges[eid].second\
    \ ^ (DIRECTED ? 0 : this->m_edges[eid].first ^ here), eid);\n            }\n \
    \         }\n        } else {\n          post[here] = true;\n        }\n     \
    \ }\n\n      return ::std::nullopt;\n    }\n  };\n}\n\n\n#line 7 \"tests/cycle_detection/undirected.test.cpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N;\n  std::cin >> N;\n  tools::cycle_detection<false>\
    \ graph(N);\n  for (i64 i = 0; i < N; ++i) {\n    i64 u, v;\n    std::cin >> u\
    \ >> v;\n    --u, --v;\n    graph.add_edge(u, v);\n  }\n\n  std::vector<bool>\
    \ is_in_cycle(N, false);\n  for (const auto v : std::vector(graph.query()->first))\
    \ {\n    is_in_cycle[v] = true;\n  }\n\n  i64 Q;\n  std::cin >> Q;\n  for (i64\
    \ q = 0; q < Q; ++q) {\n    i64 a, b;\n    std::cin >> a >> b;\n    --a, --b;\n\
    \    std::cout << (is_in_cycle[a] && is_in_cycle[b] ? 2 : 1) << '\\n';\n  }\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2891\"\n\n#include\
    \ <cstdint>\n#include <iostream>\n#include <vector>\n#include \"tools/cycle_detection.hpp\"\
    \n\nusing i64 = std::int_fast64_t;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  i64 N;\n  std::cin >> N;\n  tools::cycle_detection<false>\
    \ graph(N);\n  for (i64 i = 0; i < N; ++i) {\n    i64 u, v;\n    std::cin >> u\
    \ >> v;\n    --u, --v;\n    graph.add_edge(u, v);\n  }\n\n  std::vector<bool>\
    \ is_in_cycle(N, false);\n  for (const auto v : std::vector(graph.query()->first))\
    \ {\n    is_in_cycle[v] = true;\n  }\n\n  i64 Q;\n  std::cin >> Q;\n  for (i64\
    \ q = 0; q < Q; ++q) {\n    i64 a, b;\n    std::cin >> a >> b;\n    --a, --b;\n\
    \    std::cout << (is_in_cycle[a] && is_in_cycle[b] ? 2 : 1) << '\\n';\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/cycle_detection.hpp
  isVerificationFile: true
  path: tests/cycle_detection/undirected.test.cpp
  requiredBy: []
  timestamp: '2022-09-02 09:37:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cycle_detection/undirected.test.cpp
layout: document
redirect_from:
- /verify/tests/cycle_detection/undirected.test.cpp
- /verify/tests/cycle_detection/undirected.test.cpp.html
title: tests/cycle_detection/undirected.test.cpp
---
