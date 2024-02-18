#ifndef TOOLS_DISJOINT_SPARSE_TABLE_2D_HPP
#define TOOLS_DISJOINT_SPARSE_TABLE_2D_HPP

#include <vector>
#include <cstddef>
#include <algorithm>
#include <iterator>
#include <cassert>
#include "tools/ceil_log2.hpp"
#include "tools/pow2.hpp"
#include "tools/floor_log2.hpp"

namespace tools {
  template <typename M>
  class disjoint_sparse_table_2d {
  private:
    using T = typename M::T;
    ::std::vector<::std::vector<T>> m_value;
    ::std::size_t m_height;
    ::std::size_t m_width;
    ::std::size_t m_hcapacity;
    ::std::size_t m_wcapacity;

  public:
    disjoint_sparse_table_2d() = default;
    disjoint_sparse_table_2d(const ::tools::disjoint_sparse_table_2d<M>&) = default;
    disjoint_sparse_table_2d(::tools::disjoint_sparse_table_2d<M>&&) = default;
    ~disjoint_sparse_table_2d() = default;
    ::tools::disjoint_sparse_table_2d<M>& operator=(const ::tools::disjoint_sparse_table_2d<M>&) = default;
    ::tools::disjoint_sparse_table_2d<M>& operator=(::tools::disjoint_sparse_table_2d<M>&&) = default;

    template <typename Range>
    explicit disjoint_sparse_table_2d(const Range& range) {
      const auto begin = ::std::begin(range);
      const auto end = ::std::end(range);
      this->m_height = ::std::distance(begin, end);
      this->m_width = this->m_height == 0 ? 0 : ::std::distance(::std::begin(*begin), ::std::end(*begin));
      assert(::std::all_of(begin, end, [&](const auto& row) { return static_cast<::std::size_t>(::std::distance(::std::begin(row), ::std::end(row))) == this->m_width; }));

      const auto hdepth = this->m_height <= 1 ? this->m_height : ::tools::ceil_log2(this->m_height);
      const auto wdepth = this->m_width <= 1 ? this->m_width : ::tools::ceil_log2(this->m_width);
      this->m_hcapacity = this->m_height <= 1 ? this->m_height : ::tools::pow2(hdepth);
      this->m_wcapacity = this->m_width <= 1 ? this->m_width : ::tools::pow2(wdepth);

      const auto construct_horizontal_dst = [&](::std::vector<T>& row) {
        row.resize(wdepth * this->m_wcapacity);
        ::std::fill(row.begin() + this->m_width, row.begin() + this->m_wcapacity, M::e());

        for (::std::size_t d = 1; d < wdepth; ++d) {
          const ::std::size_t offset = d * this->m_wcapacity;
          for (::std::size_t m = ::tools::pow2(d); m < this->m_wcapacity; m += ::tools::pow2(d + 1)) {
            row[offset + (m - 1)] = row[m - 1];
            row[offset + m] = row[m];
            for (::std::size_t l = m - 1; l --> m - ::tools::pow2(d);) {
              row[offset + l] = M::op(row[l], row[offset + (l + 1)]);
            }
            for (::std::size_t r = m + 2; r <= m + ::tools::pow2(d); ++r) {
              row[offset + (r - 1)] = M::op(row[offset + (r - 2)], row[r - 1]);
            }
          }
        }
      };

      this->m_value.resize(hdepth * this->m_hcapacity);
      for (auto& row : this->m_value) {
        row.reserve(wdepth * this->m_wcapacity);
      }
      for (::std::size_t h = 0; h < this->m_height; ++h) {
        ::std::copy(::std::begin(begin[h]), ::std::end(begin[h]), ::std::back_inserter(this->m_value[h]));
        construct_horizontal_dst(this->m_value[h]);
      }
      for (::std::size_t h = this->m_height; h < this->m_hcapacity; ++h) {
        this->m_value[h].resize(wdepth * this->m_wcapacity, M::e());
      }

      for (::std::size_t d = 1; d < hdepth; ++d) {
        const ::std::size_t offset = d * this->m_hcapacity;
        for (::std::size_t m = ::tools::pow2(d); m < this->m_hcapacity; m += ::tools::pow2(d + 1)) {
          ::std::copy(this->m_value[m - 1].begin(), this->m_value[m - 1].end(), ::std::back_inserter(this->m_value[offset + (m - 1)]));
          ::std::copy(this->m_value[m].begin(), this->m_value[m].end(), ::std::back_inserter(this->m_value[offset + m]));
          for (::std::size_t l = m - 1; l --> m - ::tools::pow2(d);) {
            for (::std::size_t w = 0; w < wdepth * this->m_wcapacity; ++w) {
              this->m_value[offset + l].push_back(M::op(this->m_value[l][w], this->m_value[offset + (l + 1)][w]));
            }
          }
          for (::std::size_t r = m + 2; r <= m + ::tools::pow2(d); ++r) {
            for (::std::size_t w = 0; w < wdepth * this->m_wcapacity; ++w) {
              this->m_value[offset + (r - 1)].push_back(M::op(this->m_value[offset + (r - 2)][w], this->m_value[r - 1][w]));
            }
          }
        }
      }
    }

    ::std::size_t height() const {
      return this->m_height;
    }
    ::std::size_t width() const {
      return this->m_width;
    }

    T prod(const ::std::size_t d, const ::std::size_t u, const ::std::size_t l, const ::std::size_t r) const {
      assert(d <= u && u <= this->m_height);
      assert(l <= r && r <= this->m_width);
      if (u - d == 0 || r - l == 0) {
        return M::e();
      } else if (u - d == 1 && r - l == 1) {
        return this->m_value[d][l];
      } else if (u - d == 1) {
        const ::std::size_t woffset = ::tools::floor_log2(l ^ (r - 1)) * this->m_wcapacity;
        return M::op(this->m_value[d][woffset + l], this->m_value[d][woffset + (r - 1)]);
      } else if (r - l == 1) {
        const ::std::size_t hoffset = ::tools::floor_log2(d ^ (u - 1)) * this->m_hcapacity;
        return M::op(this->m_value[hoffset + d][l], this->m_value[hoffset + (u - 1)][l]);
      } else {
        const ::std::size_t hoffset = ::tools::floor_log2(d ^ (u - 1)) * this->m_hcapacity;
        const ::std::size_t woffset = ::tools::floor_log2(l ^ (r - 1)) * this->m_wcapacity;
        return M::op(
          M::op(this->m_value[hoffset + d][woffset + l], this->m_value[hoffset + d][woffset + (r - 1)]),
          M::op(this->m_value[hoffset + (u - 1)][woffset + l], this->m_value[hoffset + (u - 1)][woffset + (r - 1)])
        );
      }
    }
  };
}

#endif
