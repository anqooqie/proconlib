#include <cstddef>
#include <vector>
#include "atcoder/maxflow.hpp"

namespace tools {
  template <typename E>
  class bipartite_matching {
  public:
    struct edge {
      ::std::size_t from;
      ::std::size_t to;
      E attribute;
      edge() = default;
      edge(const ::tools::bipartite_matching<E>::edge&) = default;
      edge(::tools::bipartite_matching<E>::edge&&) = default;
      ~edge() = default;
      ::tools::bipartite_matching<E>::edge& operator=(const ::tools::bipartite_matching<E>::edge&) = default;
      ::tools::bipartite_matching<E>::edge& operator=(::tools::bipartite_matching<E>::edge&&) = default;
      edge(const ::std::size_t& from, const ::std::size_t& to, const E& attribute) :
        from(from), to(to), attribute(attribute) {
      }
    };

  private:
    ::std::size_t m_size1;
    ::std::size_t m_size2;
    ::atcoder::mf_graph<int> m_graph;
    ::std::vector<::tools::bipartite_matching<E>::edge> m_edges;

  public:
    bipartite_matching() = default;
    bipartite_matching(const ::tools::bipartite_matching<E>&) = default;
    bipartite_matching(::tools::bipartite_matching<E>&&) = default;
    ~bipartite_matching() = default;
    ::tools::bipartite_matching<E>& operator=(const ::tools::bipartite_matching<E>&) = default;
    ::tools::bipartite_matching<E>& operator=(::tools::bipartite_matching<E>&&) = default;

    bipartite_matching(const ::std::size_t& size1, const ::std::size_t& size2) :
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

    void add_edge(const ::std::size_t& i, const ::std::size_t& j, const E& e) {
      this->m_graph.add_edge(i, this->m_size1 + j, 1);
      this->m_edges.emplace_back(i, j, e);
    }

    ::std::vector<::tools::bipartite_matching<E>::edge> query() {
      ::std::vector<::tools::bipartite_matching<E>::edge> edges;

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
