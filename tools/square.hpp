#ifndef TOOLS_SQUARE_HPP
#define TOOLS_SQUARE_HPP

#include "tools/monoid.hpp"

namespace tools {

  template <::tools::monoid M>
  typename M::T square(const typename M::T& x) {
    return M::op(x, x);
  }

  template <typename T>
  requires (!::tools::monoid<T>)
  T square(const T& x) {
    return x * x;
  }
}

#endif
