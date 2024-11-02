#ifndef TOOLS_IS_IN_GRID_HPP
#define TOOLS_IS_IN_GRID_HPP

#include <cassert>
#include "tools/cmp_greater_equal.hpp"
#include "tools/cmp_less_equal.hpp"
#include "tools/cmp_less.hpp"

namespace tools {
  template <typename T1, typename T2, typename T3, typename T4>
  constexpr bool is_in_grid(const T1 r, const T2 c, const T3 h, const T4 w) noexcept {
    assert(::tools::cmp_greater_equal(h, 0));
    assert(::tools::cmp_greater_equal(w, 0));
    return ::tools::cmp_less_equal(0, r) && ::tools::cmp_less(r, h) && ::tools::cmp_less_equal(0, c) && ::tools::cmp_less(c, w);
  }
}

#endif
