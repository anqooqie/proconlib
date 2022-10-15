#ifndef TOOLS_TSP
#define TOOLS_TSP

#include <cstddef>
#include <vector>
#include <limits>
#include <cassert>
#include <utility>
#include <algorithm>
#include <optional>
#include <tuple>
#include "tools/pow2.hpp"
#include "tools/chmin.hpp"

namespace tools {

  template <bool Directed, typename T>
  class tsp {
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
    tsp() = default;
    tsp(const ::tools::tsp<Directed, T>&) = default;
    tsp(::tools::tsp<Directed, T>&&) = default;
    ~tsp() = default;
    ::tools::tsp<Directed, T>& operator=(const ::tools::tsp<Directed, T>&) = default;
    ::tools::tsp<Directed, T>& operator=(::tools::tsp<Directed, T>&&) = default;

    tsp(const ::std::size_t n) : m_graph(n, ::std::vector<::std::size_t>(n, ::std::numeric_limits<::std::size_t>::max())) {
      assert(n >= 2);
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T& w) {
      assert(u < this->size());
      assert(v < this->size());
      if constexpr (!Directed) {
        ::std::tie(u, v) = ::std::minmax({u, v});
      }
      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));
      if (this->m_graph[u][v] == ::std::numeric_limits<::std::size_t>::max() || w < this->m_edges[this->m_graph[u][v]].cost) {
        this->m_graph[u][v] = this->m_edges.size() - 1;
      }
      if constexpr (!Directed) {
        if (this->m_graph[v][u] == ::std::numeric_limits<::std::size_t>::max() || w < this->m_edges[this->m_graph[v][u]].cost) {
          this->m_graph[v][u] = this->m_edges.size() - 1;
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

    ::std::optional<::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>>> query() const {
      auto dp = ::std::vector(::tools::pow2(this->size()), ::std::vector(this->size(), ::std::numeric_limits<T>::max()));
      dp[0][0] = 0;
      for (::std::size_t state = 1; state < ::tools::pow2(this->size()); ++state) {
        for (::std::size_t v = 0; v < this->size(); ++v) {
          if ((static_cast<::std::size_t>(1) << v) & state) {
            const auto prev_state = state & ~(static_cast<::std::size_t>(1) << v);
            for (::std::size_t u = 0; u < this->size(); ++u) {
              if (this->m_graph[u][v] < ::std::numeric_limits<::std::size_t>::max()) {
                if (dp[prev_state][u] < ::std::numeric_limits<T>::max()) {
                  ::tools::chmin(dp[state][v], dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost);
                }
              }
            }
          }
        }
      }

      ::std::tuple<T, ::std::vector<::std::size_t>, ::std::vector<::std::size_t>> res;
      auto& [total_cost, vids, eids] = res;

      total_cost = dp[::tools::pow2(this->size()) - 1][0];
      if (total_cost == ::std::numeric_limits<T>::max()) return ::std::nullopt;

      ::std::size_t state = ::tools::pow2(this->size()) - 1;
      ::std::size_t v = 0;
      while (state > 0) {
        const auto prev_state = state & ~(static_cast<::std::size_t>(1) << v);
        for (::std::size_t u = 0; u < this->size(); ++u) {
          if (this->m_graph[u][v] < ::std::numeric_limits<::std::size_t>::max()) {
            if (dp[prev_state][u] < ::std::numeric_limits<T>::max() && dp[state][v] == dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost) {
              vids.push_back(u);
              eids.push_back(this->m_graph[u][v]);
              state = prev_state;
              v = u;
              break;
            }
          }
        }
      }

      ::std::reverse(vids.begin(), vids.end());
      ::std::reverse(eids.begin(), eids.end());

      return res;
    }
  };
}

#endif
