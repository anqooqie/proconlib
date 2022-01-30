#ifndef TOOLS_ABS_HPP
#define TOOLS_ABS_HPP

#include <cmath>

namespace tools {

  template <typename T>
  auto abs(const T& v) -> decltype(::std::abs(v)) {
    return ::std::abs(v);
  }

  template <typename T>
  auto abs(const T& v) -> decltype(v.abs()) {
    return v.abs();
  }
}

#endif
