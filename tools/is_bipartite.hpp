#ifndef TOOLS_IS_BIPARTITE_HPP
#define TOOLS_IS_BIPARTITE_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <string>
#include <queue>

namespace tools {

  class is_bipartite {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
    };

  private:
    ::std::vector<edge> m_edges;
    ::std::vector<::std::vector<::std::size_t>> m_graph;

  public:
    is_bipartite() = default;
    explicit is_bipartite(const ::std::size_t n) : m_graph(n) {
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    ::std::size_t add_edge(::std::size_t u, ::std::size_t v) {
      assert(u < this->size());
      assert(v < this->size());
      ::std::tie(u, v) = ::std::minmax({u, v});
      this->m_edges.push_back(edge{this->m_edges.size(), u, v});
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

    bool query() const {
      ::std::string belongs(this->size(), '?');
      for (::std::size_t root = 0; root < this->size(); ++root) {
        if (belongs[root] == '?') {
          ::std::queue<::std::size_t> queue({root});
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
