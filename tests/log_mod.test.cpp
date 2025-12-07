// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/discrete_logarithm_mod

#include <iostream>
#include "tools/log_mod.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll T;
  std::cin >> T;
  for (ll t = 0; t < T; ++t) {
    ll X, Y, M;
    std::cin >> X >> Y >> M;
    if (const auto answer = tools::log_mod(X, Y, M); answer) {
      std::cout << *answer << '\n';
    } else {
      std::cout << -1 << '\n';
    }
  }

  return 0;
}
