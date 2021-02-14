#ifndef TOOLS_SAFE_SUM_HPP
#define TOOLS_SAFE_SUM_HPP

#include <limits>
#include <stdexcept>

namespace tools {

  /**
   * computes $A + B$ but handles `std::numeric_limits<T>::max()` as $\infty$ and `std::numeric_limits<T>::min()` as $-\infty$
   * License: CC0
   * @author anqooqie
   * @param <T> an underlying set of the sum operation
   * @param lhs left hand side operand
   * @param rhs right hand side operand
   * @return $\mathrm{lhs} + \mathrm{rhs}$ when we regard `std::numeric_limits<T>::max()` as $\infty$ and `std::numeric_limits<T>::min()` as $-\infty$
   * @throws std::runtime_error if $\mathrm{lhs} + \mathrm{rhs}$ is indefinite.
   */
  template <typename T>
  T safe_sum(const T& lhs, const T& rhs) {
    if (lhs == ::std::numeric_limits<T>::min() && rhs == ::std::numeric_limits<T>::max()) throw std::runtime_error("Indefinite.");
    if (lhs == ::std::numeric_limits<T>::max() && rhs == ::std::numeric_limits<T>::min()) throw std::runtime_error("Indefinite.");
    if (lhs == ::std::numeric_limits<T>::min() || rhs == ::std::numeric_limits<T>::min()) return ::std::numeric_limits<T>::min();
    if (lhs == ::std::numeric_limits<T>::max() || rhs == ::std::numeric_limits<T>::max()) return ::std::numeric_limits<T>::max();
    return lhs + rhs;
  }
}

#endif
