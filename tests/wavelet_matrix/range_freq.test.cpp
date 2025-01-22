// competitive-verifier: PROBLEM https://onlinejudge.u-aizu.ac.jp/problems/2674

#include <iostream>
#include <algorithm>
#include "tools/wavelet_matrix.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int D;
  std::cin >> D;
  tools::wavelet_matrix<int> wm;
  for (int i = 0; i < D; ++i) {
    int x_i;
    std::cin >> x_i;
    wm.add_point(i, x_i);
  }
  wm.build();

  int Q;
  std::cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int l, r, e;
    std::cin >> l >> r >> e;
    --l;
    const auto [a, b] = std::minmax({wm.get_point(l).second, wm.get_point(r - 1).second});
    std::cout << (r - l) - wm.range_freq(l, r, a - e, b + e + 1) << "\n";
  }

  return 0;
}
