#ifndef TOOLS_PRIM_HPP
#define TOOLS_PRIM_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include <limits>
#include <queue>
#include "tools/greater_by.hpp"

namespace tools {

  template <typename T>
  class prim {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
      T cost;
    };

  private:
    ::std::vector<edge> m_edges;
    ::std::vector<::std::vector<::std::size_t>> m_graph;

  public:
    prim() = default;
    prim(const ::tools::prim<T>&) = default;
    prim(::tools::prim<T>&&) = default;
    ~prim() = default;
    ::tools::prim<T>& operator=(const ::tools::prim<T>&) = default;
    ::tools::prim<T>& operator=(::tools::prim<T>&&) = default;

    explicit prim(const ::std::size_t n) : m_graph(n) {
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    ::std::size_t add_edge(::std::size_t u, ::std::size_t v, const T w) {
      assert(u < this->size());
      assert(v < this->size());
      ::std::tie(u, v) = ::std::minmax({u, v});
      this->m_edges.push_back(edge({this->m_edges.size(), u, v, w}));
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      this->m_graph[v].push_back(this->m_edges.size() - 1);
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const ::std::size_t k) const {
      assert(k < this->m_edges.size());
      return this->m_edges[k];
    }

    const ::std::vector<edge>& edges() const {
      return this->m_edges;
    }

    ::std::pair<::std::vector<::std::pair<T, ::std::vector<::std::size_t>>>, ::std::vector<::std::size_t>> query() const {
      ::std::pair<::std::vector<::std::pair<T, ::std::vector<::std::size_t>>>, ::std::vector<::std::size_t>> res;
      auto& [groups, belongs_to] = res;
      belongs_to.resize(this->size());
      ::std::fill(belongs_to.begin(), belongs_to.end(), ::std::numeric_limits<::std::size_t>::max());

      for (::std::size_t root = 0; root < this->size(); ++root) {
        if (belongs_to[root] < ::std::numeric_limits<::std::size_t>::max()) continue;

        const auto greater_by_cost = ::tools::greater_by([&](const auto& pair) { return this->m_edges[pair.first].cost; });
        ::std::priority_queue<::std::pair<::std::size_t, ::std::size_t>, ::std::vector<::std::pair<::std::size_t, ::std::size_t>>, decltype(greater_by_cost)> pq(greater_by_cost);
        groups.emplace_back(0, ::std::vector<::std::size_t>());
        auto& [total_cost, edge_ids] = groups.back();

        belongs_to[root] = groups.size() - 1;
        for (const auto e : this->m_graph[root]) {
          const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ root;
          if (belongs_to[next] < ::std::numeric_limits<::std::size_t>::max()) continue;

          pq.emplace(e, next);
        }

        while (!pq.empty()) {
          const auto [from_edge_id, here] = pq.top();
          pq.pop();

          if (belongs_to[here] < ::std::numeric_limits<::std::size_t>::max()) continue;

          belongs_to[here] = belongs_to[root];
          total_cost += this->m_edges[from_edge_id].cost;
          edge_ids.push_back(from_edge_id);
          for (const auto e : this->m_graph[here]) {
            const auto next = this->m_edges[e].from ^ this->m_edges[e].to ^ here;
            if (belongs_to[next] < ::std::numeric_limits<::std::size_t>::max()) continue;

            pq.emplace(e, next);
          }
        }
      }

      return res;
    }
  };
}

#endif
