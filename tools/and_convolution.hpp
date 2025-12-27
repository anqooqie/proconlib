#ifndef TOOLS_AND_CONVOLUTION_HPP
#define TOOLS_AND_CONVOLUTION_HPP

#include <cassert>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>
#include "tools/has_single_bit.hpp"
#include "tools/superset_moebius_inplace.hpp"
#include "tools/superset_zeta_inplace.hpp"

namespace tools {
  template <std::ranges::input_range R1, std::ranges::input_range R2>
  std::vector<std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>> and_convolution(R1&& a_orig, R2&& b_orig) {
    using T = std::common_type_t<std::ranges::range_value_t<R1>, std::ranges::range_value_t<R2>>;
    auto a = std::forward<R1>(a_orig) | std::ranges::to<std::vector<T>>();
    auto b = std::forward<R2>(b_orig) | std::ranges::to<std::vector<T>>();
    const int N = a.size();
    assert(b.size() == N);
    assert(tools::has_single_bit(N));

    tools::superset_zeta_inplace(a);
    tools::superset_zeta_inplace(b);

    std::vector<T> c(N);
    for (int i = 0; i < N; ++i) {
      c[i] = a[i] * b[i];
    }
    tools::superset_moebius_inplace(c);
    return c;
  }
}

#endif
