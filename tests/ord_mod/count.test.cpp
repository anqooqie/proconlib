#define PROBLEM "https://atcoder.jp/contests/abc212/tasks/abc212_g"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/ord_mod.hpp"

using mint = atcoder::modint998244353;
using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll P;
  std::cin >> P;

  auto answer = mint::raw(1);
  for (const auto& [ord, n] : tools::ord_mod(P).count()) {
    answer += mint(ord) * mint(n);
  }
  std::cout << answer.val() << '\n';
  return 0;
}
