#ifndef TOOLS_POW_H
#define TOOLS_POW_H

#include <cstddef>
#include "tools/monoid.hpp"
#include "tools/square.hpp"

namespace tools {

  template <typename M>
  typename M::T pow(const typename M::T& base, const ::std::size_t& exponent) {
    return exponent == 0
      ? M::e()
      : exponent % 2 == 0
        ? ::tools::square<M>(::tools::pow<M>(base, exponent / 2))
        : M::op(::tools::pow<M>(base, exponent - 1), base);
  }

  template <typename T>
  T pow(const T& base, const ::std::size_t& exponent) {
    return ::tools::pow<::tools::monoid::multiplies<T>>(base, exponent);
  }
}

#endif
