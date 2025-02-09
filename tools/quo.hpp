#ifndef TOOLS_QUO_H
#define TOOLS_QUO_H

#include <cassert>
#include <type_traits>
#include "tools/is_integral.hpp"

namespace tools {

  template <typename M, typename N> requires (
    ::tools::is_integral_v<M> && !::std::is_same_v<::std::remove_cv_t<M>, bool> &&
    ::tools::is_integral_v<N> && !::std::is_same_v<::std::remove_cv_t<N>, bool>)
  constexpr ::std::common_type_t<M, N> quo(const M a, const N b) noexcept {
    assert(b != 0);

    if (a >= 0) {
      return a / b;
    } else {
      if (b >= 0) {
        return (a + 1) / b - 1;
      } else {
        return (a + 1) / b + 1;
      }
    }
  }
}

#endif
