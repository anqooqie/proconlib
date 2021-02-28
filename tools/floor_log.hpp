#ifndef TOOLS_FLOOR_LOG_HPP
#define TOOLS_FLOOR_LOG_HPP

#include <type_traits>
#include <cassert>
#include "tools/floor.hpp"

namespace tools {

  /**
   * floor of logarithm
   * License: CC0
   * @author anqooqie
   * @param <M> type of base
   * @param <N> type of antilogarithm
   * @param base $b$
   * @param antilogarithm $x$
   * @return $\left\lfloor \log_b(x) \right\rfloor$
   */
  template <typename M, typename N>
  ::std::common_type_t<M, N> floor_log(const M& base, const N& antilogarithm) {
    assert(base > 1);
    assert(antilogarithm > 0);

    const ::std::common_type_t<M, N> threshold = ::tools::floor(antilogarithm, base);
    ::std::common_type_t<M, N> logarithm = 0;
    for (::std::common_type_t<M, N> pow = 1; pow <= antilogarithm; pow = (pow <= threshold ? pow * base : antilogarithm + 1)) {
      ++logarithm;
    }

    return logarithm - 1;
  }
}

#endif
