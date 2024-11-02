#ifndef TOOLS_GREATER_EQUAL_ZETA_HPP
#define TOOLS_GREATER_EQUAL_ZETA_HPP

#include <iterator>
#include <vector>
#include <algorithm>

namespace tools {
  template <typename RandomAccessIterator>
  void greater_equal_zeta(const RandomAccessIterator begin, const RandomAccessIterator end) {
    const int N = end - begin;
    for (int i = N - 2; i >= 0; --i) {
      begin[i] += begin[i + 1];
    }
  }

  template <typename InputIterator, typename OutputIterator>
  void greater_equal_zeta(const InputIterator begin, const InputIterator end, const OutputIterator result) {
    using T = typename ::std::iterator_traits<InputIterator>::value_type;
    ::std::vector<T> a(begin, end);
    ::tools::greater_equal_zeta(a.begin(), a.end());
    ::std::move(a.begin(), a.end(), result);
  }
}

#endif
