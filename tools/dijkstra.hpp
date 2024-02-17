#ifndef TOOLS_DIJKSTRA_HPP
#define TOOLS_DIJKSTRA_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <limits>
#include <queue>
#include "tools/ceil_log2.hpp"
#include "tools/greater_by_second.hpp"
#include "tools/chmin.hpp"
#include "tools/dynamic_bitset.hpp"

namespace tools {

  template <bool Directed, typename T>
  class dijkstra {
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
    dijkstra() = default;
    dijkstra(const ::tools::dijkstra<Directed, T>&) = default;
    dijkstra(::tools::dijkstra<Directed, T>&&) = default;
    ~dijkstra() = default;
    ::tools::dijkstra<Directed, T>& operator=(const ::tools::dijkstra<Directed, T>&) = default;
    ::tools::dijkstra<Directed, T>& operator=(::tools::dijkstra<Directed, T>&&) = default;

    dijkstra(const ::std::size_t n) : m_graph(n) {
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T& w) {
      assert(u < this->size());
      assert(v < this->size());
      assert(w >= 0);
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

      if ((this->size() + this->m_edges.size()) * ::tools::ceil_log2(this->size()) < this->size() * this->size() + this->m_edges.size()) {
        // Dijkstra for sparse graph: O((|V| + |E|) log|V|)

        ::std::priority_queue<::std::pair<::std::size_t, T>, ::std::vector<::std::pair<::std::size_t, T>>, ::tools::greater_by_second> pq;
        pq.emplace(s, 0);

        while (!pq.empty()) {
          const auto [here, d] = pq.top();
          pq.pop();
          if (dist[here] < d) continue;
          for (const auto edge_id : this->m_graph[here]) {
            const auto& edge = this->m_edges[edge_id];
            const auto next = edge.to ^ (Directed ? 0 : edge.from ^ here);
            if (::tools::chmin(dist[next], dist[here] + edge.cost)) {
              prev[next] = edge.id;
              pq.emplace(next, dist[next]);
            }
          }
        }

      } else {
        // Dijkstra for dense graph: O(|V|^2 + |E|)

        auto matrix = ::std::vector(this->size(), ::std::vector(this->size(), ::std::numeric_limits<::std::size_t>::max()));
        for (const auto& edge : this->m_edges) {
          if (matrix[edge.from][edge.to] == ::std::numeric_limits<::std::size_t>::max() || edge.cost < this->m_edges[matrix[edge.from][edge.to]].cost) {
            matrix[edge.from][edge.to] = edge.id;
          }
        }

        ::tools::dynamic_bitset Q(this->size());
        Q.set();
        ::std::size_t v;
        while ((v = Q.Find_first()) < this->size()) {
          ::std::size_t here;
          T d = ::std::numeric_limits<T>::max();
          for (; v < this->size(); v = Q.Find_next(v)) {
            if (::tools::chmin(d, dist[v])) {
              here = v;
            }
          }
          if (d == ::std::numeric_limits<T>::max()) break;
          Q.reset(here);

          for (v = Q.Find_first(); v < this->size(); v = Q.Find_next(v)) {
            if (matrix[here][v] != ::std::numeric_limits<::std::size_t>::max() && ::tools::chmin(dist[v], dist[here] + this->m_edges[matrix[here][v]].cost)) {
              prev[v] = matrix[here][v];
            }
          }
        }

      }

      return ::std::make_pair(dist, prev);
    }
  };
}

#endif
