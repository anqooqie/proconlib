#ifndef TOOLS_LOWLINK_HPP
#define TOOLS_LOWLINK_HPP

#include <cstddef>
#include <vector>
#include <iterator>
#include <cassert>
#include <tuple>
#include <algorithm>
#include <limits>
#include <stack>
#include <utility>
#include <initializer_list>
#include "tools/chmin.hpp"
#include "tools/less_by.hpp"
#include "tools/fix.hpp"

namespace tools {
  class lowlink {
  public:
    struct edge {
      ::std::size_t id;
      ::std::size_t from;
      ::std::size_t to;
    };

  private:
    ::std::vector<edge> m_edges;
    ::std::vector<::std::vector<::std::size_t>> m_graph;
    bool m_built;
    ::std::vector<::std::size_t> m_from;
    ::std::vector<::std::size_t> m_ord;
    ::std::vector<::std::size_t> m_low;
    ::std::size_t m_ncc;
    ::std::vector<::std::size_t> m_ncc_without_vertex;

  public:
    class neighbors_iterable {
    private:
      ::tools::lowlink const *m_parent;
      ::std::size_t m_v;

    public:
      class iterator {
      private:
        ::tools::lowlink const *m_parent;
        ::std::size_t m_v;
        ::std::size_t m_i;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = ::std::size_t;
        using reference = const ::std::size_t&;
        using pointer = const ::std::size_t*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(::tools::lowlink const * const parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v), m_i(i) {
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
      neighbors_iterable(::tools::lowlink const * const parent, const ::std::size_t v) : m_parent(parent), m_v(v) {
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
      ::tools::lowlink const *m_parent;
      ::std::size_t m_v;

    public:
      class iterator {
      private:
        ::tools::lowlink const *m_parent;
        ::std::size_t m_v;
        ::std::size_t m_i;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = edge;
        using reference = const edge&;
        using pointer = const edge*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(::tools::lowlink const * const parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v), m_i(i) {
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
      edges_iterable(::tools::lowlink const * const parent, const ::std::size_t v) : m_parent(parent), m_v(v) {
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
      ::tools::lowlink const *m_parent;
      ::std::size_t m_v;

    public:
      class iterator {
      private:
        ::tools::lowlink const *m_parent;
        ::std::size_t m_v;
        ::std::size_t m_i;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = ::std::size_t;
        using reference = const ::std::size_t&;
        using pointer = const ::std::size_t*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(::tools::lowlink const * const parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v), m_i(i) {
          const auto& eids = this->m_parent->m_graph[this->m_v];
          for (; this->m_i < eids.size() && [&]() {
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
          assert(this->m_i < eids.size());

          for (++this->m_i; this->m_i < eids.size() && [&]() {
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
      vchildren_iterable(::tools::lowlink const * const parent, const ::std::size_t v) : m_parent(parent), m_v(v) {
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
      ::tools::lowlink const *m_parent;
      ::std::size_t m_v;

    public:
      class iterator {
      private:
        ::tools::lowlink const *m_parent;
        ::std::size_t m_v;
        ::std::size_t m_i;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = edge;
        using reference = const edge&;
        using pointer = const edge*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(::tools::lowlink const * const parent, const ::std::size_t v, const ::std::size_t i) : m_parent(parent), m_v(v), m_i(i) {
          const auto& eids = this->m_parent->m_graph[this->m_v];
          for (; this->m_i < eids.size() && [&]() {
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
          assert(this->m_i < eids.size());

          for (++this->m_i; this->m_i < eids.size() && [&]() {
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
      echildren_iterable(::tools::lowlink const * const parent, const ::std::size_t v) : m_parent(parent), m_v(v) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_v, 0);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_v, this->m_parent->m_graph[this->m_v].size());
      }
    };

    lowlink() = default;
    explicit lowlink(const ::std::size_t n) : m_graph(n), m_built(false) {
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    ::std::size_t add_edge(::std::size_t u, ::std::size_t v) {
      assert(!this->m_built);
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

    neighbors_iterable neighbors(const ::std::size_t v) const {
      assert(v < this->size());
      return neighbors_iterable(this, v);
    }

    edges_iterable edges(const ::std::size_t v) const {
      assert(v < this->size());
      return edges_iterable(this, v);
    }

    void build() {
      assert(!this->m_built);
      this->m_built = true;

      const auto N_A = ::std::numeric_limits<::std::size_t>::max();

      this->m_from.assign(this->size(), N_A);
      this->m_ord.assign(this->size(), N_A);
      this->m_low.assign(this->size(), N_A);
      this->m_ncc = 0;

      for (::std::size_t r = 0; r < this->size(); ++r) {
        if (this->m_ord[r] != N_A) continue;

        ++this->m_ncc;
        ::std::size_t next_ord = 0;

        ::std::stack<::std::pair<::std::size_t, ::std::size_t>> stack;
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
                ::tools::chmin(this->m_low[v], this->m_ord[u]);
              } else if (this->m_ord[u] > this->m_ord[v] && eid == this->m_from[u]) {
                ::tools::chmin(this->m_low[v], this->m_low[u]);
              }
            }
          }
        }

        this->m_from[r] = N_A;
      }

      this->m_ncc_without_vertex.assign(this->size(), this->m_ncc);
      for (::std::size_t v = 0; v < this->size(); ++v) {
        if (this->m_ord[v] == 0) {
          this->m_ncc_without_vertex[v] += ::std::distance(this->echildren(v).begin(), this->echildren(v).end());
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

    ::std::size_t vparent(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      assert(this->m_ord[v] > 0);

      const auto& edge = this->m_edges[this->m_from[v]];
      return edge.from ^ edge.to ^ v;
    }

    const edge& eparent(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      assert(this->m_ord[v] > 0);

      return this->m_edges[this->m_from[v]];
    }

    vchildren_iterable vchildren(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());

      return vchildren_iterable(this, v);
    }

    echildren_iterable echildren(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());

      return echildren_iterable(this, v);
    }

    ::std::size_t ord(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());

      return this->m_ord[v];
    }

    ::std::size_t low(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());

      return this->m_low[v];
    }

    ::std::size_t ncc() const {
      assert(this->m_built);

      return this->m_ncc;
    }

    ::std::size_t ncc_without_vertex(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());

      return this->m_ncc_without_vertex[v];
    }

    bool is_articulation_point(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());

      return this->m_ncc_without_vertex[v] > this->m_ncc;
    }

    bool is_bridge(const ::std::size_t k) const {
      assert(this->m_built);
      assert(k < this->m_edges.size());

      const auto [u, v] = ::std::minmax({this->m_edges[k].from, this->m_edges[k].to}, ::tools::less_by([&](const auto w) { return this->m_ord[w]; }));
      return this->m_ord[u] < this->m_low[v];
    }

    ::std::vector<::std::vector<::std::size_t>> biconnected_components() const {
      assert(this->m_built);

      ::std::vector<::std::vector<::std::size_t>> groups;

      for (::std::size_t r = 0; r < this->size(); ++r) {
        if (this->ord(r) == 0) {
          if (this->m_ncc_without_vertex[r] < this->m_ncc) {
            groups.emplace_back(::std::initializer_list<::std::size_t>{r});
          } else {
            ::tools::fix([&](auto&& dfs, const auto g, const auto v) -> void {
              for (const auto u : this->vchildren(v)) {
                if (this->ord(v) <= this->low(u)) {
                  groups.emplace_back(::std::initializer_list<::std::size_t>{v, u});
                  dfs(groups.size() - 1, u);
                } else {
                  groups[g].push_back(u);
                  dfs(g, u);
                }
              }
            })(::std::numeric_limits<::std::size_t>::max(), r);
          }
        }
      }

      return groups;
    }
  };
}

#endif
