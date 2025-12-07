#ifndef TOOLS_SCC_GRAPH_HPP
#define TOOLS_SCC_GRAPH_HPP

#include <vector>
#include <utility>
#include <cstddef>
#include <cassert>
#include <stack>
#include <algorithm>
#include "tools/less_by.hpp"

namespace tools {
  class scc_graph {
  private:
    std::vector<std::pair<std::size_t, std::size_t>> m_edges;
    std::vector<std::vector<std::size_t>> m_graph;
    std::vector<std::vector<std::size_t>> m_rev_graph;
    std::vector<std::size_t> m_vid2scc;
    std::vector<std::vector<std::size_t>> m_sccs;
    std::vector<std::vector<std::size_t>> m_edges_in_scc;
    std::vector<std::vector<std::pair<std::size_t, std::vector<std::size_t>>>> m_scc_graph;
    std::vector<std::vector<std::pair<std::size_t, std::vector<std::size_t>>>> m_rev_scc_graph;
    bool m_built;

  public:
    scc_graph() = default;
    scc_graph(const tools::scc_graph&) = default;
    scc_graph(tools::scc_graph&&) = default;
    ~scc_graph() = default;
    tools::scc_graph& operator=(const tools::scc_graph&) = default;
    tools::scc_graph& operator=(tools::scc_graph&&) = default;

    explicit scc_graph(const std::size_t n) : m_graph(n), m_rev_graph(n), m_vid2scc(n), m_built(false) {
    }

    std::size_t size() const {
      return this->m_graph.size();
    }

    std::size_t add_edge(const std::size_t from, const std::size_t to) {
      assert(from < this->size());
      assert(to < this->size());
      assert(!this->m_built);
      const auto edge_id = this->m_edges.size();
      this->m_edges.emplace_back(from, to);
      this->m_graph[from].push_back(edge_id);
      this->m_rev_graph[to].push_back(edge_id);
      return edge_id;
    }

    std::pair<std::size_t, std::size_t> edge(const std::size_t i) const {
      assert(i < this->m_edges.size());
      return this->m_edges[i];
    }
    const std::vector<std::size_t>& edges_from(const std::size_t i) const {
      assert(i < this->size());
      return this->m_graph[i];
    }
    const std::vector<std::size_t>& edges_to(const std::size_t i) const {
      assert(i < this->size());
      return this->m_rev_graph[i];
    }

    void build() {
      assert(!this->m_built);
      std::stack<std::size_t> ordered_by_dfs;
      {
        std::vector<bool> visited(this->size(), false);
        std::stack<std::pair<bool, std::size_t>> stack;
        for (std::size_t i = this->size(); i --> 0;) {
          stack.emplace(true, i);
        }
        while (!stack.empty()) {
          const auto [pre, here] = stack.top();
          stack.pop();
          if (pre) {
            if (visited[here]) continue;
            visited[here] = true;
            stack.emplace(false, here);
            for (const auto e : this->m_graph[here]) {
              const auto next = this->m_edges[e].second;
              if (visited[next]) continue;
              stack.emplace(true, next);
            }
          } else {
            ordered_by_dfs.push(here);
          }
        }
      }

      {
        std::vector<bool> visited(this->size(), false);
        while (!ordered_by_dfs.empty()) {
          const auto root = ordered_by_dfs.top();
          ordered_by_dfs.pop();
          if (visited[root]) continue;

          const auto scc_id = this->m_sccs.size();
          this->m_sccs.emplace_back();
          this->m_edges_in_scc.emplace_back();
          this->m_scc_graph.emplace_back();
          this->m_rev_scc_graph.emplace_back();

          std::stack<std::size_t> stack({root});
          while (!stack.empty()) {
            const auto here = stack.top();
            stack.pop();
            if (visited[here]) continue;
            visited[here] = true;

            this->m_vid2scc[here] = scc_id;
            this->m_sccs[scc_id].push_back(here);

            for (const auto e : this->m_rev_graph[here]) {
              const auto next = this->m_edges[e].first;
              if (visited[next]) continue;
              stack.push(next);
            }
          }

          std::vector<std::size_t> buffer; 
          for (const auto v : this->m_sccs[scc_id]) {
            for (const auto e : this->m_rev_graph[v]) {
              const auto u = this->m_edges[e].first;
              if (this->m_vid2scc[u] == this->m_vid2scc[v]) {
                this->m_edges_in_scc[scc_id].push_back(e);
              } else {
                buffer.push_back(e);
              }
            }
          }

          std::sort(buffer.begin(), buffer.end(), tools::less_by([&](const auto e) { return this->m_vid2scc[this->m_edges[e].first]; }));
          for (std::size_t l = 0, r = 0; l < buffer.size(); l = r) {
            const auto u_scc_id = this->m_vid2scc[this->m_edges[buffer[l]].first];
            this->m_rev_scc_graph[scc_id].emplace_back(u_scc_id, std::vector<std::size_t>());
            for (; r < buffer.size() && this->m_vid2scc[this->m_edges[buffer[l]].first] == this->m_vid2scc[this->m_edges[buffer[r]].first]; ++r);
            for (std::size_t i = l; i < r; ++i) {
              this->m_rev_scc_graph[scc_id].back().second.push_back(buffer[i]);
            }
          }
        }

        for (std::size_t v_scc_id = 0; v_scc_id < this->m_sccs.size(); ++v_scc_id) {
          for (const auto& [u_scc_id, edge_ids] : this->m_rev_scc_graph[v_scc_id]) {
            this->m_scc_graph[u_scc_id].emplace_back(v_scc_id, edge_ids);
          }
        }
      }

      this->m_built = true;
    }

    std::size_t scc_id(const std::size_t i) const {
      assert(i < this->size());
      assert(this->m_built);
      return this->m_vid2scc[i];
    }
    const std::vector<std::vector<std::size_t>>& sccs() const {
      assert(this->m_built);
      return this->m_sccs;
    }
    const std::vector<std::size_t>& edges_in_scc(const std::size_t i) const {
      assert(i < this->m_sccs.size());
      assert(this->m_built);
      return this->m_edges_in_scc[i];
    }
    const std::vector<std::pair<std::size_t, std::vector<std::size_t>>>& edges_from_scc(const std::size_t i) const {
      assert(i < this->m_sccs.size());
      assert(this->m_built);
      return this->m_scc_graph[i];
    }
    const std::vector<std::pair<std::size_t, std::vector<std::size_t>>>& edges_to_scc(const std::size_t i) const {
      assert(i < this->m_sccs.size());
      assert(this->m_built);
      return this->m_rev_scc_graph[i];
    }
  };
}

#endif
