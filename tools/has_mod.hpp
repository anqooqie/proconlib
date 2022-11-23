#ifndef TOOLS_HAS_MOD_HPP
#define TOOLS_HAS_MOD_HPP

#include <type_traits>
#include <utility>

namespace tools {
  template <typename T, typename = ::std::void_t<>>
  struct has_mod : ::std::false_type {};

  template <typename T>
  struct has_mod<T, ::std::void_t<decltype(::std::declval<T>().mod())>> : ::std::true_type {};

  template <typename T>
  inline constexpr bool has_mod_v = ::tools::has_mod<T>::value;
}

#endif
