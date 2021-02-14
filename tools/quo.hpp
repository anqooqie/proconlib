#ifndef TOOLS_QUO_H
#define TOOLS_QUO_H

namespace tools {

  /**
   * returns quotient as integer division
   * License: CC0
   * @author anqooqie
   * @param <T> type of operands
   * @param lhs $a$
   * @param rhs $b$
   * @return q, that satisfies $a = qb + r$ and $0 \leq r < |b|$
   */
  template <typename T>
  constexpr T quo(const T& lhs, const T& rhs) {
    return lhs > static_cast<T>(0)
      ? lhs / rhs
      : rhs > static_cast<T>(0)
        ? -((-lhs - 1 + rhs) / rhs)
        : (-lhs - 1 + -rhs) / -rhs;
  }
}

#endif
