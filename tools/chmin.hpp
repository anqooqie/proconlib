#ifndef TOOLS_CHMIN_HPP
#define TOOLS_CHMIN_HPP

#include "tools/cmp_less.hpp"
#include "tools/integral.hpp"

namespace tools {
  template <typename M, typename N>
  bool chmin(M& lhs, const N& rhs) {
    bool updated;
    if constexpr (tools::integral<M> && tools::integral<N>) {
      updated = tools::cmp_less(rhs, lhs);
    } else {
      updated = rhs < lhs;
    }
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
