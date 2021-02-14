#ifndef TOOLS_CHMIN_HPP
#define TOOLS_CHMIN_HPP

#include <algorithm>

namespace tools {

  /**
   * runs `lhs = std::min(lhs, rhs);`
   * License: CC0
   * @author anqooqie
   * @param <T> type of operands
   * @param lhs left hand side operand
   * @param rhs right hand side operand
   * @return `true` if `lhs` has been updated, `false` otherwise
   */
  template <typename T>
  bool chmin(T& lhs, const T& rhs) {
    const bool updated = lhs > rhs;
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
