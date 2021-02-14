#ifndef TOOLS_SQUARE_HPP
#define TOOLS_SQUARE_HPP

#include "tools/monoid.hpp"

namespace tools {

  /**
   * calculates square
   * License: CC0
   * @author anqooqie
   * @param <M> monoid
   * @param x input
   * @return $x^2$
   */
  template <typename M>
  typename M::T square(const typename M::T& x) {
    return M::op(x, x);
  }

  /**
   * calculates square
   * License: CC0
   * @author anqooqie
   * @param <T> type of input
   * @param x input
   * @return $x^2$
   */
  template <typename T>
  T square(const T& x) {
    return ::tools::square<::tools::monoid::multiplies<T>>(x);
  }
}

#endif
