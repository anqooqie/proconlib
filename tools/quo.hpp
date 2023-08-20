#ifndef TOOLS_QUO_H
#define TOOLS_QUO_H

#include <type_traits>

namespace tools {

  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> quo(const M lhs, const N rhs) {
    using T = ::std::common_type_t<M, N>;
    if (lhs >= M(0)) {
      return lhs / rhs;
    } else {
      if (rhs >= N(0)) {
        return -((-lhs - T(1) + rhs) / rhs);
      } else {
        return (-lhs - T(1) + -rhs) / -rhs;
      }
    }
  }
}

#endif
