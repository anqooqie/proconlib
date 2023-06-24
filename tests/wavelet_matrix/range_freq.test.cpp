#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2674"

#include <iostream>
#include <algorithm>
#include "tools/wavelet_matrix.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int D;
  std::cin >> D;
  tools::wavelet_matrix<int> x(D);
  for (int i = 0; i < D; ++i) {
    int x_i;
    std::cin >> x_i;
    x_i += 100000000;
    x.set(i, x_i);
  }
  x.build();

  int Q;
  std::cin >> Q;
  for (int q = 0; q < Q; ++q) {
    int l, r, e;
    std::cin >> l >> r >> e;
    --l;
    const auto [a, b] = std::minmax({x.access(l), x.access(r - 1)});
    std::cout << (r - l) - x.range_freq(l, r, std::max(0, a - e), b + e + 1) << "\n";
  }

  return 0;
}
