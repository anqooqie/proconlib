#ifndef TOOLS_MOD_HPP
#define TOOLS_MOD_HPP

#include "tools/quo.hpp"

namespace tools {

  /**
   * returns minimum non-negative reminder
   * License: CC0
   * @author anqooqie
   * @param <T> type of operands
   * @param lhs $a$
   * @param rhs $b$
   * @return r, that satisfies $a = qb + r$ and $0 \leq r < |b|$
   */
  template <typename T>
  constexpr T mod(const T& lhs, const T& rhs) {
    return lhs - ::tools::quo(lhs, rhs) * rhs;
  }
}

#endif
