#ifndef TOOLS_HAS_MOD_HPP
#define TOOLS_HAS_MOD_HPP

#include <type_traits>
#include <utility>

namespace tools {
  template <typename T>
  class has_mod {
  private:
    template <typename U>
    static auto check(U x) -> decltype(x.mod(), ::std::true_type{});
    static ::std::false_type check(...);

  public:
    static constexpr bool value = decltype(check(::std::declval<T>()))::value;
  };

  template <typename T>
  inline constexpr bool has_mod_v = ::tools::has_mod<T>::value;
}

#endif
