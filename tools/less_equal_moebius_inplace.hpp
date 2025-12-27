#ifndef TOOLS_LESS_EQUAL_MOEBIUS_INPLACE_HPP
#define TOOLS_LESS_EQUAL_MOEBIUS_INPLACE_HPP

#include <iterator>
#include <ranges>

namespace tools {
  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void less_equal_moebius_inplace(R&& b) {
    const int N = std::ranges::distance(b);
    for (int i = N - 1; i - 1 >= 0; --i) {
      std::ranges::begin(b)[i] -= std::ranges::begin(b)[i - 1];
    }
  }
}

#endif
