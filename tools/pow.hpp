#ifndef TOOLS_POW_H
#define TOOLS_POW_H

#include <type_traits>
#include <cassert>
#include <cmath>
#include "tools/monoids.hpp"
#include "tools/square.hpp"

namespace tools {

  template <typename M, typename E>
  std::enable_if_t<std::is_integral_v<E>, typename M::T> pow(const typename M::T& base, const E exponent) {
    assert(exponent >= 0);
    return exponent == 0
      ? M::e()
      : exponent % 2 == 0
        ? tools::square<M>(tools::pow<M>(base, exponent / 2))
        : M::op(tools::pow<M>(base, exponent - 1), base);
  }

  template <typename T, typename E>
  std::enable_if_t<std::is_integral_v<E>, T> pow(const T& base, const E exponent) {
    assert(exponent >= 0);
    return tools::pow<tools::monoids::multiplies<T>>(base, exponent);
  }

  template <typename T, typename E>
  auto pow(const T base, const E exponent) -> std::enable_if_t<!std::is_integral_v<E>, decltype(std::pow(base, exponent))> {
    return std::pow(base, exponent);
  }
}

#endif
