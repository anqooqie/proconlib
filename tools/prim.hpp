#ifndef TOOLS_PRIM_HPP
#define TOOLS_PRIM_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <queue>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/getter_result.hpp"
#include "tools/greater_by.hpp"

namespace tools {

  template <typename T>
  class prim {
  public:
    struct edge {
      int from;
      int to;
      T cost;
    };

    class minimum_spanning_tree {
      T m_cost;
      std::vector<int> m_edge_ids;

      minimum_spanning_tree(const T cost, const std::vector<int>& edge_ids) : m_cost(cost), m_edge_ids(edge_ids) {
        assert(std::ranges::all_of(edge_ids, [](const auto edge_id) { return edge_id >= 0; }));
      }

    public:
      minimum_spanning_tree() = default;

      T cost() const {
        return this->m_cost;
      }
      auto edge_ids(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<int>> {
        return std::forward_like<decltype(self)>(self.m_edge_ids);
      }

      friend tools::prim<T>;
    };

    class minimum_spanning_forest {
      std::vector<minimum_spanning_tree> m_msts;
      std::vector<int> m_mst_ids;

      minimum_spanning_forest(const std::vector<minimum_spanning_tree>& msts, const std::vector<int>& mst_ids) : m_msts(msts), m_mst_ids(mst_ids) {
        assert(std::ranges::all_of(mst_ids, [&](const auto mst_id) { return 0 <= mst_id && mst_id < std::ssize(msts); }));
      }

    public:
      minimum_spanning_forest() = default;

      auto get_mst(this auto&& self, const int k) -> tools::getter_result_t<decltype(self), minimum_spanning_tree> {
        assert(0 <= k && k < std::ssize(self.m_msts));
        return std::forward_like<decltype(self)>(self.m_msts[k]);
      }
      auto msts(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<minimum_spanning_tree>> {
        return std::forward_like<decltype(self)>(self.m_msts);
      }
      int mst_id(const int v) const {
        assert(0 <= v && v < std::ssize(this->m_mst_ids));
        return this->m_mst_ids[v];
      }

      friend tools::prim<T>;
    };

  private:
    std::vector<edge> m_edges;
    std::vector<std::vector<int>> m_graph;

  public:
    prim() = default;
    explicit prim(const int n) : m_graph(n) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(int u, int v, const T w) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      std::tie(u, v) = std::minmax({u, v});
      this->m_edges.push_back({u, v, w});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      this->m_graph[v].push_back(this->m_edges.size() - 1);
      return this->m_edges.size() - 1;
    }

    auto get_edge(this auto&& self, const int k) -> tools::getter_result_t<decltype(self), edge> {
      assert(0 <= k && k < self.m_edges.size());
      return std::forward_like<decltype(self)>(self.m_edges[k]);
    }

    auto edges(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<edge>> {
      return std::forward_like<decltype(self)>(self.m_edges);
    }

    template <bool Restore = false>
    std::conditional_t<Restore, minimum_spanning_forest, std::vector<T>> query() const {
      constexpr int none = -1;
      std::vector<std::pair<T, std::vector<int>>> groups;
      std::vector<int> belongs_to(this->size(), none);

      for (int root = 0; root < this->size(); ++root) {
        if (belongs_to[root] != none) continue;

        const auto greater_by_cost = tools::greater_by([&](const auto& pair) { return this->m_edges[pair.first].cost; });
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(greater_by_cost)> pq(greater_by_cost);
        groups.emplace_back(0, std::vector<int>{});
        auto& [total_cost, edge_ids] = groups.back();

        belongs_to[root] = groups.size() - 1;
        for (const auto e : this->m_graph[root]) {
          const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ root;
          if (belongs_to[next] != none) continue;

          pq.emplace(e, next);
        }

        while (!pq.empty()) {
          const auto [from_edge_id, here] = pq.top();
          pq.pop();

          if (belongs_to[here] != none) continue;

          belongs_to[here] = belongs_to[root];
          total_cost += this->m_edges[from_edge_id].cost;
          if constexpr (Restore) {
            edge_ids.push_back(from_edge_id);
          }
          for (const auto e : this->m_graph[here]) {
            const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ here;
            if (belongs_to[next] != none) continue;

            pq.emplace(e, next);
          }
        }
      }

      if constexpr (Restore) {
        return minimum_spanning_forest(
          groups | std::views::transform([](const auto& group) {
            return minimum_spanning_tree(group.first, group.second);
          }) | std::ranges::to<std::vector>(),
          belongs_to
        );
      } else {
        return groups | std::views::transform([](const auto& group) { return group.first; }) | std::ranges::to<std::vector<T>>();
      }
    }
  };
}

#endif
