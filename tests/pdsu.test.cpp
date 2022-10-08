#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"

#include <iostream>
#include "tools/pdsu.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll n, q;
  std::cin >> n >> q;
  tools::pdsu pdsu(n);
  for (ll i = 0; i < q; ++i) {
    ll t;
    std::cin >> t;
    if (t == 0) {
      ll x, y, z;
      std::cin >> x >> y >> z;
      if (pdsu.same(x, y)) {
        assert(pdsu.diff(x, y) == z);
      } else {
        pdsu.merge(x, y, z);
      }
    } else {
      ll x, y;
      std::cin >> x >> y;
      if (pdsu.same(x, y)) {
        std::cout << pdsu.diff(x, y) << '\n';
      } else {
        std::cout << "?" << '\n';
      }
    }
  }

  return 0;
}
