#ifndef TOOLS_TOTIENT_HPP
#define TOOLS_TOTIENT_HPP

#include <cassert>
#include <concepts>
#include <iterator>
#include <utility>
#include <vector>
#include "tools/pow.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/run_length.hpp"

namespace tools {
  template <std::integral T>
  T totient(const T x) {
    assert(x >= 1);
    T prod = 1;
    for (const auto& [p, q] : tools::run_length(tools::prime_factorization(x))) {
      prod *= tools::pow(p, q - 1) * (p - 1);
    }
    return prod;
  }
}

#endif
