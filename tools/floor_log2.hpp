#ifndef TOOLS_FLOOR_LOG2_HPP
#define TOOLS_FLOOR_LOG2_HPP

#include <cassert>
#include "tools/bit_width.hpp"

namespace tools {
  template <typename T>
  constexpr T floor_log2(T x) noexcept {
    assert(x > 0);
    return tools::bit_width(x) - 1;
  }
}

#endif
