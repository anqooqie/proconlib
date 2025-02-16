// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_affine_point_get

#include <iostream>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/dual_sparse_segtree.hpp"

using mint = atcoder::modint998244353;

struct FM {
  using T = std::pair<mint, mint>;
  static T op(const T& f, const T& g) {
    return {f.first * g.first, f.first * g.second + f.second};
  }
  static T e() {
    return {mint::raw(1), mint::raw(0)};
  }
};
using F = typename FM::T;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<mint> a(N);
  for (auto& a_i : a) {
    int x;
    std::cin >> x;
    a_i = mint::raw(x);
  }

  tools::dual_sparse_segtree<FM> f(0, N);

  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int l, r, b, c;
      std::cin >> l >> r >> b >> c;
      f.apply(l, r, {mint::raw(b), mint::raw(c)});
    } else {
      int i;
      std::cin >> i;
      const auto [b, c] = f.get(i);
      std::cout << (b * a[i] + c).val() << '\n';
    }
  }

  return 0;
}
