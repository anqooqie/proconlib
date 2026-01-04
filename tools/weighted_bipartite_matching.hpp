#ifndef TOOLS_WEIGHTED_BIPARTITE_MATCHING_HPP
#define TOOLS_WEIGHTED_BIPARTITE_MATCHING_HPP

#include <cassert>
#include <cstddef>
#include <iterator>
#include <limits>
#include <optional>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/getter_result.hpp"
#include "tools/mcf_graph.hpp"

namespace tools {
  template <bool Maximize, typename W>
  requires std::same_as<W, int> || std::same_as<W, long long>
  class weighted_bipartite_matching {
  public:
    struct edge {
      int from;
      int to;
      W weight;
    };

  private:
    int m_size1;
    int m_size2;
    tools::mcf_graph<int, W> m_graph;
    std::vector<edge> m_edges;

  public:
    weighted_bipartite_matching() = default;
    weighted_bipartite_matching(const int size1, const int size2) :
      m_size1(size1), m_size2(size2), m_graph(size1 + size2 + 2) {
      assert(size1 >= 0);
      assert(size2 >= 0);
      for (int i = 0; i < size1; ++i) {
        this->m_graph.add_edge(size1 + size2, i, 1, 0);
      }
      for (int i = 0; i < size2; ++i) {
        this->m_graph.add_edge(size1 + i, size1 + size2 + 1, 1, 0);
      }
    }

    int size1() const {
      return this->m_size1;
    }

    int size2() const {
      return this->m_size2;
    }

    int add_edge(const int i, const int j, const W w) {
      assert(i < this->size1());
      assert(j < this->size2());
      this->m_graph.add_edge(i, this->m_size1 + j, 1, Maximize ? -w : w);
      this->m_edges.push_back({i, j, w});
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
    std::optional<std::conditional_t<Restore, std::vector<int>, W>> query(const int k) {
      assert(k >= 0);
      const auto [flow, cost] = this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1, k);
      if (flow < k) return std::nullopt;

      if constexpr (Restore) {
        std::vector<int> edges;
        for (int i = 0; i < std::ssize(this->m_edges); ++i) {
          if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1) {
            edges.push_back(i);
          }
        }
        return std::make_optional(std::move(edges));
      } else {
        return std::make_optional(Maximize ? -cost : cost);
      }
    }

    template <bool Restore = false>
    std::conditional_t<Restore, std::vector<int>, W> query() {
      auto tmp_graph = this->m_graph;
      int min_cost_flow = 0;
      auto min_cost = std::numeric_limits<W>::max();
      for (const auto& [flow, cost] : tmp_graph.slope(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1)) {
        if (tools::chmin(min_cost, cost)) {
          min_cost_flow = flow;
        }
      }

      const auto [flow, cost] = this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1, min_cost_flow);

      if constexpr (Restore) {
        std::vector<int> edges;
        for (int i = 0; i < std::ssize(this->m_edges); ++i) {
          if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1) {
            edges.push_back(i);
          }
        }
        return edges;
      } else {
        return Maximize ? -cost : cost;
      }
    }
  };
}

#endif
