#ifndef TOOLS_LOWLINK_HPP
#define TOOLS_LOWLINK_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <limits>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/chmin.hpp"
#include "tools/fix.hpp"
#include "tools/less_by.hpp"

namespace tools {
  class lowlink {
  public:
    struct edge {
      int from;
      int to;
    };

  private:
    std::vector<edge> m_edges;
    std::vector<std::vector<int>> m_graph;
    bool m_built;
    std::vector<int> m_from;
    std::vector<int> m_ord;
    std::vector<int> m_low;
    int m_ncc;
    std::vector<int> m_ncc_without_vertex;

  public:
    class neighbors_iterable {
    private:
      tools::lowlink const *m_parent;
      int m_v;

    public:
      class iterator {
      private:
        tools::lowlink const *m_parent;
        int m_v;
        int m_i;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using reference = const int&;
        using pointer = const int*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::lowlink const * const parent, const int v, const int i) : m_parent(parent), m_v(v), m_i(i) {
        }

        value_type operator*() const {
          const auto& edge = this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];
          return edge.from ^ edge.to ^ this->m_v;
        }
        iterator& operator++() {
          ++this->m_i;
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          assert(lhs.m_v == rhs.m_v);
          return lhs.m_i == rhs.m_i;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      neighbors_iterable() = default;
      neighbors_iterable(tools::lowlink const * const parent, const int v) : m_parent(parent), m_v(v) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_v, 0);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_v, this->m_parent->m_graph[this->m_v].size());
      }
    };

    class edges_iterable {
    private:
      tools::lowlink const *m_parent;
      int m_v;

    public:
      class iterator {
      private:
        tools::lowlink const *m_parent;
        int m_v;
        int m_i;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = edge;
        using reference = const edge&;
        using pointer = const edge*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::lowlink const * const parent, const int v, const int i) : m_parent(parent), m_v(v), m_i(i) {
        }

        reference operator*() const {
          return this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];
        }
        iterator& operator++() {
          ++this->m_i;
          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          assert(lhs.m_v == rhs.m_v);
          return lhs.m_i == rhs.m_i;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      edges_iterable() = default;
      edges_iterable(tools::lowlink const * const parent, const int v) : m_parent(parent), m_v(v) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_v, 0);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_v, this->m_parent->m_graph[this->m_v].size());
      }
    };

    class vchildren_iterable {
    private:
      tools::lowlink const *m_parent;
      int m_v;

    public:
      class iterator {
      private:
        tools::lowlink const *m_parent;
        int m_v;
        int m_i;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using reference = const int&;
        using pointer = const int*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::lowlink const * const parent, const int v, const int i) : m_parent(parent), m_v(v), m_i(i) {
          const auto& eids = this->m_parent->m_graph[this->m_v];
          for (; this->m_i < std::ssize(eids) && [&]() {
            const auto eid = eids[this->m_i];
            const auto& edge = this->m_parent->m_edges[eid];
            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;
          }(); ++this->m_i);
        }

        value_type operator*() const {
          const auto& edge = this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];
          return edge.from ^ edge.to ^ this->m_v;
        }
        iterator& operator++() {
          const auto& eids = this->m_parent->m_graph[this->m_v];
          assert(this->m_i < std::ssize(eids));

          for (++this->m_i; this->m_i < std::ssize(eids) && [&]() {
            const auto eid = eids[this->m_i];
            const auto& edge = this->m_parent->m_edges[eid];
            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;
          }(); ++this->m_i);

          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          assert(lhs.m_v == rhs.m_v);
          return lhs.m_i == rhs.m_i;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      vchildren_iterable() = default;
      vchildren_iterable(tools::lowlink const * const parent, const int v) : m_parent(parent), m_v(v) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_v, 0);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_v, this->m_parent->m_graph[this->m_v].size());
      }
    };

    class echildren_iterable {
    private:
      tools::lowlink const *m_parent;
      int m_v;

    public:
      class iterator {
      private:
        tools::lowlink const *m_parent;
        int m_v;
        int m_i;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = edge;
        using reference = const edge&;
        using pointer = const edge*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::lowlink const * const parent, const int v, const int i) : m_parent(parent), m_v(v), m_i(i) {
          const auto& eids = this->m_parent->m_graph[this->m_v];
          for (; this->m_i < std::ssize(eids) && [&]() {
            const auto eid = eids[this->m_i];
            const auto& edge = this->m_parent->m_edges[eid];
            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;
          }(); ++this->m_i);
        }

        reference operator*() const {
          return this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]];
        }
        iterator& operator++() {
          const auto& eids = this->m_parent->m_graph[this->m_v];
          assert(this->m_i < std::ssize(eids));

          for (++this->m_i; this->m_i < std::ssize(eids) && [&]() {
            const auto eid = eids[this->m_i];
            const auto& edge = this->m_parent->m_edges[eid];
            return this->m_parent->m_from[edge.from ^ edge.to ^ this->m_v] != eid;
          }(); ++this->m_i);

          return *this;
        }
        iterator operator++(int) {
          const auto self = *this;
          ++*this;
          return self;
        }
        friend bool operator==(const iterator& lhs, const iterator& rhs) {
          assert(lhs.m_parent == rhs.m_parent);
          assert(lhs.m_v == rhs.m_v);
          return lhs.m_i == rhs.m_i;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      echildren_iterable() = default;
      echildren_iterable(tools::lowlink const * const parent, const int v) : m_parent(parent), m_v(v) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_v, 0);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_v, this->m_parent->m_graph[this->m_v].size());
      }
    };

    lowlink() = default;
    explicit lowlink(const int n) : m_graph(n), m_built(false) {
    }

    int size() const {
      return this->m_graph.size();
    }

    int add_edge(int u, int v) {
      assert(!this->m_built);
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      std::tie(u, v) = std::minmax({u, v});
      this->m_edges.push_back(edge{u, v});
      this->m_graph[u].push_back(this->m_edges.size() - 1);
      this->m_graph[v].push_back(this->m_edges.size() - 1);
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const int k) const {
      assert(0 <= k && k < std::ssize(this->m_edges));
      return this->m_edges[k];
    }

    const std::vector<edge>& edges() const {
      return this->m_edges;
    }

    neighbors_iterable neighbors(const int v) const {
      assert(0 <= v && v < this->size());
      return neighbors_iterable(this, v);
    }

    edges_iterable edges(const int v) const {
      assert(0 <= v && v < this->size());
      return edges_iterable(this, v);
    }

    void build() {
      assert(!this->m_built);
      this->m_built = true;

      const auto N_A = -1;

      this->m_from.assign(this->size(), N_A);
      this->m_ord.assign(this->size(), N_A);
      this->m_low.assign(this->size(), N_A);
      this->m_ncc = 0;

      for (int r = 0; r < this->size(); ++r) {
        if (this->m_ord[r] != N_A) continue;

        ++this->m_ncc;
        int next_ord = 0;

        std::stack<std::pair<int, int>> stack;
        stack.emplace(r, N_A);
        stack.emplace(r, N_A - 1);
        while (!stack.empty()) {
          const auto [v, from] = stack.top();
          stack.pop();

          if (from != N_A) {
            if (this->m_ord[v] != N_A) continue;

            this->m_from[v] = from;
            this->m_ord[v] = next_ord++;

            for (const auto eid : this->m_graph[v]) {
              const auto& edge = this->m_edges[eid];
              const auto u = edge.from ^ edge.to ^ v;
              if (this->m_ord[u] != N_A) continue;

              stack.emplace(u, N_A);
              stack.emplace(u, eid);
            }
          } else {
            if (this->m_low[v] != N_A) continue;

            this->m_low[v] = this->m_ord[v];
            for (const auto eid : this->m_graph[v]) {
              const auto& edge = this->m_edges[eid];
              const auto u = edge.from ^ edge.to ^ v;
              if (this->m_ord[u] < this->m_ord[v] && eid != this->m_from[v]) {
                tools::chmin(this->m_low[v], this->m_ord[u]);
              } else if (this->m_ord[u] > this->m_ord[v] && eid == this->m_from[u]) {
                tools::chmin(this->m_low[v], this->m_low[u]);
              }
            }
          }
        }

        this->m_from[r] = N_A;
      }

      this->m_ncc_without_vertex.assign(this->size(), this->m_ncc);
      for (int v = 0; v < this->size(); ++v) {
        if (this->m_ord[v] == 0) {
          this->m_ncc_without_vertex[v] += std::distance(this->echildren(v).begin(), this->echildren(v).end());
          --this->m_ncc_without_vertex[v];
        } else {
          for (const auto& edge : this->echildren(v)) {
            const auto u = edge.from ^ edge.to ^ v;
            if (this->m_ord[v] <= this->m_low[u]) {
              ++this->m_ncc_without_vertex[v];
            }
          }
        }
      }
    }

    int vparent(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      assert(this->m_ord[v] > 0);

      const auto& edge = this->m_edges[this->m_from[v]];
      return edge.from ^ edge.to ^ v;
    }

    const edge& eparent(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      assert(this->m_ord[v] > 0);

      return this->m_edges[this->m_from[v]];
    }

    vchildren_iterable vchildren(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());

      return vchildren_iterable(this, v);
    }

    echildren_iterable echildren(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());

      return echildren_iterable(this, v);
    }

    int ord(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());

      return this->m_ord[v];
    }

    int low(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());

      return this->m_low[v];
    }

    int ncc() const {
      assert(this->m_built);

      return this->m_ncc;
    }

    int ncc_without_vertex(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());

      return this->m_ncc_without_vertex[v];
    }

    bool is_articulation_point(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());

      return this->m_ncc_without_vertex[v] > this->m_ncc;
    }

    bool is_bridge(const int k) const {
      assert(this->m_built);
      assert(0 <= k && k < std::ssize(this->m_edges));

      const auto [u, v] = std::minmax({this->m_edges[k].from, this->m_edges[k].to}, tools::less_by([&](const auto w) { return this->m_ord[w]; }));
      return this->m_ord[u] < this->m_low[v];
    }

    std::vector<std::vector<int>> biconnected_components() const {
      assert(this->m_built);

      std::vector<std::vector<int>> groups;

      for (int r = 0; r < this->size(); ++r) {
        if (this->ord(r) == 0) {
          if (this->m_ncc_without_vertex[r] < this->m_ncc) {
            groups.emplace_back(std::initializer_list<int>{r});
          } else {
            tools::fix([&](auto&& dfs, const auto g, const auto v) -> void {
              for (const auto u : this->vchildren(v)) {
                if (this->ord(v) <= this->low(u)) {
                  groups.emplace_back(std::initializer_list<int>{v, u});
                  dfs(groups.size() - 1, u);
                } else {
                  groups[g].push_back(u);
                  dfs(g, u);
                }
              }
            })(-1, r);
          }
        }
      }

      return groups;
    }
  };
}

#endif
