#ifndef TOOLS_HLD_HPP
#define TOOLS_HLD_HPP

#include <vector>
#include <cstddef>
#include <iterator>
#include <cassert>
#include <limits>
#include <stack>
#include <utility>
#include <algorithm>
#include "atcoder/dsu.hpp"
#include "tools/less_by.hpp"

namespace tools {
  class hld {
  private:
    bool m_built;
    ::std::vector<::std::vector<::std::size_t>> m_graph;
    ::std::vector<::std::size_t> m_edges;
    ::std::vector<::std::size_t> m_parent;
    ::std::vector<::std::size_t> m_depth;
    ::atcoder::dsu m_dsu;
    ::std::vector<::std::size_t> m_out;
    ::std::vector<::std::size_t> m_vid2dfs;
    ::std::vector<::std::size_t> m_dfs2vid;
    ::std::vector<::std::size_t> m_eid2dfs;
    ::std::vector<::std::size_t> m_dfs2eid;

  public:
    class vchildren_iterable {
    private:
      ::tools::hld const *m_parent;
      ::std::size_t m_v;

    public:
      class iterator {
      private:
        ::tools::hld const *m_parent;
        ::std::size_t m_v;
        ::std::size_t m_i;

      public:
        using difference_type = ::std::ptrdiff_t;
        using value_type = ::std::size_t;
        using reference = ::std::size_t&;
        using pointer = ::std::size_t*;
        using iterator_category = ::std::input_iterator_tag;

        iterator() = default;
        iterator(const iterator&) = default;
        iterator(iterator&&) = default;
        ~iterator() = default;
        iterator& operator=(const iterator&) = default;
        iterator& operator=(iterator&&) = default;

        iterator(::tools::hld const * const parent, const ::std::size_t v, const ::std::size_t i) :
          m_parent(parent),
          m_v(v),
          m_i(i) {
        }

        ::std::size_t operator*() const {
          return this->m_parent->m_edges[this->m_parent->m_graph[this->m_v][this->m_i]] ^ this->m_v;
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
          return lhs.m_parent == rhs.m_parent && lhs.m_v == rhs.m_v && lhs.m_i == rhs.m_i;
        }
        friend bool operator!=(const iterator& lhs, const iterator& rhs) {
          return !(lhs == rhs);
        }
      };

      vchildren_iterable() = default;
      vchildren_iterable(const vchildren_iterable&) = default;
      vchildren_iterable(vchildren_iterable&&) = default;
      ~vchildren_iterable() = default;
      vchildren_iterable& operator=(const vchildren_iterable&) = default;
      vchildren_iterable& operator=(vchildren_iterable&&) = default;

      vchildren_iterable(::tools::hld const * const parent, const ::std::size_t v) :
        m_parent(parent),
        m_v(v) {
      }

      iterator begin() const {
        return iterator(this->m_parent, this->m_v, 0);
      };
      iterator end() const {
        return iterator(this->m_parent, this->m_v, this->m_parent->m_graph[this->m_v].size());
      }
    };

    hld() = default;
    hld(const ::tools::hld&) = default;
    hld(::tools::hld&&) = default;
    ~hld() = default;
    ::tools::hld& operator=(const ::tools::hld&) = default;
    ::tools::hld& operator=(::tools::hld&&) = default;

    explicit hld(const ::std::size_t n) : m_built(false), m_graph(n) {
      assert(n >= 1);
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }

    void add_edge(const ::std::size_t u, const ::std::size_t v) {
      assert(!this->m_built);
      assert(u < this->size());
      assert(v < this->size());
      this->m_graph[u].push_back(this->m_edges.size());
      this->m_graph[v].push_back(this->m_edges.size());
      this->m_edges.push_back(u ^ v);
    }

