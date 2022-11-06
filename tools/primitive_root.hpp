#ifndef TOOLS_PRIMITIVE_ROOT_HPP
#define TOOLS_PRIMITIVE_ROOT_HPP

#include <cassert>
#include <algorithm>
#include "tools/is_prime.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/pow_mod.hpp"

namespace tools {
  template <typename T>
  T primitive_root(const T x) {
    assert(::tools::is_prime(x));
    if (x == 2) return 1;

    auto prime_factors = ::tools::prime_factorization(x - 1);
    prime_factors.erase(::std::unique(prime_factors.begin(), prime_factors.end()), prime_factors.end());

    for (T g = 2; ; ++g) {
      if (::std::all_of(prime_factors.begin(), prime_factors.end(), [&](const T p) { return ::tools::pow_mod(g, (x - 1) / p, x) != 1; })) {
        return g;
      }
    }
  }
}

#endif
