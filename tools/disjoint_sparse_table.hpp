#ifndef TOOLS_DISJOINT_SPARSE_TABLE_HPP
#define TOOLS_DISJOINT_SPARSE_TABLE_HPP

#include <algorithm>
#include <cassert>
#include <iterator>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/ceil_log2.hpp"
#include "tools/floor_log2.hpp"
#include "tools/monoid.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <tools::monoid M>
  class disjoint_sparse_table {
    using T = typename M::T;
    std::vector<T> m_value;
    int m_size;
    int m_capacity;
    int m_height;

  public:
    disjoint_sparse_table() = default;
    template <std::ranges::input_range R>
    disjoint_sparse_table(R&& a) : m_value(std::forward<R>(a) | std::ranges::to<std::vector<T>>()) {
      this->m_size = this->m_value.size();
      this->m_height = this->m_size <= 1 ? this->m_size : tools::ceil_log2(this->m_size);
      this->m_capacity = this->m_size <= 1 ? this->m_size : tools::pow2(this->m_height);
      this->m_value.resize(this->m_height * this->m_capacity);
      std::fill(this->m_value.begin() + this->m_size, this->m_value.begin() + this->m_capacity, M::e());

      for (int d = 1; d < this->m_height; ++d) {
        const auto offset = d * this->m_capacity;
        for (int m = tools::pow2(d); m < this->m_capacity; m += tools::pow2(d + 1)) {
          this->m_value[offset + (m - 1)] = this->m_value[m - 1];
          this->m_value[offset + m] = this->m_value[m];
          for (int l = m - 1; l --> m - tools::pow2(d);) {
            this->m_value[offset + l] = M::op(this->m_value[l], this->m_value[offset + (l + 1)]);
          }
          for (int r = m + 2; r <= m + tools::pow2(d); ++r) {
            this->m_value[offset + (r - 1)] = M::op(this->m_value[offset + (r - 2)], this->m_value[r - 1]);
          }
        }
      }
    }
    template <std::input_iterator F, std::sentinel_for<F> S>
    disjoint_sparse_table(const F first, const S last) : disjoint_sparse_table(std::ranges::subrange(first, last)) {
    }

    int size() const {
      return this->m_size;
    }

    T prod(const int l, const int r) const {
      assert(0 <= l && l <= r && r <= this->m_size);
      if (r - l == 0) {
        return M::e();
      } else if (r - l == 1) {
        return this->m_value[l];
      } else {
        const auto offset = tools::floor_log2(l ^ (r - 1)) * this->m_capacity;
        return M::op(this->m_value[offset + l], this->m_value[offset + (r - 1)]);
      }
    }
  };
}

#endif
