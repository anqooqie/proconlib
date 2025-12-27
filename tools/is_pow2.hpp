#ifndef TOOLS_IS_POW2_HPP
#define TOOLS_IS_POW2_HPP

#include <cassert>
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral T>
  constexpr bool is_pow2(const T x) noexcept {
    assert(x >= 0);
    return x > 0 && (x & (x - 1)) == 0;
  }
}

#endif
