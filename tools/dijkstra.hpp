#ifndef TOOLS_DIJKSTRA_HPP
#define TOOLS_DIJKSTRA_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <cassert>
#include <functional>
#include <queue>

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

    class task {
    public:
      ::std::size_t vertex;
      T distance;
      task(const ::std::size_t vertex, const ::std::size_t distance) :
        vertex(vertex), distance(distance) {
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
      ::std::vector<bool> visited(this->node_count(), false);
      const auto compare = [](const task& x, const task& y) {
        return x.distance > y.distance;
      };
      ::std::priority_queue<task, ::std::vector<task>, decltype(compare)> tasks(compare);
      tasks.emplace(start_node, 0);

      while (!tasks.empty()) {
        const task task = tasks.top();
        tasks.pop();
        if (visited[task.vertex]) continue;
        visited[task.vertex] = true;
        for (const edge& edge : this->edges[task.vertex]) {
          const T new_distance = task.distance + edge.distance;
          if (new_distance < result.distances[edge.to]) {
            result.distances[edge.to] = new_distance;
            result.prev_nodes[edge.to] = edge.from;
            tasks.emplace(edge.to, new_distance);
          }
        }
      }

      return result;
    }
  };
}

#endif
