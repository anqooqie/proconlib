---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
  - icon: ':heavy_check_mark:'
    path: tools/cmp_less.hpp
    title: Polyfill of std::cmp_less
  - icon: ':heavy_check_mark:'
    path: tools/greater_by_second.hpp
    title: std::greater by second
  - icon: ':heavy_check_mark:'
    path: tools/ssize.hpp
    title: Polyfill of std::ssize
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: tools/weighted_bipartite_matching.hpp
    title: Matching on weighted bipartite graph
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/maximize.test.cpp
    title: tests/weighted_bipartite_matching/maximize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/minimize.test.cpp
    title: tests/weighted_bipartite_matching/minimize.test.cpp
  - icon: ':heavy_check_mark:'
    path: tests/weighted_bipartite_matching/multiple_calls.test.cpp
    title: tests/weighted_bipartite_matching/multiple_calls.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/mcf_graph.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <utility>\n#include <optional>\n#include <cassert>\n#include <limits>\n#include\
    \ <numeric>\n#include <stack>\n#include <algorithm>\n#include <queue>\n#include\
    \ <tuple>\n#line 1 \"tools/ssize.hpp\"\n\n\n\n#include <type_traits>\n#include\
    \ <cstddef>\n\nnamespace tools {\n\n  template <typename C>\n  constexpr auto\
    \ ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>>\
    \ {\n    return c.size();\n  }\n}\n\n\n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line\
    \ 1 \"tools/cmp_less.hpp\"\n\n\n\n#line 5 \"tools/cmp_less.hpp\"\n\nnamespace\
    \ tools {\n  template <typename T, typename U>\n  constexpr bool cmp_less(const\
    \ T t, const U u) noexcept {\n    using UT = ::std::make_unsigned_t<T>;\n    using\
    \ UU = ::std::make_unsigned_t<U>;\n    if constexpr (::std::is_signed_v<T> ==\
    \ ::std::is_signed_v<U>) {\n      return t < u;\n    } else if constexpr (::std::is_signed_v<T>)\
    \ {\n      return t < 0 ? true : UT(t) < u;\n    } else {\n      return u < 0\
    \ ? false : t < UU(u);\n    }\n  }\n}\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    bool updated;\n    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>)\
    \ {\n      updated = ::tools::cmp_less(rhs, lhs);\n    } else {\n      updated\
    \ = rhs < lhs;\n    }\n    if (updated) lhs = rhs;\n    return updated;\n  }\n\
    }\n\n\n#line 1 \"tools/greater_by_second.hpp\"\n\n\n\n#line 5 \"tools/greater_by_second.hpp\"\
    \n\nnamespace tools {\n\n  class greater_by_second {\n  public:\n    template\
    \ <class T1, class T2>\n    bool operator()(const ::std::pair<T1, T2>& x, const\
    \ ::std::pair<T1, T2>& y) const {\n      return x.second > y.second;\n    }\n\
    \  };\n}\n\n\n#line 17 \"tools/mcf_graph.hpp\"\n\nnamespace tools {\n  template\
    \ <typename Cap, typename Cost>\n  class mcf_graph {\n  public:\n    struct edge\
    \ {\n      int from, to;\n      Cap cap, flow;\n      Cost cost;\n    };\n\n \
    \ private:\n    ::std::vector<::std::vector<int>> m_graph;\n    ::std::vector<::tools::mcf_graph<Cap,\
    \ Cost>::edge> m_edges;\n    ::std::vector<::std::pair<Cap, Cost>> m_slope;\n\
    \    ::std::vector<Cost> m_potentials;\n    bool m_filled_negative_cycles;\n \
    \   ::std::optional<bool> m_is_dag;\n    bool m_calculated_potentials;\n\n   \
    \ int size() const {\n      return this->m_graph.size();\n    }\n\n  public:\n\
    \    mcf_graph() = default;\n    mcf_graph(const ::tools::mcf_graph<Cap, Cost>&)\
    \ = default;\n    mcf_graph(::tools::mcf_graph<Cap, Cost>&&) = default;\n    ~mcf_graph()\
    \ = default;\n    ::tools::mcf_graph<Cap, Cost>& operator=(const ::tools::mcf_graph<Cap,\
    \ Cost>&) = default;\n    ::tools::mcf_graph<Cap, Cost>& operator=(::tools::mcf_graph<Cap,\
    \ Cost>&&) = default;\n\n    explicit mcf_graph(const int n) : m_graph(n), m_slope({::std::pair<Cap,\
    \ Cost>(0, 0)}), m_potentials(n, 0), m_filled_negative_cycles(false), m_calculated_potentials(false)\
    \ {\n    }\n\n    int add_edge(const int from, const int to, const Cap cap, const\
    \ Cost cost) {\n      assert(0 <= from && from < this->size());\n      assert(0\
    \ <= to && to < this->size());\n      assert(0 <= cap);\n      assert(cost !=\
    \ ::std::numeric_limits<Cost>::min());\n      assert(cost != ::std::numeric_limits<Cost>::max());\n\
    \n      this->m_graph[from].push_back(this->m_edges.size());\n      this->m_edges.push_back(::tools::mcf_graph<Cap,\
    \ Cost>::edge({from, to, cap, 0, cost}));\n      this->m_graph[to].push_back(this->m_edges.size());\n\
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
    \      return result;\n    }\n  };\n}\n\n\n"
  code: "#ifndef TOOLS_MCF_GRAPH_HPP\n#define TOOLS_MCF_GRAPH_HPP\n\n#include <vector>\n\
    #include <utility>\n#include <optional>\n#include <cassert>\n#include <limits>\n\
    #include <numeric>\n#include <stack>\n#include <algorithm>\n#include <queue>\n\
    #include <tuple>\n#include \"tools/ssize.hpp\"\n#include \"tools/chmin.hpp\"\n\
    #include \"tools/greater_by_second.hpp\"\n\nnamespace tools {\n  template <typename\
    \ Cap, typename Cost>\n  class mcf_graph {\n  public:\n    struct edge {\n   \
    \   int from, to;\n      Cap cap, flow;\n      Cost cost;\n    };\n\n  private:\n\
    \    ::std::vector<::std::vector<int>> m_graph;\n    ::std::vector<::tools::mcf_graph<Cap,\
    \ Cost>::edge> m_edges;\n    ::std::vector<::std::pair<Cap, Cost>> m_slope;\n\
    \    ::std::vector<Cost> m_potentials;\n    bool m_filled_negative_cycles;\n \
    \   ::std::optional<bool> m_is_dag;\n    bool m_calculated_potentials;\n\n   \
    \ int size() const {\n      return this->m_graph.size();\n    }\n\n  public:\n\
    \    mcf_graph() = default;\n    mcf_graph(const ::tools::mcf_graph<Cap, Cost>&)\
    \ = default;\n    mcf_graph(::tools::mcf_graph<Cap, Cost>&&) = default;\n    ~mcf_graph()\
    \ = default;\n    ::tools::mcf_graph<Cap, Cost>& operator=(const ::tools::mcf_graph<Cap,\
    \ Cost>&) = default;\n    ::tools::mcf_graph<Cap, Cost>& operator=(::tools::mcf_graph<Cap,\
    \ Cost>&&) = default;\n\n    explicit mcf_graph(const int n) : m_graph(n), m_slope({::std::pair<Cap,\
    \ Cost>(0, 0)}), m_potentials(n, 0), m_filled_negative_cycles(false), m_calculated_potentials(false)\
    \ {\n    }\n\n    int add_edge(const int from, const int to, const Cap cap, const\
    \ Cost cost) {\n      assert(0 <= from && from < this->size());\n      assert(0\
    \ <= to && to < this->size());\n      assert(0 <= cap);\n      assert(cost !=\
    \ ::std::numeric_limits<Cost>::min());\n      assert(cost != ::std::numeric_limits<Cost>::max());\n\
    \n      this->m_graph[from].push_back(this->m_edges.size());\n      this->m_edges.push_back(::tools::mcf_graph<Cap,\
    \ Cost>::edge({from, to, cap, 0, cost}));\n      this->m_graph[to].push_back(this->m_edges.size());\n\
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
    \      return result;\n    }\n  };\n}\n\n#endif\n"
  dependsOn:
  - tools/ssize.hpp
  - tools/chmin.hpp
  - tools/cmp_less.hpp
  - tools/greater_by_second.hpp
  isVerificationFile: false
  path: tools/mcf_graph.hpp
  requiredBy:
  - tools/weighted_bipartite_matching.hpp
  timestamp: '2024-03-24 18:38:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/weighted_bipartite_matching/maximize.test.cpp
  - tests/weighted_bipartite_matching/multiple_calls.test.cpp
  - tests/weighted_bipartite_matching/minimize.test.cpp
