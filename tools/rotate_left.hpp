#ifndef TOOLS_ROTATE_LEFT_HPP
#define TOOLS_ROTATE_LEFT_HPP

#include <type_traits>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>

namespace tools {

  /**
   * circular shift to the left
   * License: CC BY-SA 3.0
   * Reference: Stack Overflow ( https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523 )
   *
   * Usage:
   * ```
   * // 5-bit circular shift to the left
   * tools::rotate_left(x, 5);
   * ```
   *
   * @author John Regehr ( https://blog.regehr.org/ )
   * @author Peter Cordes ( https://stackoverflow.com/users/224132/peter-cordes )
   * @param <T> type of $value$
   * @param value input
   * @param count shift distance
   * @return `value` left-shifted by `input`-bit with a manner of the circular shift
   */
  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>
  constexpr T rotate_left(const T& value, const ::std::size_t& count) noexcept {
    return (value << (count & ::std::numeric_limits<T>::max())) | (value >> (-(count & ::std::numeric_limits<T>::max()) & ::std::numeric_limits<T>::max()));
  }

  /**
   * circular shift to the left
   * License: CC BY-SA 3.0
   * Reference: Stack Overflow ( https://stackoverflow.com/questions/776508/best-practices-for-circular-shift-rotate-operations-in-c/776523#776523 )
   *
   * Usage:
   * ```
   * // 5-bit circular shift to the left
   * tools::rotate_left(x, 5);
   * ```
   *
   * @author John Regehr ( https://blog.regehr.org/ )
   * @author Peter Cordes ( https://stackoverflow.com/users/224132/peter-cordes )
   * @param <T> type of $value$
   * @param value input
   * @param count shift distance
   * @return `value` left-shifted by `input`-bit with a manner of the circular shift
   * @throws std::invalid_argument if `value` is negative
   */
  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value, ::std::nullptr_t>::type = nullptr>
  T rotate_left(const T& value, const ::std::size_t& count) {
    return value >= static_cast<T>(0)
      ? static_cast<T>(::tools::rotate_left(static_cast<typename ::std::make_unsigned<T>::type>(value), count))
      : (throw ::std::invalid_argument("value of tools::rotate_left must be non-negative, but was " + ::std::to_string(value) + "."));
  }
}

#endif
