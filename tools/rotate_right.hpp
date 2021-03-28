#ifndef TOOLS_ROTATE_RIGHT_HPP
#define TOOLS_ROTATE_RIGHT_HPP

#include <type_traits>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>

namespace tools {

  template <typename T, typename ::std::enable_if<::std::is_unsigned<T>::value, ::std::nullptr_t>::type = nullptr>
  constexpr T rotate_right(const T& value, const ::std::size_t& count) noexcept {
    return (value >> (count & ::std::numeric_limits<T>::max())) | (value << (-(count & ::std::numeric_limits<T>::max()) & ::std::numeric_limits<T>::max()));
  }

  template <typename T, typename ::std::enable_if<::std::is_signed<T>::value, ::std::nullptr_t>::type = nullptr>
  T rotate_right(const T& value, const ::std::size_t& count) {
    return value >= static_cast<T>(0)
      ? static_cast<T>(::tools::rotate_right(static_cast<typename ::std::make_unsigned<T>::type>(value), count))
      : (throw ::std::invalid_argument("value of tools::rotate_right must be non-negative, but was " + ::std::to_string(value) + "."));
  }
}

#endif
