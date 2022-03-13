#ifndef TOOLS_MCF_GRAPH_HPP
#define TOOLS_MCF_GRAPH_HPP

#include <vector>
#include <cassert>
#include <limits>
#include <utility>
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

    explicit mcf_graph(const int n) : m_graph(n) {
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

    ::std::vector<::std::pair<Cap, Cost>> slope(const int s, const int t, const Cap flow_limit) {
      assert(0 <= s && s < this->size());
      assert(0 <= t && t < this->size());
      assert(s != t);

      ::std::vector<::std::pair<Cap, Cost>> result;
      result.emplace_back(0, 0);

      ::std::vector<::std::pair<::std::vector<int>, ::std::vector<int>>> scc({::std::make_pair(::std::vector<int>(this->size()), ::std::vector<int>(this->m_edges.size()))});
      ::std::iota(scc[0].first.begin(), scc[0].first.end(), 0);
      ::std::iota(scc[0].second.begin(), scc[0].second.end(), 0);
      ::std::vector<int> scc_inv(this->size(), 0);
      ::std::stack<int> scc_stack({0});
      ::std::vector<bool> will_visit(this->size());
      ::std::vector<Cost> dist(this->size());
      ::std::vector<int> prev(this->size());
      while (!scc_stack.empty()) {
        const auto scc_id = scc_stack.top();
        scc_stack.pop();
        ::std::vector<int> scc_vertices;
        ::std::vector<int> scc_edge_ids;
        scc_vertices.swap(scc[scc_id].first);
        scc_edge_ids.swap(scc[scc_id].second);

        ::std::stack<int> ordered_by_dfs;
        for (const auto v : scc_vertices) {
          will_visit[v] = false;
        }
        for (const auto root : scc_vertices) {
          if (will_visit[root]) continue;

          ::std::stack<int> stack({root});
          will_visit[root] = true;
          ordered_by_dfs.push(root);
          while (!stack.empty()) {
            const auto here = stack.top();
            stack.pop();
            for (const auto edge_id : this->m_graph[here]) {
              const auto& edge = this->m_edges[edge_id];
              if (edge.flow < edge.cap && !will_visit[edge.to]) {
                stack.push(edge.to);
                will_visit[edge.to] = true;
                ordered_by_dfs.push(edge.to);
              }
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
              Cap cap = edge.cap - edge.flow;
              for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from) {
                const auto& current_edge = this->m_edges[prev[v]];
                ::tools::chmin(cap, current_edge.cap - current_edge.flow);
              }

              edge.flow += cap;
              rev.flow -= cap;
              result.back().second += cap * edge.cost;
              for (int v = edge.from; v != edge.to; v = this->m_edges[prev[v]].from) {
                auto& current_edge = this->m_edges[prev[v]];
                auto& current_rev = this->m_edges[prev[v] ^ 1];
                current_edge.flow += cap;
                current_rev.flow -= cap;
                result.back().second += cap * current_edge.cost;
              }

              scc_stack.push(new_scc_id);
              break;
            }
          }
        }
      }

      ::std::vector<Cost> potentials(this->size(), 0);
      bool has_negative_edge = ::std::any_of(this->m_edges.begin(), this->m_edges.end(), [](const auto& edge) { return edge.flow < edge.cap && edge.cost < 0; });
      while (result.back().first < flow_limit) {
        ::std::fill(dist.begin(), dist.end(), ::std::numeric_limits<Cost>::max());
        ::std::fill(prev.begin(), prev.end(), -1);
        if (has_negative_edge) {
          if (::std::all_of(scc.begin(), scc.end(), [](const auto& pair) { return pair.first.size() == 1; })) {
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
          } else {
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
          }
        } else {
          #ifndef NDEBUG
            for (const auto& edge : this->m_edges) {
              if (edge.flow < edge.cap && potentials[edge.from] < ::std::numeric_limits<Cost>::max() && potentials[edge.to] < ::std::numeric_limits<Cost>::max()) {
                 assert(edge.cost + potentials[edge.from] - potentials[edge.to] >= 0);
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
                assert(potentials[edge.from] < ::std::numeric_limits<Cost>::max());
                assert(potentials[edge.to] < ::std::numeric_limits<Cost>::max());
                if (::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost + potentials[edge.from] - potentials[edge.to])) {
                  prev[edge.to] = edge_id;
                  tasks.emplace(edge.to, dist[edge.to]);
                }
              }
            }
          }
        }

        if (dist[t] == ::std::numeric_limits<Cost>::max()) break;
        for (int i = 0; i < this->size(); ++i) {
          if (dist[i] < ::std::numeric_limits<Cost>::max()) {
            potentials[i] += dist[i];
          } else {
            potentials[i] = ::std::numeric_limits<Cost>::max();
          }
        }
        has_negative_edge = false;

        Cap cap = flow_limit - result.back().first;
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

        result.emplace_back(result.back().first + cap, result.back().second + cost);
      }

      return result;
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
