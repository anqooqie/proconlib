#ifndef TOOLS_IS_IN_GRID_HPP
#define TOOLS_IS_IN_GRID_HPP

#include <cassert>
#include <utility>

namespace tools {
  template <typename T1, typename T2, typename T3, typename T4>
  constexpr bool is_in_grid(const T1 r, const T2 c, const T3 h, const T4 w) noexcept {
    assert(::std::cmp_greater_equal(h, 0));
    assert(::std::cmp_greater_equal(w, 0));
    return ::std::cmp_less_equal(0, r) && ::std::cmp_less(r, h) && ::std::cmp_less_equal(0, c) && ::std::cmp_less(c, w);
  }
}

#endif
