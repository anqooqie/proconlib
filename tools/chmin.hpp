#ifndef TOOLS_CHMIN_HPP
#define TOOLS_CHMIN_HPP

#include <algorithm>

namespace tools {

  template <typename M, typename N>
  bool chmin(M& lhs, const N& rhs) {
    const bool updated = lhs > rhs;
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
