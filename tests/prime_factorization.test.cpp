#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <cstdint>
#include <iostream>
#include <vector>
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

    const ::std::vector<i64> prime_factors = tools::prime_factorization(a_i);
    std::cout << prime_factors.size();
    for (const i64& p : prime_factors) {
      std::cout << ' ' << p;
    }
    std::cout << '\n';
  }

  return 0;
}
