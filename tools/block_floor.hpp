#ifndef TOOLS_BLOCK_FLOOR_HPP
#define TOOLS_BLOCK_FLOOR_HPP

#include <cassert>
#include <type_traits>
#include "tools/floor.hpp"

namespace tools {
  template <typename M, typename N>
  constexpr std::common_type_t<M, N> block_floor(const M x, const N y) noexcept {
    assert(y > 0);
    return tools::floor(x, y) * y;
  }
}

#endif
