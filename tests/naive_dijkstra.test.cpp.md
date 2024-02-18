---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/less_by.hpp
    title: std::less by key
  - icon: ':heavy_check_mark:'
    path: tools/naive_dijkstra.hpp
    title: Dijkstra's algorithm for dense graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc325/tasks/abc325_e
    links:
    - https://atcoder.jp/contests/abc325/tasks/abc325_e
  bundledCode: "#line 1 \"tests/naive_dijkstra.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc325/tasks/abc325_e\"\
    \n\n#include <iostream>\n#include <vector>\n#include <limits>\n#line 1 \"tools/naive_dijkstra.hpp\"\
    \n\n\n\n#include <cstddef>\n#line 7 \"tools/naive_dijkstra.hpp\"\n#include <cassert>\n\
    #include <utility>\n#include <algorithm>\n#include <numeric>\n#include <iterator>\n\
    #line 1 \"tools/less_by.hpp\"\n\n\n\nnamespace tools {\n\n  template <class F>\n\
    \  class less_by {\n  private:\n    F selector;\n\n  public:\n    less_by(const\
    \ F& selector) : selector(selector) {\n    }\n\n    template <class T>\n    bool\
    \ operator()(const T& x, const T& y) const {\n      return selector(x) < selector(y);\n\
    \    }\n  };\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\
    \n\nnamespace tools {\n\n  template <typename M, typename N>\n  bool chmin(M&\
    \ lhs, const N& rhs) {\n    const bool updated = lhs > rhs;\n    if (updated)\
    \ lhs = rhs;\n    return updated;\n  }\n}\n\n\n#line 14 \"tools/naive_dijkstra.hpp\"\
    \n\nnamespace tools {\n\n  template <bool Directed, typename T>\n  class naive_dijkstra\
    \ {\n  public:\n    struct edge {\n      ::std::size_t id;\n      ::std::size_t\
    \ from;\n      ::std::size_t to;\n      T cost;\n    };\n\n  private:\n    ::std::size_t\
    \ m_size;\n    ::std::vector<edge> m_edges;\n    ::std::vector<::std::size_t>\
    \ m_graph;\n\n  public:\n    naive_dijkstra() = default;\n    naive_dijkstra(const\
    \ ::tools::naive_dijkstra<Directed, T>&) = default;\n    naive_dijkstra(::tools::naive_dijkstra<Directed,\
    \ T>&&) = default;\n    ~naive_dijkstra() = default;\n    ::tools::naive_dijkstra<Directed,\
    \ T>& operator=(const ::tools::naive_dijkstra<Directed, T>&) = default;\n    ::tools::naive_dijkstra<Directed,\
    \ T>& operator=(::tools::naive_dijkstra<Directed, T>&&) = default;\n\n    explicit\
    \ naive_dijkstra(const ::std::size_t n) : m_size(n), m_graph(n * n, ::std::numeric_limits<::std::size_t>::max())\
    \ {\n    }\n\n    ::std::size_t size() const {\n      return this->m_size;\n \
    \   }\n\n    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T&\
    \ w) {\n      assert(u < this->size());\n      assert(v < this->size());\n   \
    \   assert(w >= 0);\n      if constexpr (!Directed) {\n        ::std::tie(u, v)\
    \ = ::std::minmax({u, v});\n      }\n      this->m_edges.push_back(edge{this->m_edges.size(),\
    \ u, v, w});\n      if (this->m_graph[u * this->size() + v] == ::std::numeric_limits<::std::size_t>::max()\
    \ || w < this->m_edges[this->m_graph[u * this->size() + v]].cost) {\n        this->m_graph[u\
    \ * this->size() + v] = this->m_edges.size() - 1;\n        if constexpr (!Directed)\
    \ {\n            this->m_graph[v * this->size() + u] = this->m_edges.size() -\
    \ 1;\n        }\n      }\n      return this->m_edges.size() - 1;\n    }\n\n  \
    \  const edge& get_edge(const ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n\
    \      return this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges()\
    \ const {\n      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>,\
    \ ::std::vector<::std::size_t>> query(const ::std::size_t s) {\n      assert(s\
    \ < this->size());\n\n      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());\n\
    \      dist[s] = 0;\n      ::std::vector<::std::size_t> prev(this->size());\n\
    \      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\n      ::std::vector<::std::size_t>\
    \ Q(this->size());\n      ::std::iota(Q.begin(), Q.end(), 0);\n      while (!Q.empty())\
    \ {\n        const auto min_it = ::std::min_element(Q.begin(), Q.end(), ::tools::less_by([&](const\
    \ auto v) { return dist[v]; }));\n        const auto here = *min_it;\n       \
    \ if (dist[here] == ::std::numeric_limits<T>::max()) break;\n\n        ::std::iter_swap(min_it,\
    \ ::std::prev(Q.end()));\n        Q.pop_back();\n\n        for (const auto next\
    \ : Q) {\n          if (this->m_graph[here * this->size() + next] != ::std::numeric_limits<::std::size_t>::max()\
    \ && ::tools::chmin(dist[next], dist[here] + this->m_edges[this->m_graph[here\
    \ * this->size() + next]].cost)) {\n            prev[next] = this->m_graph[here\
    \ * this->size() + next];\n          }\n        }\n      }\n\n      return ::std::make_pair(dist,\
    \ prev);\n    }\n  };\n}\n\n\n#line 8 \"tests/naive_dijkstra.test.cpp\"\n\nusing\
    \ ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N, A, B, C;\n  std::cin >> N >> A >> B >> C;\n  auto D = std::vector(N,\
    \ std::vector<ll>(N));\n  for (auto& D_i : D) for (auto& D_ij : D_i) std::cin\
    \ >> D_ij;\n\n  tools::naive_dijkstra<true, ll> graph1(N);\n  tools::naive_dijkstra<true,\
    \ ll> graph2(N);\n  for (ll i = 0; i < N; ++i) {\n    for (ll j = 0; j < N; ++j)\
    \ {\n      graph1.add_edge(i, j, D[i][j] * A);\n      graph2.add_edge(i, j, D[j][i]\
    \ * B + C);\n    }\n  }\n\n  const auto dist1 = graph1.query(0).first;\n  const\
    \ auto dist2 = graph2.query(N - 1).first;\n  ll answer = std::numeric_limits<ll>::max();\n\
    \  for (ll i = 0; i < N; ++i) {\n    tools::chmin(answer, dist1[i] + dist2[i]);\n\
    \  }\n  std::cout << answer << '\\n';\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc325/tasks/abc325_e\"\n\n\
    #include <iostream>\n#include <vector>\n#include <limits>\n#include \"tools/naive_dijkstra.hpp\"\
    \n#include \"tools/chmin.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  ll N, A, B, C;\n  std::cin >> N\
    \ >> A >> B >> C;\n  auto D = std::vector(N, std::vector<ll>(N));\n  for (auto&\
    \ D_i : D) for (auto& D_ij : D_i) std::cin >> D_ij;\n\n  tools::naive_dijkstra<true,\
    \ ll> graph1(N);\n  tools::naive_dijkstra<true, ll> graph2(N);\n  for (ll i =\
    \ 0; i < N; ++i) {\n    for (ll j = 0; j < N; ++j) {\n      graph1.add_edge(i,\
    \ j, D[i][j] * A);\n      graph2.add_edge(i, j, D[j][i] * B + C);\n    }\n  }\n\
    \n  const auto dist1 = graph1.query(0).first;\n  const auto dist2 = graph2.query(N\
    \ - 1).first;\n  ll answer = std::numeric_limits<ll>::max();\n  for (ll i = 0;\
    \ i < N; ++i) {\n    tools::chmin(answer, dist1[i] + dist2[i]);\n  }\n  std::cout\
    \ << answer << '\\n';\n\n  return 0;\n}\n"
  dependsOn:
  - tools/naive_dijkstra.hpp
  - tools/less_by.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/naive_dijkstra.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/naive_dijkstra.test.cpp
layout: document
redirect_from:
- /verify/tests/naive_dijkstra.test.cpp
- /verify/tests/naive_dijkstra.test.cpp.html
title: tests/naive_dijkstra.test.cpp
---
