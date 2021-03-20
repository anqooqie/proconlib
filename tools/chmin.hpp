#ifndef TOOLS_CHMIN_HPP
#define TOOLS_CHMIN_HPP

#include <algorithm>

namespace tools {

  /**
   * runs `lhs = std::min(lhs, rhs);`
   * License: CC0
   * @author anqooqie
   * @param <M> type of lhs
   * @param <N> type of rhs
   * @param lhs left hand side operand
   * @param rhs right hand side operand
   * @return `true` if `lhs` has been updated, `false` otherwise
   */
  template <typename M, typename N>
  bool chmin(M& lhs, const N& rhs) {
    const bool updated = lhs > rhs;
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
