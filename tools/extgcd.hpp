#ifndef TOOLS_EXTGCD_HPP
#define TOOLS_EXTGCD_HPP

#include <tuple>
#include "tools/quo.hpp"

namespace tools {

  template <typename T>
  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {
    T prev_s = 1;
    T prev_t = 0;
    T s = 0;
    T t = 1;
    while (r != 0) {
      const T q = ::tools::quo(prev_r, r);
      const T next_r = prev_r - q * r;
      prev_r = r;
      r = next_r;
      const T next_s = prev_s - q * s;
      prev_s = s;
      s = next_s;
      const T next_t = prev_t - q * t;
      prev_t = t;
      t = next_t;
    }

    if (prev_r < T(0)) prev_r = -prev_r;
    return {prev_s, prev_t, prev_r};
  }
}

#endif
