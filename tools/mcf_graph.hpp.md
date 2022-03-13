---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tools/chmin.hpp
    title: chmin function
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
    path: tests/weighted_bipartite_matching.test.cpp
    title: tests/weighted_bipartite_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"tools/mcf_graph.hpp\"\n\n\n\n#include <vector>\n#include\
    \ <cassert>\n#include <limits>\n#include <utility>\n#include <numeric>\n#include\
    \ <stack>\n#include <algorithm>\n#include <queue>\n#line 1 \"tools/ssize.hpp\"\
    \n\n\n\n#include <type_traits>\n#include <cstddef>\n\nnamespace tools {\n\n  template\
    \ <typename C>\n  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t,\
    \ ::std::make_signed_t<decltype(c.size())>> {\n    return c.size();\n  }\n}\n\n\
    \n#line 1 \"tools/chmin.hpp\"\n\n\n\n#line 5 \"tools/chmin.hpp\"\n\nnamespace\
    \ tools {\n\n  template <typename M, typename N>\n  bool chmin(M& lhs, const N&\
    \ rhs) {\n    const bool updated = lhs > rhs;\n    if (updated) lhs = rhs;\n \
    \   return updated;\n  }\n}\n\n\n#line 1 \"tools/greater_by_second.hpp\"\n\n\n\
    \n#line 5 \"tools/greater_by_second.hpp\"\n\nnamespace tools {\n\n  class greater_by_second\
    \ {\n  public:\n    template <class T1, class T2>\n    bool operator()(const ::std::pair<T1,\
    \ T2>& x, const ::std::pair<T1, T2>& y) const {\n      return x.second > y.second;\n\
    \    }\n  };\n}\n\n\n#line 15 \"tools/mcf_graph.hpp\"\n\nnamespace tools {\n \
    \ template <typename Cap, typename Cost>\n  class mcf_graph {\n  public:\n   \
    \ struct edge {\n      int from, to;\n      Cap cap, flow;\n      Cost cost;\n\
    \    };\n\n  private:\n    ::std::vector<::std::vector<int>> m_graph;\n    ::std::vector<::tools::mcf_graph<Cap,\
    \ Cost>::edge> m_edges;\n\n    int size() const {\n      return this->m_graph.size();\n\
    \    }\n\n  public:\n    mcf_graph() = default;\n    mcf_graph(const ::tools::mcf_graph<Cap,\
    \ Cost>&) = default;\n    mcf_graph(::tools::mcf_graph<Cap, Cost>&&) = default;\n\
    \    ~mcf_graph() = default;\n    ::tools::mcf_graph<Cap, Cost>& operator=(const\
    \ ::tools::mcf_graph<Cap, Cost>&) = default;\n    ::tools::mcf_graph<Cap, Cost>&\
    \ operator=(::tools::mcf_graph<Cap, Cost>&&) = default;\n\n    explicit mcf_graph(const\
    \ int n) : m_graph(n) {\n    }\n\n    int add_edge(const int from, const int to,\
    \ const Cap cap, const Cost cost) {\n      assert(0 <= from && from < this->size());\n\
    \      assert(0 <= to && to < this->size());\n      assert(0 <= cap);\n      assert(cost\
    \ != ::std::numeric_limits<Cost>::min());\n      assert(cost != ::std::numeric_limits<Cost>::max());\n\
    \n      this->m_graph[from].push_back(this->m_edges.size());\n      this->m_edges.push_back(::tools::mcf_graph<Cap,\
    \ Cost>::edge({from, to, cap, 0, cost}));\n      this->m_graph[to].push_back(this->m_edges.size());\n\
    \      this->m_edges.push_back(::tools::mcf_graph<Cap, Cost>::edge({to, from,\
    \ cap, cap, -cost}));\n      return this->m_edges.size() / 2 - 1;\n    }\n\n \
    \   ::std::vector<::std::pair<Cap, Cost>> slope(const int s, const int t, const\
    \ Cap flow_limit) {\n      assert(0 <= s && s < this->size());\n      assert(0\
    \ <= t && t < this->size());\n      assert(s != t);\n\n      ::std::vector<::std::pair<Cap,\
    \ Cost>> result;\n      result.emplace_back(0, 0);\n\n      ::std::vector<::std::pair<::std::vector<int>,\
    \ ::std::vector<int>>> scc({::std::make_pair(::std::vector<int>(this->size()),\
    \ ::std::vector<int>(this->m_edges.size()))});\n      ::std::iota(scc[0].first.begin(),\
    \ scc[0].first.end(), 0);\n      ::std::iota(scc[0].second.begin(), scc[0].second.end(),\
    \ 0);\n      ::std::vector<int> scc_inv(this->size(), 0);\n      ::std::stack<int>\
    \ scc_stack({0});\n      ::std::vector<bool> will_visit(this->size());\n     \
    \ ::std::vector<Cost> dist(this->size());\n      ::std::vector<int> prev(this->size());\n\
    \      while (!scc_stack.empty()) {\n        const auto scc_id = scc_stack.top();\n\
    \        scc_stack.pop();\n        ::std::vector<int> scc_vertices;\n        ::std::vector<int>\
    \ scc_edge_ids;\n        scc_vertices.swap(scc[scc_id].first);\n        scc_edge_ids.swap(scc[scc_id].second);\n\
    \n        ::std::stack<int> ordered_by_dfs;\n        for (const auto v : scc_vertices)\
    \ {\n          will_visit[v] = false;\n        }\n        for (const auto root\
    \ : scc_vertices) {\n          if (will_visit[root]) continue;\n\n          ::std::stack<::std::pair<bool,\
    \ int>> stack;\n          stack.emplace(false, root);\n          stack.emplace(true,\
    \ root);\n          will_visit[root] = true;\n          while (!stack.empty())\
    \ {\n            const auto [pre, here] = stack.top();\n            stack.pop();\n\
    \            if (pre) {\n              for (const auto edge_id : this->m_graph[here])\
    \ {\n                const auto& edge = this->m_edges[edge_id];\n            \
    \    if (edge.flow < edge.cap && !will_visit[edge.to]) {\n                  stack.emplace(false,\
    \ edge.to);\n                  stack.emplace(true, edge.to);\n               \
    \   will_visit[edge.to] = true;\n                }\n              }\n        \
    \    } else {\n              ordered_by_dfs.push(here);\n            }\n     \
    \     }\n        }\n\n        ::std::vector<int> new_scc_ids;\n        for (const\
    \ auto v : scc_vertices) {\n          will_visit[v] = false;\n        }\n    \
    \    while (!ordered_by_dfs.empty()) {\n          const auto root = ordered_by_dfs.top();\n\
    \          ordered_by_dfs.pop();\n          if (will_visit[root]) continue;\n\n\
    \          if (new_scc_ids.empty()) {\n            new_scc_ids.push_back(scc_id);\n\
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
    \          }\n        }\n\n        for (const auto new_scc_id : new_scc_ids) {\n\
    \          const auto& [new_scc_vertices, new_scc_edge_ids] = scc[new_scc_id];\n\
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
    \ dist[edge.from] + edge.cost)) {\n              Cap cap = edge.cap - edge.flow;\n\
    \              for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from)\
    \ {\n                const auto& current_edge = this->m_edges[prev[v]];\n    \
    \            ::tools::chmin(cap, current_edge.cap - current_edge.flow);\n    \
    \          }\n\n              edge.flow += cap;\n              rev.flow -= cap;\n\
    \              result.back().second += cap * edge.cost;\n              for (int\
    \ v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from) {\n          \
    \      auto& current_edge = this->m_edges[prev[v]];\n                auto& current_rev\
    \ = this->m_edges[prev[v] ^ 1];\n                current_edge.flow += cap;\n \
    \               current_rev.flow -= cap;\n                result.back().second\
    \ += cap * current_edge.cost;\n              }\n\n              scc_stack.push(new_scc_id);\n\
    \              break;\n            }\n          }\n        }\n      }\n\n    \
    \  ::std::vector<Cost> potentials(this->size(), 0);\n      bool has_negative_edge\
    \ = ::std::any_of(this->m_edges.begin(), this->m_edges.end(), [](const auto& edge)\
    \ { return edge.flow < edge.cap && edge.cost < 0; });\n      while (result.back().first\
    \ < flow_limit) {\n        ::std::fill(dist.begin(), dist.end(), ::std::numeric_limits<Cost>::max());\n\
    \        ::std::fill(prev.begin(), prev.end(), -1);\n        if (has_negative_edge)\
    \ {\n          if (::std::all_of(scc.begin(), scc.end(), [](const auto& pair)\
    \ { return pair.first.size() == 1; })) {\n            ::std::vector<int> indeg(this->size(),\
    \ 0);\n            for (const auto& edge : this->m_edges) {\n              if\
    \ (edge.flow < edge.cap) {\n                ++indeg[edge.to];\n              }\n\
    \            }\n            ::std::queue<int> queue;\n            for (int v =\
    \ 0; v < this->size(); ++v) {\n              if (indeg[v] == 0) {\n          \
    \      queue.push(v);\n              }\n            }\n            dist[s] = 0;\n\
    \            while (!queue.empty()) {\n              const auto here = queue.front();\n\
    \              queue.pop();\n              for (const auto edge_id : this->m_graph[here])\
    \ {\n                const auto& edge = this->m_edges[edge_id];\n            \
    \    if (edge.flow < edge.cap) {\n                  if (dist[edge.from] < ::std::numeric_limits<Cost>::max()\
    \ && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {\n         \
    \           prev[edge.to] = edge_id;\n                  }\n                  --indeg[edge.to];\n\
    \                  if (indeg[edge.to] == 0) {\n                    queue.push(edge.to);\n\
    \                  }\n                }\n              }\n            }\n    \
    \      } else {\n            dist[s] = 0;\n            for (int i = 0; i < this->size()\
    \ - 1; ++i) {\n              for (int edge_id = 0; edge_id < ::tools::ssize(this->m_edges);\
    \ ++edge_id) {\n                const auto& edge = this->m_edges[edge_id];\n \
    \               if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max()\
    \ && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {\n         \
    \         prev[edge.to] = edge_id;\n                }\n              }\n     \
    \       }\n            #ifndef NDEBUG\n              for (const auto& edge : this->m_edges)\
    \ {\n                if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max())\
    \ {\n                  assert(dist[edge.to] <= dist[edge.from] + edge.cost);\n\
    \                }\n              }\n            #endif\n          }\n       \
    \ } else {\n          #ifndef NDEBUG\n            for (const auto& edge : this->m_edges)\
    \ {\n              if (edge.flow < edge.cap && potentials[edge.from] < ::std::numeric_limits<Cost>::max()\
    \ && potentials[edge.to] < ::std::numeric_limits<Cost>::max()) {\n           \
    \      assert(edge.cost + potentials[edge.from] - potentials[edge.to] >= 0);\n\
    \              }\n            }\n          #endif\n          dist[s] = 0;\n  \
    \        ::std::priority_queue<::std::pair<int, Cost>, ::std::vector<::std::pair<int,\
    \ Cost>>, ::tools::greater_by_second> tasks;\n          tasks.emplace(s, 0);\n\
    \          while (!tasks.empty()) {\n            const auto [here, d] = tasks.top();\n\
    \            tasks.pop();\n            if (dist[here] < d) continue;\n       \
    \     for (const auto edge_id : this->m_graph[here]) {\n              const auto&\
    \ edge = this->m_edges[edge_id];\n              if (edge.flow < edge.cap && dist[edge.from]\
    \ < ::std::numeric_limits<Cost>::max()) {\n                assert(potentials[edge.from]\
    \ < ::std::numeric_limits<Cost>::max());\n                assert(potentials[edge.to]\
    \ < ::std::numeric_limits<Cost>::max());\n                if (::tools::chmin(dist[edge.to],\
    \ dist[edge.from] + edge.cost + potentials[edge.from] - potentials[edge.to]))\
    \ {\n                  prev[edge.to] = edge_id;\n                  tasks.emplace(edge.to,\
    \ dist[edge.to]);\n                }\n              }\n            }\n       \
    \   }\n        }\n\n        if (dist[t] == ::std::numeric_limits<Cost>::max())\
    \ break;\n        for (int i = 0; i < this->size(); ++i) {\n          if (dist[i]\
    \ < ::std::numeric_limits<Cost>::max()) {\n            potentials[i] += dist[i];\n\
    \          } else {\n            potentials[i] = ::std::numeric_limits<Cost>::max();\n\
    \          }\n        }\n        has_negative_edge = false;\n\n        Cap cap\
    \ = flow_limit - result.back().first;\n        for (int v = t; v != s; v = this->m_edges[prev[v]].from)\
    \ {\n          const auto& edge = this->m_edges[prev[v]];\n          ::tools::chmin(cap,\
    \ edge.cap - edge.flow);\n        }\n\n        Cost cost = 0;\n        for (int\
    \ v = t; v != s; v = this->m_edges[prev[v]].from) {\n          auto& edge = this->m_edges[prev[v]];\n\
    \          auto& rev = this->m_edges[prev[v] ^ 1];\n          edge.flow += cap;\n\
    \          rev.flow -= cap;\n          cost += cap * edge.cost;\n        }\n\n\
    \        result.emplace_back(result.back().first + cap, result.back().second +\
    \ cost);\n      }\n\n      return result;\n    }\n\n    ::std::vector<::std::pair<Cap,\
    \ Cost>> slope(const int s, const int t) {\n      return this->slope(s, t, ::std::numeric_limits<Cap>::max());\n\
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
    #include <cassert>\n#include <limits>\n#include <utility>\n#include <numeric>\n\
    #include <stack>\n#include <algorithm>\n#include <queue>\n#include \"tools/ssize.hpp\"\
    \n#include \"tools/chmin.hpp\"\n#include \"tools/greater_by_second.hpp\"\n\nnamespace\
    \ tools {\n  template <typename Cap, typename Cost>\n  class mcf_graph {\n  public:\n\
    \    struct edge {\n      int from, to;\n      Cap cap, flow;\n      Cost cost;\n\
    \    };\n\n  private:\n    ::std::vector<::std::vector<int>> m_graph;\n    ::std::vector<::tools::mcf_graph<Cap,\
    \ Cost>::edge> m_edges;\n\n    int size() const {\n      return this->m_graph.size();\n\
    \    }\n\n  public:\n    mcf_graph() = default;\n    mcf_graph(const ::tools::mcf_graph<Cap,\
    \ Cost>&) = default;\n    mcf_graph(::tools::mcf_graph<Cap, Cost>&&) = default;\n\
    \    ~mcf_graph() = default;\n    ::tools::mcf_graph<Cap, Cost>& operator=(const\
    \ ::tools::mcf_graph<Cap, Cost>&) = default;\n    ::tools::mcf_graph<Cap, Cost>&\
    \ operator=(::tools::mcf_graph<Cap, Cost>&&) = default;\n\n    explicit mcf_graph(const\
    \ int n) : m_graph(n) {\n    }\n\n    int add_edge(const int from, const int to,\
    \ const Cap cap, const Cost cost) {\n      assert(0 <= from && from < this->size());\n\
    \      assert(0 <= to && to < this->size());\n      assert(0 <= cap);\n      assert(cost\
    \ != ::std::numeric_limits<Cost>::min());\n      assert(cost != ::std::numeric_limits<Cost>::max());\n\
    \n      this->m_graph[from].push_back(this->m_edges.size());\n      this->m_edges.push_back(::tools::mcf_graph<Cap,\
    \ Cost>::edge({from, to, cap, 0, cost}));\n      this->m_graph[to].push_back(this->m_edges.size());\n\
    \      this->m_edges.push_back(::tools::mcf_graph<Cap, Cost>::edge({to, from,\
    \ cap, cap, -cost}));\n      return this->m_edges.size() / 2 - 1;\n    }\n\n \
    \   ::std::vector<::std::pair<Cap, Cost>> slope(const int s, const int t, const\
    \ Cap flow_limit) {\n      assert(0 <= s && s < this->size());\n      assert(0\
    \ <= t && t < this->size());\n      assert(s != t);\n\n      ::std::vector<::std::pair<Cap,\
    \ Cost>> result;\n      result.emplace_back(0, 0);\n\n      ::std::vector<::std::pair<::std::vector<int>,\
    \ ::std::vector<int>>> scc({::std::make_pair(::std::vector<int>(this->size()),\
    \ ::std::vector<int>(this->m_edges.size()))});\n      ::std::iota(scc[0].first.begin(),\
    \ scc[0].first.end(), 0);\n      ::std::iota(scc[0].second.begin(), scc[0].second.end(),\
    \ 0);\n      ::std::vector<int> scc_inv(this->size(), 0);\n      ::std::stack<int>\
    \ scc_stack({0});\n      ::std::vector<bool> will_visit(this->size());\n     \
    \ ::std::vector<Cost> dist(this->size());\n      ::std::vector<int> prev(this->size());\n\
    \      while (!scc_stack.empty()) {\n        const auto scc_id = scc_stack.top();\n\
    \        scc_stack.pop();\n        ::std::vector<int> scc_vertices;\n        ::std::vector<int>\
    \ scc_edge_ids;\n        scc_vertices.swap(scc[scc_id].first);\n        scc_edge_ids.swap(scc[scc_id].second);\n\
    \n        ::std::stack<int> ordered_by_dfs;\n        for (const auto v : scc_vertices)\
    \ {\n          will_visit[v] = false;\n        }\n        for (const auto root\
    \ : scc_vertices) {\n          if (will_visit[root]) continue;\n\n          ::std::stack<::std::pair<bool,\
    \ int>> stack;\n          stack.emplace(false, root);\n          stack.emplace(true,\
    \ root);\n          will_visit[root] = true;\n          while (!stack.empty())\
    \ {\n            const auto [pre, here] = stack.top();\n            stack.pop();\n\
    \            if (pre) {\n              for (const auto edge_id : this->m_graph[here])\
    \ {\n                const auto& edge = this->m_edges[edge_id];\n            \
    \    if (edge.flow < edge.cap && !will_visit[edge.to]) {\n                  stack.emplace(false,\
    \ edge.to);\n                  stack.emplace(true, edge.to);\n               \
    \   will_visit[edge.to] = true;\n                }\n              }\n        \
    \    } else {\n              ordered_by_dfs.push(here);\n            }\n     \
    \     }\n        }\n\n        ::std::vector<int> new_scc_ids;\n        for (const\
    \ auto v : scc_vertices) {\n          will_visit[v] = false;\n        }\n    \
    \    while (!ordered_by_dfs.empty()) {\n          const auto root = ordered_by_dfs.top();\n\
    \          ordered_by_dfs.pop();\n          if (will_visit[root]) continue;\n\n\
    \          if (new_scc_ids.empty()) {\n            new_scc_ids.push_back(scc_id);\n\
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
    \          }\n        }\n\n        for (const auto new_scc_id : new_scc_ids) {\n\
    \          const auto& [new_scc_vertices, new_scc_edge_ids] = scc[new_scc_id];\n\
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
    \ dist[edge.from] + edge.cost)) {\n              Cap cap = edge.cap - edge.flow;\n\
    \              for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from)\
    \ {\n                const auto& current_edge = this->m_edges[prev[v]];\n    \
    \            ::tools::chmin(cap, current_edge.cap - current_edge.flow);\n    \
    \          }\n\n              edge.flow += cap;\n              rev.flow -= cap;\n\
    \              result.back().second += cap * edge.cost;\n              for (int\
    \ v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from) {\n          \
    \      auto& current_edge = this->m_edges[prev[v]];\n                auto& current_rev\
    \ = this->m_edges[prev[v] ^ 1];\n                current_edge.flow += cap;\n \
    \               current_rev.flow -= cap;\n                result.back().second\
    \ += cap * current_edge.cost;\n              }\n\n              scc_stack.push(new_scc_id);\n\
    \              break;\n            }\n          }\n        }\n      }\n\n    \
    \  ::std::vector<Cost> potentials(this->size(), 0);\n      bool has_negative_edge\
    \ = ::std::any_of(this->m_edges.begin(), this->m_edges.end(), [](const auto& edge)\
    \ { return edge.flow < edge.cap && edge.cost < 0; });\n      while (result.back().first\
    \ < flow_limit) {\n        ::std::fill(dist.begin(), dist.end(), ::std::numeric_limits<Cost>::max());\n\
    \        ::std::fill(prev.begin(), prev.end(), -1);\n        if (has_negative_edge)\
    \ {\n          if (::std::all_of(scc.begin(), scc.end(), [](const auto& pair)\
    \ { return pair.first.size() == 1; })) {\n            ::std::vector<int> indeg(this->size(),\
    \ 0);\n            for (const auto& edge : this->m_edges) {\n              if\
    \ (edge.flow < edge.cap) {\n                ++indeg[edge.to];\n              }\n\
    \            }\n            ::std::queue<int> queue;\n            for (int v =\
    \ 0; v < this->size(); ++v) {\n              if (indeg[v] == 0) {\n          \
    \      queue.push(v);\n              }\n            }\n            dist[s] = 0;\n\
    \            while (!queue.empty()) {\n              const auto here = queue.front();\n\
    \              queue.pop();\n              for (const auto edge_id : this->m_graph[here])\
    \ {\n                const auto& edge = this->m_edges[edge_id];\n            \
    \    if (edge.flow < edge.cap) {\n                  if (dist[edge.from] < ::std::numeric_limits<Cost>::max()\
    \ && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {\n         \
    \           prev[edge.to] = edge_id;\n                  }\n                  --indeg[edge.to];\n\
    \                  if (indeg[edge.to] == 0) {\n                    queue.push(edge.to);\n\
    \                  }\n                }\n              }\n            }\n    \
    \      } else {\n            dist[s] = 0;\n            for (int i = 0; i < this->size()\
    \ - 1; ++i) {\n              for (int edge_id = 0; edge_id < ::tools::ssize(this->m_edges);\
    \ ++edge_id) {\n                const auto& edge = this->m_edges[edge_id];\n \
    \               if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max()\
    \ && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {\n         \
    \         prev[edge.to] = edge_id;\n                }\n              }\n     \
    \       }\n            #ifndef NDEBUG\n              for (const auto& edge : this->m_edges)\
    \ {\n                if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max())\
    \ {\n                  assert(dist[edge.to] <= dist[edge.from] + edge.cost);\n\
    \                }\n              }\n            #endif\n          }\n       \
    \ } else {\n          #ifndef NDEBUG\n            for (const auto& edge : this->m_edges)\
    \ {\n              if (edge.flow < edge.cap && potentials[edge.from] < ::std::numeric_limits<Cost>::max()\
    \ && potentials[edge.to] < ::std::numeric_limits<Cost>::max()) {\n           \
    \      assert(edge.cost + potentials[edge.from] - potentials[edge.to] >= 0);\n\
    \              }\n            }\n          #endif\n          dist[s] = 0;\n  \
    \        ::std::priority_queue<::std::pair<int, Cost>, ::std::vector<::std::pair<int,\
    \ Cost>>, ::tools::greater_by_second> tasks;\n          tasks.emplace(s, 0);\n\
    \          while (!tasks.empty()) {\n            const auto [here, d] = tasks.top();\n\
    \            tasks.pop();\n            if (dist[here] < d) continue;\n       \
    \     for (const auto edge_id : this->m_graph[here]) {\n              const auto&\
    \ edge = this->m_edges[edge_id];\n              if (edge.flow < edge.cap && dist[edge.from]\
    \ < ::std::numeric_limits<Cost>::max()) {\n                assert(potentials[edge.from]\
    \ < ::std::numeric_limits<Cost>::max());\n                assert(potentials[edge.to]\
    \ < ::std::numeric_limits<Cost>::max());\n                if (::tools::chmin(dist[edge.to],\
    \ dist[edge.from] + edge.cost + potentials[edge.from] - potentials[edge.to]))\
    \ {\n                  prev[edge.to] = edge_id;\n                  tasks.emplace(edge.to,\
    \ dist[edge.to]);\n                }\n              }\n            }\n       \
    \   }\n        }\n\n        if (dist[t] == ::std::numeric_limits<Cost>::max())\
    \ break;\n        for (int i = 0; i < this->size(); ++i) {\n          if (dist[i]\
    \ < ::std::numeric_limits<Cost>::max()) {\n            potentials[i] += dist[i];\n\
    \          } else {\n            potentials[i] = ::std::numeric_limits<Cost>::max();\n\
    \          }\n        }\n        has_negative_edge = false;\n\n        Cap cap\
    \ = flow_limit - result.back().first;\n        for (int v = t; v != s; v = this->m_edges[prev[v]].from)\
    \ {\n          const auto& edge = this->m_edges[prev[v]];\n          ::tools::chmin(cap,\
    \ edge.cap - edge.flow);\n        }\n\n        Cost cost = 0;\n        for (int\
    \ v = t; v != s; v = this->m_edges[prev[v]].from) {\n          auto& edge = this->m_edges[prev[v]];\n\
    \          auto& rev = this->m_edges[prev[v] ^ 1];\n          edge.flow += cap;\n\
    \          rev.flow -= cap;\n          cost += cap * edge.cost;\n        }\n\n\
    \        result.emplace_back(result.back().first + cap, result.back().second +\
    \ cost);\n      }\n\n      return result;\n    }\n\n    ::std::vector<::std::pair<Cap,\
    \ Cost>> slope(const int s, const int t) {\n      return this->slope(s, t, ::std::numeric_limits<Cap>::max());\n\
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
  - tools/greater_by_second.hpp
  isVerificationFile: false
  path: tools/mcf_graph.hpp
  requiredBy:
  - tools/weighted_bipartite_matching.hpp
  timestamp: '2022-03-13 20:40:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - tests/weighted_bipartite_matching.test.cpp
documentation_of: tools/mcf_graph.hpp
layout: document
redirect_from:
- /library/tools/mcf_graph.hpp
- /library/tools/mcf_graph.hpp.html
title: tools/mcf_graph.hpp
---
