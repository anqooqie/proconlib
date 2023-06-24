#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <iostream>
#include <vector>
#include "tools/wavelet_matrix.hpp"

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> a(N);
  for (auto& a_i : a) std::cin >> a_i;

  tools::wavelet_matrix<int> wm(a);
  for (int q = 0; q < Q; ++q) {
    int l, r, k;
    std::cin >> l >> r >> k;
    std::cout << wm.kth_smallest(l, r, k) << "\n";
  }

  return 0;
}
