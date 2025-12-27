#ifndef TOOLS_SUPERSET_MOEBIUS_INPLACE_HPP
#define TOOLS_SUPERSET_MOEBIUS_INPLACE_HPP

#include <cassert>
#include <iterator>
#include <ranges>
#include "tools/has_single_bit.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void superset_moebius_inplace(R&& b) {
    const int N = std::ranges::distance(b);
    assert(tools::has_single_bit(N));

    for (int w = 0; tools::pow2(w) < N; ++w) {
      for (int i = 0; i < N; i += tools::pow2(w)) {
        for (; !((i >> w) & 1); ++i) {
          std::ranges::begin(b)[i] -= std::ranges::begin(b)[i + tools::pow2(w)];
        }
      }
    }
  }
}

#endif
