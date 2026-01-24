#ifndef TOOLS_MOD_HPP
#define TOOLS_MOD_HPP

#include <cassert>
#include "tools/make_unsigned.hpp"
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral M, tools::non_bool_integral N>
  constexpr std::common_type_t<M, N> mod(const M a, const N b) noexcept {
    assert(b != 0);

    using UM = tools::make_unsigned_t<M>;
    using UN = tools::make_unsigned_t<N>;
    const UM ua = a >= 0 ? a : static_cast<UM>(-(a + 1)) + 1;
    const UN ub = b >= 0 ? b : static_cast<UN>(-(b + 1)) + 1;
    auto r = ua % ub;
    if (a < 0 && r > 0) {
      r = ub - r;
    }
    return r;
  }
}

#endif
