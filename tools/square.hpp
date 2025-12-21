#ifndef TOOLS_SQUARE_HPP
#define TOOLS_SQUARE_HPP

#include "tools/monoid.hpp"

namespace tools {

  template <tools::monoid M>
  constexpr typename M::T square(const typename M::T& x) noexcept(noexcept(M::op(x, x))) {
    return M::op(x, x);
  }

  template <typename T>
  requires (!tools::monoid<T>)
  constexpr T square(const T& x) noexcept(noexcept(x * x)) {
    return x * x;
  }
}

#endif
