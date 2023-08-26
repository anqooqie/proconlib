#ifndef TOOLS_EXTGCD_HPP
#define TOOLS_EXTGCD_HPP

#include <tuple>
#include <utility>
#include <cassert>
#include <algorithm>
#include "tools/abs.hpp"

namespace tools {

  template <typename T>
  ::std::tuple<T, T, T> extgcd(T prev_r, T r) {
    const bool prev_r_is_neg = prev_r < T(0);
    const bool r_is_neg = r < T(0);

    if (prev_r_is_neg) prev_r = -prev_r;
    if (r_is_neg) r = -r;

    #ifndef NDEBUG
    const T a = prev_r;
    const T b = r;
    #endif

    T prev_s(1);
    T prev_t(0);
    T s(0);
    T t(1);
    while (r != T(0)) {
      const T q = prev_r / r;
      ::std::tie(prev_r, r) = ::std::make_pair(r, prev_r - q * r);
      ::std::tie(prev_s, s) = ::std::make_pair(s, prev_s - q * s);
      ::std::tie(prev_t, t) = ::std::make_pair(t, prev_t - q * t);
    }

    if (prev_r_is_neg) prev_s = -prev_s;
    if (r_is_neg) prev_t = -prev_t;

    assert(::tools::abs(prev_s) <= ::std::max(b / prev_r / T(2), T(1)));
    assert(::tools::abs(prev_t) <= ::std::max(a / prev_r / T(2), T(1)));
    return ::std::make_tuple(prev_s, prev_t, prev_r);
  }
}

#endif
