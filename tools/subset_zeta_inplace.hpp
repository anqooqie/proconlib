#ifndef TOOLS_SUBSET_ZETA_INPLACE_HPP
#define TOOLS_SUBSET_ZETA_INPLACE_HPP

#include <cassert>
#include <iterator>
#include <ranges>
#include <utility>
#include "tools/commutative_monoid.hpp"
#include "tools/groups.hpp"
#include "tools/has_single_bit.hpp"
#include "tools/pow2.hpp"

namespace tools {
  template <tools::commutative_monoid M, std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void subset_zeta_inplace(R&& a) {
    const int N = std::ranges::distance(a);
    assert(tools::has_single_bit(N));

    for (int w = 0; tools::pow2(w) < N; ++w) {
      for (int i = 0; i < N; i += tools::pow2(w)) {
        for (; !((i >> w) & 1); ++i) {
          std::ranges::begin(a)[i + tools::pow2(w)] = M::op(std::ranges::begin(a)[i + tools::pow2(w)], std::ranges::begin(a)[i]);
        }
      }
    }
  }

  template <std::ranges::random_access_range R>
  requires std::ranges::output_range<R, std::ranges::range_value_t<R>>
  void subset_zeta_inplace(R&& a) {
    tools::subset_zeta_inplace<tools::groups::plus<std::ranges::range_value_t<R>>>(std::forward<R>(a));
  }
}

#endif
