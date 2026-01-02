// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/factorize

#include <iostream>
#include "tools/prime_factorization.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    long long a_i;
    std::cin >> a_i;

    const auto prime_factors = tools::prime_factorization(a_i);
    std::cout << prime_factors.size();
    for (const auto p : prime_factors) {
      std::cout << ' ' << p;
    }
    std::cout << '\n';
  }

  return 0;
}
