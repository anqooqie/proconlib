#ifndef TOOLS_BIPARTITE_MATCHING_HPP
#define TOOLS_BIPARTITE_MATCHING_HPP

#include <cstddef>
#include <vector>
#include "atcoder/maxflow.hpp"

namespace tools {

  class bipartite_matching {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
      edge() = default;
      edge(const ::tools::bipartite_matching::edge&) = default;
      edge(::tools::bipartite_matching::edge&&) = default;
      ~edge() = default;
      ::tools::bipartite_matching::edge& operator=(const ::tools::bipartite_matching::edge&) = default;
      ::tools::bipartite_matching::edge& operator=(::tools::bipartite_matching::edge&&) = default;
      edge(const ::std::size_t id, const ::std::size_t from, const ::std::size_t to) :
        id(id), from(from), to(to) {
      }
    };

  private:
    ::std::size_t m_size1;
    ::std::size_t m_size2;
    ::atcoder::mf_graph<int> m_graph;
    ::std::vector<::tools::bipartite_matching::edge> m_edges;

  public:
    bipartite_matching() = default;
    bipartite_matching(const ::tools::bipartite_matching&) = default;
    bipartite_matching(::tools::bipartite_matching&&) = default;
    ~bipartite_matching() = default;
    ::tools::bipartite_matching& operator=(const ::tools::bipartite_matching&) = default;
    ::tools::bipartite_matching& operator=(::tools::bipartite_matching&&) = default;

    bipartite_matching(const ::std::size_t size1, const ::std::size_t size2) :
      m_size1(size1), m_size2(size2), m_graph(size1 + size2 + 2) {
      for (::std::size_t i = 0; i < size1; ++i) {
        this->m_graph.add_edge(size1 + size2, i, 1);
      }
      for (::std::size_t i = 0; i < size2; ++i) {
        this->m_graph.add_edge(size1 + i, size1 + size2 + 1, 1);
      }
    }

    ::std::size_t size1() const {
      return this->m_size1;
    }

    ::std::size_t size2() const {
      return this->m_size2;
    }

    ::std::size_t add_edge(const ::std::size_t i, const ::std::size_t j) {
      this->m_graph.add_edge(i, this->m_size1 + j, 1);
      this->m_edges.emplace_back(this->m_edges.size(), i, j);
      return this->m_edges.size() - 1;
    }

    ::std::vector<::tools::bipartite_matching::edge> query() {
      ::std::vector<::tools::bipartite_matching::edge> edges;

      this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1);
      for (::std::size_t i = 0; i < this->m_edges.size(); ++i) {
        if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1) {
          edges.push_back(this->m_edges[i]);
        }
      }

      return edges;
    }
  };
}

#endif
