#ifndef TOOLS_MCF_GRAPH_HPP
#define TOOLS_MCF_GRAPH_HPP

#include <vector>
#include <utility>
#include <optional>
#include <cassert>
#include <limits>
#include <numeric>
#include <stack>
#include <algorithm>
#include <queue>
#include "tools/ssize.hpp"
#include "tools/chmin.hpp"
#include "tools/greater_by_second.hpp"

namespace tools {
  template <typename Cap, typename Cost>
  class mcf_graph {
  public:
    struct edge {
      int from, to;
      Cap cap, flow;
      Cost cost;
    };

  private:
    ::std::vector<::std::vector<int>> m_graph;
    ::std::vector<::tools::mcf_graph<Cap, Cost>::edge> m_edges;
    ::std::vector<::std::pair<Cap, Cost>> m_slope;
    ::std::vector<Cost> m_potentials;
    bool m_filled_negative_cycles;
    ::std::optional<bool> m_is_dag;
    bool m_calculated_potentials;

    int size() const {
      return this->m_graph.size();
    }

  public:
    mcf_graph() = default;
    mcf_graph(const ::tools::mcf_graph<Cap, Cost>&) = default;
    mcf_graph(::tools::mcf_graph<Cap, Cost>&&) = default;
    ~mcf_graph() = default;
    ::tools::mcf_graph<Cap, Cost>& operator=(const ::tools::mcf_graph<Cap, Cost>&) = default;
    ::tools::mcf_graph<Cap, Cost>& operator=(::tools::mcf_graph<Cap, Cost>&&) = default;

    explicit mcf_graph(const int n) : m_graph(n), m_slope({::std::pair<Cap, Cost>(0, 0)}), m_potentials(n, 0), m_filled_negative_cycles(false), m_calculated_potentials(false) {
    }

    int add_edge(const int from, const int to, const Cap cap, const Cost cost) {
      assert(0 <= from && from < this->size());
      assert(0 <= to && to < this->size());
      assert(0 <= cap);
      assert(cost != ::std::numeric_limits<Cost>::min());
      assert(cost != ::std::numeric_limits<Cost>::max());

      this->m_graph[from].push_back(this->m_edges.size());
      this->m_edges.push_back(::tools::mcf_graph<Cap, Cost>::edge({from, to, cap, 0, cost}));
      this->m_graph[to].push_back(this->m_edges.size());
      this->m_edges.push_back(::tools::mcf_graph<Cap, Cost>::edge({to, from, cap, cap, -cost}));
      return this->m_edges.size() / 2 - 1;
    }

