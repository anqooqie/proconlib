#ifndef TOOLS_PARTIALLY_PERSISTENT_DSU_HPP
#define TOOLS_PARTIALLY_PERSISTENT_DSU_HPP

#include <vector>
#include <utility>
#include <limits>
#include <cassert>
#include <algorithm>
#include <queue>
#include "tools/less_by_first.hpp"

namespace tools {
  class partially_persistent_dsu {
  private:
    int m_now;
    ::std::vector<::std::pair<int, int>> m_parents;
    ::std::vector<int> m_ranks;
    ::std::vector<::std::vector<::std::pair<int, int>>> m_sizes;

    int size() const {
      return this->m_parents.size();
    }

  public:
    partially_persistent_dsu() = default;
    partially_persistent_dsu(const ::tools::partially_persistent_dsu&) = default;
    partially_persistent_dsu(::tools::partially_persistent_dsu&&) = default;
    ~partially_persistent_dsu() = default;
    ::tools::partially_persistent_dsu& operator=(const ::tools::partially_persistent_dsu&) = default;
    ::tools::partially_persistent_dsu& operator=(::tools::partially_persistent_dsu&&) = default;

    explicit partially_persistent_dsu(const int n) :
      m_now(0),
      m_parents(n, ::std::make_pair(::std::numeric_limits<int>::max(), -1)),
      m_ranks(n, 0),
      m_sizes(n, ::std::vector<::std::pair<int, int>>{::std::make_pair(0, 1)}) {
    }

    int now() const {
      return this->m_now;
    }

    int leader(const int t, const int x) const {
      assert(0 <= t && t <= this->m_now);
      assert(0 <= x && x < this->size());

      return t < this->m_parents[x].first ? x : this->leader(t, this->m_parents[x].second);
    }

    bool same(const int t, const int x, const int y) const {
      assert(0 <= t && t <= this->m_now);
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      return this->leader(t, x) == this->leader(t, y);
    }

    int merge(int x, int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      ++this->m_now;

      x = this->leader(this->m_now, x);
      y = this->leader(this->m_now, y);
      if (x == y) return x;

      if (this->m_ranks[x] < this->m_ranks[y]) ::std::swap(x, y);

      this->m_parents[y] = ::std::make_pair(this->m_now, x);
      if (this->m_ranks[x] == this->m_ranks[y]) ++this->m_ranks[x];
      this->m_sizes[x].emplace_back(this->m_now, this->m_sizes[x].back().second + this->m_sizes[y].back().second);

      return x;
    }

    int size(const int t, int x) const {
      assert(0 <= t && t <= this->m_now);
      assert(0 <= x && x < this->size());

      x = this->leader(t, x);
      auto it = ::std::upper_bound(this->m_sizes[x].begin(), this->m_sizes[x].end(), ::std::make_pair(t, 0), ::tools::less_by_first());
      --it;
      return it->second;
    }

    ::std::vector<::std::vector<int>> groups(const int t) const {
      assert(0 <= t && t <= this->m_now);

      ::std::vector<::std::vector<int>> graph(this->size());
      for (int i = 0; i < this->size(); ++i) {
        if (this->m_parents[i].first <= t) graph[this->m_parents[i].second].push_back(i);
      }

      ::std::vector<::std::vector<int>> res(this->size());
      for (int root = 0; root < this->size(); ++root) {
        if (t < this->m_parents[root].first) {
          ::std::queue<int> queue({root});
          while (!queue.empty()) {
            const auto here = queue.front();
            queue.pop();
            res[root].push_back(here);
            for (const auto next : graph[here]) {
              queue.push(next);
            }
          }
        }
      }

      res.erase(::std::remove_if(res.begin(), res.end(), [](const auto& group) { return group.empty(); }), res.end());
      return res;
    }
  };
}

#endif
