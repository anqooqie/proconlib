#ifndef TOOLS_FLOOR_HPP
#define TOOLS_FLOOR_HPP

#include <cassert>
#include <type_traits>
#include "tools/is_integral.hpp"

namespace tools {

  template <typename M, typename N> requires (
    ::tools::is_integral_v<M> && !::std::is_same_v<::std::remove_cv_t<M>, bool> &&
    ::tools::is_integral_v<N> && !::std::is_same_v<::std::remove_cv_t<N>, bool>)
  constexpr ::std::common_type_t<M, N> floor(const M x, const N y) noexcept {
    assert(y != 0);
    if (y >= 0) {
      if (x >= 0) {
        return x / y;
      } else {
        return (x + 1) / y - 1;
      }
    } else {
      if (x > 0) {
        return (x - 1) / y - 1;
      } else {
        return x / y;
      }
    }
  }
}

#endif
