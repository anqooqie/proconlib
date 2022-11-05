---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/greater_by.hpp
    title: std::greater by key
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
  bundledCode: "#line 1 \"tests/prim/basic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\
    \n\n#include <iostream>\n#line 1 \"tools/prim.hpp\"\n\n\n\n#include <cstddef>\n\
    #include <vector>\n#include <cassert>\n#include <utility>\n#include <algorithm>\n\
    #include <limits>\n#include <queue>\n#line 1 \"tools/greater_by.hpp\"\n\n\n\n\
    namespace tools {\n\n  template <class F>\n  class greater_by {\n  private:\n\
    \    F selector;\n\n  public:\n    greater_by(const F& selector) : selector(selector)\
    \ {\n    }\n\n    template <class T>\n    bool operator()(const T& x, const T&\
    \ y) const {\n      return selector(x) > selector(y);\n    }\n  };\n}\n\n\n#line\
    \ 12 \"tools/prim.hpp\"\n\nnamespace tools {\n\n  template <typename T>\n  class\
    \ prim {\n  public:\n    struct edge {\n      ::std::size_t id;\n      ::std::size_t\
    \ from;\n      ::std::size_t to;\n      T cost;\n    };\n\n  private:\n    ::std::vector<edge>\
    \ m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n\
    \    prim() = default;\n    prim(const ::tools::prim<T>&) = default;\n    prim(::tools::prim<T>&&)\
    \ = default;\n    ~prim() = default;\n    ::tools::prim<T>& operator=(const ::tools::prim<T>&)\
    \ = default;\n    ::tools::prim<T>& operator=(::tools::prim<T>&&) = default;\n\
    \n    prim(const ::std::size_t n) : m_graph(n) {\n    }\n\n    ::std::size_t size()\
    \ const {\n      return this->m_graph.size();\n    }\n\n    ::std::size_t add_edge(::std::size_t\
    \ u, ::std::size_t v, const T w) {\n      assert(u < this->size());\n      assert(v\
    \ < this->size());\n      ::std::tie(u, v) = ::std::minmax({u, v});\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      this->m_graph[u].push_back(this->m_edges.size() - 1);\n \
    \     this->m_graph[v].push_back(this->m_edges.size() - 1);\n      return this->m_edges.size()\
    \ - 1;\n    }\n\n    const edge& get_edge(const ::std::size_t k) const {\n   \
    \   assert(k < this->m_edges.size());\n      return this->m_edges[k];\n    }\n\
    \n    const ::std::vector<edge>& edges() const {\n      return this->m_edges;\n\
    \    }\n\n    ::std::pair<::std::vector<::std::pair<T, ::std::vector<::std::size_t>>>,\
    \ ::std::vector<::std::size_t>> query() const {\n      ::std::pair<::std::vector<::std::pair<T,\
    \ ::std::vector<::std::size_t>>>, ::std::vector<::std::size_t>> res;\n      auto&\
    \ [groups, belongs_to] = res;\n      belongs_to.resize(this->size());\n      ::std::fill(belongs_to.begin(),\
    \ belongs_to.end(), ::std::numeric_limits<::std::size_t>::max());\n\n      for\
    \ (::std::size_t root = 0; root < this->size(); ++root) {\n        if (belongs_to[root]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n        const auto\
    \ greater_by_cost = ::tools::greater_by([&](const auto& pair) { return this->m_edges[pair.first].cost;\
    \ });\n        ::std::priority_queue<::std::pair<::std::size_t, ::std::size_t>,\
    \ ::std::vector<::std::pair<::std::size_t, ::std::size_t>>, decltype(greater_by_cost)>\
    \ pq(greater_by_cost);\n        groups.emplace_back(0, ::std::vector<::std::size_t>());\n\
    \        auto& [total_cost, edge_ids] = groups.back();\n\n        belongs_to[root]\
    \ = groups.size() - 1;\n        for (const auto e : this->m_graph[root]) {\n \
    \         const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ root;\n\
    \          if (belongs_to[next] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          pq.emplace(e, next);\n        }\n\n        while (!pq.empty())\
    \ {\n          const auto [from_edge_id, here] = pq.top();\n          pq.pop();\n\
    \n          if (belongs_to[here] < ::std::numeric_limits<::std::size_t>::max())\
    \ continue;\n\n          belongs_to[here] = belongs_to[root];\n          total_cost\
    \ += this->m_edges[from_edge_id].cost;\n          edge_ids.push_back(from_edge_id);\n\
    \          for (const auto e : this->m_graph[here]) {\n            const auto\
    \ next = this->m_edges[e].from ^ this->m_edges[e].to ^ here;\n            if (belongs_to[next]\
    \ < ::std::numeric_limits<::std::size_t>::max()) continue;\n\n            pq.emplace(e,\
    \ next);\n          }\n        }\n      }\n\n      return res;\n    }\n  };\n\
    }\n\n\n#line 5 \"tests/prim/basic.test.cpp\"\n\nusing ll = long long;\n\nint main()\
    \ {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\n  ll\
    \ V, E;\n  std::cin >> V >> E;\n  tools::prim<ll> prim(V);\n  for (ll i = 0; i\
    \ < E; ++i) {\n    ll s, t, w;\n    std::cin >> s >> t >> w;\n    prim.add_edge(s,\
    \ t, w);\n  }\n\n  std::cout << prim.query().first[0].first << '\\n';\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A\"\n\n\
    #include <iostream>\n#include \"tools/prim.hpp\"\n\nusing ll = long long;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll V, E;\n  std::cin >> V >> E;\n  tools::prim<ll> prim(V);\n  for (ll i =\
    \ 0; i < E; ++i) {\n    ll s, t, w;\n    std::cin >> s >> t >> w;\n    prim.add_edge(s,\
    \ t, w);\n  }\n\n  std::cout << prim.query().first[0].first << '\\n';\n  return\
    \ 0;\n}\n"
  dependsOn:
  - tools/prim.hpp
  - tools/greater_by.hpp
  isVerificationFile: true
  path: tests/prim/basic.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/prim/basic.test.cpp
layout: document
redirect_from:
- /verify/tests/prim/basic.test.cpp
- /verify/tests/prim/basic.test.cpp.html
title: tests/prim/basic.test.cpp
---