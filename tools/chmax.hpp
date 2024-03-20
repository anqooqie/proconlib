#ifndef TOOLS_CHMAX_HPP
#define TOOLS_CHMAX_HPP

#include "tools/cmp_less.hpp"

namespace tools {

  template <typename M, typename N>
  bool chmax(M& lhs, const N& rhs) {
    const bool updated = ::tools::cmp_less(lhs, rhs);
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
