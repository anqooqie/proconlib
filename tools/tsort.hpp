#ifndef TOOLS_TSORT_HPP
#define TOOLS_TSORT_HPP

#include <cassert>
#include <cstdint>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>
#include "tools/pow2.hpp"

namespace tools {
  class tsort {
  public:
    struct edge {
      int from;
      int to;
    };

  private:
    std::vector<edge> m_edges;
    std::vector<std::vector<int>> m_graph;

  public:
    tsort() = default;
    explicit tsort(const int n) : m_graph(n) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(const int u, const int v) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      this->m_edges.push_back({u, v});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const int k) const & {
      assert(0 <= k && k < std::ssize(this->m_edges));
      return this->m_edges[k];
    }
    edge get_edge(const int k) && {
      assert(0 <= k && k < std::ssize(this->m_edges));
      return std::move(this->m_edges[k]);
    }

    const std::vector<edge>& edges() const & {
      return this->m_edges;
    }
    std::vector<edge> edges() && {
      return std::move(this->m_edges);
    }

    std::vector<int> query() const {
      std::vector<int> indegs(this->size(), 0);
      for (int u = 0; u < this->size(); ++u) {
        for (const auto e : this->m_graph[u]) {
          ++indegs[this->m_edges[e].to];
        }
      }

      std::queue<int> queue;
      for (int v = 0; v < this->size(); ++v) {
        if (indegs[v] == 0) {
          queue.push(v);
        }
      }

      std::vector<int> result;
      result.reserve(this->size());
      while (!queue.empty()) {
        const auto u = queue.front();
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
      using u32 = std::uint_fast32_t;

      assert(this->size() < 32);

      std::vector<u32> graph(this->size());
      for (const auto& edge : this->m_edges) {
        graph[edge.from] |= u32(1) << edge.to;
      }

      std::vector<R> dp(tools::pow2(this->size()));
      dp[0] = R(1);
      for (u32 state = 1; state < tools::pow2(this->size()); ++state) {
        dp[state] = R(0);
        for (int v = 0; v < this->size(); ++v) {
          if (const auto prev_state = state & ~(u32(1) << v); ((state >> v) & 1) && !(graph[v] & prev_state)) {
            dp[state] += dp[prev_state];
          }
        }
      }

      return dp[tools::pow2(this->size()) - 1];
    }
  };
}

#endif
