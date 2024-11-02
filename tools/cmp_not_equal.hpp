#ifndef TOOLS_CMP_NOT_EQUAL_HPP
#define TOOLS_CMP_NOT_EQUAL_HPP

#include "tools/cmp_equal.hpp"

namespace tools {
  template <typename T, typename U>
  constexpr bool cmp_not_equal(const T t, const U u) noexcept {
    return !::tools::cmp_equal(t, u);
  }
}

#endif
