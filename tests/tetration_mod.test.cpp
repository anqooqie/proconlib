#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include <iostream>
#include "tools/tetration_mod.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll T;
  std::cin >> T;
  for (ll i = 0; i < T; ++i) {
    ll A, B, M;
    std::cin >> A >> B >> M;
    std::cout << tools::tetration_mod(A, B, M) << '\n';
  }
  return 0;
}
