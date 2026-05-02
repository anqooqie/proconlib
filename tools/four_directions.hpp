#ifndef TOOLS_FOUR_DIRECTIONS_HPP
#define TOOLS_FOUR_DIRECTIONS_HPP

#include <array>
#include <utility>
#include "tools/signed_integral.hpp"

namespace tools {
  template <tools::signed_integral T>
  constexpr const std::array<std::pair<T, T>, 4>& four_directions() {
    static constexpr std::array<std::pair<T, T>, 4> directions = {{
      {T(0), T(1)},
      {T(1), T(0)},
      {T(0), T(-1)},
      {T(-1), T(0)},
    }};
    return directions;
  }
}

#endif
