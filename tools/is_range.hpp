#ifndef TOOLS_IS_RANGE_HPP
#define TOOLS_IS_RANGE_HPP

#include <iterator>
#include <type_traits>
#include <utility>

namespace tools {
  template <typename T>
  class is_range {
  private:
    template <typename U>
    static auto check(U x) -> decltype(::std::begin(x), ::std::end(x), ::std::true_type{});
    static ::std::false_type check(...);

  public:
    static const bool value = decltype(check(::std::declval<T>()))::value;
  };
}

#endif
