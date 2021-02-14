#ifndef TOOLS_ZERO_ONE_BFS_HPP
#define TOOLS_ZERO_ONE_BFS_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <cassert>
#include <deque>

namespace tools {

  /**
   * 01-BFS
   * License: CC0
   *
   * Usage:
   * ```
   * tools::zero_one_bfs<int> bfs(node_count);
   * bfs.add_edge(from_node, to_node, cost);
   * const tools::zero_one_bfs<int>::result result = bfs.query(start_node);
   * for (const int& distance : result.distances) {
   *   // ...
   * }
   * ```
   *
   * @author anqooqie
   * @param <T> type of weight of edges
   */
  template <typename T>
  class zero_one_bfs {
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

    zero_one_bfs(const ::std::size_t& node_count) :
      edges(node_count) {
    }

    ::std::size_t node_count() const {
      return this->edges.size();
    }

    void add_edge(const ::std::size_t& from, const ::std::size_t& to, const T& distance) {
      assert(distance == 0 || distance == 1);

      this->edges[from].emplace_back(from, to, distance);
    }

    result query(const ::std::size_t& start_node) const {
      assert(start_node < this->node_count());

      result result(this->node_count(), start_node);
      ::std::vector<bool> visited(this->node_count(), false);
      ::std::deque<::std::size_t> deque;
      deque.push_front(start_node);

      while (!deque.empty()) {
        const ::std::size_t vertex = deque.front();
        deque.pop_front();
        if (visited[vertex]) continue;
        visited[vertex] = true;
        for (const edge& edge : this->edges[vertex]) {
          const T new_distance = result.distances[vertex] + edge.distance;
          if (new_distance < result.distances[edge.to]) {
            result.distances[edge.to] = new_distance;
            result.prev_nodes[edge.to] = edge.from;
            if (edge.distance == 0) {
              deque.push_front(edge.to);
            } else {
              deque.push_back(edge.to);
            }
          }
        }
      }

      return result;
    }
  };
}

#endif
