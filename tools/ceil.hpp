#ifndef TOOLS_CEIL_HPP
#define TOOLS_CEIL_HPP

#include <cassert>
#include <type_traits>
#include "tools/non_bool_integral.hpp"
#include "tools/is_unsigned.hpp"

namespace tools {
  template <tools::non_bool_integral M, tools::non_bool_integral N>
  constexpr std::common_type_t<M, N> ceil(const M x, const N y) noexcept {
    assert(y != 0);
    if (y >= 0) {
      if (x > 0) {
        return (x - 1) / y + 1;
      } else {
        if constexpr (tools::is_unsigned_v<std::common_type_t<M, N>>) {
          return 0;
        } else {
          return x / y;
        }
      }
    } else {
      if (x >= 0) {
        if constexpr (tools::is_unsigned_v<std::common_type_t<M, N>>) {
          return 0;
        } else {
          return x / y;
        }
      } else {
        return (x + 1) / y + 1;
      }
    }
  }
}

#endif
