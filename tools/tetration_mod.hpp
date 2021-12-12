#ifndef TOOLS_TETRATION_MOD_HPP
#define TOOLS_TETRATION_MOD_HPP

#include <cstdint>
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
    const auto f = [](const ::std::int_fast64_t fa, const ::std::int_fast64_t fb) {
      if (fa == 0) return 1 - fb % 2;
      if (fa == 1) return ::std::int_fast64_t(1);
      if (fb == 0) return ::std::int_fast64_t(1);
      if (fb == 1) return fa;
      if (fb == 2 && fa <= 15) return ::tools::pow(fa, fa);
      if (fb == 3 && fa <= 3) return ::tools::pow(fa, ::tools::pow(fa, fa));
      if (fb == 4 && fa <= 2) return ::tools::pow(fa, ::tools::pow(fa, ::tools::pow(fa, fa)));

      // Too large
      return ::std::numeric_limits<::std::int_fast64_t>::max();
    };

    if (f(a, b) < ::std::numeric_limits<::std::int_fast64_t>::max()) {
      return f(a, b) % m;
    }

    ::std::vector<::std::pair<T, T>> answers;
    const ::std::vector<T> prime_factors = ::tools::prime_factorization(m);
    ::std::vector<::std::pair<T, T>> distinct_prime_factors;
    ::tools::run_length(prime_factors.begin(), prime_factors.end(), ::std::back_inserter(distinct_prime_factors));
    for (const auto& [p, q] : distinct_prime_factors) {
      const T P = ::tools::pow(p, q);
      if (::std::gcd(a, p) == 1) {
        answers.emplace_back(::tools::pow_mod(a, ::tools::tetration_mod(a, b - 1, ::tools::totient(P)), P), P);
      } else {
        if (f(a, b - 1) >= q) {
          answers.emplace_back(0, P);
        } else {
          answers.emplace_back(::tools::pow_mod(a, f(a, b - 1), P), P);
        }
      }
    }

    return ::tools::garner(answers.begin(), answers.end(), m).first;
  }
}

#endif
