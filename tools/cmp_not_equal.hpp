#ifndef TOOLS_CMP_NOT_EQUAL_HPP
#define TOOLS_CMP_NOT_EQUAL_HPP

#include "tools/cmp_equal.hpp"
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral T, tools::integral U>
  constexpr bool cmp_not_equal(const T t, const U u) noexcept {
    return !tools::cmp_equal(t, u);
  }
}

#endif
