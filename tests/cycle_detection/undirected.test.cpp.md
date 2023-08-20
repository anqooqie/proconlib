---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/cycle_detection.hpp
    title: Cycle detection on a graph
  - icon: ':question:'
    path: tools/join.hpp
    title: Join elements with delimiter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
  bundledCode: "#line 1 \"tests/cycle_detection/undirected.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\n\n#include <iostream>\n\
    #include <cstddef>\n#line 1 \"tools/cycle_detection.hpp\"\n\n\n\n#include <vector>\n\
    #line 6 \"tools/cycle_detection.hpp\"\n#include <utility>\n#include <cassert>\n\
    #include <optional>\n#include <stack>\n#include <tuple>\n#include <limits>\n#include\
    \ <algorithm>\n\nnamespace tools {\n  template <bool DIRECTED>\n  class cycle_detection\
    \ {\n  private:\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n  \
    \  ::std::vector<::std::pair<::std::size_t, ::std::size_t>> m_edges;\n\n  public:\n\
    \    cycle_detection() = default;\n    cycle_detection(const ::tools::cycle_detection<DIRECTED>&)\
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
    \ }\n\n      return ::std::nullopt;\n    }\n  };\n}\n\n\n#line 1 \"tools/join.hpp\"\
    \n\n\n\n#include <string>\n#include <sstream>\n\nnamespace tools {\n\n  template\
    \ <typename Iterator>\n  ::std::string join(const Iterator begin, const Iterator\
    \ end, const ::std::string delimiter) {\n    ::std::ostringstream ss;\n    ::std::string\
    \ current_delimiter = \"\";\n    for (Iterator it = begin; it != end; ++it) {\n\
    \      ss << current_delimiter << *it;\n      current_delimiter = delimiter;\n\
    \    }\n    return ss.str();\n  }\n}\n\n\n#line 7 \"tests/cycle_detection/undirected.test.cpp\"\
    \n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::size_t N, M;\n  std::cin >> N >> M;\n  tools::cycle_detection<false>\
    \ graph(N);\n  for (std::size_t i = 0; i < M; ++i) {\n    std::size_t u, v;\n\
    \    std::cin >> u >> v;\n    graph.add_edge(u, v);\n  }\n\n  if (const auto answer\
    \ = graph.query(); answer) {\n    const auto& [vids, eids] = *answer;\n    std::cout\
    \ << vids.size() << '\\n';\n    std::cout << tools::join(vids.begin(), vids.end(),\
    \ \" \") << '\\n';\n    std::cout << tools::join(eids.begin(), eids.end(), \"\
    \ \") << '\\n';\n  } else {\n    std::cout << -1 << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n\n#include <iostream>\n#include <cstddef>\n#include \"tools/cycle_detection.hpp\"\
    \n#include \"tools/join.hpp\"\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  std::size_t N, M;\n  std::cin >> N >> M;\n  tools::cycle_detection<false>\
    \ graph(N);\n  for (std::size_t i = 0; i < M; ++i) {\n    std::size_t u, v;\n\
    \    std::cin >> u >> v;\n    graph.add_edge(u, v);\n  }\n\n  if (const auto answer\
    \ = graph.query(); answer) {\n    const auto& [vids, eids] = *answer;\n    std::cout\
    \ << vids.size() << '\\n';\n    std::cout << tools::join(vids.begin(), vids.end(),\
    \ \" \") << '\\n';\n    std::cout << tools::join(eids.begin(), eids.end(), \"\
    \ \") << '\\n';\n  } else {\n    std::cout << -1 << '\\n';\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - tools/cycle_detection.hpp
  - tools/join.hpp
  isVerificationFile: true
  path: tests/cycle_detection/undirected.test.cpp
  requiredBy: []
  timestamp: '2022-10-22 11:25:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/cycle_detection/undirected.test.cpp
layout: document
redirect_from:
- /verify/tests/cycle_detection/undirected.test.cpp
- /verify/tests/cycle_detection/undirected.test.cpp.html
title: tests/cycle_detection/undirected.test.cpp
---
