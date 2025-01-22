// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum

#include <utility>
#include <iostream>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/lazy_avl_tree.hpp"

using mint = atcoder::modint998244353;

using S = std::pair<int, mint>;
struct SM {
  using T = S;
  static T op(const T& x, const T& y) {
    return T(x.first + y.first, x.second + y.second);
  }
  static T e() {
    return T(0, mint::raw(0));
  }
};
using F = std::pair<mint, mint>;
struct FM {
  using T = F;
  static T op(const T& f, const T& g) {
    return F(f.first * g.first, f.first * g.second + f.second);
  }
  static T e() {
    return F(mint::raw(1), mint::raw(0));
  }
};
S mapping(const F& f, const S& x) {
  return S(x.first, f.first * x.second + f.second * x.first);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<S> a;
  a.reserve(N);
  for (int i = 0; i < N; ++i) {
    int a_i;
    std::cin >> a_i;
    a.emplace_back(1, mint::raw(a_i));
  }

  tools::lazy_avl_tree<SM, FM, mapping, true>::buffer buffer;
  tools::lazy_avl_tree<SM, FM, mapping, true> avl_tree(buffer, a);
  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int i, x;
      std::cin >> i >> x;
      avl_tree.insert(i, S(1, mint::raw(x)));
    } else if (t == 1) {
      int i;
      std::cin >> i;
      avl_tree.erase(i);
    } else if (t == 2) {
      int l, r;
      std::cin >> l >> r;
      avl_tree.reverse(l, r);
    } else if (t == 3) {
      int l, r, b, c;
      std::cin >> l >> r >> b >> c;
      avl_tree.apply(l, r, F(mint::raw(b), mint::raw(c)));
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << avl_tree.prod(l, r).second.val() << '\n';
    }
  }

  return 0;
}
