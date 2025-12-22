#ifndef TOOLS_SHORTEST_PATH_TREE
#define TOOLS_SHORTEST_PATH_TREE

#include <algorithm>
#include <cassert>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/getter_result.hpp"

namespace tools {
  template <typename Cost, typename F>
  class shortest_path_tree {
    std::vector<Cost> m_dist;
    std::vector<int> m_from;
    F m_get_vertex;

  public:
    shortest_path_tree() = default;
    template <std::ranges::input_range R1, std::ranges::input_range R2>
    shortest_path_tree(R1&& d, R2&& p, const F& f) :
    m_dist(std::forward<R1>(d) | std::ranges::to<std::vector<Cost>>()),
    m_from(std::forward<R2>(p) | std::ranges::to<std::vector<int>>()),
    m_get_vertex(f) {
      assert(this->m_dist.size() == this->m_from.size());
      assert(std::ranges::all_of(this->m_from, [](const auto p_i) { return p_i >= -1; }));
    }

    int size() const {
      return this->m_dist.size();
    }

    auto dist(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<Cost>> {
      return std::forward_like<decltype(self)>(self.m_dist);
    }
    Cost dist(const int v) const {
      assert(0 <= v && v < this->size());
      return this->m_dist[v];
    }
    int from_vertex(const int v) const {
      assert(0 <= v && v < this->size());
      return this->m_from[v] >= 0 ? this->m_get_vertex(this->m_from[v], v) : -1;
    }
    int from_edge_id(const int v) const {
      assert(0 <= v && v < this->size());
      return this->m_from[v];
    }
    std::vector<int> vertex_path(const int v) const {
      assert(0 <= v && v < this->size());
      std::vector<int> path;
      for (int u = v; u >= 0; u = this->from_vertex(u)) {
        path.push_back(u);
      }
      std::ranges::reverse(path);
      return path;
    }
    std::vector<int> edge_id_path(const int v) const {
      assert(0 <= v && v < this->size());
      std::vector<int> path;
      for (int u = v; this->m_from[u] >= 0; u = this->from_vertex(u)) {
        path.push_back(this->m_from[u]);
      }
      std::ranges::reverse(path);
      return path;
    }
  };

  template <std::ranges::input_range R1, std::ranges::input_range R2, typename F>
  shortest_path_tree(R1&&, R2&&, const F&) -> shortest_path_tree<std::ranges::range_value_t<R1>, F>;
}

#endif
