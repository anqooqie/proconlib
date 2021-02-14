#ifndef TOOLS_DETAIL_CEIL_AND_FLOOR_HPP
#define TOOLS_DETAIL_CEIL_AND_FLOOR_HPP

namespace tools {

  /**
   * floor function
   * License: CC0
   * @author anqooqie
   * @param <T> type of the operands
   * @param lhs left hand side operand
   * @param rhs right hand side operand
   * @return $\left\lfloor \frac{\mathrm{lhs}}{\mathrm{rhs}} \right\rfloor$
   */
  template <typename T>
  constexpr T floor(const T& lhs, const T& rhs);

  /**
   * ceiling function
   * License: CC0
   * @author anqooqie
   * @param <T> type of the operands
   * @param lhs left hand side operand
   * @param rhs right hand side operand
   * @return $\left\lceil \frac{\mathrm{lhs}}{\mathrm{rhs}} \right\rceil$
   */
  template <typename T>
  constexpr T ceil(const T& lhs, const T& rhs);
  
  template <typename T>
  constexpr T floor(const T& lhs, const T& rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        lhs / rhs :
      lhs < 0 && rhs >= 0 ?
        -::tools::ceil<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -::tools::ceil<T>(lhs, -rhs) :
        ::tools::floor<T>(-lhs, -rhs);
  }
  
  template <typename T>
  constexpr T ceil(const T& lhs, const T& rhs) {
    return
      lhs >= 0 && rhs >= 0 ?
        (lhs - 1 + rhs) / rhs :
      lhs < 0 && rhs >= 0 ?
        -::tools::floor<T>(-lhs, rhs) :
      lhs >= 0 && rhs < 0 ?
        -::tools::floor<T>(lhs, -rhs) :
        ::tools::ceil<T>(-lhs, -rhs);
  }
}

#endif
