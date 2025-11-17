#ifndef TOOLS_MONOID_HPP
#define TOOLS_MONOID_HPP

#include <concepts>

namespace tools {
  template <typename M>
  concept monoid = requires(typename M::T x, typename M::T y) {
    { M::op(x, y) } -> ::std::same_as<typename M::T>;
    { M::e() } -> ::std::same_as<typename M::T>;
  };
}

#endif
