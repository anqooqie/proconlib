#ifndef TOOLS_RANGE_PARALLEL_DSU_HPP
#define TOOLS_RANGE_PARALLEL_DSU_HPP

#include <cassert>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>
#include "tools/bit_width.hpp"
#include "tools/dsu.hpp"
#include "tools/floor_log2.hpp"
#include "tools/pow2.hpp"

namespace tools {
  class range_parallel_dsu {
    std::vector<tools::dsu> m_dsus;

  public:
    range_parallel_dsu() = default;
    explicit range_parallel_dsu(const int n) : m_dsus(tools::bit_width(n)) {
      for (int h = 0; h < std::ssize(this->m_dsus); ++h) {
        this->m_dsus[h] = tools::dsu(n + 1 - tools::pow2(h));
      }
    }

    int leader(const int a) {
      assert(0 <= a && a < this->size());

      return this->m_dsus[0].leader(a);
    }

    bool same(const int a, const int b) {
      assert(0 <= a && a < this->size());
      assert(0 <= b && b < this->size());

      return this->m_dsus[0].same(a, b);
    }

    int merge(const int a, const int b) {
      assert(0 <= a && a < this->size());
      assert(0 <= b && b < this->size());

      return this->m_dsus[0].merge(a, b);
    }

    std::vector<std::pair<int, int>> merge(const int a, const int b, const int k) {
      assert(k >= 0);
      assert(0 <= a && a + k <= this->size());
      assert(0 <= b && b + k <= this->size());

      std::vector<std::pair<int, int>> res;
      if (k == 0) return res;

      const auto log2_k = tools::floor_log2(k);
      std::queue<std::pair<int, int>> queue;
      queue.emplace(a, log2_k);
      if (tools::pow2(log2_k) < k) {
        queue.emplace(a + k - tools::pow2(log2_k), log2_k);
      }

      while (!queue.empty()) {
        const auto [x, h] = queue.front();
        const auto y = b + (x - a);
        queue.pop();
        if (!this->m_dsus[h].same(x, y)) {
          if (h > 0) {
            queue.emplace(x, h - 1);
            queue.emplace(x + tools::pow2(h - 1), h - 1);
            this->m_dsus[h].merge(x, y);
          } else {
            const auto u = this->m_dsus[0].leader(x);
            const auto v = this->m_dsus[0].leader(y);
            const auto w = this->m_dsus[0].merge(u, v);
            res.emplace_back(w, u ^ v ^ w);
          }
        }
      }

      return res;
    }

    int size() const {
      return this->m_dsus.empty() ? 0 : this->m_dsus[0].size();
    }

    int size(const int a) {
      assert(0 <= a && a < this->size());

      return this->m_dsus[0].size(a);
    }

    std::vector<std::vector<int>> groups() {
      return this->m_dsus.empty() ? std::vector<std::vector<int>>{} : this->m_dsus[0].groups();
    }

    int ncc() const {
      return this->m_dsus.empty() ? 0 : this->m_dsus[0].ncc();
    }
  };
}

#endif
