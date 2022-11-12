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
    PROBLEM: https://atcoder.jp/contests/abc137/tasks/abc137_e
    links:
    - https://atcoder.jp/contests/abc137/tasks/abc137_e
  bundledCode: "#line 1 \"tests/bellman_ford.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc137/tasks/abc137_e\"\
    \n\n#include <iostream>\n#include <limits>\n#include <algorithm>\n#line 1 \"tools/bellman_ford.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <vector>\n#include <cassert>\n#include <utility>\n\
    #line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs)\
    \ {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n\n#line 10 \"tools/bellman_ford.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename T>\n  class bellman_ford {\n  public:\n    struct\
    \ edge {\n      ::std::size_t id;\n      ::std::size_t from;\n      ::std::size_t\
    \ to;\n      T cost;\n    };\n\n  private:\n    ::std::size_t m_size;\n    ::std::vector<edge>\
    \ m_edges;\n\n  public:\n    bellman_ford() = default;\n    bellman_ford(const\
    \ ::tools::bellman_ford<T>&) = default;\n    bellman_ford(::tools::bellman_ford<T>&&)\
    \ = default;\n    ~bellman_ford() = default;\n    ::tools::bellman_ford<T>& operator=(const\
    \ ::tools::bellman_ford<T>&) = default;\n    ::tools::bellman_ford<T>& operator=(::tools::bellman_ford<T>&&)\
    \ = default;\n\n    bellman_ford(const ::std::size_t n) : m_size(n) {\n    }\n\
    \n    ::std::size_t size() const {\n      return this->m_size;\n    }\n\n    ::std::size_t\
    \ add_edge(const ::std::size_t u, const ::std::size_t v, const T& w) {\n     \
    \ assert(u < this->size());\n      assert(v < this->size());\n      this->m_edges.push_back(edge({this->m_edges.size(),\
    \ u, v, w}));\n      return this->m_edges.size() - 1;\n    }\n\n    const edge&\
    \ get_edge(const ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n\
    \      return this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges()\
    \ const {\n      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>,\
    \ ::std::vector<::std::size_t>> query(const ::std::size_t s) {\n      assert(s\
    \ < this->size());\n\n      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());\n\
    \      dist[s] = 0;\n      ::std::vector<::std::size_t> prev(this->size());\n\
    \      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\n      for (::std::size_t\
    \ i = 0; i + 1 < this->size(); ++i) {\n        for (const auto& edge : this->m_edges)\
    \ {\n          if (dist[edge.from] < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to],\
    \ dist[edge.from] + edge.cost)) {\n            prev[edge.to] = edge.id;\n    \
    \      }\n        }\n      }\n      for (const auto& edge : this->m_edges) {\n\
    \        if (dist[edge.from] < ::std::numeric_limits<T>::max() && dist[edge.from]\
    \ + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost : 0) < dist[edge.to])\
    \ {\n          dist[edge.to] = ::std::numeric_limits<T>::min();\n          prev[edge.to]\
    \ = edge.id;\n        }\n      }\n      for (::std::size_t i = 0; i + 1 < this->size();\
    \ ++i) {\n        for (const auto& edge : this->m_edges) {\n          if (dist[edge.from]\
    \ < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to], dist[edge.from]\
    \ + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost : 0))) {\n\
    \            prev[edge.to] = edge.id;\n          }\n        }\n      }\n\n   \
    \   return ::std::make_pair(dist, prev);\n    }\n  };\n}\n\n\n#line 7 \"tests/bellman_ford.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M, P;\n  std::cin >> N >> M >> P;\n  tools::bellman_ford<ll> graph(N);\n\
    \  for (ll i = 0; i < M; ++i) {\n    ll A, B, C;\n    std::cin >> A >> B >> C;\n\
    \    --A, --B;\n    graph.add_edge(A, B, -C + P);\n  }\n\n  const auto [dist,\
    \ prev] = graph.query(0);\n  if (dist[N - 1] == std::numeric_limits<ll>::min())\
    \ {\n    std::cout << -1 << '\\n';\n  } else {\n    std::cout << std::max<ll>(0,\
    \ -dist[N - 1]) << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc137/tasks/abc137_e\"\n\n\
    #include <iostream>\n#include <limits>\n#include <algorithm>\n#include \"tools/bellman_ford.hpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, M, P;\n  std::cin >> N >> M >> P;\n  tools::bellman_ford<ll> graph(N);\n\
    \  for (ll i = 0; i < M; ++i) {\n    ll A, B, C;\n    std::cin >> A >> B >> C;\n\
    \    --A, --B;\n    graph.add_edge(A, B, -C + P);\n  }\n\n  const auto [dist,\
    \ prev] = graph.query(0);\n  if (dist[N - 1] == std::numeric_limits<ll>::min())\
    \ {\n    std::cout << -1 << '\\n';\n  } else {\n    std::cout << std::max<ll>(0,\
    \ -dist[N - 1]) << '\\n';\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - tools/bellman_ford.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/tests/bellman_ford.test.cpp
- /verify/tests/bellman_ford.test.cpp.html
title: tests/bellman_ford.test.cpp
---
