#ifndef TOOLS_MAX_MATCHING_HPP
#define TOOLS_MAX_MATCHING_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

// Source: https://github.com/ei1333/library/blob/a80478c7a06ac56632643fc80192130297d90c67/graph/flow/gabow-edmonds.hpp
// License: Unlicense
// Author: ei1333

namespace tools {
  class max_matching {
  public:
    struct edge {
      int from;
      int to;
    };

  private:
    struct internal_edge {
      int to;
      int idx;
    };

    ::std::vector<::std::vector<internal_edge>> m_g;
    ::std::vector<edge> m_edges;
    ::std::vector<int> m_mate;
    ::std::vector<int> m_label;
    ::std::vector<int> m_first;
    ::std::queue<int> m_que;

  public:
    max_matching() = default;
    explicit max_matching(const int n) : m_g(n + 1), m_mate(n + 1), m_label(n + 1, -1), m_first(n + 1) {
    }

    int size() const {
      return this->m_g.size() - 1;
    }

    int add_edge(int u, int v) {
      assert(0 <= u && u < this->size());
      assert(0 <= v && v < this->size());
      ::std::tie(u, v) = ::std::minmax({u, v});
      this->m_g[u + 1].push_back({v + 1, static_cast<int>(this->m_edges.size() + this->m_g.size())});
      this->m_g[v + 1].push_back({u + 1, static_cast<int>(this->m_edges.size() + this->m_g.size())});
      this->m_edges.push_back({u, v});
      return this->m_edges.size() - 1;
    }

    const edge& get_edge(const int k) const & {
      assert(0 <= k && k < ::std::ssize(this->m_edges));
      return this->m_edges[k];
    }
    edge get_edge(const int k) && {
      assert(0 <= k && k < ::std::ssize(this->m_edges));
      return ::std::move(this->m_edges[k]);
    }

    const ::std::vector<edge>& edges() const & {
      return this->m_edges;
    }
    ::std::vector<edge> edges() && {
      return ::std::move(this->m_edges);
    }

  private:
    int find(const int x) {
      if (this->m_label[this->m_first[x]] < 0) return this->m_first[x];
      this->m_first[x] = this->find(this->m_first[x]);
      return this->m_first[x];
    }

    void rematch(const int v, const int w) {
      const int t = this->m_mate[v];
      this->m_mate[v] = w;
      if (this->m_mate[t] != v) return;
      if (this->m_label[v] < ::std::ssize(this->m_g)) {
        this->m_mate[t] = this->m_label[v];
        this->rematch(this->m_label[v], t);
      } else {
        const int x = this->m_edges[this->m_label[v] - this->m_g.size()].from + 1;
        const int y = this->m_edges[this->m_label[v] - this->m_g.size()].to + 1;
        this->rematch(x, y);
        this->rematch(y, x);
      }
    }

    void assign_label(const int x, const int y, const int num) {
      int r = this->find(x);
      int s = this->find(y);
      int join = 0;
      if (r == s) return;
      this->m_label[r] = -num;
      this->m_label[s] = -num;
      while (true) {
        if (s != 0) ::std::swap(r, s);
        r = this->find(this->m_label[this->m_mate[r]]);
        if (this->m_label[r] == -num) {
          join = r;
          break;
        }
        this->m_label[r] = -num;
      }
      int v = this->m_first[x];
      while (v != join) {
        this->m_que.push(v);
        this->m_label[v] = num;
        this->m_first[v] = join;
        v = this->m_first[this->m_label[this->m_mate[v]]];
      }
      v = this->m_first[y];
      while (v != join) {
        this->m_que.push(v);
        this->m_label[v] = num;
        this->m_first[v] = join;
        v = this->m_first[this->m_label[this->m_mate[v]]];
      }
    }

    bool augment_check(const int u) {
      this->m_que = ::std::queue<int>{};
      this->m_first[u] = 0;
      this->m_label[u] = 0;
      this->m_que.push(u);
      while (!this->m_que.empty()) {
        int x = this->m_que.front();
        this->m_que.pop();
        for (auto e : this->m_g[x]) {
          int y = e.to;
          if (this->m_mate[y] == 0 && y != u) {
            this->m_mate[y] = x;
            this->rematch(x, y);
            return true;
          } else if (this->m_label[y] >= 0) {
            this->assign_label(x, y, e.idx);
          } else if (this->m_label[this->m_mate[y]] < 0) {
            this->m_label[this->m_mate[y]] = x;
            this->m_first[this->m_mate[y]] = y;
            this->m_que.push(this->m_mate[y]);
          }
        }
      }
      return false;
    }

  public:
    ::std::vector<::std::pair<int, int>> query() {
      for (int i = 1; i < ::std::ssize(this->m_g); ++i) {
        if (this->m_mate[i] != 0) continue;
        if (this->augment_check(i)) this->m_label.assign(this->m_g.size(), -1);
      }
      ::std::vector<::std::pair<int, int>> ret;
      for (int i = 1; i < ::std::ssize(this->m_g); ++i) {
        if (i < this->m_mate[i]) ret.emplace_back(i - 1, this->m_mate[i] - 1);
      }
      return ret;
    }
  };
}

#endif