documentation_of: tools/mcf_graph.hpp
layout: document
title: Solver of minimum-cost flow problem
---

It solves Minimum-cost flow problem.

### License
- CC0

### Author
- anqooqie

## Constructor
```cpp
mcf_graph<Cap, Cost> graph(int n);
```

It creates a directed graph with $n$ vertices and $0$ edges.
`Cap` and `Cost` are the type of the capacity and the cost, respectively.

### Constraints
- $0 \leq n \leq 10^8$
- `Cap` and `Cost` are `int` or `long long`.

### Time Complexity
- $O(n)$

## add_edge
```cpp
int graph.add_edge(int from, int to, Cap cap, Cost cost);
```

It adds an edge oriented from `from` to `to` with capacity `cap` and cost `cost`.
It returns an integer $k$ such that this is the $k$-th edge that is added.

### Constraints
- $0 \leq \mathrm{from, to} < n$
- $0 \leq \mathrm{cap}$

### Time Complexity
- $O(1)$ amortized

## flow
```cpp
(1) std::pair<Cap, Cost> graph.flow(int s, int t);
(2) std::pair<Cap, Cost> graph.flow(int s, int t, Cap flow_limit);
```

- It augments the flow from $s$ to $t$ as much as possible. It returns the amount of the flow and the cost.
- (1) It augments the $s-t$ flow as much as possible.
- (2) It augments the $s-t$ flow as much as possible, until reaching the amount of `flow_limit`.

