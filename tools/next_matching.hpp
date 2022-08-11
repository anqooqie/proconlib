#ifndef TOOLS_NEXT_MATCHING_HPP
#define TOOLS_NEXT_MATCHING_HPP

#include <iterator>
#include <cassert>
#include <algorithm>

namespace tools {
  template <typename RandomAccessIterator>
  bool next_matching(RandomAccessIterator begin, RandomAccessIterator end) {
    const auto N = ::std::distance(begin, end);
    assert(N % 2 == 0);
    // assert(::tools::mex(begin, end) == N);
    if (N == 0) return false;

    auto l = N - 2;
    for (; l > 0 && begin[l - 1] > begin[l + 1]; l -= 2);
    ::std::sort(::std::next(begin, l), end);
    if (l == 0) return false;

    ::std::iter_swap(::std::next(begin, l - 1), ::std::upper_bound(::std::next(begin, l), end, begin[l - 1]));
    return true;
  }
}

#endif
