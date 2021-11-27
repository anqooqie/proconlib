#ifndef TOOLS_SSIZE_HPP
#define TOOLS_SSIZE_HPP

#include <type_traits>
#include <cstddef>

namespace tools {

  template <typename C>
  constexpr auto ssize(const C& c) -> ::std::common_type_t<::std::ptrdiff_t, ::std::make_signed_t<decltype(c.size())>> {
    return c.size();
  }
}

#endif
