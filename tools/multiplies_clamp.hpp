#ifndef TOOLS_MULTIPLIES_CLAMP_HPP
#define TOOLS_MULTIPLIES_CLAMP_HPP

#include <limits>
#include <algorithm>

namespace tools {

  template <typename T>
  constexpr T multiplies_clamp(const T& lhs, const T& rhs, const T& min = ::std::numeric_limits<T>::min(), const T& max = ::std::numeric_limits<T>::max()) {
    return std::clamp([&]() {
      if (lhs > 0) {
        if (rhs > 0) {
          if (lhs > ::std::numeric_limits<T>::max() / rhs) {
            return ::std::numeric_limits<T>::max();
          }
        } else {
          if (rhs < ::std::numeric_limits<T>::min() / lhs) {
            return ::std::numeric_limits<T>::min();
          }
        }
      } else {
        if (rhs > 0) {
          if (lhs < ::std::numeric_limits<T>::min() / rhs) {
            return ::std::numeric_limits<T>::min();
          }
        } else {
          if (lhs != 0 && rhs < ::std::numeric_limits<T>::max() / lhs) {
            return ::std::numeric_limits<T>::max();
          }
        }
      }
      return lhs * rhs;
    }(), min, max);
  }
}

#endif
