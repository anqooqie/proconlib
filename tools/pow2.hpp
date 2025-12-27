#ifndef TOOLS_POW2_HPP
#define TOOLS_POW2_HPP

#include <cassert>
#include <limits>
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral T>
  constexpr T pow2(const T x) noexcept {
    assert(0 <= x && x < std::numeric_limits<T>::digits);
    return T(1) << x;
  }
}

#endif
