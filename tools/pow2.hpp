#ifndef TOOLS_POW2_HPP
#define TOOLS_POW2_HPP

#include <type_traits>
#include <cstddef>

namespace tools {

  template <typename T, typename std::enable_if<std::is_unsigned<T>::value, std::nullptr_t>::type = nullptr>
  constexpr T pow2(const T x) {
    return static_cast<T>(1) << x;
  }

  template <typename T, typename std::enable_if<std::is_signed<T>::value, std::nullptr_t>::type = nullptr>
  constexpr T pow2(const T x) {
    return static_cast<T>(static_cast<typename std::make_unsigned<T>::type>(1) << static_cast<typename std::make_unsigned<T>::type>(x));
  }
}

#endif
