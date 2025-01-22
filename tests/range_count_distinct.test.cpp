// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/static_range_count_distinct

#include <iostream>
#include <vector>
#include "tools/range_count_distinct.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  tools::range_count_distinct seq(a.begin(), a.end());

  for (int q = 0; q < Q; ++q) {
    int l, r;
    std::cin >> l >> r;
    std::cout << seq.query(l, r) << '\n';
  }

  return 0;
}
