#ifndef TOOLS_MIDPOINT_HPP
#define TOOLS_MIDPOINT_HPP

#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  constexpr T midpoint(const T a, const T b) noexcept {
    using U = tools::make_unsigned_t<T>;
    if (a < b) {
      return a + T((U(b) - U(a)) / U(2));
    } else {
      return a - T((U(a) - U(b)) / U(2));
    }
  }
}

#endif
