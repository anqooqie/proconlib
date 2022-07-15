#ifndef TOOLS_BELLMAN_FORD_HPP
#define TOOLS_BELLMAN_FORD_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <utility>
#include <limits>
#include "tools/chmin.hpp"

namespace tools {

  template <typename T>
  class bellman_ford {
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

  public:
    bellman_ford() = default;
    bellman_ford(const ::tools::bellman_ford<T>&) = default;
    bellman_ford(::tools::bellman_ford<T>&&) = default;
    ~bellman_ford() = default;
    ::tools::bellman_ford<T>& operator=(const ::tools::bellman_ford<T>&) = default;
    ::tools::bellman_ford<T>& operator=(::tools::bellman_ford<T>&&) = default;

    bellman_ford(const ::std::size_t n) : m_size(n) {
    }

    ::std::size_t size() const {
      return this->m_size;
    }

    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t v, const T& w) {
      assert(u < this->size());
      assert(v < this->size());
      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));
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

      for (::std::size_t i = 0; i + 1 < this->size(); ++i) {
        for (const auto& edge : this->m_edges) {
          if (dist[edge.from] < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + edge.cost)) {
            prev[edge.to] = edge.id;
          }
        }
      }
      for (const auto& edge : this->m_edges) {
        if (dist[edge.from] < ::std::numeric_limits<T>::max() && dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost : 0) < dist[edge.to]) {
          dist[edge.to] = ::std::numeric_limits<T>::min();
          prev[edge.to] = edge.id;
        }
      }
      for (::std::size_t i = 0; i + 1 < this->size(); ++i) {
        for (const auto& edge : this->m_edges) {
          if (dist[edge.from] < ::std::numeric_limits<T>::max() && ::tools::chmin(dist[edge.to], dist[edge.from] + (dist[edge.from] > ::std::numeric_limits<T>::min() ? edge.cost : 0))) {
            prev[edge.to] = edge.id;
          }
        }
      }

      return ::std::make_pair(dist, prev);
    }
  };
}

#endif
