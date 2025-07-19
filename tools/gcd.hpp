#ifndef TOOLS_GCD_HPP
#define TOOLS_GCD_HPP

#include <numeric>
#include <type_traits>

namespace tools {
  template <typename M, typename N> requires (
    ::std::is_integral_v<M> && !::std::is_same_v<::std::remove_cv_t<M>, bool>
    && ::std::is_integral_v<N> && !::std::is_same_v<::std::remove_cv_t<N>, bool>
  )
  constexpr ::std::common_type_t<M, N> gcd(const M m, const N n) {
    return ::std::gcd(m, n);
  }
}

#endif
