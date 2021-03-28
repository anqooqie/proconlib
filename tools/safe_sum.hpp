#ifndef TOOLS_SAFE_SUM_HPP
#define TOOLS_SAFE_SUM_HPP

#include <limits>
#include <stdexcept>

namespace tools {

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
