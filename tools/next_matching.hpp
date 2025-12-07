#ifndef TOOLS_NEXT_MATCHING_HPP
#define TOOLS_NEXT_MATCHING_HPP

#include <iterator>
#include <cassert>
#include <algorithm>

namespace tools {
  template <typename RandomAccessIterator>
  bool next_matching(RandomAccessIterator begin, RandomAccessIterator end) {
    const auto N = std::distance(begin, end);
    // assert(tools::mex(begin, end) == N);
    if (N <= 2) return false;

    auto l = (N - 2) / 2 * 2;
    for (; l > 0 && begin[l - 1] > begin[l + 1]; l -= 2);
    std::sort(std::next(begin, l), std::prev(end, N % 2));

    if (l == 0) {
      if (N % 2 == 0) return false;
      if (begin[N - 1] == 0) {
        std::rotate(begin, std::prev(end), end);
        return false;
      }
      std::iter_swap(std::next(begin, begin[N - 1] - 1), std::prev(end));
      return true;
    }

    std::iter_swap(std::next(begin, l - 1), std::upper_bound(std::next(begin, l), std::prev(end, N % 2), begin[l - 1]));
    return true;
  }
}

#endif
