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
    ::std::vector<::std::vector<::std::size_t>> m_graph;
    ::std::vector<::std::size_t> m_parent;
    ::std::vector<::std::size_t> m_depth;
    ::atcoder::dsu m_dsu;
    ::std::vector<::std::size_t> m_idx2dfs;
    ::std::vector<::std::size_t> m_dfs2idx;

  public:
    hld() = default;
    hld(const ::tools::hld&) = default;
    hld(::tools::hld&&) = default;
    ~hld() = default;
    ::tools::hld& operator=(const ::tools::hld&) = default;
    ::tools::hld& operator=(::tools::hld&&) = default;

    explicit hld(const ::std::size_t n) : m_graph(n), m_parent(n), m_depth(n), m_idx2dfs(n), m_dfs2idx(n) {
      assert(n >= 1);
    }

    ::std::size_t size() const {
      return this->m_graph.size();
    }
    const ::std::vector<::std::size_t>& idx2dfs() const {
      return this->m_idx2dfs;
    }
    const ::std::vector<::std::size_t>& dfs2idx() const {
      return this->m_dfs2idx;
    }

    void add_edge(const ::std::size_t u, const ::std::size_t v) {
      assert(u < this->size());
      assert(v < this->size());
      this->m_graph[u].push_back(v);
      this->m_graph[v].push_back(u);
    }

    void build(const ::std::size_t root) {
      assert(root < this->size());

      ::std::vector<::std::size_t> subtree_size(this->size());
      ::std::fill(this->m_parent.begin(), this->m_parent.end(), ::std::numeric_limits<::std::size_t>::max());
      this->m_depth[root] = 0;
      {
        ::std::stack<::std::pair<::std::size_t, bool>> stack;
        stack.emplace(root, false);
        stack.emplace(root, true);
        while (!stack.empty()) {
          const auto [here, pre] = stack.top();
          stack.pop();
          if (pre) {
            for (const auto next : this->m_graph[here]) {
              if (next != this->m_parent[here]) {
                this->m_parent[next] = here;
                this->m_depth[next] = this->m_depth[here] + 1;
                stack.emplace(next, false);
                stack.emplace(next, true);
              }
            }
          } else {
            subtree_size[here] = 1;
            for (const auto child : this->m_graph[here]) {
              if (child != this->m_parent[here]) {
                subtree_size[here] += subtree_size[child];
              }
            }
          }
        }
      }

      for (::std::size_t v = 0; v < this->size(); ++v) {
        if (v != root) {
          ::std::iter_swap(
            ::std::prev(this->m_graph[v].end()),
            ::std::find(this->m_graph[v].begin(), this->m_graph[v].end(), this->m_parent[v])
          );
        }
        ::std::iter_swap(
          this->m_graph[v].begin(),
          ::std::max_element(
            this->m_graph[v].begin(),
            ::std::prev(this->m_graph[v].end(), v == root ? 0 : 1),
            ::tools::less_by([&](const ::std::size_t v) { return subtree_size[v]; })
          )
        );
      }

      ::std::size_t dfs_order = 0;
      this->m_dsu = ::atcoder::dsu(this->size());
      {
        ::std::stack<::std::size_t> stack;
        stack.push(root);
        while (!stack.empty()) {
          const auto here = stack.top();
          stack.pop();

          this->m_idx2dfs[here] = dfs_order;
          this->m_dfs2idx[dfs_order] = here;
          ++dfs_order;

          if (this->m_graph[here].size() > (here == root ? 0 : 1)) {
            this->m_dsu.merge(here, this->m_graph[here][0]);
          }
          for (auto it = ::std::next(this->m_graph[here].rbegin(), here == root ? 0 : 1); it != this->m_graph[here].rend(); ++it) {
            stack.push(*it);
          }
        }
      }
    }
    void build() {
      this->build(0);
    }

    ::std::vector<::std::pair<::std::size_t, ::std::size_t>> query(::std::size_t u, ::std::size_t v) {
      assert(u < this->size());
      assert(v < this->size());

      ::std::vector<::std::pair<::std::size_t, ::std::size_t>> head, tail;
      while (!this->m_dsu.same(u, v)) {
        if (this->m_depth[this->m_dsu.leader(u)] >= this->m_depth[this->m_dsu.leader(v)]) {
          head.emplace_back(this->m_idx2dfs[u] + 1, this->m_idx2dfs[this->m_dsu.leader(u)]);
          u = this->m_parent[this->m_dsu.leader(u)];
        } else {
          tail.emplace_back(this->m_idx2dfs[this->m_dsu.leader(v)], this->m_idx2dfs[v] + 1);
          v = this->m_parent[this->m_dsu.leader(v)];
        }
      }
      if (this->m_depth[u] >= this->m_depth[v]) {
        head.emplace_back(this->m_idx2dfs[u] + 1, this->m_idx2dfs[v]);
      } else {
        head.emplace_back(this->m_idx2dfs[u], this->m_idx2dfs[v] + 1);
      }

      ::std::copy(tail.rbegin(), tail.rend(), ::std::back_inserter(head));
      return head;
    }
  };
}

#endif
