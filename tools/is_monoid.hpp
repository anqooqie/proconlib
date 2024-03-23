#ifndef TOOLS_IS_MONOID_HPP
#define TOOLS_IS_MONOID_HPP

#include <type_traits>
#include <utility>

namespace tools {

  template <typename M, typename = void>
  struct is_monoid : ::std::false_type {};

  template <typename M>
  struct is_monoid<M, ::std::enable_if_t<
    ::std::is_same_v<typename M::T, decltype(M::op(::std::declval<typename M::T>(), ::std::declval<typename M::T>()))> &&
    ::std::is_same_v<typename M::T, decltype(M::e())>
  , void>> : ::std::true_type {};

  template <typename M>
  inline constexpr bool is_monoid_v = ::tools::is_monoid<M>::value;
}

#endif
