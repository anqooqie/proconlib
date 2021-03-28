#ifndef TOOLS_MOD_HPP
#define TOOLS_MOD_HPP

#include <type_traits>
#include "tools/quo.hpp"

namespace tools {

  template <typename M, typename N>
  constexpr ::std::common_type_t<M, N> mod(const M lhs, const N rhs) {
    if constexpr (::std::is_unsigned_v<M> && ::std::is_unsigned_v<N>) {
      return lhs % rhs;
    } else {
      return lhs - ::tools::quo(lhs, rhs) * rhs;
    }
  }
}

#endif
