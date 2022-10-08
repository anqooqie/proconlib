#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <iostream>
#include <vector>
#include "tools/prime_factorization.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll Q;
  std::cin >> Q;
  for (ll i = 0; i < Q; ++i) {
    ll a_i;
    std::cin >> a_i;

    const ::std::vector<ll> prime_factors = tools::prime_factorization(a_i);
    std::cout << prime_factors.size();
    for (const ll& p : prime_factors) {
      std::cout << ' ' << p;
    }
    std::cout << '\n';
  }

  return 0;
}
