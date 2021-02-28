#ifndef TOOLS_PRIME_FACTORIZATION_HPP
#define TOOLS_PRIME_FACTORIZATION_HPP

#include <map>
#include <cassert>
#include <array>
#include <random>
#include <queue>
#include <numeric>
#include <cmath>
#include "tools/is_prime.hpp"
#include "tools/detail/prod_mod_u64.hpp"

namespace tools {

  /**
   * prime factorization
   * License: CC0
   * @author anqooqie
   * @param n input
   * @return map whose key is a disinct prime factor and value is the multiplicity.
   */
  template <typename T>
  ::std::map<T, T> prime_factorization(T n) {
    assert(1 <= n && n <= 1000000000000000000);

    ::std::map<T, T> result;

    constexpr ::std::array<T, 25> trivial_primes = {
      2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
      31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
      73, 79, 83, 89, 97
    };
    for (auto it = trivial_primes.begin(); *it * *it <= n && it != trivial_primes.end(); ++it) {
      for (; n % *it == 0; n /= *it) {
        ++result[*it];
      }
    }

    if (n == 1) return result;

    ::std::random_device seed_gen;
    ::std::mt19937 engine(seed_gen());

    ::std::queue<T> factors({n});
    while (!factors.empty()) {
      const T factor = factors.front();
      factors.pop();
      if (::tools::is_prime(factor)) {
        ++result[factor];
      } else {
        ::std::uniform_int_distribution<T> dist(0, factor - 1);
        while (true) {
          T c = dist(engine);
          T x = 2;
          T y = 2;
          T d = 1;
          while (d == 1) {
            x = ::tools::detail::prod_mod_u64(x, x, factor);
            x += c;
            if (x >= factor) x -= factor;
            y = ::tools::detail::prod_mod_u64(y, y, factor);
            y += c;
            if (y >= factor) y -= factor;
            y = ::tools::detail::prod_mod_u64(y, y, factor);
            y += c;
            if (y >= factor) y -= factor;
            d = ::std::gcd(::std::abs(x - y), factor);
          }
          if (d < factor) {
            factors.push(d);
            factors.push(factor / d);
            break;
          }
        }
      }
    }

    return result;
  }
}

#endif
