#ifndef TOOLS_TSORT_HPP
#define TOOLS_TSORT_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <queue>
#include <cstdint>
#include "tools/pow2.hpp"

namespace tools {

  class tsort {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
    };

  private:
    ::std::vector<edge> m_edges;
    ::std::vector<::std::vector<::std::size_t>> m_graph;

  public:
    tsort() = default;
    tsort(const ::tools::tsort&) = default;
    tsort(::tools::tsort&&) = default;
    ~tsort() = default;
    ::tools::tsort& operator=(const ::tools::tsort&) = default;
    ::tools::tsort& operator=(::tools::tsort&&) = default;

    explicit tsort(const ::std::size_t n) : m_graph(n) {
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    ::std::size_t add_edge(const ::std::size_t u, const ::std::size_t v) {
      assert(u < this->size());
      assert(v < this->size());
      this->m_edges.push_back(edge{this->m_edges.size(), u, v});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const ::std::size_t k) const {
      assert(k < this->m_edges.size());
      return this->m_edges[k];
    }

    const ::std::vector<edge>& edges() const {
      return this->m_edges;
    }

    ::std::vector<::std::size_t> query() const {
      ::std::vector<::std::size_t> indegs(this->size(), 0);
      for (::std::size_t u = 0; u < this->size(); ++u) {
        for (const auto e : this->m_graph[u]) {
          ++indegs[this->m_edges[e].to];
        }
      }

      ::std::queue<::std::size_t> queue;
      for (::std::size_t v = 0; v < this->size(); ++v) {
        if (indegs[v] == 0) {
          queue.push(v);
        }
      }

      ::std::vector<::std::size_t> result;
      result.reserve(this->size());
      while (!queue.empty()) {
        const ::std::size_t u = queue.front();
        queue.pop();
        result.push_back(u);
        for (const auto e : this->m_graph[u]) {
          const auto v = this->m_edges[e].to;
          --indegs[v];
          if (indegs[v] == 0) {
            queue.push(v);
          }
        }
      }

      return result;
    }

    template <typename R = long long>
    R count() const {
      using u32 = ::std::uint_fast32_t;

      assert(this->size() < 32);

      ::std::vector<u32> graph(this->size());
      for (const auto& edge : this->m_edges) {
        graph[edge.from] |= u32(1) << edge.to;
      }

      ::std::vector<R> dp(::tools::pow2(this->size()));
      dp[0] = R(1);
      for (u32 state = 1; state < ::tools::pow2(this->size()); ++state) {
        dp[state] = R(0);
        for (::std::size_t v = 0; v < this->size(); ++v) {
          if (const auto prev_state = state & ~(u32(1) << v); ((state >> v) & 1) && !(graph[v] & prev_state)) {
            dp[state] += dp[prev_state];
          }
        }
      }

      return dp[::tools::pow2(this->size()) - 1];
    }
  };
}

#endif
