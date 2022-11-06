#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include <iostream>
#include "tools/primitive_root.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll Q;
  std::cin >> Q;
  for (ll q = 0; q < Q; ++q) {
    ll p;
    std::cin >> p;
    std::cout << tools::primitive_root(p) << '\n';
  }

  return 0;
}
