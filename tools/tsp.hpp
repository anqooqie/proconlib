#ifndef TOOLS_TSP_HPP
#define TOOLS_TSP_HPP

#include <algorithm>
#include <cassert>
#include <limits>
#include <optional>
#include <type_traits>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/getter_result.hpp"
#include "tools/integral.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <bool Directed, tools::integral T>
  class tsp {
  public:
    struct edge {
      int from;
      int to;
      T cost;
    };

  private:
    std::vector<edge> m_edges;
    std::vector<std::vector<int>> m_graph;
    constexpr static int NONE = -1;

  public:
    tsp() = default;
    explicit tsp(const int n) : m_graph(n, std::vector(n, NONE)) {
      assert(n >= 2);
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(int u, int v, const T& w) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      if constexpr (!Directed) {
        std::tie(u, v) = std::minmax({u, v});
      }
      this->m_edges.push_back({u, v, w});
      if (this->m_graph[u][v] == NONE || w < this->m_edges[this->m_graph[u][v]].cost) {
        this->m_graph[u][v] = this->m_edges.size() - 1;
      }
      if constexpr (!Directed) {
        if (this->m_graph[v][u] == NONE || w < this->m_edges[this->m_graph[v][u]].cost) {
          this->m_graph[v][u] = this->m_edges.size() - 1;
        }
      }
      return this->m_edges.size() - 1;
    }

    auto get_edge(this auto&& self, const int k) -> tools::getter_result_t<decltype(self), edge> {
      assert(0 <= k && k < self.m_edges.size());
      return std::forward_like<decltype(self)>(self.m_edges[k]);
    }

    auto edges(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<edge>> {
      return std::forward_like<decltype(self)>(self.m_edges);
    }

    template <bool Restore = false>
    std::optional<std::conditional_t<Restore, std::tuple<T, std::vector<int>, std::vector<int>>, T>> query() const {
      auto dp = std::vector(tools::pow2(this->size()), std::vector(this->size(), std::numeric_limits<T>::max()));
      dp[0][0] = 0;
      for (int state = 1; state < tools::pow2(this->size()); ++state) {
        for (int v = 0; v < this->size(); ++v) {
          if ((1 << v) & state) {
            const auto prev_state = state ^ (1 << v);
            for (int u = 0; u < this->size(); ++u) {
              if (this->m_graph[u][v] != NONE && dp[prev_state][u] < std::numeric_limits<T>::max()) {
                tools::chmin(dp[state][v], dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost);
              }
            }
          }
        }
      }

      std::tuple<T, std::vector<int>, std::vector<int>> res;
      [[maybe_unused]] auto& [total_cost, vids, eids] = res;

      total_cost = dp[tools::pow2(this->size()) - 1][0];
      if (total_cost == std::numeric_limits<T>::max()) return std::nullopt;

      int state = tools::pow2(this->size()) - 1;
      int v = 0;
      while (state > 0) {
        const auto prev_state = state ^ (1 << v);
        for (int u = 0; u < this->size(); ++u) {
          if (this->m_graph[u][v] != NONE && dp[prev_state][u] < std::numeric_limits<T>::max() && dp[state][v] == dp[prev_state][u] + this->m_edges[this->m_graph[u][v]].cost) {
            if constexpr (Restore) {
              vids.push_back(u);
              eids.push_back(this->m_graph[u][v]);
            }
            state = prev_state;
            v = u;
            break;
          }
        }
      }

      if constexpr (Restore) {
        std::ranges::reverse(vids);
        std::ranges::reverse(eids);
        return res;
      } else {
        return total_cost;
      }
    }
  };
}

#endif
