#ifndef TOOLS_SIGNUM_HPP
#define TOOLS_SIGNUM_HPP

#include <type_traits>

namespace tools {

  /**
   * sign function
   * License: CC0
   * @author anqooqie
   * @param <T> type of input
   * @param x input
   * @return $-1$ if $x$ is negative, $1$ if $x$ is positive, $0$ if $x$ is zero
   */
  template <typename T>
  constexpr int signum(const T x) noexcept {
    if constexpr (::std::is_signed_v<T>) {
      return (T(0) < x) - (x < T(0));
    } else {
      return T(0) < x;
    }
  }
}

#endif
