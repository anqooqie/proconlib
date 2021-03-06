#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <cstdint>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include "tools/prime_factorization.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 Q;
  std::cin >> Q;
  for (i64 i = 0; i < Q; ++i) {
    i64 a_i;
    std::cin >> a_i;

    const ::std::map<i64, i64> prime_factors = tools::prime_factorization(a_i);
    std::cout << std::accumulate(prime_factors.begin(), prime_factors.end(), i64(0), [](const i64& sum, const std::pair<i64, i64>& p) { return sum + p.second; }) << '\n';
    for (const auto& [distinct_prime_factor, exponent] : prime_factors) {
      for (i64 e = 0; e < exponent; ++e) {
        std::cout << ' ' << distinct_prime_factor;
      }
    }
    std::cout << '\n';
  }

  return 0;
}