    void build(const ::std::size_t root) {
      assert(!this->m_built);
      assert(root < this->size());
      assert(this->m_edges.size() + 1 == this->size());

      this->m_parent.resize(this->size());
      this->m_depth.resize(this->size());
      this->m_dsu = ::atcoder::dsu(this->size());
      this->m_out.resize(this->size());
      this->m_vid2dfs.resize(this->size());
      this->m_dfs2vid.resize(this->size());
      this->m_eid2dfs.resize(this->m_edges.size());
      this->m_dfs2eid.resize(this->m_edges.size());

      ::std::vector<::std::size_t> subtree_size(this->size());
      this->m_parent[root] = ::std::numeric_limits<::std::size_t>::max();
      this->m_depth[root] = 0;
      ::std::stack<::std::pair<::std::size_t, bool>> stack;
      stack.emplace(root, false);
      stack.emplace(root, true);
      while (!stack.empty()) {
        const auto [here, pre] = stack.top();
        stack.pop();
        if (pre) {
          for (const auto eid : this->m_graph[here]) {
            const auto next = this->m_edges[eid] ^ here;
            if (here == root || next != (this->m_edges[this->m_parent[here]] ^ here)) {
              this->m_parent[next] = eid;
              this->m_depth[next] = this->m_depth[here] + 1;
              stack.emplace(next, false);
              stack.emplace(next, true);
            }
          }
        } else {
          subtree_size[here] = 1;
          for (const auto eid : this->m_graph[here]) {
            const auto child = this->m_edges[eid] ^ here;
            if (here == root || child != (this->m_edges[this->m_parent[here]] ^ here)) {
              subtree_size[here] += subtree_size[child];
            }
          }
        }
      }

      for (::std::size_t v = 0; v < this->size(); ++v) {
        if (v != root) {
          this->m_graph[v].erase(::std::find(this->m_graph[v].begin(), this->m_graph[v].end(), this->m_parent[v]));
        }
        ::std::iter_swap(
          this->m_graph[v].begin(),
          ::std::max_element(
            this->m_graph[v].begin(),
            this->m_graph[v].end(),
            ::tools::less_by([&](const ::std::size_t eid) { return subtree_size[this->m_edges[eid] ^ v]; })
          )
        );
      }

      ::std::size_t dfs_order = 0;
      stack.emplace(root, false);
      stack.emplace(root, true);
      while (!stack.empty()) {
        const auto [here, pre] = stack.top();
        stack.pop();

        if (pre) {
          this->m_vid2dfs[here] = dfs_order;
          this->m_dfs2vid[dfs_order] = here;
          if (here != root) {
            this->m_eid2dfs[this->m_parent[here]] = dfs_order - 1;
            this->m_dfs2eid[dfs_order - 1] = this->m_parent[here];
          }
          ++dfs_order;

          if (!this->m_graph[here].empty()) {
            this->m_dsu.merge(here, this->m_edges[this->m_graph[here].front()] ^ here);
          }
          for (auto it = this->m_graph[here].rbegin(); it != this->m_graph[here].rend(); ++it) {
            stack.emplace(this->m_edges[*it] ^ here, false);
            stack.emplace(this->m_edges[*it] ^ here, true);
          }
        } else {
          this->m_out[here] = dfs_order;
        }
      }

      this->m_built = true;
    }
    void build() {
      this->build(0);
    }

    ::std::size_t depth(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      return this->m_depth[v];
    }
    ::std::size_t vparent(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      assert(this->m_depth[v] > 0);
      return this->m_edges[this->m_parent[v]] ^ v;
    }
    ::std::size_t eparent(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      assert(this->m_depth[v] > 0);
      return this->m_parent[v];
    }
    ::tools::hld::vchildren_iterable vchildren(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      return ::tools::hld::vchildren_iterable(this, v);
    }
    const ::std::vector<::std::size_t>& echildren(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      return this->m_graph[v];
    }

    ::std::size_t vid2dfs(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      return this->m_vid2dfs[v];
    }
    ::std::size_t dfs2vid(const ::std::size_t i) const {
      assert(this->m_built);
      assert(i < this->size());
      return this->m_dfs2vid[i];
    }
    ::std::size_t eid2dfs(const ::std::size_t e) const {
      assert(this->m_built);
      assert(e < this->size());
      return this->m_eid2dfs[e];
    }
    ::std::size_t dfs2eid(const ::std::size_t i) const {
      assert(this->m_built);
      assert(i < this->size());
      return this->m_dfs2eid[i];
    }

