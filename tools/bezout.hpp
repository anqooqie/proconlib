#ifndef TOOLS_BEZOUT_HPP
#define TOOLS_BEZOUT_HPP

#include <optional>
#include <tuple>
#include "tools/extgcd.hpp"

namespace tools {
  template <typename T>
  std::optional<std::tuple<T, T, T, T>> bezout(const T a, const T b, const T c) {
    assert(a != T(0));
    assert(b != T(0));
    const auto [x0, y0, gcd] = tools::extgcd(a, b);
    return c % gcd == T(0) ? std::make_optional(std::make_tuple(-b / gcd, c / gcd * x0, a / gcd, c / gcd * y0)) : std::nullopt;
  }
}

#endif
