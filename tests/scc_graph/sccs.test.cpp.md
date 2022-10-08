---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':x:'
    path: tools/scc_graph.hpp
    title: Strongly connected component decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"tests/scc_graph/sccs.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <iostream>\n#line 1 \"tools/scc_graph.hpp\"\n\n\n\n#include <vector>\n\
    #include <utility>\n#include <cstddef>\n#include <cassert>\n#include <stack>\n\
    #include <algorithm>\n#line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\
    \n  template <class F>\n  class less_by {\n  private:\n    F selector;\n\n  public:\n\
    \    less_by(const F& selector) : selector(selector) {\n    }\n\n    template\
    \ <class T>\n    bool operator()(const T& x, const T& y) const {\n      return\
    \ selector(x) < selector(y);\n    }\n  };\n}\n\n\n#line 11 \"tools/scc_graph.hpp\"\
    \n\nnamespace tools {\n  class scc_graph {\n  private:\n    ::std::vector<::std::pair<::std::size_t,\
    \ ::std::size_t>> m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\
    \    ::std::vector<::std::vector<::std::size_t>> m_rev_graph;\n    ::std::vector<::std::size_t>\
    \ m_vid2scc;\n    ::std::vector<::std::vector<::std::size_t>> m_sccs;\n    ::std::vector<::std::vector<::std::size_t>>\
    \ m_edges_in_scc;\n    ::std::vector<::std::vector<::std::pair<::std::size_t,\
    \ ::std::vector<::std::size_t>>>> m_scc_graph;\n    ::std::vector<::std::vector<::std::pair<::std::size_t,\
    \ ::std::vector<::std::size_t>>>> m_rev_scc_graph;\n    bool m_built;\n\n  public:\n\
    \    scc_graph() = default;\n    scc_graph(const ::tools::scc_graph&) = default;\n\
    \    scc_graph(::tools::scc_graph&&) = default;\n    ~scc_graph() = default;\n\
    \    ::tools::scc_graph& operator=(const ::tools::scc_graph&) = default;\n   \
    \ ::tools::scc_graph& operator=(::tools::scc_graph&&) = default;\n\n    explicit\
    \ scc_graph(const ::std::size_t n) : m_graph(n), m_rev_graph(n), m_vid2scc(n),\
    \ m_built(false) {\n    }\n\n    ::std::size_t size() const {\n      return this->m_graph.size();\n\
    \    }\n\n    ::std::size_t add_edge(const ::std::size_t from, const ::std::size_t\
    \ to) {\n      assert(from < this->size());\n      assert(to < this->size());\n\
    \      assert(!this->m_built);\n      const auto edge_id = this->m_edges.size();\n\
    \      this->m_edges.emplace_back(from, to);\n      this->m_graph[from].push_back(edge_id);\n\
    \      this->m_rev_graph[to].push_back(edge_id);\n      return edge_id;\n    }\n\
    \n    ::std::pair<::std::size_t, ::std::size_t> edge(const ::std::size_t i) const\
    \ {\n      assert(i < this->m_edges.size());\n      return this->m_edges[i];\n\
    \    }\n    const ::std::vector<::std::size_t>& edges_from(const ::std::size_t\
    \ i) const {\n      assert(i < this->size());\n      return this->m_graph[i];\n\
    \    }\n    const ::std::vector<::std::size_t>& edges_to(const ::std::size_t i)\
    \ const {\n      assert(i < this->size());\n      return this->m_rev_graph[i];\n\
    \    }\n\n    void build() {\n      assert(!this->m_built);\n      ::std::stack<::std::size_t>\
    \ ordered_by_dfs;\n      {\n        ::std::vector<bool> visited(this->size(),\
    \ false);\n        ::std::stack<::std::pair<bool, ::std::size_t>> stack;\n   \
    \     for (::std::size_t i = this->size(); i --> 0;) {\n          stack.emplace(true,\
    \ i);\n        }\n        while (!stack.empty()) {\n          const auto [pre,\
    \ here] = stack.top();\n          stack.pop();\n          if (pre) {\n       \
    \     if (visited[here]) continue;\n            visited[here] = true;\n      \
    \      stack.emplace(false, here);\n            for (const auto e : this->m_graph[here])\
    \ {\n              const auto next = this->m_edges[e].second;\n              if\
    \ (visited[next]) continue;\n              stack.emplace(true, next);\n      \
    \      }\n          } else {\n            ordered_by_dfs.push(here);\n       \
    \   }\n        }\n      }\n\n      {\n        ::std::vector<bool> visited(this->size(),\
    \ false);\n        while (!ordered_by_dfs.empty()) {\n          const auto root\
    \ = ordered_by_dfs.top();\n          ordered_by_dfs.pop();\n          if (visited[root])\
    \ continue;\n\n          const auto scc_id = this->m_sccs.size();\n          this->m_sccs.emplace_back();\n\
    \          this->m_edges_in_scc.emplace_back();\n          this->m_scc_graph.emplace_back();\n\
    \          this->m_rev_scc_graph.emplace_back();\n\n          ::std::stack<::std::size_t>\
    \ stack({root});\n          while (!stack.empty()) {\n            const auto here\
    \ = stack.top();\n            stack.pop();\n            if (visited[here]) continue;\n\
    \            visited[here] = true;\n\n            this->m_vid2scc[here] = scc_id;\n\
    \            this->m_sccs[scc_id].push_back(here);\n\n            for (const auto\
    \ e : this->m_rev_graph[here]) {\n              const auto next = this->m_edges[e].first;\n\
    \              if (visited[next]) continue;\n              stack.push(next);\n\
    \            }\n          }\n\n          ::std::vector<::std::size_t> buffer;\
    \ \n          for (const auto v : this->m_sccs[scc_id]) {\n            for (const\
    \ auto e : this->m_rev_graph[v]) {\n              const auto u = this->m_edges[e].first;\n\
    \              if (this->m_vid2scc[u] == this->m_vid2scc[v]) {\n             \
    \   this->m_edges_in_scc[scc_id].push_back(e);\n              } else {\n     \
    \           buffer.push_back(e);\n              }\n            }\n          }\n\
    \n          ::std::sort(buffer.begin(), buffer.end(), tools::less_by([&](const\
    \ auto e) { return this->m_vid2scc[this->m_edges[e].first]; }));\n          for\
    \ (::std::size_t l = 0, r = 0; l < buffer.size(); l = r) {\n            const\
    \ auto u_scc_id = this->m_vid2scc[this->m_edges[buffer[l]].first];\n         \
    \   this->m_rev_scc_graph[scc_id].emplace_back(u_scc_id, ::std::vector<::std::size_t>());\n\
    \            for (; r < buffer.size() && this->m_vid2scc[this->m_edges[buffer[l]].first]\
    \ == this->m_vid2scc[this->m_edges[buffer[r]].first]; ++r);\n            for (::std::size_t\
    \ i = l; i < r; ++i) {\n              this->m_rev_scc_graph[scc_id].back().second.push_back(buffer[i]);\n\
    \            }\n          }\n        }\n\n        for (::std::size_t v_scc_id\
    \ = 0; v_scc_id < this->m_sccs.size(); ++v_scc_id) {\n          for (const auto&\
    \ [u_scc_id, edge_ids] : this->m_rev_scc_graph[v_scc_id]) {\n            this->m_scc_graph[u_scc_id].emplace_back(v_scc_id,\
    \ edge_ids);\n          }\n        }\n      }\n\n      this->m_built = true;\n\
    \    }\n\n    ::std::size_t scc_id(const ::std::size_t i) const {\n      assert(i\
    \ < this->size());\n      assert(this->m_built);\n      return this->m_vid2scc[i];\n\
    \    }\n    const ::std::vector<::std::vector<::std::size_t>>& sccs() const {\n\
    \      assert(this->m_built);\n      return this->m_sccs;\n    }\n    const ::std::vector<::std::size_t>&\
    \ edges_in_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_edges_in_scc[i];\n    }\n\
    \    const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_from_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_scc_graph[i];\n    }\n   \
    \ const ::std::vector<::std::pair<::std::size_t, ::std::vector<::std::size_t>>>&\
    \ edges_to_scc(const ::std::size_t i) const {\n      assert(i < this->m_sccs.size());\n\
    \      assert(this->m_built);\n      return this->m_rev_scc_graph[i];\n    }\n\
    \  };\n}\n\n\n#line 5 \"tests/scc_graph/sccs.test.cpp\"\n\nusing ll = long long;\n\
    \nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M;\n  std::cin >> N >> M;\n  tools::scc_graph graph(N);\n  for (ll i\
    \ = 0; i < M; ++i) {\n    ll a, b;\n    std::cin >> a >> b;\n    graph.add_edge(a,\
    \ b);\n  }\n\n  graph.build();\n\n  std::cout << graph.sccs().size() << '\\n';\n\
    \  for (const auto& scc : graph.sccs()) {\n    std::cout << scc.size();\n    for\
    \ (const auto v : scc) {\n      std::cout << ' ' << v;\n    }\n    std::cout <<\
    \ '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include \"tools/scc_graph.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll N, M;\n  std::cin >> N >> M;\n\
    \  tools::scc_graph graph(N);\n  for (ll i = 0; i < M; ++i) {\n    ll a, b;\n\
    \    std::cin >> a >> b;\n    graph.add_edge(a, b);\n  }\n\n  graph.build();\n\
    \n  std::cout << graph.sccs().size() << '\\n';\n  for (const auto& scc : graph.sccs())\
    \ {\n    std::cout << scc.size();\n    for (const auto v : scc) {\n      std::cout\
    \ << ' ' << v;\n    }\n    std::cout << '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/scc_graph.hpp
  - tools/less_by.hpp
  isVerificationFile: true
  path: tests/scc_graph/sccs.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/scc_graph/sccs.test.cpp
layout: document
redirect_from:
- /verify/tests/scc_graph/sccs.test.cpp
- /verify/tests/scc_graph/sccs.test.cpp.html
title: tests/scc_graph/sccs.test.cpp
---