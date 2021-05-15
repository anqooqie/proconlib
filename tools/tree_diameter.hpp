#ifndef TOOLS_TREE_DIAMETER_HPP
#define TOOLS_TREE_DIAMETER_HPP

#include <cstddef>
#include <vector>
#include <cassert>
#include <numeric>
#include <limits>
#include <queue>
#include <iterator>
#include <algorithm>
#include "tools/chmin.hpp"

namespace tools {
  template <typename T>
  class tree_diameter {
  private:
    class edge {
    public:
      ::std::size_t from;
      ::std::size_t to;
      T distance;
      edge(const ::std::size_t from, const ::std::size_t to, const T& distance) :
        from(from),
        to(to),
        distance(distance) {
      }
    };

    ::std::vector<::std::vector<edge>> edges;

  public:
    tree_diameter(const ::std::size_t node_count) :
      edges(node_count) {
    }

    ::std::size_t node_count() const {
      return this->edges.size();
    }

    void add_edge(const ::std::size_t from, const ::std::size_t to, const T& distance) {
      this->edges[from].emplace_back(from, to, distance);
      this->edges[to].emplace_back(to, from, distance);
    }

    T query() const {
      assert(::std::accumulate(this->edges.begin(), this->edges.end(), ::std::size_t(0), [](const ::std::size_t sum, const ::std::vector<edge>& e) { return sum + e.size(); }) + 2 == this->node_count() * 2);

      ::std::vector<T> distances(this->node_count(), ::std::numeric_limits<T>::max());
      distances[0] = 0;
      ::std::queue<::std::size_t> queue({0});
      while (!queue.empty()) {
        const ::std::size_t from = queue.front();
        queue.pop();
        for (const edge& edge : edges[from]) {
          if (::tools::chmin(distances[edge.to], distances[from] + edge.distance)) {
            queue.push(edge.to);
          }
        }
      }

      queue.push(::std::distance(distances.begin(), ::std::max_element(distances.begin(), distances.end())));
      ::std::fill(distances.begin(), distances.end(), ::std::numeric_limits<T>::max());
      distances[queue.front()] = 0;
      while (!queue.empty()) {
        const ::std::size_t from = queue.front();
        queue.pop();
        for (const edge& edge : edges[from]) {
          if (::tools::chmin(distances[edge.to], distances[from] + edge.distance)) {
            queue.push(edge.to);
          }
        }
      }

      return *std::max_element(distances.begin(), distances.end());
    }
  };
}

#endif
