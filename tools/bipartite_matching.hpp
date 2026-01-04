#ifndef TOOLS_BIPARTITE_MATCHING_HPP
#define TOOLS_BIPARTITE_MATCHING_HPP

#include <cassert>
#include <iterator>
#include <utility>
#include <vector>
#include "atcoder/maxflow.hpp"
#include "tools/getter_result.hpp"

namespace tools {
  class bipartite_matching {
  public:
    struct edge {
      int from;
      int to;
    };

  private:
    int m_size1;
    int m_size2;
    atcoder::mf_graph<int> m_graph;
    std::vector<edge> m_edges;

  public:
    bipartite_matching() = default;
    bipartite_matching(const int size1, const int size2) :
      m_size1(size1), m_size2(size2), m_graph(size1 + size2 + 2) {
      assert(size1 >= 0);
      assert(size2 >= 0);
      for (int i = 0; i < size1; ++i) {
        this->m_graph.add_edge(size1 + size2, i, 1);
      }
      for (int i = 0; i < size2; ++i) {
        this->m_graph.add_edge(size1 + i, size1 + size2 + 1, 1);
      }
    }

    int size1() const {
      return this->m_size1;
    }

    int size2() const {
      return this->m_size2;
    }

    int add_edge(const int i, const int j) {
      assert(0 <= i && i < this->size1());
      assert(0 <= j && j < this->size2());
      this->m_graph.add_edge(i, this->m_size1 + j, 1);
      this->m_edges.push_back({i, j});
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
    std::conditional_t<Restore, std::vector<int>, int> query() {
      std::vector<int> edges;

      this->m_graph.flow(this->m_size1 + this->m_size2, this->m_size1 + this->m_size2 + 1);
      for (int i = 0; i < std::ssize(this->m_edges); ++i) {
        if (this->m_graph.get_edge(this->m_size1 + this->m_size2 + i).flow == 1) {
          edges.push_back(i);
        }
      }

      if constexpr (Restore) {
        return edges;
      } else {
        return edges.size();
      }
    }
  };
}

#endif
