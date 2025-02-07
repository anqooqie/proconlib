#ifndef TOOLS_IS_SIGNED_HPP
#define TOOLS_IS_SIGNED_HPP

#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  struct is_signed : ::std::is_signed<T> {};
  template <>
  struct is_signed<::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<const ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<const ::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<volatile ::tools::uint128_t> : ::std::false_type {};
  template <>
  struct is_signed<const volatile ::tools::int128_t> : ::std::true_type {};
  template <>
  struct is_signed<const volatile ::tools::uint128_t> : ::std::false_type {};

  template <typename T>
  inline constexpr bool is_signed_v = ::tools::is_signed<T>::value;
}

#endif
