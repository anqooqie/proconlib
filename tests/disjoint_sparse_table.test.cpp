#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <cstdint>
#include <iostream>
#include "tools/monoid.hpp"
#include "tools/disjoint_sparse_table.hpp"

using i64 = std::int_fast64_t;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  i64 N, Q;
  std::cin >> N >> Q;
  std::vector<i64> a(N);
  for (auto& a_i : a) {
    std::cin >> a_i;
  }

  tools::disjoint_sparse_table<tools::monoid::min<i64>> dst(a.begin(), a.end());
  for (i64 q = 0; q < Q; ++q) {
    i64 l, r;
    std::cin >> l >> r;
    std::cout << dst.prod(l, r) << '\n';
  }

  return 0;
}
