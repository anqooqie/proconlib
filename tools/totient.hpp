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
    for (const auto& [p, q] : tools::run_length(tools::prime_factorization(x))) {
      prod *= tools::pow(p, q - 1) * (p - 1);
    }
    return prod;
  }
}

#endif
