#ifndef TOOLS_FLOOR_HPP
#define TOOLS_FLOOR_HPP

#include <cassert>
#include <type_traits>
#include "tools/non_bool_integral.hpp"

namespace tools {

  template <::tools::non_bool_integral M, ::tools::non_bool_integral N>
  constexpr ::std::common_type_t<M, N> floor(const M x, const N y) noexcept {
    assert(y != 0);
    if (y >= 0) {
      if (x >= 0) {
        return x / y;
      } else {
        return (x + 1) / y - 1;
      }
    } else {
      if (x > 0) {
        return (x - 1) / y - 1;
      } else {
        return x / y;
      }
    }
  }
}

#endif
