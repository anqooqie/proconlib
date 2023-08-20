#ifndef TOOLS_EXTGCD_HPP
#define TOOLS_EXTGCD_HPP

#include <tuple>
#include <utility>
#include "tools/quo.hpp"

namespace tools {

  template <typename T>
  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {
    T prev_s(1);
    T prev_t(0);
    T s(0);
    T t(1);
    while (r != T(0)) {
      const T q = ::tools::quo(prev_r, r);
      ::std::tie(prev_r, r) = ::std::make_pair(r, prev_r - q * r);
      ::std::tie(prev_s, s) = ::std::make_pair(s, prev_s - q * s);
      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t - q * t);
    }

    if (prev_r < T(0)) prev_r = -prev_r;
    return ::std::make_tuple(prev_s, prev_t, prev_r);
  }
}

#endif
