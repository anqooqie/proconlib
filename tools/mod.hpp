#ifndef TOOLS_MOD_HPP
#define TOOLS_MOD_HPP

#include <cassert>
#include <type_traits>

namespace tools {

  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> mod(const M a, const N b) {
    assert(b != 0);

    const ::std::make_unsigned_t<M> ua = a >= 0 ? a : static_cast<::std::make_unsigned_t<M>>(-(a + 1)) + 1;
    const ::std::make_unsigned_t<N> ub = b >= 0 ? b : static_cast<::std::make_unsigned_t<N>>(-(b + 1)) + 1;
    auto r = ua % ub;
    if (a < 0 && r > 0) {
      r = ub - r;
    }
    return r;
  }
}

#endif
