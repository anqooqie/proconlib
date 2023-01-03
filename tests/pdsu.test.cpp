#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_1_B"

#include <iostream>
#include <cassert>
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
      pdsu.merge(x, y, z);
      assert(pdsu.diff(x, y).first == tools::pdsu_diff::known);
    } else {
      ll x, y;
      std::cin >> x >> y;
      const auto [t, d] = pdsu.diff(x, y);
      assert(t != tools::pdsu_diff::inconsistent);
      if (t == tools::pdsu_diff::known) {
        std::cout << d << '\n';
      } else {
        std::cout << "?" << '\n';
      }
    }
  }

  return 0;
}
