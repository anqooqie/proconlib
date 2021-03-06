#ifndef TOOLS_BELLMAN_FORD_HPP
#define TOOLS_BELLMAN_FORD_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <cassert>
#include "tools/safe_int.hpp"
#include "tools/chmin.hpp"

namespace tools {

  template <typename T>
  class bellman_ford {
  private:
    class edge {
    public:
      ::std::size_t from;
      ::std::size_t to;
      T distance;
      edge(const ::std::size_t& from, const ::std::size_t& to, const T& distance) :
        from(from),
        to(to),
        distance(distance) {
      }
    };

    ::std::size_t m_node_count;
    ::std::vector<edge> m_edges;

  public:
    constexpr inline static T POS_INF = ::std::numeric_limits<T>::max();
    constexpr inline static T NEG_INF = ::std::numeric_limits<T>::min();
    constexpr inline static ::std::size_t NONE = ::std::numeric_limits<::std::size_t>::max();

    class result {
    public:
      ::std::vector<T> distances;
      ::std::vector<::std::size_t> prev_nodes;
      result(const ::std::size_t& node_count) :
        distances(node_count, POS_INF),
        prev_nodes(node_count, NONE) {
      }
    };

    explicit bellman_ford(const ::std::size_t& node_count) :
      m_node_count(node_count),
      m_edges() {
    }

    ::std::size_t node_count() const {
      return this->m_node_count;
    }

    void add_edge(const ::std::size_t& from, const ::std::size_t& to, const T& distance) {
      this->m_edges.emplace_back(from, to, distance);
    }

    result query(const ::std::size_t& start_node) const {
      assert(start_node < this->m_node_count);
      result result(this->m_node_count);
      result.distances[start_node] = 0;
      for (::std::size_t i = 0; i < this->m_node_count - 1; ++i) {
        for (const edge& edge : this->m_edges) {
          if (::tools::chmin(result.distances[edge.to], (::tools::safe_int(result.distances[edge.from]) + tools::safe_int(edge.distance)).val())) {
            result.prev_nodes[edge.to] = edge.from;
          }
        }
      }
      for (const edge& edge : this->m_edges) {
        if ((::tools::safe_int(result.distances[edge.from]) + tools::safe_int(edge.distance)).val() < result.distances[edge.to]) {
          result.distances[edge.to] = NEG_INF;
          result.prev_nodes[edge.to] = edge.from;
        }
      }
      for (::std::size_t i = 0; i < this->m_node_count; ++i) {
        for (const edge& edge : this->m_edges) {
          if (::tools::chmin(result.distances[edge.to], (::tools::safe_int(result.distances[edge.from]) + tools::safe_int(edge.distance)).val())) {
            result.prev_nodes[edge.to] = edge.from;
          }
        }
      }
      return result;
    }
  };
}

#endif
