#ifndef TOOLS_PLUS_CLAMP_HPP
#define TOOLS_PLUS_CLAMP_HPP

#include <limits>
#include <algorithm>

namespace tools {

  template <typename T>
  constexpr T plus_clamp(const T& lhs, const T& rhs, const T& min = ::std::numeric_limits<T>::min(), const T& max = ::std::numeric_limits<T>::max()) {
    T result;
    if (rhs > 0 && lhs > ::std::numeric_limits<T>::max() - rhs) {
      result = ::std::numeric_limits<T>::max();
    } else if (rhs < 0 && lhs < ::std::numeric_limits<T>::min() - rhs) {
      result = ::std::numeric_limits<T>::min();
    } else {
      result = lhs + rhs;
    }
    return ::std::clamp(result, min, max);
  }
}

#endif
