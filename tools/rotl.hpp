#ifndef TOOLS_ROTL_HPP
#define TOOLS_ROTL_HPP

#include <cassert>
#include <limits>
#include "tools/mod.hpp"

namespace tools {

  template <typename T, typename U>
  constexpr T rotl(const T x, const int n, U s) {
    assert(0 <= n && n <= std::numeric_limits<T>::digits);
    const T mask = (n == std::numeric_limits<T>::digits ? std::numeric_limits<T>::max() : (T(1) << n) - 1);
    assert(0 <= x && x <= mask);
    if (n == 0) return x;
    s = tools::mod(s, n);
    return ((x << s) | (x >> ((n - s) % n))) & mask;
  }

  template <typename T, typename U>
  T rotl(const T& x, U s) {
    if (x.size() == 0) return x;
    s = tools::mod(s, x.size());
    return (x << s) | (x >> ((x.size() - s) % x.size()));
  }
}

#endif
