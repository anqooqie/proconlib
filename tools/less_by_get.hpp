#ifndef TOOLS_LESS_BY_GET_HPP
#define TOOLS_LESS_BY_GET_HPP

#include <cstddef>
#include <tuple>

namespace tools {

  template <::std::size_t I>
  struct less_by_get {
    template <typename T>
    bool operator()(const T& x, const T& y) const {
      return ::std::get<I>(x) < ::std::get<I>(y);
    }
  };
}

#endif
