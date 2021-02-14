#ifndef TOOLS_DETAIL_CEIL_AND_FLOOR_HPP
#define TOOLS_DETAIL_CEIL_AND_FLOOR_HPP

#include <type_traits>

namespace tools {

  /**
   * floor function
   * License: CC0
   * @author anqooqie
   * @param <M> type of `lhs`
   * @param <N> type of `rhs`
   * @param lhs left hand side operand
   * @param rhs right hand side operand
   * @return $\left\lfloor \frac{\mathrm{lhs}}{\mathrm{rhs}} \right\rfloor$
   */
  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> floor(const M& lhs, const N& rhs);

  /**
   * ceiling function
   * License: CC0
   * @author anqooqie
   * @param <M> type of `lhs`
   * @param <N> type of `rhs`
   * @param lhs left hand side operand
   * @param rhs right hand side operand
   * @return $\left\lceil \frac{\mathrm{lhs}}{\mathrm{rhs}} \right\rceil$
   */
  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs);
  
  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> floor(const M& lhs, const N& rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        lhs / rhs :
      lhs < 0 && rhs >= 0 ?
        -::tools::ceil(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -::tools::ceil(lhs, -rhs) :
        ::tools::floor(-lhs, -rhs);
  }
  
  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> ceil(const M& lhs, const N& rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        (lhs - 1 + rhs) / rhs :
      lhs < 0 && rhs >= 0 ?
        -::tools::floor(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -::tools::floor(lhs, -rhs) :
        ::tools::ceil(-lhs, -rhs);
  }
}

#endif
