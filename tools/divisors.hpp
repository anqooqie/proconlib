#ifndef TOOLS_DIVISORS_HPP
#define TOOLS_DIVISORS_HPP

#include <vector>
#include <map>
#include <cstddef>
#include <algorithm>
#include "tools/prime_factorization.hpp"

namespace tools {

  template <typename T>
  ::std::vector<T> divisors(const T& n) {
    const ::std::map<T, T> prime_factors = tools::prime_factorization(n);
    ::std::vector<T> result({1});
    for (const auto& [distinct_prime_factor, exponent] : tools::prime_factorization(n)) {
      const ::std::size_t prev_size = result.size();
      for (::std::size_t i = 0; i < prev_size; ++i) {
        for (T e = 1, p_e = distinct_prime_factor; e <= exponent; ++e, p_e *= distinct_prime_factor) {
          result.push_back(result[i] * p_e);
        }
      }
    }
    ::std::sort(result.begin(), result.end());
    return result;
  }
}

#endif
