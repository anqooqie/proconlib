#ifndef TOOLS_COMPRESS_HPP
#define TOOLS_COMPRESS_HPP

#include <algorithm>
#include <ranges>
#include <vector>
#include "tools/lower_bound.hpp"

namespace tools {
  template <::std::ranges::range R, typename OutputIterator>
  void compress(R&& a, OutputIterator result) {
    using T = typename ::std::ranges::range_value_t<R>;
    if constexpr (::std::ranges::forward_range<R>) {
      ::std::vector<T> sorted(::std::ranges::begin(a), ::std::ranges::end(a));
      ::std::ranges::sort(sorted);
      sorted.erase(::std::unique(sorted.begin(), sorted.end()), sorted.end());
      for (auto it = ::std::ranges::begin(a); it != ::std::ranges::end(a); ++it, ++result) {
        *result = ::tools::lower_bound(sorted.begin(), sorted.end(), *it);
      }
    } else {
      ::tools::compress(::std::vector<T>(::std::ranges::begin(a), ::std::ranges::end(a)), result);
    }
  }
}

#endif
