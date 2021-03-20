#ifndef TOOLS_PRIME_FACTORIZATION_HPP
#define TOOLS_PRIME_FACTORIZATION_HPP

#include <cassert>
#include <array>
#include <random>
#include <queue>
#include <numeric>
#include <cmath>
#include "tools/is_prime.hpp"
#include "tools/prod_mod.hpp"

namespace tools {

  /**
   * prime factorization
   * License: CC0
   * @author anqooqie
   * @param <T> type of n
   * @param <OutputIterator> type of result
   * @param n input
   * @param result output iterator as a storage of unordered prime factors
   */
  template <typename T, typename OutputIterator>
  void prime_factorization(T n, OutputIterator result) {
    assert(1 <= n && n <= 1000000000000000000);

    for (; n % 2 == 0; n /= 2) {
      *result = 2;
      ++result;
    }
    if (n == 1) return;

    ::std::minstd_rand engine;
    ::std::queue<T> factors({n});
    while (!factors.empty()) {
      const T factor = factors.front();
      factors.pop();
      if (::tools::is_prime(factor)) {
        *result = factor;
        ++result;
      } else {
        ::std::uniform_int_distribution<T> dist(1, factor - 2);
        while (true) {
          T c = dist(engine);
          if (c == factor - 2) c = factor - 1;
          T x = 2;
          T y = 2;
          T d = 1;
          while (d == 1) {
            x = ::tools::prod_mod(x, x, factor);
            x += c;
            if (x >= factor) x -= factor;
            y = ::tools::prod_mod(y, y, factor);
            y += c;
            if (y >= factor) y -= factor;
            y = ::tools::prod_mod(y, y, factor);
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
  }
}

#endif
