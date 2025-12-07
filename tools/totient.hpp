#ifndef TOOLS_TOTIENT_HPP
#define TOOLS_TOTIENT_HPP

#include <cassert>
#include <vector>
#include <utility>
#include <iterator>
#include "tools/prime_factorization.hpp"
#include "tools/run_length.hpp"
#include "tools/pow.hpp"

namespace tools {

  template <typename T>
  T totient(const T& x) {
    assert(1 <= x && x <= 1000000000000000000);
    T prod = 1;
    const std::vector<T> prime_factors = tools::prime_factorization(x);
    std::vector<std::pair<T, T>> distinct_prime_factors;
    tools::run_length(prime_factors.begin(), prime_factors.end(), std::back_inserter(distinct_prime_factors));
    for (const auto& [p, q] : distinct_prime_factors) {
      prod *= tools::pow(p, q - 1) * (p - 1);
    }
    return prod;
  }
}

#endif
