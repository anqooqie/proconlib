#ifndef TOOLS_CHMAX_HPP
#define TOOLS_CHMAX_HPP

#include <type_traits>
#include <utility>

namespace tools {

  template <typename M, typename N>
  bool chmax(M& lhs, const N& rhs) {
    bool updated;
    if constexpr (std::is_integral_v<M> && std::is_integral_v<N>) {
      updated = std::cmp_less(lhs, rhs);
    } else {
      updated = lhs < rhs;
    }
    if (updated) lhs = rhs;
    return updated;
  }
}

#endif
