#ifndef TOOLS_CHMIN_HPP
#define TOOLS_CHMIN_HPP

#include "tools/cmp_less.hpp"

namespace tools {

  template <typename M, typename N>
  bool chmin(M& lhs, const N& rhs) {
    bool updated;
    if constexpr (::std::is_integral_v<M> && ::std::is_integral_v<N>) {
      updated = ::tools::cmp_less(rhs, lhs);
    } else {
      updated = rhs < lhs;
    }
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
