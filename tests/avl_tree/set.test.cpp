// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/point_set_range_composite

#include <utility>
#include <variant>
#include <iostream>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/avl_tree.hpp"

using mint = atcoder::modint998244353;

using S = std::pair<mint, mint>;
struct SM {
  using T = S;
  static T op(const T& x, const T& y) {
    return T(y.first * x.first, y.first * x.second + y.second);
  }
  static T e() {
    return T(mint::raw(1), mint::raw(0));
  }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<S> init;
  init.reserve(N);
  for (int i = 0; i < N; ++i) {
    int a, b;
    std::cin >> a >> b;
    init.emplace_back(mint::raw(a), mint::raw(b));
  }

  tools::avl_tree<SM>::buffer buffer;
  tools::avl_tree<SM> avl_tree(buffer, init);
  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int p, c, d;
      std::cin >> p >> c >> d;
      avl_tree.set(p, S(mint::raw(c), mint::raw(d)));
    } else {
      int l, r, x;
      std::cin >> l >> r >> x;
      const auto [a, b] = avl_tree.prod(l, r);
      std::cout << (a * mint::raw(x) + b).val() << '\n';
    }
  }

  return 0;
}
