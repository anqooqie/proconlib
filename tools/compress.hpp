#ifndef TOOLS_COMPRESS_HPP
#define TOOLS_COMPRESS_HPP

#include <algorithm>
#include <iterator>
#include <ranges>
#include <vector>
#include "tools/lower_bound.hpp"

namespace tools {
  template <std::ranges::range R, std::output_iterator<int> O>
  void compress(R&& a, O result) {
    using T = typename std::ranges::range_value_t<R>;
    if constexpr (std::ranges::forward_range<R>) {
      std::vector<T> sorted;
      std::ranges::copy(a, std::back_inserter(sorted));
      std::ranges::sort(sorted);
      sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
      for (auto it = std::ranges::begin(a); it != std::ranges::end(a); ++it, ++result) {
        *result = tools::lower_bound(sorted, *it);
      }
    } else {
      std::vector<T> v;
      std::ranges::copy(a, std::back_inserter(v));
      tools::compress(v, result);
    }
  }

  template <std::input_iterator I, std::sentinel_for<I> S, std::output_iterator<int> O>
  void compress(I begin, S end, O result) {
    tools::compress(std::ranges::subrange(begin, end), result);
  }

  template <std::ranges::random_access_range R>
  requires std::indirectly_writable<std::ranges::iterator_t<R>, int>
  void compress(R&& a) {
    tools::compress(a, std::ranges::begin(a));
  }

  template <std::random_access_iterator I, std::sentinel_for<I> S>
  requires std::indirectly_writable<I, int>
  void compress(I begin, S end) {
    tools::compress(begin, end, begin);
  }
}

#endif
