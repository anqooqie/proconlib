#ifndef TOOLS_FLOOR_QUOTIENTS_HPP
#define TOOLS_FLOOR_QUOTIENTS_HPP

#include <vector>
#include <tuple>
#include <cassert>
#include <limits>
#include "tools/ceil.hpp"

namespace tools {
  template <typename T>
  ::std::vector<::std::tuple<T, T, T>> ceil_quotients(const T A) {
    assert(A >= 0);

    ::std::vector<::std::tuple<T, T, T>> res;
    T x;
    for (x = 1; x * x < A; ++x) {
      res.emplace_back(x, x + 1, ::tools::ceil(A, x));
    }
    for (T q = ::tools::ceil(A, x); q > 1; --q) {
      res.emplace_back((A - 1) / q + 1, (A - 1) / (q - 1) + 1, q);
    }
    res.emplace_back(A, ::std::numeric_limits<T>::max(), 1);

    return res;
  }
}

#endif
