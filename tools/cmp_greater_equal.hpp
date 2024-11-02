#ifndef TOOLS_CMP_GREATER_EQUAL_HPP
#define TOOLS_CMP_GREATER_EQUAL_HPP

#include "tools/cmp_less.hpp"

namespace tools {
  template <typename T, typename U>
  constexpr bool cmp_greater_equal(const T t, const U u) noexcept {
    return !::tools::cmp_less(t, u);
  }
}

#endif
