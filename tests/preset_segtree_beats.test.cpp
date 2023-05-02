#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>
#include "tools/preset_segtree_beats.hpp"

using ll = long long;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;
  std::vector<ll> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  tools::preset_segtree_beats<ll> beats(a);
  for (ll q = 0; q < Q; ++q) {
    ll t;
    std::cin >> t;
    if (t == 0) {
      ll l, r, b;
      std::cin >> l >> r >> b;
      beats.chmin(l, r, b);
    } else if (t == 1) {
      ll l, r, b;
      std::cin >> l >> r >> b;
      beats.chmax(l, r, b);
    } else if (t == 2) {
      ll l, r, b;
      std::cin >> l >> r >> b;
      beats.add(l, r, b);
    } else {
      ll l, r;
      std::cin >> l >> r;
      std::cout << beats.sum(l, r) << '\n';
    }
  }

  return 0;
}
