#ifndef TOOLS_PDSU_HPP
#define TOOLS_PDSU_HPP

#include <vector>
#include <cassert>
#include <numeric>
#include <utility>
#include "tools/group.hpp"

namespace tools {
  template <typename G = ::tools::group::plus<long long>>
  class pdsu {
  private:
    using T = typename G::T;
    ::std::vector<int> m_parents;
    ::std::vector<int> m_sizes;
    ::std::vector<T> m_diffs;

  public:
    pdsu(const int n) :
      m_parents(n),
      m_sizes(n, 1),
      m_diffs(n, 0) {
      assert(n >= 0);
      ::std::iota(this->m_parents.begin(), this->m_parents.end(), 0);
    }

    int size() const {
      return this->m_parents.size();
    }

    int leader(const int x) {
      assert(0 <= x && x < this->size());
      if (this->m_parents[x] == x) {
        return x;
      }
      const auto r = this->leader(this->m_parents[x]);
      this->m_diffs[x] = G::op(this->m_diffs[x], this->m_diffs[this->m_parents[x]]);
      return this->m_parents[x] = r;
    }

  private:
    T potential(const int x) {
      assert(0 <= x && x < this->size());
      this->leader(x);
      return this->m_diffs[x];
    }

  public:
    T diff(const int x, const int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());
      assert(this->same(x, y));
      return G::op(this->potential(y), G::inv(this->potential(x)));
    }

    bool same(const int x, const int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());
      return this->leader(x) == this->leader(y);
    }

    int merge(int x, int y, T w) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());
      assert(!this->same(x, y));

      w = G::op(G::op(w, this->potential(x)), G::inv(this->potential(y)));
      x = this->leader(x);
      y = this->leader(y);
      if (x == y) return x;

      if (this->m_sizes[x] < this->m_sizes[y]) {
        ::std::swap(x, y);
        w = G::inv(w);
      }
      this->m_parents[y] = x;
      this->m_sizes[x] += this->m_sizes[y];

      this->m_diffs[y] = w;
      return x;
    }

    int size(const int x) {
      assert(0 <= x && x < this->size());
      return this->m_sizes[this->leader(x)];
    }

    ::std::vector<::std::vector<int>> groups() {
      ::std::vector<int> group_indices(this->size(), -1);
      int next_group_index = 0;
      for (int i = 0; i < this->size(); ++i) {
        if (group_indices[this->leader(i)] == -1) {
          group_indices[this->leader(i)] = next_group_index;
          ++next_group_index;
        }
      }

      ::std::vector<::std::vector<int>> groups(next_group_index);
      for (int i = 0; i < this->size(); ++i) {
        groups[group_indices[this->leader(i)]].push_back(i);
      }

      return groups;
    }
  };
}

#endif
