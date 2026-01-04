#ifndef TOOLS_CHMAX_HPP
#define TOOLS_CHMAX_HPP

#include "tools/cmp_less.hpp"
#include "tools/integral.hpp"

namespace tools {
  template <typename M, typename N>
  bool chmax(M& lhs, const N& rhs) {
    bool updated;
    if constexpr (tools::integral<M> && tools::integral<N>) {
      updated = tools::cmp_less(lhs, rhs);
    } else {
      updated = lhs < rhs;
    }
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
