#ifndef TOOLS_NAIVE_DIJKSTRA_HPP
#define TOOLS_NAIVE_DIJKSTRA_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iterator>
#include "tools/less_by.hpp"
#include "tools/chmin.hpp"

namespace tools {

  template <bool Directed, typename T>
  class naive_dijkstra {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
      T cost;
    };

  private:
    ::std::size_t m_size;
    ::std::vector<edge> m_edges;
    ::std::vector<::std::size_t> m_graph;

  public:
    naive_dijkstra() = default;
    naive_dijkstra(const ::tools::naive_dijkstra<Directed, T>&) = default;
    naive_dijkstra(::tools::naive_dijkstra<Directed, T>&&) = default;
    ~naive_dijkstra() = default;
    ::tools::naive_dijkstra<Directed, T>& operator=(const ::tools::naive_dijkstra<Directed, T>&) = default;
    ::tools::naive_dijkstra<Directed, T>& operator=(::tools::naive_dijkstra<Directed, T>&&) = default;

    explicit naive_dijkstra(const ::std::size_t n) : m_size(n), m_graph(n * n, ::std::numeric_limits<::std::size_t>::max()) {
    }

    ::std::size_t size() const {
      return this->m_size;
    }

    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T& w) {
      assert(u < this->size());
      assert(v < this->size());
      assert(w >= 0);
      if constexpr (!Directed) {
        ::std::tie(u, v) = ::std::minmax({u, v});
      }
      this->m_edges.push_back(edge{this->m_edges.size(), u, v, w});
      if (this->m_graph[u * this->size() + v] == ::std::numeric_limits<::std::size_t>::max() || w < this->m_edges[this->m_graph[u * this->size() + v]].cost) {
        this->m_graph[u * this->size() + v] = this->m_edges.size() - 1;
        if constexpr (!Directed) {
            this->m_graph[v * this->size() + u] = this->m_edges.size() - 1;
        }
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

    ::std::pair<::std::vector<T>, ::std::vector<::std::size_t>> query(const ::std::size_t s) const {
      assert(s < this->size());

      ::std::vector<T> dist(this->size(), ::std::numeric_limits<T>::max());
      dist[s] = 0;
      ::std::vector<::std::size_t> prev(this->size());
      prev[s] = ::std::numeric_limits<::std::size_t>::max();

      ::std::vector<::std::size_t> Q(this->size());
      ::std::iota(Q.begin(), Q.end(), 0);
      while (!Q.empty()) {
        const auto min_it = ::std::min_element(Q.begin(), Q.end(), ::tools::less_by([&](const auto v) { return dist[v]; }));
        const auto here = *min_it;
        if (dist[here] == ::std::numeric_limits<T>::max()) break;

        ::std::iter_swap(min_it, ::std::prev(Q.end()));
        Q.pop_back();

        for (const auto next : Q) {
          if (this->m_graph[here * this->size() + next] != ::std::numeric_limits<::std::size_t>::max() && ::tools::chmin(dist[next], dist[here] + this->m_edges[this->m_graph[here * this->size() + next]].cost)) {
            prev[next] = this->m_graph[here * this->size() + next];
          }
        }
      }

      return ::std::make_pair(dist, prev);
    }
  };
}

#endif
