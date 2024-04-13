#ifndef TOOLS_SQUARE_HPP
#define TOOLS_SQUARE_HPP

#include <type_traits>
#include "tools/is_monoid.hpp"

namespace tools {

  template <typename M>
  ::std::enable_if_t<::tools::is_monoid_v<M>, typename M::T> square(const typename M::T& x) {
    return M::op(x, x);
  }

  template <typename T>
  ::std::enable_if_t<!::tools::is_monoid_v<T>, T> square(const T& x) {
    return x * x;
  }
}

#endif
