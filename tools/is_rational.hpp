#ifndef TOOLS_IS_RATIONAL_HPP
#define TOOLS_IS_RATIONAL_HPP

namespace tools {

  template <typename T>
  struct is_rational {
    static constexpr bool value = false;
  };

  template <typename T>
  inline constexpr bool is_rational_v = ::tools::is_rational<T>::value;
}

#endif
