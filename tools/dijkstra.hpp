#ifndef TOOLS_DIJKSTRA_HPP
#define TOOLS_DIJKSTRA_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/getter_result.hpp"
#include "tools/greater_by_second.hpp"
#include "tools/shortest_path_tree.hpp"

namespace tools {

  template <bool Directed, typename T>
  class dijkstra {
  public:
    struct edge {
      int from;
      int to;
      T cost;
    };

  private:
    std::vector<edge> m_edges;
    std::vector<std::vector<int>> m_graph;

  public:
    dijkstra() = default;
    explicit dijkstra(const int n) : m_graph(n) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(int u, int v, const T w) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      assert(w >= 0);
      if constexpr (!Directed) {
        std::tie(u, v) = std::minmax({u, v});
      }
      this->m_edges.push_back({u, v, w});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      if constexpr (!Directed) {
        this->m_graph[v].push_back(this->m_edges.size() - 1);
      }
      return this->m_edges.size() - 1;
    }

    auto get_edge(this auto&& self, const int k) -> tools::getter_result_t<decltype(self), edge> {
      assert(0 <= k && k < std::ssize(self.m_edges));
      return std::forward_like<decltype(self)>(self.m_edges[k]);
    }

    auto edges(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<edge>> {
      return std::forward_like<decltype(self)>(self.m_edges);
    }

    template <bool Restore = false>
    auto query(const int s) const {
      assert(0 <= s && s < this->size());

      std::vector<T> dist(this->size(), std::numeric_limits<T>::max());
      dist[s] = 0;
      std::vector<int> prev(Restore ? this->size() : 0, -1);

      std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, tools::greater_by_second> pq;
      pq.emplace(s, 0);

      while (!pq.empty()) {
        const auto [here, d] = pq.top();
        pq.pop();
        if (dist[here] < d) continue;
        for (const auto edge_id : this->m_graph[here]) {
          const auto& edge = this->m_edges[edge_id];
          const auto next = edge.to ^ (Directed ? 0 : edge.from ^ here);
          if (tools::chmin(dist[next], dist[here] + edge.cost)) {
            if constexpr (Restore) {
              prev[next] = edge_id;
            }
            pq.emplace(next, dist[next]);
          }
        }
      }

      if constexpr (Restore) {
        return tools::shortest_path_tree(dist, prev, [&](const auto e, const auto v) {
          return this->m_edges[e].from ^ (Directed ? 0 : this->m_edges[e].to ^ v);
        });
      } else {
        return dist;
      }
    }
  };
}

#endif
