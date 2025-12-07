#ifndef TOOLS_ZERO_ONE_BFS_HPP
#define TOOLS_ZERO_ONE_BFS_HPP

#include <algorithm>
#include <cassert>
#include <deque>
#include <iterator>
#include <limits>
#include <utility>
#include <tuple>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/shortest_path_tree.hpp"

namespace tools {

  template <bool Directed, typename T>
  class zero_one_bfs {
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
    zero_one_bfs() = default;
    explicit zero_one_bfs(const int n) : m_graph(n) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(int u, int v, const T w) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      assert(w == 0 || w == 1);
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

    const edge& get_edge(const int k) const & {
      assert(0 <= k && k < std::ssize(this->m_edges));
      return this->m_edges[k];
    }
    edge get_edge(const int k) && {
      assert(0 <= k && k < std::ssize(this->m_edges));
      return std::move(this->m_edges[k]);
    }

    const std::vector<edge>& edges() const & {
      return this->m_edges;
    }
    std::vector<edge> edges() && {
      return std::move(this->m_edges);
    }

    template <bool Restore = false>
    auto query(const int s) const {
      assert(0 <= s && s < this->size());

      std::vector<T> dist(this->size(), std::numeric_limits<T>::max());
      dist[s] = 0;
      std::vector<int> prev(Restore ? this->size() : 0, -1);
      std::deque<std::pair<int, T>> deque;
      deque.emplace_front(s, 0);

      while (!deque.empty()) {
        const auto [here, d] = deque.front();
        deque.pop_front();
        if (dist[here] < d) continue;
        for (const auto edge_id : this->m_graph[here]) {
          const auto& edge = this->m_edges[edge_id];
          const auto next = edge.to ^ (Directed ? 0 : edge.from ^ here);
          if (tools::chmin(dist[next], dist[here] + edge.cost)) {
            if constexpr (Restore) {
              prev[next] = edge.id;
            }
            if (edge.cost == 0) {
              deque.emplace_front(next, dist[next]);
            } else {
              deque.emplace_back(next, dist[next]);
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
