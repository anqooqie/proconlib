#ifndef TOOLS_TREE_DIAMETER_HPP
#define TOOLS_TREE_DIAMETER_HPP

#include <vector>
#include <cstddef>
#include <utility>
#include <cassert>
#include <tuple>
#include <limits>
#include <queue>
#include <iterator>
#include <algorithm>
#include "tools/chmin.hpp"

namespace tools {
  template <typename T>
  class tree_diameter {
  private:
    std::vector<std::vector<std::size_t>> m_graph;
    std::vector<std::pair<std::size_t, T>> m_edges;

  public:
    tree_diameter() = default;
    tree_diameter(const tools::tree_diameter<T>&) = default;
    tree_diameter(tools::tree_diameter<T>&&) = default;
    ~tree_diameter() = default;
    tools::tree_diameter<T>& operator=(const tools::tree_diameter<T>&) = default;
    tools::tree_diameter<T>& operator=(tools::tree_diameter<T>&&) = default;

    explicit tree_diameter(const std::size_t n) :
      m_graph(n) {
      assert(n >= 1);
    }

    std::size_t size() const {
      return this->m_graph.size();
    }

    std::size_t add_edge(const std::size_t u, const std::size_t v, const T& w) {
      assert(u < this->size());
      assert(v < this->size());

      this->m_graph[u].push_back(this->m_edges.size());
      this->m_graph[v].push_back(this->m_edges.size());
      this->m_edges.emplace_back(u ^ v, w);
      return this->m_edges.size() - 1;
    }

    std::tuple<T, std::vector<std::size_t>, std::vector<std::size_t>> query() const {
      assert(this->m_edges.size() + 1 == this->size());

      std::vector<T> dist(this->size(), std::numeric_limits<T>::max());
      dist[0] = 0;
      std::queue<std::size_t> queue({0});
      while (!queue.empty()) {
        const auto here = queue.front();
        queue.pop();
        for (const auto eid : this->m_graph[here]) {
          const auto next = this->m_edges[eid].first ^ here;
          const auto w = this->m_edges[eid].second;
          if (tools::chmin(dist[next], dist[here] + w)) {
            queue.push(next);
          }
        }
      }

      queue.push(std::distance(dist.begin(), std::max_element(dist.begin(), dist.end())));
      std::fill(dist.begin(), dist.end(), std::numeric_limits<T>::max());
      dist[queue.front()] = 0;
      std::vector<std::size_t> prev(this->size(), std::numeric_limits<std::size_t>::max());
      while (!queue.empty()) {
        const auto here = queue.front();
        queue.pop();
        for (const auto eid : this->m_graph[here]) {
          const auto next = this->m_edges[eid].first ^ here;
          const auto w = this->m_edges[eid].second;
          if (tools::chmin(dist[next], dist[here] + w)) {
            prev[next] = eid;
            queue.push(next);
          }
        }
      }

      std::tuple<T, std::vector<std::size_t>, std::vector<std::size_t>> result;
      std::get<0>(result) = 0;
      std::size_t v;
      for (v = std::distance(dist.begin(), std::max_element(dist.begin(), dist.end())); prev[v] != std::numeric_limits<std::size_t>::max(); v = this->m_edges[prev[v]].first ^ v) {
        std::get<0>(result) += this->m_edges[prev[v]].second;
        std::get<1>(result).push_back(v);
        std::get<2>(result).push_back(prev[v]);
      }
      std::get<1>(result).push_back(v);
      return result;
    }
  };
}

#endif
