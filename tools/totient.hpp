#ifndef TOOLS_TOTIENT_HPP
#define TOOLS_TOTIENT_HPP

#include <map>
#include <algorithm>
#include <utility>
#include "tools/prime_factorization.hpp"
#include "tools/pow.hpp"

namespace tools {

  /**
   * Euler's totient function
   * License: CC0
   * @author anqooqie
   * @param <T> type of input
   * @param x input
   * @return $\varphi(x)$
   */
  template <typename T>
  T totient(const T& x) {
    const ::std::map<T, T> map = ::tools::prime_factorization(x);
    return ::std::accumulate(map.begin(), map.end(), static_cast<T>(1), [](const T& prod, const ::std::pair<T, T>& pair) {
      return prod * ::tools::pow(pair.first, pair.second - 1) * (pair.first - 1);
    });
  }
}

#endif
