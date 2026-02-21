#ifndef TOOLS_IS_BIPARTITE_HPP
#define TOOLS_IS_BIPARTITE_HPP

#include <algorithm>
#include <cassert>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/getter_result.hpp"

namespace tools {
  class is_bipartite {
  public:
    struct edge {
      int from;
      int to;
    };

  private:
    std::vector<edge> m_edges;
    std::vector<std::vector<int>> m_graph;

  public:
    is_bipartite() = default;
    explicit is_bipartite(const int n) : m_graph(n) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(int u, int v) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      std::tie(u, v) = std::minmax({u, v});
      this->m_edges.push_back({u, v});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      this->m_graph[v].push_back(this->m_edges.size() - 1);
      return this->m_edges.size() - 1;
    }

    auto get_edge(this auto&& self, const int k) -> tools::getter_result_t<decltype(self), edge> {
      assert(0 <= k && k < std::ssize(self.m_edges));
      return std::forward_like<decltype(self)>(self.m_edges[k]);
    }

    auto edges(this auto&& self) -> tools::getter_result_t<decltype(self), std::vector<edge>> {
      return std::forward_like<decltype(self)>(self.m_edges);
    }

    bool query() const {
      std::string belongs(this->size(), '?');
      for (int root = 0; root < this->size(); ++root) {
        if (belongs[root] == '?') {
          std::queue<int> queue({root});
          belongs[root] = '0';
          while (!queue.empty()) {
            const auto here = queue.front();
            queue.pop();
            for (const auto edge_id : this->m_graph[here]) {
              const auto& edge = this->m_edges[edge_id];
              const auto next = edge.from ^ edge.to ^ here;
              if (belongs[next] == '?') {
                belongs[next] = ((belongs[here] - '0') ^ 1) + '0';
                queue.push(next);
              } else {
                if (belongs[here] == belongs[next]) {
                  return false;
                }
              }
            }
          }
        }
      }

      return true;
    }
  };
}

#endif
