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
    std::vector<T> result({1});
    for (const auto& [p, q] : tools::run_length(tools::prime_factorization(n))) {
      const std::size_t prev_size = result.size();
      for (std::size_t i = 0; i < prev_size; ++i) {
        T p_e = p;
        for (int e = 1; e <= q; ++e, p_e *= p) {
          result.push_back(result[i] * p_e);
        }
      }
    }
    std::sort(result.begin(), result.end());
    return result;
  }
}

#endif
