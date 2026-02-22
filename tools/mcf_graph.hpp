#ifndef TOOLS_MCF_GRAPH_HPP
#define TOOLS_MCF_GRAPH_HPP

#include <algorithm>
#include <cassert>
#include <limits>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>
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
    std::vector<std::vector<int>> m_graph;
    std::vector<edge> m_edges;
    std::vector<std::pair<Cap, Cost>> m_slope;
    std::vector<Cost> m_potentials;
    bool m_calculated_potentials;

    // O(V + E) shortest path on a DAG via topological sort + DP.
    std::pair<std::vector<Cost>, std::vector<int>> find_shortest_path_by_dp(const int s) {
      std::vector<Cost> dist(this->size(), std::numeric_limits<Cost>::max());
      std::vector<int> prev(this->size(), -1);

      std::vector<int> indeg(this->size(), 0);
      for (const auto& edge : this->m_edges) {
        if (edge.flow < edge.cap) {
          ++indeg[edge.to];
        }
      }
      std::queue<int> queue;
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
            if (dist[edge.from] < std::numeric_limits<Cost>::max() && tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
              prev[edge.to] = edge_id;
            }
            --indeg[edge.to];
            if (indeg[edge.to] == 0) {
              queue.push(edge.to);
            }
          }
        }
      }

      return std::make_pair(dist, prev);
    }

    // O(VE) shortest path via Bellman-Ford. Requires no negative cycles.
    std::pair<std::vector<Cost>, std::vector<int>> find_shortest_path_by_bellman_ford(const int s) {
      std::vector<Cost> dist(this->size(), std::numeric_limits<Cost>::max());
      std::vector<int> prev(this->size(), -1);

      dist[s] = 0;
      for (int i = 0; i < this->size() - 1; ++i) {
        for (int edge_id = 0; edge_id < std::ssize(this->m_edges); ++edge_id) {
          const auto& edge = this->m_edges[edge_id];
          if (edge.flow < edge.cap && dist[edge.from] < std::numeric_limits<Cost>::max() && tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
            prev[edge.to] = edge_id;
          }
        }
      }
      #ifndef NDEBUG
        for (const auto& edge : this->m_edges) {
          if (edge.flow < edge.cap && dist[edge.from] < std::numeric_limits<Cost>::max()) {
            assert(dist[edge.to] <= dist[edge.from] + edge.cost);
          }
        }
      #endif

      return std::make_pair(dist, prev);
    }

    // O((V + E) log V) shortest path via Dijkstra with potentials.
    std::pair<std::vector<Cost>, std::vector<int>> find_shortest_path_by_dijkstra(const int s) {
      std::vector<Cost> dist(this->size(), std::numeric_limits<Cost>::max());
      std::vector<int> prev(this->size(), -1);

      #ifndef NDEBUG
        for (const auto& edge : this->m_edges) {
          if (edge.flow < edge.cap && this->m_potentials[edge.from] < std::numeric_limits<Cost>::max() && this->m_potentials[edge.to] < std::numeric_limits<Cost>::max()) {
            assert(edge.cost + (this->m_potentials[edge.from] - this->m_potentials[edge.to]) >= 0);
          }
        }
      #endif
      dist[s] = 0;
      std::priority_queue<std::pair<int, Cost>, std::vector<std::pair<int, Cost>>, tools::greater_by_second> tasks;
      tasks.emplace(s, 0);
      while (!tasks.empty()) {
        const auto [here, d] = tasks.top();
        tasks.pop();
        if (dist[here] < d) continue;
        for (const auto edge_id : this->m_graph[here]) {
          const auto& edge = this->m_edges[edge_id];
          if (edge.flow < edge.cap && dist[edge.from] < std::numeric_limits<Cost>::max()) {
            assert(this->m_potentials[edge.from] < std::numeric_limits<Cost>::max());
            assert(this->m_potentials[edge.to] < std::numeric_limits<Cost>::max());
            if (tools::chmin(dist[edge.to], dist[edge.from] + edge.cost + (this->m_potentials[edge.from] - this->m_potentials[edge.to]))) {
              prev[edge.to] = edge_id;
              tasks.emplace(edge.to, dist[edge.to]);
            }
          }
        }
      }

      return std::make_pair(dist, prev);
    }

    bool is_dag() const {
      std::vector<int> indeg(this->size(), 0);
      for (const auto& edge : this->m_edges) {
        if (edge.flow < edge.cap) {
          ++indeg[edge.to];
        }
      }
      std::queue<int> queue;
      for (int v = 0; v < this->size(); ++v) {
        if (indeg[v] == 0) {
          queue.push(v);
        }
      }
      int count = 0;
      while (!queue.empty()) {
        const auto here = queue.front();
        queue.pop();
        ++count;
        for (const auto edge_id : this->m_graph[here]) {
          const auto& edge = this->m_edges[edge_id];
          if (edge.flow < edge.cap) {
            --indeg[edge.to];
            if (indeg[edge.to] == 0) {
              queue.push(edge.to);
            }
          }
        }
      }
      return count == this->size();
    }

  public:
    mcf_graph() = default;
    explicit mcf_graph(const int n) : m_graph(n), m_slope({{0, 0}}), m_potentials(n, 0), m_calculated_potentials(false) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(const int from, const int to, const Cap cap, const Cost cost) {
      assert(0 <= from && from < this->size());
      assert(0 <= to && to < this->size());
      assert(0 <= cap);

      this->m_graph[from].push_back(this->m_edges.size());
      this->m_edges.push_back({from, to, cap, 0, cost});
      this->m_graph[to].push_back(this->m_edges.size());
      this->m_edges.push_back({to, from, cap, cap, -cost});
      return this->m_edges.size() / 2 - 1;
    }

    std::vector<std::pair<Cap, Cost>> slope(const int s, const int t, const Cap flow_limit) {
      assert(0 <= s && s < this->size());
      assert(0 <= t && t < this->size());
      assert(s != t);
      assert(this->m_slope.back().first <= flow_limit);

      while (this->m_slope.back().first < flow_limit) {
        std::vector<Cost> dist;
        std::vector<int> prev;

        if (!this->m_calculated_potentials) {
          const bool has_negative_edge = std::any_of(this->m_edges.begin(), this->m_edges.end(), [](const auto& edge) { return edge.flow < edge.cap && edge.cost < 0; });
          if (has_negative_edge) {
            if (this->is_dag()) {
              std::tie(dist, prev) = this->find_shortest_path_by_dp(s);
            } else {
              std::tie(dist, prev) = this->find_shortest_path_by_bellman_ford(s);
            }
          } else {
            std::tie(dist, prev) = this->find_shortest_path_by_dijkstra(s);
          }
        } else {
          std::tie(dist, prev) = this->find_shortest_path_by_dijkstra(s);
        }

        if (dist[t] == std::numeric_limits<Cost>::max()) break;

        for (int i = 0; i < this->size(); ++i) {
          if (dist[i] < std::numeric_limits<Cost>::max()) {
            this->m_potentials[i] += dist[i];
          } else {
            this->m_potentials[i] = std::numeric_limits<Cost>::max();
          }
        }
        this->m_calculated_potentials = true;

        // Fill the shortest path.
        Cap cap = flow_limit - this->m_slope.back().first;
        for (int v = t; v != s; v = this->m_edges[prev[v]].from) {
          const auto& edge = this->m_edges[prev[v]];
          tools::chmin(cap, edge.cap - edge.flow);
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
          const auto gcd1 = std::gcd(dx1, dy1);
          dx1 /= gcd1;
          dy1 /= gcd1;
          auto dx2 = cap;
          auto dy2 = cost;
          const auto gcd2 = std::gcd(dx2, dy2);
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

    std::vector<std::pair<Cap, Cost>> slope(const int s, const int t) {
      return this->slope(s, t, std::numeric_limits<Cap>::max());
    }

    std::pair<Cap, Cost> flow(const int s, const int t, const Cap flow_limit) {
      return this->slope(s, t, flow_limit).back();
    }

    std::pair<Cap, Cost> flow(const int s, const int t) {
      return this->slope(s, t).back();
    }

    edge get_edge(const int i) const {
      assert(0 <= i && i < std::ssize(this->m_edges) / 2);
      return this->m_edges[i * 2];
    }

    std::vector<edge> edges() const {
      std::vector<edge> result;
      for (int edge_id = 0; edge_id < std::ssize(this->m_edges); edge_id += 2) {
        result.push_back(this->m_edges[edge_id]);
      }
      return result;
    }
  };
}

#endif
