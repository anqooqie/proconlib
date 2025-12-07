#ifndef TOOLS_ROUND_HPP
#define TOOLS_ROUND_HPP

#include <cstdlib>
#include "tools/ceil.hpp"
#include "tools/floor.hpp"
#include "tools/mod.hpp"

namespace tools {

  template <typename T>
  constexpr T round(const T lhs, const T rhs) {
    return std::abs(rhs) % 2 == 0
      ? tools::mod(lhs, rhs) == std::abs(rhs) / 2
        ? tools::floor(lhs, rhs) % 2 == 0
          ? tools::floor(lhs, rhs)
          : tools::ceil(lhs, rhs)
        : tools::mod(lhs, rhs) < std::abs(rhs) / 2
          ? tools::floor(lhs, rhs)
          : tools::ceil(lhs, rhs)
      : tools::mod(lhs, rhs) <= std::abs(rhs) / 2
        ? tools::floor(lhs, rhs)
        : tools::ceil(lhs, rhs);
  }
}

#endif
