#ifndef TOOLS_SMALL_RANGE_LOWER_BOUND_HPP
#define TOOLS_SMALL_RANGE_LOWER_BOUND_HPP

#include <vector>
#include <type_traits>
#include <iterator>
#include <cstddef>
#include <cassert>
#include <algorithm>
#include <limits>
#include <iterator>
#include <vector>
#include "tools/cmp_less_equal.hpp"

namespace tools {
  template <typename T>
  class small_range_lower_bound {
    T m_min;
    ::std::vector<int> m_res;

    template <typename RandomAccessIterator, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag, typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    void init(const RandomAccessIterator begin, const RandomAccessIterator end) {
      assert(::std::is_sorted(begin, end));
      const int N = end - begin;
      if (begin == end) {
        this->m_min = ::std::numeric_limits<T>::max();
        this->m_res.resize(1);
      } else {
        this->m_min = *begin;
        this->m_res.resize(*::std::prev(end) - *begin + 2);
        for (int l = 0, r = 0, d = 0; l < N; d = begin[l] - *begin + 1, l = r) {
          for (; r < N && begin[l] == begin[r]; ++r);
          for (int x = d; ::tools::cmp_less_equal(x, begin[l] - *begin); ++x) {
            this->m_res[x] = l;
          }
        }
      }
      this->m_res.back() = N;
    }

  public:
    small_range_lower_bound() = default;
    template <typename RandomAccessIterator, ::std::enable_if_t<::std::is_base_of_v<::std::random_access_iterator_tag, typename ::std::iterator_traits<RandomAccessIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    small_range_lower_bound(const RandomAccessIterator begin, const RandomAccessIterator end) {
      this->init(begin, end);
    }
    template <typename InputIterator, ::std::enable_if_t<!::std::is_base_of_v<::std::random_access_iterator_tag, typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    small_range_lower_bound(const InputIterator begin, const InputIterator end) {
      ::std::vector<T> v(begin, end);
      this->init(v.begin(), v.end());
    }

    T query(const T x) {
      if (x < this->m_min) return 0;
      return this->m_res[::std::min<int>(x - this->m_min, this->m_res.size() - 1)];
    }
  };
}

#endif
