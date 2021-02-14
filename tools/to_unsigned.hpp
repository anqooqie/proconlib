#ifndef TOOLS_TO_UNSIGNED_HPP
#define TOOLS_TO_UNSIGNED_HPP

#include <type_traits>

namespace tools {

  /**
   * converts a signed integer into unsigned one
   * License: CC0
   *
   * Usage:
   * ```
   * std::int_fast64_t i;
   * decltype(tools::to_unsigned(i)) // => std::uint_fast64_t
   * ```
   *
   * @author anqooqie
   * @param <T> type of input
   * @param x input
   * @return `x` converted into unsigned type
   */
  template <typename T>
  constexpr typename ::std::make_unsigned<T>::type to_unsigned(const T x) noexcept {
    return x;
  }
}

#endif
