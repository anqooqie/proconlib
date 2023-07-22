#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include "tools/wavelet_matrix.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  tools::wavelet_matrix<int> wm;
  for (int i = 0; i < N; ++i) {
    int a_i;
    std::cin >> a_i;
    wm.add_point(i, a_i);
  }
  wm.build();

  for (int q = 0; q < Q; ++q) {
    int l, r, k;
    std::cin >> l >> r >> k;
    std::cout << wm.get_point(wm.kth_smallest(l, r, k)).second << "\n";
  }

  return 0;
}
