#ifndef TOOLS_ZERO_ONE_BFS_HPP
#define TOOLS_ZERO_ONE_BFS_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <limits>
#include <deque>
#include "tools/chmin.hpp"

namespace tools {

  template <bool Directed, typename T>
  class zero_one_bfs {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
      T cost;
    };

  private:
    ::std::vector<edge> m_edges;
    ::std::vector<::std::vector<::std::size_t>> m_graph;

  public:
    zero_one_bfs() = default;
    zero_one_bfs(const ::tools::zero_one_bfs<Directed, T>&) = default;
    zero_one_bfs(::tools::zero_one_bfs<Directed, T>&&) = default;
    ~zero_one_bfs() = default;
    ::tools::zero_one_bfs<Directed, T>& operator=(const ::tools::zero_one_bfs<Directed, T>&) = default;
    ::tools::zero_one_bfs<Directed, T>& operator=(::tools::zero_one_bfs<Directed, T>&&) = default;

    explicit zero_one_bfs(const ::std::size_t n) : m_graph(n) {
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T& w) {
      assert(u < this->size());
      assert(v < this->size());
      assert(w == 0 || w == 1);
      if constexpr (!Directed) {
        ::std::tie(u, v) = ::std::minmax({u, v});
      }
      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      if constexpr (!Directed) {
        this->m_graph[v].push_back(this->m_edges.size() - 1);
      }
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const ::std::size_t k) const {
      assert(k < this->m_edges.size());
      return this->m_edges[k];
    }

    const ::std::vector<edge>& edges() const {
      return this->m_edges;
    }

    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>> query(const ::std::size_t s) {
      assert(s < this->size());

      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());
      dist[s] = 0;
      ::std::vector<::std::size_t> prev(this->size());
      prev[s] = ::std::numeric_limits<::std::size_t>::max();
      ::std::deque<::std::pair<::std::size_t, T>> deque;
      deque.emplace_front(s, 0);

      while (!deque.empty()) {
        const auto [here, d] = deque.front();
        deque.pop_front();
        if (dist[here] < d) continue;
        for (const auto edge_id : this->m_graph[here]) {
          const auto& edge = this->m_edges[edge_id];
          const auto next = edge.to ^ (Directed ? 0 : edge.from ^ here);
          if (::tools::chmin(dist[next], dist[here] + edge.cost)) {
            prev[next] = edge.id;
            if (edge.cost == 0) {
              deque.emplace_front(next, dist[next]);
            } else {
              deque.emplace_back(next, dist[next]);
            }
          }
        }
      }

      return ::std::make_pair(dist, prev);
    }
  };
}

#endif
