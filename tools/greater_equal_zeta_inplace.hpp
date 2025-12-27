#ifndef TOOLS_GREATER_EQUAL_ZETA_INPLACE_HPP
#define TOOLS_GREATER_EQUAL_ZETA_INPLACE_HPP

#include <iterator>
#include <ranges>

namespace tools {
  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void greater_equal_zeta_inplace(R&& a) {
    const int N = std::ranges::distance(a);
    for (int i = N - 2; i >= 0; --i) {
      std::ranges::begin(a)[i] += std::ranges::begin(a)[i + 1];
    }
  }
}

#endif
