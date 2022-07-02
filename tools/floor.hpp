#ifndef TOOLS_FLOOR_HPP
#define TOOLS_FLOOR_HPP

#include <type_traits>
#include <cassert>

namespace tools {

  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> floor(const M lhs, const N rhs) {
    assert(rhs != 0);
    return lhs / rhs - (((lhs > 0 && rhs < 0) || (lhs < 0 && rhs > 0)) && lhs % rhs);
  }
}

#endif
