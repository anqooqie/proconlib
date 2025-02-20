// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/persistent_range_affine_range_sum

#include <iostream>
#include <utility>
#include <vector>
#include "atcoder/modint.hpp"
#include "tools/persistent_lazy_segtree.hpp"

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

  tools::persistent_lazy_segtree<SM, FM, mapping>::buffer buffer;
  std::vector<tools::persistent_lazy_segtree<SM, FM, mapping>> A_buffer(Q + 1);
  auto A = A_buffer.begin() + 1;
  A[-1] = tools::persistent_lazy_segtree<SM, FM, mapping>(buffer, [&]() {
    std::vector<S> a(N);
    for (auto& a_i : a) {
      int x;
      std::cin >> x;
      a_i = {1, mint::raw(x)};
    }
    return a;
  }());

  for (int q = 0; q < Q; ++q) {
    int t;
    std::cin >> t;
    if (t == 0) {
      int k, l, r, b, c;
      std::cin >> k >> l >> r >> b >> c;
      A[q] = A[k].apply(l, r, {mint::raw(b), mint::raw(c)});
    } else if (t == 1) {
      int k, s, l, r;
      std::cin >> k >> s >> l >> r;
      A[q] = A[k].rollback(A[s], l, r);
    } else {
      int k, l, r;
      std::cin >> k >> l >> r;
      std::cout << A[k].prod(l, r).second.val() << '\n';
    }
  }

  return 0;
}
