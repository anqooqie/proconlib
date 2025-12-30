#ifndef TOOLS_SUPERSET_MOEBIUS_INPLACE_HPP
#define TOOLS_SUPERSET_MOEBIUS_INPLACE_HPP

#include <cassert>
#include <iterator>
#include <ranges>
#include <utility>
#include "tools/commutative_group.hpp"
#include "tools/groups.hpp"
#include "tools/has_single_bit.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <tools::commutative_group G, std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void superset_moebius_inplace(R&& b) {
    const int N = std::ranges::distance(b);
    assert(tools::has_single_bit(N));

    for (int w = 0; tools::pow2(w) < N; ++w) {
      for (int i = 0; i < N; i += tools::pow2(w)) {
        for (; !((i >> w) & 1); ++i) {
          std::ranges::begin(b)[i] = G::op(std::ranges::begin(b)[i], G::inv(std::ranges::begin(b)[i + tools::pow2(w)]));
        }
      }
    }
  }

  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void superset_moebius_inplace(R&& b) {
    tools::superset_moebius_inplace<tools::groups::plus<std::ranges::range_value_t<R>>>(std::forward<R>(b));
  }
}

#endif
