#ifndef TOOLS_FLOOR_LOG_HPP
#define TOOLS_FLOOR_LOG_HPP

#include <type_traits>
#include <cassert>
#include "tools/floor.hpp"

namespace tools {

  template <typename M, typename N>
  std::common_type_t<M, N> floor_log(const M& base, const N& antilogarithm) {
    assert(2 <= base && base <= 1000000000000000000);
    assert(1 <= antilogarithm && antilogarithm <= 1000000000000000000);

    const std::common_type_t<M, N> threshold = tools::floor(antilogarithm, base);
    std::common_type_t<M, N> logarithm = 0;
    for (std::common_type_t<M, N> pow = 1; pow <= antilogarithm; pow = (pow <= threshold ? pow * base : antilogarithm + 1)) {
      ++logarithm;
    }

    return logarithm - 1;
  }
}

#endif
