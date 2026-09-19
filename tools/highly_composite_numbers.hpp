#ifndef TOOLS_HIGHLY_COMPOSITE_NUMBERS_HPP
#define TOOLS_HIGHLY_COMPOSITE_NUMBERS_HPP

#include <array>
#include <cassert>
#include <limits>
#include <map>
#include <ranges>
#include <utility>
#include <vector>
#include "tools/non_bool_integral.hpp"

namespace tools {
  template <tools::non_bool_integral T>
  std::vector<std::pair<T, T>> highly_composite_numbers(const T n) {
    assert(n >= T(1));

    std::map<T, T> res;

    [&](this const auto& dfs, const T d_m, const T m, const int max_e, const int k) -> void {
      // Enough primes for n up to the maximum of a hypothetical uint512_t, to allow for future extensions:
      // 2 * 3 * ... * 379 (75 primes) fits in 512 bits, and the search also reads the next prime, 383.
      static constexpr std::array<int, 76> primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
        73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
        127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
        179, 181, 191, 193, 197, 199, 211, 223, 227, 229,
        233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
        283, 293, 307, 311, 313, 317, 331, 337, 347, 349,
        353, 359, 367, 373, 379, 383,
      };

      if (auto it = res.lower_bound(d_m); it == res.end() || it->second > m) {
        if (it != res.end() && it->first == d_m) {
          it->second = m;
        } else {
          it = res.emplace_hint(it, d_m, m);
        }
        while (it != res.begin()) {
          --it;
          if (it->second < m) break;
          it = res.erase(it);
        }
      }

      T next_m = m;
      for (int e = 1; e <= max_e && next_m <= n / T(primes[k]); ++e) {
        next_m *= T(primes[k]);
        dfs(d_m * T(e + 1), next_m, e, k + 1);
      }
    }(T(1), T(1), std::numeric_limits<int>::max(), 0);

    return res | std::views::transform([](const auto& pair) { return std::make_pair(pair.second, pair.first); }) | std::ranges::to<std::vector>();
  }
}

#endif
