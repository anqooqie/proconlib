#ifndef TOOLS_MAKE_SIGNED_HPP
#define TOOLS_MAKE_SIGNED_HPP

#include <type_traits>
#include "tools/int128_t.hpp"
#include "tools/uint128_t.hpp"

namespace tools {
  template <typename T>
  struct make_signed : ::std::make_signed<T> {};
  template <>
  struct make_signed<::tools::int128_t> {
    using type = ::tools::int128_t;
  };
  template <>
  struct make_signed<::tools::uint128_t> {
    using type = ::tools::int128_t;
  };
  template <>
  struct make_signed<const ::tools::int128_t> {
    using type = const ::tools::int128_t;
  };
  template <>
  struct make_signed<const ::tools::uint128_t> {
    using type = const ::tools::int128_t;
  };
  template <>
  struct make_signed<volatile ::tools::int128_t> {
    using type = volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<volatile ::tools::uint128_t> {
    using type = volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<const volatile ::tools::int128_t> {
    using type = const volatile ::tools::int128_t;
  };
  template <>
  struct make_signed<const volatile ::tools::uint128_t> {
    using type = const volatile ::tools::int128_t;
  };

  template <typename T>
  using make_signed_t = typename ::tools::make_signed<T>::type;
}

#endif
