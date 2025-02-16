// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite

#include <iostream>
#include <utility>
#include <variant>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/lazy_segtree.hpp"
#include "tools/nop_mapping.hpp"
#include "tools/nop_monoid.hpp"

template <typename SM>
using segtree = tools::lazy_segtree<SM, tools::nop_monoid, tools::nop_mapping<std::monostate, typename SM::T>>;

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
  segtree<SM> f([&]() {
    std::vector<std::pair<mint, mint>> v(N);
    for (auto& [a, b] : v) {
      int x, y;
      std::cin >> x >> y;
      a = mint::raw(x);
      b = mint::raw(y);
    }
    return v;
  }());

  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int p, c, d;
      std::cin >> p >> c >> d;
      f.set(p, {mint::raw(c), mint::raw(d)});
    } else {
      int l, r, x;
      std::cin >> l >> r >> x;
      const auto [a, b] = f.prod(l, r);
      std::cout << (a * mint::raw(x) + b).val() << '\n';
    }
  }

  return 0;
}
