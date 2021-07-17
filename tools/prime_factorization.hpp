#ifndef TOOLS_PRIME_FACTORIZATION_HPP
#define TOOLS_PRIME_FACTORIZATION_HPP

#include <map>
#include <cassert>
#include <random>
#include <queue>
#include <numeric>
#include <cmath>
#include "tools/is_prime.hpp"
#include "tools/prod_mod.hpp"

namespace tools {

  template <typename T>
  ::std::map<T, T> prime_factorization(T n) {
    assert(1 <= n && n <= 1000000000000000000);
    ::std::map<T, T> result;

    for (; n % 2 == 0; n /= 2) {
      ++result[2];
    }
    if (n == 1) return result;

    ::std::minstd_rand engine;
    ::std::queue<T> factors({n});
    while (!factors.empty()) {
      const T factor = factors.front();
      factors.pop();
      if (::tools::is_prime(factor)) {
        ++result[factor];
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

    return result;
  }
}

#endif
