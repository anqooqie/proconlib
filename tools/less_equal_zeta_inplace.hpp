#ifndef TOOLS_LESS_EQUAL_ZETA_INPLACE_HPP
#define TOOLS_LESS_EQUAL_ZETA_INPLACE_HPP

#include <iterator>
#include <ranges>

namespace tools {
  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void less_equal_zeta_inplace(R&& a) {
    const int N = std::ranges::distance(a);
    for (int i = 1; i < N; ++i) {
      std::ranges::begin(a)[i] += std::ranges::begin(a)[i - 1];
    }
  }
}

#endif
