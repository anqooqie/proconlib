#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <cstdint>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
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

    std::vector<i64> prime_factors;
    tools::prime_factorization(a_i, std::back_inserter(prime_factors));
    std::cout << prime_factors.size();
    std::sort(prime_factors.begin(), prime_factors.end());
    for (const i64& prime_factor : prime_factors) {
      std::cout << ' ' << prime_factor;
    }
    std::cout << '\n';
  }

  return 0;
}
