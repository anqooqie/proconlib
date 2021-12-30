#ifndef TOOLS_LCA_HPP
#define TOOLS_LCA_HPP

#include <utility>
#include <cstddef>
#include <limits>
#include <vector>
#include <cassert>
#include <numeric>
#include <stack>
#include <tuple>
#include "tools/disjoint_sparse_table.hpp"

namespace tools {
  class lca {
  private:
    struct monoid {
      using T = ::std::pair<::std::size_t, ::std::size_t>;
      static T op(const T& x, const T& y) {
        return x.second <= y.second ? T(x.first, x.second) : T(y.first, y.second);
      }
      static T e() {
        return T(::std::numeric_limits<::std::size_t>::max(), ::std::numeric_limits<::std::size_t>::max());
      }
    };

    ::std::vector<::std::vector<::std::size_t>> m_edges;
    ::std::vector<::std::size_t> m_in;
    ::tools::disjoint_sparse_table<monoid> m_dst;

  public:

    lca() = default;
    lca(const ::tools::lca&) = default;
    lca(::tools::lca&&) = default;
    ~lca() = default;
    ::tools::lca& operator=(const ::tools::lca&) = default;
    ::tools::lca& operator=(::tools::lca&&) = default;

    lca(const ::std::size_t n) : m_edges(n), m_in(n) {
      assert(n >= 1);
    }

    ::std::size_t size() const {
      return this->m_edges.size();
    }

    void add_edge(const ::std::size_t u, const ::std::size_t v) {
      assert(u < this->size());
      assert(v < this->size());
      assert(u != v);
      this->m_edges[u].push_back(v);
      this->m_edges[v].push_back(u);
    }

    void build(const ::std::size_t root) {
      assert(::std::accumulate(this->m_edges.begin(), this->m_edges.end(), ::std::size_t(0), [](const ::std::size_t sum, const auto& edges) { return sum + edges.size(); }) == 2 * (this->size() - 1));

      ::std::size_t t = 0;
      ::std::vector<::std::pair<::std::size_t, ::std::size_t>> tour(2 * this->size() - 1);

      ::std::stack<::std::tuple<bool, ::std::size_t, ::std::size_t>> stack;
      stack.emplace(true, root, 0);
      ::std::vector<bool> will_visit(this->size(), false);
      will_visit[root] = true;
      while (!stack.empty()) {
        const auto [pre, here, depth] = stack.top();
        stack.pop();
        tour[t].first = here;
        tour[t].second = depth;
        if (pre) {
          this->m_in[here] = t;
          for (const ::std::size_t next : this->m_edges[here]) {
            if (!will_visit[next]) {
              stack.emplace(false, here, depth);
              stack.emplace(true, next, depth + 1);
              will_visit[next] = true;
            }
          }
        }
        ++t;
      }

      if (this->size() > 1) {
        tour.pop_back();
      }
      this->m_dst = ::tools::disjoint_sparse_table<monoid>(tour.begin(), tour.end());
    }

    ::std::size_t query(::std::size_t u, ::std::size_t v) const {
      assert(u < this->size());
      assert(v < this->size());

      if (this->m_in[v] < this->m_in[u]) {
        ::std::swap(u, v);
      }

      return this->m_dst.prod(this->m_in[u], this->m_in[v] + 1).first;
    }
  };
}

#endif
