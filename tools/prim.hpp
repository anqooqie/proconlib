#ifndef TOOLS_PRIM_HPP
#define TOOLS_PRIM_HPP

#include <cstddef>
#include <vector>
#include <queue>
#include <functional>
#include <limits>

namespace tools {

  template <typename T>
  class prim {
  public:
    class edge {
    private:
      ::std::size_t m_from;
      ::std::size_t m_to;
      T m_distance;

    public:
      edge(const ::std::size_t& from, const ::std::size_t& to, const T& distance) :
        m_from(from),
        m_to(to),
        m_distance(distance) {
      }

      ::std::size_t from() const {
        return this->m_from;
      }
      ::std::size_t to() const {
        return this->m_to;
      }
      T distance() const {
        return this->m_distance;
      }
    };

    class result {
    public:
      T total_distance;
      ::std::vector<edge> edges;
      result() :
        total_distance(0), edges() {
      }
    };

    ::std::vector<::std::vector<edge>> edges;

    prim(const ::std::size_t& node_count) :
      edges(node_count) {
    }

    ::std::size_t node_count() const {
      return this->edges.size();
    }

    void add_edge(const ::std::size_t& v1, const ::std::size_t& v2, const T& distance) {
      this->edges[v1].emplace_back(v1, v2, distance);
      this->edges[v2].emplace_back(v2, v1, distance);
    }

    result query() const {
      result result;
      ::std::vector<bool> visited(this->node_count(), false);
      const auto greater_by_distance = [](const edge& x, const edge& y) {
        return x.distance() > y.distance();
      };
      ::std::priority_queue<edge, ::std::vector<edge>, decltype(greater_by_distance)> tasks(greater_by_distance);
      tasks.emplace(::std::numeric_limits<::std::size_t>::max(), 0, 0);
      bool is_first_task = true;

      while (!tasks.empty()) {
        const edge task = tasks.top();
        tasks.pop();
        if (visited[task.to()]) continue;
        if (is_first_task) {
          is_first_task = false;
        } else {
          result.total_distance += task.distance();
          result.edges.push_back(task);
        }
        visited[task.to()] = true;
        for (const edge& edge : this->edges[task.to()]) {
          if (!visited[edge.to()]) {
            tasks.push(edge);
          }
        }
      }

      return result;
    }
  };
}

#endif
