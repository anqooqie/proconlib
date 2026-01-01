#ifndef TOOLS_CMP_LESS_EQUAL_HPP
#define TOOLS_CMP_LESS_EQUAL_HPP

#include "tools/cmp_less.hpp"
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral T, tools::integral U>
  constexpr bool cmp_less_equal(const T t, const U u) noexcept {
    return !tools::cmp_less(u, t);
  }
}

#endif