### Constraints
- same as `slope`.

### Time Complexity
- same as `slope`.

## slope
```cpp
(1) std::vector<std::pair<Cap, Cost>> graph.slope(int s, int t);
(2) std::vector<std::pair<Cap, Cost>> graph.slope(int s, int t, Cap flow_limit);
```

Let $g$ be a function such that $g(x)$ is the cost of the minimum cost $s-t$ flow when the amount of the flow is exactly $x$.
$g$ is known to be piecewise linear.
It returns $g$ as the list of the changepoints, that satisfies the followings.

- The first element of the list is $(0, g(0))$.
- No three changepoints are on the same line.
- (1) The last element of the list is $(x, g(x))$, where $x$ is the maximum amount of the $s-t$ flow.
- (2) The last element of the list is $(y, g(y))$, where $y = \min(x, \mathrm{flow\\_limit})$.

### Constraints
Let $x$ be the maximum absolute value of cost among all edges.

- $s \neq t$
- The total amount of the flow is in `Cap`.
- The total cost of the flow is in `Cost`.
- (Cost : `int`): $0 \leq nx \leq 2 \times 10^9 + 1000$
- (Cost : `long long`): $0 \leq nx \leq 8 \times 10^{18} + 1000$
- (2) If you call `flow` or `slope` multiple times, `flow_limit` is greater than or equal to `flow_limit` in the last call of `flow` or `slope`.

### Time Complexity
- (No edges with negative cost or DAG): $O(F (n + m) \log n)$, where $F$ is the amount of the flow and $m$ is the number of added edges.
- (Otherwise): $O(Nnm + nm + F (n + m) \log n)$, where $N$ is the number of negative cycles, $F$ is the amount of the flow and $m$ is the number of added edges.

## edges
```cpp
struct edge<Cap, Cost> {
  int from, to;
  Cap cap, flow;
  Cost cost;
};

(1) mcf_graph<Cap, Cost>::edge graph.get_edge(int i);
(2) std::vector<mcf_graph<Cap, Cost>::edge> graph.edges();
```

- It returns the current internal state of the edges.
- The edges are ordered in the same order as added by `add_edge`.

### Constraints
- $0 \leq i < m$

### Time Complexity
- (1): $(O(1))$
- (2): $(O(m))$, where $m$ is the number of added edges.
