#ifndef TOOLS_CHMIN_HPP
#define TOOLS_CHMIN_HPP

#include "tools/cmp_less.hpp"

namespace tools {

  template <typename M, typename N>
  bool chmin(M& lhs, const N& rhs) {
    const bool updated = ::tools::cmp_less(rhs, lhs);
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
