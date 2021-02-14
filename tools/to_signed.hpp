#ifndef TOOLS_TO_SIGNED_HPP
#define TOOLS_TO_SIGNED_HPP

#include <type_traits>

namespace tools {

  /**
   * converts an unsigned integer into signed one
   * License: CC0
   *
   * Usage:
   * ```
   * std::uint_fast64_t i;
   * decltype(tools::to_signed(i)) // => std::int_fast64_t
   * ```
   *
   * @author anqooqie
   * @param <T> type of input
   * @param x input
   * @return `x` converted into signed type
   */
  template <typename T>
  constexpr typename ::std::make_signed<T>::type to_signed(const T x) noexcept {
    return x;
  }
}

#endif
