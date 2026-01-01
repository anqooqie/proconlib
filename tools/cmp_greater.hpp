#ifndef TOOLS_CMP_GREATER_HPP
#define TOOLS_CMP_GREATER_HPP

#include "tools/cmp_less.hpp"
#include "tools/integral.hpp"

namespace tools {
  template <tools::integral T, tools::integral U>
  constexpr bool cmp_greater(const T t, const U u) noexcept {
    return tools::cmp_less(u, t);
  }
}

#endif
