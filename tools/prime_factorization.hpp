#ifndef TOOLS_PRIME_FACTORIZATION_HPP
#define TOOLS_PRIME_FACTORIZATION_HPP

#include <algorithm>
#include <cassert>
#include <concepts>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include "tools/floor_log2.hpp"
#include "tools/is_prime.hpp"
#include "tools/pow2.hpp"
#include "tools/prod_mod.hpp"

namespace tools {
  template <std::integral T>
  std::vector<T> prime_factorization(T n) {
    assert(n >= 1);
    std::vector<T> res;

    if (n == 1) return res;

    std::queue<std::pair<T, T>> factors;
    factors.emplace(n, 1);
    while (!factors.empty()) {
      const auto [factor, occurrences] = factors.front();
      factors.pop();
      if (tools::is_prime(factor)) {
        for (T i = 0; i < occurrences; ++i) {
          res.push_back(factor);
        }
      } else {
        const T m = tools::pow2((tools::floor_log2(factor) + 1) / 8);
        for (T c = 1; ; ++c) {
          const auto f = [&](T& x) {
            x = tools::prod_mod(x, x, factor);
            // (x + c) mod factor s.t. 0 <= x < factor and 1 <= c < factor
            if (x >= factor - c) {
              x -= factor - c;
            } else {
              x += c;
            }
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
              for (T i = 0; i < std::min<T>(m, r - k); ++i) {
                f(y);
                q = tools::prod_mod(q, std::max(x, y) - std::min(x, y), factor);
              }
              g = std::gcd(q, factor);
              k += m;
            } while (k < r && g == 1);
            r *= 2;
          } while (g == 1);
          if (g == factor) {
            do {
              f(ys);
              g = std::gcd(std::max(x, ys) - std::min(x, ys), factor);
            } while (g == 1);
          }
          if (g < factor) {
            T h = factor / g;
            std::tie(g, h) = std::minmax({g, h});
            T n = 1;
            while (h % g == 0) {
              h /= g;
              ++n;
            }
            factors.emplace(g, occurrences * n);
            if (h > 1) factors.emplace(h, occurrences);
            break;
          }
        }
      }
    }

    std::ranges::sort(res);
    return res;
  }
}

#endif
