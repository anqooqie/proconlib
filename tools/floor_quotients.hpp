#ifndef TOOLS_FLOOR_QUOTIENTS_HPP
#define TOOLS_FLOOR_QUOTIENTS_HPP

#include <vector>
#include <tuple>
#include <cassert>
#include <limits>

namespace tools {
  template <typename T>
  ::std::vector<::std::tuple<T, T, T>> floor_quotients(const T A) {
    assert(A >= 0);

    ::std::vector<::std::tuple<T, T, T>> res;
    T x;
    for (x = 1; x * x < A; ++x) {
      res.emplace_back(x, x + 1, A / x);
    }
    for (T q = A / x; q > 0; --q) {
      res.emplace_back(A / (q + 1) + 1, A / q + 1, q);
    }
    res.emplace_back(A + 1, ::std::numeric_limits<T>::max(), 0);

    return res;
  }
}

#endif
