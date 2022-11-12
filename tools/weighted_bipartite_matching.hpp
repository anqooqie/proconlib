#ifndef TOOLS_WEIGHTED_BIPARTITE_MATCHING_HPP
#define TOOLS_WEIGHTED_BIPARTITE_MATCHING_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <optional>
#include <utility>
#include <limits>
#include "tools/mcf_graph.hpp"
#include "tools/chmin.hpp"

namespace tools {
  template <typename W>
  class weighted_bipartite_matching {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
      W weight;
    };

  private:
    ::std::size_t m_size1;
    ::std::size_t m_size2;
    bool m_maximize;
    ::tools::mcf_graph<int, W> m_graph;
    ::std::vector<edge> m_edges;

  public:
    weighted_bipartite_matching() = default;
    weighted_bipartite_matching(const ::tools::weighted_bipartite_matching<W>&) = default;
    weighted_bipartite_matching(::tools::weighted_bipartite_matching<W>&&) = default;
    ~weighted_bipartite_matching() = default;
    ::tools::weighted_bipartite_matching<W>& operator=(const ::tools::weighted_bipartite_matching<W>&) = default;
    ::tools::weighted_bipartite_matching<W>& operator=(::tools::weighted_bipartite_matching<W>&&) = default;

    weighted_bipartite_matching(const ::std::size_t size1, const ::std::size_t size2, const bool maximize) :
      m_size1(size1), m_size2(size2), m_maximize(maximize), m_graph(size1 + size2 + 2) {
      for (::std::size_t i = 0; i < size1; ++i) {
        this->m_graph.add_edge(size1 + size2, i, 1, 0);
      }
      for (::std::size_t i = 0; i < size2; ++i) {
        this->m_graph.add_edge(size1 + i, size1 + size2 + 1, 1, 0);
      }
    }

    ::std::size_t size1() const {
      return this->m_size1;
    }

    ::std::size_t size2() const {
      return this->m_size2;
    }

    ::std::size_t add_edge(const ::std::size_t i, const ::std::size_t j, const W& w) {
      assert(i < this->size1());
      assert(j < this->size2());
      this->m_graph.add_edge(i, this->m_size1 + j, 1, this->m_maximize ? -w : w);
      this->m_edges.emplace_back(edge({this->m_edges.size(), i, j, w}));
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const ::std::size_t k) const {
      assert(k < this->m_edges.size());
      return this->m_edges[k];
    }

    const ::std::vector<edge>& edges() const {
      return this->m_edges;
    }

    ::std::optional<::std::pair<W, ::std::vector<::std::size_t>>> query(const ::std::size_t k) {
      const auto [flow, cost] = this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1, k);
      if (flow < static_cast<int>(k)) return ::std::nullopt;

      ::std::vector<::std::size_t> edges;
      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {
        if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1) {
          edges.push_back(i);
        }
      }

      return ::std::make_optional(::std::make_pair(this->m_maximize ? -cost : cost, edges));
    }

    ::std::pair<W, ::std::vector<::std::size_t>> query() {
      auto tmp_graph = this->m_graph;
      int min_cost_flow = 0;
      auto min_cost = ::std::numeric_limits<W>::max();
      for (const auto& [flow, cost] : tmp_graph.slope(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1)) {
        if (::tools::chmin(min_cost, cost)) {
          min_cost_flow = flow;
        }
      }

      const auto [flow, cost] = this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1, min_cost_flow);

      ::std::vector<::std::size_t> edges;
      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {
        if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1) {
          edges.push_back(i);
        }
      }

      return ::std::make_pair(this->m_maximize ? -cost : cost, edges);
    }
  };
}

#endif
