---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/zero_one_bfs.hpp
    title: 01-BFS
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/2945
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/2945
  bundledCode: "#line 1 \"tests/zero_one_bfs/directed.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/2945\"\n\n#include <iostream>\n\
    #include <array>\n#include <utility>\n#include <tuple>\n#line 1 \"tools/zero_one_bfs.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <vector>\n#include <cassert>\n#line 8 \"\
    tools/zero_one_bfs.hpp\"\n#include <algorithm>\n#include <limits>\n#include <deque>\n\
    #line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace tools\
    \ {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N& rhs)\
    \ {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n    return\
    \ updated;\n  }\n}\n\n\n#line 12 \"tools/zero_one_bfs.hpp\"\n\nnamespace tools\
    \ {\n\n  template <bool Directed, typename T>\n  class zero_one_bfs {\n  public:\n\
    \    struct edge {\n      ::std::size_t id;\n      ::std::size_t from;\n     \
    \ ::std::size_t to;\n      T cost;\n    };\n\n  private:\n    ::std::vector<edge>\
    \ m_edges;\n    ::std::vector<::std::vector<::std::size_t>> m_graph;\n\n  public:\n\
    \    zero_one_bfs() = default;\n    zero_one_bfs(const ::tools::zero_one_bfs<Directed,\
    \ T>&) = default;\n    zero_one_bfs(::tools::zero_one_bfs<Directed, T>&&) = default;\n\
    \    ~zero_one_bfs() = default;\n    ::tools::zero_one_bfs<Directed, T>& operator=(const\
    \ ::tools::zero_one_bfs<Directed, T>&) = default;\n    ::tools::zero_one_bfs<Directed,\
    \ T>& operator=(::tools::zero_one_bfs<Directed, T>&&) = default;\n\n    explicit\
    \ zero_one_bfs(const ::std::size_t n) : m_graph(n) {\n    }\n\n    ::std::size_t\
    \ size() const {\n      return this->m_graph.size();\n    }\n\n    ::std::size_t\
    \ add_edge(::std::size_t u, ::std::size_t v, const T& w) {\n      assert(u < this->size());\n\
    \      assert(v < this->size());\n      assert(w == 0 || w == 1);\n      if constexpr\
    \ (!Directed) {\n        ::std::tie(u, v) = ::std::minmax({u, v});\n      }\n\
    \      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));\n     \
    \ this->m_graph[u].push_back(this->m_edges.size() - 1);\n      if constexpr (!Directed)\
    \ {\n        this->m_graph[v].push_back(this->m_edges.size() - 1);\n      }\n\
    \      return this->m_edges.size() - 1;\n    }\n\n    const edge& get_edge(const\
    \ ::std::size_t k) const {\n      assert(k < this->m_edges.size());\n      return\
    \ this->m_edges[k];\n    }\n\n    const ::std::vector<edge>& edges() const {\n\
    \      return this->m_edges;\n    }\n\n    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>>\
    \ query(const ::std::size_t s) {\n      assert(s < this->size());\n\n      ::std::vector<T>\
    \ dist(this->size(), ::std::numeric_limits<T>::max());\n      dist[s] = 0;\n \
    \     ::std::vector<::std::size_t> prev(this->size());\n      prev[s] = ::std::numeric_limits<::std::size_t>::max();\n\
    \      ::std::deque<::std::pair<::std::size_t, T>> deque;\n      deque.emplace_front(s,\
    \ 0);\n\n      while (!deque.empty()) {\n        const auto [here, d] = deque.front();\n\
    \        deque.pop_front();\n        if (dist[here] < d) continue;\n        for\
    \ (const auto edge_id : this->m_graph[here]) {\n          const auto& edge = this->m_edges[edge_id];\n\
    \          const auto next = edge.to ^ (Directed ? 0 : edge.from ^ here);\n  \
    \        if (::tools::chmin(dist[next], dist[here] + edge.cost)) {\n         \
    \   prev[next] = edge.id;\n            if (edge.cost == 0) {\n              deque.emplace_front(next,\
    \ dist[next]);\n            } else {\n              deque.emplace_back(next, dist[next]);\n\
    \            }\n          }\n        }\n      }\n\n      return ::std::make_pair(dist,\
    \ prev);\n    }\n  };\n}\n\n\n#line 8 \"tests/zero_one_bfs/directed.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  const auto P = [](const ll x, const ll y) {\n    return 100 * y + x;\n  };\n\
    \  for (ll N; std::cin >> N, N > 0;) {\n    ll A, B, C, D;\n    std::cin >> A\
    \ >> B >> C >> D;\n    --A, --B;\n    tools::zero_one_bfs<true, ll> graph(100\
    \ * 100);\n    for (ll x = 0; x < 100; ++x) {\n      for (ll y = 0; y < 100; ++y)\
    \ {\n        for (const auto& [dx, dy] : std::array<std::pair<ll, ll>, 4>({std::make_pair(1,\
    \ 0), std::make_pair(-1, 0), std::make_pair(0, 1), std::make_pair(0, -1)})) {\n\
    \          if (0 <= x + dx && x + dx < 100 && 0 <= y + dy && y + dy < 100) {\n\
    \            graph.add_edge(P(x, y), P(x + dx, y + dy), A <= x + dx && x + dx\
    \ < C && B <= y + dy && y + dy < D ? 0 : 1);\n          }\n        }\n      }\n\
    \    }\n\n    ll answer = 0;\n    ll pX, pY;\n    std::cin >> pX >> pY;\n    --pX,\
    \ --pY;\n    for (ll i = 0; i < N; ++i) {\n      ll X, Y;\n      std::cin >> X\
    \ >> Y;\n      --X, --Y;\n      answer += graph.query(P(pX, pY)).first[P(X, Y)];\n\
    \      std::tie(pX, pY) = std::make_pair(X, Y);\n    }\n\n    std::cout << answer\
    \ << '\\n';\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/2945\"\n\n#include\
    \ <iostream>\n#include <array>\n#include <utility>\n#include <tuple>\n#include\
    \ \"tools/zero_one_bfs.hpp\"\n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n\
    \  std::ios_base::sync_with_stdio(false);\n\n  const auto P = [](const ll x, const\
    \ ll y) {\n    return 100 * y + x;\n  };\n  for (ll N; std::cin >> N, N > 0;)\
    \ {\n    ll A, B, C, D;\n    std::cin >> A >> B >> C >> D;\n    --A, --B;\n  \
    \  tools::zero_one_bfs<true, ll> graph(100 * 100);\n    for (ll x = 0; x < 100;\
    \ ++x) {\n      for (ll y = 0; y < 100; ++y) {\n        for (const auto& [dx,\
    \ dy] : std::array<std::pair<ll, ll>, 4>({std::make_pair(1, 0), std::make_pair(-1,\
    \ 0), std::make_pair(0, 1), std::make_pair(0, -1)})) {\n          if (0 <= x +\
    \ dx && x + dx < 100 && 0 <= y + dy && y + dy < 100) {\n            graph.add_edge(P(x,\
    \ y), P(x + dx, y + dy), A <= x + dx && x + dx < C && B <= y + dy && y + dy <\
    \ D ? 0 : 1);\n          }\n        }\n      }\n    }\n\n    ll answer = 0;\n\
    \    ll pX, pY;\n    std::cin >> pX >> pY;\n    --pX, --pY;\n    for (ll i = 0;\
    \ i < N; ++i) {\n      ll X, Y;\n      std::cin >> X >> Y;\n      --X, --Y;\n\
    \      answer += graph.query(P(pX, pY)).first[P(X, Y)];\n      std::tie(pX, pY)\
    \ = std::make_pair(X, Y);\n    }\n\n    std::cout << answer << '\\n';\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - tools/zero_one_bfs.hpp
  - tools/chmin.hpp
  isVerificationFile: true
  path: tests/zero_one_bfs/directed.test.cpp
  requiredBy: []
  timestamp: '2024-02-18 13:45:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/zero_one_bfs/directed.test.cpp
layout: document
redirect_from:
- /verify/tests/zero_one_bfs/directed.test.cpp
- /verify/tests/zero_one_bfs/directed.test.cpp.html
title: tests/zero_one_bfs/directed.test.cpp
---
