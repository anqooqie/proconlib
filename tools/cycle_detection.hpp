#ifndef TOOLS_CYCLE_DETECTION_HPP
#define TOOLS_CYCLE_DETECTION_HPP

#include <vector>
#include <cstddef>
#include <utility>
#include <cassert>
#include <optional>
#include <stack>
#include <tuple>
#include <limits>
#include <algorithm>

namespace tools {
  template <bool DIRECTED>
  class cycle_detection {
  private:
    std::vector<std::vector<std::size_t>> m_graph;
    std::vector<std::pair<std::size_t, std::size_t>> m_edges;

  public:
    cycle_detection() = default;
    cycle_detection(const tools::cycle_detection<DIRECTED>&) = default;
    cycle_detection(tools::cycle_detection<DIRECTED>&&) = default;
    ~cycle_detection() = default;
    tools::cycle_detection<DIRECTED>& operator=(const tools::cycle_detection<DIRECTED>&) = default;
    tools::cycle_detection<DIRECTED>& operator=(tools::cycle_detection<DIRECTED>&&) = default;

    explicit cycle_detection(const std::size_t n) :
      m_graph(n) {
    }

    std::size_t size() const {
      return this->m_graph.size();
    }

    std::size_t add_edge(std::size_t u, std::size_t v) {
      assert(u < this->size());
      assert(v < this->size());

      this->m_graph[u].push_back(this->m_edges.size());
      if (!DIRECTED) {
        this->m_graph[v].push_back(this->m_edges.size());
      }
      this->m_edges.emplace_back(u, v);
      return this->m_edges.size() - 1;
    }

    std::optional<std::pair<std::vector<std::size_t>, std::vector<std::size_t>>> query() const {
      std::stack<std::tuple<bool, std::size_t, std::size_t>> stack;
      for (std::size_t v = 0; v < this->size(); ++v) {
        stack.emplace(false, v, std::numeric_limits<std::size_t>::max());
        stack.emplace(true, v, std::numeric_limits<std::size_t>::max());
      }
      std::vector<bool> pre(this->size(), false);
      std::vector<bool> post(this->size(), false);
      std::vector<std::size_t> prev(this->size(), std::numeric_limits<std::size_t>::max());
      while (!stack.empty()) {
        const auto [is_pre, here, from] = stack.top();
        stack.pop();
        if (post[here]) continue;

        if (is_pre) {
          prev[here] = from;
          if (pre[here]) {
            std::vector<std::size_t> vids, eids({from});
            for (std::size_t v = this->m_edges[from].first ^ (DIRECTED ? 0 : this->m_edges[from].second ^ here); v != here; v = this->m_edges[prev[v]].first ^ (DIRECTED ? 0 : this->m_edges[prev[v]].second ^ v)) {
              vids.push_back(v);
              eids.push_back(prev[v]);
            }
            vids.push_back(here);
            std::reverse(vids.begin(), vids.end());
            std::reverse(eids.begin(), eids.end());
            return std::make_optional(std::make_pair(vids, eids));
          }
          pre[here] = true;
          for (const auto eid : this->m_graph[here]) {
            if (eid != from) {
              stack.emplace(false, this->m_edges[eid].second ^ (DIRECTED ? 0 : this->m_edges[eid].first ^ here), eid);
              stack.emplace(true, this->m_edges[eid].second ^ (DIRECTED ? 0 : this->m_edges[eid].first ^ here), eid);
            }
          }
        } else {
          post[here] = true;
        }
      }

      return std::nullopt;
    }
  };
}

#endif
