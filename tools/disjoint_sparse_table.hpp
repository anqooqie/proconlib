#ifndef TOOLS_DISJOINT_SPARSE_TABLE_HPP
#define TOOLS_DISJOINT_SPARSE_TABLE_HPP

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
  class disjoint_sparse_table {
  private:
    using T = typename M::T;
    ::std::vector<T> m_value;
    ::std::size_t m_size;
    ::std::size_t m_capacity;
    ::std::size_t m_height;

  public:
    disjoint_sparse_table() = default;
    disjoint_sparse_table(const ::tools::disjoint_sparse_table<M>&) = default;
    disjoint_sparse_table(::tools::disjoint_sparse_table<M>&&) = default;
    ~disjoint_sparse_table() = default;
    ::tools::disjoint_sparse_table<M>& operator=(const ::tools::disjoint_sparse_table<M>&) = default;
    ::tools::disjoint_sparse_table<M>& operator=(::tools::disjoint_sparse_table<M>&&) = default;

    template <typename InputIterator>
    disjoint_sparse_table(const InputIterator& begin, const InputIterator& end) {
      ::std::copy(begin, end, ::std::back_inserter(this->m_value));
      this->m_size = this->m_value.size();
      this->m_height = this->m_size <= 1 ? this->m_size : ::tools::ceil_log2(this->m_size);
      this->m_capacity = this->m_size <= 1 ? this->m_size : ::tools::pow2(this->m_height);
      this->m_value.resize(this->m_height * this->m_capacity);
      ::std::fill(this->m_value.begin() + this->m_size, this->m_value.begin() + this->m_capacity, M::e());

      for (::std::size_t d = 1; d < this->m_height; ++d) {
        const ::std::size_t offset = d * this->m_capacity;
        for (::std::size_t m = ::tools::pow2(d); m < this->m_capacity; m += ::tools::pow2(d + 1)) {
          this->m_value[offset + (m - 1)] = this->m_value[m - 1];
          this->m_value[offset + m] = this->m_value[m];
          for (::std::size_t l = m - 1; l --> m - ::tools::pow2(d);) {
            this->m_value[offset + l] = M::op(this->m_value[l], this->m_value[offset + (l + 1)]);
          }
          for (::std::size_t r = m + 2; r <= m + ::tools::pow2(d); ++r) {
            this->m_value[offset + (r - 1)] = M::op(this->m_value[offset + (r - 2)], this->m_value[r - 1]);
          }
        }
      }
    }

    ::std::size_t size() const {
      return this->m_size;
    }

    T prod(const ::std::size_t l, const ::std::size_t r) const {
      assert(l <= r && r <= this->m_size);
      if (r - l == 0) {
        return M::e();
      } else if (r - l == 1) {
        return this->m_value[l];
      } else {
        const ::std::size_t offset = ::tools::floor_log2(l ^ (r - 1)) * this->m_capacity;
        return M::op(this->m_value[offset + l], this->m_value[offset + (r - 1)]);
      }
    }
  };
}

#endif
