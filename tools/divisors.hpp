#ifndef TOOLS_DIVISORS_HPP
#define TOOLS_DIVISORS_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <vector>
#include "tools/prime_factorization.hpp"
#include "tools/run_length.hpp"

namespace tools {
  template <std::integral T>
  std::vector<T> divisors(const T n) {
    assert(n >= 1);
    std::vector<T> res{1};
    for (const auto& [p, q] : tools::run_length(tools::prime_factorization(n))) {
      const int prev_size = res.size();
      for (int i = 0; i < prev_size; ++i) {
        T p_e = 1;
        for (int e = 1; e <= q; ++e) {
          p_e *= p;
          res.push_back(res[i] * p_e);
        }
      }
    }
    std::ranges::sort(res);
    return res;
  }
}

#endif
