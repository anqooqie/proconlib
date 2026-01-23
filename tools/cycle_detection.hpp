#ifndef TOOLS_CYCLE_DETECTION_HPP
#define TOOLS_CYCLE_DETECTION_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <optional>
#include <stack>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/getter_result.hpp"

namespace tools {
  template <bool Directed>
  class cycle_detection {
  public:
    struct edge {
      int from;
      int to;
    };

  private:
    std::vector<edge> m_edges;
    std::vector<std::vector<int>> m_graph;

  public:
    cycle_detection() = default;
    explicit cycle_detection(const int n) : m_graph(n) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(int u, int v) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      if constexpr (!Directed) {
        std::tie(u, v) = std::minmax({u, v});
      }
      this->m_edges.push_back({u, v});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      if constexpr (!Directed) {
        this->m_graph[v].push_back(this->m_edges.size() - 1);
      }
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
    std::conditional_t<Restore, std::optional<std::pair<std::vector<int>, std::vector<int>>>, bool> query() const {
      std::stack<std::tuple<bool, int, int>> stack;
      const int NONE = -1;
      for (int v = 0; v < this->size(); ++v) {
        stack.emplace(false, v, NONE);
        stack.emplace(true, v, NONE);
      }
      std::vector<bool> pre(this->size(), false);
      std::vector<bool> post(this->size(), false);
      std::vector<int> prev(Restore ? this->size() : 0, NONE);
      while (!stack.empty()) {
        const auto [is_pre, here, from] = stack.top();
        stack.pop();
        if (post[here]) continue;

        if (is_pre) {
          if constexpr (Restore) {
            prev[here] = from;
          }
          if (pre[here]) {
            if constexpr (Restore) {
              std::vector<int> vids, eids{from};
              for (int v = this->m_edges[from].from ^ (Directed ? 0 : this->m_edges[from].to ^ here); v != here; v = this->m_edges[prev[v]].from ^ (Directed ? 0 : this->m_edges[prev[v]].to ^ v)) {
                vids.push_back(v);
                eids.push_back(prev[v]);
              }
              vids.push_back(here);
              std::ranges::reverse(vids);
              std::ranges::reverse(eids);
              return std::make_optional(std::make_pair(std::move(vids), std::move(eids)));
            } else {
              return true;
            }
          }
          pre[here] = true;
          for (const auto eid : this->m_graph[here]) {
            if (eid != from) {
              stack.emplace(false, this->m_edges[eid].to ^ (Directed ? 0 : this->m_edges[eid].from ^ here), eid);
              stack.emplace(true, this->m_edges[eid].to ^ (Directed ? 0 : this->m_edges[eid].from ^ here), eid);
            }
          }
        } else {
          post[here] = true;
        }
      }

      if constexpr (Restore) {
        return std::nullopt;
      } else {
        return false;
      }
    }
  };
}

#endif
