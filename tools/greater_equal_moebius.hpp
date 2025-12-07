#ifndef TOOLS_GREATER_EQUAL_MOEBIUS_HPP
#define TOOLS_GREATER_EQUAL_MOEBIUS_HPP

#include <iterator>
#include <vector>
#include <algorithm>

namespace tools {
  template <typename RandomAccessIterator>
  void greater_equal_moebius(const RandomAccessIterator begin, const RandomAccessIterator end) {
    const int N = end - begin;
    for (int i = 0; i + 1 < N; ++i) {
      begin[i] -= begin[i + 1];
    }
  }

  template <typename InputIterator, typename OutputIterator>
  void greater_equal_moebius(const InputIterator begin, const InputIterator end, const OutputIterator result) {
    using T = typename std::iterator_traits<InputIterator>::value_type;
    std::vector<T> b(begin, end);
    tools::greater_equal_moebius(b.begin(), b.end());
    std::move(b.begin(), b.end(), result);
  }
}

#endif
