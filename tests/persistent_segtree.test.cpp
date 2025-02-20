// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite_large_array

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/persistent_segtree.hpp"

using mint = atcoder::modint998244353;

struct SM {
  using T = std::pair<mint, mint>;
  static T op(const T& f, const T& g) {
    return {g.first * f.first, g.first * f.second + g.second};
  }
  static T e() {
    return {mint::raw(1), mint::raw(0)};
  }
};
using S = typename SM::T;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  tools::persistent_segtree<SM>::buffer buffer;
  std::vector<tools::persistent_segtree<SM>> seg;
  seg.emplace_back(buffer, 0, N);
  std::vector<std::tuple<int, int, int, mint>> queries;

  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int p, c, d;
      std::cin >> p >> c >> d;
      seg.push_back(seg.back().set(p, {mint::raw(c), mint::raw(d)}));
    } else {
      int l, r, x;
      std::cin >> l >> r >> x;
      queries.emplace_back(seg.size() - 1, l, r, mint::raw(x));
    }
  }

  for (const auto& [q, l, r, x] : queries) {
    const auto [a, b] = seg[q].prod(l, r);
    std::cout << (a * x + b).val() << '\n';
  }
  return 0;
}
