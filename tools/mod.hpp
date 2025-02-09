#ifndef TOOLS_MOD_HPP
#define TOOLS_MOD_HPP

#include <cassert>
#include <type_traits>
#include "tools/is_integral.hpp"

namespace tools {

  template <typename M, typename N> requires (
    ::tools::is_integral_v<M> && !::std::is_same_v<::std::remove_cv_t<M>, bool> &&
    ::tools::is_integral_v<N> && !::std::is_same_v<::std::remove_cv_t<N>, bool>)
  constexpr ::std::common_type_t<M, N> mod(const M a, const N b) noexcept {
    assert(b != 0);

    using UM = ::std::make_unsigned_t<M>;
    using UN = ::std::make_unsigned_t<N>;
    const UM ua = a >= 0 ? a : static_cast<UM>(-(a + 1)) + 1;
    const UN ub = b >= 0 ? b : static_cast<UN>(-(b + 1)) + 1;
    auto r = ua % ub;
    if (a < 0 && r > 0) {
      r = ub - r;
    }
    return r;
  }
}

#endif
