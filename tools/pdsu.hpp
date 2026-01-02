#ifndef TOOLS_PDSU_HPP
#define TOOLS_PDSU_HPP

#include <cassert>
#include <numeric>
#include <utility>
#include <vector>
#include "tools/groups.hpp"

namespace tools {
  enum class pdsu_diff {
    known,
    unknown,
    inconsistent
  };

  template <typename G = tools::groups::plus<long long>>
  class pdsu {
    using T = typename G::T;

    std::vector<int> m_parents;
    std::vector<int> m_sizes;
    std::vector<T> m_diffs;
    std::vector<bool> m_consistent;

  public:
    pdsu() = default;
    explicit pdsu(const int n) :
      m_parents(n),
      m_sizes(n, 1),
      m_diffs(n, G::e()),
      m_consistent(n, true) {
      assert(n >= 0);
      std::iota(this->m_parents.begin(), this->m_parents.end(), 0);
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
      if (this->m_consistent[r]) {
        this->m_diffs[x] = G::op(this->m_diffs[this->m_parents[x]], this->m_diffs[x]);
      }
      return this->m_parents[x] = r;
    }

    std::pair<tools::pdsu_diff, T> diff(const int x, const int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());
      const auto x_r = this->leader(x);
      const auto y_r = this->leader(y);
      if (x_r == y_r) {
        if (this->m_consistent[x_r]) {
          return std::make_pair(tools::pdsu_diff::known, G::op(G::inv(this->m_diffs[y]), this->m_diffs[x]));
        } else {
          return std::make_pair(tools::pdsu_diff::inconsistent, G::e());
        }
      } else {
        return std::make_pair(tools::pdsu_diff::unknown, G::e());
      }
    }

    bool same(const int x, const int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());
      return this->leader(x) == this->leader(y);
    }

    int merge(int x, int y, T w) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      auto x_r = this->leader(x);
      auto y_r = this->leader(y);

      if (x_r == y_r) {
        this->m_consistent[x_r] = (this->m_consistent[x_r] && this->m_diffs[x] == G::op(this->m_diffs[y], w));
        return x_r;
      }

      if (this->m_sizes[x_r] < this->m_sizes[y_r]) {
        std::swap(x, y);
        w = G::inv(w);
        std::swap(x_r, y_r);
      }
      this->m_parents[y_r] = x_r;
      this->m_sizes[x_r] += this->m_sizes[y_r];
      this->m_consistent[x_r] = this->m_consistent[x_r] && this->m_consistent[y_r];
      if (this->m_consistent[x_r]) {
        this->m_diffs[y_r] = G::op(G::op(this->m_diffs[x], G::inv(w)), G::inv(this->m_diffs[y]));
      }
      return x_r;
    }

    int size(const int x) {
      assert(0 <= x && x < this->size());
      return this->m_sizes[this->leader(x)];
    }

    std::vector<std::vector<int>> groups() {
      std::vector<int> group_indices(this->size(), -1);
      int next_group_index = 0;
      for (int i = 0; i < this->size(); ++i) {
        if (group_indices[this->leader(i)] == -1) {
          group_indices[this->leader(i)] = next_group_index;
          ++next_group_index;
        }
      }

      std::vector<std::vector<int>> groups(next_group_index);
      for (int i = 0; i < this->size(); ++i) {
        groups[group_indices[this->leader(i)]].push_back(i);
      }

      return groups;
    }
  };
}

#endif
