#ifndef TOOLS_BLOCK_CEIL_HPP
#define TOOLS_BLOCK_CEIL_HPP

#include <cassert>
#include <type_traits>
#include "tools/ceil.hpp"

namespace tools {
  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> block_ceil(const M x, const N y) noexcept {
    assert(y > 0);
    return ::tools::ceil(x, y) * y;
  }
}

#endif
