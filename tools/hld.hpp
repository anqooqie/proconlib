#ifndef TOOLS_HLD_HPP
#define TOOLS_HLD_HPP

#include <vector>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <limits>
#include <stack>
#include <utility>
#include <iterator>
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
    ::std::vector<::std::size_t> m_vid2dfs;
    ::std::vector<::std::size_t> m_dfs2vid;
    ::std::vector<::std::size_t> m_eid2dfs;
    ::std::vector<::std::size_t> m_dfs2eid;

  public:
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
    const ::std::vector<::std::size_t>& vid2dfs() const {
      assert(this->m_built);
      return this->m_vid2dfs;
    }
    const ::std::vector<::std::size_t>& dfs2vid() const {
      assert(this->m_built);
      return this->m_dfs2vid;
    }
    const ::std::vector<::std::size_t>& eid2dfs() const {
      assert(this->m_built);
      return this->m_eid2dfs;
    }
    const ::std::vector<::std::size_t>& dfs2eid() const {
      assert(this->m_built);
      return this->m_dfs2eid;
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
      this->m_vid2dfs.resize(this->size());
      this->m_dfs2vid.resize(this->size());
      this->m_eid2dfs.resize(this->m_edges.size());
      this->m_dfs2eid.resize(this->m_edges.size());

      ::std::vector<::std::size_t> subtree_size(this->size());
      this->m_parent[root] = ::std::numeric_limits<::std::size_t>::max();
      this->m_depth[root] = 0;
      {
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

      {
        ::std::size_t dfs_order = 0;
        ::std::stack<::std::size_t> stack;
        stack.push(root);
        while (!stack.empty()) {
          const auto here = stack.top();
          stack.pop();

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
            stack.push(this->m_edges[*it] ^ here);
          }
        }
      }

      this->m_built = true;
    }
    void build() {
      this->build(0);
    }

    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> vquery(::std::size_t u, ::std::size_t v) {
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

    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> equery(::std::size_t u, ::std::size_t v) {
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
