#ifndef TOOLS_TOTIENT_HPP
#define TOOLS_TOTIENT_HPP

#include <vector>
#include <iterator>
#include <algorithm>
#include <cstddef>
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
    assert(1 <= x && x <= 1000000000000000000);
    ::std::vector<T> prime_factors;
    ::tools::prime_factorization(x, ::std::back_inserter(prime_factors));
    ::std::sort(prime_factors.begin(), prime_factors.end());
    ::std::size_t r = 0;
    T prod = 1;
    for (::std::size_t l = 0; l < prime_factors.size(); l = r) {
      for (; r < prime_factors.size() && prime_factors[l] == prime_factors[r]; ++r);
      prod *= ::tools::pow(prime_factors[l], r - l - 1) * (prime_factors[l] - 1);
    }
    return prod;
  }
}

#endif
