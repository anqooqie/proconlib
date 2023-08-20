#ifndef TOOLS_CEIL_HPP
#define TOOLS_CEIL_HPP

#include <type_traits>
#include <cassert>

namespace tools {

  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> ceil(const M lhs, const N rhs) {
    using T = ::std::common_type_t<M, N>;
    assert(rhs != N(0));
    return lhs / rhs + T(((lhs > M(0) && rhs > N(0)) || (lhs < M(0) && rhs < N(0))) && lhs % rhs);
  }
}

#endif
