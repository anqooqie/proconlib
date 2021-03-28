#ifndef DINIC_HPP
#define DINIC_HPP

#include <cstddef>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

/*
usage:

tools::dinic<std::int_fast64_t> dinic(node_count);
dinic.add_edge(from_node, to_node, capacity);
dinic.calc(s, t) //=> maximum flow
*/

// Source: tkw's diary ( http://vartkw.hatenablog.com/entry/2016/12/02/002703 )
namespace tools {
  template <typename T>
  class dinic {
  private:
    class edge {
    private:
      std::size_t m_id;
      std::size_t m_to;
      T m_capacity;
      std::size_t m_rev_id;

    public:
      edge(const std::size_t id, const std::size_t to, const T capacity, const std::size_t rev_id) :
        m_id(id),
        m_to(to),
        m_capacity(capacity),
        m_rev_id(rev_id) {
      }

      std::size_t id() const {
        return this->m_id;
      }
      std::size_t to() const {
        return this->m_to;
      }
      T capacity() const {
        return this->m_capacity;
      }
      std::size_t rev_id() const {
        return this->m_rev_id;
      }
    };

    class buffer {
    public:
      std::vector<T> capacities;
      std::vector<std::size_t> distances;
      std::vector<std::size_t> next_edges;

      buffer(const dinic& dinic) :
        capacities(dinic.edge_count),
        distances(dinic.node_count(), std::numeric_limits<std::size_t>::max()),
        next_edges(dinic.node_count(), 0) {
        for (const std::vector<edge>& edges_from_node : dinic.edges) {
          for (const edge& edge : edges_from_node) {
            this->capacities[edge.id()] = edge.capacity();
          }
        }
      }

      void reset_for_each_loop() {
        std::fill(this->distances.begin(), this->distances.end(), std::numeric_limits<std::size_t>::max());
        std::fill(this->next_edges.begin(), this->next_edges.end(), 0);
      }
    };

    std::size_t edge_count;
    std::vector<std::vector<edge>> edges;

    void bfs(buffer& buffer, const std::size_t s) const {
      buffer.distances[s] = 0;
      std::queue<std::size_t> queue;
      queue.push(s);
      while (!queue.empty()) {
        const std::size_t from = queue.front();
        queue.pop();
        for (const edge& edge : this->edges[from]) {
          if (buffer.capacities[edge.id()] > 0 && buffer.distances[edge.to()] == std::numeric_limits<std::size_t>::max()) {
            buffer.distances[edge.to()] = buffer.distances[from] + 1;
            queue.push(edge.to());
          }
        }
      }
    }

    T dfs(buffer& buffer, const std::size_t from, const std::size_t t, const T possible_capacity) const {
      if (from == t) return possible_capacity;
      for (std::size_t i = buffer.next_edges[from]; i < this->edges[from].size(); ++i) {
        const edge& edge = this->edges[from][i];
        buffer.next_edges[from] = i;
        if (buffer.capacities[edge.id()] > 0 && buffer.distances[from] < buffer.distances[edge.to()]) {
          const T min_capacity = this->dfs(buffer, edge.to(), t, std::min(possible_capacity, buffer.capacities[edge.id()]));
          if (min_capacity > 0) {
            buffer.capacities[edge.id()] -= min_capacity;
            buffer.capacities[edge.rev_id()] += min_capacity;
            return min_capacity;
          }
        }
      }
      return 0;
    }

  public:
    dinic(const std::size_t node_count) :
      edge_count(0),
      edges(node_count) {
    }

    std::size_t node_count() const {
      return this->edges.size();
    }

    void add_edge(const std::size_t from, const std::size_t to, const T capacity) {
      this->edges[from].emplace_back(this->edge_count, to, capacity, this->edge_count + 1);
      this->edges[to].emplace_back(this->edge_count + 1, from, 0, this->edge_count);
      this->edge_count += 2;
    }

    T calc(const std::size_t s, const std::size_t t) const {
      T result = 0;
      buffer buffer(*this);
      while (true) {
        buffer.reset_for_each_loop();
        this->bfs(buffer, s);
        if (buffer.distances[t] == std::numeric_limits<std::size_t>::max()) return result;
        T min_capacity;
        while ((min_capacity = this->dfs(buffer, s, t, std::numeric_limits<T>::max())) > 0) {
          result += min_capacity;
        }
      }
      return result;
    }
  };
}

#endif
