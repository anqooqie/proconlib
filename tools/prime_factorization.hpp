#ifndef TOOLS_PRIME_FACTORIZATION_HPP
#define TOOLS_PRIME_FACTORIZATION_HPP

#include <vector>
#include <cassert>
#include <queue>
#include <algorithm>
#include <cmath>
#include <numeric>
#include "tools/is_prime.hpp"
#include "tools/pow2.hpp"
#include "tools/floor_log2.hpp"
#include "tools/prod_mod.hpp"

namespace tools {

  template <typename T>
  ::std::vector<T> prime_factorization(T n) {
    assert(1 <= n && n <= 1000000000000000000);
    ::std::vector<T> result;

    if (n == 1) return result;

    ::std::queue<T> factors({n});
    while (!factors.empty()) {
      const T factor = factors.front();
      factors.pop();
      if (::tools::is_prime(factor)) {
        result.push_back(factor);
      } else {
        const T m = ::tools::pow2((::tools::floor_log2(factor) + 1) / 8);
        for (T c = 1; ; ++c) {
          const auto f = [&](T& x) {
            x = ::tools::prod_mod(x, x, factor);
            x += c;
            if (x >= factor) x -= factor;
          };
          T y = 2;
          T r = 1;
          T q = 1;
          T x, g, ys;
          do {
            x = y;
            for (T i = 0; i < r; ++i) {
              f(y);
            }
            T k = 0;
            do {
              ys = y;
              for (T i = 0; i < ::std::min(m, r - k); ++i) {
                f(y);
                q = ::tools::prod_mod(q, ::std::abs(x - y), factor);
              }
              g = ::std::gcd(q, factor);
              k += m;
            } while (k < r && g == 1);
            r *= 2;
          } while (g == 1);
          if (g == factor) {
            do {
              f(ys);
              g = ::std::gcd(::std::abs(x - ys), factor);
            } while (g == 1);
          }
          if (g < factor) {
            factors.push(g);
            factors.push(factor / g);
            break;
          }
        }
      }
    }

    ::std::sort(result.begin(), result.end());
    return result;
  }
}

#endif
