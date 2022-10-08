---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':question:'
    path: tools/greater_by_second.hpp
    title: std::greater by second
  - icon: ':x:'
    path: tools/mcf_graph.hpp
    title: Solver of minimum-cost flow problem
  - icon: ':question:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  - icon: ':x:'
    path: tools/weighted_bipartite_matching.hpp
    title: Matching on weighted bipartite graph
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc247/tasks/abc247_g
    links:
    - https://atcoder.jp/contests/abc247/tasks/abc247_g
  bundledCode: "#line 1 \"tests/weighted_bipartite_matching/multiple_calls.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc247/tasks/abc247_g\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <optional>\n#include <utility>\n#line\
    \ 1 \"tools/weighted_bipartite_matching.hpp\"\n\n\n\n#include <cstddef>\n#line\
    \ 8 \"tools/weighted_bipartite_matching.hpp\"\n#include <limits>\n#line 1 \"tools/mcf_graph.hpp\"\
    \n\n\n\n#line 7 \"tools/mcf_graph.hpp\"\n#include <cassert>\n#line 9 \"tools/mcf_graph.hpp\"\
    \n#include <numeric>\n#include <stack>\n#include <algorithm>\n#include <queue>\n\
    #line 1 \"tools/ssize.hpp\"\n\n\n\n#include <type_traits>\n#line 6 \"tools/ssize.hpp\"\
    \n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto ssize(const\
    \ C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line\
    \ 5 \"tools/chmin.hpp\"\n\nnamespace tools {\n\n  template <typename M, typename\
    \ N>\n  bool chmin(M& lhs, const N& rhs) {\n    const bool updated = lhs > rhs;\n\
    \    if (updated) lhs = rhs;\n    return updated;\n  }\n}\n\n\n#line 1 \"tools/greater_by_second.hpp\"\
    \n\n\n\n#line 5 \"tools/greater_by_second.hpp\"\n\nnamespace tools {\n\n  class\
    \ greater_by_second {\n  public:\n    template <class T1, class T2>\n    bool\
    \ operator()(const ::std::pair<T1, T2>& x, const ::std::pair<T1, T2>& y) const\
    \ {\n      return x.second > y.second;\n    }\n  };\n}\n\n\n#line 16 \"tools/mcf_graph.hpp\"\
    \n\nnamespace tools {\n  template <typename Cap, typename Cost>\n  class mcf_graph\
    \ {\n  public:\n    struct edge {\n      int from, to;\n      Cap cap, flow;\n\
    \      Cost cost;\n    };\n\n  private:\n    ::std::vector<::std::vector<int>>\
    \ m_graph;\n    ::std::vector<::tools::mcf_graph<Cap, Cost>::edge> m_edges;\n\
    \    ::std::vector<::std::pair<Cap, Cost>> m_slope;\n    ::std::vector<Cost> m_potentials;\n\
    \    bool m_filled_negative_cycles;\n    ::std::optional<bool> m_is_dag;\n   \
    \ bool m_calculated_potentials;\n\n    int size() const {\n      return this->m_graph.size();\n\
    \    }\n\n  public:\n    mcf_graph() = default;\n    mcf_graph(const ::tools::mcf_graph<Cap,\
    \ Cost>&) = default;\n    mcf_graph(::tools::mcf_graph<Cap, Cost>&&) = default;\n\
    \    ~mcf_graph() = default;\n    ::tools::mcf_graph<Cap, Cost>& operator=(const\
    \ ::tools::mcf_graph<Cap, Cost>&) = default;\n    ::tools::mcf_graph<Cap, Cost>&\
    \ operator=(::tools::mcf_graph<Cap, Cost>&&) = default;\n\n    explicit mcf_graph(const\
    \ int n) : m_graph(n), m_slope({::std::pair<Cap, Cost>(0, 0)}), m_potentials(n,\
    \ 0), m_filled_negative_cycles(false), m_calculated_potentials(false) {\n    }\n\
    \n    int add_edge(const int from, const int to, const Cap cap, const Cost cost)\
    \ {\n      assert(0 <= from && from < this->size());\n      assert(0 <= to &&\
    \ to < this->size());\n      assert(0 <= cap);\n      assert(cost != ::std::numeric_limits<Cost>::min());\n\
    \      assert(cost != ::std::numeric_limits<Cost>::max());\n\n      this->m_graph[from].push_back(this->m_edges.size());\n\
    \      this->m_edges.push_back(::tools::mcf_graph<Cap, Cost>::edge({from, to,\
    \ cap, 0, cost}));\n      this->m_graph[to].push_back(this->m_edges.size());\n\
    \      this->m_edges.push_back(::tools::mcf_graph<Cap, Cost>::edge({to, from,\
    \ cap, cap, -cost}));\n      return this->m_edges.size() / 2 - 1;\n    }\n\n \
    \ private:\n    void fill_negative_cycles() {\n      ::std::vector<::std::pair<::std::vector<int>,\
    \ ::std::vector<int>>> scc({::std::make_pair(::std::vector<int>(this->size()),\
    \ ::std::vector<int>(this->m_edges.size()))});\n      ::std::iota(scc[0].first.begin(),\
    \ scc[0].first.end(), 0);\n      ::std::iota(scc[0].second.begin(), scc[0].second.end(),\
    \ 0);\n      ::std::vector<int> scc_inv(this->size(), 0);\n      ::std::stack<int>\
    \ scc_stack({0});\n      ::std::vector<bool> will_visit(this->size());\n     \
    \ ::std::vector<Cost> dist(this->size());\n      ::std::vector<int> prev(this->size());\n\
    \n      // Loop until every strongly connected component contains no negative\
    \ cycles.\n      while (!scc_stack.empty()) {\n        const auto scc_id = scc_stack.top();\n\
    \        scc_stack.pop();\n        ::std::vector<int> scc_vertices;\n        ::std::vector<int>\
    \ scc_edge_ids;\n        scc_vertices.swap(scc[scc_id].first);\n        scc_edge_ids.swap(scc[scc_id].second);\n\
    \n        // scc[scc_id] might be decomposed into smaller strongly connected components,\
    \ so check and decompose it.\n        ::std::stack<int> ordered_by_dfs;\n    \
    \    for (const auto v : scc_vertices) {\n          will_visit[v] = false;\n \
    \       }\n        for (const auto root : scc_vertices) {\n          if (will_visit[root])\
    \ continue;\n\n          ::std::stack<::std::pair<bool, int>> stack;\n       \
    \   stack.emplace(true, root);\n          while (!stack.empty()) {\n         \
    \   const auto [pre, here] = stack.top();\n            stack.pop();\n        \
    \    if (pre) {\n              if (will_visit[here]) continue;\n             \
    \ will_visit[here] = true;\n              stack.emplace(false, here);\n      \
    \        for (const auto edge_id : this->m_graph[here]) {\n                const\
    \ auto& edge = this->m_edges[edge_id];\n                if (edge.flow < edge.cap\
    \ && !will_visit[edge.to]) {\n                  stack.emplace(true, edge.to);\n\
    \                }\n              }\n            } else {\n              ordered_by_dfs.push(here);\n\
    \            }\n          }\n        }\n\n        ::std::vector<int> new_scc_ids;\n\
    \        for (const auto v : scc_vertices) {\n          will_visit[v] = false;\n\
    \        }\n        while (!ordered_by_dfs.empty()) {\n          const auto root\
    \ = ordered_by_dfs.top();\n          ordered_by_dfs.pop();\n          if (will_visit[root])\
    \ continue;\n\n          if (new_scc_ids.empty()) {\n            new_scc_ids.push_back(scc_id);\n\
    \          } else {\n            new_scc_ids.push_back(scc.size());\n        \
    \    scc.emplace_back();\n          }\n\n          ::std::stack<int> stack({root});\n\
    \          will_visit[root] = true;\n          while (!stack.empty()) {\n    \
    \        const auto here = stack.top();\n            stack.pop();\n\n        \
    \    scc[new_scc_ids.back()].first.emplace_back();\n            scc_inv[here]\
    \ = new_scc_ids.back();\n\n            for (const auto edge_id : this->m_graph[here])\
    \ {\n              const auto& edge = this->m_edges[edge_id];\n              const\
    \ auto& rev = this->m_edges[edge_id ^ 1];\n              if (rev.flow < rev.cap\
    \ && !will_visit[edge.to]) {\n                stack.push(edge.to);\n         \
    \       will_visit[edge.to] = true;\n              }\n            }\n        \
    \  }\n        }\n\n        for (const auto edge_id : scc_edge_ids) {\n       \
    \   const auto& edge = this->m_edges[edge_id];\n          if (scc_inv[edge.from]\
    \ == scc_inv[edge.to]) {\n            scc[scc_inv[edge.from]].second.push_back(edge_id);\n\
    \          }\n        }\n\n        // Now, scc[new_scc_id] is truly a strongly\
    \ connected component.\n        // Check whether it contains any negative cycles\
    \ using Bellman-Ford algorithm.\n        for (const auto new_scc_id : new_scc_ids)\
    \ {\n          const auto& [new_scc_vertices, new_scc_edge_ids] = scc[new_scc_id];\n\
    \          for (const auto v : new_scc_vertices) {\n            dist[v] = ::std::numeric_limits<Cost>::max();\n\
    \            prev[v] = -1;\n          }\n          dist[new_scc_vertices[0]] =\
    \ 0;\n          for (int i = 0; i < ::tools::ssize(new_scc_vertices) - 1; ++i)\
    \ {\n            for (const auto edge_id : new_scc_edge_ids) {\n             \
    \ const auto& edge = this->m_edges[edge_id];\n              if (edge.flow < edge.cap\
    \ && dist[edge.from] < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dist[edge.to],\
    \ dist[edge.from] + edge.cost)) {\n                prev[edge.to] = edge_id;\n\
    \              }\n            }\n          }\n\n          for (const auto edge_id\
    \ : new_scc_edge_ids) {\n            auto& edge = this->m_edges[edge_id];\n  \
    \          auto& rev = this->m_edges[edge_id ^ 1];\n            if (edge.flow\
    \ < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dist[edge.to],\
    \ dist[edge.from] + edge.cost)) {\n              // We found a negative cycle,\
    \ so fill it.\n              // Later, we will check whether the component can\
    \ be decomposed into smaller ones.  \n\n              Cap cap = edge.cap - edge.flow;\n\
    \              for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from)\
    \ {\n                const auto& current_edge = this->m_edges[prev[v]];\n    \
    \            ::tools::chmin(cap, current_edge.cap - current_edge.flow);\n    \
    \          }\n\n              edge.flow += cap;\n              rev.flow -= cap;\n\
    \              this->m_slope.back().second += cap * edge.cost;\n             \
    \ for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from) {\n \
    \               auto& current_edge = this->m_edges[prev[v]];\n               \
    \ auto& current_rev = this->m_edges[prev[v] ^ 1];\n                current_edge.flow\
    \ += cap;\n                current_rev.flow -= cap;\n                this->m_slope.back().second\
    \ += cap * current_edge.cost;\n              }\n\n              scc_stack.push(new_scc_id);\n\
    \              break;\n            }\n          }\n        }\n      }\n\n    \
    \  this->m_is_dag = ::std::all_of(scc.begin(), scc.end(), [](const auto& pair)\
    \ { return pair.first.size() == 1; });\n    }\n\n    // This is for the first\
    \ try to find the shortest path in a DAG with some negative edges.\n    // We\
    \ use topological sorting + DP. (O(V + E) time)\n    ::std::pair<::std::vector<Cost>,\
    \ ::std::vector<int>> find_shortest_path_by_dp(const int s) {\n      ::std::vector<Cost>\
    \ dist(this->size(), ::std::numeric_limits<Cost>::max());\n      ::std::vector<int>\
    \ prev(this->size(), -1);\n\n      ::std::vector<int> indeg(this->size(), 0);\n\
    \      for (const auto& edge : this->m_edges) {\n        if (edge.flow < edge.cap)\
    \ {\n          ++indeg[edge.to];\n        }\n      }\n      ::std::queue<int>\
    \ queue;\n      for (int v = 0; v < this->size(); ++v) {\n        if (indeg[v]\
    \ == 0) {\n          queue.push(v);\n        }\n      }\n      dist[s] = 0;\n\
    \      while (!queue.empty()) {\n        const auto here = queue.front();\n  \
    \      queue.pop();\n        for (const auto edge_id : this->m_graph[here]) {\n\
    \          const auto& edge = this->m_edges[edge_id];\n          if (edge.flow\
    \ < edge.cap) {\n            if (dist[edge.from] < ::std::numeric_limits<Cost>::max()\
    \ && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {\n         \
    \     prev[edge.to] = edge_id;\n            }\n            --indeg[edge.to];\n\
    \            if (indeg[edge.to] == 0) {\n              queue.push(edge.to);\n\
    \            }\n          }\n        }\n      }\n\n      return ::std::make_pair(dist,\
    \ prev);\n    }\n\n    // This is for the first try to find the shortest path\
    \ in a graph with some negative edges and some non-negative cycles.\n    // We\
    \ use Bellman-Ford algorithm. (O(VE) time)\n    ::std::pair<::std::vector<Cost>,\
    \ ::std::vector<int>> find_shortest_path_by_bellman_ford(const int s) {\n    \
    \  ::std::vector<Cost> dist(this->size(), ::std::numeric_limits<Cost>::max());\n\
    \      ::std::vector<int> prev(this->size(), -1);\n\n      dist[s] = 0;\n    \
    \  for (int i = 0; i < this->size() - 1; ++i) {\n        for (int edge_id = 0;\
    \ edge_id < ::tools::ssize(this->m_edges); ++edge_id) {\n          const auto&\
    \ edge = this->m_edges[edge_id];\n          if (edge.flow < edge.cap && dist[edge.from]\
    \ < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dist[edge.to], dist[edge.from]\
    \ + edge.cost)) {\n            prev[edge.to] = edge_id;\n          }\n       \
    \ }\n      }\n      #ifndef NDEBUG\n        for (const auto& edge : this->m_edges)\
    \ {\n          if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max())\
    \ {\n            assert(dist[edge.to] <= dist[edge.from] + edge.cost);\n     \
    \     }\n        }\n      #endif\n\n      return ::std::make_pair(dist, prev);\n\
    \    }\n\n    // This is for finding the shortest path in a graph without negative\
    \ edges.\n    // We use Dijkstra's algorithm with potentials. (O((V + E) logV)\
    \ time)\n    ::std::pair<::std::vector<Cost>, ::std::vector<int>> find_shortest_path_by_dijkstra(const\
    \ int s) {\n      ::std::vector<Cost> dist(this->size(), ::std::numeric_limits<Cost>::max());\n\
    \      ::std::vector<int> prev(this->size(), -1);\n\n      #ifndef NDEBUG\n  \
    \      for (const auto& edge : this->m_edges) {\n          if (edge.flow < edge.cap\
    \ && this->m_potentials[edge.from] < ::std::numeric_limits<Cost>::max() && this->m_potentials[edge.to]\
    \ < ::std::numeric_limits<Cost>::max()) {\n            assert(edge.cost + (this->m_potentials[edge.from]\
    \ - this->m_potentials[edge.to]) >= 0);\n          }\n        }\n      #endif\n\
    \      dist[s] = 0;\n      ::std::priority_queue<::std::pair<int, Cost>, ::std::vector<::std::pair<int,\
    \ Cost>>, ::tools::greater_by_second> tasks;\n      tasks.emplace(s, 0);\n   \
    \   while (!tasks.empty()) {\n        const auto [here, d] = tasks.top();\n  \
    \      tasks.pop();\n        if (dist[here] < d) continue;\n        for (const\
    \ auto edge_id : this->m_graph[here]) {\n          const auto& edge = this->m_edges[edge_id];\n\
    \          if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max())\
    \ {\n            assert(this->m_potentials[edge.from] < ::std::numeric_limits<Cost>::max());\n\
    \            assert(this->m_potentials[edge.to] < ::std::numeric_limits<Cost>::max());\n\
    \            if (::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost + (this->m_potentials[edge.from]\
    \ - this->m_potentials[edge.to]))) {\n              prev[edge.to] = edge_id;\n\
    \              tasks.emplace(edge.to, dist[edge.to]);\n            }\n       \
    \   }\n        }\n      }\n\n      return ::std::make_pair(dist, prev);\n    }\n\
    \n  public:\n    ::std::vector<::std::pair<Cap, Cost>> slope(const int s, const\
    \ int t, const Cap flow_limit) {\n      assert(0 <= s && s < this->size());\n\
    \      assert(0 <= t && t < this->size());\n      assert(s != t);\n      assert(this->m_slope.back().first\
    \ <= flow_limit);\n\n      if (!this->m_filled_negative_cycles) {\n        this->fill_negative_cycles();\n\
    \        this->m_filled_negative_cycles = true;\n      }\n      while (this->m_slope.back().first\
    \ < flow_limit) {\n        ::std::vector<Cost> dist;\n        ::std::vector<int>\
    \ prev;\n\n        if (!this->m_calculated_potentials) {\n          const bool\
    \ has_negative_edge = ::std::any_of(this->m_edges.begin(), this->m_edges.end(),\
    \ [](const auto& edge) { return edge.flow < edge.cap && edge.cost < 0; });\n \
    \         if (has_negative_edge) {\n            if (*this->m_is_dag) {\n     \
    \         ::std::tie(dist, prev) = this->find_shortest_path_by_dp(s);\n      \
    \      } else {\n              ::std::tie(dist, prev) = this->find_shortest_path_by_bellman_ford(s);\n\
    \            }\n          } else {\n            ::std::tie(dist, prev) = this->find_shortest_path_by_dijkstra(s);\n\
    \          }\n        } else {\n          ::std::tie(dist, prev) = this->find_shortest_path_by_dijkstra(s);\n\
    \        }\n\n        if (dist[t] == ::std::numeric_limits<Cost>::max()) break;\n\
    \n        for (int i = 0; i < this->size(); ++i) {\n          if (dist[i] < ::std::numeric_limits<Cost>::max())\
    \ {\n            this->m_potentials[i] += dist[i];\n          } else {\n     \
    \       this->m_potentials[i] = ::std::numeric_limits<Cost>::max();\n        \
    \  }\n        }\n        this->m_calculated_potentials = true;\n        this->m_is_dag\
    \ = ::std::nullopt;\n\n        // Fill the shortest path.\n        Cap cap = flow_limit\
    \ - this->m_slope.back().first;\n        for (int v = t; v != s; v = this->m_edges[prev[v]].from)\
    \ {\n          const auto& edge = this->m_edges[prev[v]];\n          ::tools::chmin(cap,\
    \ edge.cap - edge.flow);\n        }\n\n        Cost cost = 0;\n        for (int\
    \ v = t; v != s; v = this->m_edges[prev[v]].from) {\n          auto& edge = this->m_edges[prev[v]];\n\
    \          auto& rev = this->m_edges[prev[v] ^ 1];\n          edge.flow += cap;\n\
    \          rev.flow -= cap;\n          cost += cap * edge.cost;\n        }\n\n\
    \        if ([&]() {\n          if (this->m_slope.size() < 2) return true;\n \
    \         auto dx1 = this->m_slope.back().first - this->m_slope.rbegin()[1].first;\n\
    \          auto dy1 = this->m_slope.back().second - this->m_slope.rbegin()[1].second;\n\
    \          const auto gcd1 = ::std::gcd(dx1, dy1);\n          dx1 /= gcd1;\n \
    \         dy1 /= gcd1;\n          auto dx2 = cap;\n          auto dy2 = cost;\n\
    \          const auto gcd2 = ::std::gcd(dx2, dy2);\n          dx2 /= gcd2;\n \
    \         dy2 /= gcd2;\n          return !(dx1 == dx2 && dy1 == dy2);\n      \
    \  }()) {\n          this->m_slope.emplace_back(this->m_slope.back().first + cap,\
    \ this->m_slope.back().second + cost);\n        } else {\n          this->m_slope.back().first\
    \ += cap;\n          this->m_slope.back().second += cost;\n        }\n      }\n\
    \n      return this->m_slope;\n    }\n\n    ::std::vector<::std::pair<Cap, Cost>>\
    \ slope(const int s, const int t) {\n      return this->slope(s, t, ::std::numeric_limits<Cap>::max());\n\
    \    }\n\n    ::std::pair<Cap, Cost> flow(const int s, const int t, const Cap\
    \ flow_limit) {\n      return this->slope(s, t, flow_limit).back();\n    }\n\n\
    \    ::std::pair<Cap, Cost> flow(const int s, const int t) {\n      return this->slope(s,\
    \ t).back();\n    }\n\n    ::tools::mcf_graph<Cap, Cost>::edge get_edge(const\
    \ int i) const {\n      assert(0 <= i && i < ::tools::ssize(this->m_edges) / 2);\n\
    \      return this->m_edges[i * 2];\n    }\n\n    ::std::vector<::tools::mcf_graph<Cap,\
    \ Cost>::edge> edges() const {\n      ::std::vector<::tools::mcf_graph<Cap, Cost>::edge>\
    \ result;\n      for (int edge_id = 0; edge_id < ::tools::ssize(this->m_edges);\
    \ edge_id += 2) {\n        result.push_back(this->m_edges[edge_id]);\n      }\n\
    \      return result;\n    }\n  };\n}\n\n\n#line 11 \"tools/weighted_bipartite_matching.hpp\"\
    \n\nnamespace tools {\n  template <typename W>\n  class weighted_bipartite_matching\
    \ {\n  public:\n    struct edge {\n      ::std::size_t id;\n      ::std::size_t\
    \ from;\n      ::std::size_t to;\n      W weight;\n      edge() = default;\n \
    \     edge(const ::tools::weighted_bipartite_matching<W>::edge&) = default;\n\
    \      edge(::tools::weighted_bipartite_matching<W>::edge&&) = default;\n    \
    \  ~edge() = default;\n      ::tools::weighted_bipartite_matching<W>::edge& operator=(const\
    \ ::tools::weighted_bipartite_matching<W>::edge&) = default;\n      ::tools::weighted_bipartite_matching<W>::edge&\
    \ operator=(::tools::weighted_bipartite_matching<W>::edge&&) = default;\n    \
    \  edge(const ::std::size_t id, const ::std::size_t from, const ::std::size_t\
    \ to, const W& weight) :\n        id(id), from(from), to(to), weight(weight) {\n\
    \      }\n    };\n\n  private:\n    ::std::size_t m_size1;\n    ::std::size_t\
    \ m_size2;\n    bool m_maximize;\n    ::tools::mcf_graph<int, W> m_graph;\n  \
    \  ::std::vector<::tools::weighted_bipartite_matching<W>::edge> m_edges;\n\n \
    \ public:\n    weighted_bipartite_matching() = default;\n    weighted_bipartite_matching(const\
    \ ::tools::weighted_bipartite_matching<W>&) = default;\n    weighted_bipartite_matching(::tools::weighted_bipartite_matching<W>&&)\
    \ = default;\n    ~weighted_bipartite_matching() = default;\n    ::tools::weighted_bipartite_matching<W>&\
    \ operator=(const ::tools::weighted_bipartite_matching<W>&) = default;\n    ::tools::weighted_bipartite_matching<W>&\
    \ operator=(::tools::weighted_bipartite_matching<W>&&) = default;\n\n    weighted_bipartite_matching(const\
    \ ::std::size_t size1, const ::std::size_t size2, const bool maximize) :\n   \
    \   m_size1(size1), m_size2(size2), m_maximize(maximize), m_graph(size1 + size2\
    \ + 2) {\n      for (::std::size_t i = 0; i < size1; ++i) {\n        this->m_graph.add_edge(size1\
    \ + size2, i, 1, 0);\n      }\n      for (::std::size_t i = 0; i < size2; ++i)\
    \ {\n        this->m_graph.add_edge(size1 + i, size1 + size2 + 1, 1, 0);\n   \
    \   }\n    }\n\n    ::std::size_t size1() const {\n      return this->m_size1;\n\
    \    }\n\n    ::std::size_t size2() const {\n      return this->m_size2;\n   \
    \ }\n\n    ::std::size_t add_edge(const ::std::size_t i, const ::std::size_t j,\
    \ const W& w) {\n      this->m_graph.add_edge(i, this->m_size1 + j, 1, this->m_maximize\
    \ ? -w : w);\n      this->m_edges.emplace_back(this->m_edges.size(), i, j, w);\n\
    \      return this->m_edges.size() - 1;\n    }\n\n    ::std::optional<::std::pair<W,\
    \ ::std::vector<::tools::weighted_bipartite_matching<W>::edge>>> query(const ::std::size_t\
    \ k) {\n      const auto [flow, cost] = this->m_graph.flow(this->m_size1 + this->m_size2,\
    \ this->m_size1 + this->m_size2 + 1, k);\n      if (flow < static_cast<int>(k))\
    \ return ::std::nullopt;\n\n      ::std::vector<::tools::weighted_bipartite_matching<W>::edge>\
    \ edges;\n      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {\n \
    \       if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow ==\
    \ 1) {\n          edges.push_back(this->m_edges[i]);\n        }\n      }\n\n \
    \     return ::std::make_optional(::std::make_pair(this->m_maximize ? -cost :\
    \ cost, edges));\n    }\n\n    ::std::pair<W, ::std::vector<::tools::weighted_bipartite_matching<W>::edge>>\
    \ query() {\n      auto tmp_graph = this->m_graph;\n      int min_cost_flow =\
    \ 0;\n      auto min_cost = ::std::numeric_limits<W>::max();\n      for (const\
    \ auto& [flow, cost] : tmp_graph.slope(this->m_size1 + this->m_size2, this->m_size1\
    \ + this->m_size2 + 1)) {\n        if (::tools::chmin(min_cost, cost)) {\n   \
    \       min_cost_flow = flow;\n        }\n      }\n\n      const auto [flow, cost]\
    \ = this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2\
    \ + 1, min_cost_flow);\n\n      ::std::vector<::tools::weighted_bipartite_matching<W>::edge>\
    \ edges;\n      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {\n \
    \       if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow ==\
    \ 1) {\n          edges.push_back(this->m_edges[i]);\n        }\n      }\n\n \
    \     return ::std::make_pair(this->m_maximize ? -cost : cost, edges);\n    }\n\
    \  };\n}\n\n\n#line 8 \"tests/weighted_bipartite_matching/multiple_calls.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n  tools::weighted_bipartite_matching<ll> graph(150,\
    \ 150, true);\n  for (ll i = 0; i < N; ++i) {\n    ll A, B, C;\n    std::cin >>\
    \ A >> B >> C;\n    --A, --B;\n    graph.add_edge(A, B, C);\n  }\n\n  std::vector<ll>\
    \ answers;\n  std::optional<std::pair<ll, std::vector<tools::weighted_bipartite_matching<ll>::edge>>>\
    \ matching;\n  for (ll k = 1; (matching = graph.query(k)).has_value(); ++k) {\n\
    \    answers.push_back(matching->first);\n  }\n\n  std::cout << answers.size()\
    \ << '\\n';\n  for (const auto answer : answers) {\n    std::cout << answer <<\
    \ '\\n';\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc247/tasks/abc247_g\"\n\n\
    #include <iostream>\n#include <vector>\n#include <optional>\n#include <utility>\n\
    #include \"tools/weighted_bipartite_matching.hpp\"\n\nusing ll = long long;\n\n\
    int main() {\n  std::cin.tie(nullptr);\n  std::ios_base::sync_with_stdio(false);\n\
    \n  ll N;\n  std::cin >> N;\n  tools::weighted_bipartite_matching<ll> graph(150,\
    \ 150, true);\n  for (ll i = 0; i < N; ++i) {\n    ll A, B, C;\n    std::cin >>\
    \ A >> B >> C;\n    --A, --B;\n    graph.add_edge(A, B, C);\n  }\n\n  std::vector<ll>\
    \ answers;\n  std::optional<std::pair<ll, std::vector<tools::weighted_bipartite_matching<ll>::edge>>>\
    \ matching;\n  for (ll k = 1; (matching = graph.query(k)).has_value(); ++k) {\n\
    \    answers.push_back(matching->first);\n  }\n\n  std::cout << answers.size()\
    \ << '\\n';\n  for (const auto answer : answers) {\n    std::cout << answer <<\
    \ '\\n';\n  }\n  return 0;\n}\n"
  dependsOn:
  - tools/weighted_bipartite_matching.hpp
  - tools/mcf_graph.hpp
  - tools/ssize.hpp
  - tools/chmin.hpp
  - tools/greater_by_second.hpp
  isVerificationFile: true
  path: tests/weighted_bipartite_matching/multiple_calls.test.cpp
  requiredBy: []
  timestamp: '2022-10-08 19:22:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: tests/weighted_bipartite_matching/multiple_calls.test.cpp
layout: document
redirect_from:
- /verify/tests/weighted_bipartite_matching/multiple_calls.test.cpp
- /verify/tests/weighted_bipartite_matching/multiple_calls.test.cpp.html
title: tests/weighted_bipartite_matching/multiple_calls.test.cpp
---
