// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/sqrt_mod

#include <iostream>
#include "tools/sqrt_mod.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll T;
  std::cin >> T;
  for (ll t = 0; t < T; ++t) {
    ll Y, P;
    std::cin >> Y >> P;
    const auto answer = ::tools::sqrt_mod(Y, P);
    std::cout << (answer ? *answer : -1) << '\n';
  }

  return 0;
}
