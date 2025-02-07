#ifndef TOOLS_MAKE_UNSIGNED_HPP
#define TOOLS_MAKE_UNSIGNED_HPP

#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  struct make_unsigned : ::std::make_unsigned<T> {};
  template <>
  struct make_unsigned<::tools::int128_t> {
    using type = ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<::tools::uint128_t> {
    using type = ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const ::tools::int128_t> {
    using type = const ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const ::tools::uint128_t> {
    using type = const ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<volatile ::tools::int128_t> {
    using type = volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<volatile ::tools::uint128_t> {
    using type = volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const volatile ::tools::int128_t> {
    using type = const volatile ::tools::uint128_t;
  };
  template <>
  struct make_unsigned<const volatile ::tools::uint128_t> {
    using type = const volatile ::tools::uint128_t;
  };

  template <typename T>
  using make_unsigned_t = typename ::tools::make_unsigned<T>::type;
}

#endif
