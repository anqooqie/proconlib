#ifndef TOOLS_TETRATION_MOD_HPP
#define TOOLS_TETRATION_MOD_HPP

#include <limits>
#include <vector>
#include <utility>
#include <iterator>
#include "tools/pow.hpp"
#include "tools/prime_factorization.hpp"
#include "tools/run_length.hpp"
#include "tools/totient.hpp"
#include "tools/pow_mod.hpp"
#include "tools/garner.hpp"

namespace tools {

  template <typename T>
  T tetration_mod(const T a, const T b, const T m) {
    assert(a >= 0);
    assert(b >= 0);
    assert(m >= 1);

    if (m == 1) return 0;

    // It returns min(fa^^fb, 2^63 - 1).
    const auto f = [](const long long lla, const long long llb) {
      if (lla == 0) return 1 - llb % 2;
      if (lla == 1) return 1LL;
      if (llb == 0) return 1LL;
      if (llb == 1) return lla;
      if (llb == 2 && lla <= 15) return tools::pow(lla, lla);
      if (llb == 3 && lla <= 3) return tools::pow(lla, tools::pow(lla, lla));
      if (llb == 4 && lla <= 2) return tools::pow(lla, tools::pow(lla, tools::pow(lla, lla)));

      // Too large
      return std::numeric_limits<long long>::max();
    };

    if (const auto x = f(a, b); x < std::numeric_limits<long long>::max()) {
      return x % m;
    }

    std::vector<std::pair<T, T>> answers;
    for (const auto& [p, q] : tools::run_length(tools::prime_factorization(m))) {
      const T P = tools::pow(p, q);
      if (std::gcd(a, p) == 1) {
        answers.emplace_back(tools::pow_mod(a, tools::tetration_mod(a, b - 1, tools::totient(P)), P), P);
      } else {
        if (f(a, b - 1) >= q) {
          answers.emplace_back(0, P);
        } else {
          answers.emplace_back(tools::pow_mod(a, f(a, b - 1), P), P);
        }
      }
    }

    return tools::garner(answers.begin(), answers.end(), m).first;
  }
}

#endif
