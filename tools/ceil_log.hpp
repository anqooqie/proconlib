#ifndef TOOLS_CEIL_LOG_HPP
#define TOOLS_CEIL_LOG_HPP

#include <type_traits>
#include <cassert>
#include "tools/ceil.hpp"

namespace tools {

  /**
   * ceil of logarithm
   * License: CC0
   * @author anqooqie
   * @param <M> type of base
   * @param <N> type of antilogarithm
   * @param base $b$
   * @param antilogarithm $x$
   * @return $\left\lceil \log_b(x) \right\rceil$
   */
  template <typename M, typename N>
  ::std::common_type_t<M, N> ceil_log(const M& base, const N& antilogarithm) {
    assert(base > 1);
    assert(antilogarithm > 0);

    const ::std::common_type_t<M, N> threshold = tools::ceil(antilogarithm, base);
    ::std::common_type_t<M, N> logarithm = 0;
    for (::std::common_type_t<M, N> pow = 1; pow < antilogarithm; pow = (pow < threshold ? pow * base : antilogarithm)) {
      ++logarithm;
    }

    return logarithm;
  }
}

#endif
