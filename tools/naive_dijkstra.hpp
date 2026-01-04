#ifndef TOOLS_NAIVE_DIJKSTRA_HPP
#define TOOLS_NAIVE_DIJKSTRA_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/getter_result.hpp"
#include "tools/integral.hpp"
#include "tools/less_by.hpp"
#include "tools/shortest_path_tree.hpp"

namespace tools {
  template <bool Directed, tools::integral T>
  class naive_dijkstra {
  public:
    struct edge {
      int from;
      int to;
      T cost;
    };

  private:
    int m_size;
    std::vector<edge> m_edges;
    std::vector<int> m_graph;

  public:
    naive_dijkstra() = default;
    explicit naive_dijkstra(const int n) : m_size(n), m_graph(n * n, -1) {
    }

    int size() const {
      return this->m_size;
    }

    int add_edge(int u, int v, const T w) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      assert(w >= 0);
      if constexpr (!Directed) {
        std::tie(u, v) = std::minmax({u, v});
      }
      this->m_edges.push_back({u, v, w});
      if (this->m_graph[u * this->size() + v] < 0 || w < this->m_edges[this->m_graph[u * this->size() + v]].cost) {
        this->m_graph[u * this->size() + v] = this->m_edges.size() - 1;
        if constexpr (!Directed) {
            this->m_graph[v * this->size() + u] = this->m_edges.size() - 1;
        }
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

      std::vector<int> Q(this->size());
      std::iota(Q.begin(), Q.end(), 0);
      while (!Q.empty()) {
        const auto min_it = std::ranges::min_element(Q, tools::less_by([&](const auto v) { return dist[v]; }));
        const auto here = *min_it;
        if (dist[here] == std::numeric_limits<T>::max()) break;

        std::iter_swap(min_it, std::prev(Q.end()));
        Q.pop_back();

        for (const auto next : Q) {
          const auto edge_id = this->m_graph[here * this->size() + next];
          if (edge_id >= 0 && tools::chmin(dist[next], dist[here] + this->m_edges[edge_id].cost)) {
            if constexpr (Restore) {
              prev[next] = edge_id;
            }
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
