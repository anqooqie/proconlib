#ifndef TOOLS_IS_GROUP_HPP
#define TOOLS_IS_GROUP_HPP

#include <type_traits>
#include <utility>

namespace tools {

  template <typename G, typename = void>
  struct is_group : ::std::false_type {};

  template <typename G>
  struct is_group<G, ::std::enable_if_t<
    ::std::is_same_v<typename G::T, decltype(G::op(::std::declval<typename G::T>(), ::std::declval<typename G::T>()))> &&
    ::std::is_same_v<typename G::T, decltype(G::e())> &&
    ::std::is_same_v<typename G::T, decltype(G::inv(::std::declval<typename G::T>()))>
  , void>> : ::std::true_type {};

  template <typename G>
  inline constexpr bool is_group_v = ::tools::is_group<G>::value;
}

#endif
