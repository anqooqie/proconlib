#ifndef TOOLS_IS_PRIME_HPP
#define TOOLS_IS_PRIME_HPP

#include <array>
#include "tools/prod_mod.hpp"
#include "tools/pow_mod.hpp"

namespace tools {

  constexpr bool is_prime(const unsigned long long n) {
    constexpr std::array<unsigned long long, 7> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    auto d = n - 1;
    for (; d % 2 == 0; d /= 2);

    for (const auto a : bases) {
      if (a % n == 0) return true;

      auto power = d;
      auto target = tools::pow_mod(a, power, n);

      bool is_composite = true;
      if (target == 1) is_composite = false;
      for (; is_composite && power != n - 1; power *= 2, target = tools::prod_mod(target, target, n)) {
        if (target == n - 1) is_composite = false;
      }

      if (is_composite) {
        return false;
      }
    }

    return true;
  }
}

#endif
