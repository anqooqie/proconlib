#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"

#include <iostream>
#include "atcoder/modint.hpp"
#include "tools/extended_lucas.hpp"

using mint = atcoder::modint;
using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll T, m;
  std::cin >> T >> m;
  mint::set_mod(m);
  tools::extended_lucas<mint> cache;

  for (ll i = 0; i < T; ++i) {
    ll n, k;
    std::cin >> n >> k;
    std::cout << cache.combination(n, k).val() << '\n';
  }
  return 0;
}
