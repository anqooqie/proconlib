#ifndef TOOLS_MINIMUM_STEINER_TREE_HPP
#define TOOLS_MINIMUM_STEINER_TREE_HPP

#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <ranges>
#include <stack>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/greater_by_second.hpp"

namespace tools {
  template <typename Cost>
  class minimum_steiner_tree {
  public:
    struct edge {
      int from;
      int to;
      Cost cost;
    };

  private:
    ::std::vector<edge> m_edges;
    ::std::vector<::std::vector<int>> m_graph;

  public:
    struct query_result {
      Cost cost;
      ::std::vector<int> vertices;
      ::std::vector<int> edge_ids;
    };

    minimum_steiner_tree() = default;
    explicit minimum_steiner_tree(const int n) : m_graph(n) {
      assert(n >= 0);
    }

    int size() const {
      return this->m_graph.size();
    }
    int add_edge(int u, int v, const Cost w) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      assert(w >= 0);

      ::std::tie(u, v) = ::std::minmax({u, v});
      this->m_edges.push_back({u, v, w});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      this->m_graph[v].push_back(this->m_edges.size() - 1);
      return this->m_edges.size() - 1;
    }
    const edge& get_edge(const int i) const {
      assert(0 <= i && ::std::cmp_less(i, this->m_edges.size()));
      return this->m_edges[i];
    }
    const ::std::vector<edge>& edges() const {
      return this->m_edges;
    }

  public:
    template <bool Restore, ::std::ranges::range R>
    ::std::conditional_t<Restore, query_result, Cost> query(R&& S) const {
      if constexpr (::std::ranges::forward_range<R>) {
        const auto k = ::std::ranges::distance(S);
        assert(0 <= k && k <= this->size());
        assert(::std::ranges::all_of(S, [this](const int v) { return 0 <= v && v < this->size(); }));

        if (k == 0) {
          if constexpr (Restore) {
            return query_result{};
          } else {
            return 0;
          }
        }

        ::std::vector dp(1 << k, ::std::vector(this->size(), ::std::numeric_limits<Cost>::max()));
        ::std::vector prev(Restore ? 1 << k : 0, ::std::vector(this->size(), -1));
        for (int t = 0; const auto v : S) {
          dp[1 << t][v] = 0;
          ++t;
        }
        for (int T = 1; T < 1 << k; ++T) {
          for (int v = 0; v < this->size(); ++v) {
            for (int U = (T - 1) & T; U > 0; U = (U - 1) & T) {
              if (dp[U][v] < ::std::numeric_limits<Cost>::max() && dp[T ^ U][v] < ::std::numeric_limits<Cost>::max() && ::tools::chmin(dp[T][v], dp[U][v] + dp[T ^ U][v])) {
                if constexpr (Restore) {
                  prev[T][v] = U;
                }
              }
            }
          }
          ::std::priority_queue<::std::pair<int, Cost>, ::std::vector<::std::pair<int, Cost>>, ::tools::greater_by_second> pq;
          for (int v = 0; v < this->size(); ++v) {
            if (dp[T][v] < ::std::numeric_limits<Cost>::max()) {
              pq.emplace(v, dp[T][v]);
            }
          }
          while (!pq.empty()) {
            const auto [here, d] = pq.top();
            pq.pop();
            if (dp[T][here] < d) continue;
            for (const auto edge_id : this->m_graph[here]) {
              const auto& edge = this->m_edges[edge_id];
              const auto next = edge.from ^ edge.to ^ here;
              if (::tools::chmin(dp[T][next], dp[T][here] + edge.cost)) {
                pq.emplace(next, dp[T][next]);
                if constexpr (Restore) {
                  prev[T][next] = (1 << k) + edge_id;
                }
              }
            }
          }
        }

        if constexpr (Restore) {
          query_result qr;
          qr.cost = dp.back()[*::std::ranges::begin(S)];
          if (qr.cost == ::std::numeric_limits<Cost>::max()) return qr;

          ::std::stack<::std::pair<int, int>> stack;
          stack.emplace((1 << k) - 1, *::std::ranges::begin(S));
          qr.vertices.push_back(*::std::ranges::begin(S));
          while (!stack.empty()) {
            const auto [T, v] = stack.top();
            stack.pop();
            if (prev[T][v] == -1) continue;
            if (prev[T][v] < 1 << k) {
              stack.emplace(prev[T][v], v);
              stack.emplace(T ^ prev[T][v], v);
            } else {
              const auto edge_id = prev[T][v] - (1 << k);
              const auto& edge = this->m_edges[edge_id];
              qr.vertices.push_back(edge.from ^ edge.to ^ v);
              qr.edge_ids.push_back(edge_id);
              stack.emplace(T, edge.from ^ edge.to ^ v);
            }
          }
          return qr;
        } else {
          return dp.back()[*::std::ranges::begin(S)];
        }
      } else {
        return this->query<Restore>(::std::vector<::std::decay_t<::std::ranges::range_value_t<R>>>(::std::ranges::begin(S), ::std::ranges::end(S)));
      }
    }
    template <::std::ranges::range R>
    auto query(R&& S) const {
      return this->query<false>(::std::forward<R>(S));
    }
  };
}

#endif
