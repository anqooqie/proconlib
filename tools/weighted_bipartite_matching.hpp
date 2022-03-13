#ifndef TOOLS_WEIGHTED_BIPARTITE_MATCHING_HPP
#define TOOLS_WEIGHTED_BIPARTITE_MATCHING_HPP

#include <cstddef>
#include <vector>
#include <utility>
#include "tools/mcf_graph.hpp"

namespace tools {
  template <typename W, typename E>
  class weighted_bipartite_matching {
  public:
    struct edge {
      ::std::size_t from;
      ::std::size_t to;
      W weight;
      E attribute;
      edge() = default;
      edge(const ::tools::weighted_bipartite_matching<W, E>::edge&) = default;
      edge(::tools::weighted_bipartite_matching<W, E>::edge&&) = default;
      ~edge() = default;
      ::tools::weighted_bipartite_matching<W, E>::edge& operator=(const ::tools::weighted_bipartite_matching<W, E>::edge&) = default;
      ::tools::weighted_bipartite_matching<W, E>::edge& operator=(::tools::weighted_bipartite_matching<W, E>::edge&&) = default;
      edge(const ::std::size_t from, const ::std::size_t to, const W& weight, const E& attribute) :
        from(from), to(to), weight(weight), attribute(attribute) {
      }
    };

  private:
    ::std::size_t m_size1;
    ::std::size_t m_size2;
    bool m_maximize;
    ::tools::mcf_graph<int, W> m_graph;
    ::std::vector<::tools::weighted_bipartite_matching<W, E>::edge> m_edges;

  public:
    weighted_bipartite_matching() = default;
    weighted_bipartite_matching(const ::tools::weighted_bipartite_matching<W, E>&) = default;
    weighted_bipartite_matching(::tools::weighted_bipartite_matching<W, E>&&) = default;
    ~weighted_bipartite_matching() = default;
    ::tools::weighted_bipartite_matching<W, E>& operator=(const ::tools::weighted_bipartite_matching<W, E>&) = default;
    ::tools::weighted_bipartite_matching<W, E>& operator=(::tools::weighted_bipartite_matching<W, E>&&) = default;

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

    void add_edge(const ::std::size_t i, const ::std::size_t j, const W& w, const E& e) {
      this->m_graph.add_edge(i, this->m_size1 + j, 1, (this->m_maximize ? -1 : 1) * w);
      this->m_edges.emplace_back(i, j, w, e);
    }

    ::std::pair<W, ::std::vector<::tools::weighted_bipartite_matching<W, E>::edge>> query() {
      ::std::vector<::tools::weighted_bipartite_matching<W, E>::edge> edges;

      const auto [flow, cost] = this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1);
      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {
        if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1) {
          edges.push_back(this->m_edges[i]);
        }
      }

      return ::std::make_pair((this->m_maximize ? -1 : 1) * cost, edges);
    }
  };
}

#endif
