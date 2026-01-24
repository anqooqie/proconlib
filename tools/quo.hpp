#ifndef TOOLS_QUO_H
#define TOOLS_QUO_H

#include <cassert>
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral M, tools::non_bool_integral N>
  constexpr std::common_type_t<M, N> quo(const M a, const N b) noexcept {
    assert(b != 0);

    if (a >= 0) {
      return a / b;
    } else {
      if (b >= 0) {
        return (a + 1) / b - 1;
      } else {
        return (a + 1) / b + 1;
      }
    }
  }
}

#endif