  private:
    void fill_negative_cycles() {
      ::std::vector<::std::pair<::std::vector<int>, ::std::vector<int>>> scc({::std::make_pair(::std::vector<int>(this->size()), ::std::vector<int>(this->m_edges.size()))});
      ::std::iota(scc[0].first.begin(), scc[0].first.end(), 0);
      ::std::iota(scc[0].second.begin(), scc[0].second.end(), 0);
      ::std::vector<int> scc_inv(this->size(), 0);
      ::std::stack<int> scc_stack({0});
      ::std::vector<bool> will_visit(this->size());
      ::std::vector<Cost> dist(this->size());
      ::std::vector<int> prev(this->size());

      // Loop until every strongly connected component contains no negative cycles.
      while (!scc_stack.empty()) {
        const auto scc_id = scc_stack.top();
        scc_stack.pop();
        ::std::vector<int> scc_vertices;
        ::std::vector<int> scc_edge_ids;
        scc_vertices.swap(scc[scc_id].first);
        scc_edge_ids.swap(scc[scc_id].second);

        // scc[scc_id] might be decomposed into smaller strongly connected components, so check and decompose it.
        ::std::stack<int> ordered_by_dfs;
        for (const auto v : scc_vertices) {
          will_visit[v] = false;
        }
        for (const auto root : scc_vertices) {
          if (will_visit[root]) continue;

          ::std::stack<::std::pair<bool, int>> stack;
          stack.emplace(true, root);
          while (!stack.empty()) {
            const auto [pre, here] = stack.top();
            stack.pop();
            if (pre) {
              if (will_visit[here]) continue;
              will_visit[here] = true;
              stack.emplace(false, here);
              for (const auto edge_id : this->m_graph[here]) {
                const auto& edge = this->m_edges[edge_id];
                if (edge.flow < edge.cap && !will_visit[edge.to]) {
                  stack.emplace(true, edge.to);
                }
              }
            } else {
              ordered_by_dfs.push(here);
            }
          }
        }

        ::std::vector<int> new_scc_ids;
        for (const auto v : scc_vertices) {
          will_visit[v] = false;
        }
        while (!ordered_by_dfs.empty()) {
          const auto root = ordered_by_dfs.top();
          ordered_by_dfs.pop();
          if (will_visit[root]) continue;

          if (new_scc_ids.empty()) {
            new_scc_ids.push_back(scc_id);
          } else {
            new_scc_ids.push_back(scc.size());
            scc.emplace_back();
          }

          ::std::stack<int> stack({root});
          will_visit[root] = true;
          while (!stack.empty()) {
            const auto here = stack.top();
            stack.pop();

            scc[new_scc_ids.back()].first.emplace_back();
            scc_inv[here] = new_scc_ids.back();

            for (const auto edge_id : this->m_graph[here]) {
              const auto& edge = this->m_edges[edge_id];
              const auto& rev = this->m_edges[edge_id ^ 1];
              if (rev.flow < rev.cap && !will_visit[edge.to]) {
                stack.push(edge.to);
                will_visit[edge.to] = true;
              }
            }
          }
        }

        for (const auto edge_id : scc_edge_ids) {
          const auto& edge = this->m_edges[edge_id];
          if (scc_inv[edge.from] == scc_inv[edge.to]) {
            scc[scc_inv[edge.from]].second.push_back(edge_id);
          }
        }

        // Now, scc[new_scc_id] is truly a strongly connected component.
        // Check whether it contains any negative cycles using Bellman-Ford algorithm.
        for (const auto new_scc_id : new_scc_ids) {
          const auto& [new_scc_vertices, new_scc_edge_ids] = scc[new_scc_id];
          for (const auto v : new_scc_vertices) {
            dist[v] = ::std::numeric_limits<Cost>::max();
            prev[v] = -1;
          }
          dist[new_scc_vertices[0]] = 0;
          for (int i = 0; i < ::tools::ssize(new_scc_vertices) - 1; ++i) {
            for (const auto edge_id : new_scc_edge_ids) {
              const auto& edge = this->m_edges[edge_id];
              if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
                prev[edge.to] = edge_id;
              }
            }
          }

          for (const auto edge_id : new_scc_edge_ids) {
            auto& edge = this->m_edges[edge_id];
            auto& rev = this->m_edges[edge_id ^ 1];
            if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
              // We found a negative cycle, so fill it.
              // Later, we will check whether the component can be decomposed into smaller ones.  

              Cap cap = edge.cap - edge.flow;
              for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from) {
                const auto& current_edge = this->m_edges[prev[v]];
                ::tools::chmin(cap, current_edge.cap - current_edge.flow);
              }

              edge.flow += cap;
              rev.flow -= cap;
              this->m_slope.back().second += cap * edge.cost;
              for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from) {
                auto& current_edge = this->m_edges[prev[v]];
                auto& current_rev = this->m_edges[prev[v] ^ 1];
                current_edge.flow += cap;
                current_rev.flow -= cap;
                this->m_slope.back().second += cap * current_edge.cost;
              }

              scc_stack.push(new_scc_id);
              break;
            }
          }
        }
      }

      this->m_is_dag = ::std::all_of(scc.begin(), scc.end(), [](const auto& pair) { return pair.first.size() == 1; });
    }

    // This is for the first try to find the shortest path in a DAG with some negative edges.
    // We use topological sorting + DP. (O(V + E) time)
    ::std::pair<::std::vector<Cost>, ::std::vector<int>> find_shortest_path_by_dp(const int s) {
      ::std::vector<Cost> dist(this->size(), ::std::numeric_limits<Cost>::max());
      ::std::vector<int> prev(this->size(), -1);

      ::std::vector<int> indeg(this->size(), 0);
      for (const auto& edge : this->m_edges) {
        if (edge.flow < edge.cap) {
          ++indeg[edge.to];
        }
      }
      ::std::queue<int> queue;
      for (int v = 0; v < this->size(); ++v) {
        if (indeg[v] == 0) {
          queue.push(v);
        }
      }
      dist[s] = 0;
      while (!queue.empty()) {
        const auto here = queue.front();
        queue.pop();
        for (const auto edge_id : this->m_graph[here]) {
          const auto& edge = this->m_edges[edge_id];
          if (edge.flow < edge.cap) {
            if (dist[edge.from] < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
              prev[edge.to] = edge_id;
            }
            --indeg[edge.to];
            if (indeg[edge.to] == 0) {
              queue.push(edge.to);
            }
          }
        }
      }

      return ::std::make_pair(dist, prev);
    }

    // This is for the first try to find the shortest path in a graph with some negative edges and some non-negative cycles.
    // We use Bellman-Ford algorithm. (O(VE) time)
    ::std::pair<::std::vector<Cost>, ::std::vector<int>> find_shortest_path_by_bellman_ford(const int s) {
      ::std::vector<Cost> dist(this->size(), ::std::numeric_limits<Cost>::max());
      ::std::vector<int> prev(this->size(), -1);

      dist[s] = 0;
      for (int i = 0; i < this->size() - 1; ++i) {
        for (int edge_id = 0; edge_id < ::tools::ssize(this->m_edges); ++edge_id) {
          const auto& edge = this->m_edges[edge_id];
          if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
            prev[edge.to] = edge_id;
          }
        }
      }
      #ifndef NDEBUG
        for (const auto& edge : this->m_edges) {
          if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max()) {
            assert(dist[edge.to] <= dist[edge.from] + edge.cost);
          }
        }
      #endif

      return ::std::make_pair(dist, prev);
    }

    // This is for finding the shortest path in a graph without negative edges.
    // We use Dijkstra's algorithm with potentials. (O((V + E) logV) time)
    ::std::pair<::std::vector<Cost>, ::std::vector<int>> find_shortest_path_by_dijkstra(const int s) {
      ::std::vector<Cost> dist(this->size(), ::std::numeric_limits<Cost>::max());
      ::std::vector<int> prev(this->size(), -1);

      #ifndef NDEBUG
        for (const auto& edge : this->m_edges) {
          if (edge.flow < edge.cap && this->m_potentials[edge.from] < ::std::numeric_limits<Cost>::max() && this->m_potentials[edge.to] < ::std::numeric_limits<Cost>::max()) {
            assert(edge.cost + (this->m_potentials[edge.from] - this->m_potentials[edge.to]) >= 0);
          }
        }
      #endif
      dist[s] = 0;
      ::std::priority_queue<::std::pair<int, Cost>, ::std::vector<::std::pair<int, Cost>>, ::tools::greater_by_second> tasks;
      tasks.emplace(s, 0);
      while (!tasks.empty()) {
        const auto [here, d] = tasks.top();
        tasks.pop();
        if (dist[here] < d) continue;
        for (const auto edge_id : this->m_graph[here]) {
          const auto& edge = this->m_edges[edge_id];
          if (edge.flow < edge.cap && dist[edge.from] < ::std::numeric_limits<Cost>::max()) {
            assert(this->m_potentials[edge.from] < ::std::numeric_limits<Cost>::max());
            assert(this->m_potentials[edge.to] < ::std::numeric_limits<Cost>::max());
            if (::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost + (this->m_potentials[edge.from] - this->m_potentials[edge.to]))) {
              prev[edge.to] = edge_id;
              tasks.emplace(edge.to, dist[edge.to]);
            }
          }
        }
      }

      return ::std::make_pair(dist, prev);
    }

  public:
    ::std::vector<::std::pair<Cap, Cost>> slope(const int s, const int t, const Cap flow_limit) {
      assert(0 <= s && s < this->size());
      assert(0 <= t && t < this->size());
      assert(s != t);
      assert(this->m_slope.back().first <= flow_limit);

      if (!this->m_filled_negative_cycles) {
        this->fill_negative_cycles();
        this->m_filled_negative_cycles = true;
      }
      while (this->m_slope.back().first < flow_limit) {
        ::std::vector<Cost> dist;
        ::std::vector<int> prev;

        if (!this->m_calculated_potentials) {
          const bool has_negative_edge = ::std::any_of(this->m_edges.begin(), this->m_edges.end(), [](const auto& edge) { return edge.flow < edge.cap && edge.cost < 0; });
          if (has_negative_edge) {
            if (*this->m_is_dag) {
              ::std::tie(dist, prev) = this->find_shortest_path_by_dp(s);
            } else {
              ::std::tie(dist, prev) = this->find_shortest_path_by_bellman_ford(s);
            }
          } else {
            ::std::tie(dist, prev) = this->find_shortest_path_by_dijkstra(s);
          }
        } else {
          ::std::tie(dist, prev) = this->find_shortest_path_by_dijkstra(s);
        }

        if (dist[t] == ::std::numeric_limits<Cost>::max()) break;

        for (int i = 0; i < this->size(); ++i) {
          if (dist[i] < ::std::numeric_limits<Cost>::max()) {
            this->m_potentials[i] += dist[i];
          } else {
            this->m_potentials[i] = ::std::numeric_limits<Cost>::max();
          }
        }
        this->m_calculated_potentials = true;
        this->m_is_dag = ::std::nullopt;

        // Fill the shortest path.
        Cap cap = flow_limit - this->m_slope.back().first;
        for (int v = t; v != s; v = this->m_edges[prev[v]].from) {
          const auto& edge = this->m_edges[prev[v]];
          ::tools::chmin(cap, edge.cap - edge.flow);
        }

        Cost cost = 0;
        for (int v = t; v != s; v = this->m_edges[prev[v]].from) {
          auto& edge = this->m_edges[prev[v]];
          auto& rev = this->m_edges[prev[v] ^ 1];
          edge.flow += cap;
          rev.flow -= cap;
          cost += cap * edge.cost;
        }

        if ([&]() {
          if (this->m_slope.size() < 2) return true;
          auto dx1 = this->m_slope.back().first - this->m_slope.rbegin()[1].first;
          auto dy1 = this->m_slope.back().second - this->m_slope.rbegin()[1].second;
          const auto gcd1 = ::std::gcd(dx1, dy1);
          dx1 /= gcd1;
          dy1 /= gcd1;
          auto dx2 = cap;
          auto dy2 = cost;
          const auto gcd2 = ::std::gcd(dx2, dy2);
          dx2 /= gcd2;
          dy2 /= gcd2;
          return !(dx1 == dx2 && dy1 == dy2);
        }()) {
          this->m_slope.emplace_back(this->m_slope.back().first + cap, this->m_slope.back().second + cost);
        } else {
          this->m_slope.back().first += cap;
          this->m_slope.back().second += cost;
        }
      }

      return this->m_slope;
    }

    ::std::vector<::std::pair<Cap, Cost>> slope(const int s, const int t) {
      return this->slope(s, t, ::std::numeric_limits<Cap>::max());
    }

    ::std::pair<Cap, Cost> flow(const int s, const int t, const Cap flow_limit) {
      return this->slope(s, t, flow_limit).back();
    }

    ::std::pair<Cap, Cost> flow(const int s, const int t) {
      return this->slope(s, t).back();
    }

    ::tools::mcf_graph<Cap, Cost>::edge get_edge(const int i) const {
      assert(0 <= i && i < ::tools::ssize(this->m_edges) / 2);
      return this->m_edges[i * 2];
    }

    ::std::vector<::tools::mcf_graph<Cap, Cost>::edge> edges() const {
      ::std::vector<::tools::mcf_graph<Cap, Cost>::edge> result;
      for (int edge_id = 0; edge_id < ::tools::ssize(this->m_edges); edge_id += 2) {
        result.push_back(this->m_edges[edge_id]);
      }
      return result;
    }
  };
}

#endif
