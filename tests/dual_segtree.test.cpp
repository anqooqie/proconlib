// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_affine_point_get

#include <iostream>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/dual_segtree.hpp"

using ll = long long;
using mint = atcoder::modint998244353;

struct monoid {
  using T = std::pair<mint, mint>;
  static T op(const T& f2, const T& f1) {
    return std::make_pair(f2.first * f1.first, f2.first * f1.second + f2.second);
  }
  static T e() {
    return std::make_pair(mint(1), mint(0));
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  ll N, Q;
  std::cin >> N >> Q;
  std::vector<mint> a(N);
  for (ll i = 0; i < N; ++i) {
    ll a_i;
    std::cin >> a_i;
    a[i] = mint(a_i);
  }

  tools::dual_segtree<monoid> dual_segtree(N);
  for (ll q = 0; q < Q; ++q) {
    ll t;
    std::cin >> t;
    if (t == 0) {
      ll l, r, b, c;
      std::cin >> l >> r >> b >> c;
      dual_segtree.apply(l, r, std::make_pair(mint(b), mint(c)));
    } else {
      ll i;
      std::cin >> i;
      const auto [b, c] = dual_segtree.get(i);
      std::cout << (b * a[i] + c).val() << '\n';
    }
  }

  return 0;
}
