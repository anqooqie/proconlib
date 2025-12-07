#ifndef TOOLS_HLD_HPP
#define TOOLS_HLD_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>
#include <numeric>
#include <ranges>
#include <stack>
#include <utility>
#include <vector>
#include "atcoder/dsu.hpp"
#include "tools/less_by.hpp"
#include "tools/pow2.hpp"

namespace tools {
  class hld {
    bool m_built;
    std::vector<std::vector<int>> m_graph;
    std::vector<int> m_edges;
    std::vector<int> m_parent;
    std::vector<int> m_depth;
    atcoder::dsu m_dsu;
    std::vector<int> m_out;
    std::vector<int> m_vid2dfs;
    std::vector<int> m_dfs2vid;
    std::vector<int> m_eid2dfs;
    std::vector<int> m_dfs2eid;
    std::vector<std::vector<int>> m_ancestors;

  public:
    class vchildren_view : public std::ranges::view_interface<vchildren_view> {
      tools::hld const *m_parent;
      int m_v;

    public:
      class iterator {
      private:
        tools::hld const *m_parent;
        int m_v;
        int m_i;

      public:
        using difference_type = std::ptrdiff_t;
        using value_type = int;
        using reference = int;
        using pointer = int*;
        using iterator_category = std::input_iterator_tag;

        iterator() = default;
        iterator(tools::hld const * const parent, const int v, const int i) :
          m_parent(parent),
          m_v(v),
          m_i(i) {
        }

        reference operator*() const {
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

      vchildren_view() = default;
      vchildren_view(tools::hld const * const parent, const int v) :
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
    explicit hld(const int n) : m_built(false), m_graph(n) {
      assert(n >= 1);
    }

    int size() const {
      return this->m_graph.size();
    }

    void add_edge(const int u, const int v) {
      assert(!this->m_built);
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      this->m_graph[u].push_back(this->m_edges.size());
      this->m_graph[v].push_back(this->m_edges.size());
      this->m_edges.push_back(u ^ v);
    }

    void build(const int root) {
      assert(!this->m_built);
      assert(0 <= root && root < this->size());
      assert(std::ssize(this->m_edges) + 1 == this->size());

      this->m_parent.resize(this->size());
      this->m_depth.resize(this->size());
      this->m_dsu = atcoder::dsu(this->size());
      this->m_out.resize(this->size());
      this->m_vid2dfs.resize(this->size());
      this->m_dfs2vid.resize(this->size());
      this->m_eid2dfs.resize(this->m_edges.size());
      this->m_dfs2eid.resize(this->m_edges.size());

      std::vector<int> subtree_size(this->size());
      this->m_parent[root] = std::numeric_limits<int>::max();
      this->m_depth[root] = 0;
      std::stack<std::pair<int, bool>> stack;
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

      for (int v = 0; v < this->size(); ++v) {
        if (v != root) {
          this->m_graph[v].erase(std::ranges::find(this->m_graph[v], this->m_parent[v]));
        }
        if (this->m_graph[v].size() > 1) {
          std::iter_swap(
            this->m_graph[v].begin(),
            std::ranges::max_element(
              this->m_graph[v],
              tools::less_by([&](const int eid) { return subtree_size[this->m_edges[eid] ^ v]; })
            )
          );
        }
      }

      int dfs_order = 0;
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

    int depth(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      return this->m_depth[v];
    }
    int vparent(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      assert(this->m_depth[v] > 0);
      return this->m_edges[this->m_parent[v]] ^ v;
    }
    int eparent(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      assert(this->m_depth[v] > 0);
      return this->m_parent[v];
    }
    int vancestor(const int v, const int k) {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      assert(0 <= k && k <= this->m_depth[v]);

      if (this->m_ancestors.empty()) {
        this->m_ancestors.resize(this->size());
        std::vector<int> targets(this->size());
        std::iota(targets.begin(), targets.end(), 0);
        targets.erase(std::remove(targets.begin(), targets.end(), this->m_dfs2vid[0]), targets.end());
        for (const auto t : targets) {
          this->m_ancestors[t].push_back(this->vparent(t));
        }
        for (int g = 1; [&]() {
          targets.erase(std::remove_if(targets.begin(), targets.end(), [&](const int t) {
            return this->m_depth[t] < tools::pow2(g);
          }), targets.end());
          return !targets.empty();
        }(); ++g) {
          for (const auto t : targets) {
            this->m_ancestors[t].push_back(this->m_ancestors[this->m_ancestors[t][g - 1]][g - 1]);
          }
        }
      }

      int res = v;
      for (int g = 0; tools::pow2(g) <= k; ++g) {
        if ((k >> g) & 1) {
          res = this->m_ancestors[res][g];
        }
      }

      return res;
    }
    tools::hld::vchildren_view vchildren(const int v) const & {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      return tools::hld::vchildren_view(this, v);
    }
    const std::vector<int>& echildren(const int v) const & {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      return this->m_graph[v];
    }

    int vid2dfs(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      return this->m_vid2dfs[v];
    }
    int dfs2vid(const int i) const {
      assert(this->m_built);
      assert(0 <= i && i < this->size());
      return this->m_dfs2vid[i];
    }
    int eid2dfs(const int e) const {
      assert(this->m_built);
      assert(0 <= e && e < this->size());
      return this->m_eid2dfs[e];
    }
    int dfs2eid(const int i) const {
      assert(this->m_built);
      assert(0 <= i && i < this->size());
      return this->m_dfs2eid[i];
    }

    int lca(int u, int v) {
      assert(this->m_built);
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());

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

    std::pair<int, int> vsubtree(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      return std::make_pair(this->m_vid2dfs[v], this->m_out[v]);
    }
    std::pair<int, int> esubtree(const int v) const {
      assert(this->m_built);
      assert(0 <= v && v < this->size());
      return std::make_pair(this->m_depth[v] == 0 ? 0 : this->m_eid2dfs[this->m_parent[v]] + 1, this->m_out[v] - 1);
    }

    std::vector<std::pair<int, int>> vpath(int u, int v) {
      assert(this->m_built);
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());

      std::vector<std::pair<int, int>> head, tail;
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

      std::copy(tail.rbegin(), tail.rend(), std::back_inserter(head));
      return head;
    }
    std::vector<std::pair<int, int>> epath(int u, int v) {
      assert(this->m_built);
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());

      std::vector<std::pair<int, int>> head, tail;
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

      std::copy(tail.rbegin(), tail.rend(), std::back_inserter(head));
      return head;
    }
  };
}

#endif