    ::std::size_t lca(::std::size_t u, ::std::size_t v) {
      assert(this->m_built);
      assert(u < this->size());
      assert(v < this->size());

      while (!this->m_dsu.same(u, v)) {
        if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)]) {
          u = this->m_edges[this->m_parent[this->m_dsu.leader(u)]] ^ this->m_dsu.leader(u);
        } else {
          v = this->m_edges[this->m_parent[this->m_dsu.leader(v)]] ^ this->m_dsu.leader(v);
        }
      }
      if (this->m_depth[u] >= this->m_depth[v]) {
        return v;
      } else {
        return u;
      }
    }

    ::std::pair<::std::size_t, ::std::size_t> vsubtree(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      return ::std::make_pair(this->m_vid2dfs[v], this->m_out[v]);
    }
    ::std::pair<::std::size_t, ::std::size_t> esubtree(const ::std::size_t v) const {
      assert(this->m_built);
      assert(v < this->size());
      return ::std::make_pair(this->m_depth[v] == 0 ? 0 : this->m_eid2dfs[this->m_parent[v]] + 1, this->m_out[v] - 1);
    }

    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> vpath(::std::size_t u, ::std::size_t v) {
      assert(this->m_built);
      assert(u < this->size());
      assert(v < this->size());

      ::std::vector<::std::pair<::std::size_t, ::std::size_t>> head, tail;
      while (!this->m_dsu.same(u, v)) {
        if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)]) {
          head.emplace_back(this->m_vid2dfs[u] + 1, this->m_vid2dfs[this->m_dsu.leader(u)]);
          u = this->m_edges[this->m_parent[this->m_dsu.leader(u)]] ^ this->m_dsu.leader(u);
        } else {
          tail.emplace_back(this->m_vid2dfs[this->m_dsu.leader(v)], this->m_vid2dfs[v] + 1);
          v = this->m_edges[this->m_parent[this->m_dsu.leader(v)]] ^ this->m_dsu.leader(v);
        }
      }
      if (this->m_depth[u] >= this->m_depth[v]) {
        head.emplace_back(this->m_vid2dfs[u] + 1, this->m_vid2dfs[v]);
      } else {
        head.emplace_back(this->m_vid2dfs[u], this->m_vid2dfs[v] + 1);
      }

      ::std::copy(tail.rbegin(), tail.rend(), ::std::back_inserter(head));
      return head;
    }
    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> epath(::std::size_t u, ::std::size_t v) {
      assert(this->m_built);
      assert(u < this->size());
      assert(v < this->size());

      ::std::vector<::std::pair<::std::size_t, ::std::size_t>> head, tail;
      while (!this->m_dsu.same(u, v)) {
        if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)]) {
          head.emplace_back(this->m_eid2dfs[this->m_parent[u]] + 1, this->m_eid2dfs[this->m_parent[this->m_dsu.leader(u)]]);
          u = this->m_edges[this->m_parent[this->m_dsu.leader(u)]] ^ this->m_dsu.leader(u);
        } else {
          tail.emplace_back(this->m_eid2dfs[this->m_parent[this->m_dsu.leader(v)]], this->m_eid2dfs[this->m_parent[v]] + 1);
          v = this->m_edges[this->m_parent[this->m_dsu.leader(v)]] ^ this->m_dsu.leader(v);
        }
      }
      if (this->m_depth[u] > this->m_depth[v]) {
        head.emplace_back(this->m_eid2dfs[this->m_parent[u]] + 1, this->m_eid2dfs[this->m_graph[v].front()]);
      } else if (this->m_depth[u] < this->m_depth[v]) {
        head.emplace_back(this->m_eid2dfs[this->m_graph[u].front()], this->m_eid2dfs[this->m_parent[v]] + 1);
      }

      ::std::copy(tail.rbegin(), tail.rend(), ::std::back_inserter(head));
      return head;
    }
  };
}

#endif
