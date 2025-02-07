#ifndef TOOLS_IS_INTEGRAL_HPP
#define TOOLS_IS_INTEGRAL_HPP

#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  struct is_integral : ::std::is_integral<T> {};
  template <>
  struct is_integral<::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<const ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<const ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<volatile ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_integral<const volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_integral<const volatile ::tools::uint128_t> : ::std::true_type {};

  template <typename T>
  inline constexpr bool is_integral_v = ::tools::is_integral<T>::value;
}

#endif
