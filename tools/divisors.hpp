#ifndef TOOLS_DIVISORS_HPP
#define TOOLS_DIVISORS_HPP

#include <vector>
#include <utility>
#include <iterator>
#include <cstddef>
#include <algorithm>
#include "tools/prime_factorization.hpp"
#include "tools/run_length.hpp"

namespace tools {

  template <typename T>
  std::vector<T> divisors(const T& n) {
    const std::vector<T> prime_factors = tools::prime_factorization(n);
    std::vector<std::pair<T, T>> distinct_prime_factors;
    tools::run_length(prime_factors.begin(), prime_factors.end(), std::back_inserter(distinct_prime_factors));

    std::vector<T> result({1});
    for (const auto& [p, q] : distinct_prime_factors) {
      const std::size_t prev_size = result.size();
      for (std::size_t i = 0; i < prev_size; ++i) {
        for (T e = 1, p_e = p; e <= q; ++e, p_e *= p) {
          result.push_back(result[i] * p_e);
        }
      }
    }
    std::sort(result.begin(), result.end());
    return result;
  }
}

#endif
