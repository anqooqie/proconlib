#ifndef TOOLS_DISJOINT_SPARSE_TABLE_2D_HPP
#define TOOLS_DISJOINT_SPARSE_TABLE_2D_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <iterator>
#include <ranges>
#include <vector>
#include "tools/ceil_log2.hpp"
#include "tools/commutative_monoid.hpp"
#include "tools/pow2.hpp"
#include "tools/floor_log2.hpp"

namespace tools {
  template <tools::commutative_monoid M>
  class disjoint_sparse_table_2d {
    using T = typename M::T;
    std::vector<std::vector<T>> m_value;
    int m_height;
    int m_width;
    int m_hcapacity;
    int m_wcapacity;

  public:
    disjoint_sparse_table_2d() = default;

    template <std::ranges::input_range R>
    requires std::ranges::input_range<std::ranges::range_reference_t<R>>
          && std::assignable_from<T&, std::ranges::range_value_t<std::ranges::range_reference_t<R>>>
    explicit disjoint_sparse_table_2d(R&& range) {
      for (auto&& row : std::forward<R>(range)) {
        this->m_value.push_back(std::forward<decltype(row)>(row) | std::ranges::to<std::vector<T>>());
      }
      this->m_height = this->m_value.size();
      this->m_width = this->m_height == 0 ? 0 : this->m_value[0].size();
      assert(std::ranges::all_of(this->m_value, [&](const auto& row) { return std::ssize(row) == this->m_width; }));

      const auto hdepth = this->m_height <= 1 ? this->m_height : tools::ceil_log2(this->m_height);
      const auto wdepth = this->m_width <= 1 ? this->m_width : tools::ceil_log2(this->m_width);
      this->m_hcapacity = this->m_height <= 1 ? this->m_height : tools::pow2(hdepth);
      this->m_wcapacity = this->m_width <= 1 ? this->m_width : tools::pow2(wdepth);

      const auto construct_horizontal_dst = [&](std::vector<T>& row) {
        row.resize(wdepth * this->m_wcapacity);
        std::fill(row.begin() + this->m_width, row.begin() + this->m_wcapacity, M::e());

        for (int d = 1; d < wdepth; ++d) {
          const int offset = d * this->m_wcapacity;
          for (int m = tools::pow2(d); m < this->m_wcapacity; m += tools::pow2(d + 1)) {
            row[offset + (m - 1)] = row[m - 1];
            row[offset + m] = row[m];
            for (int l = m - 1; l --> m - tools::pow2(d);) {
              row[offset + l] = M::op(row[l], row[offset + (l + 1)]);
            }
            for (int r = m + 2; r <= m + tools::pow2(d); ++r) {
              row[offset + (r - 1)] = M::op(row[offset + (r - 2)], row[r - 1]);
            }
          }
        }
      };

      this->m_value.resize(hdepth * this->m_hcapacity);
      for (auto& row : this->m_value) {
        row.reserve(wdepth * this->m_wcapacity);
      }
      for (int h = 0; h < this->m_height; ++h) {
        construct_horizontal_dst(this->m_value[h]);
      }
      for (int h = this->m_height; h < this->m_hcapacity; ++h) {
        this->m_value[h].resize(wdepth * this->m_wcapacity, M::e());
      }

      for (int d = 1; d < hdepth; ++d) {
        const int offset = d * this->m_hcapacity;
        for (int m = tools::pow2(d); m < this->m_hcapacity; m += tools::pow2(d + 1)) {
          std::ranges::copy(this->m_value[m - 1], std::back_inserter(this->m_value[offset + (m - 1)]));
          std::ranges::copy(this->m_value[m], std::back_inserter(this->m_value[offset + m]));
          for (int l = m - 1; l --> m - tools::pow2(d);) {
            for (int w = 0; w < wdepth * this->m_wcapacity; ++w) {
              this->m_value[offset + l].push_back(M::op(this->m_value[l][w], this->m_value[offset + (l + 1)][w]));
            }
          }
          for (int r = m + 2; r <= m + tools::pow2(d); ++r) {
            for (int w = 0; w < wdepth * this->m_wcapacity; ++w) {
              this->m_value[offset + (r - 1)].push_back(M::op(this->m_value[offset + (r - 2)][w], this->m_value[r - 1][w]));
            }
          }
        }
      }
    }

    int height() const {
      return this->m_height;
    }
    int width() const {
      return this->m_width;
    }

    T prod(const  int d, const int u, const int l, const int r) const {
      assert(0 <= d && d <= u && u <= this->m_height);
      assert(0 <= l && l <= r && r <= this->m_width);
      if (u - d == 0 || r - l == 0) {
        return M::e();
      } else if (u - d == 1 && r - l == 1) {
        return this->m_value[d][l];
      } else if (u - d == 1) {
        const int woffset = tools::floor_log2(l ^ (r - 1)) * this->m_wcapacity;
        return M::op(this->m_value[d][woffset + l], this->m_value[d][woffset + (r - 1)]);
      } else if (r - l == 1) {
        const int hoffset = tools::floor_log2(d ^ (u - 1)) * this->m_hcapacity;
        return M::op(this->m_value[hoffset + d][l], this->m_value[hoffset + (u - 1)][l]);
      } else {
        const int hoffset = tools::floor_log2(d ^ (u - 1)) * this->m_hcapacity;
        const int woffset = tools::floor_log2(l ^ (r - 1)) * this->m_wcapacity;
        return M::op(
          M::op(this->m_value[hoffset + d][woffset + l], this->m_value[hoffset + d][woffset + (r - 1)]),
          M::op(this->m_value[hoffset + (u - 1)][woffset + l], this->m_value[hoffset + (u - 1)][woffset + (r - 1)])
        );
      }
    }
  };
}

#endif
