#ifndef TOOLS_RANGE_PARALLEL_DSU_HPP
#define TOOLS_RANGE_PARALLEL_DSU_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>
#include "atcoder/segtree.hpp"
#include "tools/getter_result.hpp"
#include "tools/modint_for_rolling_hash.hpp"
#include "tools/now.hpp"
#include "tools/pow_mod_cache.hpp"

namespace tools {
  class range_parallel_dsu {
    using mint = tools::modint_for_rolling_hash;
    struct monoid {
      inline static auto pow_b = tools::pow_mod_cache<mint>(tools::now());
      using T = std::pair<int, mint>;
      static T op(const T& x, const T& y) {
        return {x.first + y.first, x.second * pow_b[y.first] + y.second};
      }
      static T e() {
        return {0, mint::raw(0)};
      }
    };

    atcoder::segtree<typename monoid::T, monoid::op, monoid::e> m_seg;
    std::vector<std::vector<int>> m_groups;
    int m_ncc;

  public:
    range_parallel_dsu() = default;
    explicit range_parallel_dsu(const int n) :
      m_seg(std::views::iota(0, n) | std::views::transform([](const auto i) { return std::make_pair(1, mint::raw(i + 1)); }) | std::ranges::to<std::vector>()),
      m_groups(std::views::iota(0, n) | std::views::transform([](const auto i) { return std::vector<int>{i}; }) | std::ranges::to<std::vector>()),
      m_ncc(n) {
    }

    int leader(const int x) const {
      assert(0 <= x && x < this->size());

      return this->m_seg.get(x).second.val() - 1;
    }

    bool same(const int x, const int y) const {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      return this->leader(x) == this->leader(y);
    }

    int merge(int x, int y) {
      assert(0 <= x && x < this->size());
      assert(0 <= y && y < this->size());

      x = this->leader(x);
      y = this->leader(y);
      if (x == y) return x;

      if (this->m_groups[x].size() < this->m_groups[y].size()) std::swap(x, y);
      std::ranges::copy(this->m_groups[y], std::back_inserter(this->m_groups[x]));
      for (const auto v : this->m_groups[y]) {
        this->m_seg.set(v, {1, mint::raw(x + 1)});
      }
      this->m_groups[y].clear();

      --this->m_ncc;

      return x;
    }

    std::vector<std::pair<int, int>> merge(int x, int y, const int k) {
      assert(k >= 0);
      assert(0 <= x && x + k <= this->size());
      assert(0 <= y && y + k <= this->size());

      std::vector<std::pair<int, int>> res;
      int ok = 0;
      int ng = k + 1;
      do {
        while (ng - ok > 1) {
          const auto mid = (ok + ng) / 2;
          if (this->m_seg.prod(x, x + mid).second == this->m_seg.prod(y, y + mid).second) {
            ok = mid;
          } else {
            ng = mid;
          }
        }
        if (ok < k) {
          const auto leader_xor = this->leader(x + ok) ^ this->leader(y + ok);
          const auto new_leader = this->merge(x + ok, y + ok);
          res.emplace_back(new_leader, leader_xor ^ new_leader);
          ++ok;
          ng = k + 1;
        }
      } while (ok < k);

      this->m_ncc -= res.size();

      return res;
    }

    int size() const {
      return this->m_groups.size();
    }

    int size(const int x) const {
      assert(0 <= x && x < this->size());

      return this->m_groups[this->leader(x)].size();
    }

    std::vector<std::vector<int>> groups() const {
      std::vector<std::vector<int>> res(this->size());
      for (int i = 0; i < this->size(); ++i) {
        res[this->leader(i)].push_back(i);
      }
      res.erase(std::remove_if(res.begin(), res.end(), [](const auto& group) { return group.empty(); }), res.end());
      return res;
    }

    int ncc() const {
      return this->m_ncc;
    }

    auto group(this auto&& self, const int x) -> tools::getter_result_t<decltype(self), std::vector<int>> {
      assert(0 <= x && x < self.size());

      return std::forward_like<decltype(self)>(self.m_groups[self.leader(x)]);
    }
  };
}

#endif
