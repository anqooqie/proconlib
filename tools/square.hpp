#ifndef TOOLS_SQUARE_HPP
#define TOOLS_SQUARE_HPP

#include "tools/monoid.hpp"

namespace tools {

  template <typename M>
  typename M::T square(const typename M::T& x) {
    return M::op(x, x);
  }

  template <typename T>
  T square(const T& x) {
    return ::tools::square<::tools::monoid::multiplies<T>>(x);
  }
}

#endif
