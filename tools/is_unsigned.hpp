#ifndef TOOLS_IS_UNSIGNED_HPP
#define TOOLS_IS_UNSIGNED_HPP

#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  struct is_unsigned : ::std::is_unsigned<T> {};
  template <>
  struct is_unsigned<::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<const ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<const ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<volatile ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<volatile ::tools::uint128_t> : ::std::true_type {};
  template <>
  struct is_unsigned<const volatile ::tools::int128_t> : ::std::false_type {};
  template <>
  struct is_unsigned<const volatile ::tools::uint128_t> : ::std::true_type {};

  template <typename T>
  inline constexpr bool is_unsigned_v = ::tools::is_unsigned<T>::value;
}

#endif
