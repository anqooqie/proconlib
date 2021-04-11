#ifndef TOOLS_TSORT_HPP
#define TOOLS_TSORT_HPP

#include <vector>
#include <cstddef>
#include <vector>
#include <queue>

namespace tools {

  class tsort {
  private:
    ::std::vector<::std::vector<::std::size_t>> edges;

  public:
    explicit tsort(const ::std::size_t node_count) : edges(node_count) {
    }

    ::std::size_t node_count() const noexcept {
      return this->edges.size();
    }

    void add_edge(const ::std::size_t s, const ::std::size_t t) {
      this->edges[s].push_back(t);
    }

    template <typename OutputIterator>
    void query(OutputIterator result) const {

      ::std::vector<::std::size_t> indegs(this->node_count(), 0);
      for (::std::size_t s = 0; s < this->node_count(); ++s) {
        for (const ::std::size_t t : this->edges[s]) {
          ++indegs[t];
        }
      }

      ::std::queue<::std::size_t> queue;
      for (::std::size_t v = 0; v < this->node_count(); ++v) {
        if (indegs[v] == 0) {
          queue.push(v);
        }
      }

      while (!queue.empty()) {
        const ::std::size_t s = queue.front();
        queue.pop();
        *result = s;
        ++result;
        for (const ::std::size_t t : edges[s]) {
          --indegs[t];
          if (indegs[t] == 0) {
            queue.push(t);
          }
        }
      }
    }
  };
}

#endif
