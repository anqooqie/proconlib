#ifndef TOOLS_SMALL_RANGE_LOWER_BOUND_HPP
#define TOOLS_SMALL_RANGE_LOWER_BOUND_HPP

#include <vector>
#include <type_traits>
#include <iterator>
#include <cstddef>
#include <limits>
#include <algorithm>
#include <numeric>

namespace tools {
  template <typename T>
  class small_range_lower_bound {
    T m_min;
    ::std::vector<int> m_res;

    template <typename ForwardIterator, ::std::enable_if_t<::std::is_base_of_v<::std::forward_iterator_tag, typename ::std::iterator_traits<ForwardIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    void init(const ForwardIterator begin, const ForwardIterator end) {
      if (begin == end) {
        this->m_min = ::std::numeric_limits<T>::max();
        this->m_res.assign({0});
      } else {
        const auto [minit, maxit] = ::std::minmax_element(begin, end);
        this->m_min = *minit;
        this->m_res.assign(*maxit - *minit + 2, 0);
        for (auto it = begin; it != end; ++it) {
          ++this->m_res[*it - *minit + 1];
        }
        ::std::partial_sum(this->m_res.begin(), this->m_res.end(), this->m_res.begin());
      }
    }

  public:
    small_range_lower_bound() = default;
    template <typename ForwardIterator, ::std::enable_if_t<::std::is_base_of_v<::std::forward_iterator_tag, typename ::std::iterator_traits<ForwardIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
    small_range_lower_bound(const ForwardIterator begin, const ForwardIterator end) {
      this->init(begin, end);
    }
    template <typename InputIterator, ::std::enable_if_t<!::std::is_base_of_v<::std::forward_iterator_tag, typename ::std::iterator_traits<InputIterator>::iterator_category>, ::std::nullptr_t> = nullptr>
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
