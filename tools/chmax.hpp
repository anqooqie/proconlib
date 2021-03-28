#ifndef TOOLS_CHMAX_HPP
#define TOOLS_CHMAX_HPP

#include <algorithm>

namespace tools {

  template <typename M, typename N>
  bool chmax(M& lhs, const N& rhs) {
    const bool updated = lhs < rhs;
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
