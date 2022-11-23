#ifndef TOOLS_IS_RANGE_HPP
#define TOOLS_IS_RANGE_HPP

#include <type_traits>
#include <iterator>
#include <utility>

namespace tools {
  template <typename T, typename = ::std::void_t<>>
  struct is_range : ::std::false_type {};

  template <typename T>
  struct is_range<T, ::std::void_t<decltype(::std::begin(::std::declval<T>()), ::std::end(::std::declval<T>()))>> : ::std::true_type {};

  template <typename T>
  inline constexpr bool is_range_v = ::tools::is_range<T>::value;
}

#endif
