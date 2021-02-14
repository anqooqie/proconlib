#ifndef TOOLS_SIGNUM_HPP
#define TOOLS_SIGNUM_HPP

#include <type_traits>

namespace tools {

  template <typename T>
  constexpr int signum(const T x, const ::std::false_type) noexcept {
    return T(0) < x;
  }

  template <typename T>
  constexpr int signum(const T x, const ::std::true_type) noexcept {
    return (T(0) < x) - (x < T(0));
  }

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
    return ::tools::signum(x, ::std::is_signed<T>());
  }
}

#endif
