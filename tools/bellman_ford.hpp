#ifndef TOOLS_BELLMAN_FORD_HPP
#define TOOLS_BELLMAN_FORD_HPP

#include <cassert>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/shortest_path_tree.hpp"

namespace tools {

  template <typename T>
  class bellman_ford {
  public:
    struct edge {
      int from;
      int to;
      T cost;
    };

  private:
    int m_size;
    ::std::vector<edge> m_edges;

  public:
    bellman_ford() = default;
    explicit bellman_ford(const int n) : m_size(n) {
    }

    int size() const {
      return this->m_size;
    }

    int add_edge(const int u, const int v, const T w) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      this->m_edges.push_back({u, v, w});
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const int k) const & {
      assert(0 <= k && k < ::std::ssize(this->m_edges));
      return this->m_edges[k];
    }
    edge get_edge(const int k) && {
      assert(0 <= k && k < ::std::ssize(this->m_edges));
      return ::std::move(this->m_edges[k]);
    }

    const ::std::vector<edge>& edges() const & {
      return this->m_edges;
    }
    ::std::vector<edge> edges() && {
      return ::std::move(this->m_edges);
    }

    template <bool Restore = false>
    auto query(const int s) const {
      assert(0 <= s && s < this->size());

      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());
      dist[s] = 0;
      ::std::vector<int> prev(Restore ? this->size() : 0, -1);

      for (int i = 0; i + 1 < this->size(); ++i) {
        for (int k = 0; k < ::std::ssize(this->m_edges); ++k) {
          const auto& edge = this->m_edges[k];
          if (dist[edge.from] < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
            if constexpr (Restore) {
              prev[edge.to] = k;
            }
          }
        }
      }
      for (int k = 0; k < ::std::ssize(this->m_edges); ++k) {
        const auto& edge = this->m_edges[k];
        if (dist[edge.from] < ::std::numeric_limits<T>::max() && dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::lowest() ? edge.cost : 0) < dist[edge.to]) {
          dist[edge.to] = ::std::numeric_limits<T>::lowest();
          if constexpr (Restore) {
            prev[edge.to] = -1;
          }
        }
      }
      for (int i = 0; i + 1 < this->size(); ++i) {
        for (int k = 0; k < ::std::ssize(this->m_edges); ++k) {
          const auto& edge = this->m_edges[k];
          if (dist[edge.from] < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::lowest() ? edge.cost : 0))) {
            if constexpr (Restore) {
              prev[edge.to] = -1;
            }
          }
        }
      }

      if constexpr (Restore) {
        return ::tools::shortest_path_tree(dist, prev, [&](const auto e, auto) {
          return this->m_edges[e].from;
        });
      } else {
        return dist;
      }
    }
  };
}

#endif
