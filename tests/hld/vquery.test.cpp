#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include <cstdint>
#include <utility>
#include <iostream>
#include <vector>
#include "atcoder/modint.hpp"
#include "atcoder/segtree.hpp"
#include "tools/hld.hpp"

using i64 = std::int_fast64_t;
using mint = atcoder::modint998244353;

std::pair<mint, mint> op(const std::pair<mint, mint> e1, const std::pair<mint, mint> e2) {
  return ::std::make_pair(e1.first * e2.first, e1.first * e2.second + e1.second);
}
std::pair<mint, mint> po(const std::pair<mint, mint> e1, const std::pair<mint, mint> e2) {
  return op(e2, e1);
}
std::pair<mint, mint> e() {
  return ::std::make_pair(mint::raw(1), mint::raw(0));
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, Q;
  std::cin >> N >> Q;
  std::vector<std::pair<mint, mint>> f;
  f.reserve(N);
  for (i64 i = 0; i < N; ++i) {
    i64 a, b;
    std::cin >> a >> b;
    f.emplace_back(mint::raw(a), mint::raw(b));
  }
  tools::hld hld(N);
  for (i64 i = 0; i < N - 1; ++i) {
    i64 u, v;
    std::cin >> u >> v;
    hld.add_edge(u, v);
  }

  hld.build();
  std::vector<std::pair<mint, mint>> g(N);
  for (i64 i = 0; i < N; ++i) {
    g[hld.vid2dfs()[i]] = f[i];
  }
  atcoder::segtree<std::pair<mint, mint>, op, e> segtree_to_root(g);
  atcoder::segtree<std::pair<mint, mint>, po, e> segtree_to_leaf(g);

  for (i64 q = 0; q < Q; ++q) {
    i64 t;
    std::cin >> t;
    if (t == 0) {
      i64 p, c, d;
      std::cin >> p >> c >> d;
      segtree_to_root.set(hld.vid2dfs()[p], std::make_pair(mint::raw(c), mint::raw(d)));
      segtree_to_leaf.set(hld.vid2dfs()[p], std::make_pair(mint::raw(c), mint::raw(d)));
    } else {
      i64 u, v, x;
      std::cin >> u >> v >> x;
      std::pair<mint, mint> prod = e();
      for (const auto& [from, to] : hld.vquery(u, v)) {
        if (from < to) {
          prod = op(segtree_to_leaf.prod(from, to), prod);
        } else {
          prod = op(segtree_to_root.prod(to, from), prod);
        }
      }
      std::cout << (prod.first * mint::raw(x) + prod.second).val() << '\n';
    }
  }

  return 0;
}
