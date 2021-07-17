#ifndef TOOLS_TOTIENT_HPP
#define TOOLS_TOTIENT_HPP

#include <cassert>
#include "tools/prime_factorization.hpp"
#include "tools/pow.hpp"

namespace tools {

  template <typename T>
  T totient(const T& x) {
    assert(1 <= x && x <= 1000000000000000000);
    T prod = 1;
    for (const auto& [distinct_prime_factor, exponent] : ::tools::prime_factorization(x)) {
      prod *= ::tools::pow(distinct_prime_factor, exponent - 1) * (distinct_prime_factor - 1);
    }
    return prod;
  }
}

#endif
