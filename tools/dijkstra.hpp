#ifndef TOOLS_DIJKSTRA_HPP
#define TOOLS_DIJKSTRA_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <cassert>
#include <functional>
#include <queue>
#include "tools/greater_by_second.hpp"
#include "tools/chmin.hpp"

namespace tools {

  template <typename T>
  class dijkstra {
  private:
    class edge {
    public:
      ::std::size_t from;
      ::std::size_t to;
      T distance;
      edge(const ::std::size_t from, const ::std::size_t to, const T distance) :
        from(from),
        to(to),
        distance(distance) {
      }
    };

    ::std::vector<::std::vector<edge>> edges;

  public:
    static constexpr T INF = ::std::numeric_limits<T>::max();
    static constexpr ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();

    class result {
    public:
      ::std::vector<T> distances;
      ::std::vector<::std::size_t> prev_nodes;
      result(const ::std::size_t& node_count, const ::std::size_t& start_node) :
        distances(node_count, INF),
        prev_nodes(node_count, NONE) {
        this->distances[start_node] = 0;
      }
    };

    dijkstra(const ::std::size_t& node_count) :
      edges(node_count) {
    }

    ::std::size_t node_count() const {
      return this->edges.size();
    }

    void add_edge(const ::std::size_t& from, const ::std::size_t& to, const T& distance) {
      this->edges[from].emplace_back(from, to, distance);
    }

    result query(const ::std::size_t& start_node) const {
      assert(start_node < this->node_count());

      result result(this->node_count(), start_node);
      ::std::priority_queue<::std::pair<::std::size_t, T>, ::std::vector<::std::pair<::std::size_t, T>>, ::tools::greater_by_second> tasks;
      tasks.emplace(start_node, 0);

      while (!tasks.empty()) {
        const auto [here, d] = tasks.top();
        tasks.pop();
        if (result.distances[here] < d) continue;
        for (const edge& edge : this->edges[here]) {
          if (::tools::chmin(result.distances[edge.to], result.distances[here] + edge.distance)) {
            result.prev_nodes[edge.to] = edge.from;
            tasks.emplace(edge.to, result.distances[edge.to]);
          }
        }
      }

      return result;
    }
  };
}

#endif
