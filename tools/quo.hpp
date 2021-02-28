#ifndef TOOLS_QUO_H
#define TOOLS_QUO_H

#include <type_traits>

namespace tools {

  /**
   * returns quotient as integer division
   * License: CC0
   * @author anqooqie
   * @param <M> type of lhs
   * @param <N> type of rhs
   * @param lhs $a$
   * @param rhs $b$
   * @return q, that satisfies $a = qb + r$ and $0 \leq r < |b|$
   */
  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> quo(const M& lhs, const N& rhs) {
    return lhs > ::std::common_type_t<M, N>(0)
      ? lhs / rhs
      : rhs > ::std::common_type_t<M, N>(0)
        ? -((-lhs - 1 + rhs) / rhs)
        : (-lhs - 1 + -rhs) / -rhs;
  }
}

#endif
