#ifndef TOOLS_ROTATE_LEFT_HPP
#define TOOLS_ROTATE_LEFT_HPP

#include <cassert>
#include <limits>
#include "tools/mod.hpp"

namespace tools {

  template <typename T, typename U>
  constexpr T rotate_left(const T x, const ::std::size_t n, U s) {
    assert(n <= ::std::numeric_limits<T>::digits);
    const T mask = (n == ::std::numeric_limits<T>::digits ? ::std::numeric_limits<T>::max() : (T(1) << n) - 1);
    assert(0 <= x && x <= mask);
    s = ::tools::mod(s, n);
    return ((x << s) | (x >> ((n - s) % n))) & mask;
  }

  template <typename T, typename U>
  T rotate_left(const T& x, U s) {
    s = ::tools::mod(s, x.size());
    return (x << s) | (x >> ((x.size() - s) % x.size()));
  }
}

#endif
