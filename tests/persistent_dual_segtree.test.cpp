// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_affine_point_get

#include <iostream>
#include <tuple>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/persistent_dual_segtree.hpp"

using mint = atcoder::modint998244353;
struct monoid {
  using T = std::pair<mint, mint>;
  static T op(const T& f, const T& g) {
    return {f.first * g.first, f.first * g.second + f.second};
  }
  static T e() {
    return {mint::raw(1), mint::raw(0)};
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<mint> a(N);
  for (auto&& a_i : a) {
    int x;
    std::cin >> x;
    a_i = mint::raw(x);
  }

  tools::persistent_dual_segtree<monoid>::buffer buffer;
  std::vector<tools::persistent_dual_segtree<monoid>> seg;
  seg.emplace_back(buffer, N);
  std::vector<std::tuple<int, int>> queries;
  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int l, r, b, c;
      std::cin >> l >> r >> b >> c;
      seg.push_back(seg.back().apply(l, r, {mint::raw(b), mint::raw(c)}));
    } else {
      int i;
      std::cin >> i;
      queries.emplace_back(seg.size() - 1, i);
    }
  }

  for (const auto& [t, i] : queries) {
    const auto [b, c] = seg[t].get(i);
    std::cout << (b * a[i] + c).val() << '\n';
  }
  return 0;
}
