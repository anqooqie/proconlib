// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/range_affine_range_sum

#include <iostream>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/lazy_segtree.hpp"

using mint = atcoder::modint998244353;

struct SM {
  using T = std::pair<int, mint>;
  static T op(const T& x, const T& y) {
    return {x.first + y.first, x.second + y.second};
  }
  static T e() {
    return {0, mint::raw(0)};
  }
};
using S = typename SM::T;

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

S mapping(const F& f, const S& e) {
  return {e.first, f.first * e.second + f.second * mint::raw(e.first)};
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  tools::lazy_segtree<SM, FM, mapping> a([&]() {
    std::vector<S> v(N);
    for (auto& v_i : v) {
      int x;
      std::cin >> x;
      v_i = {1, mint::raw(x)};
    }
    return v;
  }());

  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int l, r, b, c;
      std::cin >> l >> r >> b >> c;
      a.apply(l, r, {mint::raw(b), mint::raw(c)});
    } else {
      int l, r;
      std::cin >> l >> r;
      std::cout << a.prod(l, r).second.val() << '\n';
    }
  }

  return 0;
}
